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
Node<int> *deleteHead(Node<int> *head)
{
    if (head == nullptr)
        return nullptr;
    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    Node<int> *previous = head;
    head = head->next;
    head->previous = nullptr;
    previous->next = nullptr;
    delete previous;
    return head;
}
Node<int> *deleteTail(Node<int> *head)
{
    if (head == nullptr)
        return nullptr;
    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    Node<int> *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    Node<int> *previous = temp->previous;
    previous->next = nullptr;
    temp->previous = nullptr;
    delete temp;
    return head;
}
Node<int> *deleteKthNode(Node<int> *head, int k)
{
    if (head == nullptr)
        return head;
    if (k == 1)
    {
        Node<int> *previous = head;
        head = head->next;
        previous->next = nullptr;
        if (head != nullptr)
            head->previous = nullptr;
        delete previous;
        return head;
    }
    int count = 1;
    Node<int> *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
        if (count == k)
        {
            Node<int> *previous = temp->previous;
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
    // head = deleteHead(head);
    // printDoublyLinkedList(head);
    // head = deleteTail(head);
    // printDoublyLinkedList(head);
    head = deleteKthNode(head, 0);
    printDoublyLinkedList(head);
    cout << endl
         << string(30, '-') << endl;
    return 0;
}