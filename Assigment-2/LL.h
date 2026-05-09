#include "LinkedList.h"

class LL : public LinkedList
{

public:
    LL(/* args */);
    ~LL();
    LL(const LL &other) : LinkedList()
    {
        Node *current = other.head;
        while (current != nullptr)
        {
            insertAtTail(current->data);
            current = current->next;
        }
    }
    void insertAtHead(int) override;
    void insertAtTail(int) override;
    int deleteAtHead() override;
    int deleteAtTail() override;
    void display() override;
    bool isEmpty();
    void sort();
};

bool LL::isEmpty()
{
    return head == nullptr && tail == nullptr;
}

LL::LL(/* args */) : LinkedList()
{
}

LL::~LL()
{
}
void LL::insertAtHead(int x)
{
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = nullptr;

    // case 1: if the list is empty
    if (head == nullptr && tail == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else if (head == tail)
    { // case 2: if the list has only one node
        newNode->next = head;
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}
void LL::insertAtTail(int x)
{
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = nullptr;

    // case 1: if the list is empty
    if (head == nullptr && tail == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else if (head == tail)
    { // case 2: if the list has only one node
        head->next = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}
int LL::deleteAtHead()
{
    if (head == nullptr && tail == nullptr)
    {
        cout << "List is empty. Cannot delete at head." << endl;
        return -1;
    }
    else if (head == tail)
    { // case 2: if the list has only one node
        int data = head->data;
        delete head;
        head = nullptr;
        tail = nullptr;
        return data;
    }
    else
    {
        Node *temp = head;
        int data = head->data;
        head = head->next;
        delete temp;
        temp = nullptr;
        return data;
    }
}

int LL::deleteAtTail()
{
    if (head == nullptr && tail == nullptr)
    {
        cout << "List is empty. Cannot delete at tail." << endl;
        return -1;
    }
    else if (head == tail)
    { // case 2: if the list has only one node
        int data = tail->data;
        delete tail;
        head = nullptr;
        tail = nullptr;
        return data;
    }
    else
    {
        Node *current = head;
        while (current->next != tail)
        {
            current = current->next;
        }
        int data = tail->data;
        delete tail;
        tail = current;
        tail->next = nullptr;
        return data;
    }
}
void LL::display()
{
    if (head == nullptr && tail == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
    Node *current = head;
    cout << "Linked List: ";
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void LL::sort()
{
    if (head == nullptr || head->next == nullptr)
    {
        return; // List is empty or has only one node, already sorted
    }

    Node *current = head;
    while (current != nullptr)
    {
        Node *index = current->next;
        while (index != nullptr)
        {
            if (current->data > index->data)
            {
                // Swap data
                int temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}