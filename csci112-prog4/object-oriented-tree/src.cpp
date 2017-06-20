#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "treetype.h"

using namespace std;

template<class T>
void printformatted(treetype<T> t,string filler, ostream &os)
{
    for (int i = 0; i < t.size(); i++)
    {
        if (i == t.size() - 1) filler = "";
        os << t[i] << filler;
    }
    os << endl;
}

template<class T>
void printem1(treetype<T> t, ofstream &outf)
{
    t.setorder(t.INORDER);
    outf << "Inorder traversal: ";
    printformatted(t,", ",outf);
    outf << "Deleted node 71, postorder traversal: ";
    t.del(71);
    t.setorder(t.POSTORDER);
    printformatted(t,", ",outf);
    outf << "Deleted node 38, preorder traversal: ";
    t.del(38);
    t.setorder(t.PREORDER);
    printformatted(t,", ",outf);
    outf << "Inorder traversal: ";
    t.setorder(t.INORDER);
    printformatted(t,", ",outf);
}

template<class T>
void printem2(treetype<T> t, ofstream &outf)
{
    t.setorder(t.INORDER);
    outf << "Inorder traversal: ";
    printformatted(t,", ",outf);
}

int main(int argc, char* argv[])
{
    treetype<int> t;
    string infile = (argc > 1) ? argv[0] : "input.dat";
    ifstream inf(infile);
    ofstream outf("output.ot");
    while (!inf.eof())
    {
        int data;
        inf >> data;
        t.ins(data);
    }
    printem2<int>(t, outf); //use printem2 if huge dataset
    printem1<int>(t, outf);
    return 0;
}
