#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
#include <algorithm>
#include <stdexcept>
#include "median.h"
#include "Student_info.h"
#include "grade.h"
#include "util.h"

using std::cin; using std::setprecision;
using std::cout; using std::string;
using std::endl; using std::streamsize;
using std::vector;

int main()
{
	vector<Student_info> did, didn;
	Student_info student;
	while (read(cin, student))
	{
		if (did_all_hw(student))
			did.push_back(student);
		else
			didn.push_back(student);
	}

	if (did.empty())
	{
		cout << "No student did homwork" << endl;
		return 1;
	}
		
	if (didn.empty())
	{
		cout << "every student did homwork" << endl;
		return 1;
	}
}



