#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int val) : val(val), next(nullptr){};
    ListNode(int val, ListNode *next) : val(val), next(next){};
};
ListNode *takeInput()
{
    ListNode *headNode = NULL;
    ListNode *tailNode = NULL;
    int data;
    cout << "Enter An Element : ";
    cin >> data;
    while (data != -1)
    {
        ListNode *newNode = new ListNode(data);
        // ListNode newNode(data);
        // We can't use Static Memory Allocation
        // Because the scope of the allocated memory is inside the block only.
        // So after every iteration the allocated memory is vanished out/Deleted.
        // A newely created Node is valid only one iteration
        if (headNode == NULL)
        {
            headNode = newNode;
            tailNode = headNode;
        }
        else
        {
            tailNode->next = newNode;
            tailNode = tailNode->next;
        }
        cout << "Enter An Element : ";
        cin >> data;
    }
    return headNode;
}
void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
//------------------------------------------------------------------- 2. Add Two Numbers ----------------------------------------------------------------------
// ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
// {
//     if (l1 == NULL)
//         return l2;
//     if (l2 == NULL)
//         return l1;
//     ListNode *list1 = l1, *list2 = l2;
//     int carry = 0, totalValue = 0;
//     while (list1->next != NULL && list2->next != NULL)
//     {
//         totalValue = list1->val + list2->val + carry;
//         list1->val = totalValue % 10;
//         carry = totalValue / 10;
//         list1 = list1->next;
//         list2 = list2->next;
//     }
//     if (list1->next == NULL && list2->next == NULL)
//     {
//         totalValue = list1->val + list2->val + carry;
//         list1->val = totalValue % 10;
//         carry = totalValue / 10;
//         if (carry > 0)
//         {
//             ListNode *newNode = new ListNode(carry);
//             list1->next = newNode;
//         }
//     }
//     else if (list1->next == NULL)
//     {
//         totalValue = list1->val + list2->val + carry;
//         list1->val = totalValue % 10;
//         carry = totalValue / 10;
//         list1->next = list2->next;
//         list1 = list1->next;
//         while (list1->next != NULL)
//         {
//             totalValue = list1->val + carry;
//             list1->val = totalValue % 10;
//             carry = totalValue / 10;
//             list1 = list1->next;
//         }
//         totalValue = list1->val + carry;
//         list1->val = totalValue % 10;
//         carry = totalValue / 10;
//         if (carry > 0)
//         {
//             ListNode *newNode = new ListNode(carry);
//             list1->next = newNode;
//         }
//         list1 = list1->next;
//     }
//     else if (list2->next == NULL)
//     {
//         totalValue = list1->val + list2->val + carry;
//         list1->val = totalValue % 10;
//         carry = totalValue / 10;
//         list1 = list1->next;
//         while (list1->next != NULL)
//         {
//             totalValue = list1->val + carry;
//             list1->val = totalValue % 10;
//             carry = totalValue / 10;
//             list1 = list1->next;
//         }
//         totalValue = list1->val + carry;
//         list1->val = totalValue % 10;
//         carry = totalValue / 10;
//         if (carry > 0)
//         {
//             ListNode *newNode = new ListNode(carry);
//             list1->next = newNode;
//         }
//     }
//     return l1;
// }
//-----------------------------------------------------
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *temp = NULL;
    ListNode *resultHead = NULL;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry)
    {
        int sum = 0;
        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += carry;
        carry = sum / 10;
        ListNode *newNode = new ListNode(sum % 10);
        if (temp == NULL)
        {
            temp = newNode;
            resultHead = temp;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return resultHead;
}
int main()
{
    ListNode *list1 = takeInput();
    ListNode *list2 = takeInput();
    list1 = addTwoNumbers(list1, list2);
    printList(list1);
}
//------------------------------------------------------------------- 328. Odd Even Linked List ----------------------------------------------------------------------
// ListNode *oddEvenList(ListNode *head)
// {
//     if(head == NULL || head->next == NULL || head->next->next == NULL)
//         return head;
//     ListNode *oddList = head, *evenList = head->next, *current = head->next->next;
//     ListNode *evenListHead = evenList;
//     while (current != NULL)
//     {
//         oddList->next = current;
//         current = current->next;
//         if(current == NULL){
//             oddList = oddList->next;
//             evenList->next = NULL;
//             break;
//         }
//         evenList->next = current;
//         oddList = oddList->next;
//         evenList = evenList->next;
//         current = current->next;
//     }
//     oddList->next = evenListHead;
//     return head;
// }
// int main()
// {
//     ListNode *head = takeInput();
//     head = oddEvenList(head);
//     printList(head);
// }

//------------------------------------------------------------------- 24. Swap Nodes in Pairs ----------------------------------------------------------------------
// ListNode *swapPairs(ListNode *head)
// {
//     ListNode *helper, *leftNode, *rightNode;
//     if (head == NULL)
//         return NULL;
//     if (head->next == NULL)
//         return head;
//     leftNode = head, rightNode = head->next;
//     if (rightNode->next == NULL)
//     {
//         leftNode->next = rightNode->next;
//         rightNode->next = leftNode;
//         head = rightNode;
//         return head;
//     }
//     while (rightNode != NULL)
//     {
//         if (leftNode == head)
//         {
//             leftNode->next = rightNode->next;
//             rightNode->next = leftNode;
//             head = rightNode;
//         }
//         else
//         {
//             helper->next = rightNode;
//             leftNode->next = rightNode->next;
//             rightNode->next = leftNode;
//         }
//         helper = leftNode;
//         if (helper->next == NULL)
//             return head;
//         leftNode = helper->next;
//         rightNode = leftNode->next;
//     }
//     return head;
// }
//---------------------------------------------
// ListNode *swapPairs(ListNode *head)
// {
//     if(head == NULL || head->next == NULL)
//         return head;
//     ListNode *helper = head->next;
//     head->next = swapPairs(helper->next);
//     helper->next = head;
//     return helper;
// }
// int main()
// {
//     ListNode *head = takeInput();
//     head = swapPairs(head);
//     printList(head);
// }
//------------------------------------------------------------- 19. Remove Nth Node From End of List----------------------------------------------------------------
// ListNode *removeNthFromEnd(ListNode *head, int n)
// {
//     if (head == NULL)
//         return NULL;
//     int counter = 1;
//     ListNode *current = head, *targetNode = NULL, *targetPrevous = NULL;
//     while (current != NULL)
//     {
//         if (counter >= n)
//         {
//             if (targetNode == NULL)
//             {
//                 targetNode = head;
//                 targetPrevous = NULL;
//             }
//             else
//             {
//                 targetPrevous = targetNode;
//                 targetNode = targetNode->next;
//             }
//         }
//         current = current->next;
//         counter++;
//     }
//     if (targetPrevous == NULL)
//     {
//         return targetNode->next;
//     }
//     targetPrevous->next = targetNode->next;
//     delete targetNode;
//     return head;
// }
// int main()
// {
//     ListNode *head = takeInput();
//     removeNthFromEnd(head, 1);
//     printList(head);
// }
//-------------------------------------------------------- 21. Merge Two Sorted Lists ---------------------------------------------------------
// ListNode *helperFunction(ListNode *l1, ListNode *l2)
// {
//     ListNode *helper;
//     while (l1 != NULL && l2 != NULL && l2->val <= l1->val)
//     {
//         helper = l2;
//         l2 = l2->next;
//         helper->next = l1;
//         l1 = helper;
//     }
//     ListNode *firstNode = l1;
//     while (l1 != NULL && l1->next != NULL && l2 != NULL)
//     {
//         if (l2->val >= l1->val && l2->val <= l1->next->val)
//         {
//             helper = l1->next;
//             l1->next = l2;
//             l1 = l1->next;
//             l2 = l2->next;
//             l1->next = helper;
//         }
//         else
//             l1 = l1->next;
//     }
//     if (l2 != NULL)
//         l1->next = l2;
//     return firstNode;
// }
// ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
// {
//     ListNode *head = NULL;
//     int list1Length = 0;
//     int list2Length = 0;
//     ListNode *temp1 = list1, *temp2 = list2;
//     while (temp1 != NULL || temp2 != NULL)
//     {
//         if (temp1 != NULL)
//         {
//             list1Length++;
//             temp1 = temp1->next;
//         }
//         if (temp2 != NULL)
//         {
//             list2Length++;
//             temp2 = temp2->next;
//         }
//     }
//     if (list1Length >= list2Length)
//         head = helperFunction(list1, list2);
//     else
//         head = helperFunction(list2, list1);
//     return head;
// }
//----------------------------------------------------- 141. Linked List Cycle -------------------------------------------------------------
// bool hasCycle(ListNode *head)
// {
//     if (head == NULL)
//         return false;
//     unordered_map<ListNode *, int> visitedNodes;
//     ListNode *helper = head;
//     while (helper != NULL)
//     {
//         if (visitedNodes.count(helper))
//             return true;
//         visitedNodes[helper]++;
//         helper = helper->next;
//     }
//     return false;
// }
// ----------------- TWO POINTER -------------------------
// bool hasCycle(ListNode *head)
// {
//     if (head == NULL)
//         return false;
//     ListNode *slowPointer = head;
//     if (head->next == NULL)
//         return false;
//     ListNode *fastPointer = head;
//     while (slowPointer != NULL && (fastPointer != NULL && (fastPointer->next != NULL)))
//     {
//         slowPointer = slowPointer->next;
//         fastPointer = fastPointer->next->next;
//         if(slowPointer == fastPointer)
//             return true;
//     }
//     return false;
// }
//-------------------- USING RECURSION -------------------------
// bool findCycle(ListNode *slowPointer, ListNode *fastpointer)
// {
//     if (slowPointer == NULL)
//         return false;
//     if (fastpointer == NULL || fastpointer->next == NULL)
//         return false;
//     if (slowPointer == fastpointer)
//         return true;
//     return findCycle(slowPointer->next, fastpointer->next->next);
// }
// bool hasCycle(ListNode *head)
// {
//     if (head == NULL)
//         return false;
//     ListNode *slowPointer = head;
//     if (head->next == NULL)
//         return false;
//     ListNode *fastPointer = head;
//     return findCycle(slowPointer, fastPointer->next->next);
// }
//--------------------------------------------------------------------- 206. Reverse Linked List ----------------------------------------------------------------
// ListNode *reverseList(ListNode *head)
// {
//     ListNode *helper, *current = head;
//     while (current != NULL && current->next != NULL)
//     {
//         helper = current->next;
//         current->next = helper->next; // current->next = current->next->next;
//         helper->next = head;
//         head = helper;
//     }
//     return head;
// }
//------------------------------------------------------
// ListNode *reverseList(ListNode *head)
// {
//     ListNode *helper, *current = head, *newHead = NULL;
//     while (current != NULL)
//     {
//         if (newHead == NULL)
//         {
//             newHead = current;
//             current = current->next;
//             newHead->next = NULL;
//         }
//         else
//         {
//             helper = current;
//             current = current->next;
//             helper->next = newHead;
//             newHead = helper;
//         }
//     }
//     return newHead;
// }
//----------------------------------------------------------------- 876. Middle of the Linked List ---------------------------------------------------------------------
// ListNode *middleNode(ListNode *head)
// {
//     if (head == NULL)
//         return head;
//     ListNode *slowPointer = head, *fastPointer = head;
//     while (fastPointer != NULL && fastPointer->next != NULL)
//     {
//         slowPointer = slowPointer->next;
//         fastPointer = fastPointer->next->next;
//     }
//     return slowPointer;
// }
//------------------------------------------------------------------ 234. Palindrome Linked List -----------------------------------------------------------
// bool isPalindrome(ListNode *head)
// {
//     if (head->next == NULL)
//         return true;
//     ListNode *reversedHead = NULL, *current = head, *helper;
//     while (current != NULL)
//     {
//         if (reversedHead == NULL)
//         {
//             reversedHead = new ListNode(current->val);
//             current = current->next;
//             reversedHead->next = NULL;
//         }
//         else
//         {
//             helper = new ListNode(current->val);
//             current = current->next;
//             helper->next = reversedHead;
//             reversedHead = helper;
//         }
//     }
//     helper = head;
//     while (reversedHead != NULL)
//     {
//         if(helper->val != reversedHead->val)
//             return false;
//         helper = helper->next;
//         reversedHead = reversedHead->next;
//     }
//     return true;
// }
//------------------------------------------------------------------
// bool helperFunction(ListNode *firstHalf, ListNode *secondHalf)
// {
//     ListNode *current = secondHalf, *helper;
//     while (current != NULL && current->next != NULL)
//     {
//         helper = current->next;
//         current->next = helper->next;
//         helper->next = secondHalf;
//         secondHalf = helper;
//     }
//     while (secondHalf != NULL)
//     {
//         if(firstHalf->val != secondHalf->val)
//             return false;
//         firstHalf = firstHalf->next;
//         secondHalf = secondHalf->next;
//     }
//     return true;
// }
// bool isPalindrome(ListNode *head)
// {
//     if (head == NULL || head->next == NULL)
//         return true;
//     ListNode *slowPointer = head, *fastPointer = head;
//     while (fastPointer != NULL && fastPointer->next != NULL)
//     {
//         slowPointer = slowPointer->next;
//         fastPointer = fastPointer->next->next;
//     }
//     if (fastPointer == NULL)
//         return helperFunction(head, slowPointer);
//     return helperFunction(head, slowPointer->next);
// }
// int main()
// {
//     // ListNode *list1 = takeInput();
//     // ListNode *list2 = takeInput();
//     // list1 = mergeTwoLists(list1, list2);
//     ListNode *first = new ListNode(1);
//     ListNode *second = new ListNode(2);
//     ListNode *third = new ListNode(3);
//     ListNode *fourth = new ListNode(2);
//     ListNode *fifth = new ListNode(1);
//     ListNode *sixth = new ListNode(6);

//     first->next = second;
//     second->next = third;
//     third->next = fourth;
//     fourth->next = fifth;
//     fifth->next = NULL;
//     sixth->next = NULL;
//     cout << "Palindrome Linked List : " << isPalindrome(first) << endl;
//     return 1;
// }
//------------------------------------------------------------- 146. LRU ( Least Recently Used (LRU) cache) Cache (DOUBLY LINKED LIST)----------------------------------------------------------------
// class DLinkNode
// {
// public:
//     int key, value;
//     DLinkNode *previous;
//     DLinkNode *next;
//     DLinkNode() : key(0), value(0), previous(NULL), next(NULL){};
//     DLinkNode(int key, int value) : key(key), value(value), previous(NULL), next(NULL){};
// };
// class LRUCache
// {
//     DLinkNode *head, *tail, *helper;
//     unordered_map<int, DLinkNode *> container;
//     int capacity;

// public:
//     LRUCache(int capacity)
//     {
//         this->capacity = capacity;
//         head = new DLinkNode();
//         tail = new DLinkNode();
//         head->next = tail;
//         tail->previous = head;
//     }
//     int get(int key)
//     {
//         if (container.count(key))
//         {
//             helper = container.at(key);
//             helper->previous->next = helper->next;
//             helper->next->previous = helper->previous;
//             DLinkNode *temp = head->next;
//             head->next = helper;
//             helper->previous = head;
//             helper->next = temp;
//             temp->previous = helper;
//             return container.at(key)->value;
//         }
//         return -1;
//     }
//     void put(int key, int value)
//     {
//         if (!container.count(key))
//         {
//             if (container.size() >= capacity)
//             {
//                 DLinkNode *temp = tail->previous;
//                 helper = temp->previous;
//                 helper->next = tail;
//                 tail->previous = helper;
//                 container.erase(temp->key);
//                 delete temp;
//             }
//             DLinkNode *newNode = new DLinkNode(key, value);
//             helper = head->next;
//             head->next = newNode;
//             newNode->previous = head;
//             newNode->next = helper;
//             helper->previous = newNode;
//             container.insert(pair<int, DLinkNode *>(key, newNode));
//         }
//         else
//         {
//             helper = container.at(key);
//             helper->value = value;
//             helper->previous->next = helper->next;
//             helper->next->previous = helper->previous;
//             DLinkNode *temp = head->next;
//             head->next = helper;
//             helper->previous = head;
//             helper->next = temp;
//             temp->previous = helper;
//         }
//     }
// };
// int main()
// {
//     LRUCache *cache = new LRUCache(2);
//     cache->put(1, 1);
//     cache->put(2, 2);
//     cout << cache->get(1) << endl;
//     cache->put(3, 3);
//     cout << cache->get(2) << endl;
//     cache->put(4, 4);
//     cout << cache->get(1) << endl;
//     cout << cache->get(3) << endl;
//     cout << cache->get(4) << endl;
//     return 1;
// }
