#include "task.h"

//Constructor to initialize a Task object with name and priority
Task::Task(const std::string& name, int priority) {
	this->name = name;
	this->priority = priority;
}

//Getter to retrieve name
std::string Task::getName() const
{
	return name;
}

//Getter to retrieve priority
int Task::getPriority() const
{
	return priority;
}
