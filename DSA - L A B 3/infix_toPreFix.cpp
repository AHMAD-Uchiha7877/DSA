#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isAlphanumeric(char character)
{
    return (character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z') || (character >= '0' && character <= '9');
}

int getPrecedence(char operatorChar)
{
    if (operatorChar == '^')
        return 3;
    else if (operatorChar == '*' || operatorChar == '/')
        return 2;
    else if (operatorChar == '+' || operatorChar == '-')
        return 1;
    else
        return -1; // for parentheses
}

string infixToPrefix(string infix)
{
    stack<char> operatorStack;
    string prefix = "";

    for (int i = infix.length() - 1; i >= 0; i--)
    {
        char c = infix[i];

        if (c == ' ')
            continue;

        if (isAlphanumeric(c))//if c is alpha-numeric (digit or letter ,simply write it in the string)
        {
            prefix = c + prefix;
        }
        else if (c == ')')//reverse the brackets -->in postfix opening bracket but in prefix closig bracket
        {
            operatorStack.push(c);
        }
        else if (c == '(')//reverse the brackets that is in postfix -->in postfix closing bracket but in prefix opening bracket
        {
            while (!operatorStack.empty() && operatorStack.top() != ')')
            {
                prefix = operatorStack.top() + prefix;//storing top element in the string
                operatorStack.pop();//removing top 
            }
            if (!operatorStack.empty() && operatorStack.top() == ')')
            {
                operatorStack.pop();
            }
        }
        else
        {
            while (!operatorStack.empty() && getPrecedence(operatorStack.top()) >= getPrecedence(c))
            {
                prefix = operatorStack.top() + prefix;
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    while (!operatorStack.empty())
    {
        prefix = operatorStack.top() + prefix;
        operatorStack.pop();
    }
  
    return prefix;
}

int main()
{
    string infix = " (a-b/c)*(a/k-l)";

    string prefix = infixToPrefix(infix);

    cout << "Prefix Expression: " << prefix << endl;

    return 0;
}
