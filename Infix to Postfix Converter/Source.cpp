#include "stdafx.h"

using namespace std;

bool isOd(char ch)          // check for operands 
{
    return (ch >= '0' && ch <= '9');
}

bool isOp(char op)    // check for operators
{
    return (op == '^' || op == '*' || op == '/' || op == '+' || op == '-');
}

int priorityOp(char k)  // check the priority of operands
{
    int result;

    switch (k)
    {
    case '^':
        result = 3;
        break;
    case '*':
    case '/':
        result = 2;
        break;
    case '+':
    case '-':
        result = 1;
        break;
    default:
        result = 0;
        break;
    }

    return result;
}

std::string to_postfix(std::string infix) {

    stack <char> stackOpr;      //operators stack
    string arrOut;

    unsigned long c = 0; //for ch


    while (c <= infix.length() - 1)
    {
        if (isOd(infix[c]))     // check for operands
        {
            arrOut += infix[c];
            c++;
        }

        else if (isOp(infix[c]))  // check for operators
        {
            // determine the storage location of the operator
            if (stackOpr.empty() || priorityOp(infix[c]) > priorityOp(stackOpr.top()))    //if the stackOpr is empty, send the operator to it
            {
                stackOpr.push(infix[c]);
                c++;
            }
            else    //if the stackOpr is't empty, check previous operator in stack
            {
                while (!stackOpr.empty() && (priorityOp(infix[c]) <= priorityOp(stackOpr.top())))
                {
                    arrOut += stackOpr.top();
                    stackOpr.pop();
                }

                stackOpr.push(infix[c]);
                c++;
            }
        }

        else if (infix[c] == '(')
        {
            stackOpr.push(infix[c]);
            c++;
        }
        else if (infix[c] == ')')
        {
            if ((stackOpr.top() == '(') || (stackOpr.empty()))
            {
                cout << "Input error" << endl;
                break;
            }
            //push all before the previous bracket
            while ((stackOpr.top() != '(') && (!stackOpr.empty()))
            {
                arrOut += stackOpr.top();
                stackOpr.pop();
            }
            stackOpr.pop();
            c++;
        }

        else
        {
            cout << "Wrong character entered" << endl;
            break;
        }
    }


    ////popping from the stack if at the end ')'
    if (infix[c] == infix[infix.length()])
    {
        while (!stackOpr.empty())
        {
            if (stackOpr.top() == '(')
            {
                continue;
            }
            else
            {
                arrOut += stackOpr.top();
                stackOpr.pop();
            }
        }
    }


    return arrOut;
}

int main() {
   setlocale(LC_ALL, "ru");

   cout << to_postfix("5+(6-2)*9+3^(7-1)");
       // Should return "562-9*+371-^+"

    system("pause");
}