#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {};
    Node(int data) : data(data), next(nullptr) {};
};

void removeLoop(Node *head)
{
    Node *slow = head, *fast = head;
    bool hasCycle = false;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
            hasCycle = true;
        }
    }
    if (hasCycle)
    {
        Node *temp = head;
        Node *prev = slow;
        while (1)
        {
            if (temp == slow)
            {
                prev->next = nullptr;
                return;
            }
        }
    }
}
int main()
{
    cout << string(30, '-') << endl;
    cout << endl
         << string(30, '-');
}