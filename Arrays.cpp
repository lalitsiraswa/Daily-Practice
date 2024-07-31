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
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
//     cout << removeDuplicates3(nums);
//     cout << endl
//          << string(30, '-');
// }
// -------------------------------------------------------------- 283. Move Zeroes ------------------------------------------------------------
void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
    int index = 0;
    for (int currentIndex = 0; currentIndex < n; currentIndex++)
    {
        if (nums[currentIndex] != 0)
            nums[index++] = nums[currentIndex];
    }
    while (index < n)
        nums[index++] = 0;
}
// ------------------
// Using swap()
void moveZeroes2(vector<int> &nums)
{
    int n = nums.size();
    int index = 0;
    int currentIndex = 0;
    while (index < n)
    {
        if (nums[index] == 0)
            break;
        index++;
    }
    for (int currenIndex = index + 1; currenIndex < n; currenIndex++)
    {
        if (nums[currenIndex] != 0)
        {
            swap(nums[index], nums[currenIndex]);
            index++;
        }
    }
    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {0, 1, 0, 3, 12};
//     moveZeroes2(nums);
//     cout << endl
//          << string(30, '-');
// }
// -------------------------------------------------------------- Union of Two Sorted Arrays ------------------------------------------------------------
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    vector<int> result;
    int arr1Index = 0;
    int arr2Index = 0;
    while (arr1Index < n && arr2Index < m)
    {
        int resultLength = result.size();
        if (arr1[arr1Index] <= arr2[arr2Index])
        {
            if (resultLength == 0 || (resultLength > 0) && result[resultLength - 1] != arr1[arr1Index])
                result.push_back(arr1[arr1Index]);
            if (arr1[arr1Index] == arr2[arr2Index])
                arr2Index++;
            arr1Index++;
        }
        else
        {
            if (resultLength == 0 || (resultLength > 0) && result[resultLength - 1] != arr2[arr2Index])
                result.push_back(arr2[arr2Index]);
            arr2Index++;
        }
    }
    while (arr1Index < n)
    {
        if (arr1[arr1Index - 1] != arr1[arr1Index])
            result.push_back(arr1[arr1Index]);
        arr1Index++;
    }
    while (arr2Index < m)
    {
        if (arr2[arr2Index - 1] != arr2[arr2Index])
            result.push_back(arr2[arr2Index]);
        arr2Index++;
    }
    return result;
}
// ------------
vector<int> findUnion2(int arr1[], int arr2[], int n, int m)
{
    vector<int> result;
    int arr1Index = 0;
    int arr2Index = 0;
    while (arr1Index < n && arr2Index < m)
    {
        if (arr1[arr1Index] <= arr2[arr2Index])
        {
            if (result.size() == 0 || result.back() != arr1[arr1Index])
                result.push_back(arr1[arr1Index]);
            if (arr1[arr1Index] == arr2[arr2Index])
                arr2Index++;
            arr1Index++;
        }
        else
        {
            if (result.size() == 0 || result.back() != arr2[arr2Index])
                result.push_back(arr2[arr2Index]);
            arr2Index++;
        }
    }
    while (arr1Index < n)
    {
        if (result.size() == 0 || result.back() != arr1[arr1Index])
            result.push_back(arr1[arr1Index]);
        arr1Index++;
    }
    while (arr2Index < m)
    {
        if (result.size() == 0 || result.back() != arr2[arr2Index])
            result.push_back(arr2[arr2Index]);
        arr2Index++;
    }
    return result;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     int arr1[] = {-9, -8, -7, -5, -1, 0, 3};
//     int arr2[] = {2};
//     vector<int> result = findUnion2(arr1, arr2, 7, 1);
//     for (int item : result)
//         cout << item << "  ";
//     cout << endl
//          << string(30, '-');
// }
// -------------------------------------------------------------- 349. Intersection of Two Arrays ------------------------------------------------------------
vector<int> findIntersection(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> nums1FrequencyCounter;
    unordered_map<int, int> nums2FrequencyCounter;
    vector<int> intersection;
    for (int item : nums1)
        nums1FrequencyCounter[item] = 1;
    for (int item : nums2)
        nums2FrequencyCounter[item] = 1;
    unordered_map<int, int>::iterator itr;
    for (itr = nums1FrequencyCounter.begin(); itr != nums1FrequencyCounter.end(); itr++)
    {
        if (nums2FrequencyCounter[itr->first])
            intersection.push_back(itr->first);
    }
    return intersection;
}
// ----------------
vector<int> findIntersection2(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> intersection;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int nums1Index = 0;
    int nums2Index = 0;
    while (nums1Index < nums1.size() && nums2Index < nums2.size())
    {
        if (nums1[nums1Index] == nums2[nums2Index])
        {
            if (intersection.size() == 0 || intersection.back() != nums1[nums1Index])
                intersection.push_back(nums1[nums1Index]);
            nums1Index++;
            nums2Index++;
        }
        else if (nums1[nums1Index] < nums2[nums2Index])
            nums1Index++;
        else
            nums2Index++;
    }
    return intersection;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums1 = {1, 2, 2, 1};
//     vector<int> nums2 = {2, 2};
//     vector<int> result = findIntersection2(nums1, nums2);
//     for (int item : result)
//         cout << item << "  ";
//     cout << endl
//          << string(30, '-');
// }
// -------------------------------------------------------------- 349. Intersection of Two Arrays ------------------------------------------------------------
int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    vector<int> isVisited(n + 1, 0);
    for (int item : nums)
        isVisited[item] = 1;
    int index;
    for (index = 0; index <= n; index++)
    {
        if (isVisited[index] == 0)
            break;
    }
    return index;
}
// ---------------
int missingNumber2(vector<int> &nums)
{
    nums.push_back(nums[0]);
    int index = 0;
    while (index < nums.size())
    {
        if (index == nums[index])
            index++;
        if (nums[index] != nums[nums[index]])
        {
            int temp = nums[index];
            nums[index] = nums[temp];
            nums[temp] = temp;
        }
        else
            index++;
    }
    index = 0;
    for (; index < nums.size(); index++)
    {
        if (nums[index] != index)
            break;
    }
    return index;
}
// ---------------------
int missingNumber3(vector<int> &nums)
{
    int n = nums.size();
    int index = 0;
    while (index < n)
    {
        int element = nums[index];
        if (element == n)
            index++;
        else if (nums[index] != nums[element])
        {
            nums[index] = nums[element];
            nums[element] = element;
        }
        else
            index++;
    }
    index = 0;
    while (index < n)
    {
        if (nums[index] != index)
            break;
        index++;
    }
    return index;
}
// ------- Using Mathematical Formula (SUM OF N NATURAL NUIMBERS "N(N+1)/2") ---------
int missingNumber4(vector<int> &nums)
{
    int n = nums.size();
    int sumOfNaturalNumber = n * (n + 1) / 2;
    int currentTotalSum = 0;
    for (int element : nums)
        currentTotalSum += element;
    return sumOfNaturalNumber - currentTotalSum;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {0, 1};
//     cout << missingNumber4(nums) << endl;
//     cout << endl
//          << string(30, '-');
// }
// -------------------------------------------------------------- 485. Max Consecutive Ones ------------------------------------------------------------
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int n = nums.size();
    int maxCount = 0;
    int currentCount = 0;
    int index = 0;
    for (int index = 0; index < n; index++)
    {
        if (nums[index] == 1)
            currentCount++;
        else
        {
            maxCount = max(currentCount, maxCount);
            currentCount = 0;
        }
    }
    return max(maxCount, currentCount);
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {1, 1, 0, 1, 1, 1};
//     cout << findMaxConsecutiveOnes(nums) << endl;
//     cout << endl
//          << string(30, '-');
// }
// -------------------------------------------------------------- 136. Single Number ------------------------------------------------------------
int singleNumber(vector<int> &nums)
{
    int result = nums[0];
    int n = nums.size();
    for (int i = 1; i < n; i++)
        result = result ^ nums[i];
    return result;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {4, 1, 2, 1, 2};
//     cout << singleNumber(nums) << endl;
//     cout << endl
//          << string(30, '-');
// }
// -------------------------------------------------------------- Longest Sub-Array with Sum K ------------------------------------------------------------
int lenOfLongSubarr(int A[], int N, int K)
{
    int maxSubArrayLen = 0;
    int currSubArrayLen = 0;
    for (int i = 0; i < N; i++)
    {
        int currSum = 0;
        for (int j = i; j < N; j++)
        {
            currSum += A[j];
            if (currSum == K)
            {
                maxSubArrayLen = max(maxSubArrayLen, (j - i) + 1);
            }
        }
    }
    return maxSubArrayLen;
}
// -----------------
int lenOfLongSubarr2(int A[], int N, int K)
{
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < N; i++)
    {
        sum += A[i];
        if (sum == K)
        {
            maxLen = max(maxLen, i + 1);
        }
        long long remaining = sum - K;
        if (preSumMap.find(remaining) != preSumMap.end())
        {
            int len = i - preSumMap[remaining];
            maxLen = max(maxLen, len);
        }
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     int A[] = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
//     cout << lenOfLongSubarr2(A, 6, -5) << endl;
//     cout << endl
//          << string(30, '-');
// }
// -------------------------------------------------------------- Largest subarray with 0 sum ------------------------------------------------------------
int maxLen(vector<int> &arr, int n)
{
    map<int, int> preSumMap;
    int maxLength = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            maxLength = max(maxLength, i + 1);
        }
        if (preSumMap.find(sum) != preSumMap.end())
        {
            int len = i - preSumMap[sum];
            maxLength = max(maxLength, len);
        }
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }
    return maxLength;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> arr = {-1, 1, -1, 1};
//     cout << maxLen(arr, 4) << endl;
//     cout << endl
//          << string(30, '-');
// }
// ----------------------------------------------------------------------------- 1. Two Sum ---------------------------------------------------------------------------
vector<int> twoSum(vector<int> &nums, int target)
{
    map<int, int> isPresent;
    vector<int> result(2);
    for (int index = 0; index < nums.size(); index++)
    {
        int required = target - nums[index];
        if (isPresent.find(required) != isPresent.end())
        {
            result[0] = isPresent[required];
            result[1] = index;
            break;
        }
        isPresent[nums[index]] = index;
    }
    return result;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {3, 2, 4};
//     vector<int> vect = twoSum(nums, 6);
//     cout << vect[0] << " : " << vect[1] << endl;
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------- 75. Sort Colors ------------------------------------------------------------------------
void sortColors(vector<int> &nums)
{
    map<int, int> frequencyCounter;
    for (int item : nums)
        frequencyCounter[item]++;
    int index = 0;
    for (int i = 1; i <= frequencyCounter[0]; i++)
        nums[index++] = 0;
    for (int i = 1; i <= frequencyCounter[1]; i++)
        nums[index++] = 1;
    for (int i = 1; i <= frequencyCounter[2]; i++)
        nums[index++] = 2;
    for (int item : nums)
        cout << item << " ";
}
// ------------
void sortColors2(vector<int> &nums)
{
    int n = nums.size();
    int smallest = INT_MAX;
    int largest = 0;
    for (int item : nums)
    {
        smallest = min(smallest, item);
        largest = max(largest, item);
    }
    int index = 0;
    int left = 0, right = n - 1;
    while (index <= right)
    {
        if (nums[index] == smallest)
        {
            swap(nums[index], nums[left]);
            index++;
            left++;
        }
        else if (nums[index] == largest)
        {
            swap(nums[index], nums[right]);
            right--;
        }
        else
            index++;
    }
}
// -------------
void sortColors3(vector<int> &colors)
{
    int redIndex = 0, whiteindex = 0, blueIndex = colors.size() - 1;
    while (whiteindex <= blueIndex)
    {
        if (colors[whiteindex] == 0)
        {
            if (colors[redIndex] != 0)
                swap(colors[redIndex], colors[whiteindex]);
            redIndex++;
            whiteindex++;
        }
        else if (colors[whiteindex] == 1)
            whiteindex++;
        else if (colors[whiteindex] == 2)
        {
            if (colors[blueIndex] != 2)
                swap(colors[whiteindex], colors[blueIndex]);
            blueIndex--;
        }
    }
}
// ------------------
void sortColors4(vector<int> &nums)
{
    int countZero = 0, countOne = 0, countTwo = 0;
    for (int item : nums)
    {
        if (item == 0)
            countZero++;
        else if (item == 1)
            countOne++;
        else
            countTwo++;
    }
    int index = 0;
    for (int count = 1; count <= countZero; count++)
        nums[index++] = 0;
    for (int count = 1; count <= countOne; count++)
        nums[index++] = 1;
    for (int count = 1; count <= countTwo; count++)
        nums[index++] = 2;
}
// ------- Dutch National Flag problem --------
void sortColorsImp(vector<int> &nums)
{
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else if (nums[mid] == 2)
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}
int main()
{
    cout << string(30, '-') << endl;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColorsImp(nums);
    cout << endl
         << string(30, '-');
}