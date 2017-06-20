//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//              Implementation file for Playclasses
//              Class Assignment 1 - Joel Cressy
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

#include "playclass.h"
playclass1::playclass1()
{
	length = 2.0;
	width = 1.0;
}
playclass2::playclass2()
{
	length = 4.0;
	width = 2.0;
}
playclass1::playclass1(double l, double w)
{
		length = l;
		width = w;
}
playclass2::playclass2(double l, double w)
{
		length = l;
		width = w;
}
double playclass2::getlength()
{
	return length;
}
double playclass2::getwidth()
{
	return width;
}
void playclass2::setlength(double l)
{
	length = l;
}
void playclass2::setwidth(double w)
{
	width = w;
}
void playclass1::print(ostream& os)
{
	int oldprecision = os.precision();
	os.setf(ios::fixed);
	os.precision(2);
	os << "The playclass1 object has:  length = " << right << length << left << "  width = " << right << width << left << endl;
	os.unsetf(ios::fixed);
	os.precision(oldprecision);
}
void playclass2::print(ostream& os)
{
	int oldprecision = os.precision();
	os.setf(ios::fixed);
	os.precision(2);
	os << "The playclass2 object has:  length = " << right << length << left << "  width = " << right << width << left << endl;
	os.unsetf(ios::fixed);
	os.precision(oldprecision);
}

