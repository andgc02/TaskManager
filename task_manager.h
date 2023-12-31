#pragma once

#include "task.h"
#include <vector>
#include <queue>

//TaskManager class manages collection of Task objects in a priority queue
class TaskManager {
public:
	void addTask(const Task& task); //Add task to priority queue
	void completeTask(); //Mark highest priority task as complete and remove it
	void displayTasks() const; //display all the tasks in the priority queue
	void saveTasksToFile(const std::string& filename) const; //save tasks to file is const as it does not modify any task
	void loadTasksFromFile(const std::string& filename); //load from file modifies the TaskManager by adding saved tasks

private:
	// The CompareTask struct provides a way to compare two Task objects
	// based on their priority to order them in the priority queue.
	struct CompareTask {
		bool operator()(const Task& t1, const Task& t2) const;
	};

	//Priority queue to hold the tasks
	std::priority_queue<Task, std::vector<Task>, CompareTask> tasks;


};