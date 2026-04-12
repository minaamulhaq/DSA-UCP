#include "queue.h"
class circularQueue : public queue<int>
{
    int front;
    int rare;

public:
    circularQueue(int s) : queue(s), front(0), rare(0) {}
    void enqueue(int);
    void dequeue();
    int top();
    bool isEmpty();
    bool isFull();
    void display();
};
void circularQueue::enqueue(int x)
{
    if (isFull())
    {
        cout << "Queue is full. Cannot enqueue " << x << endl;
        return;
    }
    arr[rare] = x;
    rare = (rare + 1) % maxSize;
    currentSize++;
}
void circularQueue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return;
    }
    front = (front + 1) % maxSize;
    currentSize--;
}
int circularQueue::top()
{
    if (isEmpty())
    {
        cout << "Queue is empty. No top element." << endl;
        return -1; // or throw an exception
    }
    return arr[front];
}
bool circularQueue::isEmpty()
{
    return currentSize == 0;
}
bool circularQueue::isFull()
{
    return currentSize == maxSize;
}
void circularQueue::display()
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue elements: ";
    for (int i = 0; i < currentSize; i++)
    {
        cout << arr[(front + i) % maxSize] << " ";
    }
    cout << endl;
}