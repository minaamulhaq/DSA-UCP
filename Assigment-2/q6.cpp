
// Passengers arriving at airport security form one long single queue, Q. At the security checkpoint, four separate lanes/queues (q1, q2, q3, q4) must be created for security check. The lane for each passenger is decided by their passport number (assuming integer numbers) using these rules:
// •	If passport number is divisible by 4:	q4
// •	Else if passport number is divisible by 3:	q3
// •	Else if passport number is divisible by 2:	q2
// •	For All other cases: q1

// Write a code in main() function that distributes passengers in the Q into the four queues (q1, q2, q3, q4) based on the above conditions. You are not required to declare the queues; they’re already created inside the main function, you may start using them through Q, q1, q2, q3 and q4. Further, the following functions are available to you, please do not provide their implementations: enqueue, dequeue, peek, check if queue is empty, check if queue is full, create a copy of the queue.

// Example (showing 1 or 2-digit passport numbers for simplicity):
// Q: 	12, 9, 5, 8, 7, 6, 3, 10

// After running the code:
// Q: 	<empty>
// q1: 	5, 7
// q2: 	10
// q3: 	9, 6, 3
// q4: 	12, 8

#include <queue>
#include <iostream>
using namespace std;
#include <string>
void display(queue<int> q, const string &name)
{
    cout << name << ": ";
    if (q.empty())
    {
        cout << "<empty>";
    }
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    // These queues are available for use as required by the question.
    queue<int> Q, q1, q2, q3, q4;

    // Example input
    Q.push(12);
    Q.push(9);
    Q.push(5);
    Q.push(8);
    Q.push(7);
    Q.push(6);
    Q.push(3);
    Q.push(10);

    while (!Q.empty())
    {
        int passport = Q.front(); // peek
        Q.pop();                  // dequeue

        if (passport % 4 == 0)
        {
            q4.push(passport);
        }
        else if (passport % 3 == 0)
        {
            q3.push(passport);
        }
        else if (passport % 2 == 0)
        {
            q2.push(passport);
        }
        else
        {
            q1.push(passport);
        }
    }

    display(Q, "Q");
    display(q1, "q1");
    display(q2, "q2");
    display(q3, "q3");
    display(q4, "q4");

    return 0;
}
