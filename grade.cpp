#include "grade.h"
#include "median.h"
#include <algorithm>
using std::vector; using std::list;
using std::ostream; using std::string;

double grade_aux(const Student_info& s)
{
	try {
		return grade(s);
	}
	catch (std::domain_error)
	{
		return grade(s.midterm, s.final, 0);
	}
		
}

double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0)
		throw std::domain_error("student has do not homework");
	return grade(midterm, final, median(hw));
}

double grade(const Student_info& s)
{
	return grade(s.midterm, s.final, s.homework);
}
bool fgrade(const Student_info& s)
{
	return fgrade(s) < 60;
}

list<Student_info> extract_fail(list<Student_info>& students)
{
	list<Student_info> fail;
	list<Student_info>::const_iterator iter = students.begin();

	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fail.push_back(*iter);
			iter = students.erase(iter);
		}
		else
			++iter;
	}
	return fail;
}

double median_analysis(const vector<Student_info>& students)
{
	vector<double> grades;
	std::transform(students.begin(), students.end(), std::back_inserter(grades), grade_aux);
	return median(grades);
}

void write_analysis(ostream out, const string& name,
	double analysis(const vector<Student_info>& did, 
		const vector<Student_info>& didn)
{

}