// Given an unsorted singly linked list, sort it using any sorting algorithm of your choice (e.g., bubble sort, selection sort, merge sort, etc.).

// Constraints:
// •	You cannot use insertSorted or any built-in sorting.
// •	You may define helper functions.

// Input Example:
// List = 5 → 1 → 4 → 2 → 3
// Output:
// List = 1 → 2 → 3 → 4 → 5

#include "LL.h"
int main()
{
    LL list;
    list.insertAtTail(5);
    list.insertAtTail(1);
    list.insertAtTail(4);
    list.insertAtTail(2);
    list.insertAtTail(3);
    cout << "Before sorting: ";
    list.display();
    list.sort();
    cout << "After sorting: ";
    list.display();
    return 0;
}