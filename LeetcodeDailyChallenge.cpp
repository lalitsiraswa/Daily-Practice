#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------------------------ Longest Subarray with Sum K ---------------------------------------------------------------------------
int longestSubarray(vector<int> &arr, int k)
{
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }
        long long remaining = sum - k;
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
//     vector<int> arr = {10, 5, 2, 7, 1, -10};
//     cout << longestSubarray(arr, 15);
//     cout << endl
//          << string(30, '-') << endl;
//     return 1;
// }
// ------------------------------------------------------------------------------ 560. Subarray Sum Equals K ---------------------------------------------------------------------------
int subarraySum(vector<int> &nums, int k)
{
    map<long long, int> preSumMap;
    int sum = 0;
    int subarrayCount = 0;
    for (int index = 0; index < nums.size(); index++)
    {
        sum += nums[index];
        if (sum == k)
            subarrayCount++;
        int remaining = sum - k;
        if (preSumMap.find(remaining) != preSumMap.end())
            subarrayCount += preSumMap[remaining];
        preSumMap[sum] = preSumMap[sum] + 1;
    }
    return subarrayCount;
}
int main()
{
    cout << string(30, '-') << endl;
    vector<int> nums = {1, 2, 3};
    cout << subarraySum(nums, 3);
    cout << endl
         << string(30, '-') << endl;
    return 1;
}