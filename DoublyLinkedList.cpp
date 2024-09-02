#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *previous;
    Node *next;
    Node(T value) : data(value), previous(nullptr), next(nullptr) {};
    Node(T value, Node *previous, Node *next) : data(value), previous(previous), next(next) {};
};
Node<int> *array2DoublyLinkedList(vector<int> &vect)
{
    Node<int> *head = new Node<int>(vect[0]);
    Node<int> *previous = head;
    for (int i = 1; i < vect.size(); i++)
    {
        Node<int> *newNode = new Node<int>(vect[i], previous, nullptr);
        previous->next = newNode;
        previous = newNode;
    }
    return head;
}
void printDoublyLinkedList(Node<int> *head)
{
    Node<int> *temp = head;
    while (temp)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    cout << string(30, '-') << endl;
    vector<int> vect = {2, 4, 6, 8, 10, 12};
    Node<int> *head = array2DoublyLinkedList(vect);
    printDoublyLinkedList(head);
    cout << endl
         << string(30, '-') << endl;
    return 0;
}