#include "stdafx.h"

using namespace std;

enum State();

bool isLetter(char ch);
bool isNumber(char ch);
void repeatLetter(string& str, int num, char ch, State& state, State s);
void appendLetter(string& str, char ch, State& state, State s);
void fixNum(int& num, char ch, State& state, State s);

string string_expansion(const string& s);



int main() {
   setlocale(LC_ALL, "ru");

   cout << string_expansion("3D2a5d2f");
       // Should return "DDDaadddddff"

    system("pause");
}



enum State
{
    NL, NN, LL, LN, F, FN, FL
};

bool isLetter(char ch)
{
    return (ch >= 'A' && ch <= 'z') ? 1 : 0;
}

bool isNumber(char ch)
{
    return (ch >= '0' && ch <= '9') ? 1 : 0;
}

void repeatLetter(string& str, int num, char ch, State& state, State s)
{
    switch (num)
    {
    case 0:
        break;
    default:
        for (int i = 0; i < num; i++)
        {
            str.push_back(ch);
        }
    }
    state = s;
}

void appendLetter(string& str, char ch, State& state, State s)
{
    str.push_back(ch);
    state = s;
}

void fixNum(int& num, char ch, State& state, State s)
{
    const char* n = new char(ch);
    num = atoi(n);
    state = s;
    delete[] n;
}


string string_expansion(const string& s)
{
    int num = 1;
    string resultStr;
    State state = F;

    for (unsigned int i = 0; i < s.size(); i++)
    {
        switch (state)
        {

        case F:
            if (isLetter(s[i]))
            {
                appendLetter(resultStr, s[i], state, FL);
            }
            else if (isNumber(s[i]))
            {
                fixNum(num, s[i], state, FN);
            }
            break;

        case FL:
            if (isLetter(s[i]))
            {
                appendLetter(resultStr, s[i], state, LL);
            }
            else if (isNumber(s[i]))
            {
                fixNum(num, s[i], state, LN);
            }
            break;

        case FN:
            if (isLetter(s[i]))
            {
                repeatLetter(resultStr, num, s[i], state, NL);
            }
            else if (isNumber(s[i]))
            {
                fixNum(num, s[i], state, NN);
            }
            break;

        case NL:
            if (isLetter(s[i]))
            {
                repeatLetter(resultStr, num, s[i], state, LL);
            }
            else if (isNumber(s[i]))
            {
                fixNum(num, s[i], state, LN);
            }
            break;

        case NN:
            if (isLetter(s[i]))
            {
                repeatLetter(resultStr, num, s[i], state, NL);
            }
            else if (isNumber(s[i]))
            {
                fixNum(num, s[i], state, NN);
            }
            break;

        case LN:
            if (isLetter(s[i]))
            {
                repeatLetter(resultStr, num, s[i], state, NL);
            }
            else if (isNumber(s[i]))
            {
                fixNum(num, s[i], state, NN);
            }
            break;

        case LL:
            if (isLetter(s[i]))
            {
                repeatLetter(resultStr, num, s[i], state, LL);
            }
            else if (isNumber(s[i]))
            {
                fixNum(num, s[i], state, LN);
            }
            break;
        }
    }
    return resultStr;
}