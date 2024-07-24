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
int main()
{
    cout << string(30, '-') << endl;
    vector<int> arr = {12, 35, 1, 10, 34, 1};
    cout << print2largest3(arr);
    cout << endl
         << string(30, '-');
}