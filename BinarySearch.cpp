#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------------------ 704. Binary Search ------------------------------------------------------------------------------------
int binarySearch(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        else if (target > nums[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
// --------------
int binarySearchHelper(vector<int> &nums, int left, int right, int target)
{
    if (left > right)
        return -1;
    int middle = (left + right) / 2;
    int element = nums[middle];
    if (element == target)
        return middle;
    else if (element < target)
        return binarySearchHelper(nums, middle + 1, right, target);
    return binarySearchHelper(nums, left, middle - 1, target);
}
int binarySearchRecursive(vector<int> &nums, int target)
{
    int n = nums.size();
    int left = 0, right = n - 1;
    return binarySearchHelper(nums, left, right, target);
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {-1, 0, 3, 5, 9, 12};
//     // cout << binarySearch(nums, 9) << endl;
//     cout << binarySearchRecursive(nums, 9) << endl;
//     cout << endl
//          << string(30, '-');
// }
// ------------------------------------------------------------------------ Floor in a Sorted Array ------------------------------------------------------------------------------------
int findFloor(vector<long long> &v, long long n, long long x)
{
    if (v[0] > x)
        return -1;
    int left = 0, right = n - 1;
    int middle;
    while (left <= right)
    {
        middle = left + (right - left) / 2;
        int element = v[middle];
        if (element <= x && v[middle + 1] > x)
            return middle;
        else if (element < x)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return middle;
}
int main()
{
    cout << string(30, '-') << endl;
    vector<long long> v = {1, 2, 8, 10, 11, 12, 19};
    cout << findFloor(v, v.size(), 5) << endl;
    cout << endl
         << string(30, '-');
}