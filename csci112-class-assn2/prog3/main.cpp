//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//         CSCI 112 - Class Assignment 2 - Program 3 - Joel Cressy
//    Use the STL Queue to process a set of records and output to file.
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

struct Major
{
    int count;
    string name;
};

queue<Major> readem()
{
    ifstream inf("input.dat");
    queue<Major> out;
    while (!inf.eof())
    {
        Major temp;
        inf >> temp.count >> temp.name >> ws;
        out.push(temp);
    }
    return out;
}

void printem(queue<Major> Q)
{
    ofstream outf("output.dat");
    outf << "Number of Majors in queue: " << Q.size() << endl
         << endl;
    outf << left << setw(15) << "Major" << setw(5) << "Count" << endl;
    outf << setfill('=') << setw(20) << "" << setfill(' ') << endl;
    while (!Q.empty())
    {
        outf << setw(15) << Q.front().name << setw(5) << Q.front().count << endl;
        Q.pop();
    }
}

int main()
{
    printem(readem());
    return 0;
}