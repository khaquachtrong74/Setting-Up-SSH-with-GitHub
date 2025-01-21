// Purpose: Build Operator System in Console
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <chrono>
#include <ctime>
class Process
{
private:
    int pid; // Process Identifier | private
    std::string name;
    int memoryUsage;
    bool isRunning;

public:
    Process(int id, std::string n, int memu) : pid(id), name(n), memoryUsage(memu), isRunning(false) {}
    void start() { isRunning = true; };
    void stop() { isRunning = false; };
    bool running() const { return isRunning; }
    int getPid() const { return pid; }
    std::string getName() const { return name; }
};

// Mangage Process
class ManageProcess
{
private:
    std::map<int, std::shared_ptr<Process>> processes;
    int nextPid = 1;

public:
    int createProcess(const std::string &name, int memoryRequired)
    {
        auto process = std::make_shared<Process>(nextPid, name, memoryRequired);
        processes[nextPid] = process;
        return nextPid++;
    }
    bool killProcess(int pid)
    {
        if (processes.find(pid) != processes.end())
        {
            processes.erase(pid);
            return true;
        }
        return false;
    }
    void listProcess() const
    {
        std::cout << "\n Running Process";
        for (const auto &pair : processes)
        {
            auto process = pair.second;
            std::cout << "Pid" << process->getPid()
                      << "Name: " << process->getName()
                      << "Running: " << (process->running() ? "Running" : "Stop") << "\n";
        }
    }
};

// File System
class FileSystem
{
private:
    struct File
    {
        std::string content;
        std::string name;
    };
    std::map<std::string, File> files;

public:
    bool createFile(const std::string &name)
    {
        if (files.find(name) == files.end())
        {
            files[name] = File{"", name};
            return true;
        }
        return false;
    }
    bool writeFile(const std::string &name, const std::string &content)
    {
        if (files.find(name) != files.end())
        {
            files[name].content = content;
            return true;
        }
        return false;
    }
    std::string readFile(const std::string &name)
    {
        if (files.find(name) != files.end())
        {
            return files[name].content;
        }
        return "";
    }
    // ls - view file in files
    void listFiles() const
    {
        std::cout << "\nFile in System" << std::endl;
        for (const auto file : files)
        {
            std::cout << file.first << " ";
        }
    }
};

// Design Console
// Console OS chính
class ConsoleOS
{
private:
    ManageProcess processManager;
    FileSystem fileSystem;
    bool running=false;

    void printHelp()
    {
        std::cout << "\nAvailable commands:\n"
                  << "help - Show this help\n"
                  << "create [process_name] - Create a new process\n"
                  << "kill [pid] - Kill a process\n"
                  << "ps - List all processes\n"
                  << "touch [filename] - Create a file\n"
                  << "write [filename] [content] - Write to a file\n"
                  << "read [filename] - Read a file\n"
                  << "ls - List all files\n"
                  << "exit - Exit the OS\n";
    }

public:
    ConsoleOS(){
        running = true;
    }
    void run()
    {
        std::cout << "Simple Console OS Starting...\n";
        std::cout << "Type 'help' for commands\n";

        while (running)
        {
            std::string command;
            std::cout << "\n$ ";
            std::getline(std::cin, command);

            if (command == "help")
            {
                printHelp();
            }
            else if (command.substr(0, 6) == "create")
            {
                std::string name = command.substr(7);
                int pid = processManager.createProcess(name, 1000);
                std::cout << "Created process with PID: " << pid << "\n";
            }
            else if (command.substr(0, 4) == "kill")
            {
                int pid = std::stoi(command.substr(5));
                if (processManager.killProcess(pid))
                {
                    std::cout << "Process " << pid << " killed\n";
                }
                else
                {
                    std::cout << "Process not found\n";
                }
            }
            else if (command == "ps")
            {
                processManager.listProcess();
            }
            else if (command.substr(0, 5) == "touch")
            {
                std::string filename = command.substr(6);
                if (fileSystem.createFile(filename))
                {
                    std::cout << "File created: " << filename << "\n";
                }
                else
                {
                    std::cout << "File already exists\n";
                }
            }
            else if (command.substr(0, 5) == "write")
            {
                size_t spacePos = command.find(" ", 6);
                std::string filename = command.substr(6, spacePos - 6);
                std::string content = command.substr(spacePos + 1);
                if (fileSystem.writeFile(filename, content))
                {
                    std::cout << "Content written to file\n";
                }
                else
                {
                    std::cout << "File not found\n";
                }
            }
            else if (command.substr(0, 4) == "read")
            {
                std::string filename = command.substr(5);
                std::string content = fileSystem.readFile(filename);
                if (!content.empty())
                {
                    std::cout << "Content: " << content << "\n";
                }
                else
                {
                    std::cout << "File not found or empty\n";
                }
            }
            else if (command == "ls")
            {
                fileSystem.listFiles();
            }
            else if (command == "exit")
            {
                running = false;
            }
            else
            {
                std::cout << "Unknown command. Type 'help' for available commands.\n";
            }
        }
        std::cout << "OS Shutting down...\n";
    }
};

int main()
{
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    std::time_t start_time = std::chrono::system_clock::to_time_t(start);
    std::cout<<"Start computation at "<<std::ctime(&start_time);
    ConsoleOS os;
    os.run();
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";

    return 0;
}
