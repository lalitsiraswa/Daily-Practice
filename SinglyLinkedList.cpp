#include <bits/stdc++.h>
using namespace std;

//   Definition for singly-linked list.
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

template <typename T>
class Node
{
public:
    T data;
    Node *next;
    Node() : data(0), next(nullptr) {};
    Node(T value) : data(value), next(nullptr) {};
    Node(T value, Node *nextNode) : data(value), next(nextNode) {};
};
Node<int> *convertArray2LinkedList(vector<int> &vect)
{
    Node<int> *head = new Node(vect[0]);
    Node<int> *mover = head;
    for (int i = 1; i < vect.size(); i++)
    {
        Node<int> *temp = new Node(vect[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void printLinkedList(Node<int> *head)
{
    Node<int> *temp = head;
    while (temp)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}
bool searchInLinkedList(Node<int> *head, int target)
{
    Node<int> *temp = head;
    while (temp)
    {
        if (temp->data == target)
            return true;
        temp = temp->next;
    }
    return false;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> vect = {2, 4, 6, 8, 10, 12};
//     Node<int> *head = convertArray2LinkedList(vect);
//     printLinkedList(head);
//     cout << endl
//          << "Search : " << searchInLinkedList(head, 5) << endl;
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------------------ Linked List Insertion At End --------------------------------------------------------------------
Node<int> *insertAtEnd(Node<int> *head, int x)
{
    if (head == nullptr)
    {
        head = new Node<int>(x);
        return head;
    }
    Node<int> *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = new Node<int>(x);
    return head;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     Node<int> *head = nullptr;
//     head = insertAtEnd(head, 2);
//     head = insertAtEnd(head, 4);
//     head = insertAtEnd(head, 6);
//     head = insertAtEnd(head, 8);
//     head = insertAtEnd(head, 10);
//     printLinkedList(head);
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------------------ Delete Kth element from the Linked List --------------------------------------------------------------------
Node<int> *removeKthNode(Node<int> *head, int k)
{
    if (head == nullptr)
        return head;
    int n = 0;
    Node<int> *temp = head;
    while (temp)
    {
        n++;
        temp = temp->next;
    }
    if (k > n)
        return head;
    if (k == 1)
    {
        temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    temp = head;
    int count = 1;
    Node<int> *prev = nullptr;
    while (count != k)
    {
        prev = temp;
        temp = temp->next;
        count++;
    }
    prev->next = temp->next;
    delete temp;
    return head;
}
// -----------------------
Node<int> *removeKthNodeFromLL(Node<int> *head, int k)
{
    if (head == nullptr)
        return head;
    if (k == 1)
    {
        Node<int> *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int count = 0;
    Node<int> *temp = head;
    Node<int> *previous = nullptr;
    while (temp != nullptr)
    {
        count++;
        if (count == k)
        {
            previous->next = temp->next;
            delete temp;
            break;
        }
        previous = temp;
        temp = temp->next;
    }
    return head;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     Node<int> *head = nullptr;
//     head = insertAtEnd(head, 2);
//     head = insertAtEnd(head, 4);
//     head = insertAtEnd(head, 6);
//     head = insertAtEnd(head, 8);
//     head = insertAtEnd(head, 10);
//     head = insertAtEnd(head, 12);
//     printLinkedList(head);
//     head = removeKthNodeFromLL(head, 2);
//     printLinkedList(head);
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------------------ 237. Delete Node in a Linked List --------------------------------------------------------------------
void deleteNode(Node<int> *node)
{
    Node<int> *temp = node->next;
    node->data = temp->data;
    node->next = temp->next;
    temp = NULL;
    delete temp;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     Node<int> *head = nullptr;
//     head = insertAtEnd(head, 2);
//     head = insertAtEnd(head, 4);
//     head = insertAtEnd(head, 6);
//     head = insertAtEnd(head, 8);
//     head = insertAtEnd(head, 10);
//     head = insertAtEnd(head, 12);
//     printLinkedList(head);
//     deleteNode(head->next->next->next);
//     printLinkedList(head);
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// ---------------------------------------------------------------------- Insert at kth position ------------------------------------------------------------------------
Node<int> *insertAtKthPosition(Node<int> *head, int k, int value)
{
    if (head == nullptr)
    {
        if (k == 1)
        {
            Node<int> *newNode = new Node<int>(value);
            newNode->next = head;
            return newNode;
        }
        else
            return head;
    }
    if (k == 1)
    {
        Node<int> *newNode = new Node<int>(value);
        newNode->next = head;
        return newNode;
    }
    int count = 1;
    Node<int> *temp = head;
    Node<int> *previous = NULL;
    while (temp)
    {
        count++;
        previous = temp;
        temp = temp->next;
        if (count == k)
        {
            Node<int> *newNode = new Node<int>(value);
            previous->next = newNode;
            newNode->next = temp;
            break;
        }
    }
    return head;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     Node<int> *head = nullptr;
//     head = insertAtEnd(head, 2);
//     head = insertAtEnd(head, 4);
//     head = insertAtEnd(head, 6);
//     head = insertAtEnd(head, 8);
//     head = insertAtEnd(head, 10);
//     head = insertAtEnd(head, 12);
//     printLinkedList(head);
//     head = insertAtKthPosition(head, 7, 100);
//     printLinkedList(head);
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// ---------------------------------------------------------------------- 876. Middle of the Linked List ------------------------------------------------------------------------
ListNode *array2LinkedList(vector<int> &vect)
{
    ListNode *head = new ListNode(vect[0]);
    ListNode *mover = head;
    for (int i = 1; i < vect.size(); i++)
    {
        ListNode *temp = new ListNode(vect[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void printSinglyLinkedList(ListNode *head)
{
    ListNode *temp = head;
    while (temp)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
ListNode *middleNode(ListNode *head)
{
    ListNode *slowPointer = head, *fastPointer = head;
    while (fastPointer && fastPointer->next != nullptr)
    {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
    }
    return slowPointer;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> vect = {1, 2, 3, 4, 5};
//     ListNode *head = array2LinkedList(vect);
//     printSinglyLinkedList(head);
//     cout << middleNode(head)->val << endl;
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// ---------------------------------------------------------------------- 206. Reverse Linked List - Iterative ------------------------------------------------------------------------
ListNode *reverseList(ListNode *head)
{
    if (head == nullptr)
        return head;
    ListNode *newHead = head;
    while (head->next != nullptr)
    {
        ListNode *temp = head->next;
        head->next = temp->next;
        temp->next = newHead;
        newHead = temp;
    }
    return newHead;
}
// ----------------------------------
ListNode *reverseList2(ListNode *head)
{
    // Initialize'temp' at head of linked list
    ListNode *temp = head;
    // Initialize pointer 'prev' to NULL, representing the previous node
    ListNode *previous = nullptr;
    // Traverse the list, continue till 'temp' reaches the end (NULL)
    while (temp != nullptr)
    {
        // Store the next node in 'front' to preserve the reference
        ListNode *front = temp->next;
        // Reverse the direction of the current node's 'next' pointer
        // to point to 'prev'
        temp->next = previous;
        // Move 'prev' to the current node for the next iteration
        previous = temp;
        // Move 'temp' to the 'front' node advancing the traversal
        temp = front;
    }
    // Return the new head of the reversed linked list
    return previous;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> vect = {1, 2, 3, 4, 5};
//     ListNode *head = array2LinkedList(vect);
//     printSinglyLinkedList(head);
//     head = reverseList2(head);
//     printSinglyLinkedList(head);
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// ---------------------------------------------------------------------- 206. Reverse Linked List - Recursive ------------------------------------------------------------------------
ListNode *reverseListRecursiveHelper(ListNode *head, ListNode *newHead)
{
    if (head->next == nullptr)
        return newHead;
    ListNode *temp = head->next;
    head->next = temp->next;
    temp->next = newHead;
    newHead = temp;
    return reverseListRecursiveHelper(head, newHead);
}
ListNode *reverseListRecursive(ListNode *head)
{
    if (head == nullptr)
        return head;
    ListNode *newHead = head;
    return reverseListRecursiveHelper(head, newHead);
}
// --------------------------
ListNode *reverseListRecursiveHelper2(ListNode *temp, ListNode *previous)
{
    if (temp == nullptr)
        return previous;
    // Store the next node in 'front' to preserve the reference
    ListNode *front = temp->next;
    // Reverse the direction of the current node's 'next' pointer
    // to point to 'prev'
    temp->next = previous;
    // Move 'prev' to the current node for the next iteration
    previous = temp;
    // Move 'temp' to the 'front' node advancing the traversal
    temp = front;
    return reverseListRecursiveHelper2(temp, previous);
}
ListNode *reverseListRecursive2(ListNode *head)
{
    if (head == nullptr)
        return head;
    ListNode *temp = head;
    ListNode *previous = nullptr;
    return reverseListRecursiveHelper2(temp, previous);
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> vect = {1, 2, 3, 4, 5};
//     ListNode *head = array2LinkedList(vect);
//     printSinglyLinkedList(head);
//     head = reverseListRecursive2(head);
//     printSinglyLinkedList(head);
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// ---------------------------------------------------------------------- 141. Linked List Cycle ------------------------------------------------------------------------
bool DetectCycleOtherWay(ListNode *head)
{
    if (head == NULL)
        return false;
    ListNode *slowPointer = head;
    ListNode *fastPointer = head;
    while (fastPointer && fastPointer->next)
    {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
        if (slowPointer == fastPointer)
            return true;
    }
    return false;
}
// ---------------------------------------------------------------------- 142. Linked List Cycle II ------------------------------------------------------------------------
ListNode *detectCycle2(ListNode *head)
{
    if (head == nullptr)
        return head;
    ListNode *slowPointer = head;
    ListNode *fastPointer = head;
    bool isCycleDetected = false;
    while (fastPointer != nullptr && fastPointer->next != nullptr)
    {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
        if (slowPointer == fastPointer)
        {
            isCycleDetected = true;
            break;
        }
    }
    if (isCycleDetected == false)
        return nullptr;
    slowPointer = head;
    while (1)
    {
        if (slowPointer == fastPointer)
            break;
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next;
    }
    return slowPointer;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> vect = {1, 2, 3, 4, 5};
//     ListNode *head = array2LinkedList(vect);
//     printSinglyLinkedList(head);
//     ListNode *cycleStartingNode = detectCycle2(head);
//     if (cycleStartingNode != nullptr)
//         cout << cycleStartingNode->val << endl;
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }