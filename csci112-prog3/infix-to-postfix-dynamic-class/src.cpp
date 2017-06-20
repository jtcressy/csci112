//joel cressy
//class version of infix-to-postfix (csci112-prog3)
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "./stacktype.h"

using namespace std;

int priority(char ch)
{
    switch (ch)
    {
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0; //return 0 if not an operator
    }
}

void infixToRPN(stacktype s, ifstream &inf, ofstream &outf)
{
    string input;
    string output = "";
    while (inf.is_open() && !inf.eof())
    {
        inf >> input;
        int prio;
        unsigned int i = 0;
        char ch;
        while (i < input.length())
        {
            ch = input[i];
            if (ch == '(')
            {
                s.push(ch); //put away the parenthesis, we wont need those silly things
                i++;
                continue; //short-circuit so that the parenthesis do not get evaluated as operands
            }
            if (ch == ')')
            {
                //if you see a closing parenthesis
                //shove all operators into the output string
                //then pop the opening parenthesis separately
                while (!s.isEmpty() && s.getTop() != '(')
                {
                    output += s.pop();
                }
                if (!s.isEmpty())
                {
                    s.pop();
                }
                i++;
                continue; //short-circuit again so that the parenthesis do not get evaluated as operands
            }
            prio = priority(ch);
            if (prio == 0)
            {
                //this means operand, so just throw it on the output
                output += ch;
            }
            else
            {
                if (s.isEmpty())
                {
                    //if stack is empty, means no operators to compete with
                    s.push(ch);
                }
                else
                {
                    //throw all the operators onto the output unless
                    //one has a lower priority than the current
                    while (!s.isEmpty() && s.getTop() != '(' && prio <= priority(s.getTop()))
                    {
                        output += s.pop();
                    }
                    //push the lower precedence operator to the stack
                    s.push(ch);
                }
            }
            i++;
        }
        //pop any remaining operators
        while (!s.isEmpty())
        {
            output += s.pop();
        }
        output += "\n"; //create new line in output string
    }
    outf << output;
}
int main()
{
    stacktype stack;
    ifstream inf("infix.dat");
    ofstream outf("rpn.dat");
    infixToRPN(stack,inf,outf);
    return 0;
}