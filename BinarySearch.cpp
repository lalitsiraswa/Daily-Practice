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
int main()
{
    cout << string(30, '-') << endl;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    // cout << binarySearch(nums, 9) << endl;
    cout << binarySearchRecursive(nums, 9) << endl;
    cout << endl
         << string(30, '-');
}
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int rowCount = matrix.size();
    int columnCount = matrix[0].size();
    int row = 0;
    while (row < rowCount)
    {
        int minimum = matrix[row][0];
        int maximum = matrix[row][columnCount - 1];
        if (minimum <= target && maximum >= target)
            break;
        row++;
    }
    if (row == rowCount)
        return false;
    int left = 0;
    int right = columnCount - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        int element = matrix[row][middle];
        if (element == target)
            return true;
        else if (element < target)
            left++;
        else
            right--;
    }
    return false;
}
