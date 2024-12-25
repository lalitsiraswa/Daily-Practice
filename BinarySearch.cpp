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
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
//     cout << findMin(nums) << endl;
//     cout << endl
//          << string(30, '-');
// }
// ------------------------------------------------------------------------- Find Kth Rotation ---------------------------------------------------------------------------
int findKRotation(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    int minimumIndex = 0;
    int minimum = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // search space is already sorted
        // then arr[low] will always be
        // the minimum in that search space:
        if (arr[low] <= arr[high])
        {
            if (arr[low] <= minimum)
            {
                minimum = arr[low];
                minimumIndex = low;
            }
            break;
        }
        // if left part is sorted:
        if (arr[low] <= arr[mid])
        {
            // keep the minimum:
            if (arr[low] <= minimum)
            {
                minimum = arr[low];
                minimumIndex = low;
            }
            // Eliminate left half:
            low = mid + 1;
        }
        else
        { // if right part is sorted:
            // keep the minimum:
            if (arr[mid] <= minimum)
            {
                minimum = arr[mid];
                minimumIndex = mid;
            }
            // Eliminate right half:
            high = mid - 1;
        }
    }
    return minimumIndex;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {6, 9, 2, 4};
//     cout << findKRotation(nums) << endl;
//     cout << endl
//          << string(30, '-');
// }
// ------------------------------------------------------------------------- 540. Single Element in a Sorted Array ---------------------------------------------------------------------------
int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    int low = 0, high = n - 1;
    int singleElement;
    while (low <= high)
    {
        int middle = low + (high - low) / 2;
        singleElement = nums[middle];
        // Even Index
        if (middle % 2 == 0)
        {
            if (nums[middle + 1] == nums[middle])
                low = middle + 1;
            else if (middle > 0 && nums[middle - 1] != nums[middle])
                break;
            else
                high = middle - 1;
        }
        // Odd Index
        else
        {
            if (nums[middle - 1] == nums[middle])
                low = middle + 1;
            else if (middle < n - 1 && nums[middle + 1] != nums[middle])
                break;
            else
                high = middle - 1;
        }
    }
    return singleElement;
}
// -------------------
int singleNonDuplicate2(vector<int> &nums)
{
    int n = nums.size(); // size of the array.
    // Edge cases:
    if (n == 1)
        return nums[0];
    if (nums[0] != nums[1])
        return nums[0];
    if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];
    int low = 1, high = n - 2;
    while (low <= high)
    {
        int middle = low + (high - low) / 2;
        // if arr[mid] is the single element:
        if (nums[middle] != nums[middle + 1] && nums[middle] != nums[middle - 1])
            return nums[middle];
        // we are in the left:
        if ((middle % 2 != 0 && nums[middle] == nums[middle - 1]) || (middle % 2 == 0 && nums[middle] == nums[middle + 1]))
        {
            // eliminate the left half:
            low = middle + 1;
        }
        // we are in the right:
        else
        {
            // eliminate the right half:
            high = middle - 1;
        }
    }
    // dummy return statement:
    return -1;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     // vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
//     // vector<int> nums = {3, 3, 7, 7, 10, 11, 11};
//     vector<int> nums = {1, 1, 2, 3, 3};
//     cout << singleNonDuplicate2(nums) << endl;
//     cout << endl
//          << string(30, '-');
// }
// ------------------------------------------------------------------------- 162. Find Peak Element ---------------------------------------------------------------------------
int findPeakElement(vector<int> &nums)
{
    int n = nums.size();
    int peakElementIndex = 0;
    for (int i = 1; i < n; i++)
    {
        peakElementIndex = nums[i] > nums[peakElementIndex] ? i : peakElementIndex;
    }
    return peakElementIndex;
}
// --------- TWO POINTER ----------
int findPeakElement2(vector<int> &nums)
{
    int n = nums.size();
    int peakElementIndex = 0;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        peakElementIndex = nums[low] > nums[peakElementIndex] ? low : peakElementIndex;
        peakElementIndex = nums[high] > nums[peakElementIndex] ? high : peakElementIndex;
        low++;
        high--;
    }
    return peakElementIndex;
}
// -----------------------
int findPeakElementTUF(vector<int> &nums)
{
    int n = nums.size(); // Size of array.
    // Edge cases:
    if (n == 1)
        return 0;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int middle = low + (high - low) / 2;
        // If arr[mid] is the peak:
        if ((middle == 0 && nums[middle] > nums[middle + 1]) || (middle == n - 1 && nums[middle] > nums[n - 2]))
            return middle;
        if ((middle > 0 && nums[middle - 1] < nums[middle]) && (middle < n - 1 && nums[middle] > nums[middle + 1]))
            return middle;
        // If we are in the left:
        else if (middle > 0 && nums[middle] > nums[middle - 1])
            low = middle + 1;
        // If we are in the right:
        else if (middle < n - 1 && nums[middle] > nums[middle + 1])
            high = middle - 1;
        // We can move either left ot right
        // nums[middle] is a common point:
        else
        {
            low = middle + 1;
            // high = middle - 1;
        }
    }
    return -1;
}
// -----------------------
int findPeakElementTUF2(vector<int> &nums)
{
    int n = nums.size(); // Size of array.
    // Edge cases:
    if (n == 1)
        return 0;
    if (nums[0] > nums[1])
        return 0;
    if (nums[n - 1] > nums[n - 2])
        return n - 1;
    int low = 1, high = n - 2;
    while (low <= high)
    {
        int middle = low + (high - low) / 2;
        // If arr[mid] is the peak:
        if (nums[middle - 1] < nums[middle] && nums[middle] > nums[middle + 1])
            return middle;
        // If we are in the left:
        else if (nums[middle] > nums[middle - 1])
            low = middle + 1;
        // If we are in the right:
        else if (nums[middle] > nums[middle + 1])
            high = middle - 1;
        // We can move either left ot right
        // nums[middle] is a common point:
        else
        {
            low = middle + 1;
            // high = middle - 1;
        }
    }
    return -1;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     // vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
//     // vector<int> nums = {3, 3, 7, 7, 10, 11, 11};
//     // vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
//     // vector<int> nums = {2, 1};
//     vector<int> nums = {1, 2};
//     cout << findPeakElementTUF(nums) << endl;
//     cout << endl
//          << string(30, '-');
// }
// ------------------------------------------------------------------------- 69. Sqrt(x) Square root of a number ---------------------------------------------------------------------------
long long int floorSqrt(long long int n)
{
    if (n == 0)
        return 0;
    long long int floor = 1;
    for (long long int i = 1; i <= n; i++)
    {
        if (i * i > n)
            break;
        floor = i;
    }
    return floor;
}
// ---------------------------
long long int floorSqrt2(long long int n)
{
    if (n == 0)
        return 0;
    int low = 1, high = n;
    long long int floor;
    while (low <= high)
    {
        long long int middle = low + (high - low) / 2;
        if ((middle * middle) <= n)
        {
            floor = middle;
            low = middle + 1;
        }
        else
            high = middle - 1;
    }
    return floor;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     cout << floorSqrt(5) << endl;
//     cout << endl
//          << string(30, '-');
// }
// ------------------------------------------------------------------------- Find Nth root of M ---------------------------------------------------------------------------
int NthRoot(int n, int m)
{
    int root = -1;
    for (int i = 1; i <= m; i++)
    {
        int multiply = 1;
        for (int j = 1; j <= n; j++)
        {
            multiply = multiply * i;
        }
        if (multiply > m)
            break;
        if (multiply == m)
        {
            root = i;
            break;
        }
    }
    return root;
}
// -------------------------
int NthRoot2(int n, int m)
{
    int root = -1;
    int low = 1, high = m;
    while (low <= high)
    {
        int middle = low + (high - low) / 2;
        long long int multiply = 1;
        for (int j = 1; j <= n; j++)
        {
            multiply = multiply * middle;
            if (multiply > m)
                break;
        }
        if (multiply == m)
        {
            root = middle;
            break;
        }
        if (multiply < m)
            low = middle + 1;
        else
            high = middle - 1;
    }
    return root;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     // cout << NthRoot2(2, 9) << endl;
//     // cout << NthRoot2(9, 1953125) << endl;
//     cout << NthRoot2(4, 81) << endl;
//     cout << endl
//          << string(30, '-');
// }
// ----------------------------------------------------- 1283. Find the Smallest Divisor Given a Threshold ---------------------------------------------------------------------------
// ------------------ TLE -----------------------
int smallestDivisor(vector<int> &nums, int threshold)
{
    int n = nums.size();
    int maxElement = *max_element(nums.begin(), nums.end());
    for (int divisor = 1; divisor <= maxElement; divisor++)
    {
        int totalSum = 0;
        for (auto num : nums)
        {
            totalSum += ceil((double)(num) / (double)(divisor));
            if (totalSum > threshold)
                break;
        }
        if (totalSum <= threshold)
        {
            return divisor;
        }
    }
    return -1;
}
// -----------------------------------------
int smallestDivisor2(vector<int> &nums, int threshold)
{
    int n = nums.size();
    if (n > threshold)
        return -1;
    int low = 1, high = *max_element(nums.begin(), nums.end());
    int result = -1;
    // Apply binary search:
    while (low <= high)
    {
        int middle = low + (high - low) / 2;
        int sum = 0;
        for (int num : nums)
        {
            sum += ceil((double)(num) / (double)(middle));
            if (sum > threshold)
                break;
        }
        if (sum <= threshold)
        {
            result = middle;
            high = middle - 1;
        }
        else
            low = middle + 1;
    }
    return result;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     // vector<int> nums = {1, 2, 5, 9};
//     vector<int> nums = {44, 22, 33, 11, 1};
//     cout << smallestDivisor2(nums, 5) << endl;
//     cout << endl
//          << string(30, '-');
// }
// -------------------------------------------------------------- 1539. Kth Missing Positive Number ---------------------------------------------------------------------------
int findKthPositive(vector<int> &arr, int k)
{
    int n = arr.size();
    int missingCount = 0;
    int currentPositiveInteger = 1;
    int i = 0;
    while (i < n)
    {
        if (arr[i] != currentPositiveInteger)
            missingCount++;
        else
            i++;
        if (missingCount == k)
            return currentPositiveInteger;
        currentPositiveInteger += 1;
    }
    return currentPositiveInteger + (k - missingCount - 1);
}
// ---------------------
int findKthPositive2(vector<int> &arr, int k)
{
    int n = arr.size();
    int missingCount = 0;
    int currentPositiveInteger = 1;
    for (int i = 0; i < n; i++)
    {
        if (currentPositiveInteger == arr[i])
        {
            currentPositiveInteger += 1;
        }
        else
        {
            missingCount += (arr[i] - currentPositiveInteger);
            if (missingCount >= k)
                return arr[i] - (missingCount - k) - 1;
            currentPositiveInteger = arr[i] + 1;
        }
    }
    return currentPositiveInteger + (k - missingCount) - 1;
}
// --------- TUF ----------
int findKthPositive3(vector<int> &arr, int k)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int middle = low + (high - low) / 2;
        int missing = arr[middle] - (middle + 1);
        if (missing < k)
            low = middle + 1;
        else
            high = middle - 1;
    }
    return k + high + 1;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     // vector<int> nums = {2, 3, 4, 7, 11};
//     // vector<int> nums = {3, 10};
//     // vector<int> nums = {1, 2, 3, 4};
//     vector<int> nums = {5, 6, 7, 8, 9};
//     cout << findKthPositive3(nums, 9) << endl;
//     cout << endl
//          << string(30, '-');
// }
// ---------------------------------------------------------------------- 4. Median of Two Sorted Arrays ----------------------------------------------------------------------
// ---------- Trying something different then the quesion actually asked ----------
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    int nums1index = 0;
    while (nums1index < n)
    {
        int i = nums1index;
        int nums2Index = 0;
        while (i < n && nums2Index < m)
        {
            if (nums2[nums2Index] <= nums1[i])
                swap(nums2[nums2Index], nums1[i]);
            else
                break;
            i += 1;
            nums2Index += 1;
        }
        nums1index += 1;
    }
    return 1;
}
// ---------------------------------
double findMedianSortedArrays2(vector<int> &nums1, vector<int> &nums2)
{
    // size of two given arrays:
    int n1 = nums1.size(), n2 = nums2.size();
    int n = n1 + n2; // total size
    // required indices:
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int ind1el = -1, ind2el = -1;
    // apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (nums1[i] < nums2[j])
        {
            if (cnt == ind1)
                ind1el = nums1[i];
            if (cnt == ind2)
                ind2el = nums1[i];
            cnt++;
            i++;
        }
        else
        {
            if (cnt == ind1)
                ind1el = nums2[j];
            if (cnt == ind2)
                ind2el = nums2[j];
            cnt++;
            j++;
        }
    }
    // copy the left-out elements:
    while (i < n1)
    {
        if (cnt == ind1)
            ind1el = nums1[i];
        if (cnt == ind2)
            ind2el = nums1[i];
        cnt++;
        i++;
    }
    while (j < n2)
    {
        if (cnt == ind1)
            ind1el = nums2[j];
        if (cnt == ind2)
            ind2el = nums2[j];
        cnt++;
        j++;
    }
    // Find the median:
    if (n % 2 == 1)
        return (double)ind2el;
    return (double)((double)(ind1el + ind2el)) / 2.0;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums1 = {2, 3, 6, 7, 9};
//     vector<int> nums2 = {1, 4, 8, 10};
//     // vector<int> nums1 = {1, 3};
//     // vector<int> nums2 = {2};
//     cout << findMedianSortedArrays2(nums1, nums2) << endl;
//     cout << endl
//          << string(30, '-');
// }

// ---------------------------------------------------------------------- K-th element of two Arrays ----------------------------------------------------------------------
int kthElement(int k, vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size(), m = arr2.size();
    int arr1Index = 0, arr2Index = 0;
    int elementCounter = 0;
    while (arr1Index < n && arr2Index < m)
    {
        elementCounter += 1;
        // Always think in term's of base Case: like 0, 1 etc.
        if (elementCounter == k)
            return min(arr1[arr1Index], arr2[arr2Index]);
        if (arr1[arr1Index] < arr2[arr2Index])
            arr1Index += 1;
        else
            arr2Index += 1;
    }
    while (arr1Index < n)
    {
        elementCounter += 1;
        if (elementCounter == k)
            return arr1[arr1Index];
        arr1Index += 1;
    }
    while (arr2Index < m)
    {
        elementCounter += 1;
        if (elementCounter == k)
            return arr2[arr2Index];
        arr2Index += 1;
    }
    return -1;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> arr1 = {2, 3, 6, 7, 9};
//     vector<int> arr2 = {1, 4, 8, 10};
//     cout << kthElement(5, arr1, arr2) << endl;
//     cout << endl
//          << string(30, '-');
// }
// ---------------------------------------------------------------------- Row with max 1s ----------------------------------------------------------------------
int rowWithMax1s(vector<vector<int>> &arr)
{
    int rowCount = arr.size();
    int columnCount = arr[0].size();
    int rowIndex = -1;
    int previousRowSum = 0;
    for (int row = 0; row < rowCount; row++)
    {
        int sum = 0;
        for (int column = 0; column < columnCount; column++)
            sum += arr[row][column];
        if (sum > previousRowSum)
        {
            previousRowSum = sum;
            rowIndex = row;
        }
    }
    return rowIndex;
}
// ----------------------
int findLowerBound(vector<int> nums)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int lowerBountIndex = nums.size();
    while (low <= high)
    {
        int middle = low + (high - low) / 2;
        if (nums[middle] >= 1)
        {
            lowerBountIndex = middle;
            high = middle - 1;
        }
        else
            low = middle + 1;
    }
    return lowerBountIndex;
}
int rowWithMax1s2(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    int rowIndex = -1;
    int previousRowSum = 0;
    for (int index = 0; index < n; index++)
    {
        int sum = m - findLowerBound(arr[index]);
        if (sum > previousRowSum)
        {
            previousRowSum = sum;
            rowIndex = index;
        }
    }
    return rowIndex;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<vector<int>> arr = {{0, 1, 1, 1},
//                                {0, 0, 1, 1},
//                                {1, 1, 1, 1},
//                                {0, 0, 0, 0}};
//     cout << rowWithMax1s2(arr) << endl;
//     cout << endl
//          << string(30, '-');
// }
// ---------------------------------------------------------------------- 74. Search a 2D Matrix ----------------------------------------------------------------------
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 0;
    while (row < n)
    {
        int minElement = matrix[row][0];
        int maxElement = matrix[row][m - 1];
        if (minElement <= target && target <= maxElement)
            break;
        row += 1;
    }
    if (row == n)
        return false;
    int low = 0, high = m - 1;
    while (low <= high)
    {
        int middle = low + (high - low) / 2;
        if (matrix[row][middle] == target)
            return true;
        if (matrix[row][middle] < target)
            low = middle + 1;
        else
            high = middle - 1;
    }
    return false;
}
// -----------------------------
bool searchMatrix2(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    // apply binary search:
    int low = 0, high = n * m - 1;
    while (low <= high)
    {
        int middle = low + (high - low) / 2;
        int row = middle / m;
        int column = middle % m;
        if (matrix[row][column] == target)
            return true;
        if (matrix[row][column] < target)
            low = middle + 1;
        else
            high = middle - 1;
    }
    return false;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
//     // vector<vector<int>> matrix = {{1}, {3}};
//     cout << searchMatrix2(matrix, 30) << endl;
//     cout << endl
//          << string(30, '-');
// }
// ---------------------------------------------------------------------- 240. Search a 2D Matrix II ----------------------------------------------------------------------
bool binarySearchRowWise(vector<vector<int>> &matrix, int row, int target)
{
    int m = matrix[0].size();
    int low = 0, high = m - 1;
    while (low <= high)
    {
        int middle = low + (high - low) / 2;
        if (matrix[row][middle] == target)
            return true;
        if (matrix[row][middle] < target)
            low = middle + 1;
        else
            high = middle - 1;
    }
    return false;
}
bool searchMatrix_2(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    // Check rows
    for (int row = 0; row < n; row++)
    {
        int minElement = matrix[row][0];
        int maxElement = matrix[row][m - 1];
        if (minElement <= target && target <= maxElement)
        {
            if (binarySearchRowWise(matrix, row, target))
                return true;
        }
    }
    return false;
}
// ------------------------
bool searchMatrix_2_TUF(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 0, column = m - 1;
    // traverse the matrix from (0, m-1):
    while (row < n && column >= 0)
    {
        if (matrix[row][column] == target)
            return true;
        if (matrix[row][column] < target)
            row += 1;
        else
            column -= 1;
    }
    return false;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
//     cout << searchMatrix_2_TUF(matrix, 5) << endl;
//     cout << endl
//          << string(30, '-');
// }
// ---------------------------------------------------------------------------- 1539. Kth Missing Positive Number Revision ----------------------------------------------------------------------------
int findKthPositiveRevision(vector<int> &arr, int k)
{
    int integerNumber = 1;
    int missingCount = 0;
    int i = 0;
    while (i < arr.size())
    {
        if (arr[i] == integerNumber)
            i += 1;
        else
            missingCount += 1;
        if (missingCount == k)
            return integerNumber;
        integerNumber += 1;
    }
    return arr[arr.size() - 1] + (k - missingCount);
}
// -----------------------------------
int findKthPositiveBruteForce(vector<int> &arr, int k)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
            // Shifting
            k++;
        else
            break;
    }
    return k;
}
// -----------------------------------
// INDEX - [0, 1, 2, 3, 4, 5]
// ARRAY - [1, 2, 3, 4, 5, 6]
// ARRAY[INDEX] == INDEX + 1;
// MISSING COUNT = ARRAY[INDEX] - INDEX + 1;
// (1 - (0 + 1)) = 0;
// (2 - (1 + 1)) = 0;
// (3- (2 + 1)) = 0;
// (4 - (3 + 1)) = 0;
// (5- (4 + 1)) = 0;
// (6 - (5 + 1)) = 0;
// ------------------
// INDEX - {0, 1, 2, 3, 4}
// ARRAY - {2, 3, 4, 7, 11}
// ARRAY[INDEX] == INDEX + 1;
// MISSING COUNT = ARRAY[INDEX] - INDEX + 1;
// (2 - (0 + 1)) = 1;
// (3 - (1 + 1)) = 1;
// (4- (2 + 1)) = 1;
// (7 - (3 + 1)) = 3;
// (11- (4 + 1)) = 6;
int findKthPositiveBinarySearch(vector<int> &arr, int k)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int missingCount = arr[mid] - (mid + 1);
        if (missingCount < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return k + high + 1;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> arr = {2, 3, 4, 7, 11};
//     cout << findKthPositiveBinarySearch(arr, 5) << endl;
//     cout << endl
//          << string(30, '-');
// }
// ------------------------------------------------ Floor in a Sorted Array, Ceil The Floor Revision ----------------------------------------------------------------------------
int findFloorRevision(vector<int> &arr, int k)
{
    int floorIndex = -1;
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] <= k)
        {
            floorIndex = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return floorIndex != -1 ? arr[floorIndex] : -1;
}
int findCeilRevision(vector<int> &arr, int k)
{
    int ceilIndex = -1;
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= k)
        {
            ceilIndex = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ceilIndex != -1 ? arr[ceilIndex] : -1;
}
vector<int> getFloorAndCeilRevision(int x, vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int floorIndex = findFloorRevision(arr, x);
    int ceilIndex = findCeilRevision(arr, x);
    return {floorIndex, ceilIndex};
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> arr = {5, 6, 8, 9, 6, 5, 5, 6};
//     vector<int> floorCeil = getFloorAndCeilRevision(7, arr);
//     cout << "Floor : " << floorCeil[0] << ", Ceil : " << floorCeil[1] << endl;
//     cout << endl
//          << string(30, '-');
// }
// ---------------------------------------------------------- 34. Find First and Last Position of Element in Sorted Array Revision ----------------------------------------------------------------------------
vector<int> searchRangeRevision(vector<int> &nums, int target)
{
    int startingIndex = -1;
    int endingIndex = -1;
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] < target)
            low = mid + 1;
        if (nums[mid] > target)
            high = mid - 1;
        if (nums[mid] == target)
        {
            startingIndex = mid;
            high = mid - 1;
        }
    }
    low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] < target)
            low = mid + 1;
        if (nums[mid] > target)
            high = mid - 1;
        if (nums[mid] == target)
        {
            endingIndex = mid;
            low = mid + 1;
        }
    }
    return {startingIndex, endingIndex};
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {5, 7, 7, 8, 8, 10};
//     vector<int> startEndIndex = searchRangeRevision(nums, 8);
//     cout << "Floor : " << startEndIndex[0] << ", Ceil : " << startEndIndex[1] << endl;
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------- 33. Search in Rotated Sorted Array Revision ------------------------------------------------------------------------------
int searchRevision(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target && target <= nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (nums[mid] <= target && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
//     cout << searchRevision(nums, 3) << endl;
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------- 410. Split Array Largest Sum ------------------------------------------------------------------------------
// ----- MLE -----
void splitArrayHelper(vector<int> &nums, int k, int n, int index, vector<int> &subarraySum, vector<vector<int>> &subarraySumCollection)
{
    if (index == n)
    {
        subarraySumCollection.push_back(subarraySum);
        return;
    }
    int sum = 0;
    for (int i = index; i < n; i++)
    {
        sum += nums[i];
        if (k == 1 && i != n - 1)
        {
            continue;
        }
        subarraySum.push_back(sum);
        splitArrayHelper(nums, k - 1, n, i + 1, subarraySum, subarraySumCollection);
        subarraySum.pop_back();
    }
}
int splitArray(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> subarraySum;
    vector<vector<int>> subarraySumCollection;
    splitArrayHelper(nums, k, n, 0, subarraySum, subarraySumCollection);
    int minimizedSum = INT_MAX;
    for (int i = 0; i < subarraySumCollection.size(); i++)
    {
        int subarrayMaxSum = *(max_element(subarraySumCollection[i].begin(), subarraySumCollection[i].end()));
        minimizedSum = min(minimizedSum, subarrayMaxSum);
    }
    return minimizedSum;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {7, 2, 5, 10, 8};
//     cout << splitArray(nums, 2) << endl;
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------- 81. Search in Rotated Sorted Array II Revision ------------------------------------------------------------------------------
// Dry Run
// [3, 1, 2, 3, 3, 3, 3] target = 2
// [1, 0, 1, 1, 1] target = 0
bool search2Revision(vector<int> &nums, int target)
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
//     vector<int> nums = {3, 1, 2, 3, 3, 3, 3};
//     cout << search2Revision(nums, 1) << endl;
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------- 153. Find Minimum in Rotated Sorted Array Revision ------------------------------------------------------------------------------
int findMinRevision(vector<int> &nums)
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
//     cout << string(30, '-') << endl;
//     vector<int> nums = {3, 4, 5, 1, 2};
//     cout << findMinRevision(nums) << endl;
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------- Find Kth Rotation Revision ------------------------------------------------------------------------------
int findKRotationRevision(vector<int> &arr)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int minElementIndex = 0;
    while (low <= high)
    {
        // search space is already sorted
        // then arr[low] will always be
        // the minimum in that search space:
        if (arr[low] <= arr[high])
        {
            minElementIndex = (arr[minElementIndex] > arr[low]) ? low : minElementIndex;
            break;
        }
        int mid = (low + high) / 2;
        // if left part is sorted:
        if (arr[low] <= arr[mid])
        {
            // keep the minimum:
            minElementIndex = (arr[minElementIndex] > arr[low]) ? low : minElementIndex;
            // Eliminate left half:
            low = mid + 1;
        }
        // if right part is sorted:
        else
        {
            // keep the minimum:
            minElementIndex = (arr[minElementIndex] > arr[mid]) ? mid : minElementIndex;
            // Eliminate right half:
            high = mid - 1;
        }
    }
    return minElementIndex;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {3, 4, 5, 1, 2};
//     cout << findKRotationRevision(nums) << endl;
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------- 540. Single Element in a Sorted Array REVISION ------------------------------------------------------------------------------
// INDEX : [0, 1, 2, 3, 4, 5, 6, 7]
// NUMS :  [1, 1, 2, 2, 3, 3, 4, 4]
// FOR ODD INDEX -> LEFT INDEX SHOULD MATCH
// FOR EVEN INDEX -> RIGHT INDEX SHOULD MATCH
int singleNonDuplicateRevision(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
    {
        return nums[0];
    }
    if (nums[0] != nums[1])
    {
        return nums[0];
    }
    if (nums[n - 1] != nums[n - 2])
    {
        return nums[n - 1];
    }
    int low = 0;
    int high = n - 1;
    int singleElement;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
        {
            singleElement = nums[mid];
            break;
        }
        // EVEN INDEX
        if (mid % 2 == 0)
        {
            if (nums[mid] == nums[mid + 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        // ODD INDEX
        else
        {
            if (nums[mid] == nums[mid - 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return singleElement;
}

// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
//     cout << singleNonDuplicateRevision(nums) << endl;
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------- 162. Find Peak Element REVISION ------------------------------------------------------------------------------
// Dry Run
// [1, 5, 1, 2, 1]
int findPeakElementRevision(vector<int> &nums)
{
    int n = nums.size(); // Size of array.
    // Edge cases:
    if (n == 1)
        return 0;
    if (nums[0] > nums[1])
        return 0;
    if (nums[n - 1] > nums[n - 2])
        return n - 1;
    int low = 1, high = n - 2;
    while (low <= high)
    {
        int middle = low + (high - low) / 2;
        // If arr[mid] is the peak:
        if (nums[middle - 1] < nums[middle] && nums[middle] > nums[middle + 1])
            return middle;
        // If we are in the left:
        else if (nums[middle] > nums[middle - 1])
            low = middle + 1;
        // If we are in the right:
        else if (nums[middle] > nums[middle + 1])
            high = middle - 1;
        // We can move either left ot right
        // nums[middle] is a common point:
        else
        {
            low = middle + 1;
            // high = middle - 1;
        }
    }
    return -1;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {1, 5, 1, 2, 1};
//     cout << findPeakElementRevision(nums) << endl;
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------- Square Root REVISION ------------------------------------------------------------------------------
int floorSqrtRevision(int n)
{
    if (n == 1)
        return 1;
    int low = 1;
    int high = n / 2;
    int flootSqrt;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (mid * mid <= n)
        {
            flootSqrt = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return flootSqrt;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     cout << floorSqrtRevision(11) << endl;
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------- Find nth root of m REVISION ------------------------------------------------------------------------------
int nthRootRevision(int n, int m)
{
    if (n == 1)
        return m;
    int low = 1;
    int high = m / n;
    int root = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int tempRoot = 1;
        for (int i = 1; i <= n; i++)
        {
            tempRoot *= mid;
        }
        if (tempRoot == m)
        {
            root = mid;
            break;
        }
        if (tempRoot < m)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return root;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     cout << nthRootRevision(3, 9) << endl;
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------- 875. Koko Eating Bananas ------------------------------------------------------------------------------
int minEatingSpeed(vector<int> &piles, int h)
{
    long long maxElement = INT_MIN;
    // Find the maximum:
    for (int val : piles)
    {
        if (val > maxElement)
            maxElement = val;
    }
    long long low = 1;
    long long high = maxElement;
    long long minBananaPerHour;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        long long totalHour = 0;
        // Find total hours:
        for (int val : piles)
        {
            totalHour += (val + mid - 1) / mid;
        }
        if (totalHour <= h)
        {
            minBananaPerHour = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return minBananaPerHour;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> piles = {312884470};
//     cout << minEatingSpeed(piles, 312884469) << endl;
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------- 1482. Minimum Number of Days to Make m Bouquets ------------------------------------------------------------------------------
bool possible(vector<int> &arr, int day, int m, int k)
{
    // Size of the array
    int n = arr.size();
    int adjacentFlowerCount = 0;
    int bouquetCount = 0;
    // Count the number of bouquets:
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= day)
        {
            adjacentFlowerCount += 1;
        }
        else
        {
            bouquetCount += (adjacentFlowerCount / k);
            adjacentFlowerCount = 0;
        }
    }
    bouquetCount += (adjacentFlowerCount / k);
    return bouquetCount >= m;
}
int minDays(vector<int> &bloomDay, int m, int k)
{
    // 1ll is a literal of type long long.
    long long val = m * 1ll * k * 1ll;
    // Impossible case:
    if (val > bloomDay.size())
    {
        return -1;
    }
    // Find maximum and minimum:
    int minRequiredDay = INT_MAX;
    int maxRequiredDay = INT_MIN;
    for (int day : bloomDay)
    {
        if (day < minRequiredDay)
            minRequiredDay = day;
        if (day > maxRequiredDay)
            maxRequiredDay = day;
    }
    int low = minRequiredDay;
    int high = maxRequiredDay;
    int minDay = -1;
    // Apply binary search:
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int bouquetCount = 0;
        int adjacentFlowerCount = 0;
        // We can also use the above possible() function or we can use the below for-loop code in that function:
        // Count the number of bouquets:
        for (int i = 0; i < bloomDay.size(); i++)
        {
            // If adjacent flower is bloom:
            if (bloomDay[i] <= mid)
            {
                adjacentFlowerCount += 1;
            }
            // If adjacent flower is not bloom:
            else
            {
                adjacentFlowerCount = 0;
                continue;
            }
            // If adjacentFlowerCount equals to the required flower (i.e k) to make a single bouquet, we increase the bouquetCount by 1:
            if (adjacentFlowerCount == k)
            {
                adjacentFlowerCount = 0;
                bouquetCount += 1;
            }
            // If bouquetCount equals to the the required number of bouquets (i.e m) we will break loop:
            if (bouquetCount == m)
            {
                break;
            }
        }
        if (bouquetCount == m)
        {
            minDay = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return minDay;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> bloomDay = {1, 10, 3, 10, 2};
//     cout << minDays(bloomDay, 3, 1) << endl;
//     cout << endl
//          << string(30, '-');
// }
// ------------------------------------------------------------ 1283. Find the Smallest Divisor Given a Threshold REVISION ------------------------------------------------------------------------------
// TLE
int smallestDivisorRevision(vector<int> &nums, int threshold)
{
    int maxElement = INT_MIN;
    int minDivisor = INT_MAX;
    for (int val : nums)
    {
        maxElement = max(maxElement, val);
    }
    for (int divisor = 1; divisor <= maxElement; divisor++)
    {
        int currentThreshold = 0;
        for (int val : nums)
        {
            currentThreshold += (val + divisor - 1) / divisor;
        }
        if (currentThreshold <= threshold)
        {
            minDivisor = divisor;
            break;
        }
    }
    return minDivisor;
}
// --------- Binary Search ------------
int smallestDivisorBinarySearch(vector<int> &nums, int threshold)
{
    int n = nums.size();
    if (n > threshold)
        return -1;
    int maxElement = INT_MIN;
    int minDivisor = INT_MAX;
    for (int val : nums)
    {
        maxElement = max(maxElement, val);
    }
    int low = 1;
    int high = maxElement;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int currentThreshold = 0;
        for (int val : nums)
        {
            currentThreshold += ceil((double)(val) / (double)(mid));
            // currentThreshold += (val + mid - 1) / mid;
            if (currentThreshold > threshold)
                break;
        }
        if (currentThreshold <= threshold)
        {
            minDivisor = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return minDivisor;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {44, 22, 33, 11, 1};
//     cout << smallestDivisorBinarySearch(nums, 5) << endl;
//     cout << endl
//          << string(30, '-');
// }
// ------------------------------------------------------------ 1011. Capacity To Ship Packages Within D Days ------------------------------------------------------------------------------
int shipWithinDays(vector<int> &weights, int days)
{
    // Find the maximum and the summation:
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    int minShipCapacity = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int currentWeight = 0;
        // First day:
        int currentDays = 1;
        for (int weight : weights)
        {
            if (currentWeight + weight <= mid)
            {
                // Load the weight on the same day:
                currentWeight += weight;
            }
            else
            {
                // Move to next day:
                currentDays += 1;
                // Load the weight:
                currentWeight = weight;
            }
        }
        if (currentDays <= days)
        {
            minShipCapacity = mid;
            // Eliminate right half:
            high = mid - 1;
        }
        else
        {
            // Eliminate left half:
            low = mid + 1;
        }
    }
    return minShipCapacity;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> weights = {1, 2, 3, 1, 1};
//     cout << shipWithinDays(weights, 4) << endl;
//     cout << endl
//          << string(30, '-');
// }
// ------------------------------------------------------------ Row with max 1s REVISION ------------------------------------------------------------------
int findLowerBoundHelper(vector<int> &nums)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int lowerBoundIndex = n;
    while (low <= high)
    {
        int middle = (low + high) / 2;
        if (nums[middle] >= 1)
        {
            lowerBoundIndex = middle;
            high = middle - 1;
        }
        else
        {
            low = middle + 1;
        }
    }
    return lowerBoundIndex;
}
int rowWithMax1sRevision(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    int rowIndex = -1;
    int previousRowSum = 0;
    for (int index = 0; index < n; index++)
    {
        int sum = m - findLowerBoundHelper(arr[index]);
        if (sum > previousRowSum)
        {
            previousRowSum = sum;
            rowIndex = index;
        }
    }
    return rowIndex;
}
int main()
{
    cout << string(30, '-') << endl;
    vector<vector<int>> arr = {{0, 1, 1, 1},
                               {0, 0, 1, 1},
                               {1, 1, 1, 1},
                               {0, 0, 0, 0}};
    cout << rowWithMax1sRevision(arr) << endl;
    cout << endl
         << string(30, '-');
}