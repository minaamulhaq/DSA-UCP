// Given a queue of integers, remove all duplicate values while preserving the order of first occurrences.

// Constraints:
// •	Use only queue operations and basic data structures.
// •	Avoid using inbuilt functions for duplicate removal.

// Input Example:
// Q = [3, 1, 4, 3, 4, 2, 1]
// Output:
// Q = [3, 1, 4, 2]

#include <queue>
#include <iostream>
using namespace std;
void display(queue<int> l)
{
    cout << "Queue :";

    while (!l.empty())
    {
        cout << l.front() << " ";
        l.pop();
    }
    cout << endl;
}
int main()
{
    queue<int> q;
    q.push(3);
    q.push(1);
    q.push(4);
    q.push(3);
    q.push(4);
    q.push(2);
    q.push(1);
    display(q);
    queue<int> q2;

    for (int i = 0; i < q.size(); i++)
    {
        int v = q.front();
        q.pop();

        while (!q.empty())
        {
            if (q.front() == v)
            {
                q.pop();
            }
            else
            {
                q2.push(q.front());
                q.pop();
            }
        }

        while (!q2.empty())
        {
            q.push(q2.front());
            q2.pop();
        }
        q.push(v);
    }

    display(q);
    return 0;
}