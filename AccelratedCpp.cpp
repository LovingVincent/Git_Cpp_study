#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "median.h"
#include "Student_info.h"
#include "grade.h"

using std::cin; using std::setprecision;
using std::cout; using std::string;
using std::endl; using std::streamsize;
using std::vector;

int main()
{
	std::string a;
	vector<Student_info> students;
	Student_info record;
	std::string::size_type maxlen = 0; 

	while (read(cin, record)) {
		maxlen = std::max(maxlen, record.name.size());
		students.push_back(record);
	}
	
	std::sort(students.begin(), students.end(), compare);
	
	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

		try {
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec);
		}
		catch (std::domain_error e)
		{
			cout << e.what();
		}
		cout << endl;
	}
	return 0;
}



