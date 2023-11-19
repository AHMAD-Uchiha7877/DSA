#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

double postFixEvaluation(string s)
{
    stack<double> postFixStack;
    stringstream ss(s); // Create a stringstream to split the input string by spaces

    while (ss >> s)
    {
        bool isNumeric = true;

        // Check if the token is a number
         for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i]) && s[i] != '.') {
            isNumeric = false;
            break;
        }
    }

        if (isNumeric)
        {
            postFixStack.push(stod(s)); //The stod function in C++ is used for converting a string to a double
        }
        else
        {
            double op2 = postFixStack.top(); // Pop the top operand (first in the expression)
            postFixStack.pop();
            double op1 = postFixStack.top(); // Pop the second operand (preceding the first in the expression)
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
