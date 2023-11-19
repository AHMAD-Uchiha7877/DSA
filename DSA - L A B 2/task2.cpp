#include <iostream>
#include <stack>
#include <algorithm> // for min function
using namespace std;
class MinStack
{
private:
    stack<int> valStack;
    stack<int> minStack;
    int minValue = 0;

public:
    MinStack()
    {
    }
    void push(int val)
    {
        if (valStack.empty())
        {
            val = minValue;
        }
        valStack.push(val);
        minValue = min(val, minValue);
        minStack.push(minValue);
    }
    void pop()
    {
        minStack.pop();
        valStack.pop();
        if (!minStack.empty())
        {
            minValue = minStack.top();
        }
    }

    int top()
    {
        return valStack.top();
    }

    int getMin()
    {
        return minStack.top();
    }
};

int main()
{
    MinStack minStack;
    minStack.push(5);
    minStack.push(2);
    minStack.push(-7);
    minStack.push(1);

    cout << "Minimum value in the stack: " << minStack.getMin() << endl;

    return 0;
}



