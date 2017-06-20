#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


using namespace std;

const int maxc = 30;

//output formatting constants
const int num_col_lg = 12;
const int num_col_sm = 8;
const int str_col_lg = 20;
const int str_col_sm = 10;
const int output_width = 80;

struct classType {
	int crn, crhrs, numstu, stucrhrs;
	string course, prof;
};

const classType initrec = { -1, -1, -1, -1, "N/A", "N/A" };

void initem(classType[],int&);
void readem(classType[],int&,ifstream&);
void calcTotalCrHrs(classType[],int);
void swapem(classType&,classType&);
void sortByCrHr(classType[],int);
void sortByCourse(classType[], int);
double getAvgStudents(classType[],int);
int countStuByCourse(string,classType[],int);
void printem(classType[],int,ofstream&);
void printTotals(classType[], int, ofstream&);
void printCourseTotals(classType[], int, ofstream&);
void println(char, int, ofstream&);

int main() {
	classType C[maxc];
	int numc;
	ifstream inf("input.dat");
	ofstream outf("output.ot");
	outf.setf(ios::fixed);
	outf.precision(2);
	initem(C, numc);
	readem(C, numc, inf);
	calcTotalCrHrs(C, numc);
	printem(C, numc, outf);
	calcTotalCrHrs(C, numc);
	printTotals(C, numc, outf);
	sortByCrHr(C, numc);
	printem(C, numc, outf);
	outf << left << "Average number of students per section: " << getAvgStudents(C, numc) << endl;
	println('-', output_width, outf);
	sortByCourse(C, numc);
	printCourseTotals(C, numc, outf);

	return 0;
}

void initem(classType c[], int &n)
{
	n = 0;
	for (int i = 0; i < maxc; i++)
		c[i] = initrec;
}

void readem(classType c[], int &n, ifstream &inf)
{
	int i = 0;
	while (!inf.eof()) 
	{
		inf >> c[i].crn >> c[i].course >> c[i].crhrs >> c[i].numstu >> c[i].prof;
		i++;
	}
	n = i;
}

void calcTotalCrHrs(classType a[], int n)
{
	for (int i = 0; i < n; i++)
		a[i].stucrhrs = a[i].crhrs * a[i].numstu;
}

void swapem(classType &a, classType &b)
{
	classType temp;
	temp = a;
	a = b;
	b = temp;
}

void sortByCrHr(classType a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1; j++)
			if (a[j].stucrhrs < a[j + 1].stucrhrs)
				swapem(a[j], a[j + 1]);
}

void sortByCourse(classType a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1; j++)
			if (a[j].course < a[j + 1].course)
				swapem(a[j], a[j + 1]);
}

double getAvgStudents(classType a[], int n)
{
	int total = 0;
	for (int i = 0; i < n; i++)
		total += a[i].numstu;
	return (total / n) * 1.0;
}

int countStuByCourse(string coursename, classType a[], int n)
{
	int total = 0;
	for (int i = 0; i < n; i++)
		if (coursename == a[i].course)
			total += a[i].numstu;
	return total;
}

void printem(classType c[], int n, ofstream &outf)
{
	outf << left
		<< setw(num_col_lg + str_col_lg) << "" << setw(num_col_sm) << "Credit"
		<< setw(num_col_sm) << setw(num_col_lg) << "Number of"
		<< setw(num_col_lg)  << "Total Credit"
		<< endl;
	outf << left
		<< setw(num_col_lg) << "CRN"
		<< setw(str_col_lg) << "Course"
		<< setw(num_col_sm) << "Hours"
		<< setw(num_col_lg) << "Students"
		<< setw(num_col_lg) << "Hours"
		<< setw(3) << ""
		<< setw(str_col_sm) << "Professor"
		<< endl;
	println('-', output_width, outf);
	for (int i = 0; i < n; i++)
		outf << left << setw(num_col_lg) << c[i].crn << setw(str_col_lg - 5) << c[i].course
		<< right << setw(num_col_sm) << c[i].crhrs << setw(num_col_lg) << c[i].numstu << setw(num_col_lg) << c[i].stucrhrs
		<< setw(8) << "" << left << setw(str_col_sm) << c[i].prof << endl;
	println('-', output_width, outf);
}

void printTotals(classType a[], int n, ofstream &outf)
{
	classType total = initrec;
	for (int i = 0; i < n; i++)
	{
		total.crhrs += a[i].crhrs;
		total.numstu += a[i].numstu;
		total.stucrhrs += a[i].stucrhrs;
	}
	outf << setw(num_col_lg + str_col_lg - 5) << "Totals:"
		<< right
		<< setw(num_col_sm) << total.crhrs
		<< setw(num_col_lg) << total.numstu
		<< setw(num_col_lg) << total.stucrhrs
		<< endl;
	println('-', output_width, outf);
}

void printCourseTotals(classType a[], int n, ofstream &outf)
{
	string courses[5] = {
		"Algebra",
		"Precalculus",
		"Trigonometry",
		"Geometry",
		"Calculus",
	};
	outf << left << setw(num_col_lg) << "Course" << right << setw(output_width / 2 - num_col_lg) << "Total Students" << endl;
	println('-', output_width / 2, outf);
	for (int i = 0; i < 5; i++) {
		outf << left << setw(num_col_lg) << courses[i]
			<< right << setw(output_width / 2 - num_col_lg - 6)
			<< countStuByCourse(courses[i], a, n) << endl;
	}
	println('-', output_width / 2, outf);
}

void println(char a, int n, ofstream &outf)
{
	for (int i = 0; i < n; i++)
		outf << a;
	outf << endl;
}
