//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//     CSCI112 - Program 6.2 - 5 Sorts and Their Diagnostics - Joel Cressy
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;
struct sortStat
{
    int compares;
    int copies;
    clock_t start;
    clock_t end;
};
sortStat stat;
const int maxarray = 10000;

void initem(double a[], ifstream &inf)
{
    for (int i = 0; i < maxarray; i++)
    {
        a[i] = -1;
    }
    stat = {};
    inf.seekg(0, ios::beg);
}

void printem(ofstream &outf, double a[])
{
    int n = maxarray;
    outf << left << "N = " << n << endl;
    outf << setw(6) << "";
    for (int i = 0; i < n; i += (n / 10))
    //print every n=1000th element
    {
        if (i == n / 2)
            outf << endl
                 << setw(6) << ""; //breakline halfway through
        outf << left << setw(14) << a[i];
    }
    outf << endl
         << endl
         << setw(6) << "";
    outf << right << setw(20) << "Number of Compares = " << setw(15) << left << stat.compares
         << right << setw(20) << "Number of Moves = " << setw(15) << left << stat.copies
         << endl;
    outf << endl
         << setw(6) << "";
    outf << right << setw(20) << "Compares per N = " << setw(15) << left << (stat.compares / maxarray)
         << right << setw(20) << "Moves per N = " << setw(15) << left << (stat.copies / maxarray)
         << endl;
    outf << setw(6) << "" << setw(20) << "Time to complete sort = " << setw(10)
         << left << (stat.end - stat.start) / (double)(CLOCKS_PER_SEC / 1000) << "ms" << endl
         << endl;
}

void swapem(double &a, double &b)
{
    double temp;
    temp = a;
    a = b;
    b = temp;
    stat.copies += 3;
}

void bubblesort(double[]);
void selsort(double[]);
void inssort(double[]);
void impbubsort(double[]);
void quicksort(double[], int, int);

int main()
{
    int numsorts = 5;
    //vector<double> dataset;
    double dataset[maxarray];
    ifstream inf("../prog1/randoms.dat");
    ofstream outf("output.dat");
    outf.setf(ios::fixed);
    outf.precision(4);
    for (int i = 0; i < numsorts; i++)
    {
        int n;
        switch (i)
        {
        case 0:
            outf << "Bubble Sort:" << endl;
            initem(dataset, inf);
            for (int i = 0; i < maxarray; i++)
            {
                inf >> dataset[i] >> ws;
            }
            bubblesort(dataset);
            printem(outf, dataset);
            break;
        case 1:
            outf << "Selection Sort:" << endl;
            //refresh dataset to sort again
            initem(dataset, inf);
            for (int i = 0; i < maxarray; i++)
            {
                inf >> dataset[i] >> ws;
            }
            selsort(dataset);
            printem(outf, dataset);
            break;
        case 2:
            outf << "Insertion Sort: " << endl;
            //refresh dataset to sort again
            initem(dataset, inf);
            for (int i = 0; i < maxarray; i++)
            {
                inf >> dataset[i] >> ws;
            }
            inssort(dataset);
            printem(outf, dataset);
            break;
        case 3:
            outf << "Quick Sort:" << endl;
            //refresh dataset to sort again
            initem(dataset, inf);
            for (int i = 0; i < maxarray; i++)
            {
                inf >> dataset[i] >> ws;
            }
            n = maxarray;

            stat.start = clock();
            quicksort(dataset, 0, n - 1);
            stat.end = clock();
            printem(outf, dataset);
            break;
        case 4:
            outf << "Improved Bubble Sort: " << endl;
            //refresh dataset to sort again
            initem(dataset, inf);
            for (int i = 0; i < maxarray; i++)
            {
                inf >> dataset[i] >> ws;
            }
            impbubsort(dataset);
            printem(outf, dataset);
            break;
        }
    }
    return 0;
}

void bubblesort(double a[])
{
    int n = maxarray;
    stat.start = clock();
    for (int k = 0; k < n - 1; k++)
        for (int l = 0; l < n - 1; l++)
        {
            stat.compares++;
            if (a[l] > a[l + 1])
            {
                swapem(a[l], a[l + 1]);
            }
        }
    stat.end = clock();
}

void selsort(double a[])
{
    int j, k, small, n = maxarray;
    stat.start = clock();
    if (n > 1)
    {
        //Original algorithm starts at k = 1.
        //Why would it do that? You end up skipping a[0]
        //thus not sorting the array properly.
        for (k = 0; k < n - 1; k++)
        {
            small = k;
            for (j = k + 1; j < n; j++)
            {
                stat.compares++;
                if (a[j] < a[small])
                {
                    small = j;
                }
            }
            if (small != k)
            {
                swapem(a[k], a[small]);
            }
        }
    }
    stat.end = clock();
}

void inssort(double a[])
{
    int j, k, n = maxarray;
    stat.start = clock();
    for (k = n - 1; k >= 0; k--)
    {
        j = k + 1;
        while (j < n && a[j] < a[j - 1])
        {
            stat.compares++;
            swapem(a[j], a[j - 1]);
            j++;
        }
    }
    /*
    //This does not work. I blame the inline swap statements however this
	// may change the algorithm. If it does, I accept any points off.
    for (k = n - 1; k > 0; k--)
    {
        j = k + 1;
        save = a[k];
        a[n + 1] = save;
        while (save > a[j])
        {
            a[j - 1] = a[j];
            j++;
        }
        a[j - 1] = save;
    }
    */
    stat.end = clock();
}

void impbubsort(double a[])
{
    int n = maxarray;
    bool sorted = false;
    stat.start = clock();
    int i = 1;
    while (!sorted)
    {
        sorted = true;
        for (int j = 0; j < n - i; j++)
        {
            stat.compares++;
            if (a[j] > a[j + 1])
            {
                sorted = false;
                swapem(a[j], a[j + 1]);
            }
        }
        i++;
    }
    stat.end = clock();
}

void quicksort(double a[], int left, int right)
{
    if (left < right)
    {
        int j = left;
        int k = right + 1;
        do
        {
            do
            {
                j++;
                stat.compares++;
            } while (!(a[j] >= a[left]) && !(j > k));
            do
            {
                k--;
                stat.compares++;
            } while (!(a[k] <= a[left]) && !(k < 0));
            if (j < k)
            {
                swapem(a[j], a[k]);
            }
            stat.compares++;
        } while (!(j > k));
        swapem(a[left], a[k]);
        quicksort(a, left, k - 1);
        quicksort(a, k + 1, right);
    }
}
