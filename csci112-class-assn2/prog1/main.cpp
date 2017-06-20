//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//          CSCI 112 - Class Assignment 2 - Program 1 - Joel Cressy
//            Test a templated swap function with three datatypes
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct intStringType
{
    int id;
    string str;
};

template <class T>
void swapem(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    ofstream outf("output.dat");

    //Step A
    {
        outf << "Step A - Testing with Integers:" << endl;
        int a = 2, b = 4;
        outf << "Before swap: a = " << a << ", b = " << b << endl;
        swapem<int>(a, b);
        outf << "After swap: a = " << a << ", b = " << b << endl;
        outf << endl;
    }

    //Step B
    {
        outf << "Step B - Testing with Strings:" << endl;
        string a = "Henry", b = "James";
        outf << "Before swap: a = " << a << ", b = " << b << endl;
        swapem<string>(a, b);
        outf << "After swap: a = " << a << ", b = " << b << endl;
        outf << endl;
    }

    //Step C
    {
        outf << "Step C - Testing with struct (int, string):" << endl;
        intStringType a = {1234, "Jim"}, b = {9894, "Zelda"};
        outf << "Before swap: a = {" << a.id << ", \"" << a.str << "\"} b = {" << b.id << ", \"" << b.str << "\"}" << endl;
        swapem<intStringType>(a, b);
        outf << "After swap: a = {" << a.id << ", \"" << a.str << "\"} b = {" << b.id << ", \"" << b.str << "\"}" << endl;
        outf << endl;
    }
    return 0;
}