//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//                      Rational Numbers Implementation
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
RationalNum::RationalNum()
{
    num = 0;
    den = 1;
    undefined = false;
}
RationalNum::RationalNum(int n, int d)
{
    if (d !=0)
    {
        num = n;
        den = d;
        reduce();
        undefined = false;
    }
    else
    {
        num = num;
        den = 1;
        undefined = true;
        cerr << "Invalid input: Cannot set denominator to 0!" << endl;
    }
}
int RationalNum::getNum()
{
    return num;
}
int RationalNum::getDen()
{
    return den;
}
void RationalNum::setNum(int n)
{
    num = n;
    reduce();
}
void RationalNum::setDen(int d)
{
    if (d != 0)
    {
        den = d;
        reduce();
        undefined = false;
    }
    else
    {
        den = 1;
        undefined = true;
        cerr << "Invalid input: Cannot set denominator to 0!" << endl;
    }
}
void RationalNum::print(ofstream& outf)
{
    if (!undefined)
        outf << "Numerator = " << num << " and Denominator = " << den << endl;
    else
        outf << "Err: This rational number is undefined.";
}
void RationalNum::reduce()
{
    //I found the euclidean algorithm to be rather elegant
    int n = num, d = den;
    while (d!=0)
    {
        int temp = d;
        d = n % d;
        n = temp;
    } //n is now the GCD
    num = num/n;
    den = den/n;
    //divide by the gcd and your fraction is now reduced
    //fix signs
    if (den < 0)
    {
        num = -num;
        den = -den;
    }
    if (num == 0) den = 1;
}
RationalNum operator +(RationalNum x, RationalNum y)
{
    x.reduce();
    y.reduce();
    RationalNum z;
    if (x.den == y.den)
    {
        z.num = x.num + y.num;
        z.den = x.den;
    }
    else
    {
        z.num = x.num * y.den + y.num * x.den;
        z.den = x.den * y.den;
    }
    z.reduce();
    return z;
}
RationalNum operator -(RationalNum x, RationalNum y)
{
    x.reduce();
    y.reduce();
    RationalNum z;
    if (x.den == y.den)
    {
        z.num = x.num - y.num;
        z.den = x.den;
    }
    else
    {
        z.num = x.num * y.den - y.num * x.den;
        z.den = x.den * y.den;
    }
    z.reduce();
    return z;
}
RationalNum operator *(RationalNum x, RationalNum y)
{
    RationalNum z;
    z.num = x.num * y.num;
    z.den = x.den * y.den;
    z.reduce();
    return z;
}

RationalNum operator /(RationalNum x, RationalNum y)
{ //flip the dividend then just multiply
    RationalNum z;
    z.num = x.num * y.den;
    if (y.num != 0)
    {
        z.den = x.den * y.num;
    }
    else
    {
        z.den = x.den * 1;
        z.undefined = true;
        cerr << "Invalid input: Cannot set denominator to 0!" << endl;
    }
    z.reduce();
    return z;
}
istream& operator >>(istream& ins, RationalNum& a)
{
    char ch;
    int d;
    ins >> ch >> a.num >> ch >> d >> ch >> ws;
    if (d !=0)
    {
        a.den = d;
    }
    else
    {
        a.den = 1;
        a.undefined = true;
        cerr << "Invalid input at column " << ins.tellg() << ": Cannot set denominator to 0!" << endl;
    }
    a.reduce();
    return ins;
}
ostream& operator <<(ostream& os, RationalNum a)
{
    if (!a.undefined)
    {
        a.reduce();
        stringstream temp;
        string out;
        temp << a.num << "/" << a.den;
        temp >> out;
        os << out;
    }
    else
    {
        os << "Undef";
    }
    return os;
}
