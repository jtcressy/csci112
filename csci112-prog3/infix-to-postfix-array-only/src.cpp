#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int maxstack = 20;
const char initstack = '~';

void createstack(char stack[], int &top)
{
    top = -1;
    for (int i = 0; i < maxstack; i++)
        stack[i] = initstack;
}
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
bool fullstack(int top) { return top >= maxstack; }
bool emptystack(int top) { return top < 0; }
void pushstack(char stack[], int &top, char ch)
{
    if (!fullstack(top))
    {
        top++;
        stack[top] = ch;
    }
    else
        cout << "Err: Stack is full. Cannot push value \'" << ch << "\'.\n";
}
char popstack(char stack[], int &top)
{
    char answer = initstack;
    if (!emptystack(top))
    {
        answer = stack[top];
        stack[top] = initstack;
        top--;
    }
    return answer;
}
void infixtoRPN(char stack[], int &top, ifstream &inf, ofstream &outf)
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
                pushstack(stack, top, ch); //put away the parenthesis, we wont need those silly things
                i++;
                continue; //short-circuit so that the parenthesis do not get evaluated as operands
            }
            if (ch == ')')
            {
                //if you see a closing parenthesis
                //shove all operators into the output string
                //then pop the opening parenthesis separately
                while (!emptystack(top) && stack[top] != '(')
                {
                    output += popstack(stack, top);
                }
                if (!emptystack(top))
                {
                    popstack(stack, top);
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
                if (emptystack(top))
                {
                    //if stack is empty, means no operators to compete with
                    pushstack(stack, top, ch);
                }
                else
                {
                    //throw all the operators onto the output unless
                    //one has a lower priority than the current
                    while (!emptystack(top) && stack[top] != '(' && prio <= priority(stack[top]))
                    {
                        output += popstack(stack, top);
                    }
                    //push the lower precedence operator to the stack
                    pushstack(stack, top, ch);
                }
            }
            i++;
        }
        //pop any remaining operators
        while (!emptystack(top))
        {
            output += popstack(stack, top);
        }
        output += "\n"; //create new line in output string
    }
    outf << output;
}

int main()
{
    char stack[maxstack];
    int top;
    createstack(stack, top);
    ifstream inf("infix.dat");
    if (!inf.is_open())
    {
        cout << "ERR: Cannot open file" << endl;
        return 1;
    }
    ofstream outf("rpn.dat");
    infixtoRPN(stack, top, inf, outf);
    return 0;
}