#include <bits/stdc++.h>
using namespace std;

template <typename T>
class DLLNode
{
public:
    T data;
    DLLNode *previous;
    DLLNode *next;
    DLLNode(T value) : data(value), previous(nullptr), next(nullptr) {};
    DLLNode(T value, DLLNode *previous, DLLNode *next) : data(value), previous(previous), next(next) {};
};
DLLNode<int> *array2DoublyLinkedList(vector<int> &vect)
{
    DLLNode<int> *head = new DLLNode<int>(vect[0]);
    DLLNode<int> *previous = head;
    for (int i = 1; i < vect.size(); i++)
    {
        DLLNode<int> *newNode = new DLLNode<int>(vect[i], previous, nullptr);
        previous->next = newNode;
        previous = newNode;
    }
    return head;
}
DLLNode<int> *deleteHead(DLLNode<int> *head)
{
    if (head == nullptr)
        return nullptr;
    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    DLLNode<int> *previous = head;
    head = head->next;
    head->previous = nullptr;
    previous->next = nullptr;
    delete previous;
    return head;
}
DLLNode<int> *deleteTail(DLLNode<int> *head)
{
    if (head == nullptr)
        return nullptr;
    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    DLLNode<int> *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    DLLNode<int> *previous = temp->previous;
    previous->next = nullptr;
    temp->previous = nullptr;
    delete temp;
    return head;
}
DLLNode<int> *deleteKthNode(DLLNode<int> *head, int k)
{
    if (head == nullptr)
        return head;
    if (k == 1)
    {
        DLLNode<int> *previous = head;
        head = head->next;
        previous->next = nullptr;
        if (head != nullptr)
            head->previous = nullptr;
        delete previous;
        return head;
    }
    int count = 1;
    DLLNode<int> *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
        if (count == k)
        {
            DLLNode<int> *previous = temp->previous;
            previous->next = temp->next;
            if (temp->next != nullptr)
                temp->next->previous = previous;
            temp->next = nullptr;
            temp->previous = nullptr;
            delete temp;
            break;
        }
    }
    return head;
}
void printDoublyLinkedList(DLLNode<int> *head)
{
    DLLNode<int> *temp = head;
    while (temp)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> vect = {2, 4, 6, 8, 10, 12};
//     DLLNode<int> *head = array2DoublyLinkedList(vect);
//     printDoublyLinkedList(head);
//     // head = deleteHead(head);
//     // printDoublyLinkedList(head);
//     // head = deleteTail(head);
//     // printDoublyLinkedList(head);
//     head = deleteKthNode(head, 0);
//     printDoublyLinkedList(head);
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------------- Doubly linked list Insertion at given position --------------------------------------------------------int main()
void addNode(DLLNode<int> *head, int pos, int data)
{
    int positionIndex = 0;
    DLLNode<int> *previous = head;
    while (previous != nullptr)
    {
        if (positionIndex == pos)
            break;
        positionIndex++;
        previous = previous->next;
    }
    DLLNode<int> *next = previous->next;
    DLLNode<int> *newNode = new DLLNode<int>(data);
    newNode->next = next;
    previous->next = newNode;
    newNode->previous = previous;
    if (next != nullptr)
        next->previous = newNode;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> vect = {8, 5, 1, 10, 5, 9, 9, 3, 5, 6, 6, 2};
//     DLLNode<int> *head = array2DoublyLinkedList(vect);
//     printDoublyLinkedList(head);
//     addNode(head, 1, 27);
//     printDoublyLinkedList(head);
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// ---------------------------------------------------------------------- Reverse a Doubly Linked List -----------------------------------------------------------------
// Function to reverse a doubly linked list
DLLNode<int> *reverseDLL(DLLNode<int> *head)
{
    DLLNode<int> *newHead = head;
    while (head->next != nullptr)
    {
        DLLNode<int> *temp = head->next;
        head->next = temp->next;
        if (head->next != nullptr)
            head->next->previous = head;
        temp->next = newHead;
        newHead->previous = temp;
        newHead = temp;
    }
    return newHead;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> vect = {2, 4, 6, 8, 10};
//     DLLNode<int> *head = array2DoublyLinkedList(vect);
//     printDoublyLinkedList(head);
//     head = reverseDLL(head);
//     printDoublyLinkedList(head);
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// --------------------------------------------------------- Delete all occurrences of a given key in a doubly linked list ---------------------------------------------------------------
void deleteAllOccurOfX(DLLNode<int> **head_ref, int x)
{
    // head points to head_ref as refernce is given
    DLLNode<int> *head = *head_ref;
    DLLNode<int> *temp = head;
    if (head == nullptr)
        return;
    // remove x if it is at head
    while (head->data == x)
    {
        head = head->next;
        if (head != nullptr)
            head->previous = nullptr;
        delete temp;
        temp = head;
    }
    // update the head
    *head_ref = head;
    // if x present after the head node
    while (temp != nullptr)
    {
        if (temp->data == x)
        {
            DLLNode<int> *previous = temp->previous;
            DLLNode<int> *next = temp->next;
            previous->next = next;
            if (next != nullptr)
                next->previous = previous;
            delete temp;
            temp = next;
        }
        else
            temp = temp->next;
    }
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> vect = {2, 2, 10, 8, 4, 2, 5, 2};
//     DLLNode<int> *head = array2DoublyLinkedList(vect);
//     // printDoublyLinkedList(head);
//     // deleteAllOccurOfX(&head, 2);
//     // printDoublyLinkedList(head);
//     int x = 10;
//     int *y = &x;
//     int **z = &y;
//     cout << *y << endl;
//     cout << **z << endl;
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// --------------------------------------------------------- Find pairs with given sum in doubly linked list ---------------------------------------------------------------
// ------------ TLE -------------
vector<pair<int, int>> findPairsWithGivenSum(DLLNode<int> *head, int target)
{
    vector<pair<int, int>> pairs;
    DLLNode<int> *tempLeft = head;
    while (tempLeft != nullptr)
    {
        if (tempLeft->data > target)
            break;
        DLLNode<int> *tempRight = tempLeft->next;
        while (tempRight != nullptr)
        {
            if (tempLeft->data + tempRight->data > target)
            {
                break;
            }
            if (tempLeft->data + tempRight->data == target)
            {
                pairs.push_back({tempLeft->data, tempRight->data});
            }
            tempRight = tempRight->next;
        }
        tempLeft = tempLeft->next;
    }
    return pairs;
}
// -----------------
vector<pair<int, int>> findPairsWithGivenSumBinarySearch(DLLNode<int> *head, int target)
{
    vector<pair<int, int>> pairs;
    DLLNode<int> *tempLeft = head;
    DLLNode<int> *tempRight = head;
    while (tempRight->next != nullptr)
    {
        tempRight = tempRight->next;
    }
    while (tempLeft->data < tempRight->data)
    {
        
    }
    return pairs;
}
int main()
{
    cout << string(30, '-') << endl;
    vector<int> vect = {1, 2, 4, 5, 6, 8, 9};
    DLLNode<int> *head = array2DoublyLinkedList(vect);
    printDoublyLinkedList(head);
    vector<pair<int, int>> pairs = findPairsWithGivenSumBinarySearch(head, 7);
    for (auto pair : pairs)
    {
        cout << "{" << pair.first << ", " << pair.second << "}" << endl;
    }
    cout << endl
         << string(30, '-') << endl;
    return 0;
}