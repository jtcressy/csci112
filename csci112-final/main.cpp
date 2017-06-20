//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//                  CSCI 112 - Final Project - Lexical Scanner
//                              Joel Cressy
//                     Comments for organizational purposes
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

enum StateType
{
    newtkn,
    resword,
    var,
    integer,
    real,
    delim
};
enum CharType
{
    letter,
    digit,
    period,
    delimeter,
    blank,
    pod,
    eoln,
    illegal
};

const int actionrows = 6,
          actioncols = 8,
          staterows = 6,
          statecols = 8,
          explainrows = 13,
          reservedrows = 14;
const char validDelims[] = {
    '+', '-', '*', '/', '^', '&', '(', ')', '=', ',', '<', '>', '\"',
};

//::::::::::::::::::::::::::Helper Functions::::::::::::::::::::::::::::::::
StateType strtostate(string);
string statetostr(StateType);
bool isDelim(char);
bool isResWord(string,string[]);
CharType getchartype(char);
string chartypetostr(CharType);
template <class T>
void swap(T &, T &);
template <class T>
void bubsort(T[],int);
//::::::::::::::::::::::::::Input Functions:::::::::::::::::::::::::::::::::
void readAction(int[actionrows][actioncols]);
void readState(StateType[staterows][statecols]);
void readExpl(string[]);
void readResWords(string[]);
//::::::::::::::::::::::::::Output Functions::::::::::::::::::::::::::::::::
void printAction(int[actionrows][actioncols], ofstream &);
void printState(StateType[staterows][statecols], ofstream &);
void printExpl(string[], ofstream &);
void printResWords(string[], ofstream &);

int main()
{
    ofstream outf("final.dat");
    int actions[actionrows][actioncols];
    // actions[StateType][CharType]
    StateType FSM[staterows][statecols];
    // FSM[StateType][CharType]
    string explanations[explainrows];
    // explanations[actions[state][chartype]]
    string reservedwords[reservedrows];

    readAction(actions);
    readState(FSM);
    readExpl(explanations);
    readResWords(reservedwords);

	//:::::::::::::::::::::::::::::::::
	//     Main Scanning Function
	//:::::::::::::::::::::::::::::::::
	outf << "Scan Results" << endl;
	outf << left << setw(8) << "Token"
		<< setw(15) << "type"
		<< endl;
	outf << setfill('-') << right;
	outf << setw(8) << " "
		<< setw(15) << " ";
	outf << left << setfill(' ') << endl;
	ifstream inf("prog1.bas");
	StateType state = newtkn;
	string token = "";
	int actionToDo = 0;
	while (!inf.eof())
	{
		string line;
		getline(inf, line, (char)0);
		for (unsigned int i = 0; i < line.length(); i++)
		{
			CharType chartype = getchartype(line[i]);
			actionToDo = actions[state][chartype];
			if (line[i] == '\"')
				cout << "point";
			switch (actionToDo)
			{
			case 1:
				token += line[i];
				break;
			case 2:
				outf << setw(8) << token;
				if (isResWord(token, reservedwords))
				{
					outf << setw(15) << "Reserved Word";
				}
				else
				{
					outf << setw(15) << "Variable";
				}
				outf << endl;
				token = "";
				break; 
			case 3:
				outf << setw(8) << token
					<< setw(15) << statetostr(state)
					<< endl;
				token = "";
				break;
			case 4:
				outf << setw(8) << token
					<< setw(20) << statetostr(state) 
					<< endl
					<< setw(20) 
					<< string("Improper Usage: ").append(1,line[i])
					<< endl;
				token = "";
				break;
			case 5:
				outf << setw(20) 
					<< string("Improper Usage: ").append(1, line[i])
					<< endl;
				break;
			case 6:
				//continue
				break;
			case 7:
				outf << setw(20) 
					<< string("Illegal Character: ").append(1, line[i])
					<< endl;
				break;
			case 8:
				outf << setw(8) << token;
				if (isResWord(token, reservedwords))
				{
					outf << setw(15) << "Reserved Word";
				}
				else 
				{
					outf << setw(15) << "Variable";
				}
				outf << endl;
				token = line[i];
				break;
			case 9:
				outf << setw(8) << token
					<< setw(15) << statetostr(state)
					<< endl;
				token = line[i];
				break;
			case 10:
				token += line[i];
				outf << setw(8) << token
					<< setw(15) << statetostr(var)
					<< endl;
				token = "";
				break;
			case 11:
				outf << setw(8) << token;
				if (isResWord(token, reservedwords)) {
					outf << setw(15) << "Reserved Word";
				}
				else {
					outf << setw(15) 
						<< string("Illegal Character: ").append(line[i]));
				}
				outf << endl;
				break;
			case 12:
				token += line[i];
				outf << setw(8) << token
					<< setw(15) << statetostr(state)
					<< endl;
				token = "";
				break;
			case 13:
				outf << setw(8) << token
					<< setw(20) << statetostr(state)
					<< endl
					<< setw(20) 
					<< string("Illegal Character: ").append(1, line[i])
					<< endl;
				token = "";
				break;
			}
			state = FSM[state][chartype];
		}
	}
	outf << setfill('-') << right;
	outf << setw(8) << " "
		<< setw(15) << " ";
	outf << left << setfill(' ') << endl << endl;
	//end scanning function

    printAction(actions, outf);
    printState(FSM, outf);
    printExpl(explanations, outf);
    printResWords(reservedwords, outf);

    return 0;
}
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//                           Helper Functions
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
StateType strtostate(string a)
{
    StateType outstate = newtkn;
    if (a == "newtkn")
        outstate = newtkn;
    else if (a == "resword")
        outstate = resword;
    else if (a == "var")
        outstate = var;
    else if (a == "integer")
        outstate = integer;
    else if (a == "real")
        outstate = real;
    else
        outstate = delim;
    return outstate;
}

string statetostr(StateType a)
{
    switch (a)
    {
    case StateType::delim:
        return "Delimiter";
    case StateType::integer:
        return "Integer";
    case StateType::newtkn:
        return "New Token";
    case StateType::real:
        return "Real";
    case StateType::resword:
        return "Reserved Word";
    case StateType::var:
        return "Variable";
    }
    return "Unknown";
}

bool isDelim(char ch)
{
    int n = sizeof(validDelims) / sizeof(validDelims[0]);
    bool out = false;
    for (int i = 0; i < n; i++)
        if (ch == validDelims[i])
            out = true;
    return out;
}

bool isResWord(string str, string reswords[])
{
    bool out = false;
    for (int i = 0; i < 14; i++)
        if (str == reswords[i])
            out = true;
    return out;
}

CharType getchartype(char ch)
{
    CharType out;
    if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
        out = CharType::letter;
    else if (ch >= '0' && ch <= '9')
        out = CharType::digit;
    else if (ch == '.')
        out = CharType::period;
    else if (isDelim(ch))
        out = CharType::delimeter;
    else if (ch == ' ')
        out = CharType::blank;
    else if (ch == '%' || ch == '$')
        out = CharType::pod;
    else if (ch == '\n')
        out = CharType::eoln;
    else
        out = CharType::illegal;
    return out;
}
string chartypetostr(CharType ch)
{
	string out;
	if (ch == letter)
		out = "letter";
	else if (ch == digit)
		out = "digit";
	else if (ch == period)
		out = "period";
	else if (ch == delimeter)
		out = "delimeter";
	else if (ch == blank)
		out = "blank";
	else if (ch == pod)
		out = "% or $";
	else if (ch == eoln)
		out = "EOLN";
	else
		out = "Illegal";
	return out;
}
template <class T>
void swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}
template <class T>
void bubsort(T a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//                           Input Functions
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
void readAction(int actions[actionrows][actioncols])
{
    ifstream inf("action.dat");
    for (int i = 0; i < actionrows; i++)
        for (int j = 0; j < actioncols; j++)
            inf >> actions[i][j];
}
void readState(StateType states[staterows][statecols])
{
    ifstream inf("state.dat");
    for (int i = 0; i < staterows; i++)
        for (int j = 0; j < statecols; j++)
        {
            string temp;
            inf >> temp;
            states[i][j] = strtostate(temp);
        }
}
void readExpl(string explain[])
{
    ifstream inf("explain.dat");
    for (int i = 0; i < explainrows; i++)
        getline(inf, explain[i]);
}
void readResWords(string reserved[])
{
    ifstream inf("reserved.dat");
    for (int i = 0; i < reservedrows; i++)
        getline(inf, reserved[i]);
}
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//                           Output Functions
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
void printAction(int actions[actionrows][actioncols], ofstream &outf)
{
    int colwidth = 15;
    outf << "Action Table" << endl;
    outf << left << setw(colwidth + 3) << ""
        << setw(colwidth) << "Letter" 
        << setw(colwidth) << "Digit"
        << setw(colwidth) << "Period"
        << setw(colwidth) << "Delimiter"
        << setw(colwidth) << "Blank"
        << setw(colwidth) << "% or $"
        << setw(colwidth) << "EOLN"
        << setw(colwidth) << "Illegal"
        << endl;
    outf << setfill('-') << right;
    outf << setw(colwidth + 3) << " ";
    for (int i = 0; i < actioncols; i++)
        outf << setw(colwidth) << " ";
    outf << left << setfill(' ') << endl;
    for (int i = 0; i < actionrows; i++)
    {
        StateType tempstate = (StateType)i;
        outf << setw(colwidth) << statetostr(tempstate) << " | ";
        for (int j = 0; j < actioncols; j++)
        {
            outf << right << setw(colwidth/2) << actions[i][j] 
				<< setw(colwidth/2+1) << "" << left;
        }
        outf << endl;
    }
    outf << setfill('-') << right;
    outf << setw(colwidth + 3) << " ";
    for (int i = 0; i < actioncols; i++)
        outf << setw(colwidth) << " ";
    outf << left << setfill(' ') << endl << endl;
}
void printState(StateType states[staterows][statecols], ofstream &outf)
{
    int colwidth = 15;
    outf << "State Table" << endl;
    outf << left << setw(colwidth + 3) << ""
        << setw(colwidth) << "Letter" 
        << setw(colwidth) << "Digit"
        << setw(colwidth) << "Period"
        << setw(colwidth) << "Delimiter"
        << setw(colwidth) << "Blank"
        << setw(colwidth) << "% or $"
        << setw(colwidth) << "EOLN"
        << setw(colwidth) << "Illegal"
        << endl;
    outf << setfill('-') << right;
    outf << setw(colwidth + 3) << " ";
    for (int i = 0; i < statecols; i++)
        outf << setw(colwidth) << " ";
    outf << left << setfill(' ') << endl;
    for (int i = 0; i < staterows; i++)
    {
        StateType tempstate = (StateType)i;
        outf << setw(colwidth) << statetostr(tempstate) << " | ";
        for (int j = 0; j < statecols; j++)
        {
            int center = colwidth / 2;
            string out = statetostr(states[i][j]);
            int excess = (colwidth - out.length())/2 + 1;
            int offset = center+out.length()/2;
            outf << right << setw(offset) << out 
				<< setw(excess) << ""<< left;
        }
        outf << endl;
    }
    outf << setfill('-') << right;
    outf << setw(colwidth + 3) << " ";
    for (int i = 0; i < statecols; i++)
        outf << setw(colwidth) << " ";
    outf << left << setfill(' ') << endl << endl;
}
void printExpl(string explanations[], ofstream &outf)
{
    outf << "Explanations:" << endl;
    outf << left << setw(7) << "Action" << setw(33) 
		<< "Explanation" << right << endl;
    outf << setfill('-') << setw(7) << " " << setw(33) << "" 
		<< setfill(' ') << left << endl;
    for (int i = 0; i < explainrows; i++)
    {
        outf << setw(7) << (i + 1) << setw(33) << explanations[i] << endl;
    }
    outf << right << setfill('-') << setw(7) << " " << setw(33) << "" 
		<< setfill(' ') << left << endl
         << endl;
}
void printResWords(string reswords[], ofstream &outf)
{
    outf << "Reserved words" << endl;
    outf << setfill('-') << setw(40) << "" << setfill(' ') << endl;
    bubsort(reswords,reservedrows);
    for (int i = 0; i < reservedrows; i++)
        outf << reswords[i] << endl;
    outf << setfill('-') << setw(40) << "" << setfill(' ') << endl;
}
