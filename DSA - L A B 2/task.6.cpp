#include <iostream>
using namespace std;

#include <queue>

class MyStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        // Move all elements from q1 to q2
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        // Push the new element to q1
        q1.push(x);

        // Move elements back from q2 to q1
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop()
    {
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};

int main()
{
}