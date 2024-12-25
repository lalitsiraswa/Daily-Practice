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
int main()
{
    cout << string(30, '-') << endl;
    string s = "pwwkew";
    cout << lengthOfLongestSubstringTuf(s);
    cout << endl
         << string(30, '-');
}