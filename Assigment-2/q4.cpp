// In a programming system, prefix expressions (operators first, operands second) are evaluated using a stack. In the system, the values (both operators and operands) are already placed in a queue, from left to right, following prefix order. Each element is either:
// •	A positive integer operand (multi-digit allowed)
// •	A negative integer operator according to the following mapping (only -1, -2, -3 allowed):
// o	-1 represents PLUS (+)
// o	-2 represents MULTIPLY (*)
// o	-3 represents DIVIDE (/) and it works as integer division (quotient only)

// You are required to read the elements from the queue one-by-one and use a stack to perform the expression evaluation in main(). At the end, the stack must contain exactly one value, which is the result of the prefix expression. Further, the following functions are available to you, please do not provide their codes: enqueue, dequeue, peek, check if queue is empty, check if queue is full, create a copy of the queue, push, pop, top, check if stack is empty, check if stack is full, create a copy of the stack. Use these functions to implement the solution in the main() function.

// Example 1:
// Queue contents: 	-3, -2, 7, 3, 2
// Result stored in stack:    10

// Evaluation steps (not to be displayed, these are for explanation and clarification only)
// Step 0: Queue: -3, -2, 7, 3, 2	Stack: []
// Step 1: Queue: -2, 7, 3, 2  	Stack: [-3]
// Step 2: Queue: 7, 3, 2  		Stack: [-3, -2]
// Step 3: Queue: 3, 2  		Stack: [-3, -2, 7]
// Step 4: Queue: 2  		Stack: [-3, -2, 7, 3]
// Step 5: Queue: 2  		Stack: [-3, 21]  		// Evaluated: 7 * 3 = 21
// Step 6: Queue: []  		Stack: [-3, 21, 2]
// Step 7: Queue: []  		Stack: [10]  		// Evaluated: 21 / 2 = 10
// /Hint: When top stack values are operand, operand, operator → pop them and evaluate

// Example 2:
// Queue contents:	 -1, 5, -2, 2, 3
// Result stored in stack: 	  11

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool isOperator(int x)
{
    return x == -1 || x == -2 || x == -3;
}

void reduceTopIfPossible(stack<int> &st)
{
    while (st.size() >= 3)
    {
        int first = st.top();
        st.pop();
        int second = st.top();
        st.pop();
        int op = st.top();
        st.pop();

        // Pattern required by the hint: operand, operand, operator
        if (first > 0 && second > 0 && isOperator(op))
        {
            int result = 0;
            if (op == -1)
            {
                result = second + first;
            }
            else if (op == -2)
            {
                result = second * first;
            }
            else
            {
                result = second / first; // integer division
            }
            st.push(result);
        }
        else
        {
            // Restore original order if reduction is not possible.
            st.push(op);
            st.push(second);
            st.push(first);
            break;
        }
    }
}

void evaluatePrefixQueue(queue<int> &q, stack<int> &st)
{
    while (!q.empty())
    {
        int token = q.front(); // peek
        q.pop();               // dequeue
        st.push(token);
        reduceTopIfPossible(st);
    }
}

int main()
{
    queue<int> q;
    stack<int> st;

    // Example 1: expected result = 10
    q.push(-3);
    q.push(-2);
    q.push(7);
    q.push(3);
    q.push(2);

    evaluatePrefixQueue(q, st);

    if (st.size() == 1)
    {
        cout << "Result: " << st.top() << endl;
    }
    else
    {
        cout << "Invalid expression" << endl;
    }

    // Example 2: expected result = 11
    while (!st.empty())
    {
        st.pop();
    }

    q.push(-1);
    q.push(5);
    q.push(-2);
    q.push(2);
    q.push(3);

    evaluatePrefixQueue(q, st);

    if (st.size() == 1)
    {
        cout << "Result: " << st.top() << endl;
    }
    else
    {
        cout << "Invalid expression" << endl;
    }

    return 0;
}
