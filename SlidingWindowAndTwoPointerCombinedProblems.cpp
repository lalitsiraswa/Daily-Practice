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
int main()
{
    cout << string(30, '-') << endl;
    vector<int> nums = {1, 1, 5, 6, 7, 8, 9};
    cout << totalFruitsTufSlidingWindow2(nums);
    cout << endl
         << string(30, '-');
}