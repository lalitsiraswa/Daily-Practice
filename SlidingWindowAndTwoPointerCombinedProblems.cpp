#include <bits/stdc++.h>
using namespace std;

// -------------------------------------------------------------- 1423. Maximum Points You Can Obtain from Cards ------------------------------------------------------
int maxScore(vector<int> &cardPoints, int k)
{
    int n = cardPoints.size();
    int windowSum = 0;
    for (int i = 0; i < k; i++)
    {
        windowSum += cardPoints[i];
    }
    // If the window size is equal to the number of elements:
    if (n == k)
    {
        return windowSum;
    }
    // left is pointing to the end of the left hand side window:
    int left = k - 1;
    // right is pointing to the starting of the right hand side window:
    int right = n - 1;
    int maximumScore = windowSum;
    while (left >= 0)
    {
        // Shrink the window from the left hand side:
        windowSum -= cardPoints[left];
        // Extend the window from the right hand side:
        windowSum += cardPoints[right];
        left -= 1;
        right -= 1;
        maximumScore = max(maximumScore, windowSum);
    }
    return maximumScore;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> cardPoints = {6, 2, 3, 4, 7, 2, 1, 7, 1};
//     cout << maxScore(cardPoints, 4);
//     cout << endl
//          << string(30, '-');
// }
// -------------------------------------------------------------- 3. Longest Substring Without Repeating Characters ------------------------------------------------------
int lengthOfLongestSubstring(string &s)
{
    int n = s.size();
    unordered_map<char, int> window;
    int high = 0;
    while (high < n)
    {
        if (window[s[high]] == 1)
        {
            break;
        }
        window[s[high]] = 1;
        high += 1;
    }
    int maxSubstringLength = window.size();
    int low = 0;
    while (high < n)
    {
        while (window[s[high]] == 1)
        {
            window[s[low]] = 0;
            low += 1;
        }
        window[s[high]] = 1;
        int currentWindowLength = 0;
        for (auto item : window)
        {
            currentWindowLength += item.second;
        }
        maxSubstringLength = max(maxSubstringLength, currentWindowLength);
        high += 1;
    }
    return maxSubstringLength;
}
// ---------------------------
int lengthOfLongestSubstring2(string &s)
{
    int n = s.size();
    unordered_map<char, int> window;
    int high = 0;
    while (high < n)
    {
        if (window[s[high]] == 1)
        {
            break;
        }
        window[s[high]] = 1;
        high += 1;
    }
    int maxSubstringLength = window.size();
    int low = 0;
    while (high < n)
    {
        while (window[s[high]] == 1)
        {
            window[s[low]] = 0;
            low += 1;
        }
        window[s[high]] = 1;
        maxSubstringLength = max(maxSubstringLength, (high - low) + 1);
        high += 1;
    }
    return maxSubstringLength;
}
// ---------------------------
int lengthOfLongestSubstring3(string &s)
{
    int n = s.size();
    unordered_map<char, int> window;
    int low = 0;
    int high = 0;
    int maxSubstringLength = 0;
    while (high < n)
    {
        if (window.find(s[high]) != window.end())
        {
            while (window[s[high]] == 1)
            {
                window[s[low]] = 0;
                low += 1;
            }
        }
        window[s[high]] = 1;
        // maxSubstringLength = max(maxSubstringLength, (high - low) + 1);
        high += 1;
        maxSubstringLength = max(maxSubstringLength, high - low);
    }
    return maxSubstringLength;
}
// ------------- TUF --------------
int lengthOfLongestSubstringTuf(string &s)
{
    int n = s.size();
    // unordered_map<char, index> window:
    unordered_map<char, int> window;
    // We can also use the array instead of unordered_map:
    // int hash[256] = {-1};
    int low = 0;
    int high = 0;
    int maxSubstringLength = 0;
    while (high < n)
    {
        if (window.find(s[high]) != window.end())
        {
            // If low pointer is less than the last visted index of the particular character, update it:
            if (low < window[s[high]] + 1)
            {
                low = window[s[high]] + 1;
            }
        }
        window[s[high]] = high;
        // maxSubstringLength = max(maxSubstringLength, (high - low) + 1);
        high += 1;
        maxSubstringLength = max(maxSubstringLength, high - low);
    }
    return maxSubstringLength;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     string s = "pwwkew";
//     cout << lengthOfLongestSubstringTuf(s);
//     cout << endl
//          << string(30, '-');
// }
// -------------------------------------------------------------- 1004. Max Consecutive Ones III ------------------------------------------------------
int longestOnes(vector<int> &nums, int k)
{
    int n = nums.size();
    int maxOneCount = 0;
    int low = 0;
    while (low < n)
    {
        int zeroCount = 0;
        int high = low;
        while (high < n)
        {
            if (nums[high] == 0)
            {
                zeroCount += 1;
            }
            // If we fliped 0 more than k times break the loop:
            if (zeroCount > k)
                break;
            high += 1;
        }
        maxOneCount = max(maxOneCount, high - low);
        low += 1;
        if (high == n)
        {
            break;
        }
    }
    return maxOneCount;
}
// -------------------------
int longestOnesTwoPointer(vector<int> &nums, int k)
{
    int n = nums.size();
    int maxOneCount = 0;
    int low = 0;
    int high = 0;
    int zeroCount = 0;
    while (high < n)
    {
        if (nums[high] == 0)
        {
            zeroCount += 1;
        }
        while (zeroCount > k)
        {
            if (nums[low] == 0)
            {
                zeroCount -= 1;
            }
            low += 1;
        }
        // 0 based indenxing that's why we need to add 1:
        maxOneCount = max(maxOneCount, (high - low) + 1);
        high += 1;
    }
    return maxOneCount;
}
// ------------- TUF ------------
int longestOnesTUF(vector<int> &nums, int k)
{
    int n = nums.size();
    int maxOneCount = 0;
    int low = 0;
    int high = 0;
    int zeroCount = 0;
    while (high < n)
    {
        if (nums[high] == 0)
        {
            zeroCount += 1;
        }
        if (zeroCount > k)
        {
            if (nums[low] == 0)
            {
                zeroCount -= 1;
            }
            low += 1;
        }
        if (zeroCount <= k)
        {
            maxOneCount = max(maxOneCount, high - low + 1);
        }
        high += 1;
    }
    return maxOneCount;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
//     cout << longestOnesTUF(nums, 2);
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------- Fruit Into Baskets ---------------------------------------------------------------------
int totalFruits(vector<int> &arr)
{
    int n = arr.size();
    int maxFruitCount = 0;
    for (int i = 0; i < n; i++)
    {
        int firstBasket = arr[i];
        int secondBasket = -1;
        int currentFruitCount = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] == firstBasket || arr[j] == secondBasket)
            {
                currentFruitCount += 1;
            }
            else if (secondBasket == -1)
            {
                secondBasket = arr[j];
                currentFruitCount += 1;
            }
            else
            {
                break;
            }
        }
        maxFruitCount = max(maxFruitCount, currentFruitCount);
    }
    return maxFruitCount;
}
// ----------------------
int totalFruits2(vector<int> &arr)
{
    int n = arr.size();
    int maxFruitCount = 0;
    int low = 0;
    int high = 0;
    int firstBasket = arr[0];
    int secondBasket = -1;
    int firstBasketCount = 0;
    int secondBasketCount = 0;
    while (high < n)
    {
        if (arr[high] == firstBasket)
        {
            firstBasketCount += 1;
        }
        else if (arr[high] == secondBasket)
        {
            secondBasketCount += 1;
        }
        else if (secondBasket == -1)
        {
            secondBasket = arr[high];
            secondBasketCount = 1;
        }
        else
        {
            while (true)
            {
                if (arr[low] == firstBasket)
                {
                    firstBasketCount -= 1;
                }
                if (arr[low] == secondBasket)
                {
                    secondBasketCount -= 1;
                }
                low += 1;
                if (firstBasketCount == 0)
                {
                    firstBasket = arr[high];
                    firstBasketCount = 1;
                    break;
                }
                if (secondBasketCount == 0)
                {
                    secondBasket = arr[high];
                    secondBasketCount = 1;
                    break;
                }
            }
        }
        maxFruitCount = max(maxFruitCount, high - low + 1);
        high += 1;
    }
    return maxFruitCount;
}
// ----------------------
int totalFruitsTufSlidingWindow(vector<int> &arr)
{
    int n = arr.size();
    // unordered_map<value, frequency> umap;
    unordered_map<int, int> umap;
    int maxFruitCount = 0;
    int low = 0;
    int high = 0;
    while (high < n)
    {
        umap[arr[high]] += 1;
        // Only two diffrent type of basket we have:
        while (umap.size() > 2)
        {
            umap[arr[low]] -= 1;
            if (umap[arr[low]] == 0)
            {
                umap.erase(arr[low]);
            }
            low += 1;
        }
        maxFruitCount = max(maxFruitCount, (high - low) + 1);
        high += 1;
    }
    return maxFruitCount;
}
// ----------------------
int totalFruitsTufSlidingWindow2(vector<int> &arr)
{
    int n = arr.size();
    // unordered_map<value, frequency> umap;
    unordered_map<int, int> umap;
    int maxFruitCount = 0;
    int low = 0;
    int high = 0;
    while (high < n)
    {
        umap[arr[high]] += 1;
        // Only two diffrent type of basket we have:
        if (umap.size() > 2)
        {
            umap[arr[low]] -= 1;
            if (umap[arr[low]] == 0)
            {
                umap.erase(arr[low]);
            }
            low += 1;
        }
        if (umap.size() <= 2)
        {
            maxFruitCount = max(maxFruitCount, (high - low) + 1);
        }
        high += 1;
    }
    return maxFruitCount;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {1, 1, 5, 6, 7, 8, 9};
//     cout << totalFruitsTufSlidingWindow2(nums);
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------- Longest Substring with K Uniques ---------------------------------------------------------------------
// TLE
int longestKSubstr(string &s, int k)
{
    int n = s.size();
    int maxSubstringLength = -1;
    for (int i = 0; i < n; i++)
    {
        unordered_map<char, int> frequency;
        for (int j = i; j < n; j++)
        {
            frequency[s[j]] += 1;
            if (frequency.size() == k)
            {
                maxSubstringLength = max(maxSubstringLength, (j - i) + 1);
            }
            if (frequency.size() > k)
            {
                break;
            }
        }
    }
    return maxSubstringLength;
}
// ---------- Sliding Window || Two Pointer -------------
int longestKSubstrSlidingWindow(string &s, int k)
{
    int n = s.size();
    int maxSubstringLength = -1;
    unordered_map<char, int> frequency;
    int low = 0;
    int high = 0;
    while (high < n)
    {
        frequency[s[high]] += 1;
        while (frequency.size() > k)
        {
            frequency[s[low]] -= 1;
            if (frequency[s[low]] == 0)
            {
                frequency.erase(s[low]);
            }
            low += 1;
        }
        if (frequency.size() == k)
        {
            maxSubstringLength = max(maxSubstringLength, (high - low) + 1);
        }
        high += 1;
    }
    return maxSubstringLength;
}
// ---------- Sliding Window || Two Pointer -------------
int longestKSubstrSlidingWindow2(string &s, int k)
{
    int n = s.size();
    int maxSubstringLength = -1;
    unordered_map<char, int> frequency;
    int low = 0;
    int high = 0;
    while (high < n)
    {
        frequency[s[high]] += 1;
        if (frequency.size() > k)
        {
            frequency[s[low]] -= 1;
            if (frequency[s[low]] == 0)
            {
                frequency.erase(s[low]);
            }
            low += 1;
        }
        if (frequency.size() == k)
        {
            maxSubstringLength = max(maxSubstringLength, (high - low) + 1);
        }
        high += 1;
    }
    return maxSubstringLength;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     string s = "aabacbebebe";
//     cout << longestKSubstrSlidingWindow2(s, 3);
//     cout << endl
//          << string(30, '-');
// }
// ------------------------------------------------------------ 1358. Number of Substrings Containing All Three Characters ---------------------------------------------------------------------
// TLE
int numberOfSubstrings(string s)
{
    int n = s.size();
    int totalNumberOfSubstring = 0;
    for (int i = 0; i < n; i++)
    {
        unordered_map<char, int> frequency;
        for (int j = i; j < n; j++)
        {
            frequency[s[j]] += 1;
            if (frequency.size() == 3)
            {
                totalNumberOfSubstring += (n - j);
                break;
            }
        }
    }
    return totalNumberOfSubstring;
}
// Sliding Window || Two Pointer
// "aaaabc" -> Dry Run -> 4
int numberOfSubstringsSlidingWindow(string s)
{
    int n = s.size();
    int totalNumberOfSubstring = 0;
    unordered_map<char, int> frequency;
    int low = 0;
    int high = 0;
    while (high < n)
    {
        frequency[s[high]] += 1;
        while (frequency.size() == 3)
        {
            totalNumberOfSubstring += (n - high);
            frequency[s[low]] -= 1;
            if (frequency[s[low]] == 0)
            {
                frequency.erase(s[low]);
            }
            low += 1;
        }
        high += 1;
    }
    return totalNumberOfSubstring;
}
// TUF -> Dry Run
int numberOfSubstringsSlidingWindowTUF(string s)
{
    int n = s.size();
    int totalNumberOfSubstring = 0;
    int lastSeen[3] = {-1, -1, -1};
    // Find the minimum window with all 3 characters (a, b, c):
    for (int i = 0; i < n; i++)
    {
        // Update the last seen index:
        lastSeen[s[i] - 'a'] = i;
        if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1)
        {
            // All the character before the min index character will be a substring:
            totalNumberOfSubstring += 1 + min(lastSeen[0], min(lastSeen[1], lastSeen[2]));
        }
    }
    return totalNumberOfSubstring;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     string s = "abcabc";
//     cout << numberOfSubstringsSlidingWindowTUF(s);
//     cout << endl
//          << string(30, '-');
// }
// ---------------------------------------------------------------- 424. Longest Repeating Character Replacement -------------------------------------------------------------------------
// TLE
int characterReplacement(string s, int k)
{
    int n = s.size();
    int maxSubstringLen = 0;
    for (int i = 0; i < n; i++)
    {
        unordered_map<char, int> frequency;
        int maxFrequency = 0;
        for (int j = i; j < n; j++)
        {
            frequency[s[j]] += 1;
            maxFrequency = max(maxFrequency, frequency[s[j]]);
            int charReplacementCount = ((j - i) + 1) - maxFrequency;
            if (charReplacementCount <= k)
            {
                maxSubstringLen = max(maxSubstringLen, (j - i) + 1);
            }
            else
            {
                break;
            }
        }
    }
    return maxSubstringLen;
}
// -----------------
int characterReplacementSlidingWindow(string s, int k)
{
    int n = s.size();
    int maxSubstringLen = 0;
    unordered_map<char, int> frequency;
    int maxFrequency = 0;
    int low = 0;
    int high = 0;
    while (high < n)
    {
        frequency[s[high]] += 1;
        maxFrequency = max(maxFrequency, frequency[s[high]]);
        int charReplacementCount = ((high - low) + 1) - maxFrequency;
        while (charReplacementCount > k)
        {
            frequency[s[low]] -= 1;
            if (frequency[s[low]] == 0)
            {
                frequency.erase(s[low]);
            }
            maxFrequency = 0;
            for (auto item : frequency)
            {
                maxFrequency = max(maxFrequency, item.second);
            }
            low += 1;
            charReplacementCount = ((high - low) + 1) - maxFrequency;
        }
        maxSubstringLen = max(maxSubstringLen, (high - low) + 1);
        high += 1;
    }
    return maxSubstringLen;
}
// ---------------------
int characterReplacementTuf(string s, int k)
{
    int n = s.size();
    int maxSubstringLen = 0;
    unordered_map<char, int> frequency;
    int maxFrequency = 0;
    int left = 0;
    for (int right = 0; right < n; right++)
    {
        frequency[s[right]]++;
        maxFrequency = max(maxFrequency, frequency[s[right]]);
        int windowSize = right - left + 1;
        int charReplacementCount = windowSize - maxFrequency;
        if (charReplacementCount > k)
        {
            frequency[s[left]]--;
            left++;
        }
        if (charReplacementCount <= k)
        {
            maxSubstringLen = max(maxSubstringLen, right - left + 1);
        }
    }
    return maxSubstringLen;
}

// int main()
// {
//     cout << string(30, '-') << endl;
//     string s = "AABABBA";
//     cout << characterReplacementTuf(s, 1);
//     cout << endl
//          << string(30, '-');
// }
// ---------------------------------------------------------------- 560. Subarray Sum Equals K -------------------------------------------------------------------------
int subarraySum(vector<int> &nums, int k)
{
    int n = nums.size();             // take the size of the array
    vector<int> cumulativeSum(n, 0); // make a prefix array to store prefix sum
    cumulativeSum[0] = nums[0];      // for element at index at zero, it is same
    // making our prefix array
    for (int i = 1; i < n; i++)
        cumulativeSum[i] = (nums[i] + cumulativeSum[i - 1]);
    unordered_map<int, int> umap; // declare an unordered map
    int numOfSubArray = 0;        // to store the number of our subarrays having sum as 'k'
    for (int i = 0; i < n; i++)   // traverse from the prefix array
    {
        if (cumulativeSum[i] == k) // if it already becomes equal to k, then increment ans
            numOfSubArray++;
        // now, find whether (prefix[i] - k) present in map or not
        if (umap.find(cumulativeSum[i] - k) != umap.end())
            numOfSubArray += umap[cumulativeSum[i] - k]; // if yes, then add it our answer
        umap[cumulativeSum[i]]++;                        // put prefix sum into our map
    }
    return numOfSubArray; // and at last, return our answer
}
// ----------------------------------
int subarraySum2(vector<int> &nums, int K)
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
// TUF
int subarraySumTUF(vector<int> &nums, int k)
{
    // Size of the given arrays:
    int n = nums.size();
    map<long long, int> preSumMap;
    int preSum = 0;
    int subarrayCount = 0;
    // Setting 0 in the map:
    preSumMap[0] = 1;
    for (int index = 0; index < n; index++)
    {
        // Add current element to prefix sum:
        preSum += nums[index];
        // Calculate x-k:
        int remove = preSum - k;
        // Add the number of subarrays to be removed:
        subarrayCount += preSumMap[remove];
        // Update the count of prefix sum in the map:
        preSumMap[preSum] += 1;
    }
    return subarrayCount;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
//     cout << subarraySumTUF(nums, 3);
//     cout << endl
//          << string(30, '-');
// }
// ---------------------------------------------------------------- 930. Binary Subarrays With Sum -------------------------------------------------------------------------
// TLE
int numSubarraysWithSumBruteForce(vector<int> &nums, int goal)
{
    int n = nums.size();
    int subarrayCount = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (sum == goal)
            {
                subarrayCount += 1;
            }
            if (sum > goal)
            {
                break;
            }
        }
    }
    return subarrayCount;
}
// ----------------
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    // Size of the given arrays:
    int n = nums.size();
    map<long long, int> preSumMap;
    int preSum = 0;
    int subarrayCount = 0;
    // Setting 0 in the map:
    preSumMap[0] = 1;
    for (int index = 0; index < n; index++)
    {
        // Add current element to prefix sum:
        preSum += nums[index];
        // Calculate x-k:
        int remove = preSum - goal;
        // Add the number of subarrays to be removed:
        subarrayCount += preSumMap[remove];
        // Update the count of prefix sum in the map:
        preSumMap[preSum] += 1;
    }
    return subarrayCount;
}
// -------- TUF --------
int countSubarraysWithSumLessThanOrEqualToK(const vector<int> &nums, int k)
{
    int n = nums.size();
    int subarrayCount = 0;
    int currentSum = 0;
    int start = 0;
    // Edge Case: If k is negative, no valid subarray can exist
    if (k < 0)
    {
        return 0;
    }
    for (int end = 0; end < n; ++end)
    {
        currentSum += nums[end];
        // Shrink the window if the current sum exceeds k
        while (currentSum > k)
        {
            currentSum -= nums[start];
            ++start;
        }
        // All subarrays ending at 'end' and starting from indices >= 'start' are valid
        subarrayCount += (end - start + 1);
    }
    return subarrayCount;
}
int countSubarraysWithExactSum(const vector<int> &nums, int targetSum)
{
    // Subarrays with sum exactly equal to targetSum can be derived by:
    // Count of subarrays with sum <= targetSum
    // minus Count of subarrays with sum < targetSum
    return countSubarraysWithSumLessThanOrEqualToK(nums, targetSum) -
           countSubarraysWithSumLessThanOrEqualToK(nums, targetSum - 1);
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {1, 0, 1, 0, 1};
//     cout << countSubarraysWithExactSum(nums, 2);
//     cout << endl
//          << string(30, '-');
// }
// ---------------------------------------------------------------- 1248. Count Number of Nice Subarrays -------------------------------------------------------------------------
// TLE
int numberOfSubarraysBruteForce(vector<int> &nums, int k)
{
    int n = nums.size();
    int subarraysCount = 0;
    for (int i = 0; i < n; i++)
    {
        int oddElementCount = 0;
        for (int j = i; j < n; j++)
        {
            if (nums[j] % 2 != 0)
            {
                oddElementCount += 1;
            }
            if (oddElementCount == k)
            {
                subarraysCount += 1;
            }
            if (oddElementCount > k)
            {
                break;
            }
        }
    }
    return subarraysCount;
}
// ----------------------
int countSubarraysWithAtMostKOddElements(const vector<int> &nums, int k)
{
    int n = nums.size();
    int subarrayCount = 0;
    int oddCount = 0;
    int start = 0;
    // Edge Case: If k is negative, no valid subarray can exist
    if (k < 0)
    {
        return 0;
    }
    for (int end = 0; end < n; ++end)
    {
        // Increment odd count if the current element is odd
        if (nums[end] % 2 != 0)
        {
            oddCount++;
        }
        // Shrink the window until the number of odd elements is <= k
        while (oddCount > k)
        {
            if (nums[start] % 2 != 0)
            {
                oddCount--;
            }
            start++;
        }
        // All subarrays ending at 'end' and starting from indices >= 'start' are valid
        subarrayCount += (end - start + 1);
    }
    return subarrayCount;
}
int numberOfSubarraysWithExactKOddElements(const vector<int> &nums, int k)
{
    // Subarrays with exactly k odd elements are:
    // Subarrays with at most k odd elements
    // minus Subarrays with at most (k-1) odd elements
    return countSubarraysWithAtMostKOddElements(nums, k) -
           countSubarraysWithAtMostKOddElements(nums, k - 1);
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
//     cout << numberOfSubarraysBruteForce(nums, 2);
//     cout << endl
//          << string(30, '-');
// }
// ---------------------------------------------------------------- 992. Subarrays with K Different Integers -------------------------------------------------------------------------
// TLE
int subarraysWithKDistinctBruteForce(vector<int> &nums, int k)
{
    int n = nums.size();
    int subarraysCount = 0;
    for (int i = 0; i < n; i++)
    {
        unordered_set<int> distinctSet;
        for (int j = i; j < n; j++)
        {
            distinctSet.insert(nums[j]);
            if (distinctSet.size() == k)
            {
                subarraysCount += 1;
            }
            if (distinctSet.size() > k)
            {
                break;
            }
        }
    }
    return subarraysCount;
}
// ---------------------
int countSubarraysWithAtMostKDistinctElements(const vector<int> &nums, int k)
{
    int n = nums.size();
    int subarrayCount = 0;
    int start = 0;
    unordered_map<int, int> elementFrequency;
    // Edge Case: If k is negative, no valid subarray can exist
    if (k < 0)
    {
        return 0;
    }
    for (int end = 0; end < n; ++end)
    {
        // Add the current element to the window
        elementFrequency[nums[end]]++;
        // Shrink the window until the number of distinct elements is <= k
        while (elementFrequency.size() > k)
        {
            elementFrequency[nums[start]]--;
            if (elementFrequency[nums[start]] == 0)
            {
                elementFrequency.erase(nums[start]);
            }
            ++start;
        }
        // All subarrays ending at 'end' and starting from indices >= 'start' are valid
        subarrayCount += (end - start + 1);
    }
    return subarrayCount;
}
int subarraysWithKDistinct(const vector<int> &nums, int k)
{
    // Subarrays with exactly k distinct elements are:
    // Subarrays with at most k distinct elements
    // minus Subarrays with at most (k-1) distinct elements
    return countSubarraysWithAtMostKDistinctElements(nums, k) -
           countSubarraysWithAtMostKDistinctElements(nums, k - 1);
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {1, 2, 1, 2, 3};
//     cout << subarraysWithKDistinct(nums, 2);
//     cout << endl
//          << string(30, '-');
// }
// ---------------------------------------------------------------- 76. Minimum Window Substring -------------------------------------------------------------------------
// TLE
string minWindow(string s, string t)
{
    if (t.size() > s.size())
    {
        return "";
    }
    int n = s.size();
    string minSubstring = "";
    for (int i = 0; i < n; i++)
    {
        unordered_map<char, int> requiredFrequency;
        for (auto ch : t)
        {
            requiredFrequency[ch] += 1;
        }
        int isAllVisisted = false;
        string currentSubstring;
        for (int j = i; j < n; j++)
        {
            isAllVisisted = true;
            currentSubstring.push_back(s[j]);
            if (requiredFrequency.count(s[j]))
            {
                requiredFrequency[s[j]] -= 1;
                if (requiredFrequency[s[j]] < 0)
                {
                    requiredFrequency[s[j]] = 0;
                }
            }
            for (auto item : requiredFrequency)
            {
                if (item.second != 0)
                {
                    isAllVisisted = false;
                }
            }
            if (isAllVisisted)
            {
                break;
            }
        }
        if (isAllVisisted && (currentSubstring.size() < minSubstring.size() || minSubstring.size() == 0))
        {
            minSubstring = currentSubstring;
        }
    }
    return minSubstring;
}
// ----------- TLE -----------
string minWindow2(string s, string t)
{
    int n = s.size();
    int m = t.size();
    int minLen = INT_MAX;
    int startingIndex = -1;
    if (m > n)
    {
        return "";
    }
    for (int i = 0; i < n; i++)
    {
        unordered_map<char, int> frequency;
        int count = 0;
        for (auto ch : t)
        {
            frequency[ch] += 1;
        }
        for (int j = i; j < n; j++)
        {
            if (frequency[s[j]] > 0)
            {
                count += 1;
            }
            frequency[s[j]] -= 1;
            if (count == m)
            {
                if ((j - i) + 1 < minLen)
                {
                    minLen = (j - i) + 1;
                    startingIndex = i;
                    break;
                }
            }
        }
    }
    string minSubstring = (minLen == INT_MAX) ? "" : s.substr(startingIndex, minLen);
    return minSubstring;
}
// ----------- Sliding Window || Two pointer -----------
string minWindowSlidingWindow(string s, string t)
{
    if (t == "")
    {
        return "";
    }
    unordered_map<char, int> reqCount;
    unordered_map<char, int> window;
    for (int i = 0; i < t.size(); i++)
    {
        reqCount[t.at(i)] += 1;
    }
    int required = reqCount.size();
    int current = 0;
    int resLen = INT_MAX;
    int left = 0;
    vector<int> res = {-1, -1};
    for (int right = 0; right < s.size(); right++)
    {
        char c = s.at(right);
        if (reqCount[c])
            window[c] += 1;
        if (reqCount[c] && reqCount[c] == window[c])
            current += 1;
        while (current == required)
        {
            if (right - left + 1 < resLen)
            {
                resLen = right - left + 1;
                res = {left, right};
            }
            char c = s.at(left);
            if (reqCount[c] > 0)
                window[c] -= 1;
            if (reqCount[c] && window[c] < reqCount[c])
                current -= 1;
            left += 1;
        }
    }
    int leftIndex = res.at(0);
    return resLen != INT_MAX ? s.substr(leftIndex, resLen) : "";
}
int main()
{
    cout << string(30, '-') << endl;
    string s = "ddaaabbca", t = "abc";
    cout << minWindowSlidingWindow(s, t);
    cout << endl
         << string(30, '-');
}