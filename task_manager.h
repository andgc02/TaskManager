#pragma once

#include "task.h"
#include <vector>
#include <queue>

class TaskManager {
public:
	void addTask(const Task& task);
	void completeTask();
	void displayTasks() const;

private:

	struct CompareTask {
		bool operator()(const Task& t1, const Task& t2) const;
	};

	std::priority_queue<Task, std::vector<Task>, CompareTask> tasks;


};