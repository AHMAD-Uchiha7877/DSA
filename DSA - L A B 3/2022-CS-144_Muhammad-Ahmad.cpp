
// ############################### Infix To PostFix ###########################################
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
        return -1;
}
string infixToPostfix(string infix)
{
    stack<char> operatorStack;
    string postfix = "";
    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];
        if (c == ' ')
            continue;
        if (isAlphanumeric(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            operatorStack.push(c);
        }
        else if (c == ')')
        {
            while (!operatorStack.empty() && operatorStack.top() != '(')
            {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            if (!operatorStack.empty() && operatorStack.top() == '(')
            {
                operatorStack.pop();
            }
        }
        else
        {
            while (!operatorStack.empty() && getPrecedence(operatorStack.top()) >= getPrecedence(c))
            {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }
    while (!operatorStack.empty())
    {
        postfix += operatorStack.top();
        operatorStack.pop();
    }
    return postfix;
}

int main()
{
    string infix = "5 * (6 + 2) / 4";
    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;
    return 0;
}

// ############################### Infix to preFix ###########################################
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
        return -1;
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

        if (isAlphanumeric(c))
        {
            prefix = c + prefix;
        }
        else if (c == ')')
        {
            operatorStack.push(c);
        }
        else if (c == '(')
        {
            while (!operatorStack.empty() && operatorStack.top() != ')')
            {
                prefix = operatorStack.top() + prefix;
                operatorStack.pop();
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
// ############################### PostFix Evalute ###########################################
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

double postFixEvaluation(string s)
{
    stack<double> postFixStack;
    stringstream ss(s);

    while (ss >> s)
    {
        bool isNumeric = true;
        for (int i = 0; i < s.length(); i++)
        {
            if (!isdigit(s[i]) && s[i] != '.')
            {
                isNumeric = false;
                break;
            }
        }

        if (isNumeric)
        {
            postFixStack.push(stod(s));
        }
        else
        {
            double op2 = postFixStack.top();
            postFixStack.pop();
            double op1 = postFixStack.top();
            postFixStack.pop();

            if (s == "+")
            {
                postFixStack.push(op1 + op2);
            }
            else if (s == "-")
            {
                postFixStack.push(op1 - op2);
            }
            else if (s == "*")
            {
                postFixStack.push(op1 * op2);
            }
            else if (s == "/")
            {
                postFixStack.push(op1 / op2);
            }
            else if (s == "^")
            {
                postFixStack.push(pow(op1, op2));
            }
        }
    }

    return postFixStack.top();
}
int main()
{
    cout << postFixEvaluation("66 2 * 8 / 99 -") << endl;
    return 0;
}
// ############################### PreFix Evalute ###########################################
#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int prefixEvaluation(string s)
{
    stack<int> prefixStack;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        char c = s[i];
        if (isdigit(c))
        {
            prefixStack.push(c - '0');
        }
        else if (isOperator(c))
        {
            int op1 = prefixStack.top();
            prefixStack.pop();
            int op2 = prefixStack.top();
            prefixStack.pop();

            if (c == '+')
            {
                prefixStack.push(op1 + op2);
            }
            else if (c == '-')
            {
                prefixStack.push(op1 - op2);
            }
            else if (c == '*')
            {
                prefixStack.push(op1 * op2);
            }
            else if (c == '/')
            {
                prefixStack.push(op1 / op2);
            }
            else if (c == '^')
            {
                prefixStack.push(pow(op1, op2));
            }
        }
    }

    return prefixStack.top();
}

int main()
{

    cout << "Evaluation Result: " << prefixEvaluation("/ * 5 + 6 2 4") << endl;
    return 0;
}
