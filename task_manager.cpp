#include "task_manager.h"
#include <iostream> //input output stream
#include <fstream> //file I/O stream

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
	std::priority_queue<Task, std::vector<Task>, CompareTask> temp = tasks; //create temp priority queue to read through tasks
	while (!temp.empty()) {
		Task task = temp.top(); //read from top to bottom and then delete each task
		std::cout << "Task: " << task.getName() << " - Priority: " << task.getPriority()
			<< "\n";
		temp.pop();
	}
}

//Compare two task objects based on their priority
bool TaskManager::CompareTask::operator()(const Task& t1, const Task& t2) const {
	return t1.getPriority() < t2.getPriority();
}

void TaskManager::saveTasksToFile(const std::string& filename) const {
	std::ofstream outfile(filename); //Open file to write tasks to
	if (!outfile) return; //If file can't be created or opened to write

	auto temp = tasks; //make a copy of the tasks priority queue to iterate through
	while (!temp.empty()) {
		const auto& task = temp.top(); //Get reference to the top priority task in the queue
		outfile << task.getName() << " " << task.getPriority() << "\n"; //Write task to file
		temp.pop(); //Remove top task
	}
}

void TaskManager::loadTasksFromFile(const std::string& filename) {
	std::ifstream infile(filename); //open file to read
	if (!infile) return; //If file does not exist or cannot open

	std::string name;
	int priority;

	//Read tasks from file, line by line, and add them to priority queue
	while (infile >> name >> priority) {
		addTask(Task(name, priority));
	}
}