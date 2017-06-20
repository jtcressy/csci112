//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//       CSCI112 - Extra Credit - Templated Stack Class - Joel Cressy
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "dynstack.h"
#include "arrstack.h"

using namespace std;

//Step 1 - Struct
struct rectype
{
    int id;
    string name;
};

void readem(arrstack<rectype> &s1, dynstack<rectype> &s2)
{
    ifstream inf("input.dat");
    while (!inf.eof())
    {
		rectype temp;
		inf >> temp.id >> temp.name;
		s1.push(temp);
		s2.push(temp);
    }
}

void printem(arrstack<rectype> &s1, dynstack<rectype> &s2)
{
    ofstream outf("output.dat");
    outf << left;
    outf << "Step 4 - Output" << endl
	 << endl;
    outf << "Array version of stack:" << endl;
    outf << setfill(':') << setw(16) << "" << setfill(' ') << endl;
    while (!s1.empty())
    {
		outf << setw(6) << s1.getTop().id << setw(10) << s1.getTop().name << endl;
		s1.pop();
    }
    
    outf << endl
	 << "Dynamically linked version of stack:" << endl;
     outf << setfill(':') << setw(16) << "" << setfill(' ') << endl;
    while (!s2.empty())
    {
		outf << setw(6) << s2.getTop().id << setw(10) << s2.getTop().name << endl;
		s2.pop();
    }
    
    outf << setfill(':') << setw(16) << "" << setfill(' ') << endl;
}

int main()
{
    //Step 2 - Instantiate stack
    arrstack<rectype> s1;
    dynstack<rectype> s2;

    //Step 3 - Read data into stack
    readem(s1, s2);

    //Step 4 - Output data from stack
    printem(s1, s2);

    return 0;
}
