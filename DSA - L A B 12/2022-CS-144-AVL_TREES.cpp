/*                                      AVL Trees
-->Build BST 1, 2, 3, 4, 5, 6, 7

The given sequence, 1, 2, 3, 4, 5, 6, 7, forms a linear binary tree when arranged in sequential order. This linear structure leads to inefficient operations with a time complexity of O(n^2) in worst-case scenarios. To overcome this inefficiency, AVL trees can be employed.

AVL trees are balanced binary search trees that ensure logarithmic time complexity (O(log n)) for insertion, deletion, and search operations by maintaining balance through rotations when necessary.
*/

/*   ==>Balance Factor
    The balance factor of a node in an AVL tree is defined as the difference between the height of its left subtree and the height of its right subtree. The goal is to keep this balance factor in the range of -1, 0, or 1 to maintain the balance of the tree.
    Height(leftsubtree)-Height(rightsubtree)==>should be (-1,0,1)
*/

/*

                                 Insertion in AVL

     y                               x
    / \     Right Rotation          /  \
   x   T3   - - - - - - - >        T1   y
  / \       < - - - - - - -            / \
 T1  T2     Left Rotation            T2  T3

                -->  rightRotate
Why Identify x and T2:
Role of x:

x becomes the new root of the rotated subtree after the right rotation.
It was the left child of the original node root, and it becomes the "upper" node in the rotated structure.

Role of T2:
T2 represents the right subtree of the node x.
During the rotation, T2 gets reattached as the left child of the original node root (root->left).

*/

#include <iostream>
using namespace std;

class AVL_Tree
{
    struct Node
    {
        int value;
        Node *LeftSubTree;
        Node *RightSubTree;
        int height;

        Node(int val) {
          this->value=val;
          this->LeftSubTree=nullptr;
          this->RightSubTree=nullptr;
          this->height=1;
        }
    };

public:
    Node *root;

    AVL_Tree() : root(nullptr) {}

    int Height(Node *root)
    {
        if (root == nullptr)
            return 0;
        return root->height;
    }

    int HeightDifference(Node *root)
    {
        if (root == nullptr)
            return 0;
        return Height(root->LeftSubTree) - Height(root->RightSubTree);
    }

    Node *rightRotate(Node *y)
    {
        Node *x = y->LeftSubTree;
        Node *T2 = x->RightSubTree;

        // Perform rotation
        x->RightSubTree = y;
        y->LeftSubTree = T2;

        // Update heights
        y->height = 1 + max(Height(y->LeftSubTree), Height(y->RightSubTree));
        x->height = 1 + max(Height(x->LeftSubTree), Height(x->RightSubTree));

        return x;
    }

    Node *LeftRotate(Node *x)
    {
        Node *y = x->RightSubTree;
        Node *T2 = y->LeftSubTree;

        // Perform rotation
        y->LeftSubTree = x;
        x->RightSubTree = T2;

        // Update heights
        x->height = 1 + max(Height(x->LeftSubTree), Height(x->RightSubTree));
        y->height = 1 + max(Height(y->LeftSubTree), Height(y->RightSubTree));

        return y;
    }

    Node *InsertInAVL(int val, Node *root)
    {
        if (root == nullptr)
            return new Node(val);

        if (val < root->value)
            root->LeftSubTree = InsertInAVL(val, root->LeftSubTree);
        else if (val > root->value)
            root->RightSubTree = InsertInAVL(val, root->RightSubTree);
        else
            return root;

        // Update height of the current node
        root->height = 1 + max(Height(root->LeftSubTree), Height(root->RightSubTree));

        // Get the balance factor
        int balanceFactor = HeightDifference(root);

        // Perform rotations if necessary

        // Left Left Case
        if (balanceFactor > 1 && val < root->LeftSubTree->value)
            return rightRotate(root);

        // Right Right Case
        if (balanceFactor < -1 && val > root->RightSubTree->value)
            return LeftRotate(root);

        // Left Right Case (LR)
        if (balanceFactor > 1 && val > root->LeftSubTree->value)
        {
            root->LeftSubTree = LeftRotate(root->LeftSubTree);
            return rightRotate(root);
        }

        // Right Left Case (RL)
        if (balanceFactor < -1 && val < root->RightSubTree->value)
        {
            root->RightSubTree = rightRotate(root->RightSubTree);
            return LeftRotate(root);
        }

        return root;
    }

    void Insert(int val)
    {
        root = InsertInAVL(val, root);
    }

    Node *minValueNode(Node *node)
    {
        Node *current = node;
        while (current->LeftSubTree != nullptr)
            current = current->LeftSubTree;
        return current;
    }

    Node *DelFromAVL(int val, Node *root)
    {
        if (root == nullptr)
            return root;

        if (val < root->value)
            root->LeftSubTree = DelFromAVL(val, root->LeftSubTree);
        else if (val > root->value)
            root->RightSubTree = DelFromAVL(val, root->RightSubTree);
        else
        {
            if (root->LeftSubTree == nullptr || root->RightSubTree == nullptr)
            {
                Node *temp = root->LeftSubTree ? root->LeftSubTree : root->RightSubTree;

                if (temp == nullptr)
                {
                    temp = root;
                    root = nullptr;
                }
                else
                    *root = *temp;

                delete temp;
            }
            else
            {
                Node *temp = minValueNode(root->RightSubTree);
                root->value = temp->value;
                root->RightSubTree = DelFromAVL(temp->value, root->RightSubTree);
            }
        }

        if (root == nullptr)
            return root;

        // Update height of the current node
        root->height = 1 + max(Height(root->LeftSubTree), Height(root->RightSubTree));

        // Get the balance factor
        int balanceFactor = HeightDifference(root);

        // Perform rotations if necessary

        // Left Left Case
        if (balanceFactor > 1 && HeightDifference(root->LeftSubTree) >= 0)
            return rightRotate(root);

        // Right Right Case
        if (balanceFactor < -1 && HeightDifference(root->RightSubTree) <= 0)
            return LeftRotate(root);

        // Left Right Case (LR)
        if (balanceFactor > 1 && HeightDifference(root->LeftSubTree) < 0)
        {
            root->LeftSubTree = LeftRotate(root->LeftSubTree);
            return rightRotate(root);
        }

        // Right Left Case (RL)
        if (balanceFactor < -1 && HeightDifference(root->RightSubTree) > 0)
        {
            root->RightSubTree = rightRotate(root->RightSubTree);
            return LeftRotate(root);
        }

        return root;
    }

    void Del(int val)
    {
        root = DelFromAVL(val, root);
    }

    void Traversal(Node *root)
    {
        if (root == nullptr)
            return;

        Traversal(root->LeftSubTree);
        cout << root->value << " ";
        Traversal(root->RightSubTree);
    }

    /*
    class Solution {
    public:
        vector<TreeNode*> nodes; // To store nodes in sorted order

        // In-order traversal to store nodes in sorted order
        void inOrder(TreeNode* root) {
            if (!root) return;
            inOrder(root->left);
            nodes.push_back(root);
            inOrder(root->right);
        }

        // Construct a balanced BST from sorted nodes
        TreeNode* constructBST(int start, int end) {
            if (start > end) return nullptr;

            int mid = start + (end - start) / 2;
            TreeNode* node = nodes[mid];

            node->left = constructBST(start, mid - 1);
            node->right = constructBST(mid + 1, end);

            return node;
        }

        TreeNode* balanceBST(TreeNode* root) {
            // Step 1: Traverse BST and store nodes in sorted array
            inOrder(root);

            // Step 2: Construct a new balanced BST from the sorted array
            return constructBST(0, nodes.size() - 1);
        }
    };

    class Solution {
    public:
        // Function to calculate height of the tree and check balance
        int checkHeight(TreeNode* root) {
            if (root == nullptr) return 0;

            int leftHeight = checkHeight(root->left);
            if (leftHeight == -1) return -1; // Left subtree is unbalanced

            int rightHeight = checkHeight(root->right);
            if (rightHeight == -1) return -1; // Right subtree is unbalanced

            int heightDiff = abs(leftHeight - rightHeight);
            if (heightDiff > 1) return -1; // Tree is unbalanced

            return 1 + max(leftHeight, rightHeight); // Return height of current node
        }

        bool isBalanced(TreeNode* root) {
            return checkHeight(root) != -1;
        }
    };
    */
};

int main()
{
    AVL_Tree avlTree;

    avlTree.Insert(10);
    avlTree.Insert(20);
    avlTree.Insert(30);
    avlTree.Insert(40);
    avlTree.Insert(50);
    avlTree.Insert(25);

    cout << "Height of the tree: " << avlTree.Height(avlTree.root) << endl;
    avlTree.Traversal(avlTree.root);

    avlTree.Del(25);
    cout << "\nHeight of the tree after deletion: " << avlTree.Height(avlTree.root) << endl;
    avlTree.Traversal(avlTree.root);

    return 0;
}
