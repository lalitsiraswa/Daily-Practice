#include <bits/stdc++.h>
using namespace std;

// ----------------------------- Day-1 : Valid Palindrome -------------------------------
bool IsPalindrome(const string &inputString)
{
    // Write your code here
    size_t leftPointer = 0, rightPointer = inputString.size() - 1;
    while (leftPointer < rightPointer)
    {
        if (inputString.at(leftPointer) != inputString.at(rightPointer))
            return false;
        leftPointer++;
        rightPointer--;
    }
    return true;
}
// -------------------------------- Day-2 : Sum of Three Values ----------------------------------
bool FindSumOfThree(vector<int> &nums, const int &target)
{
    // Replace this placeholder return statement with your code
    sort(nums.begin(), nums.end());
    int leftPointer = 0, rightPointer = nums.size() - 1;
    while (leftPointer < rightPointer - 1)
    {
        bool flag = true;
        for (int helper = leftPointer + 1; helper < rightPointer; helper++)
        {
            if (nums.at(leftPointer) + nums.at(helper) + nums.at(rightPointer) == target)
                return true;
            if (nums.at(leftPointer) + nums.at(helper) + nums.at(rightPointer) > target)
            {
                rightPointer--;
                flag = false;
                break;
            }
        }
        if (flag)
            leftPointer++;
    }
    return false;
}
bool FindSumOfThreeOtherWay(std::vector<int> nums, int target)
{
    // Sort the input vector
    sort(nums.begin(), nums.end());
    // Fix one integer at a time and find the other two
    for (int i = 0; i < (nums.size() - 2); i++)
    {
        // Initialize the two pointers
        int low = i + 1;
        int high = nums.size() - 1;
        // Traverse the vector to find the triplet whose sum equals the target
        while (low < high)
        {
            int triple = nums[i] + nums[low] + nums[high];
            // The sum of the triplet equals the target
            if (triple == target)
                return true;
            // The sum of the triplet is less than target, so move the low pointer forward
            else if (triple < target)
                low += 1;
            // The sum of the triplet is greater than target, so move the high pointer backward
            else
                high -= 1;
        }
    }
    // No such triplet found whose sum equals the given target
    return false;
}
// ------------------------------------ DAY-3 : Remove nth Node from End of List ---------------------------
// template <typename T>
// class ListNode
// {
// public:
//     T data;
//     ListNode *next;
//     ListNode(T data) : data(data), next(nullptr){};
// };
// ListNode<int> *takeListInput(int capacity)
// {
//     ListNode<int> *head = NULL, *currentNode = NULL;
//     for (int i = 1; i <= capacity; i++)
//     {
//         int data;
//         cout << "Enter '" << i << "' Node Data : ";
//         cin >> data;
//         ListNode<int> *newNode = new ListNode<int>(data);
//         if (head == NULL)
//         {
//             head = newNode;
//             currentNode = head;
//         }
//         currentNode->next = newNode;
//         currentNode = currentNode->next;
//     }
//     return head;
// }
// void printList(ListNode<int> *head)
// {
//     ListNode<int> *temp = head;
//     cout << string(50, '-') << endl;
//     while (temp != NULL)
//     {
//         cout << temp->data << " -> ";
//         temp = temp->next;
//     }
//     cout << "NULL" << endl;
//     cout << string(50, '-') << endl;
// }
// ListNode<int> *RemoveNthLastNode(ListNode<int> *head, int n)
// {
//     // Replace this placeholder return statement with your code
//     ListNode<int> *currentNode = head;
//     ListNode<int> *target = head;
//     ListNode<int> *targetPrevious = NULL;
//     int counter = 1;
//     while (currentNode->next != NULL)
//     {
//         if (counter < n)
//         {
//             currentNode = currentNode->next;
//             counter++;
//             continue;
//         }
//         if (counter >= n)
//         {
//             currentNode = currentNode->next;
//             targetPrevious = target;
//             target = target->next;
//             counter++;
//         }
//     }
//     if (targetPrevious == NULL || counter == n)
//     {
//         target = head;
//         head = head->next;
//     }
//     else
//         targetPrevious->next = target->next;
//     delete target;
//     return head;
// }
// ListNode<int> *RemoveNthLastNodeOtherWay(ListNode<int> *head, int n)
// {
//     // Replace this placeholder return statement with your code
//     ListNode<int> *currentNode = head;
//     ListNode<int> *target = NULL;
//     ListNode<int> *targetPrevious = NULL;
//     for (int i = 2; i <= n; i++)
//         currentNode = currentNode->next;
//     while (currentNode->next != NULL)
//     {
//         if (targetPrevious == NULL)
//         {
//             targetPrevious = head;
//             currentNode = currentNode->next;
//             continue;
//         }
//         currentNode = currentNode->next;
//         targetPrevious = targetPrevious->next;
//     }
//     if (targetPrevious == NULL)
//     {
//         target = head;
//         head = head->next;
//     }
//     else
//     {
//         target = targetPrevious->next;
//         targetPrevious->next = target->next;
//     }
//     delete target;
//     return head;
// }
// 23 28 10 5 67 39 70
// 32 78 65 90 12 44
// 12 15 13 16 17 14
// 10 20 30 40 50 60
// 1 2 3 4 5 6 7
//------------------------------------------- DAY-4 : Sort Colors------------------------------------------
// void sortColors(vector<int> &nums)
// {
//     int frequencyCounter[3] = {0};
//     for (auto item : nums)
//         frequencyCounter[item]++;
//     int position = 0;
//     for (int i = 0; i < frequencyCounter[0]; i++)
//         nums[position++] = 0;
//     for (int i = 0; i < frequencyCounter[1]; i++)
//         nums[position++] = 1;
//     for (int i = 0; i < frequencyCounter[2]; i++)
//         nums[position++] = 2;
// }
//------------------------------------------------
// vector<int> SortColors(std::vector<int> colors)
// {
//     // Write your code here
//     for (int leftPointer = 0; leftPointer < colors.size() - 1; leftPointer++)
//     {
//         for (int rightPointer = leftPointer + 1; rightPointer < colors.size(); rightPointer++)
//         {
//             if (colors.at(leftPointer) > colors.at(rightPointer))
//                 swap(colors.at(leftPointer), colors.at(rightPointer));
//         }
//     }
//     return colors;
// }
//-------------------------------------------------
// vector<int> SortColors(std::vector<int> &colors)
// {
//     // Write your code here
//     int redIndex = 0, whiteIndex = 0, blueIndex = colors.size() - 1;
//     while (whiteIndex <= blueIndex)
//     {
//         if (colors[whiteIndex] == 0)
//         {
//             if (colors.at(redIndex) != 0)
//                 swap(colors.at(redIndex), colors.at(whiteIndex));
//             redIndex++;
//             whiteIndex++;
//         }
//         else if (colors[whiteIndex] == 1)
//             whiteIndex++;
//         else if (colors[whiteIndex] == 2)
//         {
//             if (colors.at(blueIndex) != 2)
//                 swap(colors.at(whiteIndex), colors.at(blueIndex));
//             blueIndex--;
//         }
//     }
//     return colors;
// }
// ---------------------------------- Reverse Words in a String -----------------------------------
// string ReverseWords(string sentence)
// {
//     // Your code will replace this placeholder return statement
// string result, word;
// for (int i = 0; i < sentence.size(); i++)
// {
//     if (sentence.at(i) == ' ' && !word.empty())
//     {
//         result = " " + word + result;
//         word.clear();
//     }
//     else if (sentence.at(i) != ' ')
//         word.push_back(sentence.at(i));
// }
// result = word + result;
// return result;
// }
//---------------- DAY-5 ------------------
string ReverseWords(string sentence)
{
    // Your code will replace this placeholder return statement
    sentence += " ";
    int index = 0, senLen = sentence.size();
    while (index < (senLen - 1))
    {
        if (sentence.at(index) == ' ' && sentence.at(index + 1) == ' ')
            sentence.replace(index, 1, "");
        else
            index++;
        senLen = sentence.size();
    }
    reverse(sentence.begin(), sentence.end());
    int leftpointer = 0, rightPointer = -1;
    for (int index = 0; index < sentence.size(); index++)
    {
        if (sentence.at(index) == ' ')
        {
            reverse(sentence.begin() + leftpointer, sentence.begin() + rightPointer + 1);
            leftpointer = 0;
            rightPointer = 0;
            if (sentence.at(index + 1) != ' ')
            {
                leftpointer = index;
                rightPointer = index;
            }
        }
        else if (sentence.at(index) != ' ')
        {
            rightPointer++;
        }
    }
    reverse(sentence.begin() + leftpointer, sentence.begin() + rightPointer + 1);
    return sentence;
}
//------------------------------ Valid Palindrome II ---------------------------------
// bool validPalindrome2(string arr)
// {
//     // Write your code here
//     int leftPointer = 0, rightPointer = arr.size() - 1;
//     int charRemovedCounter = 0;
//     while (leftPointer < rightPointer)
//     {
//         if (arr.at(leftPointer) == arr.at(rightPointer))
//         {
//             leftPointer++;
//             rightPointer--;
//             continue;
//         }
//         else if (arr.at(leftPointer + 1) == arr.at(rightPointer))
//         {
//             leftPointer += 2;
//             rightPointer--;
//             charRemovedCounter++;
//         }
//         else if (arr.at(leftPointer) == arr.at(rightPointer - 1))
//         {
//             leftPointer++;
//             rightPointer -= 2;
//             charRemovedCounter++;
//         }
//         else
//             return false;
//         if (charRemovedCounter > 1)
//             return false;
//     }
//     return true;
// }
// -----------------
bool validPalindrome2(string arr)
{
    // Write your code here
    int leftPointer = 0, rightPointer = arr.size() - 1;
    while (leftPointer < rightPointer)
    {
        if (arr.at(leftPointer) == arr.at(rightPointer))
        {
            leftPointer++;
            rightPointer--;
            continue;
        }
        int left = leftPointer + 1;
        int right = rightPointer;
        while (left < right)
        {
            if (arr.at(left) != arr.at(right))
                break;
            left++;
            right--;
        }
        if (left >= right)
            return true;
        left = leftPointer;
        right = rightPointer - 1;
        while (left < right)
        {
            if (arr.at(left) != arr.at(right))
                break;
            left++;
            right--;
        }
        if (left >= right)
            return true;
        return false;
    }
    return true;
}
//  ------------------------------- DAY-6 : Fast and Slow Pointers (Floyd’s cycle detection algorithm) ---------------------------------------------
// -------------------- Happy Number ----------------------------
// bool IsHappyNumber(int n)
// {
//     map<int, int> occured;
//     int remainder = 0, sumOfProduct = 0;
//     while (n)
//     {
//         sumOfProduct = 0;
//         while (n)
//         {
//             remainder = n % 10;
//             n = n / 10;
//             sumOfProduct += (remainder * remainder);
//         }
//         if (sumOfProduct == 1)
//             return 1;
//         if (occured[sumOfProduct])
//             return false;
//         occured[sumOfProduct] = 1;
//         if (n == 0)
//             n = sumOfProduct;
//     }
//     return false;
// }
// ----------------------
int SumOfSquaredDigits(int number)
{
    int totalSum = 0;
    while (number > 0)
    {
        int digit = number % 10;
        number = floor(number / 10);
        totalSum += digit * digit;
    }
    return totalSum;
}

bool IsHappyNumber(int n)
{
    int slowPointer = n;
    int fastPointer = SumOfSquaredDigits(n);
    while (fastPointer != 1 && slowPointer != fastPointer)
    {
        slowPointer = SumOfSquaredDigits(slowPointer);
        fastPointer = SumOfSquaredDigits(SumOfSquaredDigits(fastPointer));
    }
    if (fastPointer == 1)
        return true;
    else
        return false;
}
// ------------------------------ DAY- 7 : Linked List Cycle ------------------------------
// template <typename T>
// class ListNode
// {
// public:
//     T data;
//     ListNode *next;
//     ListNode(T data) : data(data), next(nullptr){};
// };
// ListNode<int> *takeListInput(int capacity)
// {
//     ListNode<int> *head = NULL, *currentNode = NULL;
//     for (int i = 1; i <= capacity; i++)
//     {
//         int data;
//         cout << "Enter '" << i << "' Node Data : ";
//         cin >> data;
//         ListNode<int> *newNode = new ListNode<int>(data);
//         if (head == NULL)
//         {
//             head = newNode;
//             currentNode = head;
//         }
//         currentNode->next = newNode;
//         currentNode = currentNode->next;
//     }
//     return head;
// }
// void printList(ListNode<int> *head)
// {
//     ListNode<int> *temp = head;
//     cout << string(50, '-') << endl;
//     while (temp != NULL)
//     {
//         cout << temp->data << " -> ";
//         temp = temp->next;
//     }
//     cout << "NULL" << endl;
//     cout << string(50, '-') << endl;
// }
// bool DetectCycle(ListNode<int> *head)
// {
//     if (head == NULL)
//         return false;
//     ListNode<int> *slowPointer = head;
//     ListNode<int> *fastPointer = NULL;
//     if (head->next)
//         fastPointer = head->next;
//     while (fastPointer && fastPointer->next)
//     {
//         if (slowPointer == fastPointer)
//             return true;
//         slowPointer = slowPointer->next;
//         fastPointer = fastPointer->next->next;
//     }
//     return false;
// }
// bool DetectCycleOtherWay(ListNode<int> *head)
// {
//     if (head == NULL)
//         return false;
//     ListNode<int> *slowPointer = head;
//     ListNode<int> *fastPointer = head;
//     while (fastPointer && fastPointer->next)
//     {
//         slowPointer = slowPointer->next;
//         fastPointer = fastPointer->next->next;
//         if (slowPointer == fastPointer)
//             return true;
//     }
//     return false;
// }
// ------------------------------------- DAY - 7 : Middle of the Linked List ------------------------------------
// ListNode<int> *GetMiddleNode(ListNode<int> *head)
// {
//     if (head == nullptr || head->next == nullptr)
//         return head;
//     ListNode<int> *slowPointer = head;
//     ListNode<int> *fastPoint = head;
//     while (fastPoint && fastPoint->next)
//     {
//         slowPointer = slowPointer->next;
//         fastPoint = fastPoint->next->next;
//     }
//     return slowPointer;
// }
// int main()
// {
//     cout << string(50, '-') << endl;
//     ListNode<int> *head = NULL;
//     ListNode<int> *n1 = new ListNode<int>(1);
//     ListNode<int> *n2 = new ListNode<int>(2);
//     ListNode<int> *n3 = new ListNode<int>(3);
//     ListNode<int> *n4 = new ListNode<int>(4);
//     ListNode<int> *n5 = new ListNode<int>(5);
//     head = n1;
//     n1->next = n2;
//     n2->next = n3;
//     n3->next = n4;
//     // n4->next = n5;
//     printList(head);
//     ListNode<int> *middleNode = GetMiddleNode(head);
//     cout << middleNode->data << endl;
//     cout << string(50, '-') << endl;
// }
// ------------------------------ DAY-7: Circular Array Loop ------------------------------
// ------------- WRONG BUT TRIED --------------
// int returnIndex(vector<int> &nums, int &numsSize, int index)
// {
//     return (numsSize + (index + (nums[index] % numsSize))) % numsSize;
// }
// bool CircularArrayLoop(vector<int> nums)
// {
//     int numsSize = nums.size();
//     for (int index = 0; index < numsSize; index++)
//     {
//         int slowPointer = index;
//         int fastPointer = index;
//         int counter = 0;
//         while (1)
//         {
//             counter++;
//             slowPointer = returnIndex(nums, numsSize, slowPointer);
//             fastPointer = returnIndex(nums, numsSize, fastPointer);
//             fastPointer = returnIndex(nums, numsSize, fastPointer);
//             if ((counter == 1 && (index == slowPointer)) || (counter >= numsSize))
//                 break;
//             if ((index == slowPointer) && (index == fastPointer) && counter > 1)
//                 return true;
//         }
//     }
//     return false;
// }
//-----------------------
// A function to calculate the next step
int NextStep(int pointer, int value, int size)
{
    int result = (pointer + value) % size;
    if (result < 0)
        result += size;
    return result;
}

// A function to detect a cycle doesn't exist
bool IsNotCycle(std::vector<int> &nums, bool prev_direction, int pointer)
{
    int size = nums.size();
    // Set current direction to true if current element is positive, set false otherwise.
    bool curr_direction = nums[pointer] >= 0;
    // If current direction and previous direction are different or moving a pointer takes back to the same value,
    // then the cycle is not possible, we return true, otherwise return false.
    if (prev_direction != curr_direction || abs(nums[pointer] % size) == 0)
        return true;
    else
        return false;
}

bool CircularArrayLoop(vector<int> &nums)
{
    int size = nums.size();
    // Iterate through each index of the array 'nums'.
    for (int i = 0; i < size; i++)
    {
        // Set slow and fast pointer at current index value.
        int slow = i, fast = i;
        // Set true in 'forward' if element is positive, set false otherwise.
        bool forward = nums[i] > 0;
        while (true)
        {
            // Move slow pointer to one step.
            slow = NextStep(slow, nums[slow], size);
            // If cycle is not possible, break the loop and start from next element.
            if (IsNotCycle(nums, forward, slow))
                break;
            // First move of fast pointer.
            fast = NextStep(fast, nums[fast], size);
            // If cycle is not possible, break the loop and start from next element.
            if (IsNotCycle(nums, forward, fast))
                break;
            // Second move of fast pointer.
            fast = NextStep(fast, nums[fast], size);
            // If cycle is not possible, break the loop and start from next element.
            if (IsNotCycle(nums, forward, fast))
                break;
            // At any point, if fast and slow pointers meet each other,
            // it indicates that loop has been found, return true.
            if (slow == fast)
                return true;
        }
    }
    return false;
}
//---------------------------
int returnIndex(vector<int> &nums, int &numsSize, int index)
{
    return (numsSize + (index + (nums[index] % numsSize))) % numsSize;
}
// A function to detect a cycle doesn't exist
bool IsNotCycleCopy(std::vector<int> &nums, bool prev_direction, int pointer)
{
    int size = nums.size();
    // Set current direction to true if current element is positive, set false otherwise.
    bool curr_direction = nums[pointer] >= 0;
    // If current direction and previous direction are different or moving a pointer takes back to the same value,
    // then the cycle is not possible, we return true, otherwise return false.
    if (prev_direction != curr_direction || abs(nums[pointer] % size) == 0)
        return true;
    else
        return false;
}
bool CircularArrayLoopOtherWay(vector<int> nums)
{
    int numsSize = nums.size();
    for (int index = 0; index < numsSize; index++)
    {
        int slowPointer = index;
        int fastPointer = index;
        bool forward = nums[index] > 0;
        while (1)
        {
            slowPointer = returnIndex(nums, numsSize, slowPointer);
            if (IsNotCycleCopy(nums, forward, slowPointer))
                break;
            fastPointer = returnIndex(nums, numsSize, fastPointer);
            if (IsNotCycleCopy(nums, forward, fastPointer))
                break;
            fastPointer = returnIndex(nums, numsSize, fastPointer);
            if (IsNotCycleCopy(nums, forward, fastPointer))
                break;
            if (slowPointer == fastPointer)
                return true;
        }
    }
    return false;
}
// int main()
// {
//     cout << string(50, '-') << endl;
//     vector<int> nums = {2, 1, -1, -2};
//     cout << CircularArrayLoopOtherWay(nums) << endl;
//     cout << string(50, '-') << endl;
//     return 0;
// }
// ------------------------------ DAY-8: Find The Duplicate Number ---------------------------------------
// int FindDuplicate(vector<int> nums)
// {
//     // Your code will replace this placeholder return statement
//     int slowPointer = nums[0];
//     int fastPointer = nums[0];
//     while (1)
//     {
//         slowPointer = nums[slowPointer];
//         fastPointer = nums[nums[fastPointer]];
//         if (slowPointer == fastPointer)
//             break;
//     }
//     slowPointer = nums[0];
//     while (slowPointer != fastPointer)
//     {
//         slowPointer = nums[slowPointer];
//         fastPointer = nums[fastPointer];
//     }
//     return fastPointer;
// }
// -------------------------
int FindDuplicate(std::vector<int> nums)
{
    // Initialize the fast and slow pointers and make them point the first
    //  element of the array
    int fast = nums[0];
    int slow = nums[0];
    // PART 1: Traverse the array until an intersection point is found
    while (true)
    {
        // Move the slow pointer using the nums[slow] flow
        slow = nums[slow];
        //  Move the fast pointer two times fast as the slow pointer using the
        // nums[nums[fast]] flow
        fast = nums[nums[fast]];
        // Break the loop when slow pointer becomes equal to the fast pointer, i.e.,
        /// if the intersection is found
        if (slow == fast)
        {
            // if intersection point is found, break the loop
            break;
        }
    }
    // PART 2:
    // Make the slow pointer point the starting position of an array again, i.e.,
    // start the slow pointer from starting position
    slow = nums[0];
    // Traverse in the array until the slow pointer becomes equal to the
    // fast pointer
    while (slow != fast)
    {
        // Move the slow pointer using the nums[slow] flow
        slow = nums[slow];
        // Move the fast pointer slower than before, i.e., move the fast pointer
        // using the nums[fast] flow
        fast = nums[fast];
    }
    // return the fast pointer as it'll be pointing to the duplicate number in the array
    return fast;
}
// ----------------------------------- DAY-9: Palindrome Linked List ------------------------------------------
// template <typename T>
// class ListNode
// {
// public:
//     T data;
//     ListNode *next;
//     ListNode(T data) : data(data), next(nullptr){};
// };
// ListNode<int> *takeListInput(int capacity)
// {
//     ListNode<int> *head = NULL, *currentNode = NULL;
//     for (int i = 1; i <= capacity; i++)
//     {
//         int data;
//         cout << "Enter '" << i << "' Node Data : ";
//         cin >> data;
//         ListNode<int> *newNode = new ListNode<int>(data);
//         if (head == NULL)
//         {
//             head = newNode;
//             currentNode = head;
//         }
//         currentNode->next = newNode;
//         currentNode = currentNode->next;
//     }
//     return head;
// }
// void printList(ListNode<int> *head)
// {
//     ListNode<int> *temp = head;
//     cout << string(50, '-') << endl;
//     while (temp != NULL)
//     {
//         cout << temp->data << " -> ";
//         temp = temp->next;
//     }
//     cout << "NULL" << endl;
//     cout << string(50, '-') << endl;
// }
// ListNode<int> *reverseList(ListNode<int> *head)
// {
//     ListNode<int> *curr = head;
//     ListNode<int> *prev = NULL;
//     ListNode<int> *next = NULL;
//     while (curr)
//     {
//         next = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = next;
//     }
//     return prev;
// }
// bool Palindrome(ListNode<int> *head)
// {
//     if (head == NULL || !head->next)
//         return true;
//     ListNode<int> *slowPointer = head;
//     ListNode<int> *fastPointer = head;
//     while (fastPointer && fastPointer->next)
//     {
//         slowPointer = slowPointer->next;
//         fastPointer = fastPointer->next->next;
//     }
//     if (fastPointer)
//         slowPointer = slowPointer->next;
//     fastPointer = reverseList(slowPointer);
//     slowPointer = head;
//     while (fastPointer)
//     {
//         if (slowPointer->data != fastPointer->data)
//             return false;
//         fastPointer = fastPointer->next;
//         slowPointer = slowPointer->next;
//     }
//     return true;
// }
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
// 1 2 3 4 5 4 3 2 1
// 1 2 3 4 5 5 4 3 2 1
// int main()
// {
//     cout << string(40, '-') << endl;
//     ListNode<int> *head = takeListInput(9);
//     printList(head);
//     cout << Palindrome(head);
//     cout << string(40, '-') << endl;
// }
// ----------------------------------- DAY-10: Sliding Wndow (Repeated DNA Sequences)------------------------------------------
// set<string> FindRepeatedSequences(string s, int k)
// {
//     set<string> output{};
//     string dnaSequence;
//     for (int index = 0; index < s.size() - k; index++)
//     {
//         dnaSequence.push_back(s.at(index));
//         if (dnaSequence.size() < k)
//             continue;
//         int target = 0;
//         for (int j = index + 1; j < s.size(); j++)
//         {
//             if (dnaSequence.at(target) == s.at(j))
//                 target++;
//             if (target >= k)
//             {
//                 output.insert(dnaSequence);
//                 break;
//             }
//         }
//         dnaSequence.erase(0, 1);
//     }
//     return output;
// }
//-------------------
std::set<std::string> FindRepeatedSequencesOtherWay(std::string &s, int k)
{
    int n = s.length();
    if (n < k)
        return {};
    // Mapping of characters
    std::unordered_map<char, int> mapping = {{'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};
    // Base value
    int a = 4;
    // Numeric representation of the sequence
    std::vector<int> numbers(n, 0);
    for (int i = 0; i < n; i++)
        numbers[i] = mapping[s[i]];
    // Current hash value
    int hashValue = 0;
    // 1. Hash set to store the unique hash values
    // 2. Output set to store the repeated substrings
    std::set<int> hashSet;
    std::set<std::string> output;
    for (int i = 0; i < n - k + 1; i++)
    {
        // If the window is at it's initial position, calculate the hash value from scratch
        if (i == 0)
        {
            for (int j = 0; j < k; j++)
                hashValue += numbers[j] * static_cast<int>(pow(a, k - j - 1));
        }
        // Otherwise, utilize the previous hash value
        else
        {
            int previousHashValue = hashValue;
            hashValue = ((previousHashValue - numbers[i - 1] * static_cast<int>(pow(a, k - 1))) * a) + numbers[i + k - 1];
        }
        // If the current hash value is present in the hash set, the current substring has been repeated, so we add it to the output
        if (hashSet.count(hashValue) > 0)
            output.insert(s.substr(i, k));
        // We add the evaluated hash value to the hash set
        hashSet.insert(hashValue);
    }
    return output;
}
// int main()
// {
//     cout << string(40, '-') << endl;
//     string s = "ATATATATATATATAT";
//     set<string> output = FindRepeatedSequencesOtherWay(s, 5);
//     for (auto item : output)
//         cout << item << "  ";
//     cout << endl;
//     cout << string(40, '-') << endl;
// }
// ------------------------------- DAY-11: Find Maximum in Sliding Window ----------------------------------
// void arrangeInDescendingOrder(vector<int> &descOrder, int target)
// {
//     int i = 0;
//     for (i; i < descOrder.size(); i++)
//     {
//         if (target > descOrder.at(i))
//         {
//             descOrder.insert(descOrder.begin() + i, target);
//             break;
//         }
//     }
//     if (i >= descOrder.size())
//         descOrder.push_back(target);
// }
// vector<int> FindMaxSlidingWindow(vector<int> &nums, int w)
// {
// vector<int> result;
// vector<int> descOrder;
// for (int i = 0; i < w; i++)
//     arrangeInDescendingOrder(descOrder, nums.at(i));
// result.push_back(descOrder.front());
// for (int i = w; i < nums.size(); i++)
// {
//     vector<int>::iterator itr = find(descOrder.begin(), descOrder.end(), nums.at(i - w));
//     descOrder.erase(itr);
//     arrangeInDescendingOrder(descOrder, nums.at(i));
//     result.push_back(descOrder.front());
// }
// return result;
// }
//--------------------------------------------------------
// vector<int> FindMaxSlidingWindowOtherWay(vector<int> &nums, int w)
// {
//     vector<int> result;
//     set<int, greater<int>> s;
//     for (int index = 0; index < w; index++)
//         s.insert(nums.at(index));
//     result.push_back(*s.begin());
//     for (int index = w; index < nums.size(); index++)
//     {
//         s.erase(nums.at(index - w));
//         s.insert(nums.at(index));
//         result.push_back(*s.begin());
//     }
//     return result;
// }
//-------------------------- Try But Time Limit Exceed ---------------------------------
// void CleanUp(vector<int> &currentWindow, vector<int> &nums, int index)
// {
//     int i = 0, n = currentWindow.size();
//     while (i < n)
//     {
//         if (nums.at(currentWindow.at(i)) <= nums.at(index))
//         {
//             currentWindow.erase(currentWindow.begin() + i);
//             n--;
//         }
//         else
//             i++;
//     }
// }

//-------------------
// function to clean up the window
// void CleanUp(int i, std::vector<int> &currentWindow, const std::vector<int> &nums)
// {
//     // remove all the indexes from currentWindow whose corresponding values are smaller than or equal to the current element
//     while (!currentWindow.empty() && nums[i] >= nums[currentWindow.back()])
//     {
//         std::cout << "\t\tAs nums[" << i << "] = " << nums[i] << " is greater than or equal to nums[" << currentWindow.back() << "] = " << nums[currentWindow.back()] << "," << std::endl;
//         std::cout << "\t\tremove " << currentWindow.back() << " from currentWindow" << std::endl;
//         currentWindow.pop_back();
//     }
// }

// // function to find the maximum in all possible windows
// std::vector<int> FindMaxSlidingWindow(const std::vector<int> &nums, int w)
// {
//     // if the input array is empty, return an empty array
//     if (nums.empty())
//     {
//         return {};
//     }

//     // initializing variables
//     std::vector<int> output;
//     std::vector<int> currentWindow;

//     // if window size is greater than the array size, set the window size to the array size
//     if (w > nums.size())
//     {
//         w = nums.size();
//     }

//     std::cout << "\n\tFinding the maximum in the first window:" << std::endl;

//     // iterate over the first w elements
//     for (int i = 0; i < w; ++i)
//     {
//         std::cout << "\tAdding nums[" << i << "] = " << nums[i] << " to the first window:\n\t\tInitial state of currentWindow: ";
//         std::cout << "[";
//         std::copy(currentWindow.begin(), currentWindow.end(), std::ostream_iterator<int>(std::cout, " "));
//         std::cout << "]" << std::endl;

//         // for every element, remove the previous smaller elements from currentWindow
//         CleanUp(i, currentWindow, nums);

//         // append the index of the current element to currentWindow
//         currentWindow.push_back(i);
//         std::cout << "\t\tFinal state of currentWindow: ";
//         std::cout << "[";
//         std::copy(currentWindow.begin(), currentWindow.end(), std::ostream_iterator<int>(std::cout, " "));
//         std::cout << "]" << std::endl;
//     }

//     // appending the maximum element of the current window to the output list
//     output.push_back(nums[currentWindow[0]]);

//     std::cout << "\n\tFinding the maximum in the remaining windows:" << std::endl;

//     // iterate over the remaining input list
//     for (int i = w; i < nums.size(); ++i)
//     {
//         std::cout << "\tAdding nums[" << i << "] = " << nums[i] << " to currentWindow:\n\t\tInitial state of currentWindow: ";
//         std::cout << "[";
//         std::copy(currentWindow.begin(), currentWindow.end(), std::ostream_iterator<int>(std::cout, " "));
//         std::cout << "]" << std::endl;

//         // for every element, remove the previous smaller elements from currentWindow
//         CleanUp(i, currentWindow, nums);

//         // remove first index from the currentWindow if it has fallen out of the current window
//         if (!currentWindow.empty() && currentWindow[0] <= (i - w))
//         {
//             std::cout << "\t\tIndex " << currentWindow[0] << " has fallen out of the current window," << std::endl;
//             std::cout << "\t\tso, remove it" << std::endl;
//             currentWindow.erase(currentWindow.begin());
//         }

//         // append the index of the current element to currentWindow
//         std::cout << "\t\tAppending " << i << " to currentWindow" << std::endl;
//         currentWindow.push_back(i);
//         std::cout << "\t\tFinal state of currentWindow: ";
//         std::cout << "[";
//         std::copy(currentWindow.begin(), currentWindow.end(), std::ostream_iterator<int>(std::cout, " "));
//         std::cout << "]" << std::endl;

//         // adding the maximum element of the current window to the output list
//         output.push_back(nums[currentWindow[0]]);
//     }

//     // return the array containing output
//     return output;
// }
//-------------------
// void CleanUp(vector<int> &currentWindow, vector<int> &nums, int index)
// {
//     while (!currentWindow.empty() && nums.at(index) >= nums.at(currentWindow.back()))
//     {
//         currentWindow.pop_back();
//     }
// }
// vector<int> FindMaxSlidingWindowOtherWay(vector<int> &nums, int w)
// {
//     vector<int> result;
//     vector<int> currentWindow;
//     for (int index = 0; index < w; index++)
//     {
//         CleanUp(currentWindow, nums, index);
//         currentWindow.push_back(index);
//     }
//     result.push_back(nums.at(currentWindow.at(0)));
//     for (int index = w; index < nums.size(); index++)
//     {
//         CleanUp(currentWindow, nums, index);
//         currentWindow.push_back(index);
//         if (currentWindow.at(0) < index - (w - 1))
//         {
//             currentWindow.erase(currentWindow.begin());
//         }
//         result.push_back(nums.at(currentWindow.at(0)));
//     }
//     return result;
// }
//----------------------------------
void CleanUp(deque<int> &currentWindow, vector<int> &nums, int index)
{
    while (!currentWindow.empty() && nums.at(index) >= nums.at(currentWindow.back()))
        currentWindow.pop_back();
}
vector<int> FindMaxSlidingWindow(vector<int> &nums, int w)
{
    if (nums.empty())
        return {};
    vector<int> result;
    deque<int> currentWindow;
    if (w > nums.size())
        w = nums.size();
    for (int index = 0; index < w; index++)
    {
        CleanUp(currentWindow, nums, index);
        currentWindow.push_back(index);
    }
    result.push_back(nums.at(currentWindow.front()));
    for (int index = w; index < nums.size(); index++)
    {
        CleanUp(currentWindow, nums, index);
        currentWindow.push_back(index);
        if (currentWindow.front() < (index - (w - 1)))
            currentWindow.pop_front();
        result.push_back(nums.at(currentWindow.front()));
    }
    return result;
}
//-------------------------
// // function to clean up the window
// void CleanUp(int i, std::deque<int> &currentWindow, const std::vector<int> &nums)
// {
//     // remove all the indexes from currentWindow whose corresponding values are smaller than or equal to the current element
//     while (!currentWindow.empty() && nums[i] >= nums[currentWindow.back()])
//     {
//         currentWindow.pop_back();
//     }
// }

// // function to find the maximum in all possible windows
// std::vector<int> FindMaxSlidingWindow(const std::vector<int> &nums, int w)
// {
//     // if the input array is empty, return an empty array
//     if (nums.empty())
//     {
//         return {};
//     }

//     // initializing variables
//     std::vector<int> output;
//     std::deque<int> currentWindow;

//     // if window size is greater than the array size, set the window size to the array size
//     if (w > nums.size())
//     {
//         w = nums.size();
//     }

//     // iterate over the first w elements
//     for (int i = 0; i < w; ++i)
//     {
//         // for every element, remove the previous smaller elements from currentWindow
//         CleanUp(i, currentWindow, nums);

//         // append the index of the current element to currentWindow
//         currentWindow.push_back(i);
//     }

//     // appending the maximum element of the current window to the output list
//     output.push_back(nums[currentWindow[0]]);

//     // iterate over the remaining input list
//     for (int i = w; i < nums.size(); ++i)
//     {
//         // for every element, remove the previous smaller elements from currentWindow
//         CleanUp(i, currentWindow, nums);

//         // remove first index from the currentWindow if it has fallen out of the current window
//         if (!currentWindow.empty() && currentWindow[0] <= (i - w))
//         {
//             currentWindow.pop_front();
//         }

//         // append the index of the current element to currentWindow
//         currentWindow.push_back(i);

//         // adding the maximum element of the current window to the output list
//         output.push_back(nums[currentWindow[0]]);
//     }

//     // return the array containing output
//     return output;
// }
// int main()
// {
//     // cout << string(40, '-') << endl;
//     vector<int> nums = {2, 4, 3, 6, 5, 4, 1, 10};
//     vector<int> result = FindMaxSlidingWindow(nums, 3);
//     for (auto item : result)
//         cout << item << "  ";
//     // cout << string(40, '-') << endl;
// }
// --------------------------- DAY-14 : Minimum Window Subsequence -----------------------------------

string MinWindow(string str1, string str2)
{
    string minimumWindow, current;
    for (int index = 0; index < str1.size() && index <= (str1.size() - str2.size()); index++)
    {
        current = "";
        if (str1.at(index) == str2.at(0))
        {
            current.push_back(str1.at(index));
            int target = 1;
            for (int j = index + 1; j < str1.size(); j++)
            {
                current.push_back(str1.at(j));
                if (str1.at(j) == str2.at(target))
                    target++;
                if (target >= str2.size())
                {
                    if (minimumWindow.empty() || current.size() < minimumWindow.size())
                        minimumWindow = current;
                    if (minimumWindow.size() == str2.size())
                        return minimumWindow;
                    break;
                }
            }
        }
    }
    return minimumWindow;
}
// ------------------------------
// string MinWindowOtherWay(string str1, string str2)
// {
//     int indexS1 = 0, indexS2 = 0;
//     int length = INT_MAX;
//     string minSubsequence;
//     while (indexS1 < str1.size())
//     {
//         if (str1[indexS1] == str2[indexS2])
//         {
//             indexS1++;
//             indexS2++;
//         }
//         else
//             indexS1++;
//         if (indexS2 >= str2.size())
//         {
//             int start = indexS1 - 1;
//             int end = indexS1 - 1;
//             indexS2--;
//             start--;
//             indexS2--;
//             while (indexS2 >= 0)
//             {
//                 if (str1[start] == str2[indexS2])
//                 {
//                     start--;
//                     indexS2--;
//                 }
//                 else
//                     start--;
//             }
//             if ((end - start) < length)
//             {
//                 length = (end - start);
//                 minSubsequence = str1.substr(start + 1, length);
//             }
//             indexS1 = start + 2;
//             indexS2 = 0;
//         }
//     }
//     return minSubsequence;
// }
// int main()
// {
//     cout << string(40, '-') << endl;
//     cout << MinWindowOtherWay("azssstaszaztf", "saz") << endl;
//     cout << string(40, '-') << endl;
// }
// ------------------------------------------- Day-18:Longest Repeating Character Replacement------------------------------
int LongestRepeatingCharacterReplacement(const std::string &s, int k)
{
    int n = s.length(), currStrLen = 0, LongestStrLen = 0, maxCharReplacement = 0;
    for (int i = 0; i < n && ((n - i) > LongestStrLen); i++)
    {
        currStrLen = 1;
        maxCharReplacement = 0;
        for (int j = i + 1; j < n && maxCharReplacement <= k; j++)
        {
            if (s[i] == s[j])
                currStrLen++;
            else
                maxCharReplacement++;
        }
        if (currStrLen == n)
            return currStrLen;
        if (currStrLen >= n / 2)
        {
            if (n - currStrLen <= k)
                return n;
            return currStrLen + k;
        }
        LongestStrLen = max(currStrLen, LongestStrLen);
    }
    return LongestStrLen + k;
}
// ----------------
int LongestRepeatingCharacterReplacementUsingSlidingWindow(const std::string &s, int k)
{
    int stringLength = s.length();
    int lengthOfMaxSubString = 0;
    int start = 0;
    unordered_map<char, int> charFreq;
    int mostFreqChar = 0;
    for (int end = 0; end < stringLength; end++)
    {
        if (charFreq.find(s[end]) == charFreq.end())
            charFreq[s[end]] = 1;
        else
            charFreq[s[end]]++;
        mostFreqChar = max(mostFreqChar, charFreq[s[end]]);
        if (end - start + 1 - mostFreqChar > k)
        {
            charFreq[s[start]] -= 1;
            start += 1;
        }
        lengthOfMaxSubString = max(end - start + 1, lengthOfMaxSubString);
    }
    return lengthOfMaxSubString;
}
// int main()
// {
//     cout << string(40, '-') << endl;
//     string s = "aaacbbbaabab";
//     cout << LongestRepeatingCharacterReplacementUsingSlidingWindow(s, 2) << endl;
//     cout << string(40, '-') << endl;
// }

// ---------------------------------------- Day-22:Minimum Window Substring------------------------------
// ------------ Correct Nut TLE ----------------------
string MinWindowFun(string s, string t)
{
    unordered_map<char, int> charFreqOfT;
    for (int i = 0; i < t.size(); i++)
        charFreqOfT[t[i]]++;
    unordered_map<char, int> charFreqOfWindow;
    int n = s.size(), minWindow = INT_MAX;
    string minWindowString = "";
    for (int i = 0; i < n && (n - i) >= t.size(); i++)
    {
        for (int j = i; j < n; j++)
        {
            int flag = 1;
            charFreqOfWindow[s[j]]++;
            if (charFreqOfWindow[s[j]] >= charFreqOfT[s[j]])
            {
                for (int k = 0; k < t.size(); k++)
                {
                    if (charFreqOfWindow[t[k]] < charFreqOfT[t[k]])
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag && (j - i) + 1 <= minWindow)
                {
                    minWindow = (j - i) + 1;
                    minWindowString = s.substr(i, minWindow);
                    break;
                }
            }
        }
        if (minWindowString.size() == t.size())
            return minWindowString;
        charFreqOfWindow.clear();
    }
    return minWindowString;
}
// ----------------- TLE ------------------
string MinWindowOtherWay(string s, string t)
{
    unordered_map<char, int> charFreqOfT;
    for (int i = 0; i < t.size(); i++)
        charFreqOfT[t[i]]++;
    unordered_map<char, int> charFreqOfWindow;
    int n = s.size(), minWindow = INT_MAX;
    string minWindowString = "";
    int start = 0, end = 0;
    while (end < s.size())
    {
        int flag = 1;
        charFreqOfWindow[s[end]]++;
        if (charFreqOfWindow[s[end]] >= charFreqOfT[s[end]] && charFreqOfT[s[end]] > 0)
        {
            for (int k = 0; k < t.size(); k++)
            {
                if (charFreqOfWindow[t[k]] < charFreqOfT[t[k]])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                if ((end - start) + 1 <= minWindow)
                {
                    minWindow = (end - start) + 1;
                    minWindowString = s.substr(start, minWindow);
                }
                charFreqOfWindow[s[end]]--;
                charFreqOfWindow[s[start]]--;
                start++;
            }
            else
                end++;
        }
        else
            end++;
    }
    return minWindowString;
}
// -------------- TLE -----------------------
string MinWindowOtherWay2(string s, string t)
{
    unordered_map<char, int> charFreqOfT;
    for (int i = 0; i < t.size(); i++)
        charFreqOfT[t[i]]++;
    unordered_map<char, int> charFreqOfWindow;
    int n = s.size(), minWindow = INT_MAX;
    string minWindowString = "";
    int start = 0, end = 0;
    while (end < s.size())
    {
        int flag = 1;
        charFreqOfWindow[s[end]]++;
        if (charFreqOfT[s[end]] > 0 && charFreqOfWindow[s[end]] >= charFreqOfT[s[end]])
        {
            int k;
            for (k = 0; k < t.size(); k++)
            {
                if (charFreqOfWindow[t[k]] < charFreqOfT[t[k]])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0)
            {
                while (charFreqOfWindow[t[k]] >= charFreqOfT[t[k]])
                {
                    end++;
                    charFreqOfWindow[s[end]]++;
                }
            }
            if (flag)
            {
                if ((end - start) + 1 <= minWindow)
                {
                    minWindow = (end - start) + 1;
                    minWindowString = s.substr(start, minWindow);
                }
                charFreqOfWindow[s[end]]--;
                charFreqOfWindow[s[start]]--;
                start++;
                while (charFreqOfWindow[s[start]] - 1 >= charFreqOfT[s[start]])
                {
                    charFreqOfWindow[s[start]]--;
                    start++;
                }
            }
            else
                end++;
        }
        else
            end++;
    }
    return minWindowString;
}
// -----------------------------
std::string MinWindowOtherWay3(std::string s, std::string t)
{
    if (t == "")
        return "";
    std::unordered_map<char, int> reqCount;
    std::unordered_map<char, int> window;
    for (int i = 0; i < t.length(); i++)
    {
        char c = t.at(i);
        reqCount[c] = 1 + reqCount[c];
    }
    for (int i = 0; i < t.length(); i++)
    {
        char c = t.at(i);
        window[c] = 0;
    }
    int current = 0;
    int required = reqCount.size();
    std::vector<int> res = {-1, -1};
    int resLen = INT_MAX;

    int left = 0;
    for (int right = 0; right < s.length(); right++)
    {
        char c = s.at(right);
        if (t.find(c) != std::string::npos)
            window[c] = 1 + window[c];
        if (reqCount[c] && window[c] == reqCount[c])
            current += 1;
        while (current == required)
        {
            if ((right - left + 1) < resLen)
            {
                res = {left, right};
                resLen = (right - left + 1);
            }
            char leftChar = s.at(left);
            if (t.find(leftChar) != std::string::npos)
                window[leftChar] -= 1;
            if (reqCount[leftChar] && window[leftChar] < reqCount[leftChar])
                current -= 1;
            left += 1;
        }
    }
    int leftIndex = res.at(0);
    int rightIndex = res.at(1);
    return resLen != INT_MAX ? s.substr(leftIndex, resLen) : "";
}
// ----------------------
string MinWindowOtherWay4(std::string s, std::string t)
{
    if (t == "")
        return "";
    unordered_map<char, int> reqCount;
    unordered_map<char, int> window;
    for (int i = 0; i < t.size(); i++)
        reqCount[t.at(i)]++;
    int required = reqCount.size();
    int current = 0;
    int resLen = INT_MAX;
    int left = 0;
    vector<int> res = {-1, -1};
    for (int right = 0; right < s.size(); right++)
    {
        char c = s.at(right);
        if (reqCount[c])
            window[c]++;
        if (reqCount[c] && reqCount[c] == window[c])
            current++;
        while (current == required)
        {
            if (right - left + 1 < resLen)
            {
                res = {left, right};
                resLen = right - left + 1;
            }
            char c = s.at(left);
            if (reqCount[c] > 0)
                window[c]--;
            if (reqCount[c] && window[c] < reqCount[c])
                current--;
            left++;
        }
    }
    int leftIndex = res.at(0);
    return resLen != INT_MAX ? s.substr(leftIndex, resLen) : "";
}
// int main()
// {
//     cout << string(40, '-') << endl;
//     cout << MinWindowOtherWay4("ABDOEDECOBE", "BC") << endl;
//     cout << string(40, '-') << endl;
// }
//---------------------------- Longest Substring without Repeating Characters ----------------------------------------
// int FindLongestSubstring(string str)
// {
//     unordered_map<char, int> window;
//     int left = 0, right = 0, longestSubstringLength = 0;
//     for (right; right < str.size(); right++)
//     {
//         char currentChar = str.at(right);
//         window[currentChar]++;
//         if (window[currentChar] > 1)
//         {
//             if ((right - left) > longestSubstringLength)
//                 longestSubstringLength = (right - left);
//             while (window[currentChar] > 1)
//             {
//                 char c = str.at(left);
//                 window[c]--;
//                 left++;
//             }
//         }
//     }
//     if ((right - left) > longestSubstringLength)
//         longestSubstringLength = (right - left);
//     return longestSubstringLength;
// }
// -----------------------------
int FindLongestSubstringOtherWay(string str)
{
    int helperIndex = 0, n = str.length(), longestSubstringLength = 0, index = 0;
    for (index; index < n; index++)
    {
        string::iterator itr = find((str.begin() + helperIndex), str.end() - (n - index), str.at(index));
        if (itr - str.begin() < index)
        {
            if ((index - helperIndex) > longestSubstringLength)
                longestSubstringLength = index - helperIndex;
            helperIndex = itr - str.begin() + 1;
        }
    }
    if ((index - helperIndex) > longestSubstringLength)
        longestSubstringLength = index - helperIndex;
    return longestSubstringLength;
}
//-----------------------
int FindLongestSubstringOtherWay02(string str)
{
    int longestSubstringLength = 0, left = 0, index = 0;
    unordered_map<char, int> indexTrack;
    for (index; index < str.length(); index++)
    {
        char c = str.at(index);
        if (indexTrack.find(c) == indexTrack.end())
            indexTrack[c] = index;
        else if (left <= indexTrack[c] && indexTrack[c] < index)
        {
            if ((index - left) > longestSubstringLength)
                longestSubstringLength = (index - left);
            left = indexTrack[c] + 1;
            indexTrack[c] = index;
        }
        else
            indexTrack[c] = index;
    }
    if ((index - left) > longestSubstringLength)
        longestSubstringLength = (index - left);
    return longestSubstringLength;
}
// int main()
// {
//     cout << string(40, '-') << endl;
//     cout << FindLongestSubstringOtherWay02("conceptoftheday") << endl;
//     cout << string(40, '-') << endl;
// }
//--------------------------------------- Minimum Size Subarray Sum ----------------------------------
int MinSubArrayLen(int target, vector<int> &nums)
{
    int n = nums.size(), totalSum = 0, minSubArrayLen = INT_MAX;
    int index = 0;
    while (index < n && totalSum < target)
    {
        totalSum += nums.at(index);
        index++;
    }
    int left = 0, right = index;
    while (right < n)
    {
        if (totalSum >= target)
        {
            if (right - left < minSubArrayLen)
                minSubArrayLen = right - left;
            totalSum -= nums.at(left);
            left++;
        }
        else
        {
            totalSum += nums.at(right);
            right++;
        }
    }
    while (totalSum >= target)
    {
        if (right - left < minSubArrayLen)
            minSubArrayLen = right - left;
        totalSum -= nums.at(left);
        left++;
    }
    return (minSubArrayLen == INT_MAX) ? 0 : minSubArrayLen;
}
//----------------------------
int MinSubArrayLenOtherWay(int target, vector<int> &nums)
{
    int n = nums.size(), totalSum = 0, minSubArrayLen = INT_MAX, left = 0;
    for (int right = 0; right < n; right++)
    {
        totalSum += nums.at(right);
        while (totalSum >= target)
        {
            if ((right - left) + 1 < minSubArrayLen)
                minSubArrayLen = (right - left) + 1;
            totalSum -= nums.at(left);
            left++;
        }
    }
    return (minSubArrayLen == INT_MAX) ? 0 : minSubArrayLen;
}
// int main()
// {
//     cout << string(40, '-') << endl;
//     vector<int> nums = {1, 2, 7, 3, 4, 5};
//     cout << MinSubArrayLenOtherWay(10, nums) << endl;
//     cout << string(40, '-') << endl;
//     return 0;
// }
// ------------------------------------- Best Time to Buy and Sell Stock --------------------------------
int MaxProfit(vector<int> &stockPrices)
{
    int n = stockPrices.size(), left = 0, right = 0, maxProfit = INT_MIN;
    while (right < n)
    {
        int currentProfit = stockPrices.at(right) - stockPrices.at(left);
        if (currentProfit < 0)
            left = right;
        else if (currentProfit > maxProfit)
        {
            maxProfit = currentProfit;
            right++;
        }
        else
            right++;
    }
    return maxProfit;
}
// int main()
// {
//     cout << string(40, '-') << endl;
//     vector<int> stackPrices = {4, 4, 4, 3, 3, 4};
//     cout << MaxProfit(stackPrices) << endl;
//     cout << string(40, '-') << endl;
//     return 0;
// }
// -------------------------------------- Merge Intervals: Introduction ------------------------------------
// ----------------------------------------- Merge Intervals -----------------------------------------------
// class Interval
// {
// public:
//     int start, end;
//     bool closed;
//     Interval(int start, int end)
//     {
//         this->start = start;
//         this->end = end;
//         this->closed = true; // by default, the interval is closed
//     }
//     // set the flag for closed/open
//     void SetClosed(bool closed)
//     {
//         this->closed = closed;
//     }
//     std::string ToString()
//     {
//         return (this->closed) ? "[" + std::to_string(this->start) + ", " + std::to_string(this->end) + "]" : "(" + std::to_string(this->start) + ", " + std::to_string(this->end) + ")";
//     }
// };
// vector<Interval> MergeIntervals(vector<Interval> &intervals)
// {
//     vector<Interval> mergeInterval;
//     Interval helper(intervals.at(0));
//     int index = 1;
//     for (index; index < intervals.size(); index++)
//     {
//         if (intervals.at(index).start <= helper.end)
//         {
//             helper.start = min(intervals.at(index).start, helper.start);
//             helper.end = max(intervals.at(index).end, helper.end);
//         }
//         else
//         {
//             mergeInterval.push_back(helper);
//             helper = intervals.at(index);
//         }
//     }
//     mergeInterval.push_back(helper);
//     return mergeInterval;
// }
// int main()
// {
//     cout << string(40, '-') << endl;

//     // vector<Interval> intervals = {Interval(1, 3), Interval(2, 6), Interval(8, 10), Interval(15, 18), Interval(18, 20)};
//     // vector<Interval> intervals = {Interval(1, 6), Interval(2, 4)};
//     // vector<Interval> intervals = {Interval(1, 8)};
//     vector<Interval> intervals = {Interval(2, 4), Interval(3, 5), Interval(4, 5), Interval(6, 10), Interval(12, 14)};
//     vector<Interval> mergeInterval = MergeIntervals(intervals);
//     for (Interval interval : mergeInterval)
//         cout << "[" << interval.start << " , " << interval.end << "]" << endl;
//     cout << string(40, '-') << endl;
//     return 0;
// }
//------------------------------------------ Insert Interval ------------------------------------------------
class Interval
{
public:
    int start, end;
    bool closed;
    Interval(int start, int end)
    {
        this->start = start;
        this->end = end;
        this->closed = true; // by default, the interval is closed
    }
    // set the flag for closed/open
    void SetClosed(bool closed)
    {
        this->closed = closed;
    }
    std::string ToString()
    {
        return (this->closed) ? "[" + std::to_string(this->start) + ", " + std::to_string(this->end) + "]" : "(" + std::to_string(this->start) + ", " + std::to_string(this->end) + ")";
    }
};
vector<Interval> InsertInterval(vector<Interval> existingIntervals, Interval newInterval)
{
    vector<Interval> resultInterval;
    int index = 0, n = existingIntervals.size();
    while (index < n && newInterval.start > existingIntervals.at(index).end)
    {
        resultInterval.push_back(existingIntervals.at(index));
        index++;
    }
    while (index < n && existingIntervals.at(index).start <= newInterval.end)
    {
        newInterval.start = min(newInterval.start, existingIntervals.at(index).start);
        newInterval.end = max(newInterval.end, existingIntervals.at(index).end);
        index++;
    }
    resultInterval.push_back(newInterval);
    while (index < n)
    {
        resultInterval.push_back(existingIntervals.at(index));
        index++;
    }
    return resultInterval;
}
//--------------------------------
vector<Interval> InsertIntervalOtherWay(vector<Interval> existingIntervals, Interval newInterval)
{
    vector<Interval> resultInterval;
    int n = existingIntervals.size();
    for (int index = 0; index < n; index++)
    {
        if (newInterval.start > existingIntervals.at(index).end)
            resultInterval.push_back(existingIntervals.at(index));
        else if (existingIntervals.at(index).start > newInterval.end)
        {
            resultInterval.push_back(newInterval);
            newInterval = existingIntervals.at(index);
        }
        else if (newInterval.start <= existingIntervals.at(index).end)
        {
            newInterval.start = min(newInterval.start, existingIntervals.at(index).start);
            newInterval.end = max(newInterval.end, existingIntervals.at(index).end);
        }
    }
    resultInterval.push_back(newInterval);
    return resultInterval;
}
// int main()
// {
//     cout << string(40, '-') << endl;
//     // vector<Interval> existingIntervals = {Interval(1, 2), Interval(5, 7), Interval(8, 10)};
//     // vector<Interval> existingIntervals = {Interval(3, 5)};
//     vector<Interval> existingIntervals = {Interval(1, 2), Interval(3, 5), Interval(6, 7), Interval(8, 10), Interval(12, 16)};
//     vector<Interval> mergeInterval = InsertIntervalOtherWay(existingIntervals, Interval(4, 8));
//     for (Interval interval : mergeInterval)
//         cout << "[" << interval.start << " , " << interval.end << "]" << endl;
//     cout << string(40, '-') << endl;
//     return 0;
// }
// ---------------------------------------- Interval List Intersections ----------------------------------------
vector<Interval> helperFunction(vector<Interval> &intervalListA, std::vector<Interval> &intervalListB)
{
    vector<Interval> dummyResult;
    int m = intervalListA.size(), n = intervalListB.size();
    for (int i = 0; i < m; i++)
    {
        Interval intervalA = intervalListA.at(i);
        for (int j = 0; j < n; j++)
        {
            Interval intervalB = intervalListB.at(j);
            if (intervalB.start > intervalA.end)
                break;
            if (intervalB.start <= intervalA.end && intervalA.start < intervalB.start && intervalA.end < intervalB.end)
                dummyResult.push_back(Interval(intervalB.start, intervalA.end));
            else if (intervalA.start <= intervalB.end && intervalB.start < intervalA.start && intervalB.end < intervalA.end)
                dummyResult.push_back(Interval(intervalA.start, intervalB.end));
            else if (intervalB.start >= intervalA.start && intervalB.start <= intervalA.end && intervalB.end >= intervalA.start && intervalB.end <= intervalA.end)
                dummyResult.push_back(intervalB);
            else if (intervalA.start >= intervalB.start && intervalA.start <= intervalB.end && intervalA.end >= intervalB.start && intervalA.end <= intervalB.end)
                dummyResult.push_back(intervalA);
        }
    }
    return dummyResult;
}
vector<Interval> IntervalsIntersection(vector<Interval> &intervalListA, std::vector<Interval> &intervalListB)
{
    return (intervalListA.size() <= intervalListB.size()) ? helperFunction(intervalListB, intervalListA) : helperFunction(intervalListA, intervalListB);
}

// --------------------------
std::vector<Interval> IntervalsIntersectionOtherWay(std::vector<Interval> intervalListA, std::vector<Interval> intervalListB)
{
    std::vector<Interval> intersections{};
    int i = 0, j = 0;
    while (i < intervalListA.size() && j < intervalListB.size())
    {
        int start = std::max(intervalListA[i].start, intervalListB[j].start);
        int end = std::min(intervalListA[i].end, intervalListB[j].end);
        if (start <= end)
        {
            intersections.push_back(Interval(start, end));
        }
        if (intervalListA[i].end < intervalListB[j].end)
        {
            i += 1;
        }
        else
        {
            j += 1;
        }
    }
    return intersections;
}
vector<Interval> IntervalsIntersectionOtherWay(std::vector<Interval> &intervalListA, std::vector<Interval> &intervalListB)
{
    vector<Interval> intersactions;
    int i = 0, j = 0;
    while (i < intervalListA.size() && j < intervalListB.size())
    {
        int start = max(intervalListA.at(i).start, intervalListB.at(j).start);
        int end = min(intervalListA.at(i).end, intervalListB.at(j).end);
        if (start <= end)
            intersactions.push_back(Interval(start, end));
        if (intervalListA.at(i).end < intervalListB.at(j).end)
            i += 1;
        else
            j += 1;
    }
    return intersactions;
}
// int main()
// {
//     cout << string(40, '-') << endl;
//     vector<Interval> intervalListA = {Interval(2, 6), Interval(7, 9), Interval(10, 13), Interval(14, 19), Interval(20, 24)};
//     vector<Interval> intervalListB = {Interval(1, 4), Interval(6, 8), Interval(15, 18)};
//     // vector<Interval> intervalListA = {Interval(1, 29)};
//     // vector<Interval> intervalListB = {Interval(1, 5), Interval(6, 10), Interval(11, 14), Interval(15, 18), Interval(19, 20)};
//     vector<Interval> mergeInterval = IntervalsIntersection(intervalListA, intervalListB);
// for (Interval interval : mergeInterval)
//     cout << "[" << interval.start << " , " << interval.end << "]" << endl;
//     cout << string(40, '-') << endl;
//     return 0;
// }
// ----------------------------------------------Employee Free Time-----------------------------------------
vector<Interval> EmployeeFreeTimeOtherWay(vector<vector<Interval>> schedule)
{
    vector<Interval> employeeFreeTime;
    vector<vector<int>> mergeInterval;
    for (int i = 0; i < schedule.size(); i++)
    {
        for (int j = 0; j < schedule.at(i).size(); j++)
        {
            mergeInterval.push_back({schedule.at(i).at(j).start, schedule.at(i).at(j).end});
        }
    }
    sort(mergeInterval.begin(), mergeInterval.end());
    vector<int> helper = mergeInterval.at(0);
    int index = 1;
    for (index; index < mergeInterval.size(); index++)
    {
        if (mergeInterval.at(index)[0] <= helper[1])
        {
            helper[0] = min(helper[0], mergeInterval.at(index)[0]);
            helper[1] = max(helper[1], mergeInterval.at(index)[1]);
        }
        else
        {
            employeeFreeTime.push_back(Interval(helper[1], mergeInterval.at(index)[0]));
            helper = mergeInterval.at(index);
        }
    }
    return employeeFreeTime;
}
// -----------------------
struct IntervalCompare
{
    bool operator()(const std::tuple<int, int, int> &a, const std::tuple<int, int, int> &b)
    {
        return std::get<0>(a) > std::get<0>(b);
    }
};
std::vector<Interval> EmployeeFreeTime(const std::vector<std::vector<Interval>> &schedule)
{
    std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, IntervalCompare> heap;
    for (int i = 0; i < schedule.size(); i++)
    {
        heap.push(std::make_tuple(schedule[i][0].start, i, 0));
    }
    std::vector<Interval> result;
    int previous = schedule[std::get<1>(heap.top())][std::get<2>(heap.top())].start;
    while (!heap.empty())
    {
        int i = std::get<1>(heap.top());
        int j = std::get<2>(heap.top());
        heap.pop();
        const Interval &interval = schedule[i][j];
        if (interval.start > previous)
        {
            result.push_back(Interval(previous, interval.start));
        }
        previous = std::max(previous, interval.end);

        if (j + 1 < schedule[i].size())
        {
            heap.push(std::make_tuple(schedule[i][j + 1].start, i, j + 1));
        }
    }
    return result;
}
// int main()
// {
//     cout << string(40, '-') << endl;
//     // [[[3, 5], [8, 10]], [[4, 6], [9, 12]], [[5, 6], [8, 10]]]
//     vector<vector<Interval>> schedule = {{Interval(1, 3), Interval(5, 6), Interval(9, 10)}, {Interval(2, 4), Interval(7, 8)}, {Interval(8, 11), Interval(12, 14)}};
//     vector<Interval> employeeFreeTime = EmployeeFreeTime(schedule);
//     for (Interval freeTime : employeeFreeTime)
//         cout << "[" << freeTime.start << " , " << freeTime.end << "]" << endl;
//     cout << string(40, '-') << endl;
//     return 0;
// }
// --------------------------------------------- Task Scheduler -------------------------------------------------
template <typename T>
class ComparatorCopy
{
public:
    bool operator()(T lhs, T rhs)
    {
        return lhs.second < rhs.second;
    }
};
int LeastTime(const std::vector<char> &tasks, int n)
{
    std::unordered_map<char, int> frequencies;
    for (char t : tasks)
        frequencies[t] = frequencies[t] + 1;
    std::vector<std::pair<char, int>> sortedFrequencies(frequencies.begin(), frequencies.end());
    // std::sort(sortedFrequencies.begin(), sortedFrequencies.end(), [](const auto &lhs, const auto &rhs)
    //           { return lhs.second < rhs.second; });
    std::sort(sortedFrequencies.begin(), sortedFrequencies.end(), ComparatorCopy<pair<char, int>>());
    int maxFreq = sortedFrequencies.back().second;
    sortedFrequencies.pop_back();
    int idleTime = (maxFreq - 1) * n;
    while (!sortedFrequencies.empty() && idleTime > 0)
    {
        idleTime -= std::min(maxFreq - 1, sortedFrequencies.back().second);
        sortedFrequencies.pop_back();
    }
    idleTime = std::max(0, idleTime);
    return tasks.size() + idleTime;
}
int LeastTimeOtherWay(const vector<char> &tasks, int n)
{
    int frequencyCounter[26] = {0};
    for (auto ch : tasks)
        frequencyCounter[ch - 'A']++;
    sort(frequencyCounter, frequencyCounter + 26, greater<int>());
    int ideal = (frequencyCounter[0] - 1) * n;
    for (int i = 1; i < 26; i++)
        ideal -= min(frequencyCounter[0] - 1, frequencyCounter[i]);
    return tasks.size() + max(0, ideal);
}

// int main()
// {
//     cout << string(40, '-') << endl;
//     // cout << LeastTime({'A', 'A', 'A', 'B', 'B', 'C', 'C'}, 1) << endl;
//     // cout << LeastTime({'D', 'A', 'F', 'B', 'G', 'E', 'C'}, 1) << endl;
//     // cout << LeastTime({'A', 'A', 'C', 'C', 'C', 'B', 'E', 'E', 'E'}, 2) << endl;
//     // cout << LeastTimeOtherWay({'A', 'A', 'A', 'B', 'B', 'B'}, 2) << endl;
//     cout << LeastTime({'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'}, 2) << endl;
//     cout << string(40, '-') << endl;
//     return 0;
// }
// ------------------------------------------- N meetings in one room ----------------------------------------
// int MaxMeetingsOtherWay(int start[], int end[], int n)
// {
//     vector<pair<int, int>> mergeInterval;
//     for (int i = 0; i < n; i++)
//         mergeInterval.push_back(pair<int, int>(start[i], end[i]));
//     pair<int, int> mettingScheduleTime = mergeInterval.at(0);
//     int maxMettings = 1;
//     for (int i = 1; i < mergeInterval.size(); i++)
//     {
//         if (mergeInterval[i].first > mettingScheduleTime.second)
//         {
//             maxMettings++;
//             mettingScheduleTime.second = max(mettingScheduleTime.second, mergeInterval[i].second);
//         }
//     }
//     return maxMettings;
// }
// ------------------------
// template <typename T>
// class Comparator
// {
// public:
//     bool operator()(T vect1, T vect2)
//     {
//         return vect1.at(1) < vect2.at(0);
//     }
// };
// int MaxMeetings(int start[], int end[], int n)
// {
//     vector<vector<int>> mergeInterval;
//     for (int i = 0; i < n; i++)
//         mergeInterval.push_back({start[i], end[i]});
//     sort(mergeInterval.begin(), mergeInterval.end(), Comparator<vector<int>>());
//     vector<int> mettingScheduleTime = mergeInterval.at(0);
//     int maxMettings = 1;
//     for (int i = 1; i < mergeInterval.size(); i++)
//     {
//         if (mergeInterval.at(i).at(0) > mettingScheduleTime.at(1))
//         {
//             maxMettings++;
//             mettingScheduleTime.at(1) = max(mettingScheduleTime.at(1), mergeInterval.at(i).at(1));
//         }
//     }
//     return maxMettings;
// }
// -------------------------------
struct meeting
{
    int start;
    int end;
    int position;
};
bool comparator(struct meeting m1, meeting m2)
{
    if (m1.end < m2.end)
        return true;
    else if (m1.end > m2.end)
        return false;
    else if (m1.position < m2.position)
        return true;
    return false;
}
int maxMeetings(int start[], int end[], int n)
{
    struct meeting meet[n];
    for (int i = 0; i < n; i++)
    {
        meet[i].start = start[i];
        meet[i].end = end[i];
        meet[i].position = i + 1;
    }
    sort(meet, meet + n, comparator);
    vector<int> answer;
    int limit = meet[0].end;
    answer.push_back(meet[0].position);
    for (int i = 1; i < n; i++)
    {
        if (meet[i].start > limit)
        {
            limit = meet[i].end;
            answer.push_back(meet[i].position);
        }
    }
    // cout << "The order in which the meetings will be performed is " << endl;
    // for (int i = 0; i < answer.size(); i++)
    // {
    //     cout << answer[i] << " ";
    // }
    return answer.size();
}
// int main()
// {
//     cout << string(40, '-') << endl;
//     int start[] = {1, 0, 3, 8, 5, 8};
//     int end[] = {2, 6, 4, 9, 7, 9};
//     cout << maxMeetings(start, end, 6) << endl;
//     cout << string(40, '-') << endl;
//     return 0;
// }
// --------------------------------------------- Meeting Rooms II ------------------------------------------------
class Interval01
{
public:
    int start, end;
    bool closed;
    Interval01(int start, int end)
    {
        this->start = start;
        this->end = end;
        this->closed = true; // by default, the interval is closed
    }
    // set the flag for closed/open
    void SetClosed(bool closed)
    {
        this->closed = closed;
    }
    std::string ToString()
    {
        return (this->closed) ? "[" + std::to_string(this->start) + ", " + std::to_string(this->end) + "]" : "(" + std::to_string(this->start) + ", " + std::to_string(this->end) + ")";
    }
};
bool intervalComparator(Interval01 interval1, Interval01 interval2)
{
    return interval1.start < interval2.start;
}
int FindSets(vector<Interval01> &intervals)
{
    sort(intervals.begin(), intervals.end(), intervalComparator);
    vector<Interval01> roomsTimeInterval;
    roomsTimeInterval.push_back(intervals.at(0));
    for (int i = 1; i < intervals.size(); i++)
    {
        int flag = 1;
        for (int j = 0; j < roomsTimeInterval.size(); j++)
        {
            if (intervals.at(i).start >= roomsTimeInterval.at(j).end)
            {
                roomsTimeInterval.at(j).end = intervals.at(i).end;
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            roomsTimeInterval.push_back(intervals.at(i));
        }
    }
    return roomsTimeInterval.size();
}
// ---------------
int FindSetsOtherWay(vector<Interval01> &intervals)
{
    sort(intervals.begin(), intervals.end(), intervalComparator);
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (const auto interval : intervals)
    {
        if (!minHeap.empty() && interval.start >= minHeap.top())
            minHeap.pop();
        minHeap.push(interval.end);
    }
    return minHeap.size();
}
// int main()
// {
//     cout << string(40, '-') << endl;
//     vector<Interval01> intervals = {Interval01(3, 17), Interval01(19, 20), Interval01(20, 22), Interval01(1, 18), Interval01(9, 19), Interval01(21, 22), Interval01(3, 4), Interval01(7, 22)};
//     // vector<Interval01> intervals = {Interval01(1, 3), Interval01(2, 6), Interval01(8, 10), Interval01(9, 15), Interval01(12, 14)};
//     // vector<Interval01> intervals = {Interval01(1, 6), Interval01(1, 6), Interval01(1, 6), Interval01(1, 6), Interval01(1, 6), Interval01(1, 6), Interval01(1, 6), Interval01(1, 6)};
//     // vector<Interval01> intervals = {Interval01(2, 8), Interval01(3, 4), Interval01(3, 9), Interval01(5, 11), Interval01(8, 20), Interval01(11, 15)};
//     cout << FindSetsOtherWay(intervals) << endl;
//     cout << string(40, '-') << endl;
//     return 0;
// }
// ------------------------------------------ In-place Reversal of a Linked List -----------------------------------------------------
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int val) : val(val), next(nullptr){};
    ListNode(int val, ListNode *next) : val(val), next(next){};
    ~ListNode()
    {
        delete next;
    }
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
        // A newely created Node is valid only one iteration.
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
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
// ----------------------------------------- Reverse Linked List ----------------------------------------------
ListNode *Reverse(ListNode *head)
{
    if (head == NULL)
        return head;
    ListNode *currentNode = head, *previousNode = NULL, *currentNext = NULL;
    while (currentNode)
    {
        currentNext = currentNode->next;
        currentNode->next = previousNode;
        previousNode = currentNode;
        currentNode = currentNext;
    }
    return previousNode;
}
ListNode *ReverseOtherWay(ListNode *head)
{
    if (head == NULL)
        return head;
    ListNode *currentNode = head, *currentNext = NULL;
    while (currentNode && currentNode->next)
    {
        currentNext = currentNode->next;
        currentNode->next = currentNext->next;
        currentNext->next = head;
        head = currentNext;
    }
    return head;
}

// int main()
// {
//     cout << string(40, '-') << endl;
//     ListNode *head = takeInput();
//     printList(head);
//     head = ReverseOtherWay(head);
//     printList(head);
//     cout << string(40, '-') << endl;
//     delete head;
//     return 0;
// }
// ----------------------------------------- Reverse Nodes in k-Group ---------------------------------------
ListNode *ReverseKGroups(ListNode *head, int k)
{
    if (head == NULL)
        return head;
    ListNode *helperNode = head;
    ListNode *currentNode = head, *currentNext = NULL, *previousNode = NULL;
    ListNode *temp = head;
    int n = 0;
    while (temp)
    {
        n++;
        temp = temp->next;
    }
    if (k >= n)
        return head;
    int numberOfGroupPossible = n / k;
    while (numberOfGroupPossible)
    {
        temp = currentNode;
        int i = k;
        while (i)
        {
            currentNext = currentNode->next;
            currentNode->next = previousNode;
            previousNode = currentNode;
            currentNode = currentNext;
            i--;
        }
        if (numberOfGroupPossible == n / k)
        {
            head = previousNode;
        }
        else
        {
            helperNode->next = previousNode;
            helperNode = temp;
        }
        previousNode = NULL;
        currentNext = NULL;
        numberOfGroupPossible--;
    }
    helperNode->next = currentNode;
    return head;
}
// 1 2 3 4 5 6 7 8 9 10 11 12 13 -1
// 8 0 6 1 0 7 8 7 5 3 5 2 4 9 -1
// 6 6 7 7 8 8 9 9 0 0 -1
// 1 2 3 4 5
// int main()
// {
//     cout << string(40, '-') << endl;
//     ListNode *head = takeInput();
//     head = ReverseKGroups(head, 3);
//     printList(head);
//     delete head;
//     return 0;
// }
// ---------------------------------------------------- Reverse Linked List II -----------------------------------------------------
ListNode *ReverseBetween(ListNode *head, int left, int right)
{
    if (head == NULL)
        return head;
    int i = 1;
    ListNode *leftPrevious = NULL, *currentNode = head;
    while (i < left)
    {
        leftPrevious = currentNode;
        currentNode = currentNode->next;
        i++;
    }
    ListNode *helperNode = currentNode, *previous = NULL, *currentNext = NULL;
    while (left != right + 1)
    {
        currentNext = currentNode->next;
        currentNode->next = previous;
        previous = currentNode;
        currentNode = currentNext;
        left++;
    }
    if (leftPrevious == NULL)
    {
        head = previous;
        helperNode->next = currentNode;
    }
    else
    {
        leftPrevious->next = previous;
        helperNode->next = currentNode;
    }
    return head;
}
// 8 0 6 1 0 7 8 2 -1 (1, 5)
// 6 6 7 7 8 8 9 9 0 0 -1 (4. 7)
// 4 2 7 8 9 0 2 -1 (3, 7)
// int main()
// {
//     cout << string(40, '-') << endl;
//     ListNode *head = takeInput();
//     head = ReverseBetween(head, 3, 7);
//     printList(head);
//     delete head;
//     return 0;
// }
//-------------------------------------------------------- Reorder List ----------------------------------------------------------
ListNode *ReorderList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    vector<ListNode *> nodeStore;
    ListNode *temp = head;
    while (temp != NULL)
    {
        nodeStore.push_back(temp);
        temp = temp->next;
    }
    int i = 0, j = nodeStore.size() - 1;
    head = NULL;
    while (i < j)
    {
        if (head == NULL)
        {
            head = nodeStore.at(i);
            head->next = nodeStore.at(j);
            temp = head->next;
        }
        else
        {
            temp->next = nodeStore.at(i);
            temp = temp->next;
            temp->next = nodeStore.at(j);
            temp = temp->next;
        }
        i++;
        j--;
    }
    if (i == j)
    {
        temp->next = nodeStore.at(i);
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}
ListNode *ReorderListOtherWay(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    int n = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        n++;
        temp = temp->next;
    }
    int target = n / 2;
    if (n % 2 != 0)
        target++;
    ListNode *currentNode = head, *targetPrevious = NULL;
    while (target)
    {
        targetPrevious = currentNode;
        currentNode = currentNode->next;
        target--;
    }
    targetPrevious->next = NULL;
    ListNode *previousNode = NULL, *currentNext = NULL;
    while (currentNode)
    {
        currentNext = currentNode->next;
        currentNode->next = previousNode;
        previousNode = currentNode;
        currentNode = currentNext;
    }
    currentNode = head;
    ListNode *previousNext = NULL;
    while (currentNode && previousNode)
    {
        currentNext = currentNode->next;
        previousNext = previousNode->next;
        currentNode->next = previousNode;
        previousNode->next = currentNext;
        currentNode = currentNext;
        previousNode = previousNext;
    }
    return head;
}
ListNode *ReorderListOtherWay2(ListNode *&head)
{
    if (!head)
        return head;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *prev = nullptr;
    ListNode *curr = slow;
    ListNode *tmp;
    while (curr)
    {
        tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    ListNode *first = head;
    ListNode *second = prev;
    while (second->next)
    {
        tmp = first->next;
        first->next = second;
        first = tmp;
        tmp = second->next;
        second->next = first;
        second = tmp;
    }
    return head;
}
// 6 6 7 7 8 8 9 9 0 0 -1
// 4 2 7 8 9 0 2 -1
// 0 6 7 -1
// 9 5 8 2 1 -1
// 6 6 7 7 8 8 9 9 0 0 -1
// 1 2 3 4 5 6 -1
// int main()
// {
//     cout << string(40, '-') << endl;
//     ListNode *head = takeInput();
//     head = ReorderListOtherWay2(head);
//     printList(head);
//     delete head;
//     return 0;
// }
// ------------------------------------------------- Swapping Nodes in a Linked List ----------------------------------------------------
ListNode *SwapNodes(ListNode *head, int k)
{
    int count = 0;
    ListNode *front = NULL, *end = NULL, *curr = head;
    while (curr)
    {
        count++;
        if (end != NULL)
            end = end->next;
        if (count == k)
        {
            front = curr;
            end = head;
        }
        curr = curr->next;
    }
    int temp = front->val;
    front->val = end->val;
    end->val = temp;
    return head;
}
ListNode *SwapNodesOtherWay(ListNode *head, int k)
{
    ListNode *front = NULL, *end = NULL, *curr = head;
    int target = 1;
    while (target != k)
    {
        curr = curr->next;
        target++;
    }
    front = curr;
    end = head;
    while (curr && curr->next)
    {
        curr = curr->next;
        end = end->next;
    }
    int temp = front->val;
    front->val = end->val;
    end->val = temp;
    return head;
}
// 7 4 6 1 5 8 -1 5
// 1 2 3 4 5 -1 3
// 9 0 8 2 -1 2
// 6 8 7 -1 1
// 9 9 8 4 1 1 3 5 0 2 6 7 1 4 7 8 2 1 -1 18
// 1 2 3 4 5 -1 5
// int main()
// {
//     cout << string(40, '-') << endl;
//     ListNode *head = takeInput();
//     head = SwapNodesOtherWay(head, 5);
//     printList(head);
//     delete head;
//     return 0;
// }
// ------------------------------------------------------- Two Heaps: Introduction -----------------------------------------------
// --------------------------------------------------------- Maximize Capital ----------------------------------------------------
// ------------ TLE ------------------
int MaximumCapital(int totalCapital, int k, vector<int> capitals, vector<int> profits)
{
    map<int, int> indexOccured;
    int maxProfit, capitalIndex;
    while (k)
    {
        maxProfit = 0;
        for (int i = 0; i < capitals.size(); i++)
        {
            if (indexOccured.find(i + 1) == indexOccured.end() && capitals[i] <= totalCapital)
            {
                if (profits[i] >= maxProfit)
                {
                    capitalIndex = i;
                    maxProfit = profits[i];
                }
            }
        }
        totalCapital += maxProfit;
        indexOccured[capitalIndex + 1] = 1;
        k--;
    }
    return totalCapital;
}
// ------------ TLE ------------
int MaximumCapitalOtherWay(int totalCapital, int k, vector<int> capitals, vector<int> profits)
{
    int maxProfit, capitalIndex = 0, flag = 0;
    while (k)
    {
        maxProfit = 0;
        flag = 0;
        for (int i = 0; i < capitals.size(); i++)
        {
            if (capitals[i] <= totalCapital && profits[i] != INT_MIN && profits[i] >= maxProfit)
            {
                flag = 1;
                capitalIndex = i;
                maxProfit = profits[i];
            }
        }
        if (flag == 0)
            return totalCapital;
        totalCapital += maxProfit;
        profits[capitalIndex] = INT_MIN;
        k--;
    }
    return totalCapital;
}
// --------------------------------
int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
{
    int n = profits.size();
    vector<pair<int, int>> projects(n);
    for (int i = 0; i < n; i++)
    {
        projects[i] = {capital[i], profits[i]};
    }
    // We sort the projects by their minimum capital required in ascending order because we want to consider the projects that we can afford with our current capital. By iterating over the sorted projects, we can ensure that we only consider the projects that have a minimum capital requirement less than or equal to our current capital.
    sort(projects.begin(), projects.end());
    int i = 0;
    priority_queue<int> maximizeCapital;
    while (k--)
    {
        // The condition projects[i].first <= w checks if the minimum capital requirement of the next project is less than or equal to our current capital w. If this condition is true, we can add the project to the priority queue because we have enough capital to start the project.
        // We use this condition to ensure that we only add the available projects that we can afford to the priority queue. By checking the minimum capital requirement of the next project before adding it to the priority queue, we can avoid adding projects that we cannot afford, and we can focus on selecting the most profitable project that we can afford with our current capital.
        // The loop while (i < n && projects[i].first <= w) runs until we add all the available projects that we can afford to the priority queue
        while (i < n && projects[i].first <= w)
        {
            maximizeCapital.push(projects[i].second);
            i++;
        }
        if (maximizeCapital.empty())
            break;
        w += maximizeCapital.top();
        maximizeCapital.pop();
    }
    return w;
}
int MaximumCapitalOtherWay2(int c, int k, vector<int> capitals, vector<int> profits)
{
    int n = profits.size();
    vector<pair<int, int>> projects;
    for (int i = 0; i < n; i++)
        projects.push_back(pair<int, int>(capitals[i], profits[i]));
    sort(projects.begin(), projects.end());
    int i = 0;
    priority_queue<int> maximizeCapital;
    while (k--)
    {
        while (i < n && projects[i].first <= c)
        {
            maximizeCapital.push(projects[i].second);
            i++;
        }
        if (maximizeCapital.empty())
            break;
        c += maximizeCapital.top();
        maximizeCapital.pop();
    }
    return c;
}
// int main()
// {
//     cout << string(40, '-') << endl;
//     vector<int> capitals = {2, 3, 5, 6, 8, 12};
//     vector<int> profits = {1, 2, 5, 6, 8, 9};
//     cout << MaximumCapitalOtherWay2(2, 4, capitals, profits) << endl;
//     cout << string(40, '-') << endl;
//     return 0;
// }
// --------------------------------------------------- Find Median from a Data Stream ------------------------------------------------
// class MedianOfStream
// {
//     vector<int> input;

// public:
//     // This function should take a number and store it
//     void InsertNum(int num)
//     {
//         // Write your code here
//         input.push_back(num);
//     }
//     // This function should return the median of the stored numbers
//     double FindMedian()
//     {
//         // Replace this placeholder return statement with your code
//         priority_queue<int, vector<int, greater<int>>> MIN_HEAP;
//         priority_queue<int> MAX_HEAP;
//         for (int i = 0; i < input.size(); i++)
//             MIN_HEAP.push(input.at(i));
//         int n = input.size();
//         int k = 1;
//         while (k++ <= n / 2)
//         {
//             MAX_HEAP.push(MIN_HEAP.top());
//             MIN_HEAP.pop();
//         }
//         if (n % 2 != 2)
//             return MIN_HEAP.top();
//         return (MAX_HEAP.top() + MIN_HEAP.top()) / 2;
//     }
// };
// int main()
// {
//     cout << string(30, '-') << endl;
//     cout << string(30, '-') << endl;
//     return 0;
// }
// ---------------------------------------------------------- Sliding Window Median ------------------------------------------------------------------
double helperFunction(vector<int> window, int k)
{
    priority_queue<int, vector<int>, greater<int>> MIN_HEAP;
    priority_queue<int> MAX_HEAP;
    for (auto item : window)
        MIN_HEAP.push(item);
    int j = 1;
    while (j <= k / 2)
    {
        MAX_HEAP.push(MIN_HEAP.top());
        MIN_HEAP.pop();
        j++;
    }
    if (k % 2 == 0)
        return ((double)MAX_HEAP.top() + (double)MIN_HEAP.top()) * 0.5;
    else
        return (long)MIN_HEAP.top();
}
vector<double> MedianSlidingWindow(vector<int> nums, int k)
{
    vector<double> medians;
    vector<int> window;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (i < k)
            window.push_back(nums.at(i));
        else
        {
            medians.push_back(helperFunction(window, k));
            window.erase(window.begin());
            window.push_back(nums.at(i));
        }
    }
    medians.push_back(helperFunction(window, k));
    return medians;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {1, 3, -1, 2, -2, -3, 5, 1, 5, 3};
//     vector<double> result = MedianSlidingWindow(nums, 4);
//     for (auto item : result)
//         cout << item << "  ";
//     cout << endl;
//     cout << string(30, '-') << endl;
//     return 0;
// }
// -------------------------------------------- Schedule Tasks on Minimum Machines -----------------------------------------------
int Tasks(vector<vector<int>> tasksList)
{
    sort(tasksList.begin(), tasksList.end());
    vector<vector<int>> assignedTasksToMachine;
    assignedTasksToMachine.push_back(tasksList.at(0));
    for (int i = 1; i < tasksList.size(); i++)
    {
        int flag = 1;
        for (int j = 0; j < assignedTasksToMachine.size(); j++)
        {
            if (tasksList.at(i)[0] >= assignedTasksToMachine.at(j)[1])
            {
                flag = 0;
                assignedTasksToMachine.at(j)[1] = tasksList.at(i)[1];
                break;
            }
        }
        if (flag)
            assignedTasksToMachine.push_back(tasksList.at(i));
    }
    return assignedTasksToMachine.size();
}
// ------------
int TasksOtherWay(vector<vector<int>> tasksList)
{
    int requiredMachineCounter = 0;
    sort(tasksList.begin(), tasksList.end());
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for (auto item : tasksList)
        pq.push(item);
    while (!pq.empty())
    {
        cout << pq.top()[0] << " : " << pq.top()[1] << endl;
        pq.pop();
    }
    return requiredMachineCounter;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<vector<int>> tasksList = {{12, 13}, {13, 15}, {17, 20}, {13, 14}, {19, 21}, {18, 20}};
//     cout << "Tasks : " << TasksOtherWay(tasksList) << endl;
//     cout << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------ K-way Merge: Introduction -------------------------------------------------------------
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> vect01 = {2, 6, 8};
//     vector<int> vect02 = {3, 6, 7};
//     vector<int> vect03 = {1, 3, 4};
//     priority_queue<pair<int, vector<int>::iterator>, vector<pair<int, vector<int>::iterator>>, greater<pair<int, vector<int>::iterator>>> pq;
//     pq.push(pair<int, vector<int>::iterator>(vect01.at(0), vect01.begin()));
//     pq.push(pair<int, vector<int>::iterator>(vect02.at(0), vect02.begin()));
//     pq.push(pair<int, vector<int>::iterator>(vect03.at(0), vect03.begin()));
//     cout << *(vect01.begin() + 3) << endl;
//     cout << string(30, '-') << endl;
//     return 0;
// }

// ------------------------------------------------------ Merge Sorted Array ----------------------------------------------------------------
// vector<int> mergeSortedArray(vector<int> &nums1, int m, vector<int> &nums2, int n)
// {
//     priority_queue<pair<int, vector<int>::iterator>, vector<pair<int, vector<int>::iterator>>, greater<pair<int, vector<int>::iterator>>> pq;
//     vector<int>::iterator itr;
//     pq.push(pair<int, vector<int>::iterator>(nums1.at(0), nums1.begin()));
//     pq.push(pair<int, vector<int>::iterator>(nums2.at(0), nums2.begin()));
//     return nums1;
// }
vector<int> mergeSortedArray(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int p1 = m - 1, p2 = n - 1;
    int p = (m + n) - 1;
    while (p1 > -1 && p2 > -1)
    {
        if (nums1[p1] > nums2[p2])
            nums1[p--] = nums1[p1--];
        else
            nums1[p--] = nums2[p2--];
    }
    while (p2 > -1)
    {
        nums1[p--] = nums2[p2--];
    }
    return nums1;
}
vector<int> mergeSortedArrayOtherWay(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int p1 = m - 1;
    int p2 = n - 1;
    for (int p = n + m - 1; p > -1; p--)
    {
        if (p2 < 0)
            break;
        if (p1 >= 0 && nums1[p1] > nums2[p2])
        {
            nums1[p] = nums1[p1];
            p1 -= 1;
        }
        else
        {
            nums1[p] = nums2[p2];
            p2 -= 1;
        }
    }
    return nums1;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums1 = {1, 12, 57, 98, 0, 0, 0, 0};
//     vector<int> nums2 = {1, 4, 5, 57};
//     int m = 4;
//     int n = 4;
//     nums1 = mergeSortedArrayOtherWay(nums1, m, nums2, n);
//     for (auto item : nums1)
//         cout << item << "  ";
//     cout << endl;
//     cout << string(30, '-') << endl;
//     return 0;
// }
// ---------------------------------------------------- Kth Smallest Number in M Sorted Lists------------------------------------
int KSmallestNumber01(std::vector<std::vector<int>> list, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < list.size(); i++)
    {
        for (int j = 0; j < list.at(i).size(); j++)
        {
            pq.push(list.at(i).at(j));
        }
    }
    int target = 1;
    int n = pq.size();
    while (target < n && target < k)
    {
        pq.pop();
        target++;
    }
    return pq.size() ? pq.top() : 0;
}
int KSmallestNumberOtherWay(std::vector<std::vector<int>> list, int k)
{
    priority_queue<pair<int, pair<vector<int>::iterator, vector<int>::iterator>>, vector<pair<int, pair<vector<int>::iterator, vector<int>::iterator>>>, greater<pair<int, pair<vector<int>::iterator, vector<int>::iterator>>>> pq;
    for (int i = 0; i < list.size(); i++)
    {
        if (list.at(i).size() > 0)
            pq.push({list.at(i)[0], {list.at(i).begin(), list.at(i).end()}});
    }
    int target = 1;
    while (!pq.empty() && target < k)
    {
        if (pq.size() == 1 && (pq.top().second.first + 1) == (pq.top().second.second))
            break;
        if ((pq.top().second.first + 1) != (pq.top().second.second))
        {
            pq.push({*(pq.top().second.first + 1), {pq.top().second.first + 1, pq.top().second.second}});
        }
        pq.pop();
        target++;
    }
    return !pq.empty() ? pq.top().first : 0;
}
int KSmallestNumberOtherWayEfficient(std::vector<std::vector<int>> list, int k)
{
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> kthSmallest;
    for (int index = 0; index < list.size(); index++)
    {
        if (list.at(index).size() > 0)
        {
            kthSmallest.push({list.at(index)[0], index, 0});
        }
    }
    int numbersChecked = 0, smallestNumber = 0;
    while (!kthSmallest.empty())
    {
        vector<int> smallest = kthSmallest.top();
        kthSmallest.pop();
        smallestNumber = smallest[0];
        int listIndex = smallest[1];
        int numIndex = smallest[2];
        numbersChecked++;
        if (numbersChecked == k)
            break;
        if (numIndex + 1 < list[listIndex].size())
        {
            kthSmallest.push({list[listIndex][numIndex + 1], listIndex, numIndex + 1});
        }
    }
    return smallestNumber;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<vector<int>> list = {{5, 8, 9}, {1, 7}};
//     cout << "Kth Smallest Number : " << KSmallestNumberOtherWayEfficient(list, 3) << endl;
//     cout << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------ 42. Trapping Rain Water ---------------------------------------------------
int trap(vector<int> &height)
{
    vector<vector<int>> tracker;
    int max_left = 0, max_right = 0;
    for (int index = 0; index < height.size(); index++)
    {
        if (index > 0)
            max_left = max(height.at(index - 1), max_left);
        tracker.push_back({max_left, height.at(index), 0});
    }
    for (int index = height.size() - 1; index >= 0; index--)
    {
        if (index < height.size() - 1)
            max_right = max(height.at(index + 1), max_right);
        tracker.at(index)[2] = max_right;
    }
    int maxWaterTrap = 0;
    for (int index = 0; index < tracker.size(); index++)
    {
        int maxWaterFilled = min(tracker.at(index)[0], tracker.at(index)[2]);
        int waterTrapForSingleBar = maxWaterFilled - tracker.at(index)[1];
        maxWaterTrap += (waterTrapForSingleBar < 0) ? 0 : waterTrapForSingleBar;
    }
    return maxWaterTrap;
}
// ----------------- TLE ----------------------
int trapOtherWay(vector<int> &height)
{
    int n = height.size();
    int waterTrapped = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        int leftMax = 0, rightMax = 0;
        while (j >= 0)
        {
            leftMax = max(leftMax, height[j]);
            j--;
        }
        j = i;
        while (j < n)
        {
            rightMax = max(rightMax, height[j]);
            j++;
        }
        waterTrapped += min(leftMax, rightMax) - height[i];
    }
    return waterTrapped;
}
// ---------------------------------
int trapOtherWay2(vector<int> &height)
{
    int n = height.size();
    int waterTrapped = 0;
    int prefix[n], suffix[n];
    prefix[0] = height[0];
    for (int index = 1; index < n; index++)
    {
        prefix[index] = max(prefix[index - 1], height[index]);
    }
    suffix[n - 1] = height[n - 1];
    for (int index = n - 2; index >= 0; index--)
    {
        suffix[index] = max(suffix[index + 1], height[index]);
    }
    for (int index = 0; index < n; index++)
    {
        waterTrapped += min(prefix[index], suffix[index]) - height[index];
    }
    return waterTrapped;
}
int trapOtherWay3(vector<int> &height)
{
    int n = height.size();
    int waterTrapped = 0;
    int leftPointer = 0, rightPointer = n - 1;
    int leftMax = 0, rightMax = 0;
    while (leftPointer <= rightPointer)
    {
        if (height[leftPointer] <= height[rightPointer])
        {
            if (leftMax <= height[leftPointer])
                leftMax = height[leftPointer];
            else
                waterTrapped += leftMax - height[leftPointer];
            leftPointer++;
        }
        else
        {
            if (rightMax <= height[rightPointer])
                rightMax = height[rightPointer];
            else
                waterTrapped += rightMax - height[rightPointer];
            rightPointer--;
        }
    }
    return waterTrapped;
}
// int main()
// {
//     // vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
//     vector<int> height = {4, 2, 0, 3, 2, 5};
//     cout << "Trap Water : " << trapOtherWay3(height) << endl;
//     return 0;
// }
// ------------------------------------------------------------- Find K Pairs with Smallest Sums ------------------------------------------------------
// --------------- Memory Limit Exceed ----------------------
class comparator_class
{
public:
    bool operator()(vector<int> &x, vector<int> &y)
    {
        return (x.at(0) + x.at(1) < y.at(0) + y.at(1));
    }
};
bool smallSumComparator(vector<int> &x, vector<int> &y)
{
    return (x.at(0) + x.at(1) < y.at(0) + y.at(1));
}
void makePairs(vector<int> &list1, vector<int> &list2, vector<vector<int>> &pairs)
{
    for (int i = 0; i < list1.size(); i++)
    {
        for (int j = 0; j < list2.size(); j++)
        {
            pairs.push_back({list1.at(i), list2.at(j)});
        }
    }
}
vector<vector<int>> KSmallestPairs(vector<int> &list1, vector<int> &list2, int k)
{
    vector<vector<int>> pairs;
    makePairs(list1, list2, pairs);
    sort(pairs.begin(), pairs.end(), comparator_class());
    if (k > pairs.size())
        return pairs;
    return {pairs.begin(), pairs.begin() + k};
}
// ------------------- TIME LIMIT EXCEED ----------------
vector<vector<int>> KSmallestPairsOtherWay(vector<int> &list1, vector<int> &list2, int k)
{
    priority_queue<vector<int>, vector<vector<int>>> pq;
    int counter = 0, flag = 0;
    for (int i = 0; i < list1.size(); i++)
    {
        for (int j = 0; j < list2.size(); j++)
        {
            pq.push({list1.at(i) + list2.at(j), list1.at(i), list2.at(j)});
            counter++;
            if (counter > k)
                pq.pop();
        }
    }
    int n = pq.size();
    vector<vector<int>> pairs(n);
    while (!pq.empty())
    {
        pairs[n - 1] = {pq.top()[1], pq.top()[2]};
        pq.pop();
        n--;
    }
    return pairs;
}
vector<vector<int>> KSmallestPairsOtherWay2(vector<int> &list1, vector<int> &list2, int k)
{
    int listLength = list1.size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
    vector<std::vector<int>> pairs;
    for (int i = 0; i < std::min(k, listLength); i++)
    {
        minHeap.push({list1[i] + list2[0], {i, 0}});
    }
    int counter = 1;
    while (minHeap.size() > 0 && counter <= k)
    {
        int sumOfPairs = minHeap.top().first;
        int i = minHeap.top().second.first;
        int j = minHeap.top().second.second;
        minHeap.pop();
        pairs.push_back({list1[i], list2[j]});
        int nextElement = j + 1;
        if (list2.size() > nextElement)
        {
            minHeap.push({list1[i] + list2[nextElement], {i, nextElement}});
        }
        counter++;
    }
    return pairs;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     // vector<int> list1 = {0, 0, 0, 0, 0, 2, 2, 2, 2};
//     // vector<int> list2 = {-3, 22, 35, 56, 76};
//     vector<int> list1 = {2, 8, 9};
//     vector<int> list2 = {1, 3, 6};
//     vector<vector<int>> pairs = KSmallestPairsOtherWay2(list1, list2, 3);
//     for (auto pair : pairs)
//         cout << "[" << pair.at(0) << ", " << pair.at(1) << "]" << endl;
//     cout << string(30, '-') << endl;
//     return 0;
// }
// ----------------------------------------------------------- Merge K Sorted Lists ---------------------------------------------------------
struct EduLinkedListNode
{
    int data;
    EduLinkedListNode *next;
    EduLinkedListNode *arbitrary_pointer;
    EduLinkedListNode(int d)
    {
        data = d;
        next = nullptr;
        arbitrary_pointer = nullptr;
    }
};
class EduLinkedList
{
public:
    EduLinkedListNode *head;
    EduLinkedList() { head = nullptr; }
    EduLinkedList(EduLinkedListNode *h)
    {
        head = h;
    }
    void InsertAtHead(int data)
    {
        if (head == nullptr)
        {
            head = new EduLinkedListNode(data);
        }
        else
        {
            EduLinkedListNode *new_node = new EduLinkedListNode(data);
            new_node->next = head;
            head = new_node;
        }
    }
    void InsertAtTail(int data)
    {
        if (head == nullptr)
        {
            head = new EduLinkedListNode(data);
        }
        else
        {
            EduLinkedListNode *new_node = new EduLinkedListNode(data);
            EduLinkedListNode *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }
    void CreateLinkedList(std::vector<int> &vec)
    {
        for (int i = vec.size() - 1; i >= 0; i--)
        {
            InsertAtHead(vec[i]);
        }
    }
};
EduLinkedListNode *ReverseLinkedList(EduLinkedListNode *head)
{
    EduLinkedListNode *current = head;
    EduLinkedListNode *prev = nullptr;
    EduLinkedListNode *nxt = nullptr;
    while (current != nullptr)
    {
        nxt = current->next;
        current->next = prev;
        prev = current;
        current = nxt;
    }
    return prev;
}
void TraverseLinkedList(EduLinkedListNode *head)
{
    EduLinkedListNode *current = head;
    EduLinkedListNode *nxt = nullptr;
    while (current != nullptr)
    {
        cout << current->data << " -> ";
        nxt = current->next;
        current = nxt;
    }
    cout << "NULL" << endl;
}
EduLinkedListNode *MergeKLists(vector<EduLinkedList *> lists)
{
    EduLinkedListNode *newHeadNode = nullptr;
    EduLinkedListNode *tailNode = nullptr;
    priority_queue<pair<int, EduLinkedListNode *>, vector<pair<int, EduLinkedListNode *>>, greater<pair<int, EduLinkedListNode *>>> pq;
    int n = lists.size();
    for (int index = 0; index < n; index++)
    {
        if (lists.at(index) != nullptr)
            pq.push(pair<int, EduLinkedListNode *>(lists.at(index)->head->data, lists.at(index)->head));
    }
    while (!pq.empty())
    {
        EduLinkedListNode *smallestPoppedNode = pq.top().second;
        pq.pop();
        if (newHeadNode == nullptr)
        {
            newHeadNode = smallestPoppedNode;
            tailNode = newHeadNode;
        }
        else
        {
            tailNode->next = smallestPoppedNode;
            tailNode = tailNode->next;
        }
        if (smallestPoppedNode->next)
        {
            pq.push(pair<int, EduLinkedListNode *>(smallestPoppedNode->next->data, smallestPoppedNode->next));
        }
    }
    return newHeadNode;
}
// ------------------------- TLE --------------------------------------
EduLinkedListNode *MergeKListsOtherWay(vector<EduLinkedList *> lists)
{
    EduLinkedListNode *newHeadNode = nullptr;
    EduLinkedListNode *tailNode = nullptr;
    int n = lists.size();
    vector<pair<int, EduLinkedListNode *>> vect;
    for (int i = 0; i < n; i++)
    {
        if (lists.at(i) != nullptr)
            vect.push_back(pair<int, EduLinkedListNode *>(lists.at(i)->head->data, lists.at(i)->head));
    }
    while (!vect.empty())
    {
        sort(vect.begin(), vect.end(), greater<pair<int, EduLinkedListNode *>>());
        EduLinkedListNode *smallestPoppedNode = vect.at(vect.size() - 1).second;
        vect.pop_back();
        if (newHeadNode == nullptr)
        {
            newHeadNode = smallestPoppedNode;
            tailNode = newHeadNode;
        }
        else
        {
            tailNode->next = smallestPoppedNode;
            tailNode = tailNode->next;
        }
        if (smallestPoppedNode->next)
        {
            vect.push_back(pair<int, EduLinkedListNode *>(smallestPoppedNode->next->data, smallestPoppedNode->next));
        }
    }
    return newHeadNode;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     EduLinkedList *list1 = new EduLinkedList();
//     list1->InsertAtTail(2);
//     list1->InsertAtTail(4);
//     list1->InsertAtTail(6);
//     list1->InsertAtTail(8);
//     EduLinkedList *list2 = new EduLinkedList();
//     list2->InsertAtTail(1);
//     list2->InsertAtTail(3);
//     list2->InsertAtTail(5);
//     list2->InsertAtTail(7);
//     // TraverseLinkedList(list1->head);
//     // TraverseLinkedList(list2->head);
//     EduLinkedListNode *newHead = MergeKListsOtherWay({list1, list2});
//     TraverseLinkedList(newHead);
//     cout << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------- Kth Smallest Element in a Sorted Matrix ---------------------------------------------------------
int KSmallestNumber(vector<vector<int>> matrix, int k)
{
    int n = matrix.size();
    int smallestElement;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for (int rowIndex = 0; rowIndex < n; rowIndex++)
    {
        pq.push({matrix.at(rowIndex)[0], rowIndex, 0});
    }
    int counter = 0;
    while (!pq.empty() && counter < k)
    {
        vector<int> smallestPoppedData = pq.top();
        pq.pop();
        smallestElement = smallestPoppedData.at(0);
        int rowIndex = smallestPoppedData.at(1);
        int columnIndex = smallestPoppedData.at(2);
        int nextColumnIndex = columnIndex + 1;
        if (n > nextColumnIndex)
            pq.push({matrix.at(rowIndex)[nextColumnIndex], rowIndex, nextColumnIndex});
        counter++;
    }
    return smallestElement;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
//     cout << "KSmallestNumber : " << KSmallestNumber(matrix, 8) << endl;
//     cout << string(30, '-') << endl;
//     return 0;
// }
// -------------------------------------------------- Top K Elements: Introduction -------------------------------------------------------
// 1. Insert the first k elements from the given set of elements to the min-heap or max-heap.
// 2. Iterate through the rest of the elements.
// 2.1 For min-heap, if you find the larger element, remove the top (smallest number) of the min-heap and insert the new larger element.
// 2.2 For max-heap, if you find the smaller element, remove the top (largest number) of the max-heap and insert the new smaller element.
// Iterating the complete list takes O(n) time, and the heap takes O(logk) time for insertion. However, we get the O(1) access to the k elements using the heap.
// ---------------------------------- Sort characters by frequency -----------------------------------
class MaxCharFrequencyComperator
{
public:
    bool operator()(const pair<char, int> &p1, const pair<char, int> &p2)
    {
        return p1.second <= p2.second;
    }
};
string SortCharactersByFrequency(string str)
{
    int n = str.size();
    unordered_map<char, int> umap;
    string result;
    for (int index = 0; index < n; index++)
    {
        umap[str.at(index)]++;
    }
    vector<pair<char, int>> charFrequency(umap.begin(), umap.end());
    sort(charFrequency.begin(), charFrequency.end(), MaxCharFrequencyComperator());
    for (auto item : charFrequency)
        result.append(string(item.second, item.first));
    return result;
}
string SortCharactersByFrequencyOtherWay(string str)
{
    int n = str.size();
    unordered_map<char, int> umap;
    string result;
    for (int index = 0; index < n; index++)
    {
        umap[str.at(index)]++;
    }
    priority_queue<pair<char, int>, vector<pair<char, int>>, MaxCharFrequencyComperator> pq(umap.begin(), umap.end());
    while (!pq.empty())
    {
        pair<char, int> topElement = pq.top();
        pq.pop();
        result.append(string(topElement.second, topElement.first));
    }
    return result;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     cout << "Sort characters by frequency : " << SortCharactersByFrequencyOtherWay("buubble") << endl;
//     cout << string(30, '-') << endl;
//     return 0;
// }
// ---------------------------------------------------- Kth Largest Element in a Stream ------------------------------------------------------------
class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        for (auto item : nums)
            pq.push(item);
        while (pq.size() > k)
            pq.pop();
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > k)
            pq.pop();
        return pq.top();
    }
};
// int main()
// {
//     cout << string(30, '-') << endl;
//     cout << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------------------- Reorganize String ------------------------------------------------------------------
class MaxFrequencyComperator
{
public:
    bool operator()(const pair<char, int> &p1, const pair<char, int> &p2)
    {
        return p1.second <= p2.second;
    }
};
class MinFrequencyComperator
{
public:
    bool operator()(const pair<char, int> &p1, const pair<char, int> &p2)
    {
        return p1.second >= p2.second;
    }
};
string ReorganizeString(string str)
{
    map<char, int> mp;
    string sortCharactersByFrequency;
    for (auto item : str)
        mp[item]++;
    priority_queue<pair<char, int>, vector<pair<char, int>>, MaxFrequencyComperator> maxHeap(mp.begin(), mp.end());
    string result;
    int n = str.size();
    if (((n % 2) == 0 && maxHeap.top().second > (n / 2)) || ((n % 2) != 0 && maxHeap.top().second > ((n / 2) + 1)))
    {
        return "";
    }
    while (!maxHeap.empty())
    {
        pair<char, int> maxHeapTop = maxHeap.top();
        maxHeap.pop();
        result.push_back(maxHeapTop.first);
        if (!maxHeap.empty())
        {
            pair<char, int> maxHeapSecondTop = maxHeap.top();
            maxHeap.pop();
            result.push_back(maxHeapSecondTop.first);
            if (maxHeapSecondTop.second > 1)
            {
                maxHeapSecondTop.second--;
                maxHeap.push(maxHeapSecondTop);
            }
        }
        if (maxHeapTop.second > 1)
        {
            maxHeapTop.second--;
            maxHeap.push(maxHeapTop);
        }
    }
    return result;
}
string ReorganizeStringOther(string str)
{
    map<char, int> mp;
    for (auto item : str)
        mp[item]++;
    priority_queue<pair<char, int>, vector<pair<char, int>>, MaxFrequencyComperator> maxHeap(mp.begin(), mp.end());
    string result;
    int n = str.size();
    if (((n % 2) == 0 && maxHeap.top().second > (n / 2)) || ((n % 2) != 0 && maxHeap.top().second > ((n / 2) + 1)))
    {
        return "";
    }
    pair<char, int> maxHeapTop = maxHeap.top();
    maxHeap.pop();
    result.push_back(maxHeapTop.first);
    while (!maxHeap.empty())
    {
        pair<char, int> heapTop = maxHeap.top();
        maxHeap.pop();
        result.push_back(heapTop.first);
        maxHeapTop.second--;
        if (maxHeapTop.second > 0)
        {
            maxHeap.push(maxHeapTop);
        }
        maxHeapTop = heapTop;
    }
    return result;
}
string ReorganizeStringOther2(string str)
{
    map<char, int> mp;
    for (auto item : str)
        mp[item]++;
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> maxHeap;
    string result;
    int n = str.size();
    for (auto item : mp)
    {
        maxHeap.push({-item.second, item.first});
    }
    if (((n % 2) == 0 && -(maxHeap.top().first) > (n / 2)) || ((n % 2) != 0 && -(maxHeap.top().first) > ((n / 2) + 1)))
    {
        return "";
    }
    pair<int, char> maxHeapTop = maxHeap.top();
    maxHeap.pop();
    result.push_back(maxHeapTop.second);
    while (!maxHeap.empty())
    {
        pair<int, char> heapTop = maxHeap.top();
        maxHeap.pop();
        result.push_back(heapTop.second);
        maxHeapTop.first++;
        if (maxHeapTop.first < 0)
        {
            maxHeap.push(maxHeapTop);
        }
        maxHeapTop = heapTop;
    }
    return result;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     cout << ReorganizeStringOther2("aaabc") << endl;
//     // cout << ReorganizeStringOther2("abaacdda") << endl;
//     cout << string(30, '-') << endl;
//     return 0;
// }
// -------------------------------------------------------------- K Closest Points to Origin -----------------------------------------------------------
class Point
{
public:
    int x;
    int y;
    // Point(int x, int y)
    // {
    //     this->x = x;
    //     this->y = y;
    // }
    Point(int x, int y) : x(x), y(y){};
};

vector<Point> KClosest(vector<Point> locations, int k)
{
    priority_queue<pair<double, int>, vector<pair<double, int>>> pq;
    for (int i = 0; i < locations.size(); i++)
    {
        double squareRoot = sqrt(pow(locations.at(i).x, 2) + pow(locations.at(i).y, 2));
        pq.push(pair<double, int>({squareRoot, i}));
        if (pq.size() > k)
            pq.pop();
    }
    vector<Point> kClosestLocations;
    while (!pq.empty())
    {
        Point point = locations.at(pq.top().second);
        pq.pop();
        kClosestLocations.push_back(point);
    }
    return kClosestLocations;
}
vector<Point> KClosestOtherWay(vector<Point> locations, int k)
{
    priority_queue<pair<double, int>, vector<pair<double, int>>> pq;
    double squareRoot;
    for (int i = 0; i < k; i++)
    {
        squareRoot = sqrt(pow(locations.at(i).x, 2) + pow(locations.at(i).y, 2));
        pq.push(pair<double, int>({squareRoot, i}));
    }
    for (int i = k; i < locations.size(); i++)
    {
        double topPointDistance = pq.top().first;
        squareRoot = sqrt(pow(locations.at(i).x, 2) + pow(locations.at(i).y, 2));
        if (topPointDistance > squareRoot)
        {
            pq.pop();
            pq.push(pair<double, int>({squareRoot, i}));
        }
    }
    vector<Point> kClosestLocations;
    while (!pq.empty())
    {
        Point point = locations.at(pq.top().second);
        pq.pop();
        kClosestLocations.push_back(point);
    }
    return kClosestLocations;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<Point> locations = {Point(1, 3), Point(2, 4), Point(2, -1), Point(-2, 2), Point(5, 3), Point(3, -2)};
//     locations = KClosestOtherWay(locations, 3);
//     for (Point point : locations)
//     {
//         cout << "{" << point.x << ",  " << point.y << "}" << endl;
//     }
//     cout << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------- Top K Frequent Elements ----------------------------------------------------------
vector<int> TopKFrequent(vector<int> lists, int k)
{
    unordered_map<int, int> freqCounter;
    int n = lists.size();
    for (int i = 0; i < n; i++)
    {
        freqCounter[lists.at(i)]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    for (auto item : freqCounter)
    {
        minHeap.push(pair<int, int>({item.second, item.first}));
        if (minHeap.size() > k)
        {
            minHeap.pop();
        }
    }
    vector<int> topKFrequency;
    while (!minHeap.empty())
    {
        topKFrequency.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return topKFrequency;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> lists = {1, 3, 5, 14, 18, 14, 5};
//     vector<int> topKFrequency = TopKFrequent(lists, 2);
//     for (auto item : topKFrequency)
//         cout << item << ",  ";
//     cout << endl;
//     cout << string(30, '-') << endl;
//     return 0;
// }
// -------------------------------------------------------- Kth Largest Element in an Array ------------------------------------------------
int FindKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        minHeap.push(nums.at(i));
        if (minHeap.size() > k)
        {
            minHeap.pop();
        }
    }
    return minHeap.top();
}
int FindKthLargestOtherWay(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int n = nums.size();
    for (int i = 0; i < k; i++)
    {
        minHeap.push(nums.at(i));
    }
    for (int i = k; i < n; i++)
    {
        if (nums.at(i) > minHeap.top())
        {
            minHeap.pop();
            minHeap.push(nums.at(i));
        }
    }
    return minHeap.top();
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {1, 2, 12, 2, 11, 9, 7, 30};
//     cout << "Kth Largest Element : " << FindKthLargestOtherWay(nums, 3) << endl;
//     cout << string(30, '-') << endl;
//     return 0;
// }
// --------------------------------------------------- Top K Frequent Words -------------------------------------------------
class customComparator
{
public:
    bool operator()(const pair<int, string> &p1, const pair<int, string> &p2)
    {
        if (p1.first < p2.first)
            return true;
        if (p1.first > p2.first)
            return false;
        return p1.second > p2.second;
    }
};
vector<string> TopKFrequentWords(vector<string> words, int k)
{
    unordered_map<string, int> wordFreqCounter;
    for (auto item : words)
    {
        wordFreqCounter[item]++;
    }
    priority_queue<pair<int, string>, vector<pair<int, string>>, customComparator> pq;
    for (auto item : wordFreqCounter)
    {
        pq.push(pair<int, string>({item.second, item.first}));
    }
    vector<string> topKFrequentWords;
    while (!pq.empty() && k)
    {
        pair<int, string> topPair = pq.top();
        topKFrequentWords.push_back(topPair.second);
        pq.pop();
        k--;
    }
    return topKFrequentWords;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<string> words = {"we", "few", "we", "happy", "few", "we", "band", "of", "brothers"};
//     words = TopKFrequentWords(words, 5);
//     for (auto item : words)
//         cout << item << ", ";
//     cout << endl;
//     cout << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------------------ Binary Search -------------------------------------------------------------------------
bool binarySearch(vector<int> &nums, int target)
{
    int n = nums.size();
    int start = 0, end = n - 1, middle = 0;
    while (start <= end)
    {
        middle = (start + end) / 2;
        if (nums.at(middle) == target)
            return true;
        if (nums.at(middle) < target)
            start = middle + 1;
        else
            end = middle - 1;
    }
    return false;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {3, 12, 22, 56, 75, 98, 102};
//     cout << binarySearch(nums, 3) << endl;
//     cout << string(30, '-') << endl;
//     return 0;
// }
// ----------------------------------------------------- Modified Binary Search: Introduction ---------------------------------------------------------------
// --------------------------------------------- Find the first & last position of an elemnt in sorted array ------------------------------------------------
vector<int> findFirstAndLastPosition(vector<int> &nums, int target)
{
    int start = -1, end = -1, middle = 0, n = nums.size();
    int i = 0, j = n - 1;
    while (i <= j)
    {
        middle = (i + j) / 2;
        if (nums.at(middle) == target)
        {
            start = middle;
            if ((middle - 1) >= 0 && nums.at(middle - 1) == target)
                j = middle - 1;
            else
                break;
        }
        if (nums.at(middle) < target)
            i = middle + 1;
        if (nums.at(middle) > target)
            j = middle - 1;
    }
    i = 0, j = n - 1;
    while (i <= j)
    {
        middle = (i + j) / 2;
        if (nums.at(middle) == target)
        {
            end = middle;
            if ((middle + 1) < n && nums.at(middle + 1) == target)
                i = middle + 1;
            else
                break;
        }
        if (nums.at(middle) < target)
            i = middle + 1;
        if (nums.at(middle) > target)
            j = middle - 1;
    }
    return {start, end};
}
vector<int> findFirstAndLastPositionOtherWay(vector<int> &nums, int target)
{
    int start = -1, end = -1, middle = 0, n = nums.size();
    int i = 0, j = n - 1;
    while (i <= j)
    {
        middle = (i + j) / 2;
        if (nums.at(middle) == target)
        {
            start = middle;
            j = middle - 1;
        }
        if (nums.at(middle) < target)
            i = middle + 1;
        if (nums.at(middle) > target)
            j = middle - 1;
    }
    i = 0, j = n - 1;
    while (i <= j)
    {
        middle = (i + j) / 2;
        if (nums.at(middle) == target)
        {
            end = middle;
            i = middle + 1;
        }
        if (nums.at(middle) < target)
            i = middle + 1;
        if (nums.at(middle) > target)
            j = middle - 1;
    }
    return {start, end};
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {3, 9, 9, 9, 11, 12};
//     vector<int> positions = findFirstAndLastPositionOtherWay(nums, 9);
//     cout << "START : " << positions.at(0) << " END : " << positions.at(1) << endl;
//     cout << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------------- 69. Sqrt(x) ---------------------------------------------------------------------------
int mySqrt(int x)
{
    if (x == 0 || x == 1)
        return x;
    int left = 2, right = x / 2;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (middle * middle == x)
            return middle;
        if (middle * middle < x)
            left = middle + 1;
        if (middle * middle > x)
            right = middle - 1;
    }
    return right;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     cout << mySqrt(8) << endl;
//     cout << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------------------ Binary Search ------------------------------------------------------------------------------
int BinarySearch(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1, middle = 0;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (nums.at(middle) == target)
            return middle;
        if (nums.at(middle) < target)
            left = middle + 1;
        if (nums.at(middle) > target)
            right = middle - 1;
    }
    return -1;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     cout << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------------------ Search in Rotated Sorted Array ------------------------------------------------------------------------------
// ------------------ WRONG ANSWER -----------------
int BinarySearchRotated(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1, middle = 0;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (nums.at(middle) == target)
            return middle;
        else if (nums.at(middle) > target && nums.at(left) > target)
            left = middle + 1;
        else if (nums.at(middle) > target)
            right = middle - 1;
        else if (nums.at(middle) < target && nums.at(right) < target)
            right = middle - 1;
        else if (nums.at(middle) < target)
            left = middle + 1;
    }
    return -1;
}
int BinarySearchRotatedOtherWay(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1, middle = 0;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (nums.at(middle) == target)
            return middle;
        else if (nums.at(middle) > target && nums.at(left) > target)
            left++;
        else if (nums.at(middle) > target)
            right = middle - 1;
        else if (nums.at(middle) < target && nums.at(right) < target)
            right--;
        else if (nums.at(middle) < target)
            left = middle + 1;
    }
    return -1;
}
int BinarySearchRotatedOtherWay2(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1, middle = 0;
    if (left > right)
        return -1;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (nums.at(middle) == target)
            return middle;
        else if (nums.at(left) <= nums.at(middle))
        {
            if (nums.at(left) <= target && target < nums.at(middle))
                right = middle - 1;
            else
                left = middle + 1;
        }
        else if (nums.at(middle) <= nums.at(right))
        {
            if (nums.at(middle) < target && target <= nums.at(right))
                left = middle + 1;
            else
                right = middle - 1;
        }
    }
    return -1;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {4, 5, 1, 2, 3, 4, 5, 6};
//     cout << BinarySearchRotatedOtherWay2(nums, 1) << endl;
//     cout << string(30, '-') << endl;
//     return 0;
// }
// -------------------------------------------------------- First Bad Version -------------------------------------------------------------------
// int firstBadVersion(int n)
// {
//     int left = 0, right = n, middle = 0;
//     int firstBadVersion = -1, totalAPICalls = 0;
//     while (left <= right)
//     {
//         middle = (left + right) / 2;
//         if (isBadVersion(int middle))
//         {
//             firstBadVersion = middle;
//             totalAPICalls++;
//             right = middle-1;
//         }
//         else{
//             left = middle+1;
//         }
//     }
//     return {firstBadVersion, totalAPICalls};
// }
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {4, 5, 1, 2, 3, 4, 5, 6};
//     cout << BinarySearchRotatedOtherWay2(nums, 1) << endl;
//     cout << string(30, '-') << endl;
//     return 0;
// }
// -------------------------------------------------------------------- Random Pick with Weight --------------------------------------------------------------
// -------------- WRONG ANSWER ------------------
// int pickindex(vector<int> weights, int left, int right, int &maxValue)
// {
//     if (left > right)
//         return 0;
//     int maxIndex = 0;
//     int middle = (left + right) / 2;
//     if (weights.at(middle) > maxValue)
//     {
//         maxValue = weights.at(middle);
//         maxIndex = middle;
//     }
//     int leftMaxIndex = pickindex(weights, left, middle - 1, maxValue);
//     int rightMaxIndex = pickindex(weights, middle + 1, right, maxValue);
//     if (weights.at(leftMaxIndex) > weights.at(maxIndex))
//         maxIndex = leftMaxIndex;
//     if (weights.at(rightMaxIndex) > weights.at(maxIndex))
//         maxIndex = rightMaxIndex;
//     return maxIndex;
// }
// -------------------------------
class Solution
{
private:
    vector<int> runningSums;

public:
    Solution(vector<int> &weights)
    {
        int runningSum = 0;
        for (int w : weights)
        {
            runningSum += w;
            runningSums.push_back(runningSum);
        }
    }
    int pickIndex()
    {
        int totalSum = runningSums.back();
        int target = rand() % totalSum;
        target = 18;
        runningSums = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
        int low = 0;
        int high = runningSums.size() - 1;
        while (low < high)
        {
            int middle = (low + high) / 2;
            if (target < runningSums.at(middle))
                high = middle;
            else
                low = middle + 1;
        }
        return low;
    }
};
// class Solution
// {
// private:
//     vector<int> runningSums;

// public:
//     Solution(vector<int> &weights)
//     {
//         int runningSum = 0;
//         for (int w : weights)
//         {
//             runningSum += w;
//             runningSums.push_back(runningSum);
//         }
//     }

//     int pickIndex()
//     {
//         int totalSum = runningSums.back();
//         int target = rand() % totalSum;
//         auto upper = upper_bound(runningSums.begin(), runningSums.end(), target);
//         return upper - runningSums.begin();
//     }
// };

// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> vect = {5, 10, 15, 20, 25, 30};
//     Solution *solution = new Solution(vect);
//     cout << solution->pickIndex() << endl;
//     ;
//     cout << string(30, '-') << endl;
//     return 0;
// }
// ----------------------------------------------------------- Find K Closest Elements --------------------------------------------------------------
bool distanceCompare(const pair<int, int> &x, const pair<int, int> &y)
{
    if (x.first == y.first)
        return x.second < y.second;
    return x.first < y.first;
}
vector<int> FindClosestElements(vector<int> &nums, int k, int target)
{
    vector<pair<int, int>> distances;
    for (int i = 0; i < nums.size(); i++)
    {
        pair<int, int> distance = {abs(nums.at(i) - target), nums.at(i)};
        distances.push_back(pair<int, int>(distance));
    }
    sort(distances.begin(), distances.end(), distanceCompare);
    vector<int> closestElements;
    for (int i = 0; i < k; i++)
    {
        closestElements.push_back(distances.at(i).second);
    }
    sort(closestElements.begin(), closestElements.end());
    return closestElements;
}
// ------------------------
class DistanceCompare
{
public:
    bool operator()(const pair<int, int> &x, const pair<int, int> &y)
    {
        if (x.first == y.first)
            return x.second < y.second;
        return x.first < y.first;
    }
};
vector<int> FindClosestElementsOtherWay(vector<int> &nums, int k, int target)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, DistanceCompare> pq;
    for (int i = 0; i < nums.size(); i++)
    {
        pair<int, int> distance = {abs(nums.at(i) - target), nums.at(i)};
        pq.push(distance);
        if (pq.size() > k)
            pq.pop();
    }
    vector<int> closestElements;
    while (!pq.empty())
    {
        pair<int, int> top = pq.top();
        closestElements.push_back(top.second);
        cout << top.first << " : " << top.second << endl;
        pq.pop();
    }
    sort(closestElements.begin(), closestElements.end());
    return closestElements;
}
// -------------------
int BinarySearchFirstClosest(std::vector<int> &numbersList, int target)
{
    int left = 0;
    int right = numbersList.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (numbersList[mid] == target)
        {
            return mid;
        }
        if (numbersList[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return left;
}
vector<int> FindClosestElementsOtherWay2(vector<int> &nums, int k, int target)
{
    if (nums.size() == k)
    {
        return nums;
    }
    if (target <= nums[0])
    {
        return vector<int>(nums.begin(), nums.begin() + k);
    }
    if (target >= nums[nums.size() - 1])
    {
        return vector<int>(nums.end() - k, nums.end());
    }
    int firstClosest = BinarySearchFirstClosest(nums, target);
    int windowLeft = firstClosest - 1;
    int windowRight = windowLeft + 1;
    while ((windowRight - windowLeft - 1) < k)
    {
        if (windowLeft == -1)
        {
            windowRight += 1;
            continue;
        }
        if (windowRight == nums.size() || abs(nums[windowLeft] - target) <= abs(nums[windowRight] - target))
        {
            windowLeft -= 1;
        }
        else
        {
            windowRight += 1;
        }
    }
    return vector<int>(nums.begin() + windowLeft + 1, nums.begin() + windowRight);
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {25, 41, 81, 85, 103, 117, 319};
//     vector<int> closestElements = FindClosestElementsOtherWay2(nums, 3, 99);
//     for (auto item : closestElements)
//         cout << item << ", ";
//     cout << endl;
//     cout << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------- Single Element in a Sorted Array -----------------------------------------------------------
int SingleNonDuplicate(vector<int> nums)
{
    int i = 0;
    if (nums.size() == 1)
        return nums.at(0);
    while (i < nums.size() - 2)
    {
        if (nums.at(i) != nums.at(i + 1))
            break;
        i += 2;
    }
    return nums.at(i);
}
int SingleNonDuplicateOtherWay(vector<int> nums)
{
    if (nums.size() == 1)
        return nums.at(0);
    int i = 0, j = nums.size() - 1;
    while (i < j)
    {
        if (nums.at(i) != nums.at(i + 1))
            return nums.at(i);
        if (nums.at(j) != nums.at(j - 1))
            return nums.at(j);
        i += 2;
        j -= 2;
    }
    return nums.at(i);
}
int SingleNonDuplicateOtherWay2(vector<int> nums)
{
    if (nums.size() == 1)
        return nums.at(0);
    int n = nums.size();
    int left = 0, right = n - 1, middle;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (middle % 2 == 0)
        {
            if (middle - 1 >= 0 && nums.at(middle) == nums.at(middle - 1))
                right = middle - 1;
            else if (middle + 1 < n && nums.at(middle) == nums.at(middle + 1))
                left = middle + 1;
            else
                break;
        }
        if (middle % 2 != 0)
        {
            if (middle + 1 < n && nums.at(middle) == nums.at(middle + 1))
                right = middle - 1;
            else if (middle - 1 >= 0 && nums.at(middle) == nums.at(middle - 1))
                left = middle + 1;
            else
                break;
        }
    }
    return nums.at(middle);
}
int SingleNonDuplicateOtherWay3(vector<int> nums)
{
    int left = 0, right = nums.size() - 1, middle;
    while (left != right)
    {
        middle = left + (right - left) / 2;
        if (middle % 2 != 0)
            middle -= 1;
        if (nums.at(middle) == nums.at(middle + 1))
            left = middle + 2;
        else
            right = middle;
    }
    return nums.at(left);
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 5, 5};
//     cout << SingleNonDuplicateOtherWay3(nums) << endl;
//     cout << string(30, '-') << endl;
//     return 0;
// }
// -------------------------------------------------------- 81. Search in Rotated Sorted Array II ------------------------------------------------------------------
bool searchInRotatedSortedArray(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.size() - 1, middle;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (nums.at(middle) == target)
            return true;
        if (nums.at(middle) < target)
            left = middle + 1;
        if (nums.at(middle) > target)
            right = middle - 1;
    }
    return false;
}
bool searchInRotatedSortedArrayOtherWay(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1, middle;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (nums.at(middle) == target)
            return true;
        else if (nums.at(middle) > target && nums.at(left) > target)
            left++;
        else if (nums.at(middle) > target)
            right = middle - 1;
        else if (nums.at(middle) < target && nums.at(right) < target)
            right--;
        else if (nums.at(middle) < target)
            left = middle + 1;
    }
    return false;
}
bool searchInRotatedSortedArrayOtherWay2(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1, middle = 0;
    if (left > right)
        return -1;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (nums.at(middle) == target)
            return true;
        else if (nums.at(left) <= nums.at(middle))
        {
            if (nums.at(left) <= target && target < nums.at(middle))
                right = middle - 1;
            else
                left = middle + 1;
        }
        else if (nums.at(middle) <= nums.at(right))
        {
            if (nums.at(middle) < target && target <= nums.at(right))
                left = middle + 1;
            else
                right = middle - 1;
        }
    }
    return false;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {1, 0, 1, 1, 1};
//     cout << "SEARCH : " << searchInRotatedSortedArrayOtherWay2(nums, 0) << endl;
//     // for (auto item : nums)
//     //     cout << item << ", ";
//     // cout << endl;
//     cout << string(30, '-') << endl;
//     return 0;
// }
// -------------------------------------------------------- Subsets: Introduction ---------------------------------------------------------------------
void createSubSets(vector<int> &nums, vector<vector<int>> &subSets, int target)
{
    if (target > nums.size() - 1)
    {
        subSets.push_back({});
        return;
    }
    int n = subSets.size();
    for (int i = 0; i < n; i++)
    {
        vector<int> singleSet = subSets.at(i);
        singleSet.push_back(nums.at(target));
        subSets.push_back(singleSet);
    }
    subSets.push_back({nums.at(target)});
    return createSubSets(nums, subSets, target + 1);
}

// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {4, 5, 5};
//     vector<vector<int>> subSets;
//     createSubSets(nums, subSets, 0);
//     for (auto item : subSets)
//     {
//         cout << "{";
//         for (auto i : item)
//             cout << i << ", ";
//         cout << "}" << endl;
//         ;
//     }
//     cout << string(30, '-') << endl;
//     return 0;
// }
// ---------------------------------------------------------- Subsets -----------------------------------------------------------------------
vector<vector<int>> FindAllSubsets_02(vector<int> nums)
{
    vector<vector<int>> allSubSets;
    allSubSets.push_back({});
    for (int i = 0; i < nums.size(); i++)
    {
        int n = allSubSets.size();
        for (int j = 0; j < n; j++)
        {
            vector<int> subSet = allSubSets.at(j);
            subSet.push_back(nums.at(i));
            allSubSets.push_back(subSet);
        }
    }
    set<vector<int>> uniqueSubSets(allSubSets.begin(), allSubSets.end());
    return {uniqueSubSets.begin(), uniqueSubSets.end()};
}
vector<vector<int>> FindAllSubsetsOtherWay(vector<int> nums)
{
    set<vector<int>> uniqueSubSets;
    for (int i = 0; i < nums.size(); i++)
    {
        set<vector<int>>::iterator endIterator;
        endIterator = uniqueSubSets.end();
        for (auto itr = uniqueSubSets.begin(); itr != endIterator; itr++)
        {
            vector<int> subSet = *itr;
            subSet.push_back(nums.at(i));
            uniqueSubSets.insert(subSet);
        }
        uniqueSubSets.insert({nums.at(i)});
    }
    return {};
}
void findSubsets(int ind, vector<int> &nums, vector<int> &subSet, vector<vector<int>> &allSubSets)
{
    allSubSets.push_back(subSet);
    for (int i = ind; i < nums.size(); i++)
    {
        if (i != ind && nums[i] == nums[i - 1])
            continue;
        subSet.push_back(nums[i]);
        findSubsets(i + 1, nums, subSet, allSubSets);
        subSet.pop_back();
    }
}
vector<vector<int>> AllSubsets(vector<int> &nums)
{
    vector<int> subSet;
    sort(nums.begin(), nums.end());
    vector<vector<int>> allSubSets;
    findSubsets(0, nums, subSet, allSubSets);
    return allSubSets;
}
vector<vector<int>> AllSubsetsOtherWay(vector<int> &nums)
{
    vector<vector<int>> allSubSet;
    int pow_set_size = pow(2, nums.size());
    for (int counter = 0; counter < pow_set_size; counter++)
    {
        vector<int> subSet;
        for (int j = 0; j < nums.size(); j++)
        {
            if (counter & (1 << j))
                subSet.push_back(nums.at(j));
        }
        allSubSet.push_back(subSet);
    }
    return allSubSet;
}
vector<vector<int>> AllSubsetsOtherWay2(vector<int> &nums)
{
    vector<vector<int>> allSubSet;
    int pow_set_size = pow(2, nums.size());
    for (int counter = 0; counter < pow_set_size; counter++)
    {
        vector<int> subSet;
        for (int j = 0; j < nums.size(); j++)
        {
            if (counter & (1 << j))
                subSet.push_back(nums.at(j));
        }
        if (find(allSubSet.begin(), allSubSet.end(), subSet) == allSubSet.end())
            allSubSet.push_back(subSet);
    }
    return allSubSet;
}
int GetBit(int num, int bit)
{
    int temp = (1 << bit);
    temp = temp & num;
    if (temp == 0)
    {
        return 0;
    }
    return 1;
}
vector<vector<int>> FindAllSubsets(vector<int> nums)
{
    vector<vector<int>> sets;
    if (!nums.empty())
    {
        int subsetsCount = (int)(pow(2, nums.size()));
        for (int i = 0; i < subsetsCount; ++i)
        {
            vector<int> subset;
            for (int j = 0; j < nums.size(); ++j)
            {

                if (GetBit(i, j) == 1)
                {
                    int x = nums[j];
                    subset.push_back(x);
                }
            }
            sets.push_back(subset);
        }
    }
    else
    {
        vector<int> emptySet;
        sets.push_back(emptySet);
    }
    return sets;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {1, 2, 2};
//     vector<vector<int>> subSets;
//     subSets = FindAllSubsets(nums);
// for (auto item : subSets)
// {
//     cout << "{";
//     for (auto i : item)
//         cout << i << ", ";
//     cout << "}" << endl;
//     ;
// }
//     cout << string(30, '-') << endl;
//     return 0;
// }
// -------------------------------------------------------------------- Permutations ----------------------------------------------------------------------------
void recurPermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &result, int freq[])
{
    if (ds.size() == nums.size())
    {
        result.push_back(ds);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (!freq[i])
        {
            ds.push_back(nums[i]);
            freq[i] = 1;
            recurPermute(ds, nums, result, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> result;
    vector<int> ds;
    int freq[nums.size()];
    for (int i = 0; i < nums.size(); i++)
        freq[i] = 0;
    recurPermute(ds, nums, result, freq);
    return result;
}
void recurPermuteOtherWay(int currIndex, vector<int> nums, vector<vector<int>> &result)
{
    if (currIndex == nums.size())
    {
        result.push_back(nums);
        return;
    }
    for (int i = currIndex; i < nums.size(); i++)
    {
        swap(nums[currIndex], nums[i]);
        recurPermuteOtherWay(currIndex + 1, nums, result);
        swap(nums[currIndex], nums[i]);
    }
}
vector<vector<int>> permuteOtherWay(vector<int> &nums)
{
    vector<vector<int>> result;
    recurPermuteOtherWay(0, nums, result);
    return result;
}
vector<int> recurPermuteOtherWay2(vector<int> &nums, vector<vector<int>> &result)
{
    if (nums.size() == 1)
        return nums;
    for (int i = 0; i < nums.size(); i++)
    {
        vector<int> smallAnswer = recurPermuteOtherWay2(nums, result);
    }
    return {};
}
vector<vector<int>> permuteOtherWay2(vector<int> &nums)
{
    vector<vector<int>> result;
    recurPermuteOtherWay2(nums, result);
    return result;
}

// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {1, 2, 3};
//     vector<vector<int>> result = permuteOtherWay2(nums);
//     for (auto item : result)
//     {
//         cout << "{";
//         for (auto i : item)
//             cout << i << ", ";
//         cout << "}" << endl;
//         ;
//     }
//     cout << string(30, '-') << endl;
//     return 0;
// }
// ---------------------------------------------------------------------- String Permutation ---------------------------------------------------------------------
void recursivePermuteWord(int currIndex, string &word, vector<string> &result)
{
    if (currIndex == word.size())
    {
        result.push_back(word);
        return;
    }
    for (int i = currIndex; i < word.size(); i++)
    {
        swap(word[currIndex], word[i]);
        recursivePermuteWord(currIndex + 1, word, result);
        swap(word[currIndex], word[i]);
    }
}
vector<string> PermuteWord(string word)
{
    vector<string> result;
    if (!word.empty())
        recursivePermuteWord(0, word, result);
    return result;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     string word = "ABC";
//     vector<string> result = PermuteWord(word);
//     for (auto item : result)
//     {
//         cout << "{";
//         for (auto i : item)
//             cout << i << ", ";
//         cout << "}" << endl;
//         ;
//     }
//     cout << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------------------ Letter Combinations of a Phone Number ----------------------------------------------------------
void recursiveLetterCombinations(vector<string> &words, string &word, vector<string> &result, int wordIndex)
{
    if (word.size() == words.size())
    {
        result.push_back(word);
        return;
    }
    string curr = words.at(wordIndex);
    for (int i = 0; i < curr.size(); i++)
    {
        word.push_back(curr.at(i));
        recursiveLetterCombinations(words, word, result, wordIndex + 1);
        word.pop_back();
    }
}
vector<string> LetterCombinations(string digits)
{
    unordered_map<char, string> digitLetterMap;
    digitLetterMap['1'] = "";
    digitLetterMap['2'] = "abc";
    digitLetterMap['3'] = "def";
    digitLetterMap['4'] = "ghi";
    digitLetterMap['5'] = "jkl";
    digitLetterMap['6'] = "mno";
    digitLetterMap['7'] = "pqrs";
    digitLetterMap['8'] = "tuv";
    digitLetterMap['9'] = "wxyz";
    vector<string> words;
    vector<string> result;
    if (!digits.size())
        return result;
    for (int i = 0; i < digits.size(); i++)
        words.push_back(digitLetterMap[digits[i]]);
    string word = "";
    recursiveLetterCombinations(words, word, result, 0);
    return result;
}
// vector<string> LetterCombinationsOtherway(string digits)
// {
//     unordered_map<char, string> digitLetterMap;
//     digitLetterMap['1'] = "";
//     digitLetterMap['2'] = "abc";
//     digitLetterMap['3'] = "def";
//     digitLetterMap['4'] = "ghi";
//     digitLetterMap['5'] = "jkl";
//     digitLetterMap['6'] = "mno";
//     digitLetterMap['7'] = "pqrs";
//     digitLetterMap['8'] = "tuv";
//     digitLetterMap['9'] = "wxyz";
//     vector<string> result;
//     result.push_back(digitLetterMap[digits.at(0)]);
//     for (int i = 1; i < digits.size(); i++)
//     {
//         int n = result.size();
//         for (int j = 0; j < n; j++)
//         {
//             string str = result.at(j);
//             string target = digitLetterMap[digits.at(i)];
//             for (int l = 0; l < target.size(); l++)
//             {
//                 result.push_back(str + target.at(l));
//             }
//         }
//     }
//     return result;
// }
void Backtrack(int index, vector<char> &path, const string &digits, unordered_map<char, vector<string>> &digitsMapping, vector<string> &combinations)
{
    if (path.size() == digits.size())
    {
        string combination(path.begin(), path.end());
        combinations.push_back(combination);
        return;
    }
    char currentDigit = digits[index];
    vector<string> &possibleLetters = digitsMapping[currentDigit];

    for (const string &letter : possibleLetters)
    {
        path.push_back(letter[0]);
        Backtrack(index + 1, path, digits, digitsMapping, combinations);
        path.pop_back();
    }
}
vector<string> LetterCombinationsOtherWay2(string digits)
{
    vector<string> combinations;
    if (digits.empty())
    {
        return combinations;
    }
    unordered_map<char, vector<string>> digitsMapping = {
        {'1', {""}},
        {'2', {"a", "b", "c"}},
        {'3', {"d", "e", "f"}},
        {'4', {"g", "h", "i"}},
        {'5', {"j", "k", "l"}},
        {'6', {"m", "n", "o"}},
        {'7', {"p", "q", "r", "s"}},
        {'8', {"t", "u", "v"}},
        {'9', {"w", "x", "y", "z"}}};
    vector<char> path;
    Backtrack(0, path, digits, digitsMapping, combinations);
    return combinations;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<string> result = LetterCombinationsOtherWay2("23");
//     for (auto item : result)
//     {
//         cout << "{";
//         for (auto i : item)
//             cout << i << ", ";
//         cout << "}" << endl;
//         ;
//     }
//     cout << string(30, '-') << endl;
//     return 0;
// }
// ----------------------------------------------------------------- Generate Parentheses ------------------------------------------------------------------------
// Backtracking function to generate all combinations of valid balanced parentheses
void BackTrack(string curr, int left_count, int right_count, int n, vector<string> &result)
{
    if (left_count == n && right_count == n)
    {
        result.push_back(curr);
        return;
    }
    if (left_count < n)
        BackTrack(curr + '(', left_count + 1, right_count, n, result);
    if (right_count < left_count)
        BackTrack(curr + ')', left_count, right_count + 1, n, result);
}
// Function to generate all combinations of valid balanced parentheses for a given 'n'
vector<string> GenerateCombinations(int n)

{
    vector<string> result{};
    BackTrack("", 0, 0, n, result);
    return result;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<string> result = GenerateCombinations(3);
//     for (auto item : result)
//     {
//         cout << "{";
//         for (auto i : item)
//             cout << i << ", ";
//         cout << "}" << endl;
//         ;
//     }
//     cout << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------------------ Find K-Sum Subsets ----------------------------------------------------------------------------
void RecursionFun(int index, vector<int> &subSet, vector<vector<int>> &result, int &totalSum, vector<int> &nums, int &targetSum)
{
    if (totalSum == targetSum)
    {
        result.push_back(subSet);
        return;
    }
    if (totalSum > targetSum)
        return;
    for (int i = index; i < nums.size(); i++)
    {
        subSet.push_back(nums.at(i));
        totalSum += nums.at(i);
        RecursionFun(i + 1, subSet, result, totalSum, nums, targetSum);
        subSet.pop_back();
        totalSum -= nums.at(i);
    }
}
vector<vector<int>> GetKSumSubsets(vector<int> nums, int targetSum)
{
    vector<vector<int>> result;
    vector<int> subSet;
    int totalSum = 0;
    RecursionFun(0, subSet, result, totalSum, nums, targetSum);
    return result;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {1, 3, 5, 21, 19, 7, 2};
//     vector<vector<int>> result = GetKSumSubsets(nums, 10);
//     for (auto item : result)
//     {
//         cout << "{";
//         for (auto i : item)
//             cout << i << ", ";
//         cout << "}" << endl;
//     }
//     cout << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------------------ Greedy Techniques: Introduction --------------------------------------------------------------------
// --------------------------------------------------------------------------- Jump Game I --------------------------------------------------------------------------------------
bool JumpGame(vector<int> nums)
{
    int n = nums.size();
    int reachable = 0;
    for (int i = 0; i < n; i++)
    {
        if (i > reachable)
            return false;
        if (nums[i] + i > reachable)
            reachable = nums[i] + i;
        if (reachable >= n - 1)
            break;
    }
    return true;
}
bool JumpGameOtherWay(vector<int> nums)
{
    int n = nums.size();
    if (n == 1)
        return true;
    int currentElement = nums[0];
    for (int i = 1; i < n && nums[0] != 0; i++)
    {
        currentElement--;
        if (currentElement < 0)
        {
            return false;
        }
        if (nums[i] + i >= n - 1)
        {
            return true;
        }
        if (nums[i] > currentElement)
            currentElement = nums[i];
    }
    return false;
}
bool recursiveJumpGame(int index, int reachable, vector<int> &nums)
{
    if (index > reachable)
        return false;
    if (nums[index] + index > reachable)
        reachable = nums[index] + index;
    if (reachable >= nums.size() - 1)
        return true;
    return recursiveJumpGame(index + 1, reachable, nums);
}
bool JumpGameOtherWay2(vector<int> nums)
{
    return recursiveJumpGame(0, 0, nums);
}
bool JumpGameOtherWay3(vector<int> nums)
{
    int n = nums.size();
    int target = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (i + nums.at(i) >= target)
            target = i;
    }
    if (target == 0)
        return true;
    return false;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {3, 2, 1, 0, 4};
//     // vector<int> nums = {3, 2, 2, 0, 4, 5, 2, 1, 0, 5};
//     cout << "JumpGame : " << JumpGameOtherWay3(nums) << endl;
//     cout << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------------------- Boats to Save People -------------------------------------------------------------------------
// --------------- WRONG CODE --------------------
int RescueBoats(vector<int> people, int limit)
{
    int n = people.size();
    int isPersonSafe[n] = {0};
    int totalBoats = 0;
    for (int index = 0; index < n; index++)
    {
        int numOfPerson = 0;
        if (isPersonSafe[index])
            continue;
        int currentWeight = people.at(index);
        numOfPerson++;
        isPersonSafe[index] = 1;
        if (currentWeight == limit)
        {
            totalBoats++;
            continue;
        }
        for (int i = index + 1; i < n; i++)
        {
            if (!isPersonSafe[i] && currentWeight + people.at(i) <= limit)
            {
                isPersonSafe[i] = 1;
                currentWeight += people.at(i);
                numOfPerson++;
            }
            if (numOfPerson == 2 || currentWeight == limit)
                break;
        }
        totalBoats++;
    }
    return totalBoats;
}
int RescueBoatsOtherWay(vector<int> people, int limit)
{
    int n = people.size();
    int totalBoats = 0;
    sort(people.begin(), people.end());
    int left = 0, right = n - 1;
    while (left <= right)
    {
        if (people.at(left) + people.at(right) <= limit)
        {
            left++;
            right--;
        }
        else if (people.at(left) >= people.at(right))
            left++;
        else if (people.at(right) >= people.at(left))
            right--;
        totalBoats++;
    }
    return totalBoats;
}
int RescueBoatsOtherWay03(std::vector<int> people, int limit)
{
    sort(people.begin(), people.end());
    int left = 0;
    int right = people.size() - 1;
    int totalBoats = 0;
    while (left <= right)
    {
        if (people[left] + people[right] <= limit)
            left += 1;
        // We have sorted the array, so the right side person always heavier than left one
        right -= 1;
        totalBoats += 1;
    }
    return totalBoats;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {21, 40, 16, 24, 30};
//     cout << "Total Rescue Boats Are : " << RescueBoatsOtherWay(nums, 50) << endl;
//     cout << string(30, '-') << endl;
//     return 0;
// }
// ---------------------------------------------------------------- Gas Stations ---------------------------------------------------------------------------
// ----------------------- TLE ---------------------------
int GasStationJourney(vector<int> &gas, vector<int> &cost)
{
    int n = gas.size();
    int currentGas = 0;
    for (int i = 0; i < n; i++)
    {
        if (gas[i] >= cost[i])
        {
            currentGas = gas[i];
            for (int j = i + 1; j <= (n + i); j++)
            {
                int index = j % n;
                int currentCost = cost[(j - 1) % n];
                currentGas = (currentGas - currentCost) + gas[index];
                if (i == index && currentGas >= 0)
                    return i;
                if (currentGas < cost[index])
                    break;
            }
        }
    }
    return -1;
}
int GasStationJourneyOtherWay(vector<int> gas, vector<int> cost)
{
    int sumCost = accumulate(cost.begin(), cost.end(), 0);
    int sumGas = accumulate(gas.begin(), gas.end(), 0);
    if (sumCost > sumGas)
    {
        return -1;
    }
    int currentGas = 0, startingIndex = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        currentGas += (gas[i] - cost[i]);
        if (currentGas < 0)
        {
            currentGas = 0;
            startingIndex = i + 1;
        }
    }
    return startingIndex;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> gas = {1, 2, 3, 4, 5};
//     vector<int> cost = {3, 4, 5, 1, 2};
//     cout << "Gas Station Journey Starts At : " << GasStationJourneyOtherWay(gas, cost) << endl;
//     cout << string(30, '-') << endl;
//     return 0;
// }
// --------------------------------------------------------------------- Two City Scheduling --------------------------------------------------------------------------
int TwoCityScheduling(vector<vector<int>> &costs)
{
    int n = costs.size();
    int isScheduled[n] = {0};
    int minimumCost = 0;
    int destinationA = 0;
    int destinationB = 0;
    for (int i = 0; i < n; i++)
    {
        if (destinationA == n / 2 || destinationB == n / 2)
            break;
        vector<int> maxCost = {-1, 0};
        int currMinCostPossible;
        for (int j = 0; j < n; j++)
        {
            if (!isScheduled[j])
            {
                if (maxCost[0] == -1)
                    maxCost[0] = j;
                if (costs[j][0] >= costs[maxCost[0]][maxCost[1]])
                {
                    maxCost[0] = j;
                    maxCost[1] = 0;
                    currMinCostPossible = costs[j][1];
                }
                if (costs[j][1] >= costs[maxCost[0]][maxCost[1]])
                {
                    maxCost[0] = j;
                    maxCost[1] = 1;
                    currMinCostPossible = costs[j][0];
                }
            }
        }
        isScheduled[maxCost[0]] = 1;
        if (maxCost[1] != 0)
            destinationA++;
        else
            destinationB++;
        minimumCost += currMinCostPossible;
    }
    if (destinationA == (n / 2))
    {
        for (int i = 0; i < n; i++)
        {
            if (!isScheduled[i])
            {
                minimumCost += costs[i][1];
                isScheduled[i] = 1;
            }
        }
    }
    if (destinationB == (n / 2))
    {
        for (int i = 0; i < n; i++)
        {
            if (!isScheduled[i])
            {
                minimumCost += costs[i][0];
                isScheduled[i] = 1;
            }
        }
    }
    return minimumCost;
}
// class CustomComparator
// {
// public:
//     bool operator()(vector<int> x, vector<int> y){
//         return false;
//     }
// };
bool fairComparator(vector<int> &x, vector<int> &y)
{
    return (x[0] - x[1]) < (y[0] - y[1]);
}
int TwoCitySchedulingOtherWay(vector<vector<int>> &costs)
{
    sort(costs.begin(), costs.end(), fairComparator);
    int totalMinimumCost = 0, n = costs.size();
    for (int i = 0; i < n / 2; i++)
        totalMinimumCost += costs[i][0];
    for (int i = n / 2; i < n; i++)
        totalMinimumCost += costs[i][1];
    return totalMinimumCost;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<vector<int>> costs = {{259, 770}, {448, 54}, {926, 667}, {184, 139}, {840, 118}, {577, 469}};
//     // vector<vector<int>> costs = {{20, 60}, {10, 50}, {40, 200}, {30, 300}};
//     cout << "Two City Scheduling Minimum Cost : " << TwoCitySchedulingOtherWay(costs) << endl;
//     cout << string(30, '-') << endl;
//     return 0;
// }
// -------------------------------------------------------------------- 64. Minimum Path Sum ----------------------------------------------------------------
// ---------------------- TLE ----------------------
int recursiveMinPathSum(int i, int j, int pathSum, int &row, int &column, vector<vector<int>> &grid)
{
    if (i == (row - 1) && j == (column - 1))
    {
        return pathSum;
    }
    int downSmallAnswer = INT_MAX;
    int rightSmallAnswer = INT_MAX;
    if (i < (row - 1))
    {
        downSmallAnswer = recursiveMinPathSum(i + 1, j, pathSum + grid[i + 1][j], row, column, grid);
    }
    if (j < (column - 1))
    {
        rightSmallAnswer = recursiveMinPathSum(i, j + 1, pathSum + grid[i][j + 1], row, column, grid);
    }
    return (downSmallAnswer < rightSmallAnswer) ? downSmallAnswer : rightSmallAnswer;
}

int minPathSum(vector<vector<int>> &grid)
{
    int row = grid.size();
    int column = grid[0].size();
    int minimumPathSum = grid[0][0];
    int i = 0, j = 0;
    minimumPathSum = recursiveMinPathSum(i, j, minimumPathSum, row, column, grid);
    return minimumPathSum;
}
// ----------------- DP (Dynamic Programming) -----------------------
int minPathSumOtherWay(vector<vector<int>> &grid)
{
    int row = grid.size();
    if (row == 0)
        return 0;
    int column = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(column, 0));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < column; i++)
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    for (int i = 1; i < row; i++)
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < column; j++)
        {
            dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[row - 1][column - 1];
}
// -------------------------
int minSumPathUtil(int i, int j, int &row, int &column, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i == (row - 1) && j == (column - 1))
    {
        dp[i][j] = grid[i][j];
        return dp[i][j];
    }
    int downSmallAnswer = INT_MAX;
    int rightSmallAnswer = INT_MAX;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i < (row - 1))
    {
        downSmallAnswer = grid[i][j] + minSumPathUtil(i + 1, j, row, column, grid, dp);
    }
    if (j < (column - 1))
    {
        rightSmallAnswer = grid[i][j] + minSumPathUtil(i, j + 1, row, column, grid, dp);
    }
    dp[i][j] = (downSmallAnswer < rightSmallAnswer) ? downSmallAnswer : rightSmallAnswer;
    return dp[i][j];
}
int minPathSumOtherWay2(vector<vector<int>> &grid)
{
    int row = grid.size();
    int column = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(column, -1));
    minSumPathUtil(0, 0, row, column, grid, dp);
    return dp[0][0];
}
// ---------------------------
int minSumPathUtilOtherWay(int row, int column, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (row == 0 && column == 0)
    {
        dp[row][column] = grid[row][column];
        return dp[row][column];
    }
    if (dp[row][column] != -1)
        return dp[row][column];
    int upSmallAnswer = INT_MAX;
    int leftSmallAnswer = INT_MAX;
    if (dp[row][column] != -1)
        return dp[row][column];
    if (column > 0)
        leftSmallAnswer = grid[row][column] + minSumPathUtilOtherWay(row, column - 1, grid, dp);
    if (row > 0)
        upSmallAnswer = grid[row][column] + minSumPathUtilOtherWay(row - 1, column, grid, dp);
    dp[row][column] = min(leftSmallAnswer, upSmallAnswer);
    return dp[row][column];
}
int minPathSumOtherWay3(vector<vector<int>> &grid)
{
    int row = grid.size();
    int column = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(column, -1));
    minSumPathUtilOtherWay(row - 1, column - 1, grid, dp);
    return dp[row - 1][column - 1];
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
//     // vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}};
//     cout << "Minimum Path Sum : " << minPathSumOtherWay3(grid) << endl;
//     cout << string(30, '-') << endl;
//     return 0;
// }
// -------------------------------------------------- 33. Search in Rotated Sorted Array ---------------------------------------------
int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (nums[middle] == target)
            return middle;
        else if (nums[left] < nums[middle])
        {
            if (nums[left] <= target && target <= nums[middle])
            {
                right = middle;
            }
            else
            {
                left = middle + 1;
            }
        }
        else if (nums[middle] < nums[right])
        {
            if (nums[middle] <= target && target <= nums[right])
            {
                left = middle;
            }
            else
            {
                right = middle - 1;
            }
        }
    }
    return -1;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
//     cout << "Search : " << search(nums, 3) << endl;
//     cout << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------------ 200. Number of Islands ------------------------------------------------------------------------
// ------------ BFS ---------------
int numIslands(vector<vector<char>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int islandCount = 0;
    queue<pair<int, int>> q;
    vector<vector<int>> visitedNode(m, vector<int>(n, 0));
    for (int row = 0; row < m; row++)
    {
        for (int column = 0; column < n; column++)
        {
            if (visitedNode[row][column] == 1)
            {
                continue;
            }
            if (grid[row][column] == '1')
            {
                islandCount++;
                q.push({row, column});
                visitedNode[row][column] = 1;
                while (!q.empty())
                {
                    pair<int, int> position = q.front();
                    int rowIndex = position.first, columnIndex = position.second;
                    visitedNode[rowIndex][columnIndex] = 1;
                    q.pop();
                    if (rowIndex > 0 && grid[rowIndex - 1][columnIndex] == '1' && visitedNode[rowIndex - 1][columnIndex] == 0)
                    {
                        q.push({rowIndex - 1, columnIndex});
                        visitedNode[rowIndex - 1][columnIndex] = 1;
                    }
                    if (rowIndex < m - 1 && grid[rowIndex + 1][columnIndex] == '1' && visitedNode[rowIndex + 1][columnIndex] == 0)
                    {
                        q.push({rowIndex + 1, columnIndex});
                        visitedNode[rowIndex + 1][columnIndex] = 1;
                    }
                    if (columnIndex > 0 && grid[rowIndex][columnIndex - 1] == '1' && visitedNode[rowIndex][columnIndex - 1] == 0)
                    {
                        q.push({rowIndex, columnIndex - 1});
                        visitedNode[rowIndex][columnIndex - 1] = 1;
                    }
                    if (columnIndex < n - 1 && grid[rowIndex][columnIndex + 1] == '1' && visitedNode[rowIndex][columnIndex + 1] == 0)
                    {
                        q.push({rowIndex, columnIndex + 1});
                        visitedNode[rowIndex][columnIndex + 1] = 1;
                    }
                }
            }
        }
    }
    return islandCount;
}
// ---------------------------------------------
void BFS(int row, int column, vector<vector<int>> &visitedNode, vector<vector<char>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    visitedNode[row][column] = 1;
    queue<pair<int, int>> q;
    q.push({row, column});
    while (!q.empty())
    {
        int rowIndex = q.front().first;
        int columnIndex = q.front().second;
        q.pop();
        // traverse in the neigbours
        // Up
        if (rowIndex > 0 && grid[rowIndex - 1][columnIndex] == '1' && visitedNode[rowIndex - 1][columnIndex] == 0)
        {
            q.push({rowIndex - 1, columnIndex});
            visitedNode[rowIndex - 1][columnIndex] = 1;
        }
        // Down
        if (rowIndex < m - 1 && grid[rowIndex + 1][columnIndex] == '1' && visitedNode[rowIndex + 1][columnIndex] == 0)
        {
            q.push({rowIndex + 1, columnIndex});
            visitedNode[rowIndex + 1][columnIndex] = 1;
        }
        // Left
        if (columnIndex > 0 && grid[rowIndex][columnIndex - 1] == '1' && visitedNode[rowIndex][columnIndex - 1] == 0)
        {
            q.push({rowIndex, columnIndex - 1});
            visitedNode[rowIndex][columnIndex - 1] = 1;
        }
        // Right
        if (columnIndex < n - 1 && grid[rowIndex][columnIndex + 1] == '1' && visitedNode[rowIndex][columnIndex + 1] == 0)
        {
            q.push({rowIndex, columnIndex + 1});
            visitedNode[rowIndex][columnIndex + 1] = 1;
        }
    }
}
int numIslandsOtherWay(vector<vector<char>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int islandCount = 0;
    queue<pair<int, int>> q;
    vector<vector<int>> visitedNode(m, vector<int>(n, 0));
    for (int row = 0; row < m; row++)
    {
        for (int column = 0; column < n; column++)
        {
            if (visitedNode[row][column] == 1)
            {
                continue;
            }
            if (grid[row][column] == '1')
            {
                islandCount++;
                BFS(row, column, visitedNode, grid);
            }
        }
    }
    return islandCount;
}

// int main()
// {
//     cout << string(30, '-') << endl;
//     // vector<vector<char>> grid = {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
//     vector<vector<char>> grid = {{'1', '1', '0', '0', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'}};
//     cout << "Islands Count : " << numIslandsOtherWay(grid) << endl;
//     cout << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------ Minimum Number of Refueling Stops ---------------------------------------
// int main()
// {
//     cout << string(30, '-') << endl;
//     cout << "Islands Count : " << numIslandsOtherWay(grid) << endl;
//     cout << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------- Find a pth of 1s from top-left to bottom-right ------------------------------------------------------
bool findPath(int m, int n, vector<vector<int>> &matrix, vector<pair<int, int>> &pathVect)
{
    if (m < 0 || m == matrix.size() || n < 0 || n == matrix[0].size() || matrix[m][n] == 0)
        return false;
    pathVect.push_back(pair<int, int>(m, n));
    if (m == matrix.size() - 1 && n == matrix[0].size() - 1)
        return true;
    bool right = findPath(m, n + 1, matrix, pathVect);
    if (right)
        return true;
    bool down = findPath(m + 1, n, matrix, pathVect);
    if (down)
        return true;
    pathVect.pop_back();
    return false;
}
bool findPathOtherWay(int m, int n, vector<vector<int>> &matrix)
{
    if (m < 0 || m == matrix.size() || n < 0 || n == matrix[0].size() || matrix[m][n] == 0)
        return false;
    if (m == matrix.size() - 1 && n == matrix[0].size() - 1)
        return true;
    bool right = findPathOtherWay(m, n + 1, matrix);

    if (right)
        return true;
    bool down = findPathOtherWay(m + 1, n, matrix);
    if (down)
        return true;
    matrix[m][n] = 0;
    return false;
}
vector<pair<int, int>> findPathOf1s(vector<vector<int>> matrix)
{
    vector<pair<int, int>> pathVect;
    findPathOtherWay(0, 0, matrix);
    return pathVect;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<vector<int>> matrix = {
//         {1, 1, 1, 1, 0},
//         {0, 1, 0, 0, 0},
//         {0, 1, 1, 1, 0},
//         {0, 0, 0, 1, 0},
//         {1, 1, 1, 1, 1}};
//     vector<pair<int, int>> pathVect = findPathOf1s(matrix);
//     for (auto path : pathVect)
//         cout << "[" << path.first << ", " << path.second << "]"
//              << " -> ";
//     cout << string(30, '-') << endl;
//     return 0;
// }
// ----------------------------------------------------------------------- N-Queens -------------------------------------------------------------------------------
// ---------------------------- WRONG SOLUTION ---------------------------------
bool solveNQueensRecursively(int row, int column, vector<int> &rows, vector<int> &columns, vector<vector<int>> &chessBoard, int n)
{
    if (n == 1)
        return true;
    if (column < 0 || column >= chessBoard.size() || row >= chessBoard.size())
        return false;
    for (int i = column; i < chessBoard.size(); i++)
    {
        if (row > 0 && i < chessBoard.size() - 1 && chessBoard[row - 1][i + 1])
            continue;
        if (!columns[i] && !rows[row])
        {
            rows[row] = 1;
            columns[i] = 1;
            chessBoard[row][i] = 1;
            bool smallAnswer = solveNQueensRecursively(row + 1, i + 2, rows, columns, chessBoard, n - 1);
            if (!smallAnswer)
            {
                rows[row] = 0;
                columns[i] = 0;
                chessBoard[row][i] = 0;
                continue;
            }
            return true;
        }
    }
    for (int i = column; i >= 0; i--)
    {
        if (row > 0 && i > 0 && chessBoard[row - 1][i - 1])
            continue;
        if (!columns[i] && !rows[row])
        {
            rows[row] = 1;
            columns[i] = 1;
            chessBoard[row][i] = 1;
            bool smallAnswer = solveNQueensRecursively(row + 1, i - 2, rows, columns, chessBoard, n - 1);
            if (!smallAnswer)
            {
                rows[row] = 0;
                columns[i] = 0;
                chessBoard[row][i] = 0;
                continue;
            }
            return true;
        }
    }
    return false;
}
// ---------------------------- WRONG SOLUTION ---------------------------------
void solveNQueensRecursivelyOtherway(int row, vector<int> &rows, vector<int> &columns, vector<vector<int>> &chessBoard, int n, int &totalResults)
{
    if (n == 0)
    {
        totalResults++;
        return;
    }
    if (row >= chessBoard.size())
        return;
    for (int i = 0; i < chessBoard.size(); i++)
    {
        if (row > 0 && i < chessBoard.size() - 1 && chessBoard[row - 1][i + 1])
            continue;
        if (row > 0 && i > 0 && chessBoard[row - 1][i - 1])
            continue;
        if (!columns[i] && !rows[row])
        {
            rows[row] = 1;
            columns[i] = 1;
            chessBoard[row][i] = 1;
            solveNQueensRecursivelyOtherway(row + 1, rows, columns, chessBoard, n - 1, totalResults);
            rows[row] = 0;
            columns[i] = 0;
            chessBoard[row][i] = 0;
        }
    }
    return;
}
vector<vector<int>> solveNQueensOtherWay(int n)
{
    vector<vector<int>> chessBoard(n, vector<int>(n, 0));
    vector<int> rows(n, 0);
    vector<int> columns(n, 0);
    int totalResults = 0;
    solveNQueensRecursivelyOtherway(0, rows, columns, chessBoard, n, totalResults);
    return chessBoard;
}
// ---------------------------- WRONG SOLUTION ---------------------------------
void solveNQueensRecursivelyOtherway(int row, vector<int> &rows, vector<int> &columns, vector<string> &chessBoard, int n, vector<vector<string>> &solution)
{
    if (n == 0)
    {
        solution.push_back(chessBoard);
        return;
    }
    if (row >= chessBoard.size())
        return;
    for (int i = 0; i < chessBoard.size(); i++)
    {
        // if (row > 0 && i < chessBoard.size() - 1 && chessBoard[row - 1][i + 1] == 'Q')
        //     continue;
        int col = i;
        bool flag = false;
        for (int m = row; m > 0; m--)
        {
            if (col < chessBoard.size() - 1 && chessBoard[m - 1][col + 1] == 'Q')
            {
                flag = true;
                break;
            }
            col++;
        }
        if (flag)
            continue;
        // if (row > 0 && i > 0 && chessBoard[row - 1][i - 1] == 'Q')
        //     continue;
        col = i;
        for (int m = row; m > 0; m--)
        {
            if (col < chessBoard.size() - 1 && chessBoard[m - 1][col - 1] == 'Q')
            {
                flag = true;
                break;
            }
            col--;
        }
        if (flag)
            continue;
        if (!columns[i] && !rows[row])
        {
            rows[row] = 1;
            columns[i] = 1;
            chessBoard[row][i] = 'Q';
            solveNQueensRecursivelyOtherway(row + 1, rows, columns, chessBoard, n - 1, solution);
            rows[row] = 0;
            columns[i] = 0;
            chessBoard[row][i] = '.';
        }
    }
    return;
}
// ---------------------------------- WORKING SOLUTION -------------------------------------
void solveNQueensRecursivelyOtherway2(int row, vector<int> &rows, vector<int> &columns, vector<string> &chessBoard, int n, vector<vector<string>> &solution)
{
    if (n == 0)
    {
        solution.push_back(chessBoard);
        return;
    }
    if (row >= chessBoard.size())
        return;
    for (int i = 0; i < chessBoard.size(); i++)
    {
        int col = i;
        bool flag = false;
        // Check For Upper Diagonal Right
        for (int m = row; m > 0; m--)
        {
            if (col < chessBoard.size() - 1 && chessBoard[m - 1][col + 1] == 'Q')
            {
                flag = true;
                break;
            }
            col++;
        }
        if (flag)
            continue;
        col = i;
        // Check For Upper Diagonal Left
        for (int m = row; m > 0; m--)
        {
            if (col > 0 && chessBoard[m - 1][col - 1] == 'Q')
            {
                flag = true;
                break;
            }
            col--;
        }
        if (flag)
            continue;
        if (!columns[i] && !rows[row])
        {
            rows[row] = 1;
            columns[i] = 1;
            chessBoard[row][i] = 'Q';
            solveNQueensRecursivelyOtherway2(row + 1, rows, columns, chessBoard, n - 1, solution);
            rows[row] = 0;
            columns[i] = 0;
            chessBoard[row][i] = '.';
        }
    }
    return;
}
void solveNQueensRecursivelyOtherway3(int column, vector<int> &rows, vector<int> &columns, vector<string> &chessBoard, int n, vector<vector<string>> &solution)
{
    if (n == 0)
    {
        solution.push_back(chessBoard);
        return;
    }
    if (column >= chessBoard.size())
        return;
    for (int i = 0; i < chessBoard.size(); i++)
    {
        int col = column;
        bool flag = false;
        for (int m = i; m > 0; m--)
        {
            if (col > 0 && chessBoard[m - 1][col - 1] == 'Q')
            {
                flag = true;
                break;
            }
            col--;
        }
        if (flag)
            continue;
        col = column;
        for (int m = i; m < chessBoard.size() - 1; m++)
        {
            if (col > 0 && chessBoard[m + 1][col - 1] == 'Q')
            {
                flag = true;
                break;
            }
            col--;
        }
        if (flag)
            continue;
        if (!columns[column] && !rows[i])
        {
            rows[i] = 1;
            columns[column] = 1;
            chessBoard[i][column] = 'Q';
            solveNQueensRecursivelyOtherway3(column + 1, rows, columns, chessBoard, n - 1, solution);
            rows[i] = 0;
            columns[column] = 0;
            chessBoard[i][column] = '.';
        }
    }
    return;
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> solution;
    vector<string> chessBoard;
    // string rowString;
    // for (int i = 0; i < n; i++)
    //     rowString.append(".");
    string rowString(n, '.');
    for (int i = 0; i < n; i++)
        chessBoard.push_back(rowString);
    vector<int> rows(n, 0);
    vector<int> columns(n, 0);
    solveNQueensRecursivelyOtherway3(0, rows, columns, chessBoard, n, solution);
    return solution;
}
void solveNQueensRecursivelyBestWay(int row, vector<int> &rows, vector<int> &columns, vector<string> &chessBoard, int n, vector<vector<string>> &solution, vector<int> &upperLeftDiagonal, vector<int> &upperRightDiagonal)
{
    if (row == n)
    {
        solution.push_back(chessBoard);
        return;
    }
    for (int column = 0; column < n; column++)
    {
        if (!columns[column] && !rows[row] && upperLeftDiagonal[(n - 1) + (row - column)] == 0 && upperRightDiagonal[row + column] == 0)
        {
            rows[row] = 1;
            columns[column] = 1;
            upperLeftDiagonal[(n - 1) + (row - column)] = 1;
            upperRightDiagonal[row + column] = 1;
            chessBoard[row][column] = 'Q';
            solveNQueensRecursivelyBestWay(row + 1, rows, columns, chessBoard, n, solution, upperLeftDiagonal, upperRightDiagonal);
            rows[row] = 0;
            columns[column] = 0;
            upperLeftDiagonal[(n - 1) + (row - column)] = 0;
            upperRightDiagonal[row + column] = 0;
            chessBoard[row][column] = '.';
        }
    }
    return;
}
vector<vector<string>> solveNQueensOtherWay2(int n)
{
    vector<vector<string>> solution;
    vector<string> chessBoard;
    string rowString(n, '.');
    for (int i = 0; i < n; i++)
        chessBoard.push_back(rowString);
    vector<int> rows(n, 0);
    vector<int> columns(n, 0);
    vector<int> upperRightDiagonal((2 * n) - 1, 0);
    vector<int> upperLeftDiagonal((2 * n) - 1, 0);
    solveNQueensRecursivelyBestWay(0, rows, columns, chessBoard, n, solution, upperLeftDiagonal, upperRightDiagonal);
    return solution;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<vector<string>> queen = solveNQueensOtherWay2(4);
//     cout << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------------------ Word Search ------------------------------------------------------------------------
bool existRecusrsiveCall(int row, int column, vector<vector<char>> &board, string &word, string &str, int targetIndex, vector<vector<int>> &isVisited)
{
    if (str == word)
        return true;
    if (row < 0 || column < 0 || row >= board.size() || column >= board[0].size())
        return false;
    bool isExists;
    if (board[row][column] == word[targetIndex] && isVisited[row][column] == 0)
    {
        str += board[row][column];
        isVisited[row][column] = 1;
        // Horizontal Right Call
        isExists = existRecusrsiveCall(row, column + 1, board, word, str, targetIndex + 1, isVisited);
        if (isExists)
            return true;
        // Horizontal Left Call
        isExists = existRecusrsiveCall(row, column - 1, board, word, str, targetIndex + 1, isVisited);
        if (isExists)
            return true;
        // Vertical Bottom Call
        isExists = existRecusrsiveCall(row + 1, column, board, word, str, targetIndex + 1, isVisited);
        if (isExists)
            return true;
        // Vertical Up Call
        isExists = existRecusrsiveCall(row - 1, column, board, word, str, targetIndex + 1, isVisited);
        if (isExists)
            return true;
        str.pop_back();
        isVisited[row][column] = 0;
    }
    return false;
}
bool exist(vector<vector<char>> &board, string &word)
{
    int m = board.size();
    int n = board[0].size();
    vector<vector<int>> isVisited(m, vector<int>(n, 0));
    for (int row = 0; row < m; row++)
    {
        for (int column = 0; column < n; column++)
        {
            if (board[row][column] == word[0])
            {
                string str;
                if (existRecusrsiveCall(row, column, board, word, str, 0, isVisited))
                    return true;
            }
        }
    }
    return false;
}
// --------------------
bool existRecusrsiveCallOtherWay(int row, int column, vector<vector<char>> &board, string &word, int targetIndex, vector<vector<int>> &isVisited)
{
    if (targetIndex == word.size())
        return true;
    if (row < 0 || column < 0 || row >= board.size() || column >= board[0].size())
        return false;
    bool isExists;
    if (board[row][column] == word[targetIndex] && isVisited[row][column] == 0)
    {
        isVisited[row][column] = 1;
        // Horizontal Right Call
        isExists = existRecusrsiveCallOtherWay(row, column + 1, board, word, targetIndex + 1, isVisited);
        if (isExists)
            return true;
        // Horizontal Left Call
        isExists = existRecusrsiveCallOtherWay(row, column - 1, board, word, targetIndex + 1, isVisited);
        if (isExists)
            return true;
        // Vertical Bottom Call
        isExists = existRecusrsiveCallOtherWay(row + 1, column, board, word, targetIndex + 1, isVisited);
        if (isExists)
            return true;
        // Vertical Up Call
        isExists = existRecusrsiveCallOtherWay(row - 1, column, board, word, targetIndex + 1, isVisited);
        if (isExists)
            return true;
        isVisited[row][column] = 0;
    }
    return false;
}
bool existOtherWay(vector<vector<char>> &board, string &word)
{
    int m = board.size();
    int n = board[0].size();
    vector<vector<int>> isVisited(m, vector<int>(n, 0));
    for (int row = 0; row < m; row++)
    {
        for (int column = 0; column < n; column++)
        {
            if (board[row][column] == word[0])
            {
                if (existRecusrsiveCallOtherWay(row, column, board, word, 0, isVisited))
                    return true;
            }
        }
    }
    return false;
}
// ----------------- Without Using Any Extra Space--------
bool existRecusrsiveCall(int row, int column, vector<vector<char>> &board, string &word, int targetIndex)
{
    if (targetIndex == word.size())
        return true;
    if (row < 0 || column < 0 || row >= board.size() || column >= board[0].size())
        return false;
    bool isExists;
    if (board[row][column] == word[targetIndex])
    {
        char visited = board[row][column];
        board[row][column] = '.';
        // board[row][column] -= 65; // Without using any extra space
        // Horizontal Right Call
        isExists = existRecusrsiveCall(row, column + 1, board, word, targetIndex + 1);
        if (isExists)
            return true;
        // Horizontal Left Call
        isExists = existRecusrsiveCall(row, column - 1, board, word, targetIndex + 1);
        if (isExists)
            return true;
        // Vertical Bottom Call
        isExists = existRecusrsiveCall(row + 1, column, board, word, targetIndex + 1);
        if (isExists)
            return true;
        // Vertical Up Call
        isExists = existRecusrsiveCall(row - 1, column, board, word, targetIndex + 1);
        if (isExists)
            return true;
        board[row][column] = visited;
        // board[row][column] += 65;
    }
    return false;
}
bool existOtherWay2(vector<vector<char>> &board, string &word)
{
    int m = board.size();
    int n = board[0].size();
    for (int row = 0; row < m; row++)
    {
        for (int column = 0; column < n; column++)
        {
            if (board[row][column] == word[0])
            {
                if (existRecusrsiveCall(row, column, board, word, 0))
                    return true;
            }
        }
    }
    return false;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
//     string word = "ABCCED";
//     cout << existOtherWay2(board, word) << endl;
//     cout << string(30, '-') << endl;
//     return 0;
// }
// --------------------------------------------------------------------- Flood Fill -------------------------------------------------------------------
void recursiveFloodFill(vector<vector<int>> &grid, int row, int column, int target, int sourceValue)
{
    if (row < 0 || column < 0 || row > grid.size() - 1 || column > grid[0].size() - 1)
        return;
    if (grid[row][column] == sourceValue)
    {
        grid[row][column] = target;
        recursiveFloodFill(grid, row - 1, column, target, sourceValue); // Up
        recursiveFloodFill(grid, row + 1, column, target, sourceValue); // Down
        recursiveFloodFill(grid, row, column - 1, target, sourceValue); // Left
        recursiveFloodFill(grid, row, column + 1, target, sourceValue); // Right
    }
}
vector<vector<int>> FloodFill(vector<vector<int>> &grid, int sr, int sc, int target)
{
    int sourceValue = grid[sr][sc];
    if (sourceValue == target)
        return grid;
    recursiveFloodFill(grid, sr, sc, target, sourceValue);
    return grid;
}
// ------------------------
void recursiveFloodFillOtherWay(vector<vector<int>> &grid, int row, int column, int target, int sourceValue, vector<vector<int>> &dp)
{
    if (grid[row][column] == sourceValue)
    {
        grid[row][column] = target;
        dp[row][column] = 1;
        if (row - 1 >= 0 && dp[row - 1][column] != 1)
            recursiveFloodFillOtherWay(grid, row - 1, column, target, sourceValue, dp); // Up
        if (row + 1 < grid.size() && dp[row + 1][column] != 1)
            recursiveFloodFillOtherWay(grid, row + 1, column, target, sourceValue, dp); // Down
        if (column - 1 >= 0 && dp[row][column - 1] != 1)
            recursiveFloodFillOtherWay(grid, row, column - 1, target, sourceValue, dp); // Left
        if (column + 1 < grid[0].size() && dp[row][column + 1] != 1)
            recursiveFloodFillOtherWay(grid, row, column + 1, target, sourceValue, dp); // Right
    }
}
vector<vector<int>> FloodFillOtherWay(vector<vector<int>> &grid, int sr, int sc, int target)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int sourceValue = grid[sr][sc];
    if (sourceValue == target)
        return grid;
    recursiveFloodFillOtherWay(grid, sr, sc, target, sourceValue, dp);
    return grid;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     // vector<vector<int>> grid = {{4, 4, 1, 4}, {1, 4, 1, 4}, {4, 4, 4, 1}, {1, 4, 1, 4}};
//     // vector<vector<int>> grid = {{1, 1, 0, 1}, {0, 0, 1, 1}, {0, 1, 1, 0}, {1, 1, 0, 1}};
//     vector<vector<int>> grid = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
//     FloodFillOtherWay(grid, 1, 1, 2);
//     cout << string(30, '-') << endl;
// }
// ------------------------------------------------------------------------ Sudoku Solver -------------------------------------------------------------------------
bool checkInMatrix(vector<vector<char>> &board, int row, int column, char data)
{
    for (int i = row; i < row + 3; i++)
    {
        for (int j = column; j < column + 3; j++)
        {
            if (board[i][j] == data)
                return false;
        }
    }
    return true;
}
bool isPossible(vector<vector<char>> &board, unordered_map<int, unordered_map<char, int>> &rowMapping, unordered_map<int, unordered_map<char, int>> &collMapping, int row, int column, char data)
{
    if (rowMapping[row][data] == 1 || collMapping[column][data] == 1)
        return false;
    if (row >= 0 && row <= 2)
    {
        if (column >= 0 && column <= 2)
            return checkInMatrix(board, 0, 0, data);
        if (column >= 3 && column <= 5)
            return checkInMatrix(board, 0, 3, data);
        if (column >= 6 && column <= 8)
            return checkInMatrix(board, 0, 6, data);
    }
    if (row >= 3 && row <= 5)
    {
        if (column >= 0 && column <= 2)
            return checkInMatrix(board, 3, 0, data);
        if (column >= 3 && column <= 5)
            return checkInMatrix(board, 3, 3, data);
        if (column >= 6 && column <= 8)
            return checkInMatrix(board, 3, 6, data);
    }
    if (row >= 6 && row <= 8)
    {
        if (column >= 0 && column <= 2)
            return checkInMatrix(board, 6, 0, data);
        if (column >= 3 && column <= 5)
            return checkInMatrix(board, 6, 3, data);
        if (column >= 6 && column <= 8)
            return checkInMatrix(board, 6, 6, data);
    }
}
bool solveSudokuRecursive(vector<vector<char>> &board, unordered_map<int, unordered_map<char, int>> &rowMapping, unordered_map<int, unordered_map<char, int>> &collMapping, int row)
{
    for (int i = row; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
            {
                for (int data = 1; data <= 9; data++)
                {
                    bool flag = isPossible(board, rowMapping, collMapping, i, j, data + 48);
                    if (flag)
                    {
                        board[i][j] = data + 48;
                        rowMapping[i][board[i][j]] = 1;
                        collMapping[j][board[i][j]] = 1;
                        bool isSudokuResolved = solveSudokuRecursive(board, rowMapping, collMapping, i);
                        if (isSudokuResolved)
                            return true;
                        rowMapping[i][board[i][j]] = 0;
                        collMapping[j][board[i][j]] = 0;
                        board[i][j] = '.';
                    }
                    if (!flag && data == 9)
                        return false;
                }
            }
        }
    }
    return true;
}
vector<vector<char>> solveSudoku(vector<vector<char>> &board)
{
    unordered_map<int, unordered_map<char, int>> rowMapping;
    unordered_map<int, unordered_map<char, int>> collMapping;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                rowMapping[i][board[i][j]] = 1;
                collMapping[j][board[i][j]] = 1;
            }
        }
    }
    solveSudokuRecursive(board, rowMapping, collMapping, 0);
    return board;
}
int main()
{
    cout << string(30, '-') << endl;
    // vector<vector<char>> board = {{'5', '3', '.', '6', '7', '8', '9', '.', '2'},
    //                               {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
    //                               {'.', '9', '8', '3', '4', '2', '5', '6', '7'},
    //                               {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
    //                               {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
    //                               {'7', '1', '3', '9', '.', '4', '8', '5', '6'},
    //                               {'9', '6', '.', '5', '3', '7', '2', '8', '4'},
    //                               {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
    //                               {'3', '4', '5', '2', '8', '6', '1', '7', '9'}};
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    solveSudoku(board);
    cout << string(30, '-') << endl;
}