#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if a character is alphanumeric (a letter or a digit).
bool isAlphanumeric(char character) {
    return (character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z') || (character >= '0' && character <= '9');
} 

// Function to get the precedence of an operator.
int getPrecedence(char operatorChar) {
    if (operatorChar == '^')
        return 3;
    else if (operatorChar == '*' || operatorChar == '/')
        return 2;
    else if (operatorChar == '+' || operatorChar == '-')
        return 1;
    else
        return -1; // for parentheses
}

// Function to convert infix expression to postfix.
string infixToPostfix(string infix) {
    stack<char> operatorStack; // Stack to store operators.
    string postfix = "";      // Output postfix expression.

    // Iterate through each character in the infix expression.
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // Skip spaces.
        if (c == ' ')
            continue;

        // If c is alphanumeric (a letter or digit), add it directly to the postfix expression.
        if (isAlphanumeric(c)) {
            postfix += c;
        }
        // If c is an opening parenthesis '(', push it onto the operator stack.
        else if (c == '(') {
            operatorStack.push(c);
        }
        // If c is a closing parenthesis ')', pop operators from the stack and add them to the postfix
        // expression until the corresponding opening parenthesis is encountered and removed.
        else if (c == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            if (!operatorStack.empty() && operatorStack.top() == '(') {
                operatorStack.pop(); // Remove the remaining '('
            }
        }
        // If c is an operator (+, -, *, /, or ^), compare its precedence with operators on the stack.
        // Pop operators from the stack and add them to the postfix expression until the precedence
        // condition is met, then push c onto the stack.
        else {
            while (!operatorStack.empty() && getPrecedence(operatorStack.top()) >= getPrecedence(c)) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    // After processing all characters, pop any remaining operators from the stack and add them to the postfix expression.
    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    // Return the final postfix expression.
    return postfix;
}

int main() {
    string infix = "5 * (6 + 2) / 4";

    string postfix = infixToPostfix(infix);

    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}
