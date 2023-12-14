//                             Red Black tree

//https://www.geeksforgeeks.org/introduction-to-red-black-tree/

// Red black trees require less rotations than AVL trees when inserting or deleting nodes. This means that they can perform these operations faster and more efficiently12.

// every Red black tree is not a AVL tree-->roughly height balnced
//  Max 2 rotation will be required

// search: O(log n)

// Insertion:O(log n)

// Deletion:O(log n)

// Red black trees only need one bit of extra information per node to store the color (red or black), while AVL trees need more space to store the balance factor or height of each node12

// its a self balancing BST
// every node is either Black or Red
// Root is always black
// Every leaf which is nill is black
// if node is red then its children black
// every path from a node to any of its descendent NIL node has same number of black nodes

/*
example:
      10 (Black)
     /   \
   5(Red)  15(Red)
  /  \     /   \
3(B) 7(B) 12(B) 18(B)

                   10 (Black)
                /              \
          5 (Black)          20 (Black)
         /      \           /       \
    3 (Red)   8 (Red)   15 (Red)  25 (Red)
   /   \     /    \     /    \     /     \
1(B) 4(B) 7(B) 9(B) 13(B) 18(B) 23(B) 30(B)

*/
#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T key;
    Node<T> *left, *right, *parent;
    bool isRed;

    Node(T data) : key(data), left(nullptr), right(nullptr), parent(nullptr), isRed(true) {}
};

template <typename T>
class RedBlackTree {
private:
    Node<T>* root;

    void leftRotate(Node<T>* x) {
        Node<T>* y = x->right;
        x->right = y->left;

        if (y->left != nullptr)
            y->left->parent = x;

        y->parent = x->parent;

        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node<T>* y) {
        Node<T>* x = y->left;
        y->left = x->right;

        if (x->right != nullptr)
            x->right->parent = y;

        x->parent = y->parent;

        if (y->parent == nullptr)
            root = x;
        else if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;

        x->right = y;
        y->parent = x;
    }

    void insertFixup(Node<T>* newNode) {
        while (newNode != root && newNode->parent->isRed) {
            if (newNode->parent == newNode->parent->parent->left) {
                Node<T>* uncle = newNode->parent->parent->right;
                if (uncle != nullptr && uncle->isRed) {
                    newNode->parent->isRed = false;
                    uncle->isRed = false;
                    newNode->parent->parent->isRed = true;
                    newNode = newNode->parent->parent;
                } else {
                    if (newNode == newNode->parent->right) {
                        newNode = newNode->parent;
                        leftRotate(newNode);
                    }
                    newNode->parent->isRed = false;
                    newNode->parent->parent->isRed = true;
                    rightRotate(newNode->parent->parent);
                }
            } else {
                Node<T>* uncle = newNode->parent->parent->left;
                if (uncle != nullptr && uncle->isRed) {
                    newNode->parent->isRed = false;
                    uncle->isRed = false;
                    newNode->parent->parent->isRed = true;
                    newNode = newNode->parent->parent;
                } else {
                    if (newNode == newNode->parent->left) {
                        newNode = newNode->parent;
                        rightRotate(newNode);
                    }
                    newNode->parent->isRed = false;
                    newNode->parent->parent->isRed = true;
                    leftRotate(newNode->parent->parent);
                }
            }
        }
        root->isRed = false;
    }

    void transplant(Node<T>* u, Node<T>* v) {
        if (u->parent == nullptr)
            root = v;
        else if (u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;

        if (v != nullptr)
            v->parent = u->parent;
    }

    Node<T>* minimum(Node<T>* x) {
        while (x->left != nullptr)
            x = x->left;
        return x;
    }

    void deleteFixup(Node<T>* x) {
        while (x != root && !x->isRed) {
            if (x == x->parent->left) {
                Node<T>* w = x->parent->right;
                if (w->isRed) {
                    w->isRed = false;
                    x->parent->isRed = true;
                    leftRotate(x->parent);
                    w = x->parent->right;
                }
                if (!w->left->isRed && !w->right->isRed) {
                    w->isRed = true;
                    x = x->parent;
                } else {
                    if (!w->right->isRed) {
                        w->left->isRed = false;
                        w->isRed = true;
                        rightRotate(w);
                        w = x->parent->right;
                    }
                    w->isRed = x->parent->isRed;
                    x->parent->isRed = false;
                    w->right->isRed = false;
                    leftRotate(x->parent);
                    x = root;
                }
            } else {
                Node<T>* w = x->parent->left;
                if (w->isRed) {
                    w->isRed = false;
                    x->parent->isRed = true;
                    rightRotate(x->parent);
                    w = x->parent->left;
                }
                if (!w->right->isRed && !w->left->isRed) {
                    w->isRed = true;
                    x = x->parent;
                } else {
                    if (!w->left->isRed) {
                        w->right->isRed = false;
                        w->isRed = true;
                        leftRotate(w);
                        w = x->parent->left;
                    }
                    w->isRed = x->parent->isRed;
                    x->parent->isRed = false;
                    w->left->isRed = false;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->isRed = false;
    }

public:
    RedBlackTree() : root(nullptr) {}

    void insert(T key) {
        Node<T>* newNode = new Node<T>(key);
        Node<T>* y = nullptr;
        Node<T>* x = root;

        while (x != nullptr) {
            y = x;
            if (newNode->key < x->key)
                x = x->left;
            else
                x = x->right;
        }

        newNode->parent = y;
        if (y == nullptr)
            root = newNode;
        else if (newNode->key < y->key)
            y->left = newNode;
        else
            y->right = newNode;

        insertFixup(newNode);
    }

    void remove(T key) {
        Node<T>* z = search(key);
        if (z == nullptr)
            return;

        Node<T>* y = z;
        Node<T>* x;
        bool yOriginalColor = y->isRed;

        if (z->left == nullptr) {
            x = z->right;
            transplant(z, z->right);
        } else if (z->right == nullptr) {
            x = z->left;
            transplant(z, z->left);
        } else {
            y = minimum(z->right);
            yOriginalColor = y->isRed;
            x = y->right;
            if (y->parent == z)
                x->parent = y;
            else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->isRed = z->isRed;
        }
        if (!yOriginalColor)
            deleteFixup(x);
        delete z;
    }

    Node<T>* search(T key) {
        Node<T>* current = root;
        while (current != nullptr && current->key != key) {
            if (key < current->key)
                current = current->left;
            else
                current = current->right;
        }
        return current;
    }

    // Other methods for traversal, printing tree, etc.
};

int main() {
    RedBlackTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    Node<int>* found = tree.search(5);
    if (found != nullptr)
        cout << "Element found: " << found->key << endl;
    else
        cout << "Element not found" << endl;

    tree.remove(5);
    // Perform other operations here

    return 0;
}
