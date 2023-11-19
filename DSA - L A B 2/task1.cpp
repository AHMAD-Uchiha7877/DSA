#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> p_stack;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if (c == '(')
        {
            p_stack.push(')');
        }
        else if (c == '{')
        {
            p_stack.push('}');
        }
        else if (c == '[')
        {
            p_stack.push(']');
        }

        else if (p_stack.empty() || p_stack.top() != c)
        {
            return false;
        }

        if (c == ')' || c == '}' || c == ']')
        {
            p_stack.pop();
        }
    }

    return p_stack.empty();
}
