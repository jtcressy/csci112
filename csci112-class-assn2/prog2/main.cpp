//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//          CSCI 112 - Class Assignment 2 - Program 2 - Joel Cressy
//  Use a vector to store integers, an iterator pointer arithmetic for output,
//                   and system sort() to sort the vector.
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> readem()
{
    ifstream inf("input.dat");
    vector<int> out;
    while (!inf.eof())
    {
        int temp;
        inf >> temp;
        out.push_back(temp);
    }
    return out;
}

void printem(vector<int> vec)
{
    ofstream outf("output.dat");
    vector<int>::iterator vecIt;
    outf << "Iterator output before sorting: " << endl;
    for (vecIt = vec.begin(); vecIt != vec.end(); ++vecIt)
        outf << *vecIt << " ";
    outf << endl;
    sort(vec.begin(), vec.end());
    outf << "Iterator output after sorting: " << endl;
    for (vecIt = vec.begin(); vecIt != vec.end(); ++vecIt)
        outf << *vecIt << " ";
    outf << endl;
}

int main()
{
    printem(readem());
    return 0;
}
