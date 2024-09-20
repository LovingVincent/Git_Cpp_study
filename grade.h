#pragma once
#include <vector>
#include <list>
#include <iostream>
#include "Student_info.h"

double grade(double midterm, double final, double homework);
double grade(double midterm, double final, const std::vector<double>& hw);
double grade(const Student_info& s);
bool fgrade(const Student_info& s);
std::list<Student_info> extract_fail(std::list<Student_info>& students);
void write_analysis(std::ostream& out, const std::string& name, double analysis(const std::vector<Student_info>&),
	const std::vector<Student_info>& did, const std::vector<Student_info>& didnt);
double median_analysis(const std::vector<Student_info>& students);
double average_analysis(const std::vector<Student_info>& students);
double optimistic_median_analysis(const std::vector<Student_info>& students);
