// A game show stores each participant’s lottery ticket number in a singly linked list, with each digit placed in a separate node. For example, the ticket number 1234 is represented as:  1 → 2 → 3 → 4

// The winners of the lottery are decided based on the following conditions:
// •	Rs. 2000: The ticket number forms a palindrome.
// •	Rs. 1000: The ticket number has exactly 4 digits and the sum of digits exceeds 20.
// •	Rs. 3000: The ticket number forms a palindrome, has exactly 4 digits and the sum of digits exceeds 20.

// Write a function that takes a singly linked list as an input parameter (representing the lottery ticket) and checks if the ticket qualifies for a prize or not. The function returns: 0, 1000, 2000 or 3000.
// int checkIfWon(ticketLinkedList)
// The linked list is already created in main(), ready for evaluation, you are only required to provide one function that takes this already created linked list as an input parameter. Further, the following functions are available to you, please do not provide their implementation: insert at head (first value), insert at tail (last value), delete from head, delete from tail, check if empty, create copy of linked list. Your function is to be created the source file (above main) and you do not have access to head or tail pointers since they are private.

// Examples:
// ticketLinkedList	Output
// 4 → 2 → 1 → 2 → 4	2000
// 5 → 6 → 5 → 7	1000
// 9 → 1 → 1 → 9 		3000
// 2 → 1 → 1 → 7 → 1 → 8  	0

#include "LL.h"
int checkIfWon(LL &ticketLinkedList)
{
    // Create safe copies
    LL temp = ticketLinkedList;
    LL reversed = ticketLinkedList;

    int sum = 0;
    int count = 0;

    // Step 1: reverse + compute sum & count using temp
    while (!temp.isEmpty())
    {
        int digit = temp.deleteAtHead();
        reversed.insertAtHead(digit);

        sum += digit;
        count++;
    }

    // Step 2: check palindrome
    LL a = ticketLinkedList;
    LL b = reversed;

    bool isPalindrome = true;

    while (!a.isEmpty())
    {
        if (a.deleteAtHead() != b.deleteAtHead())
        {
            isPalindrome = false;
            break;
        }
    }

    bool hasFourDigitsAndSumExceeds20 = (count == 4 && sum > 20);

    if (isPalindrome && hasFourDigitsAndSumExceeds20)
        return 3000;
    else if (isPalindrome)
        return 2000;
    else if (hasFourDigitsAndSumExceeds20)
        return 1000;
    else
        return 0;
}

int main()
{
    LL ticket1;
    ticket1.insertAtTail(4);
    ticket1.insertAtTail(2);
    ticket1.insertAtTail(1);
    ticket1.insertAtTail(2);
    ticket1.insertAtTail(4);
    cout << "Ticket 1 Prize: " << checkIfWon(ticket1) << endl; // Expected output: 2000

    LL ticket2;
    ticket2.insertAtTail(5);
    ticket2.insertAtTail(6);
    ticket2.insertAtTail(5);
    ticket2.insertAtTail(7);
    cout << "Ticket 2 Prize: " << checkIfWon(ticket2) << endl; // Expected output: 1000

    LL ticket3;
    ticket3.insertAtTail(9);
    ticket3.insertAtTail(1);
    ticket3.insertAtTail(1);
    ticket3.insertAtTail(9);
    cout << "Ticket 3 Prize: " << checkIfWon(ticket3) << endl; // Expected output: 3000

    LL ticket4;
    ticket4.insertAtTail(2);
    ticket4.insertAtTail(1);
    ticket4.insertAtTail(1);
    ticket4.insertAtTail(7);
    ticket4.insertAtTail(1);
    ticket4.insertAtTail(8);
    cout << "Ticket 4 Prize: " << checkIfWon(ticket4) << endl; // Expected output: 0

    return 0;
}