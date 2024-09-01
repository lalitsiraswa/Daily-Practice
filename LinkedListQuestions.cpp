#include <bits/stdc++.h>
using namespace std;

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
