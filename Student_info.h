#pragma once
#include <iostream>
#include <vector>
#include <string>

struct Student_info {
	std::string name;
	double midterm, final;
	std::vector<double> homework;
};

std::istream& read_hw(std::istream& in, std::vector<double>& hw);
std::istream& read(std::istream& is, Student_info& s);
bool compare(const Student_info& x, Student_info& y);
bool did_all_hw(const Student_info& s);
