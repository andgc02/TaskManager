#include "task_manager.h"
#include <iostream>

int main() {
	TaskManager taskManager;

	int choice;
    do {
        // Display Menu
        std::cout << "\nPriority Task Manager\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Complete Task\n";
        std::cout << "3. Display Tasks\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        //Perform action based on user
        switch (choice) {
        case 1: {
            std::cin.ignore(); //clear input buffer
            
            std::string name;
            int priority;

            std::cout << "Enter task name: ";
            std::getline(std::cin, name);

            std::cout << "Enter task priority: ";
            std::cin >> priority;
            taskManager.addTask(Task(name, priority));
            break;
        }
        case 2:
            taskManager.completeTask();
            break;
        case 3:
            taskManager.displayTasks();
            break;
        case 4:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice! Please choose again. \n";
        }
    } while (choice != 4);
    return 0;
}