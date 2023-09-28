#pragma once

#include <string>

class Task {
public:
	Task(const std::string& name, int priority);

	std::string getName() const;
	int getPriority() const;

private:
	std::string name;
	int priority;
};