#include <bits/stdc++.h>
using namespace std;

// -------------------------------------------------------------- Largest Element in Array ------------------------------------------------------------
int largestElement(vector<int> &arr, int n)
{
    int largestElement = 0;
    int leftPointer = 0, rightPointer = n - 1;
    while (leftPointer <= rightPointer)
    {
        largestElement = max(largestElement, max(arr[leftPointer], arr[rightPointer]));
        leftPointer++;
        rightPointer--;
    }
    return largestElement;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> arr = {3, 2, 1, 5, 2};
//     cout << largestElement(arr, arr.size());
//     cout << endl
//          << string(30, '-');
// }
// -------------------------------------------------------------- Second Largest Element in Array ------------------------------------------------------------
// ---------- Prefer One -----------
int print2largest(vector<int> &arr)
{
    int firstLargestElement = arr[0], secondLargestElement = -1;
    for (int index = 1; index < arr.size(); index++)
    {
        if (firstLargestElement < arr[index])
        {
            secondLargestElement = firstLargestElement;
            firstLargestElement = arr[index];
        }
        else if (secondLargestElement < arr[index] && arr[index] != firstLargestElement)
            secondLargestElement = arr[index];
    }
    return secondLargestElement;
}
// ---------
int print2largest2(vector<int> &arr)
{
    int firstLargestElement = 0, secondLargestElement = 0;
    for (int index = 0; index < arr.size(); index++)
    {
        if (firstLargestElement < arr[index])
        {
            secondLargestElement = firstLargestElement;
            firstLargestElement = arr[index];
        }
        else if (secondLargestElement < arr[index] && arr[index] != firstLargestElement)
            secondLargestElement = arr[index];
    }
    return secondLargestElement == 0 ? -1 : secondLargestElement;
}
// -----------
int print2largest3(vector<int> &arr)
{
    int firstLargestElement = 0, secondLargestElement = -1;
    int n = arr.size();
    for (int index = 0; index < n; index++)
    {
        if (firstLargestElement < arr[index])
            firstLargestElement = arr[index];
    }
    for (int index = 0; index < n; index++)
    {
        if (arr[index] > secondLargestElement && arr[index] != firstLargestElement)
            secondLargestElement = arr[index];
    }
    return secondLargestElement;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> arr = {12, 35, 1, 10, 34, 1};
//     cout << print2largest3(arr);
//     cout << endl
//          << string(30, '-');
// }
// -------------------------------------------------------------- Second Largest Element in Array ------------------------------------------------------------
int find2ndLargest(vector<int> &arr, int n)
{
    int firstLargest = arr[0];
    int secondLargest = INT_MIN;
    for (int index = 1; index < n; index++)
    {
        if (firstLargest < arr[index])
            firstLargest = arr[index];
    }
    for (int index = 0; index < n; index++)
    {
        if (arr[index] > secondLargest && arr[index] != firstLargest)
            secondLargest = arr[index];
    }
    return secondLargest;
}
int find2ndSmallest(vector<int> &arr, int n)
{
    int firstSmallest = arr[0];
    int secondSmallest = INT_MAX;
    for (int index = 1; index < n; index++)
    {
        if (firstSmallest > arr[index])
            firstSmallest = arr[index];
    }
    for (int index = 0; index < n; index++)
    {
        if (arr[index] < secondSmallest && arr[index] != firstSmallest)
            secondSmallest = arr[index];
    }
    return secondSmallest;
}
int findSecondLargest(vector<int> &arr, int n)
{
    int firstLargest = arr[0];
    int secondLargest = INT_MIN;
    for (int index = 1; index < n; index++)
    {
        if (firstLargest < arr[index])
        {
            secondLargest = firstLargest;
            firstLargest = arr[index];
        }
        else if (secondLargest < arr[index] && arr[index] < firstLargest)
            secondLargest = arr[index];
    }
    return secondLargest;
}
int findSecondSmallest(vector<int> &arr, int n)
{
    int firstSmallest = arr[0];
    int secondSmallest = INT_MAX;
    for (int index = 1; index < n; index++)
    {
        if (firstSmallest > arr[index])
        {
            secondSmallest = firstSmallest;
            firstSmallest = arr[index];
        }
        else if (secondSmallest > arr[index] && arr[index] > firstSmallest)
            secondSmallest = arr[index];
    }
    return secondSmallest;
}
vector<int> getSecondOrderElements(int n, vector<int> a)
{
    return {findSecondLargest(a, n), findSecondSmallest(a, n)};
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> arr = {3, 4, 5, 2};
//     vector<int> result = getSecondOrderElements(arr.size(), arr);
//     cout << "{" << result[0] << ", " << result[1] << "}";
//     cout << endl
//          << string(30, '-');
// }
// -------------------------------------------------------------- 1752. Check if Array Is Sorted and Rotated ------------------------------------------------------------
bool check(vector<int> &nums)
{
    int n = nums.size();
    int index = 1;
    int firstElement = nums[0];
    while (index < n)
    {
        if (nums[index] >= nums[index - 1])
            index++;
        else
            break;
    }
    if (index < n && nums[index] > firstElement)
        return false;
    index++;
    while (index < n)
    {
        if (nums[index] >= nums[index - 1] && nums[index] <= firstElement)
            index++;
        else
            return false;
    }
    return true;
}
// -------------------
bool check2(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    // Check if the array is non-decreasing
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] > nums[i])
            count++;
    }
    // Check if the last element is greater than the first element
    if (nums[n - 1] > nums[0])
        count++;
    // If the count of violations is less than or equal to 1, return true
    return count <= 1;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {3, 4, 5, 1, 2};
//     cout << check2(nums);
//     cout << endl
//          << string(30, '-');
// }
// -------------------------------------------------------------- 26. Remove Duplicates from Sorted Array ------------------------------------------------------------
int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    int previous = 0;
    int current = 1;
    for (int current = 1; current < n; current++)
    {
        if (nums[current] != nums[previous])
        {
            nums[previous + 1] = nums[current];
            previous++;
        }
    }
    return previous + 1;
}
// --------------
int removeDuplicates2(vector<int> &nums)
{
    int n = nums.size();
    int previous = 0;
    int current = 1;
    while (current < n)
    {
        if (nums[current] == nums[current - 1])
            current++;
        else
        {
            nums[previous] = nums[current - 1];
            previous++;
            current++;
        }
    }
    if (previous > 0 && nums[current - 1] != nums[previous - 1])
        nums[previous] = nums[current - 1];
    return previous + 1;
}
// --------------
int removeDuplicates3(vector<int> &nums)
{
    int n = nums.size();
    int previous = 0;
    int current = 1;
    while (current < n)
    {
        if (nums[current] != nums[current - 1])
        {
            nums[previous] = nums[current - 1];
            previous++;
        }
        current++;
    }
    if (previous > 0 && nums[current - 1] != nums[previous - 1])
        nums[previous] = nums[current - 1];
    return previous + 1;
}
int main()
{
    cout << string(30, '-') << endl;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << removeDuplicates3(nums);
    cout << endl
         << string(30, '-');
}