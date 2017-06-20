#include <string>
#include <ctime>
#include <vector>
#include <iostream>
using namespace std;
class sorts
{
  public:
    sorts();
    // Using an enumerator to store pre-defined settings
    enum SortType
    {
        BUBBLE,
        IMPROVED_BUBBLE,
        SELECTION,
        INSERTION,
        QUICK
    };
    sorts(SortType);
    sorts(vector<double>, SortType);
    void reset(vector<double>, SortType);
    void setmode(SortType);
    void sort();
    bool isSorted();
    string getDebugInfo();

    friend istream &operator>>(istream &is, sorts &a);
    friend ostream &operator<<(ostream &os, sorts &a);

  private:
    int compares;
    int copies;
    clock_t start;
    clock_t finish;
    SortType sortmode;
    vector<double> dataset;
    bool sorted;
    void swapem(double&,double&);
    void bubble();
    void imp_bubble();
    void selection();
    void insertion();
    void quick(int,int);
};
#include "sorts.cpp"