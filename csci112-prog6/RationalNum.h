//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//                 Rational Numbers Headers and Definitions
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
#ifndef ofstream
#include <fstream>
#endif
using namespace std;
class RationalNum
{
public:
    RationalNum();
    RationalNum(int,int);
    int getNum();
    int getDen();
    void setNum(int);
    void setDen(int);
    void print(ofstream&);
    friend RationalNum operator +(RationalNum, RationalNum);
    friend RationalNum operator -(RationalNum, RationalNum);
    friend RationalNum operator *(RationalNum, RationalNum);
    friend RationalNum operator /(RationalNum, RationalNum);
    friend istream& operator >>(istream&,RationalNum&);
    friend ostream& operator <<(ostream&,RationalNum);
private:
    int num, den;
    bool undefined;
    void reduce();
};
RationalNum operator +(RationalNum, RationalNum);
RationalNum operator -(RationalNum, RationalNum);
RationalNum operator *(RationalNum, RationalNum);
RationalNum operator /(RationalNum, RationalNum);
istream& operator >>(istream&,RationalNum&);
ostream& operator <<(ostream&,RationalNum);
#include "RationalNum.cpp"
