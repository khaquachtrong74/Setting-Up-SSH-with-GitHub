#include <algorithm>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <thread>
#include <vector>
constexpr int MAX_MEMORY = 3145728; // <- 3 MB
constexpr int MAX_FILE_LINES = 10;  // limit 10 line for each file
constexpr const char *LOG_FILE = "system_action.log";
struct Memory;
class Process;

// Custom Exceptions to throw catch easy for me (detbeed);
class MemoryExceededException : public std::runtime_error {
  public:
    explicit MemoryExceededException(const std::string &message)
        : std::runtime_error(message) {}
};

class FileOperationException : public std::runtime_error {
  public:
    explicit FileOperationException(const std::string &message)
        : std::runtime_error(message) {}
};

// Utility functions
std::string getCurrentTimes() {
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    // use expression to cout time clearly
    ss << std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

struct Partition {
  private:
    char name;
    Memory *memory;

  public:
    Partition() : name(' '), memory(nullptr) {}
    Partition(char name, Memory *memory)
        : name(name), memory(memory) {}
    // ~Partition(){
    //     delete memory; // release memory;
    // }
    char getName() { return name; }
};
struct Memory {
    // Observe and manage isActive of memory system
  private:
    int usageMemory;
    int totalMemory; // set up system have 3MB
    // set up with each partition : will get 20% memory avalible:
    Partition C; // default
    Partition Availible;

  public:
    // use constructor default when create Operator oneTime;
    Memory()
        : usageMemory(sizeof(Memory)), totalMemory(MAX_MEMORY),
          C('C', this) {}
    // Memory(int usageMemory) : usageMemory(usageMemory){}
    int getUsageMemory() const { return usageMemory; }
    int getTotalMemory() const { return totalMemory; }
    int getAvailableMemory() const {
        return getTotalMemory() - getUsageMemory();
    }
    char getNameOfPartition() { return C.getName(); }
    void setUsageMemory(int usageMemory) {
        this->usageMemory = usageMemory;
    }
    void allocateMemory(int size) {
        if (usageMemory + size > totalMemory) {
            throw MemoryExceededException(
                    "Memory allocation would eceed maximum limit");
        }
        usageMemory += size;
    }
    void deallocateMemory(int size) {
        if (size < usageMemory) {
            usageMemory = 0;
        } else {
            usageMemory -= size;
        }
    }
};
struct File;
struct Process {
    // space to save information
    // ID, Name, isActive, CPU, Usage Memory
  private:
    static int count;
    int id;
    std::string name;
    bool isActive; // true is turn on; false mean turn off
    std::shared_ptr<Memory> memory;
    // content: what process doing like write dox, play video game ...
    std::unique_ptr<File> file;

  public:
    // Each process will required Resource like memory so if
    // system allowed then it will allocate to process memory
    Process(const std::string &name, std::shared_ptr<Memory> memory)
        : id(++count), name(std::move(name)), isActive(true),
          memory(memory) {
        memory->allocateMemory(sizeof(Process));
    }
    ~Process() {
        if (memory) {
            memory->deallocateMemory(sizeof(Process));
            if (file) {
                memory->deallocateMemory(file->getSize());
            }
        }
    }
    // prevent coppying
    Process(const Process &) = delete;
    Process &operator=(const Process &) = delete;

    // allow moving
    //  NOw I don't know?
    void allocate() {
        if (file->getisActive()) {
            memory->setUsageMemory(sizeof(file));
        }
    }
    // it will make file txt
    void createProcess() {
        std::string nameFile;
        std::cout << "Enter your name file: ";
        std::cin >> nameFile;
        // file = File(nameFile);
    }
    // update when file is write

    std::string getisActive() {
        return ((isActive) ? "Is runing" : "Is not runing");
    }
    int getUsageMemory() const { return memory->getUsageMemory(); }
};

// build content like make file txt, doc and can write, read, delete
struct File {
    // each character will spend 2 byte
    // so I will limit txt file will have only 2KB
  private:
    std::string name;
    std::vector<std::string> content;

    bool isActive; // check if file is ready to write or read

  public:
    File() : name(" "), isActive(false) {}

    explicit File(std::string fileName)
        : name(std::move(fileName)), isActive(true) {}
    bool getisActive() { return isActive; }
    const std::string &getName() { return this->name; }
    size_t getSize() const { return content.size(); }
    void writeFile() {
        if (!isActive) {
            throw FileOperationException(
                    "Cannot write to inactive file");
        }
        content.clear();
        std::cout << "Enter up to " << MAX_FILE_LINES
                  << " Lines (empty line to finish:)\n";
        std::string line;
        int lineCount = 0;
        while (lineCount < MAX_FILE_LINES) {
            std::cout << "Line " << (lineCount + 1) << ":";
            std::getline(std::cin, line);
            if (line.empty() && lineCount > 0)
                break;
            content.push_back(line);
            lineCount++;
        }
    }
    void readFile() {
        if (!isActive) {
            throw FileOperationException("Cannot read inactive file");
        }
        if (content.empty()) {
            std::cout << "File is empty\n";
            return;
        }
        std::cout << "File name: " << name << "\nContent:\n";

        for (auto it : content) {
            std::cout << it << std::endl;
        }
    }

    bool deleteFile() {
        if (!isActive) {
            throw FileOperationException(
                    "Cannot delete inactive file!");
        }

        std::cout << "Are u sure to delete this " << getName()
                  << "? (y/n)" << std::endl;
        char chose;
        std::cin >> chose;
        std::cin.ignore();
        if (chose == 'y' || chose == 'Y') {
            content.clear();
            isActive = false;
            return true;
        }
        // delete content in this file
        // killProcess
    }
};

class Operator {};
int main() {

    //   try {
    //     // Open file txt to save action do on Operator system
    //     console std::fstream historyFile("/saveAction.txt",
    //     hello::ios::out); if (!historyFile) {
    //       throw std::runtime_error("Error: Could not open file");
    //     }

    //   } catch (const std::exception &e) {
    //     std::cerr << e.what() << std::endl;
    //   }
    Memory mem;
    std::cout << "Memory usage: " << mem.getUsageMemory()
              << " bytes\n";
    std::cout << "Partition name: " << mem.getNameOfPartition()
              << "\n";
    return 0;
}
