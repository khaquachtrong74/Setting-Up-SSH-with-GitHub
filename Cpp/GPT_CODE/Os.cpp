#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>

// Định nghĩa cấu trúc Process
class Process {
private:
    int pid;
    std::string name;
    int memoryUsage;
    bool isRunning;

public:
    Process(int id, std::string n, int mem) : 
        pid(id), name(n), memoryUsage(mem), isRunning(false) {}

    void start() { isRunning = true; }
    void stop() { isRunning = false; }
    bool running() const { return isRunning; }
    int getPid() const { return pid; }
    std::string getName() const { return name; }
};

// Quản lý Process
class ProcessManager {
private:
    std::map<int, std::shared_ptr<Process>> processes;
    int nextPid = 1;

public:
    int createProcess(const std::string& name, int memoryRequired) {
        auto process = std::make_shared<Process>(nextPid, name, memoryRequired);
        processes[nextPid] = process;
        return nextPid++;
    }

    bool killProcess(int pid) {
        if (processes.find(pid) != processes.end()) {
            processes.erase(pid);
            return true;
        }
        return false;
    }

    void listProcesses() {
        std::cout << "\nRunning Processes:\n";
        for (const auto& pair : processes) {
            auto process = pair.second;
            std::cout << "PID: " << process->getPid() 
                      << " Name: " << process->getName() 
                      << " Status: " << (process->running() ? "Running" : "Stopped")
                      << "\n";
        }
    }
};

// File System đơn giản
class FileSystem {
private:
    struct File {
        std::string content;
        std::string name;
    };
    std::map<std::string, File> files;

public:
    bool createFile(const std::string& name) {
        if (files.find(name) == files.end()) {
            files[name] = File{"", name};
            return true;
        }
        return false;
    }

    bool writeFile(const std::string& name, const std::string& content) {
        if (files.find(name) != files.end()) {
            files[name].content = content;
            return true;
        }
        return false;
    }

    std::string readFile(const std::string& name) {
        if (files.find(name) != files.end()) {
            return files[name].content;
        }
        return "";
    }

    void listFiles() {
        std::cout << "\nFiles in system:\n";
        for (const auto& pair : files) {
            std::cout << pair.first << "\n";
        }
    }
};

// Console OS chính
class ConsoleOS {
private:
    ProcessManager processManager;
    FileSystem fileSystem;
    bool running = true;

    void printHelp() {
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
    void run() {
        std::cout << "Simple Console OS Starting...\n";
        std::cout << "Type 'help' for commands\n";

        while (running) {
            std::string command;
            std::cout << "\n$ ";
            std::getline(std::cin, command);

            if (command == "help") {
                printHelp();
            }
            else if (command.substr(0, 6) == "create") {
                std::string name = command.substr(7);
                int pid = processManager.createProcess(name, 1000);
                std::cout << "Created process with PID: " << pid << "\n";
            }
            else if (command.substr(0, 4) == "kill") {
                int pid = std::stoi(command.substr(5));
                if (processManager.killProcess(pid)) {
                    std::cout << "Process " << pid << " killed\n";
                } else {
                    std::cout << "Process not found\n";
                }
            }
            else if (command == "ps") {
                processManager.listProcesses();
            }
            else if (command.substr(0, 5) == "touch") {
                std::string filename = command.substr(6);
                if (fileSystem.createFile(filename)) {
                    std::cout << "File created: " << filename << "\n";
                } else {
                    std::cout << "File already exists\n";
                }
            }
            else if (command.substr(0, 5) == "write") {
                size_t spacePos = command.find(" ", 6);
                std::string filename = command.substr(6, spacePos - 6);
                std::string content = command.substr(spacePos + 1);
                if (fileSystem.writeFile(filename, content)) {
                    std::cout << "Content written to file\n";
                } else {
                    std::cout << "File not found\n";
                }
            }
            else if (command.substr(0, 4) == "read") {
                std::string filename = command.substr(5);
                std::string content = fileSystem.readFile(filename);
                if (!content.empty()) {
                    std::cout << "Content: " << content << "\n";
                } else {
                    std::cout << "File not found or empty\n";
                }
            }
            else if (command == "ls") {
                fileSystem.listFiles();
            }
            else if (command == "exit") {
                running = false;
            }
            else {
                std::cout << "Unknown command. Type 'help' for available commands.\n";
            }
        }
        std::cout << "OS Shutting down...\n";
    }
};

int main() {
    ConsoleOS os;
    os.run();
    return 0;
}
