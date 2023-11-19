#include <iostream>
#include <vector>
using namespace std;

class Queue {
    int front; // taking front pointer that points to the front of the vector
    int rear;  // taking rear pointer that points to the rear of the vector
    vector<int> v;

public:
    Queue() {
        // initializing front and rear to -1 at first --> queue is empty
        this->front = -1;
        this->rear = -1;
    }

    void Enqueue(int val) {
        v.push_back(val);
        this->rear++; // increment the rear when the new element is added to point to the end
        if (this->rear == 0) {
            this->front = 0;
        }
    }

    void Dequeue() {
        if (this->front == this->rear) { // means the queue is empty
            this->front = -1;
            this->rear = -1;
        } else {
            this->front++; //fault: increment the front ==> disadvantage of space
        }
    }

    int getFront() {
        if (this->front == -1) {
            return -1;
        }
        return v[this->front];
    }

    int getEnd() {
        if (this->rear == -1) {
            return -1;
        }
        return v[this->rear];
    }

    bool isEmpty() {
        return this->front == -1;
    }
};

int main() {
    Queue q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Dequeue();
    q.Enqueue(220);


    while (!q.isEmpty()) {
        cout << q.getFront() << " ";
        q.Dequeue();
    }

    return 0;
}
