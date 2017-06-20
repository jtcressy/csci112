#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "sorts.h"
using namespace std;

int main()
{
    ifstream inf("../prog1/randoms.dat");
    ofstream outf("testoutput.dat");
    outf.setf(ios::fixed);
    outf.precision(4);
    vector<double> unsorted;
    while (!inf.eof())
    {
        double temp;
        inf >> temp >> ws;
        unsorted.push_back(temp);
    }
    sorts data;
    
    data.reset(unsorted,sorts::SortType::BUBBLE);
    data.sort();
    outf << data;

    data.reset(unsorted,sorts::SortType::IMPROVED_BUBBLE);
    data.sort();
    outf << data;

    data.reset(unsorted,sorts::SortType::QUICK);
    data.sort();
    outf << data;
    
    data.reset(unsorted,sorts::SortType::INSERTION);
    data.sort();
    outf << data;

    data.reset(unsorted,sorts::SortType::SELECTION);
    data.sort();
    outf << data;

    return 0;
}