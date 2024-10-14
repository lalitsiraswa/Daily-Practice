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
        {
            newHead = previous;
            newPrevious = dummyHead;
        }
        else
        {
            newPrevious->next = previous;
            newPrevious = dummyHead;
        }
    }
    return newHead;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> vect = {1, 2, 3, 4, 5};
//     ListNode *head = array2LinkedList(vect);
//     printSinglyLinkedList(head);
//     head = reverseKGroup(head, 2);
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
// -------------------------------------------
ListNode *mergeTwoSortedLinkedLists(ListNode *list1, ListNode *list2)
{
    // Create a dummy node to serve
    // as the head of the merged list
    ListNode *dummyNode = new ListNode(-1);
    ListNode *temp = dummyNode;
    // Traverse both lists simultaneously
    while (list1 != nullptr && list2 != nullptr)
    {
        // Compare elements of both lists and
        // link the smaller node to the merged list
        if (list1->val <= list2->val)
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2 = list2->next;
        }
        // Move the temporary pointer
        // to the next node
        temp = temp->next;
    }
    // If any list still has remaining
    // elements, append them to the merged list
    if (list1 != nullptr)
    {
        temp->next = list1;
    }
    else
    {
        temp->next = list2;
    }
    return dummyNode->next;
}
// Function to find the middle of a linked list
ListNode *findMiddle(ListNode *head)
{
    // If the list is empty or has only one node
    // the middle is the head itself
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    // Initializing slow and fast pointers
    ListNode *slow = head;
    ListNode *fast = head->next;
    // Move the fast pointer twice as fast as the slow pointer
    // When the fast pointer reaches the end, the slow pointer
    // will be at the middle
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
// Function to perform merge sort on a linked list
ListNode *sortListMergeSort(ListNode *head)
{
    // Base case: if the list is empty or has only one node
    // it is already sorted, so return the head
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    // Find the middle of the list using the findMiddle function
    ListNode *middle = findMiddle(head);
    // Divide the list into two halves
    ListNode *right = middle->next;
    middle->next = nullptr;
    ListNode *left = head;
    // Recursively sort the left and right halves
    left = sortListMergeSort(left);
    right = sortListMergeSort(right);
    // Merge the sorted halves using the mergeTwoSortedLinkedLists function
    return mergeTwoSortedLinkedLists(left, right);
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> vect = {4, 2, 1, 3};
//     ListNode *head = array2LinkedList(vect);
//     printSinglyLinkedList(head);
//     head = sortList(head);
//     printSinglyLinkedList(head);
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// -------------------------------------------------------------------- Sort a linked list of 0s, 1s and 2s ----------------------------------------------------------------------
// Function to sort a linked list of 0s, 1s and 2s.
ListNode *segregate(ListNode *head)
{
    ListNode *zeroHead = new ListNode(-1);
    ListNode *oneHead = new ListNode(-1);
    ListNode *twoHead = new ListNode(-1);
    ListNode *tempZero = zeroHead, *tempOne = oneHead, *tempTwo = twoHead;
    ListNode *temp = head;
    head = nullptr;
    while (temp != nullptr)
    {
        if (temp->val == 0)
        {
            tempZero->next = temp;
            tempZero = tempZero->next;
        }
        else if (temp->val == 1)
        {
            tempOne->next = temp;
            tempOne = tempOne->next;
        }
        else
        {
            tempTwo->next = temp;
            tempTwo = tempTwo->next;
        }
        temp = temp->next;
    }
    if (tempZero->val != -1 && head == nullptr)
    {
        head = zeroHead->next;
        if (tempOne->val != -1)
        {
            tempZero->next = oneHead->next;
            tempOne->next = twoHead->next;
        }
        else
            tempZero->next = twoHead->next;
    }
    if (tempOne->val != -1 && head == nullptr)
    {
        head = oneHead->next;
        tempOne->next = twoHead->next;
    }
    if (tempTwo->val != -1 && head == nullptr)
        head = twoHead->next;
    tempTwo->next = nullptr;
    return head;
}
// ----------------------
ListNode *segregate2(ListNode *head)
{
    ListNode *zeroHead = new ListNode(-1);
    ListNode *oneHead = new ListNode(-1);
    ListNode *twoHead = new ListNode(-1);
    ListNode *tempZero = zeroHead, *tempOne = oneHead, *tempTwo = twoHead;
    ListNode *temp = head;
    while (temp != nullptr)
    {
        if (temp->val == 0)
        {
            tempZero->next = temp;
            tempZero = tempZero->next;
        }
        else if (temp->val == 1)
        {
            tempOne->next = temp;
            tempOne = tempOne->next;
        }
        else
        {
            tempTwo->next = temp;
            tempTwo = tempTwo->next;
        }
        temp = temp->next;
    }
    tempZero->next = (oneHead->next != nullptr) ? oneHead->next : twoHead->next;
    tempOne->next = twoHead->next;
    tempTwo->next = nullptr;
    return zeroHead->next;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> vect = {2, 2, 2, 0};
//     ListNode *head = array2LinkedList(vect);
//     printSinglyLinkedList(head);
//     head = segregate2(head);
//     printSinglyLinkedList(head);
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// -------------------------------------------------------------------- 160. Intersection of Two Linked Lists ----------------------------------------------------------------------
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    int listALength = 0;
    int listBLength = 0;
    ListNode *tempA = headA;
    ListNode *tempB = headB;
    while (tempA != nullptr)
    {
        listALength++;
        tempA = tempA->next;
    }
    while (tempB)
    {
        listBLength++;
        tempB = tempB->next;
    }
    tempA = headA;
    tempB = headB;
    if (listALength >= listBLength)
    {
        while (listALength != listBLength)
        {
            tempA = tempA->next;
            listALength--;
        }
    }
    else
    {
        while (listALength != listBLength)
        {
            tempB = tempB->next;
            listBLength--;
        }
    }
    while (tempA != nullptr && tempB != nullptr)
    {
        if (tempA == tempB)
            return tempA;
        tempA = tempA->next;
        tempB = tempB->next;
    }
    return nullptr;
}
// ----------------------------
ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB)
{
    if (headA == nullptr || headB == nullptr)
        return nullptr;
    ListNode *tempA = headA;
    ListNode *tempB = headB;
    while (tempA != tempB)
    {
        tempA = tempA->next;
        tempB = tempB->next;
        if (tempA == tempB)
            return tempA;
        if (tempA == nullptr)
            tempA = headB;
        if (tempB == nullptr)
            tempB = headA;
    }
    return tempA;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> vect = {2, 2, 2, 0};
//     ListNode *head = array2LinkedList(vect);
//     printSinglyLinkedList(head);
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// -------------------------------------------------------------------- Add 1 to a Linked List Number ----------------------------------------------------------------------
ListNode *addOne1(ListNode *head)
{
    ListNode *temp = head;
    ListNode *previous = nullptr;
    while (temp != nullptr)
    {
        ListNode *next = temp->next;
        temp->next = previous;
        previous = temp;
        temp = next;
    }
    temp = previous;
    while (temp != nullptr)
    {
        if (temp->next == nullptr && (temp->val + 1) > 9)
        {
            int sum = temp->val + 1;
            temp->val = sum % 10;
            ListNode *newNode = new ListNode(sum / 10);
            temp->next = newNode;
            head = newNode;
            break;
        }
        else if (temp->val + 1 > 9)
        {
            temp->val = 0;
        }
        else
        {
            temp->val += 1;
            break;
        }
        temp = temp->next;
    }
    temp = previous;
    previous = nullptr;
    while (temp != nullptr)
    {
        ListNode *next = temp->next;
        temp->next = previous;
        previous = temp;
        temp = next;
    }
    return head;
}
// ----------------------------
ListNode *reverseLinkedList(ListNode *head)
{
    ListNode *previous = nullptr;
    ListNode *temp = head;
    ListNode *next = nullptr;
    while (temp != nullptr)
    {
        // storing next node
        next = temp->next;
        // linking current node to previous
        temp->next = previous;
        // updating previous
        previous = temp;
        // updating temp
        temp = next;
    }
    return previous;
}
ListNode *addOne2(ListNode *head)
{
    head = reverseLinkedList(head);
    ListNode *temp = head;
    int carry = 1;
    while (carry != 0)
    {
        // adding one to current node
        temp->val += 1;
        if (temp->val < 10)
        {
            // if no carry we can reverse back list and return it
            return reverseLinkedList(head);
        }
        // else we continue with taking carry forward
        else
            temp->val = 0;
        // if, end of list, we break from loop
        if (temp->next == nullptr)
            break;
        // else we move to next node
        else
            temp = temp->next;
    }
    // adding new node for the carried 1
    temp->next = new ListNode(1);
    return reverseLinkedList(head);
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> vect = {3};
//     ListNode *head = array2LinkedList(vect);
//     printSinglyLinkedList(head);
//     head = addOne2(head);
//     printSinglyLinkedList(head);
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// -------------------------------------------------------------------- 2. Add Two Numbers ----------------------------------------------------------------------
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *templ1 = l1;
    ListNode *templ2 = l2;
    ListNode *prevTempl1 = nullptr;
    ListNode *prevTempl2 = nullptr;
    int carry = 0;
    while (templ1 != nullptr && templ2 != nullptr)
    {
        int totalSum = templ1->val + templ2->val + carry;
        templ1->val = totalSum % 10;
        carry = totalSum / 10;
        prevTempl1 = templ1;
        templ1 = templ1->next;
        prevTempl2 = templ2;
        templ2 = templ2->next;
    }
    // DryRun for [5] and [5]
    ListNode *previous = prevTempl1;
    if (templ1 == nullptr)
        prevTempl1->next = templ2;
    templ1 = prevTempl1->next;
    while (templ1 != nullptr && carry != 0)
    {
        previous = templ1;
        int totalSum = templ1->val + carry;
        templ1->val = totalSum % 10;
        carry = totalSum / 10;
        templ1 = templ1->next;
    }
    if (carry > 0)
    {
        previous->next = new ListNode(carry);
    }
    return l1;
}
// ----------------------
ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2)
{
    ListNode *dummyHead = new ListNode(-1);
    ListNode *temp = dummyHead;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr || carry != 0)
    {
        int sum = 0;
        if (l1 != nullptr)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += carry;
        carry = sum / 10;
        ListNode *node = new ListNode(sum % 10);
        temp->next = node;
        temp = temp->next;
    }
    return dummyHead->next;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> vect2 = {5};
//     vector<int> vect1 = {5};
//     ListNode *head1 = array2LinkedList(vect1);
//     ListNode *head2 = array2LinkedList(vect2);
//     printSinglyLinkedList(head1);
//     printSinglyLinkedList(head2);
//     head1 = addTwoNumbers2(head1, head2);
//     printSinglyLinkedList(head1);
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// -------------------------------------------------------------------- 61. Rotate List ----------------------------------------------------------------------
ListNode *rotateRight(ListNode *head, int k)
{
    if (head == nullptr)
        return head;
    ListNode *temp = head;
    ListNode *tailNode = nullptr;
    int listLength = 0;
    while (temp != nullptr)
    {
        listLength++;
        // storing the last/tail node
        tailNode = temp;
        temp = temp->next;
    }
    temp = head;
    k = k % listLength;
    // k == 0 when k == listLength (5 % 5 == 0)
    if (k == 0)
        return head;
    int counter = 1;
    while (counter < (listLength - k))
    {
        counter++;
        temp = temp->next;
    }
    ListNode *next = temp->next;
    temp->next = nullptr;
    tailNode->next = head;
    head = next;
    return head;
}
// ---------------------
ListNode *rotateRight2(ListNode *head, int k)
{
    if (head == nullptr)
        return head;
    ListNode *temp = head;
    ListNode *tailNode = nullptr;
    int listLength = 0;
    while (temp != nullptr)
    {
        listLength++;
        tailNode = temp;
        temp = temp->next;
    }
    k = k % listLength;
    // k == 0 when k == listLength (5 % 5 == 0)
    if (k == 0)
        return head;
    // connect last/tail node with the head
    tailNode->next = head;
    temp = head;
    int counter = 1;
    while (counter < (listLength - k))
    {
        counter++;
        temp = temp->next;
    }
    head = temp->next;
    temp->next = nullptr;
    return head;
}
int main()
{
    cout << string(30, '-') << endl;
    vector<int> vect = {1, 2, 3, 4, 5};
    ListNode *head = array2LinkedList(vect);
    printSinglyLinkedList(head);
    head = rotateRight2(head, 0);
    printSinglyLinkedList(head);
    cout << endl
         << string(30, '-') << endl;
    return 0;
}