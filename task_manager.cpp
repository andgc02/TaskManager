#include "task_manager.h"
#include <iostream> //input output stream
#include <fstream> //file I/O stream
#include <sstream>
#include <iterator>
#include <numeric> //for accumulator

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
    // Open the file
    std::ifstream file(filename);

    // Check if the file is open, if not log an error message and return from function
    if (!file.is_open()) {
        std::cerr << "Could not open file: " << filename << std::endl;
        return;
    }

    // Clear the existing tasks
    while (!tasks.empty()) tasks.pop();

    std::string line;
    // Read the file line by line
    while (std::getline(file, line)) {
        // Skip empty lines
        if (line.empty()) continue;

        // Convert the line to a string stream for parsing
        std::istringstream iss(line);

        // Split the line into words and store them in a vector
        std::vector<std::string> words{ std::istream_iterator<std::string>{iss},
                                       std::istream_iterator<std::string>{} };

        // If the line does not contain any word, skip it
        if (words.empty()) continue;

        // Convert the last word to an integer assuming it is the priority
        int priority = std::stoi(words.back());

        // Remove the last word (priority) from the vector
        words.pop_back();

        // Concatenate all the other words with spaces to form the task name
        std::string name = std::accumulate(std::next(words.begin()), words.end(),
            words[0], // start with the first word
            [](const std::string& a, const std::string& b) {
                // concatenate all words with a space
                return a + ' ' + b;
            });

        // Add the task to the task manager
        addTask(Task(name, priority));
    }

    // Close the file after reading
    file.close();
}