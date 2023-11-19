#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> p_Stack;

        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];

            if (c == '(' || c == '[' || c == '{')
            {
                p_Stack.push(c);
            }
            else
            {
                // Check if the stack is empty (no opening parenthesis to match)
                if (p_Stack.empty())
                {
                    return false;
                }

                // Check if the current character matches the top of the stack
                char top = p_Stack.top();
                if ((c == ')' && top == '(') || (c == ']' && top == '[') || (c == '}' && top == '{'))
                {
                    p_Stack.pop();
                }
                else
                {
                    return false; 
                }
            }
        }

        
        return p_Stack.empty();
    }
};

int main()
{
    Solution solution;
    string input;

    cout << "Enter a string with parentheses: ";
    cin >> input;

    if (solution.isValid(input))
    {
        cout << "The input string is valid." << endl;
    }
    else
    {
        cout << "The input string is not valid." << endl;
    }

    return 0;
}
