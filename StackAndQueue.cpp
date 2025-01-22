#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------------------------ 225. Implement Stack using Queues ---------------------------------------------------------------------------
class MyStack
{
    queue<int> mainQueue;
    queue<int> helperQueue;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        mainQueue.push(x);
    }

    int pop()
    {
        while (mainQueue.size() > 1)
        {
            helperQueue.push(mainQueue.front());
            mainQueue.pop();
        }
        int val = mainQueue.front();
        mainQueue.pop();
        while (!helperQueue.empty())
        {
            mainQueue.push(helperQueue.front());
            helperQueue.pop();
        }
        return val;
    }

    int top()
    {
        return mainQueue.back();
    }

    bool empty()
    {
        return mainQueue.empty();
    }
};
// int main()
// {
//     cout << string(30, '-') << endl;
//     MyStack stk;
//     stk.push(1);
//     stk.push(2);
//     cout << stk.top() << endl;
//     cout << stk.pop() << endl;
//     cout << string(30, '-') << endl;
//     return 1;
// }
// ------------------------------------------------------------------------------ 225. Implement Stack using Queues ---------------------------------------------------------------------------
bool isValid(string s)
{
    stack<char> bracketStack;
    for (char bracket : s)
    {
        if (bracket == '(' || bracket == '{' || bracket == '[')
            bracketStack.push(bracket);
        else if (bracketStack.empty())
            return false;
        else if (bracket == ')' && bracketStack.top() == '(')
            bracketStack.pop();
        else if (bracket == '}' && bracketStack.top() == '{')
            bracketStack.pop();
        else if (bracket == ']' && bracketStack.top() == '[')
            bracketStack.pop();
        else
            return false;
    }
    return bracketStack.empty();
}
int main()
{
    cout << string(30, '-') << endl;
    string s = "()[]{{}";
    cout << isValid(s) << endl;
    cout << string(30, '-') << endl;
    return 1;
}