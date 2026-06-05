#include <iostream>
#include <queue>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;
    char colour;
};

template <class T>
class RedBlackTree
{
private:
    Node<T> *root;

    Node<T> *createNode(T value)
    {
        Node<T> *newNode = new Node<T>;
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->colour = 'R';
        return newNode;
    }

    bool isRed(Node<T> *node)
    {
        return node != NULL && node->colour == 'R';
    }

    // Find parent using 2-pointer approach (no parent pointer in struct)
    Node<T> *getParent(Node<T> *current, Node<T> *child)
    {
        if (current == NULL || current == child)
            return NULL;

        if (current->left == child || current->right == child)
            return current;

        if (child->data < current->data)
            return getParent(current->left, child);
        else
            return getParent(current->right, child);
    }

    Node<T> *getGrandparent(Node<T> *node)
    {
        Node<T> *parent = getParent(root, node);
        if (parent == NULL)
            return NULL;
        return getParent(root, parent);
    }

    Node<T> *getUncle(Node<T> *node)
    {
        Node<T> *parent = getParent(root, node);
        Node<T> *grandparent = getGrandparent(node);

        if (grandparent == NULL)
            return NULL;

        if (parent == grandparent->left)
            return grandparent->right;
        else
            return grandparent->left;
    }

    // Replace child of a parent (or update root if no parent)
    void replaceChild(Node<T> *parent, Node<T> *oldChild, Node<T> *newChild)
    {
        if (parent == NULL)
            root = newChild;
        else if (parent->left == oldChild)
            parent->left = newChild;
        else
            parent->right = newChild;
    }

    // Left rotation around node x
    //        gp                gp
    void rotateLeft(Node<T> *x)
    {
        Node<T> *y = x->right;            // y is right child of x
        Node<T> *gp = getParent(root, x); // grandparent (parent of x)

        x->right = y->left; // b becomes right child of x
        y->left = x;        // x becomes left child of y

        replaceChild(gp, x, y); // y takes x's place in the tree

        // Swap colours: y gets x's old colour, x becomes red
        char temp = x->colour;
        x->colour = y->colour;
        y->colour = temp;
    }

    // Right rotation around node x

    void rotateRight(Node<T> *x)
    {
        Node<T> *y = x->left;             // y is left child of x
        Node<T> *gp = getParent(root, x); // grandparent (parent of x)

        x->left = y->right; // b becomes left child of x
        y->right = x;       // x becomes right child of y

        replaceChild(gp, x, y); // y takes x's place in the tree

        // Swap colours
        char temp = x->colour;
        x->colour = y->colour;
        y->colour = temp;
    }

    void fixInsertion(Node<T> *node)
    {
        // Keep fixing while node is not root and parent is red
        while (node != root && isRed(getParent(root, node)))
        {
            Node<T> *parent = getParent(root, node);
            Node<T> *grandparent = getGrandparent(node);
            Node<T> *uncle = getUncle(node);

            // ── Case 3: Parent AND Uncle are RED → Recolour ──────────────
            if (isRed(uncle))
            {
                parent->colour = 'B';
                uncle->colour = 'B';
                grandparent->colour = 'R';

                // Move up: grandparent might now violate rules
                node = grandparent;
            }

            // ── Uncle is BLACK (or NULL) → Rotation needed ───────────────
            else
            {
                // Parent is LEFT child of grandparent
                if (parent == grandparent->left)
                {
                    // Case 4: Left-Right → rotate parent left first
                    if (node == parent->right)
                    {
                        rotateLeft(parent);
                        // After rotation, old parent is now child of node
                        // Re-fetch for Case 5
                        node = parent; // old parent is now the lower node
                        parent = getParent(root, node);
                        grandparent = getGrandparent(node);
                    }

                    // Case 5: Left-Left → rotate grandparent right
                    rotateRight(grandparent);
                }

                // Parent is RIGHT child of grandparent
                else
                {
                    // Case 4: Right-Left → rotate parent right first
                    if (node == parent->left)
                    {
                        rotateRight(parent);
                        node = parent;
                        parent = getParent(root, node);
                        grandparent = getGrandparent(node);
                    }

                    // Case 5: Right-Right → rotate grandparent left
                    rotateLeft(grandparent);
                }
            }
        }

        // Root is always black
        root->colour = 'B';
    }

public:
    RedBlackTree()
    {
        root = NULL;
    }

    void insert(T value)
    {
        Node<T> *newNode = createNode(value);

        // Case 1: Tree is empty → new node becomes root
        if (root == NULL)
        {
            newNode->colour = 'B';
            root = newNode;
            return;
        }

        // Standard BST insert
        Node<T> *current = root;
        Node<T> *parent = nullptr;

        while (current != nullptr)
        {
            parent = current;
            if (value < current->data)
                current = current->left;
            else if (value > current->data)
                current = current->right;
            else
            {
                delete newNode; // duplicate, ignore
                return;
            }
        }

        if (value < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;

        // Case 2: Parent is black → no fix needed
        if (parent->colour == 'B')
            return;

        // Cases 3, 4, 5 handled in fixInsertion
        fixInsertion(newNode);
    }

    void inorder(Node<T> *node)
    {
        if (node == NULL)
            return;
        inorder(node->left);
        cout << node->data << "(" << node->colour << ") ";
        inorder(node->right);
    }

    void inorder()
    {
        inorder(root);
        cout << endl;
    }

    void levelOrder()
    {
        if (root == NULL)
            return;

        queue<Node<T> *> q;
        q.push(root);

        while (!q.empty())
        {
            Node<T> *current = q.front();
            q.pop();

            cout << current->data << "(" << current->colour << ") ";

            if (current->left != NULL)
                q.push(current->left);
            if (current->right != NULL)
                q.push(current->right);
        }
        cout << endl;
    }
};

int main()
{
    // ── Test 1: original values from the assignment ───────────────────────
    cout << "=== Test 1: 500 800 1500 300 3000 2000 4000 ===" << endl;
    RedBlackTree<int> tree;
    tree.insert(500);
    tree.insert(800);
    tree.insert(1500);
    tree.insert(300);
    tree.insert(3000);
    tree.insert(2000);
    tree.insert(4000);

    cout << "Inorder:     ";
    tree.inorder();
    cout << "Level Order: ";
    tree.levelOrder();

    // ── Test 2: sequential insert from the lecture slides ────────────────
    cout << "\n=== Test 2: 1..11 ===" << endl;
    RedBlackTree<int> tree2;
    for (int i = 1; i <= 11; i++)
        tree2.insert(i);

    cout << "Inorder:     ";
    tree2.inorder();
    cout << "Level Order: ";
    tree2.levelOrder();

    // ── Test 3: lecture example (Case 5 - left-left) ─────────────────────
    cout << "\n=== Test 3: 100 95 90 ===" << endl;
    RedBlackTree<int> tree3;
    tree3.insert(100);
    tree3.insert(95);
    tree3.insert(90);
    cout << "Inorder:     ";
    tree3.inorder();
    cout << "Level Order: ";
    tree3.levelOrder();

    return 0;
}