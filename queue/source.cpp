#include "myqueue.h"
int main()
{
    myqueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();

    cout << "Top element: " << q.top() << endl;

    q.dequeue();
    q.dequeue();
    q.display();

    cout << "Top element: " << q.top() << endl;

    q.enqueue(60); // This should show that the queue is full
    return 0;
}