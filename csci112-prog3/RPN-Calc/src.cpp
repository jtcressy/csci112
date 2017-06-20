//Joel Cressy

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int maxstack = 20;
const double initstack = 0.0;

void createStack(double stack[], int &top)
{
    int i;
    top = -1;
    for (i = 0; i < maxstack; i++) stack[i] = initstack;
}

bool fullstack(int top)
{
    return top >= maxstack - 1;
}

bool emptystack(int top)
{
    return top < 0;
}

void push(double stack[], int &top, double num)
{
    if(!fullstack(top))
    {
        top++;
        stack[top] = num;
    }
    else
        cout << "The stack is full! Can't push value\n";
}

double pop(double stack[], int &top)
{
    double answer = initstack;
    if (!emptystack(top))
    {
        answer = stack[top];
        stack[top] = initstack;
        top--;
    }
    return answer;
}

double chartodouble(char ch)
{
    double answer;
    if(ch == '0')
        answer = 0.0;
    else if(ch == '1')
        answer = 1.0;
    else if(ch == '2')
        answer = 2.0;
    else if(ch == '3')
        answer = 3.0;
    else if(ch == '4')
        answer = 4.0;
    else if(ch == '5')
        answer = 5.0;
    else if(ch == '6')
        answer = 6.0;
    else if(ch == '7')
        answer = 7.0;
    else if(ch == '8')
        answer = 8.0;
    else
        answer = 9.0;
    return answer;
}

void readem(double stack[], int &top)
{
    string instring;
    int currLine = 0;
    double value, num, x, y;
    int i, len;
    char ch;
    ifstream inf;
    ofstream outf;
    inf.open("rpn.dat");
    outf.open("rpn.ot");
    outf.setf(ios::fixed);
    outf.precision(3);

    while (!inf.eof())
    {
        inf >> instring;
        len = instring.length();
        value = 0;
        for (i = 0; i < len; i++)
        {
            ch = instring[i];
            if (ch >= '0' && ch <= '9')
            {
                num = chartodouble(ch);
                push(stack, top, num);
            }
            else
            {
                y = pop(stack,top);
                x = pop(stack,top);
                switch(ch)
                {
                    case '+': value = x + y;
                        break;
                    case '-': value = x - y;
                        break;
                    case '*': value = x * y;
                        break;
                    case '/': value = x / y;
                        break;
                    default: cout << "Invalid operator (" << ch << ") at index (" << i << ") on line (" << currLine << ")" << endl;
                }
                push(stack,top,value);
            }
        }
        value = pop(stack,top);
        outf << setw(3) << currLine << ": " << setw(10) << instring << setw(3) << "=" << setw(8) << value << endl << endl;
        currLine++;
    }
}

int main()
{
    double stack[maxstack];
    int top;
    createStack(stack,top);
    readem(stack,top);
    return 0;
}