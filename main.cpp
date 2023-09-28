#include "task_manager.h"
#include <iostream>

int main() {
	TaskManager taskManager;
    taskManager.loadTasksFromFile("tasks.txt");//Load tasks from file

	int choice;
    do {
        // Display Menu
        std::cout << "------------------------\n";
        std::cout << "\nPriority Task Manager\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Complete Task\n";
        std::cout << "3. Show All Tasks\n";
        std::cout << "4. Save Tasks to File\n";
        std::cout << "5. Load Tasks from File\n";
        std::cout << "6. Exit\n";
        std::cout << "-----------------------\n";
        std::cout << "Enter your choice: ";
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
            taskManager.saveTasksToFile("tasks.txt"); // Save tasks after completing
            break;
        case 3:
            taskManager.displayTasks();
            break;
        case 4:
            taskManager.saveTasksToFile("tasks.txt");
            std::cout << "Tasks have been saved to tasks.txt.\n";
            break;
        case 5:
            taskManager.loadTasksFromFile("tasks.txt");
            std::cout << "Tasks have been loaded from tasks.txt.\n";
            break;
        case 6:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice! Please choose again. \n";
        }
    } while (choice != 6);
    return 0;
}