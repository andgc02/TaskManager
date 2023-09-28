#pragma once
#include <string>

//Task class is a task with a name and a priority
class Task {
public:
	//Constructor to initialize a task object with a name and priority
	Task(const std::string& name, int priority);

	//Retrieve task name
	std::string getName() const;

	//Retrieve task priority
	int getPriority() const;

private:
	std::string name; //Name of task
	int priority; //Priority of task
};