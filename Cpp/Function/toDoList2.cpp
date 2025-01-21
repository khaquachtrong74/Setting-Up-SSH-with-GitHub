#include <iostream>
#include <vector>
#include <string>
#include <limits>

void displayMenu() {
    std::cout << "1. Add a new task\n"
              << "2. Complete a task\n"
              << "3. View all tasks\n"
              << "4. Delete a task\n"
              << "0. Save and exit\n";
}

void addTask(std::vector<std::string>& tasks) {
    std::string task;
    std::cout << "Enter your new task: ";
    std::cin.ignore();
    std::getline(std::cin, task);
    tasks.push_back(task);
    std::cout << "Task added successfully!\n";
}

void completeTask(std::vector<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to complete.\n";
        return;
    }
    
    int index;
    std::cout << "Enter the number of the task you've completed: ";
    std::cin >> index;
    
    if (index < 1 || index > static_cast<int>(tasks.size())) {
        std::cout << "Invalid task number. Please try again.\n";
        return;
    }
    
    std::cout << "Completed task: " << tasks[index - 1] << std::endl;
    tasks.erase(tasks.begin() + index - 1);
}

void viewTasks(const std::vector<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks in the list.\n";
    } else {
        std::cout << "Your tasks:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i] << std::endl;
        }
    }
}

void deleteTask(std::vector<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to delete.\n";
        return;
    }
    
    int index;
    std::cout << "Enter the number of the task you want to delete: ";
    std::cin >> index;
    
    if (index < 1 || index > static_cast<int>(tasks.size())) {
        std::cout << "Invalid task number. Please try again.\n";
        return;
    }
    
    std::cout << "Deleted task: " << tasks[index - 1] << std::endl;
    tasks.erase(tasks.begin() + index - 1);
}

int main() {
    std::vector<std::string> tasks;
    int choice;

    while (true) {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 0:
                std::cout << "Saving and exiting. Goodbye!\n";
                return 0;
            case 1:
                addTask(tasks);
                break;
            case 2:
                completeTask(tasks);
                break;
            case 3:
                viewTasks(tasks);
                break;
            case 4:
                deleteTask(tasks);
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

        std::cout << std::endl;
    }

    return 0;
}
