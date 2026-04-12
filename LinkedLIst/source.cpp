#include "LL.h"
int main()
{
    LL list;
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtTail(30);
    list.insertAtTail(40);
    list.display();

    cout << "Deleted at head: " << list.deleteAtHead() << endl;
    cout << "Deleted at tail: " << list.deleteAtTail() << endl;
    list.display();

    return 0;
}