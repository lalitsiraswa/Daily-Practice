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
// ---------------------------------------------------------------------- Find length of Loop ------------------------------------------------------------------------
int countNodesinLoop(ListNode *head)
{
    if (head == nullptr)
        return 0;
    ListNode *slowPointer = head, *fastpointer = head;
    bool isCycleDetected = false;
    while (fastpointer != nullptr && fastpointer->next != nullptr)
    {
        slowPointer = slowPointer->next;
        fastpointer = fastpointer->next->next;
        if (slowPointer == fastpointer)
        {
            isCycleDetected = true;
            break;
        }
    }
    if (!isCycleDetected)
        return 0;
    int cycleLength = 1;
    while (slowPointer->next != fastpointer)
    {
        cycleLength++;
        slowPointer = slowPointer->next;
    }
    return cycleLength;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> vect = {1, 2, 3, 4, 5};
//     ListNode *head = array2LinkedList(vect);
//     printSinglyLinkedList(head);
//     ListNode *cycleStartingNode = detectCycle2(head);
//     cout << countNodesinLoop(head);
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// ---------------------------------------------------------------------- 234. Palindrome Linked List ------------------------------------------------------------------------
bool isPalindrome(ListNode *head)
{
    if (head == nullptr)
        return head;
    ListNode *slowPointer = head, *fastPointer = head;
    while (fastPointer != nullptr && fastPointer->next != nullptr)
    {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
    }
    ListNode *temp = nullptr;
    // Even number of nodes
    if (fastPointer == nullptr)
        temp = slowPointer;
    // Odd number of nodes
    else
        temp = slowPointer->next;
    // Reverse the second half
    ListNode *previous = nullptr;
    while (temp != nullptr)
    {
        ListNode *next = temp->next;
        temp->next = previous;
        previous = temp;
        temp = next;
    }
    // Now the previous will be our newHead for the second half linked list
    slowPointer = head;
    while (previous != nullptr)
    {
        if (slowPointer->val != previous->val)
            return false;
        slowPointer = slowPointer->next;
        previous = previous->next;
    }
    return true;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> vect = {1, 2, 3, 3, 1};
//     ListNode *head = array2LinkedList(vect);
//     printSinglyLinkedList(head);
//     cout << isPalindrome(head) << endl;
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// ---------------------------------------------------------------------- 328. Odd Even Linked List ------------------------------------------------------------------------
ListNode *oddEvenList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
        return head;
    ListNode *oddHead = head;
    ListNode *previousOddNode = head;
    ListNode *evenHead = head->next;
    ListNode *previousEvenNode = head->next;
    ListNode *temp = head->next->next;
    bool isOdd = true;
    while (temp != nullptr)
    {
        if (isOdd)
        {
            previousOddNode->next = temp;
            previousOddNode = temp;
        }
        else
        {
            previousEvenNode->next = temp;
            previousEvenNode = temp;
        }
        temp = temp->next;
        isOdd = !isOdd;
    }
    previousEvenNode->next = nullptr;
    previousOddNode->next = evenHead;
    return oddHead;
}
// -------------------------------
ListNode *oddEvenList2(ListNode *head)
{
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
        return head;
    ListNode *oddNode = head;
    ListNode *evenNode = head->next;
    ListNode *evenNodeHead = head->next;
    while (evenNode != nullptr && evenNode->next != nullptr)
    {
        oddNode->next = oddNode->next->next;
        evenNode->next = evenNode->next->next;
        oddNode = oddNode->next;
        evenNode = evenNode->next;
    }
    oddNode->next = evenNodeHead;
    return head;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> vect = {1, 2, 3, 4, 5};
//     ListNode *head = array2LinkedList(vect);
//     printSinglyLinkedList(head);
//     head = oddEvenList2(head);
//     printSinglyLinkedList(head);
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// ---------------------------------------------------------------------- 19. Remove Nth Node From End of List ------------------------------------------------------------------------
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *currentNode = head;
    ListNode *targetNode = nullptr;
    ListNode *targetPrevious = nullptr;
    int counter = 1;
    while (currentNode != nullptr)
    {
        if (counter >= n)
        {
            targetPrevious = targetNode;
            if (targetNode == nullptr)
                targetNode = head;
            else
                targetNode = targetNode->next;
        }
        counter++;
        currentNode = currentNode->next;
    }
    if (targetPrevious == nullptr)
    {
        head = head->next;
        delete targetNode;
        return head;
    }
    targetPrevious->next = targetNode->next;
    delete targetNode;
    return head;
}
// ----------------
ListNode *removeNthFromEnd2(ListNode *head, int n)
{
    ListNode *fastPointer = head;
    ListNode *slowPointer = head;
    ListNode *slowPointerPrevious = nullptr;
    for (int i = 1; i < n; i++)
        fastPointer = fastPointer->next;
    while (fastPointer->next != nullptr)
    {
        slowPointerPrevious = slowPointer;
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next;
    }
    if (slowPointerPrevious == nullptr)
    {
        head = head->next;
        delete slowPointer;
        return head;
    }
    slowPointerPrevious->next = slowPointer->next;
    delete slowPointer;
    return head;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> vect = {1, 2, 3, 4, 5};
//     ListNode *head = array2LinkedList(vect);
//     printSinglyLinkedList(head);
//     head = removeNthFromEnd2(head, 1);
//     printSinglyLinkedList(head);
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// ---------------------------------------------------------------- 2095. Delete the Middle Node of a Linked List ------------------------------------------------------------------
ListNode *deleteMiddle(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    ListNode *slowPointer = head;
    ListNode *fastPointer = head;
    ListNode *slowPointerPrevious = nullptr;
    while (fastPointer != nullptr && fastPointer->next != nullptr)
    {
        slowPointerPrevious = slowPointer;
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
    }
    slowPointerPrevious->next = slowPointer->next;
    delete slowPointer;
    return head;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> vect = {1, 2};
//     ListNode *head = array2LinkedList(vect);
//     printSinglyLinkedList(head);
//     head = deleteMiddle(head);
//     printSinglyLinkedList(head);
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// -------------------------------------------------------------------- 148. Sort Singly Linked List ----------------------------------------------------------------------
ListNode *sortList(ListNode *head)
{
    ListNode *temp = head;
    vector<int> vect;
    while (temp != nullptr)
    {
        vect.push_back(temp->val);
        temp = temp->next;
    }
    sort(vect.begin(), vect.end());
    temp = head;
    int index = 0;
    while (temp != nullptr)
    {
        temp->val = vect[index++];
        temp = temp->next;
    }
    return head;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> vect = {-1, 5, 3, 4, 0};
//     ListNode *head = array2LinkedList(vect);
//     printSinglyLinkedList(head);
//     head = sortList(head);
//     printSinglyLinkedList(head);
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// -------------------------------------------------------------------- 21. Merge Two Sorted Lists ----------------------------------------------------------------------
ListNode *mergeTwoLists(ListNode *head1, ListNode *head2)
{
    if (head1 == nullptr)
        return head2;
    if (head2 == nullptr)
        return head1;
    ListNode *newHead = nullptr;
    if (head1->val <= head2->val)
    {
        newHead = head1;
        head1 = head1->next;
    }
    else
    {
        newHead = head2;
        head2 = head2->next;
    }
    ListNode *temp = newHead;
    while (head1 != nullptr && head2 != nullptr)
    {
        if (head1->val <= head2->val)
        {
            temp->next = head1;
            head1 = head1->next;
        }
        else
        {
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }
    if (head1 != nullptr)
        temp->next = head1;
    if (head2 != nullptr)
        temp->next = head2;
    return newHead;
}
// ----- Using Dummy Node Concept -----
ListNode *mergeTwoLists2(ListNode *head1, ListNode *head2)
{
    if (head1 == nullptr)
        return head2;
    if (head2 == nullptr)
        return head1;
    ListNode *dummyNode = new ListNode(-1);
    ListNode *temp = dummyNode;
    while (head1 != nullptr && head2 != nullptr)
    {
        if (head1->val <= head2->val)
        {
            temp->next = head1;
            head1 = head1->next;
        }
        else
        {
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }
    if (head1 != nullptr)
        temp->next = head1;
    if (head2 != nullptr)
        temp->next = head2;
    return dummyNode->next;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> list1 = {1, 2, 4};
//     vector<int> list2 = {1, 3, 4};
//     ListNode *head1 = array2LinkedList(list1);
//     ListNode *head2 = array2LinkedList(list2);
//     printSinglyLinkedList(head1);
//     printSinglyLinkedList(head2);
//     head1 = mergeTwoLists2(head1, head2);
//     printSinglyLinkedList(head1);
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// -------------------------------------------------------------------- 25. Reverse Nodes in k-Group ----------------------------------------------------------------------
ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head->next == nullptr)
        return head;
    int listLength = 0;
    ListNode *temp = head;
    while (temp != nullptr)
    {
        listLength++;
        temp = temp->next;
    }
    ListNode *newHead = nullptr;
    ListNode *newPrevious = nullptr;
    temp = head;
    int counter = 1;
    while (temp != nullptr)
    {
        ListNode *dummyHead = temp;
        if ((counter + k) - 1 > listLength)
        {
            newPrevious->next = dummyHead;
            break;
        }
        ListNode *previous = nullptr;
        int count = 1;
        while (count <= k)
        {
            ListNode *next = temp->next;
            temp->next = previous;
            previous = temp;
            temp = next;
            count++;
            counter++;
        }
        if (newHead == nullptr)
            newHead = previous;
        if (newPrevious == nullptr)
            newPrevious = head;
        else
        {
            newPrevious->next = previous;
            newPrevious = dummyHead;
        }
    }
    return newHead;
}
int main()
{
    cout << string(30, '-') << endl;
    vector<int> vect = {1, 2, 3, 4, 5};
    ListNode *head = array2LinkedList(vect);
    printSinglyLinkedList(head);
    head = reverseKGroup(head, 2);
    printSinglyLinkedList(head);
    cout << endl
         << string(30, '-') << endl;
    return 0;
}