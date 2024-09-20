#include "grade.h"
#include "median.h"
#include <algorithm>
#include <numeric>

using std::vector; using std::list;
using std::ostream; using std::string;
using std::endl;

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
	return grade(s) < 60;
}

bool pgrade(const Student_info& s)
{
	return !fgrade(s);
}

vector<Student_info> extract_fail(vector<Student_info>& students)
{
	vector<Student_info>::iterator iter = std::stable_partition(students.begin(), students.end(), pgrade);
	vector<Student_info> fail(iter, students.end());
	students.erase(iter, students.end());
	return fail;

	//list<Student_info> fail;

	////조건이 만적할 경우 처리 과락한 학생들을 fail을 통한 back_inserter반복자를 사용해 넣는다
	std::remove_copy_if(students.begin(), students.end(), std::back_inserter(fail), pgrade);

	//// 조건을 만족하지 않을 경우를 처리 fgrade가 아닌 과락한 않은 학생들을 뒤로 밀고 과락 학생들을 삭제한다.
	//students.erase(std::remove_if(students.begin(), students.end(), fgrade), students.end()); 
	//return fail;
	
}

double median_analysis(const vector<Student_info>& students)
{
	vector<double> grades;
	std::transform(students.begin(), students.end(), std::back_inserter(grades), grade_aux);
	return median(grades);
}

double average(const vector<double>& v)
{
	return std::accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const Student_info& s)
{
	return grade(s.midterm, s.final, average(s.homework));
}

double average_analysis(const vector<Student_info>& students)
{
	vector<double> grades;
	std::transform(students.begin(), students.end(), std::back_inserter(grades), average_grade);
	return median(grades);
}

double optimistic_median(const Student_info& s)
{
	vector<double> nonzero;
	std::remove_copy(s.homework.begin(), s.homework.end(), std::back_inserter(nonzero), 0);

	if (nonzero.empty())
		return grade(s.midterm, s.final, 0);
	else
		return grade(s.midterm, s.final, median(nonzero));
}

double optimistic_median_analysis(const vector<Student_info>& students)
{
	vector<double> grades;
	std::transform(students.begin(), students.end(), std::back_inserter(grades), optimistic_median);
	return median(grades);
}

void write_analysis(ostream& out, const string& name, double analysis(const vector<Student_info>&),
	const vector<Student_info>& did, const vector<Student_info>&didnt)
{
    out << name << ": median(did) = " << analysis(did) << ", median(didnt) = " << analysis(didnt) << endl;
}
