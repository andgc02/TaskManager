#include "task_manager.h"
#include <iostream>
#include <fstream>

//Add task to priority queue
void TaskManager::addTask(const Task& task) {
	tasks.push(task);
}

//Mark highest priority task as complete
void TaskManager::completeTask() {
	if (!tasks.empty()) {
		Task completed = tasks.top();
		tasks.pop();
		std::cout << "Completed task: " << completed.getName() << "\n";
	}
	else {
		std::cout << "No tasks available\n";
	}
}

//Display all tasks in the priority queue
void TaskManager::displayTasks() const {
	std::priority_queue<Task, std::vector<Task>, CompareTask> temp = tasks;
	while (!temp.empty()) {
		Task task = temp.top();
		std::cout << "Task: " << task.getName() << " - Priority: " << task.getPriority()
			<< "\n";
		temp.pop();
	}
}

//Compare two task objects based on their priority
bool TaskManager::CompareTask::operator()(const Task& t1, const Task& t2) const {
	return t1.getPriority() < t2.getPriority();
}

void TaskManager::loadTasksFromFile(const std::string& filename) {
	std::ifstream infile(filename);
	std::string name;
	int priority;
}