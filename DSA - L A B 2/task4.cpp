#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
    stack<string> stringStack; // A stack to store strings
    stack<int> numStack; // A stack to store numbers (multipliers)

public:
    string decodeString(string s) {
        string currentStr = ""; // Initialize an empty string to build the current substring
        int currentNum = 0; // Initialize the current multiplier to 0

        for (int i = 0; i < s.length(); i++) { 
            char c = s[i]; // Get the current character from the input string

            if (isdigit(c)) { // If the character is a digit
                currentNum = currentNum * 10 + (c - '0'); // Build the multiplier (k)
            } else if (c == '[') { // If the character is an opening bracket
                numStack.push(currentNum); // Push the multiplier onto the number stack
                currentNum = 0; // Reset the current multiplier
                stringStack.push(currentStr); // Push the current substring onto the string stack
                currentStr = ""; // Reset the current substring
            } else if (c == ']') { // If the character is a closing bracket
                int k = numStack.top(); // Get the multiplier (k) from the number stack
                numStack.pop(); // Pop the multiplier from the number stack
                string prevStr = stringStack.top(); // Get the previous substring from the string stack
                stringStack.pop(); // Pop the previous substring from the string stack

                for (int j = 0; j < k; j++) {
                    prevStr += currentStr; // Repeat the current substring 'k' times and append to the previous substring
                }

                currentStr = prevStr; // Update the current substring with the combined result
            } else {
                currentStr += c; // If the character is a letter, append it to the current substring
            }
        }

        return currentStr; // Return the final decoded string
    }
};

int main() {
    Solution solution;
    string encoded = "3[a]2[bc]";
    string decoded = solution.decodeString(encoded);
    cout << "Decoded string: " << decoded << endl;
    return 0;
}
