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
    int low = 0, high = n - 1;
    int floorIndex = -1;
    while (low <= high)
    {
        int middle = low + (high - low) / 2;
        int element = v[middle];
        if (element <= x)
        {
            floorIndex = middle;
            low = middle + 1;
        }
        else
            high = middle - 1;
    }
    return floorIndex;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<long long> v = {1, 2, 8, 10, 11, 12, 19};
//     cout << findFloor(v, v.size(), 5) << endl;
//     cout << endl
//          << string(30, '-');
// }
// ------------------------------------------------------------------------ Ceil The Floor ------------------------------------------------------------------------------------
vector<int> getFloorAndCeil(int x, vector<int> &arr)
{
    vector<int> result;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    // Find Floor
    int floor = -1;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int middle = low + (high - low) / 2;
        int element = arr[middle];
        if (element <= x)
        {
            floor = element;
            low = middle + 1;
        }
        else
            high = middle - 1;
    }
    result.push_back(floor);
    // Find Ceil
    int ceil = -1;
    low = 0, high = n - 1;
    while (low <= high)
    {
        int middle = low + (high - low) / 2;
        int element = arr[middle];
        if (element >= x)
        {
            ceil = element;
            high = middle - 1;
        }
        else
            low = middle + 1;
    }
    result.push_back(ceil);
    return result;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     // vector<int> arr = {5, 6, 8, 9, 6, 5, 5, 6};
//     // vector<int> result = getFloorAndCeil(7, arr);
//     // vector<int> arr = {5, 6, 8, 8, 6, 5, 5, 6};
//     // vector<int> result = getFloorAndCeil(10, arr);
//     vector<int> arr = {94, 51, 22, 55, 94, 3, 78, 57, 15};
//     vector<int> result = getFloorAndCeil(94, arr);
//     cout << result[0] << ", " << result[1] << endl;
//     cout << string(30, '-');
// }
// ------------------------------------------------------------------------ 35. Search Insert Position ------------------------------------------------------------------------------------
int searchInsert(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int middle = low + (high - low) / 2;
        int element = nums[middle];
        if (element == target)
            return middle;
        else if (element < target)
            low = middle + 1;
        else
            high = middle - 1;
    }
    return low;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     // vector<int> nums = {1, 3, 5, 6};
//     vector<int> nums = {5, 6, 7, 8, 9, 10};
//     cout << searchInsert(nums, 15) << endl;
//     cout << endl
//          << string(30, '-');
// }
// ----------------------------------------------------- 34. Find First and Last Position of Element in Sorted Array -----------------------------------------------------------------
vector<int> searchRange(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> result;
    // Find first position
    int firstIIndex = -1;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int middle = low + (high - low) / 2;
        int element = nums[middle];
        if (element == target)
        {
            firstIIndex = middle;
            high = middle - 1;
        }
        else if (element < target)
            low = middle + 1;
        else
            high = middle - 1;
    }
    result.push_back(firstIIndex);
    // Find last position
    int lastIndex = -1;
    low = 0, high = n - 1;
    while (low <= high)
    {
        int middle = low + (high - low) / 2;
        int element = nums[middle];
        if (element == target)
        {
            lastIndex = middle;
            low = middle + 1;
        }
        else if (element < target)
            low = middle + 1;
        else
            high = middle - 1;
    }
    result.push_back(lastIndex);
    return result;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {5, 7, 7, 8, 8, 10};
//     vector<int> result = searchRange(nums, 6);
//     cout << result[0] << ", " << result[1] << endl;
//     cout << endl
//          << string(30, '-');
// }
// ------------------------------------------------------------------ 33. Search in Rotated Sorted Array ---------------------------------------------------------------------------
int search(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        if (nums[left] <= nums[mid])
        {
            if (nums[left] <= target && target <= nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else if (nums[mid] <= nums[right])
        {
            if (nums[mid] <= target && target <= nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
    return -1;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
//     cout << search(nums, 3) << endl;
//     cout << endl
//          << string(30, '-');
// }
// ------------------------------------------------------------------ 81. Search in Rotated Sorted Array II ---------------------------------------------------------------------------
bool searchInARotatedSortedArrayII(vector<int> &nums, int target)
{
    int n = nums.size(); // size of the array.
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int middle = low + (high - low) / 2;
        // if mid points the target
        if (nums[middle] == target)
            return true;
        // Edge case:
        if (nums[low] == nums[middle] && nums[middle] == nums[high])
        {
            low = low + 1;
            high = high - 1;
            continue;
        }
        // if left part is sorted:
        if (nums[low] <= nums[middle])
        {
            if (nums[low] <= target && target <= nums[middle])
            {
                // element exists:
                high = middle - 1;
            }
            else
            {
                // element does not exist:
                low = middle + 1;
            }
        }
        // if right part is sorted:
        else
        {
            if (nums[middle] <= target && target <= nums[high])
            {
                // element exists:
                low = middle + 1;
            }
            else
            {
                // element does not exist:
                high = middle - 1;
            }
        }
    }
    return false;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
//     cout << searchInARotatedSortedArrayII(nums, 0) << endl;
//     cout << endl
//          << string(30, '-');
// }
// ------------------------------------------------------------- 153. Find Minimum in Rotated Sorted Array ---------------------------------------------------------------------------
int findMin(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;
    int minimum = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // search space is already sorted
        // then arr[low] will always be
        // the minimum in that search space:
        if (nums[low] <= nums[high])
        {
            minimum = min(minimum, nums[low]);
            break;
        }
        // if left part is sorted:
        if (nums[low] <= nums[mid])
        {
            // keep the minimum:
            minimum = min(minimum, nums[low]);
            // Eliminate left half:
            low = mid + 1;
        }
        else
        { // if right part is sorted:
            // keep the minimum:
            minimum = min(minimum, nums[mid]);
            // Eliminate right half:
            high = mid - 1;
        }
    }
    return minimum;
}
int main()
{
    cout << string(30, '-') << endl;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << findMin(nums) << endl;
    cout << endl
         << string(30, '-');
}