//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//                   Headers for Playclasses - Joel Cressy
//                   Class assignment 1
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
#pragma once
class playclass1
{
public:
	double length, width;
	void print(ostream&);
	playclass1();
	playclass1(double,double);
};
class playclass2
{
private:
	double length, width;
public:
	void setlength(double);
	void setwidth(double);
	double getlength();
	double getwidth();
	void print(ostream&);
	playclass2();
	playclass2(double,double);
};
