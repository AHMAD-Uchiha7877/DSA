#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node(int data)
    {
        val = data;
        prev = nullptr;
        next = nullptr;
    }
};

//............................iteratots

class LinkList
{
public:
    Node *head;
    Node *tail;

    LinkList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // forward iterator
    class ForwardIterator
    {
        Node *current;

    public:
        ForwardIterator(Node *p)
        {
            this->current = p;
        }

        ForwardIterator operator++()
        {
            current = current->next;
            return current;
        }

        bool operator!=(const ForwardIterator &other)
        {
            return current != other.current;
        }

        int operator*()
        {
            return current->val;
        }
    };

    // Reverse iterator
    class ReverseIterator
    {
        Node *current;

    public:
        ReverseIterator(Node *p)
        {
            current = p;
        }

        ReverseIterator operator--()
        {
            current = current->prev;
            return current;
        }

        bool operator!=(const ReverseIterator &other)
        {
            return current != other.current;
        }

        int operator*()
        {
            return current->val;
        }
    };
    // General Iterator
    class GeneralIterator
    {
        Node *current;

    public:
        GeneralIterator(Node *p)
        {
            current = p;
        }

        GeneralIterator operator++()
        {
            current = current->next;
            return current;
        }

        GeneralIterator operator--()
        {
            current = current->prev;
            return current;
        }

        bool operator!=(const GeneralIterator &other)
        {
            return current != other.current;
        }

        int operator*()
        {
            return current->val;
        }
    };

    GeneralIterator begin()
    {
        return GeneralIterator(head);
    }

    GeneralIterator end()
    {
        return GeneralIterator(nullptr);
    }

    ForwardIterator forwardBegin()
    {
        return ForwardIterator(head);
    }

    ForwardIterator forwardEnd()
    {
        return ForwardIterator(nullptr);
    }

    ReverseIterator reverseBegin()
    {
        return ReverseIterator(tail);
    }

    ReverseIterator reverseEnd()
    {
        return ReverseIterator(nullptr);
    }

    void insertNode(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void insertAtFront(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void removeAt(int pos)
    {
        if (head == nullptr)
        {

            return;
        }
        else if (pos == 0)
        {
            head = head->next;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            return;
        }
        else
        {
            int len = 0;
            Node *temp = head;
            while (temp != nullptr && len < pos)
            {
                temp = temp->next;
                len++;
            }

            if (temp == nullptr)
            {
                cout << "Invalid position" << endl;
                return;
            }

            Node *prevNode = temp->prev;
            Node *nextNode = temp->next;

            if (nextNode == nullptr)
            {
                prevNode->next = nullptr;
            }
            else
            {
                prevNode->next = nextNode;
                nextNode->prev = prevNode;
            }

            delete temp;
        }
    }
};

// leetcode-1
Node *mergeTwoLists(Node *list1, Node *list2)
{
    Node *temp = new Node(-1);
    Node *current = temp;

    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->val <= list2->val)
        {
            current->next = list1;
            list1 = list1->next;
        }
        else
        {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    if (list1 != nullptr)
    {
        current->next = list1;
    }
    else
    {
        current->next = list2;
    }

    return temp->next;
}

// leetcode-2

Node *removeNthFromEnd(Node *head, int n)
{
    Node *fast = head;
    Node *slow = head;
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    if (fast == nullptr)
    {

        return head->next;
    }
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
}

// leetcode-3

Node *swapPairs(Node *head)
{
    Node *dummy = new Node(0);
    dummy->next = head;
    Node *prev = dummy;
    while (head != nullptr && head->next != nullptr)
    {
        Node *first = head;
        Node *second = head->next;

        // Swapping nodes
        prev->next = second;
        first->next = second->next;
        second->next = first;

        // Move pointers to the next pair of nodes
        prev = first;
        head = first->next;
    }
    return dummy->next;
}

// leetcode-4

Node *reverseBetween(Node *head, int left, int right)
{
    if (head == nullptr)
        return head;

    Node *dummy = new Node(0);
    dummy->next = head;

    Node *prev = dummy;
    for (int i = 0; i < left - 1; i++)
    {
        prev = prev->next;
    }
    Node *curr = prev->next;

    for (int i = 0; i < right - left; i++)
    {
        Node *next = curr->next;
        curr->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }

    return dummy->next;
}

// leetcode-5

class MyLinkedList
{
private:
    Node *head;

public:
    MyLinkedList()
    {
        head = nullptr;
    }

    int get(int index)
    {
        if (index < 0)
        {
            return -1;
        }

        Node *temp = head;
        int count = 0;
        while (temp != nullptr && count < index)
        {
            temp = temp->next;
            count++;
        }

        if (temp != nullptr)
        {
            return temp->val;
        }
        else
        {
            return -1;
        }
    }

    void addAtHead(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void addAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0)
        {
            return;
        }

        Node *newNode = new Node(val);
        if (index == 0)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        int count = 0;
        Node *temp = head;
        while (count < index - 1 && temp != nullptr)
        {
            temp = temp->next;
            count++;
        }

        if (temp != nullptr)
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deleteAtIndex(int index)
    {
        if (index < 0)
        {
            return; // Invalid index
        }

        if (index == 0)
        {
            Node *temp = head;
            if (temp != nullptr)
            {
                head = temp->next;
                delete temp;
            }
            return;
        }

        int count = 0;
        Node *temp = head;
        while (count < index - 1 && temp != nullptr)
        {
            temp = temp->next;
            count++;
        }

        if (temp != nullptr && temp->next != nullptr)
        {
            Node *nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            delete nodeToDelete;
        }
    }
};

int main()
{
}