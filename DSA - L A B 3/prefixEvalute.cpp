#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int prefixEvaluation(string s) {
    stack<int> prefixStack;

    for (int i = s.length() - 1; i >= 0; i--) {
        char c = s[i];
        if (isdigit(c)) {
            prefixStack.push(c - '0');
        } else if (isOperator(c)) {
            int op1 = prefixStack.top();
            prefixStack.pop();
            int op2 = prefixStack.top();
            prefixStack.pop();

            if (c == '+') {
                prefixStack.push(op1 + op2);
            } else if (c == '-') {
                prefixStack.push(op1 - op2);
            } else if (c == '*') {
                prefixStack.push(op1 * op2);
            } else if (c == '/') {
                prefixStack.push(op1 / op2);
            } else if (c == '^') {
                prefixStack.push(pow(op1, op2));
            }
        }
    }

    return prefixStack.top();
}

int main() {
    
    cout << "Evaluation Result: " << prefixEvaluation("/ * 5 + 6 2 4") << endl;
    return 0;
}
