//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//                     Test Program - Class Assignment 1
//                               Joel Cressy
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

#include <iostream>
#include <iomanip>
#include <fstream>
#include "playclass.cpp"

using namespace std;

int main(int argc, char* argv[])
{
	//Step 2A
	playclass1 a;
	playclass2 b;
	ofstream outf("playing.ot");

	//Step 2B
	outf << endl << "-- Step 2B --" << endl;
	a.print(outf);
	b.print(outf);

	//Step 3A
	outf << endl << "-- Step 3A --" << endl;
	playclass1 x(6.25,4.38);
	playclass2 y(10.00,12.75);
	x.print(outf);
	y.print(outf);

	//Step 3B
	{
		outf << endl << "-- Step 3B --" << endl;
		double area;
		area = x.length * x.width;
		outf << "Area of x: " << area << endl;
		area = y.getlength() * y.getwidth();
		outf << "Area of y: " << area << endl;
	}
	//Step 3C
	{
		double area;
		outf << endl << "-- Step 3C --" << endl;
		a.length = 6.50;
		a.width = 3.33;
		area = a.length * a.width;
		outf << "Area of a: " << area << endl;
	}
	//Step 3D
	{
		double area;
		outf << endl << "-- Step 3D --" << endl;
		b.setlength(11.00);
		b.setwidth(8.50);
		area = b.getlength() * b.getwidth();
		outf << "Area of b: " << area << endl;
	}
	return 0;
}
