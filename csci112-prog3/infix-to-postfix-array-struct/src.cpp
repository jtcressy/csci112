//Joel Cressy
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int maxstack = 200;
const char initstack = '~';

struct stacktype
{
    int top;
    char data[maxstack];
    void create()
    {
        top = -1;
        for (int i = 0; i < maxstack; i++)
            data[i] = initstack;
    }
    bool isFull() { return top >= maxstack; }
    bool isEmpty() { return top < 0; }
    void push(char ch)
    {
        if (!isFull())
        {
            top++;
            data[top] = ch;
        } 
        else
            cout << "Err: Stack full. Cannot push value\n";
    }
    char pop()
    {
        char answer = initstack;
        if(!isEmpty())
        {
            answer = data[top];
            data[top] = initstack;
            top--;
        }
        return answer;
    }
};

void readem(stacktype &stack, ifstream &inf)
{
    string input;
    while (!inf.eof())
    {
        inf >> input;
        int len = input.length();
        for (int i = 0; i < len; i++)
        {
            stack.push(input[i]);
        }
        stack.push('\n');
    }
}

void printem(stacktype &stack, ofstream &outf)
{
    string output = "";
    while (!stack.isEmpty())
    {
        output = stack.pop() + output;
    }
    cout << output << endl;
}

int main()
{
    stacktype stack; //would not want to use this identifier if using <stl_stack.h> LOL
    stack.create();
    ifstream inf("infix.dat");
    ofstream outf("rpn.dat");
    readem(stack,inf);
    printem(stack,outf);
    return 0;
}