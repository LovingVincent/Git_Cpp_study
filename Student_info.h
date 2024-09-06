#pragma once
#include <iostream>
#include <vector>
#include <string>
struct Student_info {
	string name;
	double midterm, final;
	vector<double> homework;
};

std::istream& read_hw(std::istream& in, vector<double>& hw);
std::istream& read(std::istream& is, Student_info& s);
bool compare(const Student_info& x, Student_info& y);
