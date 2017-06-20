//Joel Cressy
//Fun Names: head -> kirk, tail -> picard
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//set output column widths
const int num_col_w = 6;
const int str_col_w = 12; 
const int output_width = (num_col_w + str_col_w*2);
const int num_col = 3; //number of columns

struct linklist
{
    string last;
    string first;
    int id;
    linklist *link;
};

//<Not Necessary For Assignment>
void println(char a, int n);
int sizelist(linklist *kirk, linklist *picard);
int countlist(linklist *kirk, linklist *picard);
void printDebug(linklist *&kirk, linklist *&picard);
//</Not Necessary For Assignment>

void createlist(linklist *&kirk, linklist *&picard) 
{
    kirk = new linklist;
    picard = new linklist;
    kirk -> id = -1;
    kirk -> last = "AAAAAAAA";
    kirk -> first = "AAAAAAAA";
    picard -> id = 9999;
    picard -> last = "zzzzzzzz";
    picard -> first = "zzzzzzzz";
    kirk -> link = picard;
}

bool emptylist(linklist *kirk, linklist *picard)
{
    return kirk -> link == picard;
}

void deletelist(linklist *kirk, linklist *picard, string last)
{
    linklist *C, *previous, *next;
    //step one - init condition - set current to one entry after kirk
    previous = kirk;
    C = kirk -> link;
    //traverse list until last name is not greater than current record
    while (C!=picard && last > C -> last) 
    {
        previous = C;
        C = C -> link;
    }
    //step two - if found, assign next, update links, delete current(C).
    if (C!=picard && last == C -> last) 
    {
        next = C -> link;
        previous -> link = next;
        delete C;
    }
    else
        cout << "Item not found in list for last name: " << last << endl;
}

void insertlist(linklist *kirk, linklist *picard, string last, string first, int id)
{
    linklist *newentry, *previous, *next;
    //step 1 - create new record
    newentry = new linklist;
    newentry -> id = id;
    newentry -> last = last;
    newentry -> first = first;
    //step 2 - init condition and traverse the list
    previous = kirk;
    next = kirk -> link;
    while (next != picard && last > next -> last) 
    {
        previous = next;
        next = next -> link;
    }
    //step 3 - update links to include the new entry as an item
    previous -> link = newentry;
    newentry -> link = next;
}

void readem(linklist *&kirk, linklist *&picard, ifstream &inf)
{
    string first, last;
    int id;
    while (!inf.eof())
    {
        inf >> last >> first >> id;
        last.erase(last.find(','),1);
        insertlist(kirk,picard,last,first,id);
    }
}

void printlnf(char a, int n, ofstream &outf)
{
    for (int i = 0; i < n; i++)
        outf << a;
    outf << endl;
}

void printem(linklist *kirk, linklist *picard, ofstream &outf)
{
    printlnf('-',output_width,outf);
    //format column titles dynamically using const global vars
    string titles[num_col] = {"ID","First","Last"};
    outf << right << setw((num_col_w + titles[0].length()) / 2) 
        << titles[0] << setw(num_col_w / 2) << ""
        << left << setw(str_col_w) << titles[1]
        << setw(str_col_w) << titles[2] << endl;
    printlnf('-',output_width,outf);
    
    linklist *C;
    if (!emptylist(kirk,picard))
    {
        C = kirk -> link;
        while (C != picard)
        { //center output in columns based on const global vars
            outf << right << setw((num_col_w + 3) / 2) << (C -> id) 
                << setw(num_col_w / 2) << ""
                << left
                << setw(str_col_w) << (C -> first)
                << setw(str_col_w) << (C -> last)
                << endl;
            C = C -> link;
        }
    }
    else
        cout << "The list is empty!" << endl;
    printlnf('-',output_width,outf);
}

int main(int argc, char* argv[])
{
    ifstream inf("input.dat");
    ofstream outf("output.ot");
    linklist *kirk, *picard;
    createlist(kirk,picard);
    readem(kirk,picard,inf);
    printem(kirk,picard,outf);
    deletelist(kirk,picard,"Solo");
    outf << "Deleted entry for Han Solo: " << endl;
    printem(kirk,picard,outf);
    insertlist(kirk,picard,"Skywalker","Luke",333);
    outf << "Inserted Luke Skywalker into list: " << endl;
    printem(kirk,picard,outf);
    
    //<Debug Only - Not for assignment>
    string arg = "-d";
    if (argv[argc-1] == arg)
        printDebug(kirk,picard);
    cout << "exited" << endl;
    //</Debug Only - Not for assignment>
    return 0;
}




//<Not necessary for assignment>
void println(char a, int n) 
{
    for (int i = 0; i < n; i++)
        cout << a;
    cout << endl;
}

int sizelist(linklist *kirk, linklist *picard)
{
    linklist *C;
    int total = 0;
    if (!emptylist(kirk,picard))
    {
        C = kirk -> link;
        while (C != picard)
        {
            total += sizeof(*C);
            C = C -> link;
        }
    }
    return total;
}
int countlist(linklist *kirk, linklist *picard)
{
    linklist *C;
    int total = 0;
    if (!emptylist(kirk,picard))
    {
        C = kirk -> link;
        while (C != picard)
        {
            total++;
            C = C -> link;
        }
    }
    return total;
}

void printDebug(linklist *&kirk, linklist *&picard) 
{
    println('-',output_width);
    cout << "Memory Addresses for Linked List" << endl;
    println('-',output_width);
    cout << "kirk: " << kirk << endl;
    cout << "picard: " << picard << endl;
    println('-',output_width);
    cout << "Size of each" << endl;
    println('-',output_width);
    cout << "kirk: " << sizeof(*kirk) << " Bytes" << endl;
    cout << "picard: " << sizeof(*picard) << " Bytes" << endl;
    cout << "Entire list: " << sizelist(kirk,picard) << " Bytes" << endl;
    cout << "Number of elements: " << countlist(kirk,picard) << endl;
    println('-',output_width);
    cout << "List is empty?: " << boolalpha << emptylist(kirk,picard) << endl;
    println('-',output_width);
}
//</Not necessary for assignment>
