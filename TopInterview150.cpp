#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------------- 88. Merge Sorted Array ------------------------------------------------------------------
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int index = (m + n) - 1;
    int mPtr = --m, nPtr = --n;
    while (nPtr >= 0)
    {
        if (mPtr < 0)
        {
            nums1[index] = nums2[nPtr--];
        }
        else if (nums2[nPtr] > nums1[mPtr])
        {
            nums1[index] = nums2[nPtr--];
        }
        else
        {
            nums1[index] = nums1[mPtr--];
        }
        index--;
    }
}
void merge_2(vector<int> &nums1, int m, vector<int> &nums2, int n)
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
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> nums1 = {2, 0};
//     vector<int> nums2 = {1};
//     int m = 1, n = 1;
//     merge(nums1, m, nums2, n);
//     for (auto item : nums1)
//         cout << item << " ";
//     cout << endl;
//     cout << string(35, '-');
//     return 0;
// }
// -------------------------------------------------------------- 27. Remove Element -----------------------------------------------------------------------
int removeElement(vector<int> &nums, int val)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    int left = 0, right = n - 1;
    while (left < right)
    {
        if (nums[left] != val)
            left++;
        else if (nums[right] == val)
            right--;
        if (nums[left] == val && nums[right] != val)
        {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
    return (nums[left] != val) ? left + 1 : left;
}
// -------------------
int removeElement_2(vector<int> &nums, int val)
{
    int index = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
        {
            nums[index] = nums[i];
            index++;
        }
    }
    return index;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
//     cout << removeElement_2(nums, 2) << endl;
//     cout << string(35, '-');
//     return 0;
// }
// ------------------------------------------------------------ 153. Find Minimum in Rotated Sorted Array -------------------------------------------------------------
// Key Observation: If an array is rotated and sorted, we already know that for every index, one of the 2 halves of the array will always be sorted.
int findMin(vector<int> &nums)
{
    int left = 0;
    int right = nums.size() - 1;
    int minValue = INT_MAX;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        // if left part is sorted:
        if (nums[left] <= nums[mid])
        {
            // keep the minimum:
            minValue = min(minValue, nums[left]);
            // Eliminate left half:
            left = mid + 1;
        }
        // if right part is sorted:
        else
        {
            // keep the minimum:
            minValue = min(minValue, nums[mid]);
            // Eliminate right half:
            right = mid - 1;
        }
    }
    return minValue;
}
// --------------------
int findMin_2(vector<int> &nums)
{
    int left = 0;
    int right = nums.size() - 1;
    int minValue = INT_MAX;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        // search space is already sorted
        // then arr[low] will always be
        // the minimum in that search space:
        if (nums[left] <= nums[right])
        {
            minValue = min(minValue, nums[left]);
            break;
        }
        // if left part is sorted:
        if (nums[left] <= nums[mid])
        {
            // keep the minimum:
            minValue = min(minValue, nums[left]);
            // Eliminate left half:
            left = mid + 1;
        }
        // if right part is sorted:
        else
        {
            // keep the minimum:
            minValue = min(minValue, nums[mid]);
            // Eliminate right half:
            right = mid - 1;
        }
    }
    return minValue;
}
int main()
{
    cout << string(35, '-') << endl;
    vector<int> nums = {11, 13, 15, 17};
    cout << findMin(nums) << endl;
    cout << string(35, '-');
    return 0;
}