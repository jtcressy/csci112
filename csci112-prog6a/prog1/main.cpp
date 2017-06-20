//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//       CSCI112 - Program 6.1 - Random Number Generator - Joel Cressy
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>

using namespace std;

int getmaxnum()
{
    int out;
    cout << "enter amount of random numbers: ";
    cin >> out;
    cout << endl;
    return out;
}

void printrand(int maxnum)
{
    ofstream outf("randoms.dat");
    outf.setf(ios::fixed);
    outf.precision(4);
    int i = 0;
    double num;
    while (i < maxnum)
    {
        //Core formula: rand() % 2N^3 - N^3
        srand(time(NULL) * i); //initial seed
        srand(time(NULL) * i * (rand() % (2*maxnum*maxnum*maxnum) - (maxnum*maxnum*maxnum))); //advanced seed
        num = rand() % (2*maxnum*maxnum*maxnum) - (maxnum*maxnum*maxnum); //harvest
        outf << (num / maxnum) << endl;
        i++;
    }
}

int main(int argc, char *argv[])
{
    //Call program with first argument as N elements,
    // Or answer interactive prompt to supply N.
    if (argc > 1)
        printrand(atoi(argv[1]));
    else
        printrand(getmaxnum());
    return 0;
}
