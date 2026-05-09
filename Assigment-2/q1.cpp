// You are given a queue Q containing integers. You are only allowed to use queue operations (enqueue, dequeue, isEmpty, front, etc.) and possibly more than one queue object to reverse the contents of Q.

// Constraints:
// •	No use of stack or recursion.
// •	Only queue operations are allowed.

// Use additional queues if required.

// Input Example:
// Q = [1, 2, 3, 4, 5]
// Output:
// Q = [5, 4, 3, 2, 1]

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
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    int size = q.size();
    queue<int> q2;
    // queue<int> q3 = q;
    display(q);
    int i = 1;
    for (int x = 0; x < q.size(); x++)
    {
        while (q.size() - i)
        {
            q2.push(q.front());
            q.pop();
        }

        int v = q.front();
        // cout << v << endl;
        q.pop();
        q.push(v);

        while (!q.empty())
        {
            q2.push(q.front());
            q.pop();
        }
        while (!q2.empty())
        {
            q.push(q2.front());
            q2.pop();
        }
        i++;
    }
    display(q);
    return 0;
}