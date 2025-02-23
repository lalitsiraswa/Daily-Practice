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
// int main()
// {
//     cout << string(30, '-') << endl;
//     string s = "AB-DE+F*/";
//     cout << postfixToInfix(s) << endl;
//     cout << string(30, '-') << endl;
//     return 1;
// }
// --------------------------------------------------------------------------------- Prefix to Infix ------------------------------------------------------------------------------
string preToInfix(string &s)
{
    // Convert prefix to postfix (reverse):
    reverse(s.begin(), s.end());
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
    string result = stk.top();
    reverse(result.begin(), result.end());
    // Replace '(' with ')' and vice versa:
    for (int i = 0; i < result.size(); i++)
    {
        if (result[i] == '(')
            result[i] = ')';
        else if (result[i] == ')')
            result[i] = '(';
    }
    return result;
}
// -------- TUF --------
string preToInfixTuf(string &s)
{
    stack<string> stk;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            string str(1, s[i]);
            stk.push(str);
        }
        else
        {
            string firstOperand = stk.top();
            stk.pop();
            string secondOperand = stk.top();
            stk.pop();
            string temp = '(' + firstOperand + s[i] + secondOperand + ')';
            stk.push(temp);
        }
    }
    return stk.top();
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     string s = "*-A/BC-/AKL";
//     cout << preToInfixTuf(s) << endl;
//     cout << string(30, '-') << endl;
//     return 1;
// }
// ------------------------------------------------------------------------ Postfix to Prefix Conversion ------------------------------------------------------------------------------
string postToPre(string &s)
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
            string temp = s[i] + firstOperand + secondOperand;
            stk.push(temp);
        }
    }
    return stk.top();
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     string s = "ABC/-AK/L-*";
//     cout << postToPre(s) << endl;
//     cout << string(30, '-') << endl;
//     return 1;
// }
// ------------------------------------------------------------------------ Prefix to Postfix Conversion ------------------------------------------------------------------------------
string preToPost(string &s)
{
    stack<string> stk;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            string str(1, s[i]);
            stk.push(str);
        }
        else
        {
            string firstOperand = stk.top();
            stk.pop();
            string secondOperand = stk.top();
            stk.pop();
            string temp = firstOperand + secondOperand + s[i];
            stk.push(temp);
        }
    }
    return stk.top();
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     string s = "*-A/BC-/AKL";
//     cout << preToPost(s) << endl;
//     cout << string(30, '-') << endl;
//     return 1;
// }
// ------------------------------------------------------------------------ 496. Next Greater Element I ------------------------------------------------------------------------------
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        bool isGreaterFound = false;
        bool isElementFound = false;
        for (int j = 0; j < m; j++)
        {
            if (nums1[i] == nums2[j])
            {
                isElementFound = true;
            }
            if (isElementFound && nums2[j] > nums1[i])
            {
                result.push_back(nums2[j]);
                isGreaterFound = true;
                break;
            }
        }
        if (!isGreaterFound)
        {
            result.push_back(-1);
        }
    }
    return result;
}
// ---------------------
// Monotonic Stack : Storing elements in a specific order:
vector<int> nextGreaterElementTuf(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    unordered_map<int, int> mapGreater;
    // We are storing the elements in the decreasing order:
    stack<int> monotonicStack;
    for (int i = m - 1; i >= 0; i--)
    {
        // Check if the stack holds any values and compare them with array value:
        while (!monotonicStack.empty() && monotonicStack.top() <= nums2[i])
        {
            // If the values in the stack are less than or equal to the array value remove them:
            monotonicStack.pop();
        }
        // If the stack is not empty, set the top element of the stack has the next greater element:
        if (!monotonicStack.empty())
        {
            mapGreater[nums2[i]] = monotonicStack.top();
        }
        else
        {
            mapGreater[nums2[i]] = -1;
        }
        monotonicStack.push(nums2[i]);
    }
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        result.push_back(mapGreater[nums1[i]]);
    }
    return result;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums1 = {1, 3, 5, 2, 4};
//     vector<int> nums2 = {6, 5, 4, 3, 2, 1, 7};
//     vector<int> result = nextGreaterElementTuf(nums1, nums2);
//     for (auto item : result)
//     {
//         cout << item << ", ";
//     }
//     cout << endl
//          << string(30, '-') << endl;
//     return 1;
// }
// ------------------------------------------------------------------------ 503. Next Greater Element II ------------------------------------------------------------------------------
vector<int> nextGreaterElementsBruteForce(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n, -1);
    for (int i = 0; i < n; i++)
    {
        bool isGreaterFound = false;
        // Check on the right hand side of the element for greater value:
        for (int j = i + 1; j < n && !isGreaterFound; j++)
        {
            if (nums[j] > nums[i])
            {
                result[i] = nums[j];
                isGreaterFound = true;
            }
        }
        // Check on the left hand side of the element for greater value:
        for (int j = 0; j < i && !isGreaterFound; j++)
        {
            if (nums[j] > nums[i])
            {
                result[i] = nums[j];
                isGreaterFound = true;
            }
        }
    }
    return result;
}
// ----------------------------
// Hypothetically double the array
// Original arrays : {2, 10, 12, 1, 11}:
// Immaginare arrays : {2, 10, 12, 1, 11, 2, 10, 12, 1, 11}:
vector<int> nextGreaterElementsBruteForce2(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= (i + n - 1); j++)
        {
            int index = j % n;
            if (nums[index] > nums[i])
            {
                result[i] = nums[index];
                break;
            }
        }
    }
    return result;
}
// ----------------------------
// Hypothetically double the array
// Original arrays : {2, 10, 12, 1, 11}:
// Immaginare arrays : {2, 10, 12, 1, 11, 2, 10, 12, 1, 11}:
vector<int> nextGreaterElementsUsingMonotonicStack(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n);
    stack<int> monotonicStack;
    for (int i = (n * 2) - 1; i >= 0; i--)
    {
        int index = i % n;
        while (!monotonicStack.empty() && monotonicStack.top() <= nums[index])
        {
            monotonicStack.pop();
        }
        if (monotonicStack.empty())
        {
            result[index] = -1;
        }
        else
        {
            result[index] = monotonicStack.top();
        }
        monotonicStack.push(nums[index]);
    }
    return result;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {2, 10, 12, 1, 11};
//     vector<int> result = nextGreaterElementsBruteForce(nums);
//     for (auto item : result)
//     {
//         cout << item << ", ";
//     }
//     cout << endl
//          << string(30, '-') << endl;
//     return 1;
// }
// ------------------------------------------------------------------------ Nearest Smaller Element ------------------------------------------------------------------------------
// https://www.interviewbit.com/problems/nearest-smaller-element/
vector<int> immediateSmaller(vector<int> &nums)
{
    int n = nums.size();
    stack<int> monotonicStack;
    vector<int> result(n, -1);
    for (int i = 0; i < n; i++)
    {
        while (!monotonicStack.empty() && monotonicStack.top() >= nums[i])
        {
            monotonicStack.pop();
        }
        if (!monotonicStack.empty())
        {
            result[i] = monotonicStack.top();
        }
        monotonicStack.push(nums[i]);
    }
    return result;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {4, 5, 2, 10, 8};
//     vector<int> result = immediateSmaller(nums);
//     for (auto item : result)
//     {
//         cout << item << ", ";
//     }
//     cout << endl
//          << string(30, '-') << endl;
//     return 1;
// }
// ------------------------------------------------------------------------ 42. Trapping Rain Water ------------------------------------------------------------------------------
int trapByPrefixAndPostfix(vector<int> &height)
{
    int n = height.size();
    int waterTrapped = 0;
    int prefix[n], suffix[n];
    prefix[0] = height[0];
    for (int index = 1; index < n; index++)
    {
        prefix[index] = max(prefix[index - 1], height[index]);
    }
    suffix[n - 1] = height[n - 1];
    for (int index = n - 2; index >= 0; index--)
    {
        suffix[index] = max(suffix[index + 1], height[index]);
    }
    for (int index = 0; index < n; index++)
    {
        waterTrapped += min(prefix[index], suffix[index]) - height[index];
    }
    return waterTrapped;
}
// --------------------------
int trap(vector<int> &height)
{
    int n = height.size();
    int left = 0, right = n - 1;
    int leftMax = height[left];
    int rightMax = height[right];
    int totalWaterTrap = 0;
    while (left < right)
    {
        int waterCanFillBetween = 0;
        if (height[left] <= height[right])
        {
            leftMax = max(leftMax, height[left]);
            waterCanFillBetween = leftMax - height[left];
            left += 1;
        }
        else
        {
            rightMax = max(rightMax, height[right]);
            waterCanFillBetween = rightMax - height[right];
            right -= 1;
        }
        totalWaterTrap += waterCanFillBetween;
    }
    return totalWaterTrap;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
//     cout << trap(nums) << endl;
//     cout << endl
//          << string(30, '-') << endl;
//     return 1;
// }
// ------------------------------------------------------------------------ Number of greater elements to the right ------------------------------------------------------------------------------
vector<int> count_NGE_BruteForce(int n, vector<int> &arr, int queries, vector<int> &indices)
{
    vector<int> result;
    for (int i = 0; i < indices.size(); i++)
    {
        int index = indices[i];
        int countGreaterElements = 0;
        for (int j = index + 1; j < n; j++)
        {
            if (arr[j] > arr[index])
            {
                countGreaterElements += 1;
            }
        }
        result.push_back(countGreaterElements);
    }
    return result;
}
// ------------------
vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices)
{
    vector<int> result;
    stack<int> monotonicStackDescending;
    stack<int> monotonicStackAscending;
    unordered_map<int, int> indexToGreaterMap;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!monotonicStackDescending.empty() && monotonicStackDescending.top() <= arr[i])
        {
            monotonicStackAscending.push(monotonicStackDescending.top());
            monotonicStackDescending.pop();
        }
        indexToGreaterMap[i] = monotonicStackDescending.size();
        monotonicStackDescending.push(arr[i]);
        while (!monotonicStackAscending.empty())
        {
            monotonicStackDescending.push(monotonicStackAscending.top());
            monotonicStackAscending.pop();
        }
    }
    for (int i = 0; i < indices.size(); i++)
    {
        int index = indices[i];
        result.push_back(indexToGreaterMap[index]);
    }
    return result;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> arr = {3, 4, 2, 7, 5, 8, 10, 6};
//     vector<int> indices = {0, 5};
//     vector<int> result = count_NGE(arr.size(), arr, 2, indices);
//     for (int val : result)
//     {
//         cout << val << ", ";
//     }
//     cout << endl
//          << string(30, '-') << endl;
//     return 1;
// }
// ------------------------------------------------------------------------ 907. Sum of Subarray Minimums ------------------------------------------------------------------------------
// -------------- TLE ----------------
int sumSubarrayMins(vector<int> &arr)
{
    int MOD = (int)(1e9 + 7);
    long long int totalMinElementSum = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        long long int minElement = INT_MAX;
        for (int j = i; j < n; j++)
        {
            if (minElement > arr[j])
            {
                minElement = arr[j];
            }
            totalMinElementSum += minElement;
        }
    }
    return totalMinElementSum % MOD;
}
// ----------------- TUF ------------------
vector<int> findNSE(vector<int> &arr, int &n)
{
    vector<int> nse(n);
    stack<int> monotonicStack;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!monotonicStack.empty() && arr[monotonicStack.top()] >= arr[i])
        {
            monotonicStack.pop();
        }
        nse[i] = monotonicStack.empty() ? n : monotonicStack.top();
        monotonicStack.push(i);
    }
    return nse;
}
vector<int> findPSE(vector<int> &arr, int &n)
{
    vector<int> pse(n);
    stack<int> monotonicStack;
    for (int i = 0; i < n; i++)
    {
        while (!monotonicStack.empty() && arr[monotonicStack.top()] > arr[i])
        {
            monotonicStack.pop();
        }
        pse[i] = monotonicStack.empty() ? -1 : monotonicStack.top();
        monotonicStack.push(i);
    }
    return pse;
}
int sumSubarrayMinsTuf(vector<int> &arr)
{
    int n = arr.size();
    int MOD = (int)(1e9 + 7);
    int totalMinElementSum = 0;
    vector<int> nse = findNSE(arr, n);
    vector<int> pse = findPSE(arr, n);
    for (int i = 0; i < n; i++)
    {
        int left = i - pse[i];
        int right = nse[i] - i;
        totalMinElementSum = (totalMinElementSum + (right * left * 1ll * arr[i]) % MOD) % MOD;
    }
    return totalMinElementSum;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> arr = {3, 1, 2, 4};
//     cout << sumSubarrayMinsTuf(arr);
//     cout << endl
//          << string(30, '-') << endl;
//     return 1;
// }
// --------------------------------------------------------------------------------- 146. LRU Cache ---------------------------------------------------------------------------------------
class DLinkedNode
{
public:
    int key, value;
    DLinkedNode *previous;
    DLinkedNode *next;
    DLinkedNode() : key(0), value(0), previous(nullptr), next(nullptr) {};
    DLinkedNode(int key, int value) : key(key), value(value), previous(nullptr), next(nullptr) {};
};
class LRUCache
{
public:
    DLinkedNode *head, *tail, *helper;
    unordered_map<int, DLinkedNode *> container;
    int capacity;
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->previous = head;
    }

    int get(int key)
    {
        if (container.count(key))
        {
            helper = container.at(key);
            helper->previous->next = helper->next;
            helper->next->previous = helper->previous;
            DLinkedNode *temp = head->next;
            head->next = helper;
            helper->previous = head;
            helper->next = temp;
            temp->previous = helper;
            return helper->value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (!container.count(key))
        {
            if (container.size() == capacity)
            {
                DLinkedNode *temp = tail->previous;
                helper = temp->previous;
                helper->next = tail;
                tail->previous = helper;
                container.erase(temp->key);
                delete temp;
            }
            DLinkedNode *newNode = new DLinkedNode(key, value);
            helper = head->next;
            head->next = newNode;
            newNode->previous = head;
            newNode->next = helper;
            helper->previous = newNode;
            container.insert(pair<int, DLinkedNode *>(key, newNode));
        }
        else
        {
            helper = container.at(key);
            helper->value = value;
            helper->previous->next = helper->next;
            helper->next->previous = helper->previous;
            DLinkedNode *temp = head->next;
            head->next = helper;
            helper->previous = head;
            helper->next = temp;
            temp->previous = helper;
        }
    }
};
int main()
{
    cout << string(30, '-') << endl;
    vector<int> arr = {3, 1, 2, 4};
    cout << sumSubarrayMinsTuf(arr);
    cout << endl
         << string(30, '-') << endl;
    return 1;
}