#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;
    char colour; // 'R' or 'B'
};

template <class T>
class RedBlackTree
{
private:
    Node<T> *root;

    // Create new node (always RED initially)
    Node<T> *createNode(T value)
    {
        Node<T> *n = new Node<T>;
        n->data = value;
        n->left = NULL;
        n->right = NULL;
        n->colour = 'R';
        return n;
    }

    bool isRed(Node<T> *node)
    {
        return node != NULL && node->colour == 'R';
    }

    // Find parent (no parent pointer)
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
        Node<T> *p = getParent(root, node);
        if (!p)
            return NULL;
        return getParent(root, p);
    }

    Node<T> *getUncle(Node<T> *node)
    {
        Node<T> *p = getParent(root, node);
        Node<T> *g = getGrandparent(node);

        if (!g || !p)
            return NULL;

        if (g->left == p)
            return g->right;
        return g->left;
    }

    // Replace child pointer
    void replaceChild(Node<T> *parent, Node<T> *oldChild, Node<T> *newChild)
    {
        if (parent == NULL)
        {
            root = newChild;
        }
        else if (parent->left == oldChild)
        {
            parent->left = newChild;
        }
        else
        {
            parent->right = newChild;
        }
    }

    // LEFT ROTATION (NO color changes here)
    void rotateLeft(Node<T> *x)
    {
        Node<T> *y = x->right;
        Node<T> *gp = getParent(root, x);

        if (y == NULL)
            return;

        x->right = y->left;
        y->left = x;

        replaceChild(gp, x, y);
    }

    // RIGHT ROTATION (NO color changes here)
    void rotateRight(Node<T> *x)
    {
        Node<T> *y = x->left;
        Node<T> *gp = getParent(root, x);

        if (y == NULL)
            return;

        x->left = y->right;
        y->right = x;

        replaceChild(gp, x, y);
    }

    // FIX INSERTION
    void fixInsertion(Node<T> *node)
    {
        while (node != root && isRed(getParent(root, node)))
        {
            Node<T> *parent = getParent(root, node);
            Node<T> *grandparent = getGrandparent(node);
            Node<T> *uncle = getUncle(node);

            // CASE 3: Parent RED + Uncle RED → recolor
            if (isRed(uncle))
            {
                parent->colour = 'B';
                uncle->colour = 'B';
                grandparent->colour = 'R';

                node = grandparent;
            }
            else
            {
                // Parent is LEFT child
                if (parent == grandparent->left)
                {
                    // LR case
                    if (node == parent->right)
                    {
                        rotateLeft(parent);
                        node = parent;
                        parent = getParent(root, node);
                    }

                    // LL case
                    parent->colour = 'B';
                    grandparent->colour = 'R';
                    rotateRight(grandparent);
                }
                else
                {
                    // RL case
                    if (node == parent->left)
                    {
                        rotateRight(parent);
                        node = parent;
                        parent = getParent(root, node);
                    }

                    // RR case
                    parent->colour = 'B';
                    grandparent->colour = 'R';
                    rotateLeft(grandparent);
                }
            }
        }

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

        if (root == NULL)
        {
            newNode->colour = 'B';
            root = newNode;
            return;
        }

        Node<T> *cur = root;
        Node<T> *parent = NULL;

        while (cur != NULL)
        {
            parent = cur;

            if (value < cur->data)
                cur = cur->left;
            else if (value > cur->data)
                cur = cur->right;
            else
            {
                delete newNode;
                return;
            }
        }

        if (value < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;

        if (parent->colour == 'B')
            return;

        fixInsertion(newNode);
    }

    void inorder(Node<T> *node)
    {
        if (!node)
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

    void preorder(Node<T> *node)
    {
        if (!node)
            return;
        cout << node->data << "(" << node->colour << ") ";
        preorder(node->left);
        preorder(node->right);
    }

    void preorder()
    {
        preorder(root);
        cout << endl;
    }
    void postorder(Node<T> *node)
    {
        if (!node)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << "(" << node->colour << ") ";
    }

    void postorder()
    {
        postorder(root);
        cout << endl;
    }
    void deleteTree(Node<T> *node)
    {
        if (!node)
            return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

    bool deleteValue(T value);

    void Search(T value)
    {
        Node<T> *cur = root;
        while (cur != NULL)
        {
            if (value < cur->data)
                cur = cur->left;
            else if (value > cur->data)
                cur = cur->right;
            else
            {
                cout << "Found: " << cur->data << "(" << cur->colour << ")" << endl;
                return;
            }
        }
        cout << "Not found: " << value << endl;
    }
    ~RedBlackTree()
    {
        // Implement a destructor to free memory (not shown here)
        deleteTree(root);
    }
};

int main()
{
    // ── Test 1: original values from the assignment ───────────────────────
    // cout << "=== Test 1: 500 800 1500 300 3000 2000 4000 ===" << endl;
    RedBlackTree<int> tree;
    // tree.insert(500);
    // tree.insert(800);
    // tree.insert(1500);
    // tree.insert(300);
    // tree.insert(3000);
    // tree.insert(2000);
    // tree.insert(4000);

    // cout << "Inorder:     ";
    // tree.inorder();
    // // ── Test 2: sequential insert from the lecture slides ────────────────
    // cout << "\n=== Test 2: 1..11 ===" << endl;
    // RedBlackTree<int> tree2;
    // for (int i = 1; i <= 11; i++)
    //     tree2.insert(i);

    // cout << "Inorder:     ";

    // // ── Test 3: lecture example (Case 5 - left-left) ─────────────────────
    // cout << "\n=== Test 3: 100 95 90 ===" << endl;
    // RedBlackTree<int> tree3;
    // tree3.insert(100);
    // tree3.insert(95);
    // tree3.insert(90);
    // cout << "Inorder:     ";
    // tree3.inorder();

    // •	User-friendly interface/menu
    cout << "\n=== Interactive Search ===" << endl;
    // Create dash board for user input
    int choice, value;
    // 1. Inset 2. Search 3 inorder 4. preorder 5. postorder 6. delete value 7. exit
    while (true)
    {
        cout << "\nMenu:\n1. Insert\n2. Search\n3. Inorder Traversal\n4. Preorder Traversal\n5. Postorder Traversal\n6. Delete Value\n7. Exit\nEnter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter value to insert: ";
            cin >> value;
            tree.insert(value);
        }
        else if (choice == 2)
        {
            cout << "Enter value to search: ";
            cin >> value;
            tree.Search(value);
        }
        else if (choice == 3)
        {
            cout << "Inorder: ";
            tree.inorder();
        }
        else if (choice == 4)
        {
            cout << "Preorder: ";
            tree.preorder();
        }
        else if (choice == 5)
        {
            cout << "Postorder: ";
            tree.postorder();
        }
        else if (choice == 6)
        {
            cout << "Enter value to delete: ";
            cin >> value;
            cout << "Delete functionality " << tree.deleteValue(value) << endl;
        }
        else if (choice == 7)
        {
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
        /* code */
    }

    return 0;
}
template <class T>
bool RedBlackTree<T>::deleteValue(T value)
{
    if (root == nullptr)
        return false;

    Node<T> *p = nullptr;
    Node<T> *c = root;

    // Find node
    while (c != nullptr && c->data != value)
    {
        p = c;

        if (value < c->data)
            c = c->left;
        else
            c = c->right;
    }

    if (c == nullptr)
        return false;

    // Case 2 children
    if (c->left != nullptr && c->right != nullptr)
    {
        Node<T> *successorParent = c;
        Node<T> *successor = c->right;

        while (successor->left != nullptr)
        {
            successorParent = successor;
            successor = successor->left;
        }

        c->data = successor->data;

        p = successorParent;
        c = successor;
    }

    // Case: leaf
    if (c->left == nullptr && c->right == nullptr)
    {
        if (p == nullptr)
        {
            delete c;
            root = nullptr;
            return true;
        }

        if (p->left == c)
            p->left = nullptr;
        else
            p->right = nullptr;

        delete c;
        return true;
    }

    // Case: one child (left)
    if (c->left != nullptr && c->right == nullptr)
    {
        if (p == nullptr)
            root = c->left;
        else if (p->left == c)
            p->left = c->left;
        else
            p->right = c->left;

        delete c;
        return true;
    }

    // Case: one child (right)
    if (c->right != nullptr && c->left == nullptr)
    {
        if (p == nullptr)
            root = c->right;
        else if (p->left == c)
            p->left = c->right;
        else
            p->right = c->right;

        delete c;
        return true;
    }

    return false;
}