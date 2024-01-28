#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int listLength(ListNode *head)
{
    int length = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *current_node = head;
    ListNode *Nth_node = head;
    ListNode *Nth_last_node = NULL;
    int counter = 1;
    while (current_node->next != NULL)
    {
        current_node = current_node->next;
        counter++;
        if (counter > n)
        {
            Nth_last_node = Nth_node;
            Nth_node = Nth_node->next;
        }
    }
    if (Nth_node == head)
    {
        head = head->next;
        delete Nth_node;
        return head;
    }
    if (Nth_last_node == NULL)
        return NULL;
    Nth_last_node->next = Nth_node->next;
    delete Nth_node;
    return head;
}
//-------------------------------------------------------
// ListNode *removeNthFromEnd(ListNode *head, int n)
// {
//     int length = listLength(head);
//     if (length == 1)
//         return NULL;
//     if ((length - n) == 0)
//     {
//         ListNode *deletion_node = head;
//         head = head->next;
//         delete deletion_node;
//         return head;
//     }
//     int Nth_last_node = 1;
//     ListNode *temp = head;
//     while (Nth_last_node < (length - n))
//     {
//         temp = temp->next;
//         Nth_last_node++;
//     }
//     ListNode *temp2;
//     temp2 = temp->next;
//     temp->next = temp->next->next;
//     delete temp2;
//     return head;
// }
//--------------------------------------------------
void printIthNode(ListNode *head, int index)
{
    // ListNode *temp = head;
    // if (index < 0)
    // {
    //     cout << -1 << endl;
    // }
    // int length = listLength(head);
    // if (index > length - 1)
    // {
    //     cout << "Invalid Index" << endl;
    // }
    //-------------------------
    // while (index > 0)
    // {
    //     temp = temp->next;
    //     index--;
    // }
    // cout << temp->val << endl;
    //--------------------------
    // int counter = 0;
    // while (counter < index)
    // {
    //     temp = temp->next;
    //     counter++;
    // }
    // cout << temp->val << endl;
    //---------------------------------
    if (index < 0)
    {
        cout << "-1" << endl;
        return;
    }
    int count = 0;
    while (count < index && head != NULL)
    {
        head = head->next;
        count++;
    }
    if (head != NULL)
        cout << head->val << endl;
    else
        cout << "-1" << endl;
}
ListNode *insert_at_Ith_index(ListNode *head, int data, int index)
{
    if (index < 0)
    {
        cout << "Index can't be negative!" << endl;
        return head;
    }
    // int length = listLength(head);
    // if (index > length)
    // {
    //     cout << "Index is not valid!" << endl;
    //     return head;
    // }
    ListNode *newNode = new ListNode(data);
    if (index == 0)
    {
        newNode->next = head;
        return newNode;
    }
    int index_counter = 0;
    ListNode *temp = head;
    while (index_counter < index - 1 && temp != NULL)
    {
        temp = temp->next;
        index_counter++;
    }
    if (temp == NULL)
    {
        cout << "Index is not valid!" << endl;
        return head;
    }
    // newNode->next = temp->next;
    // temp->next = newNode;
    //---------- 2nd Approach--------------
    ListNode *copyNode = temp->next;
    temp->next = newNode;
    newNode->next = copyNode;
    return head;
}
ListNode *deleteIthNode(ListNode *head, int index)
{
    if (head == NULL)
    {
        return head;
    }
    if (index < 0)
    {
        cout << "Invalid Index!" << endl;
        return head;
    }
    ListNode *temp = head;
    int index_counter = 0;
    if (index == 0)
    {
        head = head->next;
        temp->next = NULL;
        delete temp;
        return head;
    }
    // while (index_counter < (index - 1) && temp->next != NULL)
    while (index_counter != (index - 1) && temp->next != NULL)
    {
        temp = temp->next;
        index_counter++;
    }
    if (temp->next == NULL)
    {
        cout << "Invalid Index!" << endl;
        return head;
    }
    ListNode *target = temp->next;
    temp->next = temp->next->next;
    target->next = NULL;
    delete target;
    return head;
}
int lengthRecursively(ListNode *node)
{
    // Base Case
    if (node == NULL)
        return 0;
    // Recursive Case
    int small_answer = lengthRecursively(node->next);
    // Calculation
    return 1 + small_answer;
}
bool isElementPresent(ListNode *node, int element)
{
    if (node == NULL)
        return false;
    if (node->val == element)
        return true;
    return isElementPresent(node->next, element);
}
ListNode *findMid(ListNode *head)
{
    ListNode *temp = head;
    int index_counter = 0;
    if (temp->next != NULL)
    {
        index_counter = 1;
    }
    ListNode *middleNode = head;
    while (temp != NULL)
    {
        temp = temp->next;
        index_counter++;
        if (index_counter % 2 != 0)
            middleNode = middleNode->next;
    }
    return middleNode;
}
int main()
{
    ListNode *head = NULL;
    ListNode *n1 = new ListNode(1);
    head = n1;
    ListNode *n2 = new ListNode(2);
    n1->next = n2;
    ListNode *n3 = new ListNode(3);
    n2->next = n3;
    // ListNode *n4 = new ListNode(4);
    // n3->next = n4;
    // ListNode *n5 = new ListNode(5);
    // n4->next = n5;

    // head = removeNthFromEnd(head, 2);
    // printList(head);
    // printIthNode(head, 5);
    // insert_at_Ith_index(head, 10, 3);
    // head = deleteIthNode(head, 2);
    // printList(head);

    // cout << "Length of the linked-list is : " << lengthRecursively(head) << endl;
    // cout << "Element present : " << isElementPresent(head, 0) << endl;

    ListNode *middleNode = findMid(head);
    cout << middleNode->val << endl;
}

//------------------------------------------------------------
// class Node
// {
// public:
//     int data;
//     Node *next;

//     // Node(int data)
//     // {
//     //     this->data = data;
//     //     this->next = NULL;
//     // }
//     Node(int x) : data(x), next(nullptr) {}
//     Node(int x, Node *next) : data(x), next(next) {}
// };
// //----------------------------------------------------
// Node *takeInput()
// {
//     Node *headNode = NULL;
//     Node *tailNode = NULL;
//     int data;
//     cout << "Enter An Element : ";
//     cin >> data;
//     while (data != -1)
//     {
//         Node *newNode = new Node(data);
//         if (headNode == NULL)
//         {
//             headNode = newNode;
//             tailNode = headNode;
//         }
//         else
//         {
//             tailNode->next = newNode;
//             tailNode = tailNode->next;
//             // tailNode = newNode;
//         }
//         cout << "Enter An Element : ";
//         cin >> data;
//     }
//     // printList(headNode);
//     return headNode;
// }
// //----------------------------------------
// void printList(Node *head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << "  ";
//         temp = temp->next;
//     }
//     cout << "NULL" << endl;
// }
// //-----------------------------------------
// // Node *takeInput()
// // {
// //     Node *headNode = NULL;
// //     int data;
// //     cout << "Enter An Element : ";
// //     cin >> data;
// //     while (data != -1)
// //     {
// //         Node *newNode = new Node(data);
// //         if (headNode == NULL)
// //         {
// //             headNode = newNode;
// //         }
// //         else
// //         {
// //             newNode->next = headNode;
// //             headNode = newNode;
// //         }
// //         cout << "Enter An Element : ";
// //         cin >> data;
// //     }
// //     return headNode;
// // }
// //-----------------------------------
// // Node *takeInput()
// // {
// //     Node *headNode = NULL;
// //     Node *tailNode = NULL;
// //     int data;
// //     cout << "Enter An Element : ";
// //     cin >> data;
// //     while (data != -1)
// //     {
// //         // Node *newNode = new Node(data);
// //         Node newNode(data); //  We can't use Static Memory Allocation
// //         // Because the scope of the allocated memory is inside the block only.
// //         // So after every iteration the allocated memory is vanished out/Deleted.
// //         // A newely creted Node is valid only one iteration
// //         if (headNode == NULL)
// //         {
// //             headNode = &newNode;
// //             cout << headNode->data << endl;
// //             tailNode = headNode;
// //         }
// //         else
// //         {
// //             tailNode->next = &newNode;
// //             cout << headNode->data << endl;
// //             tailNode = tailNode->next;
// //         }
// //         cout << "Enter An Element : ";
// //         cin >> data;
// //     }
// //     cout << headNode->data;
// //     return headNode;
// // }
// //-----------------------------------
// int listLength(Node *head)
// {
//     Node *temp = head;
//     int length = 0;
//     while (temp != NULL)
//     {
//         length++;
//         temp = temp->next;
//     }
//     return length;
// }
// int print_ith_node(Node *head, int index)
// {
//     Node *temp = head;
//     while (index > 0)
//     {
//         temp = temp->next;
//         index--;
//     }
//     return temp->data;
// }
// Node* findMid(Node *head)
// {

// }
// // int main()
// // {
// //     Node *head = NULL;
// //     head = takeInput();
// //     printList(head);
// //     cout << "Length of the linked list is : " << listLength(head) << endl;
// //     int ith = 4;
// //     cout << ith << " Node value is : " << print_ith_node(head, ith) << endl;
// // }

// //------------------------------------------------------------------------------------------------
// // // void printList(Node *head)
// // // {
// // //     while (head != NULL)
// // //     {
// // //         cout << head->data << "  ";
// // //         head = head->next;
// // //     }
// // //     cout << "NULL" << endl;
// // // }
// // void printList(Node *&head)
// // {
// //     while (head != NULL)
// //     {
// //         cout << head->data << "  ";
// //         head = head->next;
// //     }
// //     cout << "NULL" << endl;
// // }
// // //----------------------------------
// // // void reverse_list(Node *head)
// // // {
// // //     Node *result_head = head;
// // //     Node *temp = head;
// // //     int length = 0;
// // //     while (temp != NULL)
// // //     {
// // //         length++;
// // //         temp = temp->next;
// // //     }
// // //     cout << length << endl;
// // //     int left = 0, right = length - 1;
// // //     int counter;
// // //     while (left < right)
// // //     {
// // //         counter = 0;
// // //         temp = result_head;
// // //         while (counter < right)
// // //         {
// // //             temp = temp->next;
// // //             counter++;
// // //         }
// // //         int tempData = head->data;
// // //         head->data = temp->data;
// // //         temp->data = tempData;
// // //         head = head->next;
// // //         left++;
// // //         right--;
// // //     }
// // //     printList(result_head);
// // // }
// // //----------------------------------------
// // void reverse_list(Node *head)
// // {
// //     Node *previous = NULL;
// //     Node *current = head;
// //     while (current)
// //     {
// //         // store the next step
// //         Node *current_next = current->next;
// //         // current next points to previous
// //         current->next = previous;
// //         // preparting the next step
// //         // now, previvious is the current
// //         previous = current;
// //         current = current_next;
// //     }
// //     printList(previous);
// // }
// // int main()
// // {
// //     // Statically Memory Allocation
// //     Node n1(1);
// //     Node *head = &n1;
// //     Node n2(2);
// //     n1.next = &n2;
// //     // Dynamically Memory Allocation
// //     Node *n3 = new Node(3);
// //     n2.next = n3;
// //     Node *n4 = new Node(4);
// //     // n3->next = n4;
// //     (*n3).next = n4;
// //     Node *n5 = new Node(5);
// //     // n4->next = n5;
// //     (*n4).next = n5;
// //     Node *n6 = new Node(6);
// //     (*n5).next = n6;
// //     reverse_list(head);
// //     // cout << (*head).data;
// //     // printList(head); // Pass By Value
// //     // printList(head); // Pass by Reference
// //     // cout << head->data << endl;
// // }