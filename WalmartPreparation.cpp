#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/explore?page=1&company=Walmart&sortBy=submissions&itm_source=geeksforgeeks&itm_medium=main_header&itm_campaign=practice_header
// ------------------------------------------------------------------------ Kadane's Algorithm ------------------------------------------------------------------------------
int maxSubarraySum(vector<int> &arr)
{
    int maxSum = arr[0];
    int currentSum = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        currentSum = max(currentSum + arr[i], arr[i]);
        maxSum = max(currentSum, maxSum);
    }
    return maxSum;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
//     cout << maxSubarraySum(arr) << endl;
//     cout << endl
//          << string(30, '-') << endl;
//     return 1;
// }
// ------------------------------------------------------------------------ Minimum Jumps ------------------------------------------------------------------------------
// --------------- TLE -------------------
int minJumps(vector<int> &arr, int index, vector<int> &dp)
{
    if (index >= arr.size() - 1)
    {
        return 0;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }
    int minJumpsCount = INT_MAX;
    int currJumpCount = 0;
    for (int i = 1; i <= arr[index]; i++)
    {

        currJumpCount = 1 + minJumps(arr, index + i, dp);
        if (currJumpCount > 0)
            minJumpsCount = min(minJumpsCount, currJumpCount);
    }
    return dp[index] = (minJumpsCount == INT_MAX) ? -2 : minJumpsCount;
}
int minJumps(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, -1);
    minJumps(arr, 0, dp);
    return dp[0] == -2 ? -1 : dp[0];
}
// --------------- TLE ----------------
int minJumpsTabulation(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, -1);
    dp[n - 1] = 0;
    for (int index = n - 2; index >= 0; index--)
    {
        int minJumpsCount = INT_MAX;
        int currJumpCount = 0;
        for (int i = 1; i <= arr[index] && i < n; i++)
        {

            currJumpCount = 1 + dp[index + i];
            if (currJumpCount > 0)
                minJumpsCount = min(minJumpsCount, currJumpCount);
        }
        dp[index] = (minJumpsCount == INT_MAX) ? -2 : minJumpsCount;
    }
    return dp[0] == -2 ? -1 : dp[0];
}
// --------------- GREEDY ALGORITMS  ----------------
int minJumpsGreedy(vector<int> &arr)
{
    int n = arr.size();
    int minJumps = 0;
    int currentEnd = 0;
    int currentFarthest = 0;
    for (int index = 0; index < arr.size() - 1; index++)
    {
        currentFarthest = max(currentFarthest, index + arr[index]);
        if (index == currentEnd)
        {
            minJumps += 1;
            currentEnd = currentFarthest;
        }
        if (currentEnd > n - 1)
        {
            break;
        }
    }
    if (currentEnd < n - 1)
    {
        return -1;
    }
    return minJumps;
}
int main()
{
    cout << string(30, '-') << endl;
    vector<int> arr = {2, 3, 1, 1, 4};
    cout << minJumpsGreedy(arr) << endl;
    cout << endl
         << string(30, '-') << endl;
    return 1;
}