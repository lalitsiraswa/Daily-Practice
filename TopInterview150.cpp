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
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> nums = {11, 13, 15, 17};
//     cout << findMin(nums) << endl;
//     cout << string(35, '-');
//     return 0;
// }
// --------------------------------------------------------------- 33. Search in Rotated Sorted Array ----------------------------------------------------------
// Key Observation: If an array is rotated and sorted, we already know that for every index, one of the 2 halves of the array will always be sorted.
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
//     cout << string(35, '-') << endl;
//     vector<int> nums = {1};
//     cout << search(nums, 3) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ------------------------------------------------------------- 26. Remove Duplicates from Sorted Array -----------------------------------------------------
int removeDuplicates(vector<int> &nums)
{
    int index = 0, i;
    for (i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[index++] = nums[i - 1];
        }
    }
    if (index > 0 && nums[index - 1] != nums[i - 1])
    {
        nums[index++] = nums[i - 1];
    }
    return (index == 0) ? 1 : index;
}
// ----------------
int removeDuplicates_2(vector<int> &nums)
{
    int index = 0, i;
    for (i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] != nums[i + 1])
        {
            nums[index++] = nums[i];
        }
    }
    if (index > 0 && nums[index - 1] != nums[i])
    {
        nums[index++] = nums[i];
    }
    return (index == 0) ? 1 : index;
}
// ---------------------
int removeDuplicates_3(vector<int> &nums)
{
    int index = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (index < 1 || nums[i] != nums[index - 1])
        {
            nums[index++] = nums[i];
        }
    }
    return index;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
//     cout << removeDuplicates_2(nums) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ----------------------------------------------------- 169. Majority Element -------------------------------------------------------------
int majorityElement(vector<int> &nums)
{
    unordered_map<int, int> frequencyMap;
    for (auto item : nums)
    {
        frequencyMap[item] += 1;
    }
    int maxFreq = INT_MIN;
    int majorElement;
    for (auto item : frequencyMap)
    {
        if (item.second > maxFreq)
        {
            maxFreq = item.second;
            majorElement = item.first;
        }
    }
    return majorElement;
}
// ------------------------------------
//--- Using Boyer-Moore Majority Voting Algorithm ----
int majorityElement_2(vector<int> &nums)
{
    int n = nums.size();
    int majority_element = nums[0];
    int counter = 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == majority_element)
            counter++;
        else
        {
            counter--;
            if (counter == 0)
            {
                majority_element = nums[i];
                counter = 1;
            }
        }
    }
    return majority_element;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
//     cout << majorityElement(nums) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// --------------------------------------------------- 14. Longest Common Prefix ----------------------------------------------------------
string longestCommonPrefix(vector<string> &strs)
{
    string longestCommonPrefix;
    for (int i = 0; i < strs[0].size(); i++)
    {
        for (int j = 1; j < strs.size(); j++)
        {
            if (strs[j].size() - 1 >= i)
            {
                if (strs[j][i] != strs[0][i])
                    return longestCommonPrefix;
            }
            else
                return longestCommonPrefix;
        }
        longestCommonPrefix.push_back(strs[0][i]);
    }
    return longestCommonPrefix;
}
// ----------------
string longestCommonPrefix_2(vector<string> &strs)
{
    string longestCommonPrefix = "";
    sort(strs.begin(), strs.end());
    string firstString = strs[0];
    string lastString = strs[strs.size() - 1];
    for (int i = 0; i < firstString.size(); i++)
    {
        if (firstString[i] != lastString[i])
            return longestCommonPrefix;
        longestCommonPrefix.push_back(firstString[i]);
    }
    return longestCommonPrefix;
}
// ----------------
string longestCommonPrefix_3(vector<string> &strs)
{
    string longestCommonPrefix = "";
    for (int i = 0; i < strs[0].size(); i++)
    {
        char ch = strs[0][i];
        for (int j = 1; j < strs.size(); j++)
        {
            if (ch != strs[j][i])
                return longestCommonPrefix;
        }
        longestCommonPrefix.push_back(ch);
    }
    return longestCommonPrefix;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<string> strs = {"flower", "flow", "flowerable"};
//     cout << longestCommonPrefix_3(strs) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ----------------------------------------------------------- 80. Remove Duplicates from Sorted Array II --------------------------------------------------------
int removeDuplicates2(vector<int> &nums)
{
    int index = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (index < 2 || nums[i] != nums[index - 2])
        {
            nums[index++] = nums[i];
        }
    }
    return index;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> nums = {1, 1, 1, 2, 2, 3};
//     cout << removeDuplicates2(nums) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ------------------------------------------------------------------------ 189. Rotate Array ------------------------------------------------------------------
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> rotatedVect(n);
    for (int i = 0; i < n; i++)
    {
        rotatedVect[(i + k) % n] = nums[i];
    }
    nums = rotatedVect;
}
// ------- TLE -------
void rotate_2(vector<int> &nums, int k)
{
    int n = nums.size();
    for (int i = 0; i < k; i++)
    {
        int temp = nums[n - 1];
        for (int j = n - 2; j >= 0; j--)
        {
            nums[(j + 1) % n] = nums[j];
        }
        nums[0] = temp;
    }
}
// ---------- USING "reverse()" -----------
void rotate_3(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}
// ------------ Reverse Manually ------------
void rotate_4(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;
    int left = 0, right = n - 1;
    while (left < right)
    {
        int temp = nums[left];
        nums[left++] = nums[right];
        nums[right--] = temp;
    }
    left = 0, right = k - 1;
    while (left < right)
    {
        int temp = nums[left];
        nums[left++] = nums[right];
        nums[right--] = temp;
    }
    left = k, right = n - 1;
    while (left < right)
    {
        int temp = nums[left];
        nums[left++] = nums[right];
        nums[right--] = temp;
    }
}
int main()
{
    cout << string(35, '-') << endl;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    rotate_2(nums, 3);
    for (auto num : nums)
        cout << num << " ";
    cout << endl
         << string(35, '-');
    return 0;
}