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
struct StackNode
{
    int data;
    StackNode *next;
    StackNode() : data(0), next(nullptr) {};
    StackNode(int data) : data(data), next(nullptr) {};
};
struct StackImpl
{
    StackNode *top;
    int size;
    StackImpl() : top(nullptr), size(0) {};

    void stackPush(int data)
    {
        StackNode *newNode = new StackNode(data);
        newNode->next = top;
        top = newNode;
        size += 1;
        cout << "Element pushed : " << data << endl;
    }
    int stackPop()
    {
        if (top == nullptr)
        {
            return -1;
        }
        int topData = top->data;
        StackNode *temp = top;
        top = top->next;
        delete temp;
        size -= 1;
        return topData;
    }
    int stackSize()
    {
        return size;
    }
    bool stackIsEmpty()
    {
        return top == nullptr;
    }
    int stackPeek()
    {
        if (top == NULL)
            return -1;
        return top->data;
    }
};
// int main()
// {
//     cout << string(30, '-') << endl;
//     StackImpl *stk = new StackImpl();
//     stk->stackPush(2);
//     stk->stackPush(4);
//     stk->stackPush(6);
//     stk->stackPush(8);
//     cout << stk->stackPop() << endl;
//     cout << stk->stackPop() << endl;
//     cout << stk->stackPeek() << endl;
//     cout << stk->stackPop() << endl;
//     cout << stk->stackPop() << endl;
//     cout << stk->stackIsEmpty() << endl;
//     cout << stk->stackSize() << endl;
//     cout << string(30, '-') << endl;
//     return 1;
// }
// ------------------------------------------------------------------------------ 155. Min Stack ---------------------------------------------------------------------------
class MinStack
{
public:
    // vector<pair<val, minElement>> s;
    vector<pair<int, int>> s;
    MinStack() {}
    void push(int val)
    {
        if (s.empty())
        {
            s.push_back({val, val});
        }
        else
        {
            s.push_back({val, min(s.back().second, val)});
        }
    }
    void pop()
    {
        s.pop_back();
    }
    int top()
    {
        return s.back().first;
    }
    int getMin()
    {
        return s.back().second;
    }
};
// int main()
// {
//     cout << string(30, '-') << endl;
//     cout << string(30, '-') << endl;
//     return 1;
// }
// --------------------------------------------------------------------------------- Infix to Postfix ------------------------------------------------------------------------------
// Function to return precedence of operators:
int precedence(char ch)
{
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return -1;
}
string infixToPostfix(string &s)
{
    stack<char> stk;
    string result;
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        // If the scanned character is an operand, add it to output string:
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
            result.push_back(ch);
        // If the scanned character is an ‘(‘, push it to the stack:
        else if (ch == '(')
            stk.push(ch);
        // If the scanned character is an ‘)’, pop and to output string from the stack until an ‘(‘ is encountered:
        else if (ch == ')')
        {
            while (!stk.empty() && stk.top() != '(')
            {
                result.push_back(stk.top());
                stk.pop();
            }
            stk.pop();
        }
        // If an operator is scanned:
        else
        {
            while (!stk.empty() && precedence(ch) <= precedence(stk.top()))
            {
                result.push_back(stk.top());
                stk.pop();
            }
            stk.push(ch);
        }
    }
    // Pop all the remaining elements from the stack:
    while (!stk.empty())
    {
        result.push_back(stk.top());
        stk.pop();
    }
    return result;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     string s = "a+b*(c^d-e)^(f+g*h)-i";
//     cout << infixToPostfix(s) << endl;
//     cout << string(30, '-') << endl;
//     return 1;
// }
// --------------------------------------------------------------------------------- Infix to Prefix ------------------------------------------------------------------------------
// Step 1: Reverse the given Infix string (Convert all the opening bracket to closing bracket and vice versa):
// Step 2: Infix to postfix conversion:
// Step 3: Reverse the result string:
// Function to return precedence of operators:
int precedenceForInfixToPrefix(char ch)
{
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return -1;
}
string infixToPrefix(string &s)
{
    // Reverse the Infix string:
    reverse(s.begin(), s.end());
    // Make all the closing bracket to opening and vice versa:
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }
    stack<char> stk;
    string result;
    // Infix to postfix conversion
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        // If the scanned character is an operand, add it to output string:
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
            result.push_back(ch);
        // If the scanned character is an ‘(‘, push it to the stack:
        else if (ch == '(')
            stk.push(ch);
        // If the scanned character is an ‘)’, pop and to output string from the stack until an ‘(‘ is encountered:
        else if (ch == ')')
        {
            while (!stk.empty() && stk.top() != '(')
            {
                result.push_back(stk.top());
                stk.pop();
            }
            stk.pop();
        }
        // If an operator is scanned:
        else
        {
            if (s[i] == '^')
            {
                while (!stk.empty() && precedenceForInfixToPrefix(ch) <= precedenceForInfixToPrefix(stk.top()))
                {
                    result.push_back(stk.top());
                    stk.pop();
                }
            }
            else
            {
                while (!stk.empty() && precedenceForInfixToPrefix(ch) < precedenceForInfixToPrefix(stk.top()))
                {
                    result.push_back(stk.top());
                    stk.pop();
                }
            }
            stk.push(ch);
        }
    }
    // Pop all the remaining elements from the stack:
    while (!stk.empty())
    {
        result.push_back(stk.top());
        stk.pop();
    }
    // Reverse the result string
    reverse(result.begin(), result.end());
    return result;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     string s = "(A+B)*C-D+F";
//     cout << infixToPrefix(s) << endl;
//     cout << string(30, '-') << endl;
//     return 1;
// }
// --------------------------------------------------------------------------------- Postfix to Infix ------------------------------------------------------------------------------
string postfixToInfix(string &s)
{
    stack<string> stk;
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            string str(1, s[i]);
            stk.push(str);
        }
        else
        {
            string secondOperand = stk.top();
            stk.pop();
            string firstOperand = stk.top();
            stk.pop();
            string temp = '(' + firstOperand + s[i] + secondOperand + ')';
            stk.push(temp);
        }
    }
    return stk.top();
}
int main()
{
    cout << string(30, '-') << endl;
    string s = "AB-DE+F*/";
    cout << postfixToInfix(s) << endl;
    cout << string(30, '-') << endl;
    return 1;
}