#include <iostream>
#include"../myStack.h"
using namespace std;
int main()
{
    myStack<char> s(100);

    string infix = "( ( ( 12 + 13 ) * ( 20 - 30 ) ) / ( 811 + 99 ) ) ";
    string postfix = "";

    int length = infix.length();

    for (int i = 0; i < length; i++)
    {
        char c = infix[i];

        if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (s.top() != '(' && !s.isEmpty())
            {
                postfix += s.top();
                s.pop();
            }
            if (!s.isEmpty())
            {
                s.pop(); // Pop the '(' from the stack
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            s.push(c);
        }
        else
        {
            postfix += c;
        }
    }
    while (!s.isEmpty())
    {
        if (s.top() != '(') // Ensure that we don't add any remaining '(' to the postfix expression
        {
            postfix += s.top();
        }
        s.pop();
    }

    cout << "Postfix Expression: " << postfix << endl;
    return 0;
}