#include <bits/stdc++.h>
using namespace std;
// ----------------------------------------------------------- 509. Fibonacci Number ------------------------------------------------
int fibRecursionMemo(int n, vector<int> &dp)
{
    if (n <= 1)
        return dp[n] = n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fibRecursionMemo(n - 1, dp) + fibRecursionMemo(n - 2, dp);
}
int fib(int n)
{
    vector<int> dp(n + 1, -1);
    fibRecursionMemo(n, dp);
    return dp[n];
}
// ----------------------------
int fibTabulation(int n)
{
    if (n == 0)
        return n;
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    for (int index = 2; index <= n; index++)
    {
        dp[index] = dp[index - 1] + dp[index - 2];
    }
    return dp[n];
}
// ---------------------------
int fibSpaceOptimization(int n)
{
    if (n <= 1)
        return n;
    int lastSecond = 0, lastFirst = 1, result = 0;
    for (int index = 2; index <= n; index++)
    {
        result = lastFirst + lastSecond;
        lastSecond = lastFirst;
        lastFirst = result;
    }
    return result;
}
// int main()
// {
//     cout << string(20, '-') << endl;
//     cout << fibSpaceOptimization(4);
//     cout << endl
//          << string(20, '-');
//     return 0;
// }
// --------------------------------------------------------------------- 70. Climbing Stairs -------------------------------------------------------------------------
int climbStairsMemoization(int n, vector<int> &dp)
{
    if (n == 0)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    int takeOneStep = climbStairsMemoization(n - 1, dp);
    int takeTwoStep = 0;
    if (n >= 2)
        takeTwoStep = climbStairsMemoization(n - 2, dp);
    return dp[n] = takeOneStep + takeTwoStep;
}
int climbStairs(int n)
{
    vector<int> dp(n + 1, -1);
    climbStairsMemoization(n, dp);
    return dp[n];
}
// -----------------------
int climbStairsTabulation(int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 1;
    for (int step = 1; step <= n; step++)
    {
        int takeOneStep = dp[step - 1];
        int takeTwoStep = 0;
        if (step >= 2)
            takeTwoStep = dp[step - 2];
        dp[step] = takeOneStep + takeTwoStep;
    }
    return dp[n];
}
// --------------------------
int climbStairsSpaceOptimization(int n)
{
    if (n <= 1)
        return n;
    int lastSecond = 1, lastFirst = 1, result = 0;
    for (int step = 2; step <= n; step++)
    {
        result = lastFirst + lastSecond;
        lastSecond = lastFirst;
        lastFirst = result;
    }
    return result;
}
// int main()
// {
//     cout << string(20, '-') << endl;
//     cout << climbStairsSpaceOptimization(3);
//     cout << endl
//          << string(20, '-');
//     return 0;
// }
// --------------------------------------------------------------------- 403. Frog Jump -------------------------------------------------------------------------
// Wrong Answer
bool canCrossHelper(int index, int jumps, vector<int> &stones, vector<vector<int>> &dp)
{
    if (index == stones.size() - 1)
        return true;
    if (dp[index][jumps] != -1)
        return dp[index][jumps];
    bool answer = false;
    for (int ind = index + 1; ind < stones.size(); ind++)
    {
        if (stones[ind] - stones[index] > jumps + 1)
            break;
        for (int jump = 0; jump < 2; jump++)
        {
            if (stones[ind] - stones[index] == jumps + jump)
            {
                answer = canCrossHelper(ind, jumps + jump, stones, dp) || answer;
            }
        }
    }
    return dp[index][jumps] = answer;
}
bool canCross(vector<int> &stones)
{
    if (stones[1] - stones[0] > 1)
        return false;
    if (stones.size() == 2)
        return (stones[1] - stones[0] == 1);
    int n = stones.size();
    vector<vector<int>> dp(2000, vector<int>(2000, -1));
    return canCrossHelper(0, 1, stones, dp);
}
// --------- Correct One ---------
bool canCrossHelper(int index, int jumps, vector<int> &stones, vector<vector<int>> &dp, unordered_map<int, int> &isPresent)
{
    if (index == stones.size() - 1)
        return true;
    if (dp[index][jumps] != -1)
        return dp[index][jumps];
    bool jumpZero = false;
    bool jumpMinusOne = false;
    bool jumpPlusOne = false;
    if (isPresent.find(stones[index] + jumps) != isPresent.end())
        jumpZero = canCrossHelper(isPresent[stones[index] + jumps], jumps, stones, dp, isPresent);
    if (jumps > 1 && isPresent.find(stones[index] + jumps - 1) != isPresent.end())
        jumpMinusOne = canCrossHelper(isPresent[stones[index] + jumps - 1], jumps - 1, stones, dp, isPresent);
    if (isPresent.find(stones[index] + jumps + 1) != isPresent.end())
        jumpPlusOne = canCrossHelper(isPresent[stones[index] + jumps + 1], jumps + 1, stones, dp, isPresent);
    return dp[index][jumps] = jumpZero || jumpMinusOne || jumpPlusOne;
}
bool canCrossPractice(vector<int> &stones)
{
    if (stones[1] - stones[0] != 1)
        return false;
    unordered_map<int, int> isPresent;
    vector<vector<int>> dp(2000, vector<int>(2000, -1));
    for (int index = 0; index < stones.size(); index++)
        isPresent[stones[index]] = index;
    return canCrossHelper(1, 1, stones, dp, isPresent);
}
// int main()
// {
//     cout << string(20, '-') << endl;
//     vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};
//     cout << canCrossPractice(stones);
//     cout << endl
//          << string(20, '-');
//     return 0;
// }
// ---------------------------------- DP 3. Frog Jump | Dynamic Programming | Learn to write 1D DP ----------------------------------------
int frogJumpTUF(vector<int> &heights, int index)
{
    if (index == heights.size() - 1)
        return 0;
    int takeOneStep = abs(heights[index + 1] - heights[index]) + frogJumpTUF(heights, index + 1);
    int takeTwoStep = INT_MAX;
    if (index < heights.size() - 2)
        takeTwoStep = abs(heights[index + 2] - heights[index]) + frogJumpTUF(heights, index + 2);
    return min(takeOneStep, takeTwoStep);
}
// ---------------

int frogJumpTUFMemoizationRecusion(vector<int> &heights, int index, vector<int> &dp)
{
    if (index == 0)
        return dp[index] = 0;
    if (dp[index] != -1)
        return dp[index];
    int takeOneStep = abs(heights[index - 1] - heights[index]) + frogJumpTUFMemoizationRecusion(heights, index - 1, dp);
    int takeTwoStep = INT_MAX;
    if (index > 1)
        takeTwoStep = abs(heights[index - 2] - heights[index]) + frogJumpTUFMemoizationRecusion(heights, index - 2, dp);
    return dp[index] = min(takeOneStep, takeTwoStep);
}
int frogJumpTUFMemoization(vector<int> &heights, int index)
{
    int n = heights.size();
    vector<int> dp(n, -1);
    frogJumpTUFMemoizationRecusion(heights, n - 1, dp);
    return dp[n - 1];
}
// -----------------
int frogJumpTUFTabulation(vector<int> &heights)
{
    int n = heights.size();
    vector<int> dp(n, -1);
    dp[0] = 0;
    for (int index = 1; index < n; index++)
    {
        int takeOneStep = abs(heights[index - 1] - heights[index]) + dp[index - 1];
        int takeTwoStep = INT_MAX;
        if (index > 1)
            takeTwoStep = abs(heights[index - 2] - heights[index]) + dp[index - 2];
        dp[index] = min(takeOneStep, takeTwoStep);
    }
    return dp[n - 1];
}
// ------------------------------
int frogJumpTUFSpaceOptimization(vector<int> &heights)
{
    int n = heights.size();
    int minEnergy = INT_MAX;
    int firstStep = 0;
    int secondStep = heights[1] - heights[0];
    for (int index = 2; index < n; index++)
    {

        int takeOneStep = abs(heights[index - 1] - heights[index]) + secondStep;
        int takeTwoStep = INT_MAX;
        takeTwoStep = abs(heights[index - 2] - heights[index]) + firstStep;
        minEnergy = min(takeOneStep, takeTwoStep);
        firstStep = secondStep;
        secondStep = minEnergy;
    }
    return minEnergy;
}
// int main()
// {
//     cout << string(20, '-') << endl;
//     vector<int> heights = {30, 10, 60, 10, 60, 50};
//     // cout << frogJumpTUFSpaceOptimization(heights, heights.size() - 1);
//     cout << frogJumpTUFTabulation(heights);
//     cout << endl
//          << string(20, '-');
//     return 0;
// }
// ------------------------------------------ TUF - DP 4. Frog Jump with K Distance | Lecture 3 Follow Up Question ----------------------------------------------
int frogJumpTUFWithKDistance(vector<int> &heights, int k, int index, vector<int> &dp)
{
    if (index == 0)
        return dp[index] = 0;
    if (dp[index] != -1)
        return dp[index];
    int minEnergy = INT_MAX;
    int currentEnergy = 0;
    for (int i = 1; i <= k; i++)
    {
        if (index - i >= 0)
        {
            currentEnergy = abs(heights[index] - heights[index - i]) + frogJumpTUFWithKDistance(heights, k, index - i, dp);
        }
        minEnergy = min(minEnergy, currentEnergy);
    }
    return dp[index] = minEnergy;
}
int frogJumpTUFWithKDistance(vector<int> &heights, int k)
{
    int n = heights.size();
    vector<int> dp(n, -1);
    frogJumpTUFWithKDistance(heights, k, n - 1, dp);
    return dp[n - 1];
}
// ---------------------------
int frogJumpTUFWithKDistanceTabulation(vector<int> &heights, int k)
{
    int n = heights.size();
    vector<int> dp(n, -1);
    dp[0] = 0;
    for (int index = 1; index < n; index++)
    {
        int minEnergy = INT_MAX;
        int currentEnergy = 0;
        for (int i = 1; i <= k; i++)
        {
            if (index - i >= 0)
            {
                currentEnergy = abs(heights[index] - heights[index - i]) + dp[index - i];
            }
            minEnergy = min(minEnergy, currentEnergy);
        }
        dp[index] = minEnergy;
    }
    return dp[n - 1];
}
// int main()
// {
//     cout << string(20, '-') << endl;
//     vector<int> heights = {30, 10, 60, 10, 60, 50};
//     // cout << frogJumpTUFSpaceOptimization(heights, heights.size() - 1);
//     cout << frogJumpTUFWithKDistanceTabulation(heights, 2);
//     cout << endl
//          << string(20, '-');
//     return 0;
// }
// --------------------------------------------------------------------- 198. House Robber -------------------------------------------------------------------------
int robRecursionMemoization(vector<int> &nums, int index, vector<int> &dp)
{
    if (index == 0)
        return dp[index] = nums[index];
    if (dp[index] != -1)
        return dp[index];
    int notTake = 0 + robRecursionMemoization(nums, index - 1, dp);
    int take = nums[index];
    if (index > 1)
        take += robRecursionMemoization(nums, index - 2, dp);
    return dp[index] = max(take, notTake);
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    robRecursionMemoization(nums, n - 1, dp);
    return dp[n - 1];
}
// ----------------------
int robTabulation(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    dp[0] = nums[0];
    for (int index = 1; index < n; index++)
    {
        int notTake = 0 + dp[index - 1];
        int take = nums[index];
        if (index > 1)
            take += dp[index - 2];
        dp[index] = max(take, notTake);
    }
    return dp[n - 1];
}
// --------------------
int robSpaceOptimization(vector<int> &nums)
{
    int n = nums.size();
    int maxRob = INT_MIN;
    int previousSecond = nums[0];
    int previousFirst = INT_MIN;
    if (n > 1)
        previousFirst = max(nums[0], nums[1]);
    maxRob = max(previousFirst, previousSecond);
    for (int index = 2; index < n; index++)
    {
        int notTake = 0 + previousFirst;
        int take = nums[index] + previousSecond;
        maxRob = max(take, notTake);
        previousSecond = previousFirst;
        previousFirst = maxRob;
    }
    return maxRob;
}
// ---------------------
int robSpaceOptimization2(vector<int> &nums)
{
    int n = nums.size();
    int maxRob = INT_MIN;
    int previousFirst = nums[0];
    int previousSecond = INT_MIN;
    maxRob = max(previousFirst, previousSecond);
    for (int index = 1; index < n; index++)
    {
        int notTake = 0 + previousFirst;
        int take = nums[index];
        if (index > 1)
            take += previousSecond;
        maxRob = max(take, notTake);
        previousSecond = previousFirst;
        previousFirst = maxRob;
    }
    return maxRob;
}
// int main()
// {
//     cout << string(20, '-') << endl;
//     vector<int> nums = {2, 7, 9, 3, 1};
//     cout << robSpaceOptimization2(nums);
//     cout << endl
//          << string(20, '-');
//     return 0;
// }
// --------------------------------------------------------------------- 213. House Robber II -------------------------------------------------------------------------
int houseRobberSpaceOptimization(vector<int> nums)
{
    int n = nums.size();
    int maxRob = INT_MIN;
    int previousFirst = nums[0];
    int previousSecond = INT_MIN;
    maxRob = max(previousFirst, previousSecond);
    for (int index = 1; index < n; index++)
    {
        int notTake = 0 + previousFirst;
        int take = nums[index];
        if (index > 1)
            take += previousSecond;
        maxRob = max(take, notTake);
        previousSecond = previousFirst;
        previousFirst = maxRob;
    }
    return maxRob;
}
int rob2(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    vector<int> includeFirstElement(nums.begin(), nums.end() - 1);
    vector<int> excludeFirstElement(nums.begin() + 1, nums.end());
    // Then Same As the 198. House Robber
    int includeElementFirst = houseRobberSpaceOptimization(includeFirstElement);
    int excludeElementFirst = houseRobberSpaceOptimization(excludeFirstElement);
    return max(includeElementFirst, excludeElementFirst);
}
int main()
{
    cout << string(20, '-') << endl;
    vector<int> nums = {2, 3, 2};
    cout << rob2(nums);
    cout << endl
         << string(20, '-');
    return 0;
}