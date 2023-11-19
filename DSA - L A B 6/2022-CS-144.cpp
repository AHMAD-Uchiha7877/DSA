#include <iostream>
using namespace std;

int main()
{
    cout << "" << endl;
    return 0;
}
class Node
{
public:
    int val;
    Node *nextAddress;

    Node(int data)
    {
        this->val = data;
        nextAddress = NULL;
    }
};
//.........................................Q-1.....................................................................//
int GetFront(Node *head)
{
    if (head != nullptr)
    {
        return head->val;
    }

    return -1;
}

int GetTail(Node *head)
{
    if (head != nullptr)
    {
        Node *temp = head;
        while (temp->nextAddress != nullptr)
        {
            temp = temp->nextAddress;
        }
        return temp->val;
    }
    return -1; // Return -1 for an empty linked list
}

bool isEmpty(Node *head)
{
    if (head == nullptr)
    {
        return true;
    }
    return false;
}

void InsertValueAtHead(Node *&head, int value) // time complexity O(1)
{
    Node *new_Node = new Node(value);
    new_Node->nextAddress = head;
    head = new_Node;
}

void InsertAtTail(int val, Node *&head) // time complexity O(n)
{
    Node *temp = head;
    Node *newNode = new Node(val);

    while (temp->nextAddress != NULL)
    {
        temp = temp->nextAddress;
    }

    temp->nextAddress = newNode;
}

void InsertAtMiddle(Node *&head, int value)
{
    Node *x = head;
    Node *y = head;
    Node *newNode = new Node(value);
    // x will move one step from head
    // y will move two steps from head
    // when y reaches null or the end, it means x is at the middle position
    while (y != nullptr && y->nextAddress != nullptr)
    {
        x = x->nextAddress;
        y = y->nextAddress->nextAddress;
    }
    // Insert the new node after the middle node (x)
    newNode->nextAddress = x->nextAddress;
    x->nextAddress = newNode;
}
void InsertAfter(int val, int position, Node *&head)
{
    if (position == 0)
    {
        InsertValueAtHead(head, val);
        return;
    }
    Node *newNode = new Node(val);
    Node *temp = head;
    int currentPosition = 0;
    while (currentPosition != position - 1)
    {
        temp = temp->nextAddress;
        currentPosition++;
    }
    newNode->nextAddress = temp->nextAddress;
    temp->nextAddress = newNode;
}
void InsertAfterGivenValue(int val, int key, Node *&head)
{
    if (key == 0)
    {
        InsertValueAtHead(head, val);
        return;
    }
    Node *newNode = new Node(val);
    Node *temp = head;
    int currentPosition = 0;
    while (currentPosition != key - 1)
    {
        temp = temp->nextAddress;
        currentPosition++;
    }
    newNode->nextAddress = temp->nextAddress;
    temp->nextAddress = newNode;
}
void InsertBeforeGivenValue(int val, int key, Node *&head)
{
    if (key == 0)
    {
        InsertValueAtHead(head, val);
        return;
    }
    Node *newNode = new Node(val);
    Node *temp = head;
    int currentPosition = 0;
    while (currentPosition != key - 2)
    {
        temp = temp->nextAddress;
        currentPosition++;
    }
    newNode->nextAddress = temp->nextAddress;
    temp->nextAddress = newNode;
}
Node *Search(int key, Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (key == temp->val)
        {
            return temp->nextAddress;
        }
        temp = temp->nextAddress;
    }
    return nullptr;
}
void RemoveFront(Node *&head)
{
    if (head != nullptr)
    {
        Node *temp = head;
        head = head->nextAddress;
    }
}
void Removetail(Node *&head)
{
    if (head != nullptr)
    {
        Node *secondLast = head;
        while (secondLast->nextAddress->nextAddress != nullptr)
        {
            secondLast = secondLast->nextAddress;
        }
        delete secondLast->nextAddress;
        secondLast->nextAddress = nullptr;
    }
}
void removeMiddle(Node *&head)
{
    if (head == nullptr || head->nextAddress == nullptr || head->nextAddress->nextAddress == nullptr)
    {
        return;
    }
    Node *x = head;
    Node *y = head;
    while (y != nullptr && y->nextAddress != nullptr && y->nextAddress->nextAddress != nullptr)
    {
        x = x->nextAddress;
        y = y->nextAddress->nextAddress;
    }
    Node *temp = x->nextAddress;
    x->nextAddress = x->nextAddress->nextAddress;
    delete temp;
}
void display(Node *&head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << "-->";
        temp = temp->nextAddress;
    }
    cout << "Null" << endl;
}
//.........................................Q-1.....................................................................//

//.........................................Q-2.....................................................................//
// stack using  linklist
template <typename T>
class Stack
{
private:
    Node *head;
    int capacity;
    int size;

public:
    Stack(int c)
    {
        head = nullptr;
        capacity = c;
        size = 0;
    }

    bool IsEmpty()
    {
        return head == nullptr;
    }

    void Push(T val)
    {
        if (size < capacity)
        {
            Node *newNode = new Node(val);
            newNode->nextAddress = head;
            head = newNode;
            size++;
        }
    }

    T Pop()
    {
        if (IsEmpty())
        {
            return -1;
        }

        Node *temp = head;
        T res = temp->val;
        head = head->nextAddress;
        delete temp;
        size--;
        return res;
    }
};

// queue using link list
template <typename T>
class Queue
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    Queue()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void Enqueue(T value)
    {
        Node *newNode = new Node(value);
        if (IsEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->nextAddress = newNode;
            tail = newNode;
        }
        size++;
    }

    T Dequeue()
    {
        if (IsEmpty())
        {
            // Handle underflow (returning a default value, you can also throw an exception)
            return T();
        }
        Node *temp = head;
        T value = temp->val;
        head = head->nextAddress;
        delete temp;
        size--;
        if (head == nullptr)
        {
            tail = nullptr; // Queue is empty after dequeueing
        }
        return value;
    }

    bool IsEmpty()
    {
        return head == nullptr;
    }
};

//.........................................Q-2.....................................................................//

//.........................................Q-3.....................................................................//

void printLinkedListRecursively(Node *head)
{
    if (head == nullptr)
    {
        return;
    }
    // Print in linked list order
    cout << head->val << " ";
    printLinkedListRecursively(head->nextAddress);
    // Print in reverse linked list order
    cout << head->val << " ";
}

Node *findMiddle(Node *head)
{
    if (head == nullptr || head->nextAddress == nullptr)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->nextAddress != nullptr)
    {
        slow = slow->nextAddress;
        fast = fast->nextAddress->nextAddress;
    }
    return slow;
}

bool isCircular(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->nextAddress != nullptr)
    {
        slow = slow->nextAddress;
        fast = fast->nextAddress->nextAddress;
        if (slow == fast)
        {
            return true; // There is a cycle in the linked list
        }
    }
    return false; // Linked list is not circular
}

Node* reverseLinkedList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current != nullptr) {
        next = current->nextAddress; // Save the next node
        current->nextAddress = prev; // Reverse the current node's pointer
        prev = current; // Move prev to this node
        current = next; // Move to the next node
    }
    head = prev; // Set the head to the new first node
    return head;
}


//.........................................Q-3.....................................................................//
