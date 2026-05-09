#include "Node.h"
#include <iostream>
using namespace std;
class LinkedList
{
protected:
    Node *head;
    Node *tail;

public:
    LinkedList();
    virtual void insertAtHead(int) = 0;
    virtual void insertAtTail(int) = 0;
    virtual int deleteAtHead() = 0;
    virtual int deleteAtTail() = 0;
    virtual void display() = 0;
    virtual ~LinkedList();
};
LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}
LinkedList::~LinkedList()
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }
}