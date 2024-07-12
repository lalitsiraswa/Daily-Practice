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
// ------------------
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
    if (isPresent.find(stones[index] + jumps - 1) != isPresent.end())
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
int main()
{
    cout << string(20, '-') << endl;
    vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};
    cout << canCrossPractice(stones);
    cout << endl
         << string(20, '-');
    return 0;
}