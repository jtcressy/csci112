#include <iostream>
#include <iomanip>
#include <fstream>
#include "RationalNum.h"
#include <stack>
using namespace std;

stack<RationalNum> readem(ifstream& inf, stack<RationalNum> buffer)
{
    RationalNum temp;
    while (!inf.eof()){
	inf >> temp;
	buffer.push(temp);
    }
    return buffer;
}

stack<RationalNum> printem(ofstream& outf, stack<RationalNum> buffer)
{
    int i = 0;
    while(!buffer.empty())
    {
	outf << "line " << i << ": " << buffer.top() << endl;
	buffer.pop();
    }
    return buffer;
}    

int main()
{
	ifstream inf("test.dat");
	ofstream outf("output.dat");
	RationalNum x, y(1,2);
	outf << "Test constructors, x, y(1,2)" << endl;
	outf << "x: ";
	x.print(outf);
	outf << "y: ";
	y.print(outf);

	outf << "Test overloaded operator >>" << endl;
	inf >> x >> y;
	outf << "x: ";
	x.print(outf);
	outf << "y: ";
	y.print(outf);
	
	outf << "Test overloaded operator <<" << endl;
	outf << "x: " << x << endl;
	outf << "y: " << y << endl;

	outf << "Test reduction method, 13/52 -> 1/4" << endl;
	RationalNum reductest;
	inf >> reductest;
	outf << "reductest: " << reductest << endl;

	outf << "Read whole file and output using << and >>" << endl;
	stack<RationalNum> buffer;
	buffer = readem(inf, buffer);
	buffer = printem(outf, buffer);
	return 0;
}
