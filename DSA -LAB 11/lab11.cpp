#include <iostream>
using namespace std;
#include <queue>

struct Node
{
    int data;
    int priority;
    Node *left;
    Node *right;
};

class PriorityQueue
{
private:
    Node *root;

    Node *createNode(int data, int priority)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->priority = priority;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

public:
    PriorityQueue() : root(nullptr) {}

    void enqueue(int data, int priority)
    {
        Node *newNode = createNode(data, priority);
        if (!root)
        {
            root = newNode;
            return;
        }

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            if (temp->left == nullptr)
            {
                temp->left = newNode;
                return;
            }
            else if (temp->right == nullptr)
            {
                temp->right = newNode;
                return;
            }
            else
            {
                q.push(temp->left);
                q.push(temp->right);
            }
        }
    }

    void dequeue()
    {
        // Dequeue operation based on priority can be implemented here.
        // This example just removes the root node.
        if (!root)
            return;

        Node *temp = root;
        delete temp;
        root = nullptr;
    }

    // Other operations like front(), isEmpty(), etc., can be added here.

    ~PriorityQueue()
    {
        // Code to delete the nodes and free memory.
    }
};

// int main()
// {
//     priority_queue<int> pq;

//     // Enqueue elements
//     pq.push(30);
//     pq.push(10);
//     pq.push(50);
//     pq.push(20);

//     // Output elements based on priority
//     while (!pq.empty())
//     {
//         cout << pq.top() << " ";
//         pq.pop();
//     }

//     return 0;
// }

#include <iostream>
#include <queue>
#include <vector>

template<class T, class Compare = std::less<T>>
void HeapSort(std::vector<T> &V) {
    // Creating a min heap using a priority queue
    std::priority_queue<T, std::vector<T>, Compare> PQ;

    // Adding all values to the priority queue
    for (int vi = 0; vi < V.size(); vi++) {
        PQ.push(V[vi]);
    }

    V.clear(); // Clearing the previous vector

    // Populating the vector by popping elements from the priority queue
    while (!PQ.empty()) {
        V.push_back(PQ.top());
        PQ.pop();
    }
}

int main() {
    std::vector<int> data = {12, 3, 45, 7, 23, 6};

    std::cout << "Before sorting: ";
    for (int val : data) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Sorting using Heap Sort with priority queue
    HeapSort(data);

    std::cout << "After sorting: ";
    for (int val : data) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
#include <iostream>
#include <queue>

int main() {
    // Custom comparison function for pairs (compare by second element)
    auto cmp = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second > b.second;  // Change the comparison logic as needed
    };

    // Priority queue of pairs with the custom comparator
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> pq(cmp);

    // Enqueue elements
    pq.push({1, 5});
    pq.push({2, 3});
    pq.push({3, 7});
    pq.push({4, 1});

    // Dequeue elements based on the custom comparison
    while (!pq.empty()) {
        std::cout << pq.top().first << " : " << pq.top().second << std::endl;
        pq.pop();
    }

    return 0;
}


int main()
{
    PriorityQueue pq;

    // Enqueue elements
    pq.enqueue(30, 3);
    pq.enqueue(10, 1);
    pq.enqueue(50, 5);
    pq.enqueue(20, 2);

    // Dequeue elements based on priority
    // Implement your dequeue logic accordingly
    // ...

    return 0;
}
