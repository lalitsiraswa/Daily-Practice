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
int main()
{
    cout << string(30, '-') << endl;
    vector<int> nums = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    cout << subarraySumTUF(nums, 3);
    cout << endl
         << string(30, '-');
}