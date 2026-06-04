#include <iostream>

enum Color
{
    RED,
    BLACK
};

struct Node
{
    int data;
    Color color;
    Node *left;
    Node *right;

    Node(int val) : data(val), color(RED), left(nullptr), right(nullptr) {}
};

class RedBlackTree
{
private:
    Node *root;

    // Helper utilities
    bool isRed(Node *node)
    {
        return node != nullptr && node->color == RED;
    }

    void swapColors(Node *n1, Node *n2)
    {
        Color temp = n1->color;
        n1->color = n2->color;
        n2->color = temp;
    }

    // Rotations modify local tree structures and return the new local root
    Node *rotateLeft(Node *node)
    {
        Node *child = node->right;
        node->right = child->left;
        child->left = node;
        return child;
    }

    Node *rotateRight(Node *node)
    {
        Node *child = node->left;
        node->left = child->right;
        child->right = node;
        return child;
    }

    // Recursive insertion that fixes violations on the way back up
    Node *insertHelp(Node *node, int data)
    {
        // Step 1: Standard BST Insertion
        if (node == nullptr)
        {
            return new Node(data);
        }

        if (data < node->data)
        {
            node->left = insertHelp(node->left, data);
        }
        else if (data > node->data)
        {
            node->right = insertHelp(node->right, data);
        }
        else
        {
            return node; // Duplicate keys not allowed
        }

        // Step 2: Fix Red-Red Violations (Looking down at children/grandchildren)

        // CASE A: Left Child is Red and its Left Grandchild is Red (LL Case)
        if (isRed(node->left) && isRed(node->left->left))
        {
            // Check Uncle (Right child)
            if (isRed(node->right))
            { // Uncle is Red -> Recolor
                node->color = RED;
                node->left->color = BLACK;
                node->right->color = BLACK;
            }
            else
            { // Uncle is Black -> Rotate Right and Swap Colors
                node = rotateRight(node);
                swapColors(node, node->right);
            }
        }
        // CASE B: Left Child is Red and its Right Grandchild is Red (LR Case)
        else if (isRed(node->left) && isRed(node->left->right))
        {
            if (isRed(node->right))
            { // Uncle is Red -> Recolor
                node->color = RED;
                node->left->color = BLACK;
                node->right->color = BLACK;
            }
            else
            { // Uncle is Black -> Left Rotate Child, Right Rotate Parent
                node->left = rotateLeft(node->left);
                node = rotateRight(node);
                swapColors(node, node->right);
            }
        }
        // CASE C: Right Child is Red and its Right Grandchild is Red (RR Case)
        else if (isRed(node->right) && isRed(node->right->right))
        {
            // Check Uncle (Left child)
            if (isRed(node->left))
            { // Uncle is Red -> Recolor
                node->color = RED;
                node->left->color = BLACK;
                node->right->color = BLACK;
            }
            else
            { // Uncle is Black -> Rotate Left and Swap Colors
                node = rotateLeft(node);
                swapColors(node, node->left);
            }
        }
        // CASE D: Right Child is Red and its Left Grandchild is Red (RL Case)
        else if (isRed(node->right) && isRed(node->right->left))
        {
            if (isRed(node->left))
            { // Uncle is Red -> Recolor
                node->color = RED;
                node->left->color = BLACK;
                node->right->color = BLACK;
            }
            else
            { // Uncle is Black -> Right Rotate Child, Left Rotate Parent
                node->left = rotateRight(node->right);
                node = rotateLeft(node);
                swapColors(node, node->left);
            }
        }

        return node;
    }

    void inorderHelp(Node *node)
    {
        if (node == nullptr)
            return;
        inorderHelp(node->left);
        std::cout << node->data << "(" << (node->color == RED ? "R" : "B") << ") ";
        inorderHelp(node->right);
    }

public:
    RedBlackTree() : root(nullptr) {}

    void insert(int data)
    {
        root = insertHelp(root, data);
        if (root != nullptr)
        {
            root->color = BLACK; // Root must always be black
        }
    }

    void inorder()
    {
        inorderHelp(root);
        std::cout << std::endl;
    }
};

int main()
{
    RedBlackTree tree;

    // Test basic tree properties
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(15);
    tree.insert(25);

    std::cout << "Inorder Traversal of Created Red-Black Tree: " << std::endl;
    tree.inorder();

    return 0;
}