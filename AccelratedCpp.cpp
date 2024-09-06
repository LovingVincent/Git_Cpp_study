#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
#include <vector>
#include <algorithm>
#include <stdexcept>

using std::cin; using std::setprecision;
using std::cout; using std::string;
using std::endl; using std::streamsize;
using std::vector;

struct Student_info {
	string name;
	double midterm, final;
	vector<double> homework;
};

double median(vector<double> vec)
{
	typedef vector<double>::size_type vec_size;
	vec_size size = vec.size();

	if (size == 0)
		throw std::domain_error("median of an empty vector");

	std::sort(vec.begin(), vec.end());
	vec_size mid = size / 2;
	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final,const vector<double>& hw)
{
	if(hw.size() == 0)
		throw std::domain_error("student has do not homework");
	return grade(midterm, final, median(hw));
}

double grade(const Student_info& s)
{
	return grade(s.midterm, s.final, s.homework);
}

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

int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0; 
	cout << "Please enter your first name : ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	cout << "Please enter your midterm and final exam grades : ";
	double midterm, final;
	cin >> midterm >> final;

	cout << "Enter all your homework grades, "
		"followed by end-of-file";

	vector<double> homework;

	read_hw(cin, homework);

	try {
		double final_grade = grade(midterm, final, homework);
		streamsize prec = cout.precision();
		cout << "Your final grade is " << setprecision(3) 
			<< final_grade << setprecision(prec) << endl;
	}
	catch (std::domain_error) {
		cout << endl << "You must enter grades "
			"Please try again" << endl;
		return 1;
	}
	return 0;
}



