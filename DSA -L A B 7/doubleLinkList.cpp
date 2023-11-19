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
/*
int main()
{
    LinkList list;
    list.insertNode(5);
    list.insertNode(6);
    list.insertNode(6);
    //  list.insertAtFront(9);
    //  list.insertAtTail(4);
    //  list.insertAtTail(4);
    // list.removeAt(0);
    cout << "Forward iterator: ";
    for (LinkList::ReverseIterator it = list.reverseBegin(); it != list.reverseEnd(); --it)
    {
        cout << *it;
    }
    cout << endl;
}
*/
//...........................................................
/*
class doublyLinkList
{
public:
    Node *tail;
    Node *head;
    doublyLinkList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (tail == nullptr)
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

    void insertAtHead(int val)
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
            head->prev = newNode->next;
            head = newNode;
        }
    }
    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->val << "<--->";
            temp = temp->next;
        }
        cout << endl;
    }

    void deleteAtHead()
    {
        if (head == nullptr)
        {

            return;
        }

        Node *temp = head;

        // If there is only one node in the list
        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp; // Free the memory occupied by the previous head node
    }

    void deleteAtTail()
    {
        if (tail == nullptr)
        {

            return;
        }

        Node *temp = tail;

        // If there is only one node in the list
        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete temp; // Free the memory occupied by the previous head node
    }
};
*/

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


class Solution
{
public:
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
        while ( fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

 Node* swapPairs(Node* head) {
        Node* dummy = new Node(0);
        dummy->next = head;
        Node* prev = dummy;
        while (head != nullptr && head->next != nullptr) {
            Node* first = head;
            Node* second = head->next;
            
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









    class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        for (int i = 0; i < left-1; i++) {
            prev = prev->next;
        }
        ListNode* curr = prev->next;
        
        for (int i = 0; i < right-left; i++) {
            ListNode* next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }
        
        return dummy->next;
    }
};
// int main()
// {
//     Node*head=nullptr;
//     // Node *newNode = new Node(3);
//     //doublyLinkList dll;
//     dll.insertAtHead(1);
//     dll.insertAtHead(2);
//     dll.insertAtHead(3);

//     swapPairs(head);
//     // dll.insertAtEnd(29);
//     // // dll.deleteAtHead();
//     // dll.deleteAtTail();

//     dll.display();
//     return 0;
// }
