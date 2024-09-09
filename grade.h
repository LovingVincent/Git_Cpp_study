#pragma once
#include <vector>
#include <list>
#include "Student_info.h"

double grade(double midterm, double final, double homework);
double grade(double midterm, double final, const std::vector<double>& hw);
double grade(const Student_info& s);
bool fgrade(const Student_info& s);
std::list<Student_info> extract_fail(std::list<Student_info>& students);