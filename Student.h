#pragma once
#include <string>
class Student
{
private:
	std::string name;
	int age;
public:
	void showStatus()
	{
		std::cout << "name : " << name << " age : " << age;
	}
};
