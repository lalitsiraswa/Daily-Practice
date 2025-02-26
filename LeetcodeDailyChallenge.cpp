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
int main()
{
    cout << string(30, '-') << endl;
    vector<int> arr = {10, 5, 2, 7, 1, -10};
    cout << longestSubarray(arr, 15);
    cout << endl
         << string(30, '-') << endl;
    return 1;
}