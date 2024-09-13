#include "Student_info.h"
#include <algorithm>
using std::vector;

bool compare(const Student_info& x, Student_info& y)
{
	return x.name < y.name;
}

std::istream& read_hw(std::istream& in, vector<double>& hw)
{
	if (in) {
		hw.clear();

		double x;

		while (in >> x)
			hw.push_back(x);
		in.clear();
	}
	return in;
}

std::istream& read(std::istream& is, Student_info& s)
{
	is >> s.name >> s.midterm >> s.final;
	read_hw(is, s.homework);
	return is;
}

bool did_all_hw(const Student_info& s)
{
	return std::find(s.homework.begin(), s.homework.end(), 0) == s.homework.end();
}