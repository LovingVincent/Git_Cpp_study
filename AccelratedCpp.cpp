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
	vector<Student_info> did, didnt;

	Student_info student;

	while (read(cin, student))
	{
		if (did_all_hw(student))
			did.push_back(student);
		else
			didnt.push_back(student);

		if (did.empty())
		{
			cout << "No student did all the homework!" << endl;
			return 1;
		}

		if (didnt.empty())
		{
			cout << "evert student did all the homework!" << endl;
			return 1;
		}

		write_analysis(cout, "median", median_analysis, did, didnt);
		write_analysis(cout, "average", average_analysis, did, didnt);
		write_analysis(cout, "median of homework turn in", optimistic_median_analysis, did, didnt);
	}
}



