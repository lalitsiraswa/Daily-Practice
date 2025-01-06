#include <bits/stdc++.h>
using namespace std;

bool divideArraysHelper(vector<int> &nums, int target, int index, vector<vector<int>> &dp)
{
    // Base:
    if (index == 0)
    {
        if (target == nums[0])
            return dp[index][target] = true;
        return dp[index][target] = false;
    }
    if (dp[index][target] != -1)
    {
        return dp[index][target];
    }
    // Take
    if (nums[index] <= target)
    {
        if (divideArraysHelper(nums, target - nums[index], index - 1, dp))
        {
            return dp[index][target] = true;
        }
    }
    // Not-Take
    if (divideArraysHelper(nums, target, index - 1, dp))
    {
        return dp[index][target] = true;
    }
    return dp[index][target] = false;
}

bool divideArrays(vector<int> &nums)
{
    int n = nums.size();
    int totalSum = 0;
    for (auto val : nums)
    {
        totalSum += val;
    }
    if (totalSum % 2 != 0)
    {
        return false;
    }
    int target = totalSum / 2;
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    return divideArraysHelper(nums, target, n - 1, dp);
}

int main()
{
    vector<int> nums = {1, 5, 11, 5};
    cout << divideArrays(nums);
    return 0;
}