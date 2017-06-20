//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//                       Twonums Demo Class
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
#pragma once
using namespace std;
class twonums
{
private:
	double one, two;
public:
	twonums();
	twonums(double, double);
	void print(ostream&);
	double getone() { return one; }
	double gettwo() { return two; }
	void setone(double a) { one = a; }
	void settwo(double a) { two = a; }
	double sum();
};
twonums operator+(twonums, twonums);

twonums::twonums()
{
	one = 0;
	two = 0;
}

twonums::twonums(double a, double b)
{
	one = a;
	two = b;
}

void twonums::print(ostream &os)
{
	os.setf(ios::fixed);
	os.precision(3);
	os << "This object has number one = " << setw(10)
		<< one << " and number two = " << setw(10) << two
		<< endl << endl;
}

double twonums::sum()
{
	return one + two;
}

twonums operator +(twonums a, twonums b)
{
	twonums c;
	c.setone(a.getone() + b.getone());
	c.settwo(a.gettwo() + b.gettwo());
	return c;
}
