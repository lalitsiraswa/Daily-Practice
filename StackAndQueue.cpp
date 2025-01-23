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
// int main()
// {
//     cout << string(30, '-') << endl;
//     string s = "()[]{{}";
//     cout << isValid(s) << endl;
//     cout << string(30, '-') << endl;
//     return 1;
// }
// ------------------------------------------------------------------------------ Queue Using Array ---------------------------------------------------------------------------
class Queue
{
    int *arr;
    int start, end, currSize, maxSize;

public:
    Queue() : arr(new int[16]), start(-1), end(-1), currSize(0), maxSize(16) {};
    Queue(int maxSize) : maxSize(maxSize), arr(new int[maxSize]), start(-1), end(-1), currSize(0) {};
    void push(int newElement)
    {
        if (currSize == maxSize)
        {
            cout << "Queue is full\nExiting..." << endl;
            exit(1);
        }
        if (end == -1)
        {
            start = 0;
            end = 0;
        }
        else
        {
            end = (end + 1) % maxSize;
        }
        arr[end] = newElement;
        cout << "The element pushed is " << newElement << endl;
        currSize++;
    }
    int pop()
    {
        if (start == -1)
        {
            cout << "Queue Empty\nExiting..." << endl;
            exit(1);
        }
        int popped = arr[start];
        if (currSize == 1)
        {
            start = -1;
            end = -1;
        }
        else
        {
            start = (start + 1) % maxSize;
        }
        currSize -= 1;
        return popped;
    }
    int top()
    {
        if (start == -1)
        {
            cout << "Queue is Empty" << endl;
            exit(1);
        }
        return arr[start];
    }
    int size()
    {
        return currSize;
    }
};
// int main()
// {
//     cout << string(30, '-') << endl;
//     Queue q;
//     q.push(2);
//     q.push(4);
//     q.push(6);
//     cout << q.pop() << endl;
//     cout << q.pop() << endl;
//     cout << q.pop() << endl;
//     cout << q.pop() << endl;
//     cout << string(30, '-') << endl;
//     return 1;
// }
// ------------------------------------------------------------------------------ Stack using Linked List ---------------------------------------------------------------------------
int main()
{
    cout << string(30, '-') << endl;
    cout << string(30, '-') << endl;
    return 1;
}