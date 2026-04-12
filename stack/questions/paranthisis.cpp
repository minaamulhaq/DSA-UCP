#include <iostream>
// for this i am using stack STL libray to insure my stack and the stl stack is same
#include <stack>
using namespace std;

int longestValidParentheses(string s)
{
    stack<int> st;
    st.push(-1); // base index

    int maxLen = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            st.pop();

            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                int len = i - st.top();
                maxLen = max(maxLen, len);
            }
        }
    }

    return maxLen;
}

int main()
{
    cout << longestValidParentheses("(()") << endl;   // 2
    cout << longestValidParentheses("()(()") << endl; // 2
}