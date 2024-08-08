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
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {2, 0, 2, 1, 1, 0};
//     sortColorsImp(nums);
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------- 169. Majority Element ------------------------------------------------------------------------
// Boyer-Moore Majority Voting Algorithm
int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int element;
    int elementCounter = 0;
    for (int index = 0; index < n; index++)
    {
        if (elementCounter == 0)
        {
            element = nums[index];
            elementCounter = 1;
        }
        else if (element == nums[index])
            elementCounter++;
        else
            elementCounter--;
    }
    int counter = 0;
    for (int index = 0; index < n; index++)
    {
        if (element == nums[index])
            counter++;
    }
    if (counter > n / 2)
        return element;
    return -1;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
//     cout << majorityElement(nums) << endl;
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------- 53. Maximum Subarray & print logic ------------------------------------------------------------------------
int maxSubArray(vector<int> &nums)
{
    int max_so_for = INT_MIN;
    int max_ending_here = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        max_ending_here += nums[i];
        if (max_ending_here > max_so_for)
            max_so_for = max_ending_here;
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_for;
}
// ---------------------
void printMaxSubArray(vector<int> &nums)
{
    int max_so_for = INT_MIN;
    int max_ending_here = 0;
    int maxSubArrayStartIndex = -1;
    int maxSubArrayEndingIndex = -1;
    int start;
    for (int i = 0; i < nums.size(); i++)
    {
        if (max_ending_here == 0)
            start = i;
        max_ending_here += nums[i];
        if (max_ending_here > max_so_for)
        {
            max_so_for = max_ending_here;
            maxSubArrayStartIndex = start;
            maxSubArrayEndingIndex = i;
        }
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    for (int index = maxSubArrayStartIndex; index <= maxSubArrayEndingIndex; index++)
    {
        cout << nums[index] << " ";
    }
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {-2, -3, 4, -1, -2, 1, 5, -2};
//     printMaxSubArray(nums);
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------- Maximum Score from Subarray Minimums ------------------------------------------------------------------------
int pairWithMaxSum(vector<int> &arr)
{
    int n = arr.size();
    int maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        int firstSmall = arr[i];
        int secondSmall = INT_MAX;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] <= firstSmall)
            {
                secondSmall = firstSmall;
                firstSmall = arr[j];
            }
            else
            {
                secondSmall = min(secondSmall, arr[j]);
            }
            maxSum = max(maxSum, firstSmall + secondSmall);
        }
    }
    return maxSum;
}
// ------------------
int pairWithMaxSum2(vector<int> &arr)
{
    int n = arr.size();
    int maxSum = 0;
    for (int index = 0; index < n - 1; index++)
    {
        maxSum = max(arr[index] + arr[index + 1], maxSum);
    }
    return maxSum;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> arr = {4, 3, 1, 5, 6};
//     cout << pairWithMaxSum2(arr) << endl;
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------- 121. Best Time to Buy and Sell Stock ------------------------------------------------------------------------
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int buyPrice = INT_MAX;
    int sellPrice = INT_MIN;
    int maxProfitPrice = 0;
    for (int index = 0; index < n; index++)
    {
        if (prices[index] < buyPrice)
        {
            buyPrice = prices[index];
            sellPrice = prices[index];
        }
        else if (prices[index] > sellPrice)
            sellPrice = prices[index];
        maxProfitPrice = max(maxProfitPrice, sellPrice - buyPrice);
    }
    return maxProfitPrice;
}
// -----------------------
int maxProfit2(vector<int> &prices)
{
    int n = prices.size();
    int buyPrice = INT_MAX;
    int sellPrice = INT_MIN;
    int maxProfitPrice = 0;
    for (int index = 0; index < n; index++)
    {
        sellPrice = prices[index];
        maxProfitPrice = max(maxProfitPrice, sellPrice - buyPrice);
        buyPrice = min(buyPrice, prices[index]);
    }
    return maxProfitPrice;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> arr = {7, 1, 5, 3, 6, 4};
//     cout << maxProfit2(arr) << endl;
//     cout << endl
//          << string(30, '-');
// }
// ------------------------------------------------------------- 2149. Rearrange Array Elements by Sign ------------------------------------------------------------------------
vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> result;
    int n = nums.size();
    int positiveIndex = 0;
    int negativeIndex = 0;
    while (positiveIndex < n || negativeIndex < n)
    {
        while (positiveIndex < n && nums[positiveIndex] < 0)
            positiveIndex++;
        if (positiveIndex < n)
            result.push_back(nums[positiveIndex]);
        positiveIndex++;
        while (negativeIndex < n && nums[negativeIndex] > 0)
            negativeIndex++;
        if (negativeIndex < n)
            result.push_back(nums[negativeIndex]);
        negativeIndex++;
    }
    return result;
}
// -----------------------
vector<int> rearrangeArray2(vector<int> &nums)
{
    vector<int> result;
    int n = nums.size();
    int positiveIndex = 0;
    int negativeIndex = 0;
    while (positiveIndex < n || negativeIndex < n)
    {
        while (positiveIndex < n)
        {
            if (nums[positiveIndex] >= 0)
            {
                result.push_back(nums[positiveIndex]);
                break;
            }
            positiveIndex++;
        }
        positiveIndex++;
        while (negativeIndex < n)
        {
            if (nums[negativeIndex] < 0)
            {
                result.push_back(nums[negativeIndex]);
                break;
            }
            negativeIndex++;
        }
        negativeIndex++;
    }
    return result;
}
// -------------------
vector<int> rearrangeArray3(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n);
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] >= 0)
        {
            result[index] = nums[i];
            index += 2;
        }
    }
    index = 1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] < 0)
        {
            result[index] = nums[i];
            index += 2;
        }
    }
    return result;
}
// ------------------
vector<int> rearrangeArray4(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n);
    int positiveIndex = 0;
    int negativeIndex = 1;
    for (int index = 0; index < n; index++)
    {
        if (nums[index] >= 0)
        {
            result[positiveIndex] = nums[index];
            positiveIndex += 2;
        }
        if (nums[index] < 0)
        {
            result[negativeIndex] = nums[index];
            negativeIndex += 2;
        }
    }
    return result;
}
// -------------------------------
// When negatinge count and positive count are not equal
vector<int> rearrangeArray5(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result;
    int positiveIndex = 0;
    int negativeIndex = 0;
    while (negativeIndex < n || positiveIndex < n)
    {
        while (positiveIndex < n && nums[positiveIndex] < 0)
            positiveIndex++;
        if (positiveIndex < n)
            result.push_back(nums[positiveIndex]);
        positiveIndex++;
        while (negativeIndex < n && nums[negativeIndex] >= 0)
            negativeIndex++;
        if (negativeIndex < n)
            result.push_back(nums[negativeIndex]);
        negativeIndex++;
    }
    return result;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     // vector<int> nums = {3, 1, -2, -5, 2, -4};
//     vector<int> nums = {1, -4, 2, -5, 3, 6};
//     vector<int> result = rearrangeArray5(nums);
//     for (int item : result)
//         cout << item << "  ";
//     cout << endl
//          << string(30, '-');
// }
// -------------------------------------------------------------------- 31. Next Permutation ------------------------------------------------------------------------
void nextPermutation(vector<int> &nums)
{
    int n = nums.size(); // size of the array.
    // Step 1: Find the break point:
    int index = -1; // break point
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            // index i is the break point
            index = i;
            break;
        }
    }
    // If break point does not exist:
    if (index == -1)
    {
        // reverse the whole array:
        reverse(nums.begin(), nums.end());
        return;
    }
    // Step 2: Find the next greater element
    // and swap it with arr[ind]:
    for (int i = n - 1; i > index; i--)
    {
        if (nums[i] > nums[index])
        {
            swap(nums[i], nums[index]);
            break;
        }
    }
    // Step 3: reverse the right half:
    reverse(nums.begin() + index + 1, nums.end());
}
// --------------------
void nextPermutationPractice(vector<int> &nums)
{
    int n = nums.size();
    int index = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }
    for (int i = n - 1; i > index; i--)
    {
        if (nums[i] > nums[index])
        {
            swap(nums[i], nums[index]);
            break;
        }
    }
    reverse(nums.begin() + index + 1, nums.end());
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     // vector<int> nums = {2, 1, 5, 4, 3, 0, 0};
//     // vector<int> nums = {2, 3, 0, 0, 1, 4, 5};
//     // vector<int> nums = {2, 3, 0, 0, 1, 5, 4};
//     vector<int> nums = {2, 3, 0, 0, 4, 5, 1};
//     // vector<int> nums = {1, 1, 5};
//     nextPermutationPractice(nums);
//     for (int item : nums)
//         cout << item << "  ";
//     cout << endl
//          << string(30, '-');
// }
// -------------------------------------------------------------------- Array Leaders ------------------------------------------------------------------------
vector<int> leaders(int n, int arr[])
{
    vector<int> result;
    result.push_back(arr[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] >= result.back())
        {
            result.push_back(arr[i]);
        }
    }
    reverse(result.begin(), result.end());
    return result;
}
// ---------------
vector<int> leader2(int n, int arr[])
{
    vector<int> result;
    // Last element of an array is always a leader,
    // push into ans array.
    int max = arr[n - 1];
    result.push_back(arr[n - 1]);
    // Start checking from the end whether a number is greater
    // than max no. from right, hence leader.
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > max)
        {
            result.push_back(arr[i]);
            max = arr[i];
        }
    }
    reverse(result.begin(), result.end());
    return result;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     int arr[] = {16, 17, 4, 3, 5, 2};
//     vector<int> result = leader2(sizeof(arr) / sizeof(int), arr);
//     for (int item : result)
//         cout << item << "  ";
//     cout << endl
//          << string(30, '-');
// }
// -------------------------------------------------------------------- 128. Longest Consecutive Sequence ------------------------------------------------------------------------
// TLE
int longestConsecutive(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> umap;
    for (int item : nums)
        umap[item] = 1;
    int maxCount = 0;
    for (int index = 0; index < n; index++)
    {
        int currentCount = 0;
        int element = nums[index];
        while (umap[element])
        {
            currentCount++;
            element--;
        }
        maxCount = max(maxCount, currentCount);
    }
    return maxCount;
}
// ------------------
int longestConsecutive2(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    sort(nums.begin(), nums.end());
    int longestLength = INT_MIN;
    int currentLongestLength = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1])
            continue;
        else if (nums[i] == (nums[i - 1] + 1))
            currentLongestLength++;
        else
        {
            longestLength = max(longestLength, currentLongestLength);
            currentLongestLength = 1;
        }
    }
    longestLength = max(longestLength, currentLongestLength);
    return longestLength;
}
// -------------------
int longestConsecutive3(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    int longest = 1;
    unordered_set<int> st;
    // put all the array elements into set:
    for (int i = 0; i < n; i++)
        st.insert(nums[i]);
    // Find the longest sequence:
    for (auto &item : st)
    {
        // if 'it' is a starting number:
        if (st.find(item - 1) == st.end())
        {
            // find consecutive numbers:
            int count = 1;
            int x = item;
            while (st.find(x + 1) != st.end())
            {
                x = x + 1;
                count++;
            }
            longest = max(longest, count);
        }
    }
    return longest;
}
// --------------------
int longestConsecutive4(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    int longest = 1;
    unordered_map<int, int> umap;
    // put all the array elements into Map:
    for (int item : nums)
        umap[item] = 1;
    // Find the longest sequence:
    for (auto &item : umap)
    {
        int element = item.first;
        // if 'it' is a starting number:
        if (umap.count(element - 1) == 0)
        {
            // find consecutive numbers:
            int currentCount = 1;
            while (umap.count(element + 1))
            {
                currentCount++;
                element++;
            }
            longest = max(longest, currentCount);
        }
    }
    return longest;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {8, 3, 5, 2, 1, 0, 3, 1, 0, 0, 2};
//     cout << longestConsecutive4(nums) << endl;
//     cout << endl
//          << string(30, '-');
// }
// -------------------------------------------------------------------- 73. Set Matrix Zeroes ------------------------------------------------------------------------
void setZeroes1(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> rowValidate;
    vector<int> columnValidate;
    for (int row = 0; row < m; row++)
    {
        for (int column = 0; column < n; column++)
        {
            if (matrix[row][column] == 0)
            {
                for (int rw = 0; rw < m; rw++)
                {
                    if (matrix[rw][column] != 0)
                        matrix[rw][column] = -1;
                }
                for (int col = 0; col < n; col++)
                {
                    if (matrix[row][col] != 0)
                        matrix[row][col] = -1;
                }
            }
        }
    }
    for (int row = 0; row < m; row++)
    {
        for (int column = 0; column < n; column++)
        {
            if (matrix[row][column] == -1)
                matrix[row][column] = 0;
        }
    }
    for (int row = 0; row < m; row++)
    {
        for (int column = 0; column < n; column++)
        {
            cout << matrix[row][column] << "  ";
        }
        cout << endl;
    }
}
// -----------------------
void setZeroes2(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> rowValidate;
    vector<int> columnValidate;
    for (int row = 0; row < m; row++)
    {
        for (int column = 0; column < n; column++)
        {
            if (matrix[row][column] == 0)
            {
                rowValidate.push_back(row);
                columnValidate.push_back(column);
            }
        }
    }
    for (int row : rowValidate)
    {
        for (int column = 0; column < n; column++)
        {
            matrix[row][column] = 0;
        }
    }
    for (int column : columnValidate)
    {
        for (int row = 0; row < m; row++)
        {
            matrix[row][column] = 0;
        }
    }
    for (int row = 0; row < m; row++)
    {
        for (int column = 0; column < n; column++)
        {
            cout << matrix[row][column] << "  ";
        }
        cout << endl;
    }
}
// --------------
void setZeroes3(vector<vector<int>> &matrix)
{
    int rowCount = matrix.size();
    int columnCount = matrix[0].size();
    // int row[rowCount] = {0}; --> matrix[..][0]
    // int col[columnCount] = {0}; --> matrix[0][..]
    int col0 = 1;
    // step: 1: Traverse the matrix amd
    // mark 1st row & col accordingly:
    for (int row = 0; row < rowCount; row++)
    {
        for (int column = 0; column < columnCount; column++)
        {
            if (matrix[row][column] == 0)
            {
                // mark i-th row
                matrix[row][0] = 0;
                // mark j-th column
                if (column != 0)
                    matrix[0][column] = 0;
                else
                    col0 = 0;
            }
        }
    }

    // Step 2: Mark with 0 from (1, 1) to (rowCount-1, columnCount-1):
    for (int row = 1; row < rowCount; row++)
    {
        for (int column = 1; column < columnCount; column++)
        {
            if (matrix[row][column] != 0)
            {
                // check for row & column
                if (matrix[row][0] == 0 || matrix[0][column] == 0)
                    matrix[row][column] = 0;
            }
        }
    }
    // Step 3: Finally mark the 1st column and then 1st row:
    if (matrix[0][0] == 0)
    {
        for (int column = 0; column < columnCount; column++)
        {
            matrix[0][column] = 0;
        }
    }
    if (col0 == 0)
    {
        for (int row = 0; row < rowCount; row++)
        {
            matrix[row][0] = 0;
        }
    }
}
// ------------
void setZeroesRevision(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int col0 = 1;
    for (int row = 0; row < m; row++)
    {
        for (int column = 0; column < n; column++)
        {
            if (matrix[row][column] == 0)
            {
                matrix[row][0] = 0;
                if (column != 0)
                    matrix[0][column] = 0;
                else
                    col0 = 0;
            }
        }
    }
    for (int row = 1; row < m; row++)
    {
        for (int column = 1; column < n; column++)
        {
            if (matrix[row][column] != 0)
            {
                if (matrix[row][0] == 0 || matrix[0][column] == 0)
                {
                    matrix[row][column] = 0;
                }
            }
        }
    }
    if (matrix[0][0] == 0)
    {
        for (int row = 0; row < m; row++)
        {
            matrix[row][0] = 0;
        }
    }
    if (col0 == 0)
    {
        for (int column = 0; column < n; column++)
        {
            matrix[0][column] = 0;
        }
    }
    for (int row = 0; row < m; row++)
    {
        for (int column = 0; column < n; column++)
        {
            cout << matrix[row][column] << "  ";
        }
        cout << endl;
    }
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
//     // vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
//     // vector<vector<int>> matrix = {{1, 0, 3}};
//     setZeroesRevision(matrix);
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------- 48. Rotate Image ------------------------------------------------------------------------
void rotate(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    for (int row = 1; row < m; row++)
    {
        for (int column = 0; column < row; column++)
        {
            swap(matrix[row][column], matrix[column][row]);
        }
    }
    for (int row = 0; row < m; row++)
    {
        for (int column = 0; column < n / 2; column++)
        {
            int temp = matrix[row][column];
            matrix[row][column] = matrix[row][n - 1 - column];
            matrix[row][n - 1 - column] = temp;
        }
    }
    for (int row = 0; row < m; row++)
    {
        for (int column = 0; column < n; column++)
        {
            cout << matrix[row][column] << "  ";
        }
        cout << endl;
    }
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<vector<int>> matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
//     rotate(matrix);
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------- 54. Spiral Matrix ------------------------------------------------------------------------
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int columnLeft = 0, columnRight = n - 1;
    int rowTop = 0, rowBottom = m - 1;
    vector<int> result;
    while (1)
    {
        for (int column = columnLeft; column <= columnRight; column++)
            result.push_back(matrix[rowTop][column]);
        rowTop++;
        if (rowTop > rowBottom)
            break;
        for (int row = rowTop; row <= rowBottom; row++)
            result.push_back(matrix[row][columnRight]);
        columnRight--;
        if (columnLeft > columnRight)
            break;
        for (int column = columnRight; column >= columnLeft; column--)
            result.push_back(matrix[rowBottom][column]);
        rowBottom--;
        if (rowTop > rowBottom)
            break;
        for (int row = rowBottom; row >= rowTop; row--)
            result.push_back(matrix[row][columnLeft]);
        columnLeft++;
        if (columnLeft > columnRight)
            break;
    }
    return result;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
//     vector<int> result = spiralOrder(matrix);
//     for (int item : result)
//         cout << item << " ";
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------- 560. Subarray Sum Equals K ------------------------------------------------------------------------
int subarraySum(vector<int> &nums, int K)
{
    map<long long, int> preSumMap;
    int sum = 0;
    int subarrayCount = 0;
    for (int index = 0; index < nums.size(); index++)
    {
        sum += nums[index];
        if (sum == K)
            subarrayCount++;
        int remaining = sum - K;
        if (preSumMap.find(remaining) != preSumMap.end())
            subarrayCount += preSumMap[remaining];
        preSumMap[sum] = preSumMap[sum] + 1;
    }
    return subarrayCount;
}
// --------------
int subarraySum2(vector<int> &nums, int K)
{
    map<long long, int> preSumMap;
    int sum = 0;
    int subarrayCount = 0;
    preSumMap[0] = 1;
    for (int index = 0; index < nums.size(); index++)
    {
        sum += nums[index];
        int remaining = sum - K;
        if (preSumMap.find(remaining) != preSumMap.end())
            subarrayCount += preSumMap[remaining];
        preSumMap[sum] = preSumMap[sum] + 1;
    }
    return subarrayCount;
}

// int main()
// {
//     cout << string(30, '-') << endl;
//     // vector<int> nums = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//     vector<int> nums = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
//     cout << subarraySum2(nums, 3) << endl;
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------- 118. Pascal's Triangle ------------------------------------------------------------------------
// nCr=n!/r!(n-r)!
int nCr(int n, int r)
{
    long long result = 1;
    // calculating nCr:
    for (int i = 0; i < r; i++)
    {
        result = result * (n - i);
        result = result / (i + 1);
    }
    return result;
}
void pascaltriangle(int n)
{
    // printing the entire row m:
    for (int c = 1; c <= n; c++)
    {
        cout << nCr(n - 1, c - 1) << " ";
    }
}
// ----------------------
void pascaltriangle2(int n)
{
    long long result = 1;
    cout << result << " "; // printing 1st element
    // printing the rest of the part:
    for (int i = 1; i < n; i++)
    {
        result = result * (n - 1);
        result = result / i;
        cout << result << " ";
    }
}
// -------------------------------------
vector<int> generateRow(int row)
{
    long long result = 1;
    vector<int> resultRow;
    resultRow.push_back(1); // inserting the 1st element
    // calculating the rest of the elements:
    for (int column = 1; column < row; column++)
    {
        result = result * (row - column);
        result = result / column;
        resultRow.push_back(result);
    }
    return resultRow;
}
vector<vector<int>> generatePascalTrianle(int n)
{
    vector<vector<int>> result;
    // store the entire pascal's triangle:
    for (int row = 1; row <= n; row++)
    {
        result.push_back(generateRow(row));
    }
    return result;
}
// -------------------------------------
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> result;
    for (int row = 0; row < numRows; row++)
    {
        result.push_back({});
        for (int column = 0; column <= row; column++)
        {
            if (column == 0 || column == row)
                result.back().push_back(1);
            else
                result.back().push_back(result[row - 1][column - 1] + result[row - 1][column]);
        }
    }
    return result;
}
int main()
{
    cout << string(30, '-') << endl;
    vector<vector<int>> result = generate(5);
    for (int row = 0; row < 5; row++)
    {
        for (int column = 0; column <= row; column++)
        {
            cout << result[row][column] << " ";
        }
        cout << endl;
    }
    cout << endl
         << string(30, '-');
}