#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using  namespace std;
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> sandwichStack;  // Stack to represent sandwiches
        queue<int> studentQueue;   // Queue to represent students

        // Initialize the stack with sandwiches (in reverse order)
        for (int i = sandwiches.size() - 1; i >= 0; i--) {
            sandwichStack.push(sandwiches[i]);
        }

        // Initialize the queue with student preferences
        for (int student : students) {
            studentQueue.push(student);
        }

        int unableToEat = 0;

        while (!studentQueue.empty()) {
            int frontStudent = studentQueue.front();
            int topSandwich = sandwichStack.top();

            if (frontStudent == topSandwich) {
                // If the student prefers the top sandwich, they take it
                studentQueue.pop();
                sandwichStack.pop();
                unableToEat = 0; // Reset the count of students unable to eat
            } else {
                // If the student doesn't prefer the top sandwich, they go to the end of the queue
                studentQueue.pop();
                studentQueue.push(frontStudent);

                // Increase the count of students unable to eat
                unableToEat++;

                // If all students have gone through without eating, break the loop
                if (unableToEat == studentQueue.size()) {
                    break;
                }
            }
        }

        return studentQueue.size(); // The remaining students in the queue are unable to eat
    }
};

int main() {
    vector<int> students = {1, 1, 0, 0};
    vector<int> sandwiches = {0, 1, 0, 1};
    Solution solution;
    int result = solution.countStudents(students, sandwiches);
    cout << result << endl; // Output: 0
    return 0;
}
