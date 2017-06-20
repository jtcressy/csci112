//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//              CSCI 112 - Program 6 - Joel Cressy
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
#include <iostream>
#include <iomanip>
#include <fstream>
#include "RationalNum.h"

using namespace std;

const int cols = 2, rows = 5;

void readem(RationalNum a[][cols])
{
    ifstream inf("input.dat");
    for (int j = 0; j < rows; j++)
        for (int i = 0; i < cols; i++)
            inf >> a[j][i];
}

void printem(RationalNum a[][cols])
{
    ofstream outf("output.dat");
    outf << "Rational Number Tests And Results" << endl;
    outf << setfill(':') << setw(54) << "" << setfill(' ') << endl;
    outf << "Number Pair  |    +    |    -    |    *    |    /    |" << endl;
    for (int i = 0; i < rows; i++)
        outf << setw(6) << a[i][0] << ", " << setw(4) << a[i][1]
            << setw(10) << (a[i][0] + a[i][1])
            << setw(10) << (a[i][0] - a[i][1])
            << setw(10) << (a[i][0] * a[i][1])
            << setw(10) << (a[i][0] / a[i][1])
            << endl;
}

int main() 
{
    RationalNum nums[rows][cols];
    readem(nums);
    printem(nums);
    return 0;
}
