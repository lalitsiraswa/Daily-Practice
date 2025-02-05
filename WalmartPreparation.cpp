#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data) : data(data), left(nullptr), right(nullptr) {};
};

struct ListNode
{
    int data;
    ListNode *next;
    ListNode(int data) : data(data), next(nullptr) {};
};

// https://www.geeksforgeeks.org/explore?page=1&company=Walmart&sortBy=submissions&itm_source=geeksforgeeks&itm_medium=main_header&itm_campaign=practice_header
// ------------------------------------------------------------------------ Kadane's Algorithm ------------------------------------------------------------------------------
int maxSubarraySum(vector<int> &arr)
{
    int maxSum = arr[0];
    int currentSum = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        currentSum = max(currentSum + arr[i], arr[i]);
        maxSum = max(currentSum, maxSum);
    }
    return maxSum;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
//     cout << maxSubarraySum(arr) << endl;
//     cout << endl
//          << string(30, '-') << endl;
//     return 1;
// }
// ------------------------------------------------------------------------ Minimum Jumps ------------------------------------------------------------------------------
// --------------- TLE -------------------
int minJumps(vector<int> &arr, int index, vector<int> &dp)
{
    if (index >= arr.size() - 1)
    {
        return 0;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }
    int minJumpsCount = INT_MAX;
    int currJumpCount = 0;
    for (int i = 1; i <= arr[index]; i++)
    {

        currJumpCount = 1 + minJumps(arr, index + i, dp);
        if (currJumpCount > 0)
            minJumpsCount = min(minJumpsCount, currJumpCount);
    }
    return dp[index] = (minJumpsCount == INT_MAX) ? -2 : minJumpsCount;
}
int minJumps(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, -1);
    minJumps(arr, 0, dp);
    return dp[0] == -2 ? -1 : dp[0];
}
// --------------- TLE ----------------
int minJumpsTabulation(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, -1);
    dp[n - 1] = 0;
    for (int index = n - 2; index >= 0; index--)
    {
        int minJumpsCount = INT_MAX;
        int currJumpCount = 0;
        for (int i = 1; i <= arr[index] && i < n; i++)
        {

            currJumpCount = 1 + dp[index + i];
            if (currJumpCount > 0)
                minJumpsCount = min(minJumpsCount, currJumpCount);
        }
        dp[index] = (minJumpsCount == INT_MAX) ? -2 : minJumpsCount;
    }
    return dp[0] == -2 ? -1 : dp[0];
}
// --------------- GREEDY ALGORITMS  ----------------
int minJumpsGreedy(vector<int> &arr)
{
    int n = arr.size();
    int minJumps = 0;
    int currentEnd = 0;
    int currentFarthest = 0;
    for (int index = 0; index < arr.size() - 1; index++)
    {
        currentFarthest = max(currentFarthest, index + arr[index]);
        if (index == currentEnd)
        {
            minJumps += 1;
            currentEnd = currentFarthest;
        }
        if (currentEnd >= n - 1)
        {
            break;
        }
    }
    if (currentEnd < n - 1)
    {
        return -1;
    }
    return minJumps;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> arr = {2, 3, 1, 1, 4};
//     cout << minJumpsGreedy(arr) << endl;
//     cout << endl
//          << string(30, '-') << endl;
//     return 1;
// }
// ------------------------------------------------------------------------ Sort 0s, 1s and 2s ------------------------------------------------------------------------------
void sort012(vector<int> &arr)
{
    int n = arr.size();
    int left = 0, right = n - 1;
    int middle = 0;
    while (middle <= right && left <= right)
    {
        if (arr[middle] == 0)
        {
            swap(arr[left], arr[middle]);
            left += 1;
            middle += 1;
        }
        else if (arr[middle] == 2)
        {
            swap(arr[middle], arr[right]);
            right -= 1;
        }
        else
        {
            middle += 1;
        }
    }
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> arr = {2, 0, 2};
//     sort012(arr);
//     for (int val : arr)
//     {
//         cout << val << ", ";
//     }
//     cout << endl
//          << string(30, '-') << endl;
//     return 1;
// }
// ------------------------------------------------------------------------ Parenthesis Checker ------------------------------------------------------------------------------
bool isParenthesisBalanced(string &s)
{
    int n = s.size();
    stack<char> stk;
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            stk.push(s[i]);
            continue;
        }
        else if (stk.empty() || (ch == ')' && stk.top() != '(') || (ch == ']' && stk.top() != '[') || (ch == '}' && stk.top() != '{'))
        {
            return false;
        }
        else
        {
            stk.pop();
        }
    }
    return stk.empty();
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     string s = "[{()}]";
//     cout << isParenthesisBalanced(s);
//     cout << endl
//          << string(30, '-') << endl;
//     return 1;
// }
// ------------------------------------------------------------------------ Check for BST ------------------------------------------------------------------------------
bool isBST(Node *root, Node *minNode, Node *maxNode)
{
    if (root == nullptr)
    {
        return true;
    }
    if ((minNode && root->data <= minNode->data) || (maxNode && root->data >= maxNode->data))
    {
        return false;
    }
    return isBST(root->left, minNode, root) && isBST(root->right, root, maxNode);
}
bool isBST(Node *root)
{
    return isBST(root, nullptr, nullptr);
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     Node *root = new Node(10);
//     root->left = new Node(5);
//     root->right = new Node(20);
//     root->right->left = new Node(9);
//     root->right->right = new Node(25);
//     cout << isBST(root);
//     cout << endl
//          << string(30, '-') << endl;
//     return 1;
// }
// ------------------------------------------------------------------------ Remove loop in Linked List ------------------------------------------------------------------------------
void removeLoop(ListNode *head)
{
    unordered_map<ListNode *, int> isVisited;
    ListNode *previous = nullptr;
    ListNode *current = head;
    while (current != nullptr)
    {
        if (isVisited.count(current))
        {
            previous->next = nullptr;
            return;
        }
        isVisited[current] = 1;
        previous = current;
        current = current->next;
    }
}
// -----------------------------
void removeLoopOptimize(ListNode *head)
{
    // Same problem like : find the entry point in the loop in given linked list:
    // Optimised Approach : 2 steps
    /* 1. Find the entry point of the loop in the list
       2. now just update the prev node of entry point*/

    // taking three pointers to traverse on the list:
    ListNode *fast = head;
    ListNode *slow = head;

    // this node would point to the previous node of the slow:
    ListNode *prev = nullptr;
    // keep updating until you get the loop or the list finishes:
    while (fast != nullptr && fast->next != nullptr)
    {
        // updating the fast by two places:
        fast = fast->next->next;
        // updating the prev pointer as the prev node of slow pointer:
        prev = slow;
        // updating the slow pointer by one move:
        slow = slow->next;
        // if fast and slow becomes equal, that means, you got the loop:
        if (fast == slow)
        {
            ListNode *start = head;
            // keep moving by one place until start and slow does not become equal:
            while (start != slow)
            {
                prev = slow;
                slow = slow->next;
                start = start->next;
            }
            // at the moment they become equal, then make the next pointer of prev of slow as null:
            prev->next = nullptr;
            return;
        }
    }
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     ListNode *head = new ListNode(1);
//     head->next = new ListNode(3);
//     head->next->next = new ListNode(4);
//     head->next->next->next = head->next;
//     removeLoop(head);
//     cout << endl
//          << string(30, '-') << endl;
//     return 1;
// }
// ------------------------------------------------------------------------ Detect Loop in linked list ------------------------------------------------------------------------------
bool detectLoop(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     ListNode *head = new ListNode(1);
//     head->next = new ListNode(3);
//     head->next->next = new ListNode(4);
//     head->next->next->next = head->next;
//     cout << detectLoop(head);
//     cout << endl
//          << string(30, '-') << endl;
//     return 1;
// }
// ------------------------------------------------------------------------ Top View of Binary Tree ------------------------------------------------------------------------------
vector<int> topView(Node *root)
{
    map<int, int> visited;
    queue<pair<Node *, int>> todo;
    todo.push({root, 0});
    while (!todo.empty())
    {
        auto front = todo.front();
        Node *node = front.first;
        int column = front.second;
        todo.pop();
        if (visited.find(column) == visited.end())
        {
            visited[column] = node->data;
        }
        if (node->left != nullptr)
        {
            todo.push({node->left, column - 1});
        }
        if (node->right != nullptr)
        {
            todo.push({node->right, column + 1});
        }
    }
    vector<int> topView;
    for (auto item : visited)
    {
        topView.push_back(item.second);
    }
    return topView;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     Node *root = new Node(10);
//     root->left = new Node(20);
//     root->left->left = new Node(40);
//     root->left->right = new Node(60);
//     root->right = new Node(30);
//     root->right->left = new Node(90);
//     root->right->right = new Node(100);
//     vector<int> result = topView(root);
//     for (auto item : result)
//     {
//         cout << item << ", ";
//     }
//     cout << endl
//          << string(30, '-') << endl;
//     return 1;
// }
// ------------------------------------------------------------------------ Bottom View of Binary Tree ------------------------------------------------------------------------------
vector<int> bottomView(Node *root)
{
    map<int, int> visited;
    queue<pair<Node *, int>> todo;
    todo.push({root, 0});
    while (!todo.empty())
    {
        auto front = todo.front();
        todo.pop();
        Node *node = front.first;
        int column = front.second;
        visited[column] = node->data;
        if (node->left != nullptr)
        {
            todo.push({node->left, column - 1});
        }
        if (node->right != nullptr)
        {
            todo.push({node->right, column + 1});
        }
    }
    vector<int> bottomView;
    for (auto item : visited)
    {
        bottomView.push_back(item.second);
    }
    return bottomView;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     Node *root = new Node(10);
//     root->left = new Node(20);
//     root->left->left = new Node(40);
//     root->left->right = new Node(60);
//     root->right = new Node(30);
//     root->right->left = new Node(90);
//     root->right->right = new Node(100);
//     vector<int> result = topView(root);
//     for (auto item : result)
//     {
//         cout << item << ", ";
//     }
//     cout << endl
//          << string(30, '-') << endl;
//     return 1;
// }
// ------------------------------------------------------------------------ Vertical Tree Traversal ------------------------------------------------------------------------------
vector<int> verticalOrder(Node *root)
{
    map<int, map<int, multiset<int>>> visited;
    queue<pair<Node *, pair<int, int>>> todo;
    todo.push({root, {0, 0}});
    while (!todo.empty())
    {
        auto p = todo.front();
        todo.pop();
        Node *temp = p.first;
        int column = p.second.first;
        int row = p.second.second;
        visited[column][row].insert(temp->data);
        if (temp->left)
        {
            todo.push({temp->left, {column - 1, row + 1}});
        }
        if (temp->right)
        {
            todo.push({temp->right, {column + 1, row + 1}});
        }
    }
    vector<int> verticalOrder;
    for (auto item : visited)
    {
        for (auto data : item.second)
        {
            verticalOrder.insert(verticalOrder.end(), data.second.begin(), data.second.end());
        }
    }
    return verticalOrder;
}
// ---------------------------
void verticalTraversalDFS(Node *root, map<int, map<int, multiset<int>>> &visited, int row, int column)
{
    if (root == nullptr)
        return;
    visited[column][row].insert(root->data);
    verticalTraversalDFS(root->left, visited, row + 1, column - 1);
    verticalTraversalDFS(root->right, visited, row + 1, column + 1);
}
vector<int> verticalTraversalDFS(Node *root)
{
    map<int, map<int, multiset<int>>> visited;
    verticalTraversalDFS(root, visited, 0, 0);
    vector<int> verticalOrder;
    for (auto p : visited)
    {
        for (auto q : p.second)
        {
            verticalOrder.insert(verticalOrder.end(), q.second.begin(), q.second.end());
        }
    }
    return verticalOrder;
}
// ---------------------------
void verticalTraversalGFG(Node *root, map<int, map<int, vector<int>>> &visited, int row, int column)
{
    if (root == nullptr)
        return;
    visited[column][row].push_back(root->data);
    verticalTraversalGFG(root->left, visited, row + 1, column - 1);
    verticalTraversalGFG(root->right, visited, row + 1, column + 1);
}
vector<int> verticalTraversalGFG(Node *root)
{
    map<int, map<int, vector<int>>> visited;
    verticalTraversalGFG(root, visited, 0, 0);
    vector<int> verticalOrder;
    for (auto item : visited)
    {
        for (auto data : item.second)
        {
            verticalOrder.insert(verticalOrder.end(), data.second.begin(), data.second.end());
        }
    }
    return verticalOrder;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     Node *root = new Node(10);
//     root->left = new Node(20);
//     root->left->left = new Node(40);
//     root->left->right = new Node(60);
//     root->right = new Node(30);
//     root->right->left = new Node(90);
//     root->right->right = new Node(100);
//     vector<int> result = verticalTraversalGFG(root);
//     for (auto item : result)
//     {
//         cout << item << ", ";
//     }
//     cout << endl
//          << string(30, '-') << endl;
//     return 1;
// }
// ------------------------------------------------------------------------ ZigZag Tree Traversal ------------------------------------------------------------------------------
vector<int> zigZagTraversal(Node *root)
{
    vector<int> zigZagTraversal;
    bool isLeftToRight = true;
    queue<Node *> todo;
    todo.push(root);
    while (!todo.empty())
    {
        int size = todo.size();
        vector<int> level(size);
        for (int i = 0; i < size; i++)
        {
            Node *node = todo.front();
            todo.pop();
            if (isLeftToRight)
            {
                level[i] = node->data;
            }
            else
            {
                level[size - 1 - i] = node->data;
            }
            if (node->left != nullptr)
            {
                todo.push(node->left);
            }
            if (node->right != nullptr)
            {
                todo.push(node->right);
            }
        }
        for (int i = 0; i < level.size(); i++)
        {
            zigZagTraversal.push_back(level[i]);
        }
        isLeftToRight = !isLeftToRight;
    }
    return zigZagTraversal;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     Node *root = new Node(10);
//     root->left = new Node(20);
//     root->left->left = new Node(40);
//     root->left->right = new Node(60);
//     root->right = new Node(30);
//     root->right->left = new Node(90);
//     root->right->right = new Node(100);
//     vector<int> result = zigZagTraversal(root);
//     for (auto item : result)
//     {
//         cout << item << ", ";
//     }
//     cout << endl
//          << string(30, '-') << endl;
//     return 1;
// }
// ------------------------------------------------------------------------ Longest Consecutive Subsequence ------------------------------------------------------------------------------
int longestConsecutive(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, int> visited;
    int maxLength = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        visited[arr[i]] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        int currentLength = 0;
        int value = arr[i];
        while (visited.find(value) != visited.end())
        {
            currentLength += 1;
            value -= 1;
        }
        maxLength = max(maxLength, currentLength);
    }
    return maxLength;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> arr = {1, 9, 3, 10, 4, 20, 2};
//     cout << longestConsecutive(arr);
//     cout << endl
//          << string(30, '-') << endl;
//     return 1;
// }
// ------------------------------------------------------------------------ Reverse a linked list ------------------------------------------------------------------------------
ListNode *reverseList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr && current->next != nullptr)
    {
        ListNode *next = current->next;
        current->next = next->next;
        next->next = head;
        head = next;
    }
    return head;
}
int main()
{
    cout << string(30, '-') << endl;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    reverseList(head);
    cout << endl
         << string(30, '-') << endl;
    return 1;
}