#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class Node
{
public:
    Node<T> *left;
    Node<T> *right;
    T data;

    Node(T data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

template <typename T>
class BST
{

public:
    Node<T> *root;

    BST()
    {
        root = nullptr;
    }
    //.......................................................................................

    // Inorder traversal printing
    void recursivePrinting(Node<T> *root)
    {
        if (root != nullptr)
        {
            recursivePrinting(root->left);
            cout << root->data << " ";
            recursivePrinting(root->right);
        }
    }
    //.......................................................................................

    // search elements un the tree
    bool searchRecursive(Node<T> *node, T data)
    {
        // Base case: if the current node is nullptr, return false
        if (node == nullptr)
        {
            return false;
        }

        // Check if the current node contains the data
        if (node->data == data)
        {
            return true;
        }

        // If data is smaller than the current node's data, search in the left subtree
        if (data < node->data)
        {
            return searchRecursive(node->left, data);
        }
        // If data is larger than the current node's data, search in the right subtree
        else
        {
            return searchRecursive(node->right, data);
        }
    }

    bool search(int data)
    {
        return searchRecursive(root, data);
    }

    //.......................................................................................

    // insert in binary tree randomly
    Node<T> *insertRandomlyInBST(Node<T> *root, T &value)
    {
        if (root == nullptr)
        {
            return new Node<T>(value);
        }

        // Randomly decide whether to insert left or right
        if (rand() % 2 == 0)
        {
            root->left = insert(root->left, value);
        }
        else
        {
            root->right = insert(root->right, value);
        }

        return root;
    }
    //.......................................................................................
    // insertion in BST
    Node<T> *InsertInBST(Node<T> *root, T data)
    {
        if (root == nullptr)
        {
            root = new Node<T>(data);
            return root;
        }
        if (root->data > data)
        {
            root->left = InsertInBST(root->left, data);
        }
        else if (root->data < data)
        {
            root->right = InsertInBST(root->right, data);
        }
        return root;
    }
    //.......................................................................................
    //   traversals method in trees
    vector<int> preorderTraversal()
    {
        Solution1 sol;
        return sol.preorder(root);
    }

    vector<int> inorderTraversal()
    {
        Solution2 sol;
        return sol.inorder(root);
    }

    vector<int> postorderTraversal()
    {
        Solution3 sol;
        return sol.postorder(root);
    }

    class Solution1
    {
    public:
        vector<int> preorder(Node<T> *node)
        {
            vector<int> result;
            preorder(node, result);
            return result;
        }

        void preorder(Node<T> *node, vector<int> &result)
        {
            if (node == nullptr)
            {
                return;
            }

            result.push_back(node->data);
            preorder(node->left, result);
            preorder(node->right, result);
        }
    };

    class Solution2
    {
    public:
        vector<int> inorder(Node<T> *node)
        {
            vector<int> result;
            inorder(node, result);
            return result;
        }

        void inorder(Node<T> *node, vector<int> &result)
        {
            if (node == nullptr)
            {
                return;
            }

            inorder(node->left, result);
            result.push_back(node->data);
            inorder(node->right, result);
        }
    };

    class Solution3
    {
    public:
        vector<int> postorder(Node<T> *node)
        {
            vector<int> result;
            postorder(node, result);
            return result;
        }

        void postorder(Node<T> *node, vector<int> &result)
        {
            if (node == nullptr)
            {
                return;
            }

            postorder(node->left, result);
            postorder(node->right, result);
            result.push_back(node->data);
        }
    };

    void levelOrderTraversal(Node<T> *root)
    {
        if (root == nullptr)
        {
            return;
        }

        queue<Node<T> *> q;
        q.push(root);

        while (!q.empty())
        {
            Node<T> *current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left != nullptr)
            {
                q.push(current->left);
            }
            if (current->right != nullptr)
            {
                q.push(current->right);
            }
        }
    }
    //................................................................................
    bool isSameTree(Node<T> *p, Node<T> *q)
    {
        // If both trees are null, they are identical
        if (p == nullptr && q == nullptr)
        {
            return true;
        }

        // If only one tree is null, they are not identical
        if (p == nullptr || q == nullptr)
        {
            return false;
        }

        // Check if the current nodes' data are the same
        if (p->data == q->data)
        {
            // Check left subtrees and right subtrees recursively
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }

        return false;
    }
    //..............................................................................
    // Even count
    int countEven(Node<T> *root)
    {
        if (root == nullptr)
        {
            return 0; // Base case: No nodes, so no even numbers
        }

        int count = 0;
        if (root->data % 2 == 0)
        {
            count = 1; // If the current node's value is even, count as 1
        }

        // Recursively count even numbers in left and right subtrees
        return count + countEven(root->left) + countEven(root->right);
    }
    //..................................................................................

    int countLeaves(Node<T> *root)
    {
        if (root == nullptr)
        {
            return 0; // Base case: No nodes, so no leaves
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            return 1; // If it's a leaf node, return 1
        }

        // Recursively count leaf nodes in left and right subtrees
        return countLeaves(root->left) + countLeaves(root->right);
    }
    //.................................................................................

    //        1
    //       / \\
    //      2   3
    //     / \   \\
    //    4   5   6
    //           /
    //          7
    //     Dry Run:
    // Call maxHeight(root) with root = Node(1)
    // root != nullptr, proceed to next step.
    // leftHeight = maxHeight(root->left) -> maxHeight(2)
    // root != nullptr, proceed to next step.
    // leftHeight = maxHeight(root->left) -> maxHeight(4)
    // root != nullptr, proceed to next step.
    // leftHeight = maxHeight(root->left) -> maxHeight(null)
    // root == nullptr, return 0 (height of an empty tree is 0).
    // rightHeight = maxHeight(root->right) -> maxHeight(null)
    // root == nullptr, return 0.
    // Return 1 + max(0, 0) = 1.
    // rightHeight = maxHeight(root->right) -> maxHeight(5)
    // Both root->left and root->right are null, so both leftHeight and rightHeight are 0.
    // Return 1 + max(0, 0) = 1.
    // Return 1 + max(1, 1) = 2.
    // rightHeight = maxHeight(root->right) -> maxHeight(3)
    // root != nullptr, proceed to next step.
    // leftHeight = maxHeight(root->left) -> maxHeight(null)
    // root == nullptr, return 0.
    // rightHeight = maxHeight(root->right) -> maxHeight(6)
    // root != nullptr, proceed to next step.
    // leftHeight = maxHeight(root->left) -> maxHeight(7)
    // root != nullptr, proceed to next step.
    // Both root->left and root->right are null, so both leftHeight and rightHeight are 0.
    // Return 1 + max(0, 0) = 1.
    // rightHeight = maxHeight(root->right) -> maxHeight(null)
    // root == nullptr, return 0.
    // Return 1 + max(0, 1) = 2.
    // Return 1 + max(0, 2) = 3.
    // Return 1 + max(2, 3) = 4.

    int maxHeight(Node<T> *root)
    {
        if (root == nullptr)
        {
            return 0; // Height of an empty tree is 0
        }

        int leftHeight = maxHeight(root->left);   // Height of left subtree
        int rightHeight = maxHeight(root->right); // Height of right subtree

        // Return the maximum height between the left and right subtrees, plus 1 for the current level
        return 1 + max(leftHeight, rightHeight);
    }

    //...................................................................................

    bool Validate_BST(Node<T> *root, T minVal, T maxVal)
    {
        // If the current node is null, it satisfies the BST property
        if (root == nullptr)
        {
            return true;
        }

        // Checking if the current node's value is within the allowed range
        if (root->data > minVal && root->data < maxVal)
        {
            // Recursively check left and right subtrees
            bool leftValid = Validate_BST(root->left, minVal, root->data);
            bool rightValid = Validate_BST(root->right, root->data, maxVal);

            // Both left and right subtrees should be valid BSTs
            return leftValid && rightValid;
        }

        // If the current node's value violates the BST property
        return false;
    }

    //.......................................................................
    void printGivenLevel(Node<T> *node, int level)
    {
        if (node == nullptr)
        {
            return;
        }
        if (level == 1)
        {
            cout << node->data << " ";
        }
        else if (level > 1)
        {
            printGivenLevel(node->left, level - 1);
            printGivenLevel(node->right, level - 1);
        }
    }

    void outputTree()
    {
        int height = maxHeight(root);
        for (int i = 1; i <= height; i++)
        {
            printGivenLevel(root, i);
            cout << endl;
        }
    }
    //..............................................................

    int countInternalNodes(Node<T> *node)
    {
        if (node == nullptr || (node->left == nullptr && node->right == nullptr))
        {
            return 0;
        }

        return 1 + countInternalNodes(node->left) + countInternalNodes(node->right);
    }
    int getInternalNodesCount()
    {
        return countInternalNodes(root);
    }
};

int main()
{
    BST<int> tree;
    tree.root = tree.InsertInBST(tree.root, 4);
    tree.root = tree.InsertInBST(tree.root, 2);
    tree.root = tree.InsertInBST(tree.root, 1);
    tree.root = tree.InsertInBST(tree.root, 3);
    tree.root = tree.InsertInBST(tree.root, 6);
    tree.root = tree.InsertInBST(tree.root, 5);
    tree.root = tree.InsertInBST(tree.root, 7);

    // cout << "Pre-order Traversal: ";
    // for (int val : tree.preorderTraversal())
    // {
    //     cout << val << " ";
    // }
    // cout << endl;

    // cout << "In-order Traversal: ";
    // for (int val : tree.inorderTraversal())
    // {
    //     cout << val << " ";
    // }
    // cout << endl;

    // cout << "Post-order Traversal: ";
    // for (int val : tree.postorderTraversal())
    // {
    //     cout << val << " ";
    // }
    // cout << endl;

    // bool isFound = tree.search(50);
    // if (isFound)
    // {
    //     cout << "Found" << endl;
    // }
    // else
    // {
    //     cout << "Not found" << endl;
    // }

    // Creating the first binary tree
    // Creating the first binary tree
    // Node<int> *p = new Node<int>(1);
    // p->left = new Node<int>(2);
    // p->right = new Node<int>(3);
    // p->left->left = new Node<int>(4);

    // // Creating the second binary tree
    // Node<int> *q = new Node<int>(1);
    // q->left = new Node<int>(2);
    // q->right = new Node<int>(3);
    // q->left->left = new Node<int>(4);

    // bool areSame = tree.isSameTree(p, q);

    // if (areSame)
    // {
    //     cout << "The trees are identical." << endl;
    // }
    // else
    // {
    //     cout << "The trees are not identical." << endl;
    // }
    cout << "Tree output:" << endl;
    tree.outputTree();
    cout << endl;
    int internalNodesCount = tree.getInternalNodesCount();
    cout << "Number of internal nodes: " << internalNodesCount << endl;

    cout << "Level Order Traversal: ";
    tree.levelOrderTraversal(tree.root);
    cout << endl;

    return 0;
}
