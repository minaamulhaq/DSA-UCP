#include <iostream>

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

    bool isBlack(Node<T> *node)
    {
        return node == NULL || node->colour == 'B';
    }

    // 2 pointeer appprich to find the parent
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

    void rotateLeft(Node<T> *x)
    {
        Node<T> *y = x->left;

        Node<T> *z = getParent(root, x);
        if (z == nullptr)
        {
            return;
        }
        x->left = z;
        z->right = y;

        // chnage the colour of x and y and z
        char temp = x->colour;
        x->colour = z->colour;
        z->colour = temp;
        y->colour = temp;
    }

    void rotateRight(Node<T> *x)
    {
        Node<T> *y = x->right;
        Node<T> *z = getParent(root, x);
        if (z == nullptr)
        {
            return;
        }
        x->right = z;
        z->left = y;
        // chnage the colour of x and y and z
        char temp = x->colour;
        x->colour = z->colour;
        z->colour = temp;
        y->colour = temp;
    }

    void fixInsertion(Node<T> *node)
    {
        while (node != root && isRed(getParent(root, node)))
        {
            Node<T> *parent = getParent(root, node);
            Node<T> *grandparent = getGrandparent(node);
            Node<T> *uncle = getUncle(node);

            // Case 3: Parent and Uncle both are RED
            // Solution: Re-colour
            if (isRed(uncle))
            {
                parent->colour = 'B';
                uncle->colour = 'B';
                grandparent->colour = 'R';

                node = grandparent;
            }

            // Uncle is BLACK or NULL
            // rotation
            else
            {
                // Parent is left child of grandparent
                if (parent == grandparent->left)
                {
                    // Case 4: Left Right case
                    // First rotate parent left
                    // Node is on the right of the parent
                    if (node == parent->right)
                    {

                        grandparent->left = node;
                        parent->right = node->left;
                        node->left = parent;

                        rotateRight(node);
                    }
                    // Node is on the left of the parent
                    else
                    {
                        rotateRight(parent);
                        node = parent;
                    }

                    // // Case 5: Left Left case
                    // // Rotate grandparent right
                    // parent = getParent(root, node);
                    // grandparent = getGrandparent(node);

                    // parent->colour = 'B';
                    // grandparent->colour = 'R';

                    // rotateRight(grandparent);
                }

                // Parent is right child of grandparent
                else
                {
                    // Case 4: Right Left case
                    // First rotate parent right
                    if (node == parent->left)
                    {
                        grandparent->right = node;
                        parent->left = node->right;
                        node->right = parent;

                        rotateLeft(node);
                    }
                    // Node is on the right of the parent
                    else
                    {
                        rotateLeft(parent);
                        node = parent;
                    }

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

        // Case 1: Tree is empty, new node becomes root
        if (root == NULL)
        {
            newNode->colour = 'B';
            root = newNode;
            return;
        }

        Node<T> *current = root;
        Node<T> *parent = nullptr;

        while (current != nullptr)
        {
            parent = current;

            if (value < current->data)
            {
                current = current->left;
            }
            else if (value > current->data)
            {
                current = current->right;
            }
            else
            {
                // Duplicate value not inserted
                delete newNode;
                return;
            }
        }

        if (value < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;

        // Case 2: Parent is black, no fixing needed
        if (parent->colour == 'B')
            return;

        // Otherwise handle Case 3, Case 4, Case 5
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




};

int main()
{
    RedBlackTree<int> tree;

    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(8);
    tree.insert(9);

    cout << "Inorder: ";
    tree.inorder();


    return 0;
}