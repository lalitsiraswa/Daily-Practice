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
// int main()
// {
//     cout << string(20, '-') << endl;
//     vector<int> nums = {2, 3, 2};
//     cout << rob2(nums);
//     cout << endl
//          << string(20, '-');
//     return 0;
// }
// --------------------------------------------------------------------- TUF : DP 7. Ninja's Training -------------------------------------------------------------------------
// Recursive function to calculate the maximum points for the ninja training
int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    // Base case: When we reach the first day (day == 0)
    if (day == 0)
    {
        int maxi = 0;
        // Calculate the maximum points for the first day by choosing an activity
        // different from the last one
        for (int i = 0; i <= 2; i++)
        {
            if (i != last)
                maxi = max(maxi, points[0][i]);
        }
        // Store the result in dp array and return it
        return dp[day][last] = maxi;
    }
    // If the result for this day and last activity is already calculated, return it
    if (dp[day][last] != -1)
        return dp[day][last];
    int maxi = 0;
    // Iterate through the activities for the current day
    for (int i = 0; i <= 2; i++)
    {
        if (i != last)
        {
            // Calculate the points for the current activity and add it to the
            // maximum points obtained so far (recursively calculated)
            int activity = points[day][i] + f(day - 1, i, points, dp);
            maxi = max(maxi, activity);
        }
    }
    // Store the result in dp array and return it
    return dp[day][last] = maxi;
}

// Function to find the maximum points for ninja training
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Create a memoization table (dp) to store intermediate results
    vector<vector<int>> dp(n, vector<int>(4, -1));
    // Start the recursive calculation from the last day with no previous activity
    return f(n - 1, 3, points, dp);
}
// ---------------------
// Function to find the maximum points for ninja training
int ninjaTrainingTabulation(int n, vector<vector<int>> &points)
{
    // Create a 2D DP (Dynamic Programming) table to store the maximum points
    // dp[i][j] represents the maximum points at day i, considering the last activity as j
    vector<vector<int>> dp(n, vector<int>(4, 0));
    // Initialize the DP table for the first day (day 0)
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
    // Iterate through the days starting from day 1
    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            // Iterate through the tasks for the current day
            for (int task = 0; task <= 2; task++)
            {
                if (task != last)
                {
                    // Calculate the points for the current activity and add it to the
                    // maximum points obtained on the previous day (recursively calculated)
                    int activity = points[day][task] + dp[day - 1][task];
                    // Update the maximum points for the current day and last activity
                    dp[day][last] = max(dp[day][last], activity);
                }
            }
        }
    }
    // The maximum points for the last day with any activity can be found in dp[n-1][3]
    return dp[n - 1][3];
}
// -----------------
// Function to find the maximum points for ninja training
int ninjaTrainingSpaceOptimization(int n, vector<vector<int>> &points)
{
    // Initialize a vector to store the maximum points for the previous day's activities
    vector<int> prev(4, 0);

    // Initialize the DP table for the first day (day 0)
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    // Iterate through the days starting from day 1
    for (int day = 1; day < n; day++)
    {
        // Create a temporary vector to store the maximum points for the current day's activities
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++)
        {
            temp[last] = 0;
            // Iterate through the tasks for the current day
            for (int task = 0; task <= 2; task++)
            {
                if (task != last)
                {
                    // Calculate the points for the current activity and add it to the
                    // maximum points obtained on the previous day (stored in prev)
                    temp[last] = max(temp[last], points[day][task] + prev[task]);
                }
            }
        }
        // Update prev with the maximum points for the current day
        prev = temp;
    }

    // The maximum points for the last day with any activity can be found in prev[3]
    return prev[3];
}
// int main()
// {
//     cout << string(20, '-') << endl;
//     vector<vector<int>> points = {{2, 1, 3}, {3, 4, 6}, {10, 1, 6}, {8, 3, 7}};
//     cout << ninjaTrainingSpaceOptimization(points.size(), points);
//     cout << endl
//          << string(20, '-');
//     return 0;
// }
// --------------------------------------------------------------------- 62. Unique Paths -------------------------------------------------------------------------
int uniquePathsMemoization(int row, int column, int &m, int &n, vector<vector<int>> &dp)
{
    if (row == m - 1 && column == n - 1)
        return dp[row][column] = 1;
    if (dp[row][column] != -1)
        return dp[row][column];
    int moveDown = 0;
    int moveRight = 0;
    if (row < m - 1)
        moveDown = uniquePathsMemoization(row + 1, column, m, n, dp);
    if (column < n - 1)
        moveRight = uniquePathsMemoization(row, column + 1, m, n, dp);
    return dp[row][column] = (moveDown + moveRight);
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return uniquePathsMemoization(0, 0, m, n, dp);
}
// -------------------------
int uniquePathsTabulation(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    dp[m - 1][n - 1] = 1;
    for (int row = m - 1; row >= 0; row--)
    {
        for (int column = n - 1; column >= 0; column--)
        {
            if (row == (m - 1) && column == (n - 1))
                continue;
            int moveDown = 0;
            int moveRight = 0;
            if (row < m - 1)
                moveDown = dp[row + 1][column];
            if (column < n - 1)
                moveRight = dp[row][column + 1];
            dp[row][column] = (moveDown + moveRight);
        }
    }
    return dp[0][0];
}
// --------------------
int uniquePathsTabulationModified(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for (int column = 0; column < n; column++)
        dp[m - 1][column] = 1;
    for (int row = m - 2; row >= 0; row--)
    {
        for (int column = n - 1; column >= 0; column--)
        {
            int moveDown = 0;
            int moveRight = 0;
            if (row < m - 1)
                moveDown = dp[row + 1][column];
            if (column < n - 1)
                moveRight = dp[row][column + 1];
            dp[row][column] = (moveDown + moveRight);
        }
    }
    return dp[0][0];
}
// --------------------------
int uniquePathsSpaceOptimization(int m, int n)
{
    vector<int> lastStoredData(n, -1);
    for (int column = 0; column < n; column++)
        lastStoredData[column] = 1;
    for (int row = m - 2; row >= 0; row--)
    {
        vector<int> tempData(n, -1);
        for (int column = n - 1; column >= 0; column--)
        {
            int moveDown = 0;
            int moveRight = 0;
            if (row < m - 1)
                moveDown = lastStoredData[column];
            if (column < n - 1)
                moveRight = tempData[column + 1];
            tempData[column] = (moveDown + moveRight);
        }
        lastStoredData = tempData;
    }
    return lastStoredData[0];
}
// --------------------------
int countWaysUtil(int row, int column, vector<vector<int>> &dp)
{
    if (row == 0 && column == 0)
        return dp[row][column] = 1;
    if (dp[row][column] != -1)
        return dp[row][column];
    int moveUp = 0;
    int moveLeft = 0;
    if (row > 0)
        moveUp = countWaysUtil(row - 1, column, dp);
    if (column > 0)
        moveLeft = countWaysUtil(row, column - 1, dp);
    return dp[row][column] = (moveUp + moveLeft);
}
int countWays(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return countWaysUtil(m - 1, n - 1, dp);
}
// ----------------------------
int countWaysTabulation(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    dp[0][0] = 1;
    for (int row = 0; row < m; row++)
    {
        for (int column = 0; column < n; column++)
        {
            if (row == 0 && column == 0)
                continue;
            int moveUp = 0;
            int moveLeft = 0;
            if (row > 0)
                moveUp = dp[row - 1][column];
            if (column > 0)
                moveLeft = dp[row][column - 1];
            dp[row][column] = (moveUp + moveLeft);
        }
    }
    return dp[m - 1][n - 1];
}
// ------------------------
int countWaysSpaceOptimization(int m, int n)
{
    vector<int> previousDataStore(n);
    previousDataStore[0] = 1;
    vector<int> tempDataStore(n);
    for (int row = 0; row < m; row++)
    {
        for (int column = 0; column < n; column++)
        {
            if (row == 0 && column == 0)
                continue;
            int moveUp = 0;
            int moveLeft = 0;
            if (row > 0)
                moveUp = tempDataStore[column];
            if (column > 0)
                moveLeft = previousDataStore[column - 1];
            previousDataStore[column] = (moveUp + moveLeft);
        }
        tempDataStore = previousDataStore;
    }
    return previousDataStore[n - 1];
}
// int main()
// {
//     cout << string(20, '-') << endl;
//     int m = 3, n = 2;
//     cout << countWaysSpaceOptimization(m, n);
//     cout << endl
//          << string(20, '-');
//     return 0;
// }
// --------------------------------------------------------------------- 63. Unique Paths II -------------------------------------------------------------------------
int uniquePathsWithObstaclesMemoization(vector<vector<int>> &obstacleGrid, int row, int column, vector<vector<int>> &dp)
{
    if (row == 0 && column == 0)
        return dp[row][column] = 1;
    if (dp[row][column] != -1)
        return dp[row][column];
    int moveUp = 0;
    int moveLeft = 0;
    if (row > 0 && obstacleGrid[row - 1][column] != 1)
        moveUp = uniquePathsWithObstaclesMemoization(obstacleGrid, row - 1, column, dp);
    if (column > 0 && obstacleGrid[row][column - 1] != 1)
        moveLeft = uniquePathsWithObstaclesMemoization(obstacleGrid, row, column - 1, dp);
    return dp[row][column] = (moveUp + moveLeft);
}
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int row = obstacleGrid.size();
    int column = obstacleGrid[0].size();
    vector<vector<int>> dp(row, vector<int>(column, -1));
    if (obstacleGrid[row - 1][column - 1] != 1)
        return uniquePathsWithObstaclesMemoization(obstacleGrid, row - 1, column - 1, dp);
    return 0;
}
// ------------------------------------
int uniquePathsWithObstaclesTabulation(vector<vector<int>> &obstacleGrid)
{
    int rowCount = obstacleGrid.size();
    int columnCount = obstacleGrid[0].size();
    if (obstacleGrid[rowCount - 1][columnCount - 1] == 1 || obstacleGrid[0][0] == 1)
        return 0;
    vector<vector<int>> dp(rowCount, vector<int>(columnCount, -1));
    dp[0][0] = 1;
    for (int row = 0; row < rowCount; row++)
    {
        for (int column = 0; column < columnCount; column++)
        {
            if (row == 0 && column == 0)
                continue;
            int moveUp = 0;
            int moveLeft = 0;
            if (row > 0 && obstacleGrid[row - 1][column] != 1)
                moveUp = dp[row - 1][column];
            if (column > 0 && obstacleGrid[row][column - 1] != 1)
                moveLeft = dp[row][column - 1];
            dp[row][column] = (moveUp + moveLeft);
        }
    }
    return dp[rowCount - 1][columnCount - 1];
}
// -----------------------
int uniquePathsWithObstaclesSpaceOptimization(vector<vector<int>> &obstacleGrid)
{
    int rowCount = obstacleGrid.size();
    int columnCount = obstacleGrid[0].size();
    if (obstacleGrid[rowCount - 1][columnCount - 1] == 1 || obstacleGrid[0][0] == 1)
        return 0;
    vector<int> previousDataStore(columnCount, -1);
    previousDataStore[0] = 1;
    vector<int> tempDataStore(columnCount, -1);
    for (int row = 0; row < rowCount; row++)
    {
        for (int column = 0; column < columnCount; column++)
        {
            if (row == 0 && column == 0)
                continue;
            int moveUp = 0;
            int moveLeft = 0;
            if (row > 0 && obstacleGrid[row - 1][column] != 1)
                moveUp = tempDataStore[column];
            if (column > 0 && obstacleGrid[row][column - 1] != 1)
                moveLeft = previousDataStore[column - 1];
            previousDataStore[column] = (moveUp + moveLeft);
        }
        tempDataStore = previousDataStore;
    }
    return previousDataStore[columnCount - 1];
}
// int main()
// {
//     cout << string(20, '-') << endl;
//     vector<vector<int>> obstacleGrid = {{0, 1}, {0, 0}};
//     cout << uniquePathsWithObstaclesSpaceOptimization(obstacleGrid);
//     cout << endl
//          << string(20, '-');
//     return 0;
// }
// --------------------------------------------------------------------- 64. Minimum Path Sum -------------------------------------------------------------------------
int minPathSumMemoization(vector<vector<int>> &grid, int row, int column, vector<vector<int>> &dp)
{
    if (row == 0 && column == 0)
        return dp[row][column] = grid[row][column];
    if (dp[row][column] != -1)
        return dp[row][column];
    int moveUp = 1e9;
    int moveLeft = 1e9;
    if (row > 0)
        moveUp = grid[row][column] + minPathSumMemoization(grid, row - 1, column, dp);
    if (column > 0)
        moveLeft = grid[row][column] + minPathSumMemoization(grid, row, column - 1, dp);
    return dp[row][column] = min(moveUp, moveLeft);
}
int minPathSum(vector<vector<int>> &grid)
{
    int rowCount = grid.size();
    int columnCount = grid[0].size();
    vector<vector<int>> dp(rowCount, vector<int>(columnCount, -1));
    return minPathSumMemoization(grid, rowCount - 1, columnCount - 1, dp);
}
// ----------------------
int minPathSumTabulation(vector<vector<int>> &grid)
{
    int rowCount = grid.size();
    int columnCount = grid[0].size();
    vector<vector<int>> dp(rowCount, vector<int>(columnCount, -1));
    dp[0][0] = grid[0][0];
    for (int row = 0; row < rowCount; row++)
    {
        for (int column = 0; column < columnCount; column++)
        {
            if (row == 0 && column == 0)
                continue;
            int moveUp = 1e9;
            int moveLeft = 1e9;
            if (row > 0)
                moveUp = grid[row][column] + dp[row - 1][column];
            if (column > 0)
                moveLeft = grid[row][column] + dp[row][column - 1];
            dp[row][column] = min(moveUp, moveLeft);
        }
    }
    return dp[rowCount - 1][columnCount - 1];
}
// --------------------
int minPathSumSpaceOptimization(vector<vector<int>> &grid)
{
    int rowCount = grid.size();
    int columnCount = grid[0].size();
    vector<int> previousDataStore(columnCount, -1);
    previousDataStore[0] = grid[0][0];
    vector<int> tempDataStore(columnCount, -1);
    for (int row = 0; row < rowCount; row++)
    {
        for (int column = 0; column < columnCount; column++)
        {
            if (row == 0 && column == 0)
                continue;
            int moveUp = 1e9;
            int moveLeft = 1e9;
            if (row > 0)
                moveUp = grid[row][column] + tempDataStore[column];
            if (column > 0)
                moveLeft = grid[row][column] + previousDataStore[column - 1];
            previousDataStore[column] = min(moveUp, moveLeft);
        }
        tempDataStore = previousDataStore;
    }
    return previousDataStore[columnCount - 1];
}
// int main()
// {
//     cout << string(20, '-') << endl;
//     vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
//     cout << minPathSumSpaceOptimization(grid);
//     cout << endl
//          << string(20, '-');
//     return 0;
// }
// --------------------------------------------------------------------- 120. Triangle -------------------------------------------------------------------------
int minimumTotalRecursion(vector<vector<int>> &triangle, int row, int column, vector<vector<int>> &dp)
{
    if (row == 0 && column == 0)
        return dp[row][column] = triangle[row][column];
    if (dp[row][column] != -1)
        return dp[row][column];
    int moveUp = 1e9;
    int moveLeft = 1e9;
    if (row > 0)
    {
        if (row != column)
            moveUp = triangle[row][column] + minimumTotalRecursion(triangle, row - 1, column, dp);
        if (column > 0)
            moveLeft = triangle[row][column] + minimumTotalRecursion(triangle, row - 1, column - 1, dp);
    }
    return dp[row][column] = min(moveUp, moveLeft);
}
int minimumTotal(vector<vector<int>> &triangle)
{
    int m = triangle.size();
    int n = triangle[m - 1].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int minimumTotal = INT_MAX;
    for (int column = n - 1; column >= 0; column--)
    {
        int currentTotal = minimumTotalRecursion(triangle, m - 1, column, dp);
        minimumTotal = min(minimumTotal, currentTotal);
        dp[m - 1][column] = minimumTotal;
    }
    return minimumTotal;
}
// --------------------
int minimumTotalTabulation(vector<vector<int>> &triangle)
{
    int m = triangle.size();
    int n = triangle[m - 1].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    dp[0][0] = triangle[0][0];
    int minimumTotal = INT_MAX;
    for (int column = 0; column < n; column++)
    {
        int currentTotal = 1e9;
        for (int row = 0; row < column; row++)
        {
            for (int col = 0; col <= column; col++)
            {
                if (row == 0 && col == 0)
                    continue;
                int moveUp = 1e9;
                int moveLeft = 1e9;
                if (row > 0)
                {
                    if (row != column)
                        moveUp = triangle[row][column] + dp[row - 1][column];
                    if (column > 0)
                        moveLeft = triangle[row][column] + dp[row - 1][column - 1];
                }
                dp[row][col] = min(moveUp, moveLeft);
                currentTotal = min(currentTotal, dp[row][col]);
            }
        }
        minimumTotal = min(minimumTotal, currentTotal);
        dp[m - 1][column] = minimumTotal;
    }
    return minimumTotal;
}
// -------------------- Preferred Ways 'Move from (0, 0)' ---------------
int minimumTotalMemoizationWay(vector<vector<int>> &triangle, int &m, int &n, int row, int column, vector<vector<int>> &dp)
{
    if (row == m - 1)
        return dp[row][column] = triangle[row][column];
    if (dp[row][column] != -1)
        return dp[row][column];
    int moveDown = INT_MAX;
    int moveRight = INT_MAX;
    if (row < m - 1)
    {
        moveDown = triangle[row][column] + minimumTotalMemoizationWay(triangle, m, n, row + 1, column, dp);
        if (column < n - 1)
            moveRight = triangle[row][column] + minimumTotalMemoizationWay(triangle, m, n, row + 1, column + 1, dp);
    }
    return dp[row][column] = min(moveDown, moveRight);
}
int minimumTotalPreferWay(vector<vector<int>> &triangle)
{
    int m = triangle.size();
    int n = triangle[m - 1].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return minimumTotalMemoizationWay(triangle, m, n, 0, 0, dp);
}
// ------------------
int minimumTotalTabulationWay(vector<vector<int>> &triangle)
{
    int m = triangle.size();
    int n = triangle[m - 1].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for (int column = 0; column < n; column++)
        dp[m - 1][column] = triangle[m - 1][column];
    for (int row = m - 2; row >= 0; row--)
    {
        for (int column = 0; column <= row; column++)
        {
            int moveDown = INT_MAX;
            int moveRight = INT_MAX;
            if (row < m - 1)
            {
                moveDown = triangle[row][column] + dp[row + 1][column];
                if (column < n - 1)
                    moveRight = triangle[row][column] + dp[row + 1][column + 1];
            }
            dp[row][column] = min(moveDown, moveRight);
        }
    }
    return dp[0][0];
}
// --------------
int minimumTotalSpaceOptimizationWay(vector<vector<int>> &triangle)
{
    int m = triangle.size();
    int n = triangle[m - 1].size();
    vector<int> previousDataStore(n, -1);
    for (int column = 0; column < n; column++)
        previousDataStore[column] = triangle[m - 1][column];
    for (int row = m - 2; row >= 0; row--)
    {
        vector<int> currentDataStore(n, -1);
        for (int column = 0; column <= row; column++)
        {
            int moveDown = INT_MAX;
            int moveRight = INT_MAX;
            if (row < m - 1)
            {
                moveDown = triangle[row][column] + previousDataStore[column];
                if (column < n - 1)
                    moveRight = triangle[row][column] + previousDataStore[column + 1];
            }
            currentDataStore[column] = min(moveDown, moveRight);
        }
        previousDataStore = currentDataStore;
    }
    return previousDataStore[0];
}
// int main()
// {
//     cout << string(20, '-') << endl;
//     vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
//     // vector<vector<int>> triangle = {{-10}};
//     cout << minimumTotalSpaceOptimizationWay(triangle);
//     cout << endl
//          << string(20, '-');
//     return 0;
// }
// --------------------------------------------------------------------- 931. Minimum/Maximum Falling Path Sum -------------------------------------------------------------------------
// ----------------- MEMOIZATION 'TLE' -------------------
int minFallingPathSumMemoization(vector<vector<int>> &matrix, int row, int column, int &size, vector<vector<int>> &dp)
{
    if (row == 0)
        return dp[row][column] = matrix[row][column];
    if (dp[row][column] != -1)
        return dp[row][column];
    int moveUp = matrix[row][column] + minFallingPathSumMemoization(matrix, row - 1, column, size, dp);
    int moveDiagonalLeft = INT_MAX;
    int moveDiagonalRight = INT_MAX;
    if (column > 0)
        moveDiagonalLeft = matrix[row][column] + minFallingPathSumMemoization(matrix, row - 1, column - 1, size, dp);
    if (column < size - 1)
        moveDiagonalRight = matrix[row][column] + minFallingPathSumMemoization(matrix, row - 1, column + 1, size, dp);
    return dp[row][column] = min(moveUp, min(moveDiagonalLeft, moveDiagonalRight));
}
int minFallingPathSum(vector<vector<int>> &matrix)
{
    int size = matrix.size();
    vector<vector<int>> dp(size, vector<int>(size, -1));
    int minFallingPath = INT_MAX;
    for (int column = 0; column < size; column++)
    {
        int currentFallingPath = minFallingPathSumMemoization(matrix, size - 1, column, size, dp);
        dp[size - 1][column] = currentFallingPath;
        minFallingPath = min(currentFallingPath, minFallingPath);
    }
    return minFallingPath;
}
// -------------------------
int minFallingPathSumTabulation(vector<vector<int>> &matrix)
{
    int size = matrix.size();
    vector<vector<int>> dp(size, vector<int>(size, -1));
    int minFallingPath = 1e9;
    for (int column = 0; column < size; column++)
    {
        dp[0][column] = matrix[0][column];
        minFallingPath = min(minFallingPath, dp[0][column]);
    }
    for (int row = 1; row < size; row++)
    {
        minFallingPath = 1e9;
        for (int column = 0; column < size; column++)
        {
            int moveUp = matrix[row][column] + dp[row - 1][column];
            int moveDiagonalLeft = 1e9;
            int moveDiagonalRight = 1e9;
            if (column > 0)
                moveDiagonalLeft = matrix[row][column] + dp[row - 1][column - 1];
            if (column < size - 1)
                moveDiagonalRight = matrix[row][column] + dp[row - 1][column + 1];
            dp[row][column] = min(moveUp, min(moveDiagonalLeft, moveDiagonalRight));
            minFallingPath = min(minFallingPath, dp[row][column]);
        }
    }
    return minFallingPath;
}
// -------------------
int minFallingPathSumTabulationOtherWay(vector<vector<int>> &matrix)
{
    int size = matrix.size();
    vector<vector<int>> dp(size, vector<int>(size, -1));
    int minFallingPath = 1e9;
    for (int column = 0; column < size; column++)
        dp[0][column] = matrix[0][column];
    for (int row = 1; row < size; row++)
    {
        for (int column = 0; column < size; column++)
        {
            int moveUp = matrix[row][column] + dp[row - 1][column];
            int moveDiagonalLeft = 1e9;
            int moveDiagonalRight = 1e9;
            if (column > 0)
                moveDiagonalLeft = matrix[row][column] + dp[row - 1][column - 1];
            if (column < size - 1)
                moveDiagonalRight = matrix[row][column] + dp[row - 1][column + 1];
            dp[row][column] = min(moveUp, min(moveDiagonalLeft, moveDiagonalRight));
        }
    }
    for (int column = 0; column < size; column++)
        minFallingPath = min(minFallingPath, dp[size - 1][column]);
    return minFallingPath;
}
// -------------------
int minFallingPathSumSpaceOptimization(vector<vector<int>> &matrix)
{
    int size = matrix.size();
    vector<int> previousDataStore(size, -1);
    int minFallingPath = 1e9;
    for (int column = 0; column < size; column++)
    {
        previousDataStore[column] = matrix[0][column];
        minFallingPath = min(minFallingPath, previousDataStore[column]);
    }
    for (int row = 1; row < size; row++)
    {
        vector<int> currentDataStore(size, -1);
        minFallingPath = 1e9;
        for (int column = 0; column < size; column++)
        {
            int moveUp = matrix[row][column] + previousDataStore[column];
            int moveDiagonalLeft = 1e9;
            int moveDiagonalRight = 1e9;
            if (column > 0)
                moveDiagonalLeft = matrix[row][column] + previousDataStore[column - 1];
            if (column < size - 1)
                moveDiagonalRight = matrix[row][column] + previousDataStore[column + 1];
            currentDataStore[column] = min(moveUp, min(moveDiagonalLeft, moveDiagonalRight));
            minFallingPath = min(minFallingPath, currentDataStore[column]);
        }
        previousDataStore = currentDataStore;
    }
    return minFallingPath;
}
// -----------------
int minFallingPathSumSpaceOptimizationOtherWay(vector<vector<int>> &matrix)
{
    int size = matrix.size();
    vector<int> previousDataStore(size, -1);
    int minFallingPath = 1e9;
    for (int column = 0; column < size; column++)
        previousDataStore[column] = matrix[0][column];
    for (int row = 1; row < size; row++)
    {
        vector<int> currentDataStore(size, -1);
        minFallingPath = 1e9;
        for (int column = 0; column < size; column++)
        {
            int moveUp = matrix[row][column] + previousDataStore[column];
            int moveDiagonalLeft = 1e9;
            int moveDiagonalRight = 1e9;
            if (column > 0)
                moveDiagonalLeft = matrix[row][column] + previousDataStore[column - 1];
            if (column < size - 1)
                moveDiagonalRight = matrix[row][column] + previousDataStore[column + 1];
            currentDataStore[column] = min(moveUp, min(moveDiagonalLeft, moveDiagonalRight));
        }
        previousDataStore = currentDataStore;
    }
    for (int column = 0; column < size; column++)
        minFallingPath = min(minFallingPath, previousDataStore[column]);
    return minFallingPath;
}
// int main()
// {
//     cout << string(20, '-') << endl;
//     vector<vector<int>> matrix = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
//     cout << minFallingPathSumSpaceOptimizationOtherWay(matrix);
//     cout << endl
//          << string(20, '-');
//     return 0;
// }
// --------------------------------------------------------------------- 741. Cherry Pickup 'Wrong Code' -------------------------------------------------------------------------
int cherryPickupMemoization2(vector<vector<int>> &grid, int row, int column, int &size, vector<vector<int>> &dp)
{
    if (row == 0 && column == 0)
        return dp[row][column] = grid[row][column];
    if (dp[row][column] != -1)
        return dp[row][column];
    int moveUp = 0;
    int moveLeft = 0;
    if (row > 0 && grid[row - 1][column] != -1)
    {
        int temp = grid[row][column];
        grid[row][column] = 0;
        moveUp = temp + cherryPickupMemoization2(grid, row - 1, column, size, dp);
        grid[row][column] = temp;
    }
    if (column > 0 && grid[row][column - 1] != -1)
    {
        int temp = grid[row][column];
        grid[row][column] = 0;
        moveLeft = temp + cherryPickupMemoization2(grid, row, column - 1, size, dp);
        grid[row][column] = temp;
    }
    return dp[row][column] = max(moveUp, moveLeft);
}
int cherryPickupMemoization1(vector<vector<int>> &grid, int row, int column, int &size, vector<vector<int>> &dp)
{
    if (row == size - 1 && column == size - 1)
    {
        int temp = grid[row][column];
        grid[row][column] = 0;
        vector<vector<int>> dp2(size, vector<int>(size, -1));
        int result = temp + cherryPickupMemoization2(grid, row, column, size, dp);
        grid[row][column] = temp;
        return dp[row][column] = result;
    }
    if (dp[row][column] != -1)
        return dp[row][column];
    int moveDown = 0;
    int moveRight = 0;
    if (row + 1 < size && grid[row + 1][column] != -1)
    {
        int temp = grid[row][column];
        grid[row][column] = 0;
        moveDown = temp + cherryPickupMemoization1(grid, row + 1, column, size, dp);
        grid[row][column] = temp;
    }
    if (column + 1 < size && grid[row][column + 1] != -1)
    {
        int temp = grid[row][column];
        grid[row][column] = 0;
        moveRight = temp + cherryPickupMemoization1(grid, row, column + 1, size, dp);
        grid[row][column] = temp;
    }
    return dp[row][column] = max(moveDown, moveRight);
}
int cherryPickup(vector<vector<int>> &grid)
{
    int size = grid.size();
    vector<vector<int>> dp(size, vector<int>(size, -1));
    return cherryPickupMemoization1(grid, 0, 0, size, dp);
}
// int main()
// {
//     cout << string(20, '-') << endl;
//     // vector<vector<int>> grid = {{0, 1, -1}, {1, 0, -1}, {1, 1, 1}};
//     vector<vector<int>> grid = {{1, 1, -1}, {1, -1, 1}, {-1, 1, 1}};
//     cout << cherryPickup(grid);
//     cout << endl
//          << string(20, '-');
//     return 0;
// }
// --------------------------------------------------------------------- DP 14. Subset Sum Equals to Target -------------------------------------------------------------------------
bool subsetSumToKMemoization(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return dp[index][target] = true;
    // if (arr[index] == target)
    //     return dp[index][target] = true;
    if (index == 0)
        return dp[index][target] = (arr[index] == target);
    if (dp[index][target] != -1)
        return dp[index][target];
    bool pick = false;
    if (arr[index] <= target)
        pick = subsetSumToKMemoization(index - 1, target - arr[index], arr, dp);
    bool notPick = subsetSumToKMemoization(index - 1, target, arr, dp);
    return dp[index][target] = (notPick || pick);
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return subsetSumToKMemoization(n - 1, k, arr, dp);
}
// ---------------------
bool subsetSumToKTabulation(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    // if index == 0;
    for (int target = 0; target <= k; target++)
        dp[0][target] = (arr[0] == target);
    // If target == 0;
    for (int index = 0; index < n; index++)
        dp[index][0] = true;
    for (int index = 1; index < n; index++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool pick = false;
            if (arr[index] <= target)
                pick = dp[index - 1][target - arr[index]];
            bool notPick = dp[index - 1][target];
            dp[index][target] = (notPick || pick);
        }
    }
    return dp[n - 1][k];
}
// ----------------------
bool subsetSumToKSpaceOptimization(int n, int k, vector<int> &arr)
{
    vector<int> previousDataStore(k + 1, -1);
    // if index == 0;
    for (int target = 0; target <= k; target++)
        previousDataStore[target] = (arr[0] == target);
    // If target == 0;
    previousDataStore[0] = true;
    for (int index = 1; index < n; index++)
    {
        vector<int> currentDataStore(k + 1, -1);
        for (int target = 1; target <= k; target++)
        {
            bool pick = false;
            if (arr[index] <= target)
                pick = previousDataStore[target - arr[index]];
            bool notPick = previousDataStore[target];
            currentDataStore[target] = (notPick || pick);
        }
        currentDataStore[0] = true;
        previousDataStore = currentDataStore;
    }
    return previousDataStore[k];
}
// int main()
// {
//     cout << string(20, '-') << endl;
//     vector<int> arr = {4, 3, 2, 1};
//     int k = 2;
//     cout << subsetSumToKSpaceOptimization(arr.size(), k, arr);
//     cout << endl
//          << string(20, '-');
//     return 0;
// }
// // --------------------------------------------------------------------- 416. Partition Equal Subset Sum -------------------------------------------------------------------------
bool canPartitionTabulation(vector<int> &nums, int index, int target, vector<vector<int>> &dp)
{
    if (target == 0)
        return dp[index][target] = true;
    if (index == 0)
        return dp[index][target] = nums[index] == target;
    if (dp[index][target] != -1)
        return dp[index][target];
    int notPick = canPartitionTabulation(nums, index - 1, target, dp);
    int pick = false;
    if (nums[index] <= target)
        pick = canPartitionTabulation(nums, index - 1, target - nums[index], dp);
    return dp[index][target] = (pick || notPick);
}
bool canPartition(vector<int> &nums)
{
    int n = nums.size();
    int totalSum = 0;
    for (int index = 0; index < n; index++)
        totalSum += nums[index];
    if (totalSum % 2 != 0)
        return false;
    int targetSum = totalSum / 2;
    vector<vector<int>> dp(n, vector<int>(targetSum + 1, -1));
    return canPartitionTabulation(nums, n - 1, targetSum, dp);
}
// ------------------------
bool canPartitionTabulation(vector<int> &nums)
{
    int n = nums.size();
    int totalSum = 0;
    for (int index = 0; index < n; index++)
        totalSum += nums[index];
    if (totalSum % 2 != 0)
        return false;
    int targetSum = totalSum / 2;
    vector<vector<int>> dp(n, vector<int>(targetSum + 1, -1));
    for (int target = 0; target <= targetSum; target++)
        dp[0][target] = nums[0] == target;
    for (int index = 0; index < n; index++)
        dp[index][0] = true;
    for (int index = 1; index < n; index++)
    {
        for (int target = 1; target <= targetSum; target++)
        {
            int notPick = dp[index - 1][target];
            int pick = false;
            if (nums[index] <= target)
                pick = dp[index - 1][target - nums[index]];
            dp[index][target] = (pick || notPick);
        }
    }
    return dp[n - 1][targetSum];
}
// -----------------
bool canPartitionSpaceOptimization(vector<int> &nums)
{
    int n = nums.size();
    int totalSum = 0;
    for (int index = 0; index < n; index++)
        totalSum += nums[index];
    if (totalSum % 2 != 0)
        return false;
    int targetSum = totalSum / 2;
    vector<int> previousDataStore(targetSum + 1, -1);
    for (int target = 0; target <= targetSum; target++)
        previousDataStore[target] = nums[0] == target;
    previousDataStore[0] = true;
    for (int index = 1; index < n; index++)
    {
        vector<int> currentDataStore(targetSum + 1, -1);
        for (int target = 1; target <= targetSum; target++)
        {
            int notPick = previousDataStore[target];
            int pick = false;
            if (nums[index] <= target)
                pick = previousDataStore[target - nums[index]];
            currentDataStore[target] = (pick || notPick);
        }
        currentDataStore[0] = true;
        previousDataStore = currentDataStore;
    }
    return previousDataStore[targetSum];
}
// int main()
// {
//     cout << string(20, '-') << endl;
//     vector<int> nums = {1, 5, 11, 5};
//     cout << canPartitionSpaceOptimization(nums);
//     cout << endl
//          << string(20, '-');
//     return 0;
// }
// --------------------------------------------------------------------- DP 17. Counts Subsets with Sum K | Dp on Subsequences -------------------------------------------------------------------------
// https://www.naukri.com/code360/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM
int mod = (int)(1e9 + 7);
int findWaysMemoization(vector<int> &arr, int target, int index, vector<vector<int>> &dp)
{
    // if (index == 0)
    // {
    //     if (target == 0 && arr[0] == 0)
    //         return 2;
    //     if (target == 0 || target == arr[0])
    //         return 1;
    //     return 0;
    // }
    if (index == 0)
    {
        if (target == 0)
            return dp[index][target] = (arr[0] == 0) ? 2 : 1;
        return dp[index][target] = (arr[0] == target) ? 1 : 0;
    }
    if (dp[index][target] != -1)
        return dp[index][target];
    int notPick = findWaysMemoization(arr, target, index - 1, dp);
    int pick = 0;
    if (arr[index] <= target)
        pick = findWaysMemoization(arr, target - arr[index], index - 1, dp);
    return dp[index][target] = (pick + notPick);
}
// -----------------------
int findWaysMemoizationCorrectOne(vector<int> &arr, int index, int target, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (target == 0 && arr[0] == 0)
            return dp[index][target] = 2;
        if (target == 0 || target == arr[0])
            return dp[index][target] = 1;
        return dp[index][target] = 0;
    }
    if (dp[index][target] != -1)
        return dp[index][target];
    int notPick = findWaysMemoizationCorrectOne(arr, index - 1, target, dp);
    int pick = 0;
    if (arr[index] <= target)
        pick = findWaysMemoizationCorrectOne(arr, index - 1, target - arr[index], dp);
    return dp[index][target] = (pick + notPick) % mod;
}
int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return findWaysMemoizationCorrectOne(arr, k, n - 1, dp);
}
// ------------------
int findWaysTabulation(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    for (int target = 0; target <= k; target++)
    {
        if (target == 0)
        {
            dp[0][target] = (arr[0] == 0) ? 2 : 1;
            continue;
        }
        dp[0][target] = (arr[0] == target) ? 1 : 0;
    }
    for (int index = 1; index < n; index++)
    {
        for (int target = 0; target <= k; target++)
        {
            int notPick = dp[index - 1][target];
            int pick = 0;
            if (arr[index] <= target)
                pick = dp[index - 1][target - arr[index]];
            dp[index][target] = (pick + notPick) % mod;
        }
    }
    return dp[n - 1][k];
}
// ------------------
int findWaysSpaceOptimization(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> previousDataStore(k + 1, -1);
    for (int target = 0; target <= k; target++)
    {
        if (target == 0)
        {
            previousDataStore[target] = (arr[0] == 0) ? 2 : 1;
            continue;
        }
        previousDataStore[target] = (arr[0] == target) ? 1 : 0;
    }
    for (int index = 1; index < n; index++)
    {
        vector<int> currentDataStore(k + 1, -1);
        for (int target = 0; target <= k; target++)
        {
            int notPick = previousDataStore[target];
            int pick = 0;
            if (arr[index] <= target)
                pick = previousDataStore[target - arr[index]];
            currentDataStore[target] = (pick + notPick) % mod;
        }
        previousDataStore = currentDataStore;
    }
    return previousDataStore[k];
}
// int main()
// {
//     cout << string(20, '-') << endl;
//     vector<int> arr = {0, 1, 3};
//     cout << findWaysSpaceOptimization(arr, 4);
//     cout << endl
//          << string(20, '-');
//     return 0;
// }
// --------------------------------------------------------------------- DP 18. Count Partitions With Given Difference | Dp on Subsequences -------------------------------------------------------------------------
// Same As Counts Subsets with Sum K Above Code
// Same As Counts Subsets with Sum K Above Code
// Same As Counts Subsets with Sum K Above Code
// Same As Counts Subsets with Sum K Above Code
int countPartitionsMemoization(vector<int> &arr, int index, int target, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (target == 0 && arr[0] == 0)
            return dp[index][target] = 2;
        if (target == 0 || target == arr[0])
            return dp[index][target] = 1;
        return dp[index][target] = 0;
    }
    if (dp[index][target] != -1)
        return dp[index][target];
    int notPick = countPartitionsMemoization(arr, index - 1, target, dp);
    int pick = 0;
    if (arr[index] <= target)
        pick = countPartitionsMemoization(arr, index - 1, target - arr[index], dp);
    return dp[index][target] = (pick + notPick) % mod;
}
int countPartitions(int n, int d, vector<int> &arr)
{
    int totalSum = 0;
    for (int index = 0; index < n; index++)
        totalSum += arr[index];
    if ((totalSum - d) < 0 || (totalSum - d) % 2 != 0)
        return 0;
    int target = (totalSum - d) / 2;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return countPartitionsMemoization(arr, n - 1, target, dp);
}
// int main()
// {
//     cout << string(20, '-') << endl;
//     vector<int> arr = {0, 1, 3};
//     cout << findWays(arr, 4);
//     cout << endl
//          << string(20, '-');
//     return 0;
// }
// ---------------------------------------- DP 19. 0/1 Knapsack | Recursion to Single Array Space Optimised Approach | DP on Subsequences --------------------------------
int knapsackMemoization(vector<int> &weight, vector<int> &value, int index, int targetWeight, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (weight[index] <= targetWeight)
            return dp[index][targetWeight] = value[index];
        return dp[index][targetWeight] = 0;
    }
    if (dp[index][targetWeight] != -1)
        return dp[index][targetWeight];
    int notPick = knapsackMemoization(weight, value, index - 1, targetWeight, dp);
    int pick = 0;
    if (weight[index] <= targetWeight)
        pick = value[index] + knapsackMemoization(weight, value, index - 1, targetWeight - weight[index], dp);
    return dp[index][targetWeight] = max(pick, notPick);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return knapsackMemoization(weight, value, n - 1, maxWeight, dp);
}
// ----------------
int knapsackTabulation(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    for (int targetWeight = 0; targetWeight <= maxWeight; targetWeight++)
    {
        if (weight[0] <= targetWeight)
            dp[0][targetWeight] = value[0];
        else
            dp[0][targetWeight] = 0;
    }
    for (int index = 1; index < n; index++)
    {
        for (int targetWeight = 0; targetWeight <= maxWeight; targetWeight++)
        {
            int notPick = dp[index - 1][targetWeight];
            int pick = 0;
            if (weight[index] <= targetWeight)
                pick = value[index] + dp[index - 1][targetWeight - weight[index]];
            dp[index][targetWeight] = max(pick, notPick);
        }
    }
    return dp[n - 1][maxWeight];
}
// -------------------
int knapsackSpaceOptimization(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> previousDataStore(maxWeight + 1, -1);
    for (int targetWeight = 0; targetWeight <= maxWeight; targetWeight++)
    {
        if (weight[0] <= targetWeight)
            previousDataStore[targetWeight] = value[0];
        else
            previousDataStore[targetWeight] = 0;
    }
    for (int index = 1; index < n; index++)
    {
        vector<int> currentDataStore(maxWeight + 1, -1);
        for (int targetWeight = 0; targetWeight <= maxWeight; targetWeight++)
        {
            int notPick = previousDataStore[targetWeight];
            int pick = 0;
            if (weight[index] <= targetWeight)
                pick = value[index] + previousDataStore[targetWeight - weight[index]];
            currentDataStore[targetWeight] = max(pick, notPick);
        }
        previousDataStore = currentDataStore;
    }
    return previousDataStore[maxWeight];
}
// -------------------------
int knapsackSpaceOptimizationOtherWay(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> previousDataStore(maxWeight + 1, -1);
    for (int targetWeight = 0; targetWeight <= maxWeight; targetWeight++)
    {
        if (weight[0] <= targetWeight)
            previousDataStore[targetWeight] = value[0];
        else
            previousDataStore[targetWeight] = 0;
    }
    for (int index = 1; index < n; index++)
    {
        for (int targetWeight = maxWeight; targetWeight >= 0; targetWeight--)
        {
            int notPick = previousDataStore[targetWeight];
            int pick = 0;
            if (weight[index] <= targetWeight)
                pick = value[index] + previousDataStore[targetWeight - weight[index]];
            previousDataStore[targetWeight] = max(pick, notPick);
        }
    }
    return previousDataStore[maxWeight];
}
// int main()
// {
//     cout << string(20, '-') << endl;
//     vector<int> weight = {1, 2, 4, 5};
//     vector<int> values = {5, 4, 8, 6};
//     cout << knapsackSpaceOptimizationOtherWay(weight, values, weight.size(), 5);
//     cout << endl
//          << string(20, '-');
//     return 0;
// }
// ---------------------------------------- DP 19. Coin Change | Recursion to Single Array Space Optimised Approach | DP on Subsequences --------------------------------
int coinChangeMemoization(vector<int> &coins, int targetAmount, int index, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (targetAmount % coins[0] == 0)
            return dp[index][targetAmount] = targetAmount / coins[0];
        return dp[index][targetAmount] = 1e9;
    }
    if (dp[index][targetAmount] != -1)
        return dp[index][targetAmount];
    int notPick = 0 + coinChangeMemoization(coins, targetAmount, index - 1, dp);
    int pick = 1e9;
    if (coins[index] <= targetAmount)
        pick = 1 + coinChangeMemoization(coins, targetAmount - coins[index], index, dp);
    return dp[index][targetAmount] = min(pick, notPick);
}
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int minimumCoins = coinChangeMemoization(coins, amount, n - 1, dp);
    return minimumCoins > amount ? -1 : minimumCoins;
}
// --------------------
int coinChangeTabulation(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    for (int targetAmount = 0; targetAmount <= amount; targetAmount++)
    {
        if (targetAmount % coins[0] == 0)
            dp[0][targetAmount] = targetAmount / coins[0];
        else
            dp[0][targetAmount] = 1e9;
    }
    for (int index = 1; index < n; index++)
    {
        for (int targetAmount = 0; targetAmount <= amount; targetAmount++)
        {
            int notPick = 0 + dp[index - 1][targetAmount];
            int pick = 1e9;
            if (coins[index] <= targetAmount)
                pick = 1 + dp[index][targetAmount - coins[index]];
            dp[index][targetAmount] = min(pick, notPick);
        }
    }
    int minimumCoins = dp[n - 1][amount];
    return minimumCoins > amount ? -1 : minimumCoins;
}
// -----------------
int coinChangeSpaceOptimization(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<int> previousDataStore(amount + 1, -1);
    for (int targetAmount = 0; targetAmount <= amount; targetAmount++)
    {
        if (targetAmount % coins[0] == 0)
            previousDataStore[targetAmount] = targetAmount / coins[0];
        else
            previousDataStore[targetAmount] = 1e9;
    }
    for (int index = 1; index < n; index++)
    {
        vector<int> currentDataStore(amount + 1, -1);
        for (int targetAmount = 0; targetAmount <= amount; targetAmount++)
        {
            int notPick = 0 + previousDataStore[targetAmount];
            int pick = 1e9;
            if (coins[index] <= targetAmount)
                pick = 1 + currentDataStore[targetAmount - coins[index]];
            currentDataStore[targetAmount] = min(pick, notPick);
        }
        previousDataStore = currentDataStore;
    }
    int minimumCoins = previousDataStore[amount];
    return minimumCoins > amount ? -1 : minimumCoins;
}
// int main()
// {
//     cout << string(20, '-') << endl;
//     vector<int> coins = {1, 2, 5};
//     // vector<int> coins = {2};
//     cout << coinChangeSpaceOptimization(coins, 11);
//     cout << endl
//          << string(20, '-');
//     return 0;
// }
// ---------------------------------------------------------------------------- 494. Target Sum -------------------------------------------------------------------------
int findTargetSumWaysMemoization(vector<int> &arr, int index, int target, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (target == 0 && arr[0] == 0)
            return dp[index][target] = 2;
        if (target == 0 || target == arr[0])
            return dp[index][target] = 1;
        return dp[index][target] = 0;
    }
    if (dp[index][target] != -1)
        return dp[index][target];
    int notPick = findTargetSumWaysMemoization(arr, index - 1, target, dp);
    int pick = 0;
    if (arr[index] <= target)
        pick = findTargetSumWaysMemoization(arr, index - 1, target - arr[index], dp);
    return dp[index][target] = pick + notPick;
}

int findTargetSumWays(vector<int> &nums, int targetValue)
{
    int n = nums.size();
    int totalSum = 0;
    for (int index = 0; index < n; index++)
        totalSum += nums[index];
    if ((totalSum - targetValue) < 0 || (totalSum - targetValue) % 2 != 0)
        return 0;
    int target = (totalSum - targetValue) / 2;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return findTargetSumWaysMemoization(nums, n - 1, target, dp);
}
// ---------------------
int findTargetSumWaysTabulation(vector<int> &nums, int targetValue)
{
    int n = nums.size();
    int totalSum = 0;
    for (int index = 0; index < n; index++)
        totalSum += nums[index];
    if ((totalSum - targetValue) < 0 || (totalSum - targetValue) % 2 != 0)
        return 0;
    int target = (totalSum - targetValue) / 2;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    for (int currTarget = 0; currTarget <= target; currTarget++)
    {
        if (currTarget == 0)
        {
            dp[0][currTarget] = (nums[0] == 0) ? 2 : 1;
            continue;
        }
        dp[0][currTarget] = (nums[0] == currTarget) ? 1 : 0;
    }
    for (int index = 1; index < n; index++)
    {
        for (int currTarget = 0; currTarget <= target; currTarget++)
        {
            int notPick = dp[index - 1][currTarget];
            int pick = 0;
            if (nums[index] <= currTarget)
                pick = dp[index - 1][currTarget - nums[index]];
            dp[index][currTarget] = (pick + notPick) % mod;
        }
    }
    return dp[n - 1][target];
}
// ------------------
int findTargetSumWaysSpaceOptimization(vector<int> &nums, int targetValue)
{
    int n = nums.size();
    int totalSum = 0;
    for (int index = 0; index < n; index++)
        totalSum += nums[index];
    if ((totalSum - targetValue) < 0 || (totalSum - targetValue) % 2 != 0)
        return 0;
    int target = (totalSum - targetValue) / 2;
    vector<int> previousDataStore(target + 1, -1);
    for (int currTarget = 0; currTarget <= target; currTarget++)
    {
        if (currTarget == 0)
        {
            previousDataStore[currTarget] = (nums[0] == 0) ? 2 : 1;
            continue;
        }
        previousDataStore[currTarget] = (nums[0] == currTarget) ? 1 : 0;
    }
    for (int index = 1; index < n; index++)
    {
        vector<int> currentDataStore(target + 1, -1);
        for (int currTarget = 0; currTarget <= target; currTarget++)
        {
            int notPick = previousDataStore[currTarget];
            int pick = 0;
            if (nums[index] <= currTarget)
                pick = previousDataStore[currTarget - nums[index]];
            currentDataStore[currTarget] = (pick + notPick) % mod;
        }
        previousDataStore = currentDataStore;
    }
    return previousDataStore[target];
}
// int main()
// {
//     cout << string(20, '-') << endl;
//     vector<int> coins = {1, 2, 3, 1};
//     cout << findTargetSumWaysSpaceOptimization(coins, 3);
//     cout << endl
//          << string(20, '-');
//     return 0;
// }
// ---------------------------------------------------------------------------- 518. Coin Change II -------------------------------------------------------------------------
int changeMemoization(int amount, vector<int> &coins, int index, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (amount % coins[0] == 0)
            return dp[index][amount] = 1;
        return dp[index][amount] = 0;
    }
    if (dp[index][amount] != -1)
        return dp[index][amount];
    int notTake = changeMemoization(amount, coins, index - 1, dp);
    int take = 0;
    if (coins[index] <= amount)
        take = changeMemoization(amount - coins[index], coins, index, dp);
    return dp[index][amount] = (take + notTake);
}
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    return changeMemoization(amount, coins, n - 1, dp);
}
// -----------------
int changeTabulation(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    for (int targetAmount = 0; targetAmount <= amount; targetAmount++)
    {
        if (targetAmount % coins[0] == 0)
            dp[0][targetAmount] = 1;
        else
            dp[0][targetAmount] = 0;
    }
    for (int index = 1; index < n; index++)
    {
        for (int targetAmount = 0; targetAmount <= amount; targetAmount++)
        {
            int notTake = dp[index - 1][targetAmount];
            int take = 0;
            if (coins[index] <= targetAmount)
                take = dp[index][targetAmount - coins[index]];
            dp[index][targetAmount] = (take + notTake);
        }
    }
    return dp[n - 1][amount];
}
// ----------------------
int changeSpaceOptimization(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<int> previousDataStore(amount + 1, -1);
    for (int targetAmount = 0; targetAmount <= amount; targetAmount++)
    {
        if (targetAmount % coins[0] == 0)
            previousDataStore[targetAmount] = 1;
        else
            previousDataStore[targetAmount] = 0;
    }
    for (int index = 1; index < n; index++)
    {
        vector<int> currentDataStore(amount + 1, -1);
        for (int targetAmount = 0; targetAmount <= amount; targetAmount++)
        {
            int notTake = previousDataStore[targetAmount];
            int take = 0;
            if (coins[index] <= targetAmount)
                take = currentDataStore[targetAmount - coins[index]];
            currentDataStore[targetAmount] = (take + notTake);
        }
        previousDataStore = currentDataStore;
    }
    return previousDataStore[amount];
}
// int main()
// {
//     cout << string(20, '-') << endl;
//     vector<int> coins = {1, 2, 5};
//     cout << changeSpaceOptimization(5, coins);
//     cout << endl
//          << string(20, '-');
//     return 0;
// }
// ---------------------------------------------- DP 23. Unbounded Knapsack | 1-D Array Space Optimised Approach -------------------------------------------------------------------------
int unboundedKnapsackMemoization(vector<int> &profit, vector<int> &weight, int index, int targetWeight, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (weight[0] <= targetWeight)
            return dp[index][targetWeight] = (targetWeight / weight[0]) * profit[0];
        return dp[index][targetWeight] = 0;
    }
    if (dp[index][targetWeight] != -1)
        return dp[index][targetWeight];
    int notPick = unboundedKnapsackMemoization(profit, weight, index - 1, targetWeight, dp);
    int pick = 0;
    if (weight[index] <= targetWeight)
        pick = profit[index] + unboundedKnapsackMemoization(profit, weight, index, targetWeight - weight[index], dp);
    return dp[index][targetWeight] = max(pick, notPick);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return unboundedKnapsackMemoization(profit, weight, n - 1, w, dp);
}
// -------------------------
int unboundedKnapsackTabulation(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    for (int targetWeight = 0; targetWeight <= w; targetWeight++)
    {
        if (weight[0] <= targetWeight)
            dp[0][targetWeight] = (targetWeight / weight[0]) * profit[0];
        else
            dp[0][targetWeight] = 0;
    }
    for (int index = 1; index < n; index++)
    {
        for (int targetWeight = 0; targetWeight <= w; targetWeight++)
        {
            int notPick = dp[index - 1][targetWeight];
            int pick = 0;
            if (weight[index] <= targetWeight)
                pick = profit[index] + dp[index][targetWeight - weight[index]];
            dp[index][targetWeight] = max(pick, notPick);
        }
    }
    return dp[n - 1][w];
}
// -----------------
int unboundedKnapsackSpaceOptimization(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int> previousDataStore(w + 1, -1);
    for (int targetWeight = 0; targetWeight <= w; targetWeight++)
    {
        if (weight[0] <= targetWeight)
            previousDataStore[targetWeight] = (targetWeight / weight[0]) * profit[0];
        else
            previousDataStore[targetWeight] = 0;
    }
    for (int index = 1; index < n; index++)
    {
        vector<int> currentDataStore(w + 1, -1);
        for (int targetWeight = 0; targetWeight <= w; targetWeight++)
        {
            int notPick = previousDataStore[targetWeight];
            int pick = 0;
            if (weight[index] <= targetWeight)
                pick = profit[index] + currentDataStore[targetWeight - weight[index]];
            currentDataStore[targetWeight] = max(pick, notPick);
        }
        previousDataStore = currentDataStore;
    }
    return previousDataStore[w];
}
// int main()
// {
//     cout << string(20, '-') << endl;
//     vector<int> profit = {5, 11, 13};
//     vector<int> weight = {2, 4, 6};
//     cout << unboundedKnapsackSpaceOptimization(3, 10, profit, weight);
//     cout << endl
//          << string(20, '-');
//     return 0;
// }
// --------------------------------------------------- DP 24. Rod Cutting Problem | 1D Array Space Optimised Approach -------------------------------------------------------------------------
int cutRodMemoization(vector<int> &price, int index, int targetRodSize, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        // return targetRodSize * price[0];
        if (1 <= targetRodSize)
            dp[index][targetRodSize] = (targetRodSize / 1) * price[index];
        else
            dp[index][targetRodSize] = 0;
    }
    if (dp[index][targetRodSize] != -1)
        return dp[index][targetRodSize];
    int notPick = 0 + cutRodMemoization(price, index - 1, targetRodSize, dp);
    int pick = 0;
    int rodLength = index + 1;
    if (rodLength <= targetRodSize)
        pick = price[index] + cutRodMemoization(price, index, targetRodSize - rodLength, dp);
    return dp[index][targetRodSize] = max(pick, notPick);
}
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return cutRodMemoization(price, n - 1, n, dp);
}
// We can do the Tabulation and Space Optimization in the similar way as above
// int main()
// {
//     cout << string(20, '-') << endl;
//     vector<int> price = {2, 5, 7, 8, 10};
//     cout << cutRod(price, price.size());
//     cout << endl
//          << string(20, '-');
//     return 0;
// }
// --------------------------------------------------------------------- 1143. Longest Common Subsequence ---------------------------------------------------------------
int longestCommonSubsequenceMemoization(string &text1, string &text2, int text1Index, int text2Index, vector<vector<int>> &dp)
{
    if (text1Index < 0 || text2Index < 0)
        return 0;
    if (dp[text1Index][text2Index] != -1)
        return dp[text1Index][text2Index];
    // Match
    if (text1[text1Index] == text2[text2Index])
        return dp[text1Index][text2Index] = 1 + longestCommonSubsequenceMemoization(text1, text2, text1Index - 1, text2Index - 1, dp);
    // Not Match
    return dp[text1Index][text2Index] = 0 + max(longestCommonSubsequenceMemoization(text1, text2, text1Index - 1, text2Index, dp), longestCommonSubsequenceMemoization(text1, text2, text1Index, text2Index - 1, dp));
}
int longestCommonSubsequence(string text1, string text2)
{
    int text1Size = text1.size();
    int text2Size = text2.size();
    vector<vector<int>> dp(text1Size, vector<int>(text2Size, -1));
    return longestCommonSubsequenceMemoization(text1, text2, text1Size - 1, text2Size - 1, dp);
}
// --- "MEMOIZATION WITH SHIFTING INDEX 1 BY RIGHT IN DP, FOR TABULATION APPROACH" ---
int longestCommonSubsequenceMemoization2(string &text1, string &text2, int text1Index, int text2Index, vector<vector<int>> &dp)
{
    if (text1Index == 0 || text2Index == 0)
        return 0;
    if (dp[text1Index][text2Index] != -1)
        return dp[text1Index][text2Index];
    // Match
    if (text1[text1Index - 1] == text2[text2Index - 1])
        return dp[text1Index][text2Index] = 1 + longestCommonSubsequenceMemoization2(text1, text2, text1Index - 1, text2Index - 1, dp);
    // Not Match
    return dp[text1Index][text2Index] = 0 + max(longestCommonSubsequenceMemoization2(text1, text2, text1Index - 1, text2Index, dp), longestCommonSubsequenceMemoization2(text1, text2, text1Index, text2Index - 1, dp));
}
int longestCommonSubsequence2(string text1, string text2)
{
    int text1Size = text1.size();
    int text2Size = text2.size();
    vector<vector<int>> dp(text1Size + 1, vector<int>(text2Size + 1, -1));
    return longestCommonSubsequenceMemoization2(text1, text2, text1Size, text2Size, dp);
}
// -----------------------------
int longestCommonSubsequenceTabulation(string text1, string text2)
{
    int text1Size = text1.size();
    int text2Size = text2.size();
    vector<vector<int>> dp(text1Size + 1, vector<int>(text2Size + 1, -1));
    // If column == 0
    for (int text1Index = 0; text1Index <= text1Size; text1Index++)
        dp[text1Index][0] = 0;
    // if row == 0
    for (int text2Index = 0; text2Index <= text2Size; text2Index++)
        dp[0][text2Index] = 0;
    for (int text1Index = 1; text1Index <= text1Size; text1Index++)
    {
        for (int text2Index = 1; text2Index <= text2Size; text2Index++)
        {
            // Match
            if (text1[text1Index - 1] == text2[text2Index - 1])
                dp[text1Index][text2Index] = 1 + dp[text1Index - 1][text2Index - 1];
            // Not Match
            else
                dp[text1Index][text2Index] = 0 + max(dp[text1Index - 1][text2Index], dp[text1Index][text2Index - 1]);
        }
    }
    return dp[text1Size][text2Size];
}
// ------------------------
int longestCommonSubsequenceSpaceOptimization(string text1, string text2)
{
    int text1Size = text1.size();
    int text2Size = text2.size();
    vector<int> previousDataStore(text2Size + 1, -1);
    // if row == 0
    for (int text2Index = 0; text2Index <= text2Size; text2Index++)
        previousDataStore[text2Index] = 0;
    // If column == 0
    previousDataStore[0] = 0;
    for (int text1Index = 1; text1Index <= text1Size; text1Index++)
    {
        vector<int> currentDataStore(text2Size + 1, -1);
        currentDataStore[0] = 0;
        for (int text2Index = 1; text2Index <= text2Size; text2Index++)
        {
            // Match
            if (text1[text1Index - 1] == text2[text2Index - 1])
                currentDataStore[text2Index] = 1 + previousDataStore[text2Index - 1];
            // Not Match
            else
                currentDataStore[text2Index] = 0 + max(previousDataStore[text2Index], currentDataStore[text2Index - 1]);
        }
        previousDataStore = currentDataStore;
    }
    return previousDataStore[text2Size];
}
// int main()
// {
//     cout << string(20, '-') << endl;
//     string text1 = "abcde";
//     string text2 = "ace";
//     cout << longestCommonSubsequenceSpaceOptimization(text1, text2);
//     cout << endl
//          << string(20, '-');
//     return 0;
// }
// ----------------------------------------------------------- DP 26. Print Longest Common Subsequence | Dp on Strings ---------------------------------------------------------------
string printLCSMemoization(string &s, string &t, int sIndex, int tIndex)
{
    if (sIndex == 0 || tIndex == 0)
        return "";
    // Match
    if (s[sIndex - 1] == t[tIndex - 1])
        return printLCSMemoization(s, t, sIndex - 1, tIndex - 1) + s[sIndex - 1];
    // Not Match
    string shiftingSIndex = printLCSMemoization(s, t, sIndex - 1, tIndex);
    string shiftingTindex = printLCSMemoization(s, t, sIndex, tIndex - 1);
    return (shiftingSIndex.size() >= shiftingTindex.size()) ? shiftingSIndex : shiftingTindex;
}
void printLCS(string &s, string &t)
{
    int sSize = s.size();
    int tSize = t.size();
    string lcsString = printLCSMemoization(s, t, sSize, tSize);
    cout << lcsString;
}
// ---------------------------------
string printLongestCommonSubsequenceTabulation(string text1, string text2)
{
    int text1Size = text1.size();
    int text2Size = text2.size();
    vector<vector<int>> dp(text1Size + 1, vector<int>(text2Size + 1, -1));
    // If column == 0
    for (int text1Index = 0; text1Index <= text1Size; text1Index++)
        dp[text1Index][0] = 0;
    // if row == 0
    for (int text2Index = 0; text2Index <= text2Size; text2Index++)
        dp[0][text2Index] = 0;
    for (int text1Index = 1; text1Index <= text1Size; text1Index++)
    {
        for (int text2Index = 1; text2Index <= text2Size; text2Index++)
        {
            // Match
            if (text1[text1Index - 1] == text2[text2Index - 1])
                dp[text1Index][text2Index] = 1 + dp[text1Index - 1][text2Index - 1];
            // Not Match
            else
                dp[text1Index][text2Index] = 0 + max(dp[text1Index - 1][text2Index], dp[text1Index][text2Index - 1]);
        }
    }
    int text1Index = text1Size;
    int text2Index = text2Size;
    string lcsString;
    while (text1Index > 0 && text2Index > 0)
    {
        if (text1[text1Index - 1] == text2[text2Index - 1])
        {
            lcsString = text1[text1Index - 1] + lcsString;
            text1Index--;
            text2Index--;
        }
        else if (dp[text1Index - 1][text2Index] >= dp[text1Index][text2Index - 1])
            text1Index--;
        // else if (dp[text1Index - 1][text2Index] < dp[text1Index][text2Index - 1])
        else
            text2Index--;
    }
    return lcsString;
    // return dp[text1Size][text2Size];
}
void printLCSFun(string &s, string &t)
{
    string lcsString = printLongestCommonSubsequenceTabulation(s, t);
    cout << lcsString;
}
// int main()
// {
//     cout << string(20, '-') << endl;
//     string s = "ace";
//     string t = "abcde";
//     printLCSFun(s, t);
//     cout << endl
//          << string(20, '-');
//     return 0;
// }
// ----------------------------------------------------------- DP 27. Longest Common Substring | DP on Strings ---------------------------------------------------------------
int longestCommonSubstringMemorization(string &str1, string &str2, int str1Index, int str2Index, int currentLength, vector<vector<vector<int>>> &memo)
{
    if (str1Index == 0 || str2Index == 0)
        return currentLength;
    if (memo[str1Index][str2Index][currentLength] != -1)
        return memo[str1Index][str2Index][currentLength];
    // If characters match, increment current substring length and continue
    if (str1[str1Index - 1] == str2[str2Index - 1])
        return longestCommonSubstringMemorization(str1, str2, str1Index - 1, str2Index - 1, currentLength + 1, memo);
    // If characters don't match, reset current substring length to 0 and compare the results of skipping each character
    int str1CharacterSkip = longestCommonSubstringMemorization(str1, str2, str1Index - 1, str2Index, 0, memo);
    int str2CharacterSkip = longestCommonSubstringMemorization(str1, str2, str1Index, str2Index - 1, 0, memo);
    return memo[str1Index][str2Index][currentLength] = max(currentLength, max(str1CharacterSkip, str2CharacterSkip));
}

int longestCommonSubstring(string &str1, string &str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(m + 1, vector<int>(min(n, m) + 1, -1)));
    return longestCommonSubstringMemorization(str1, str2, str1.size(), str2.size(), 0, memo);
}
// -------------
int longestCommonSubStringTabulation(string text1, string text2)
{
    int text1Size = text1.size();
    int text2Size = text2.size();
    vector<vector<int>> dp(text1Size + 1, vector<int>(text2Size + 1, -1));
    // If column == 0
    for (int text1Index = 0; text1Index <= text1Size; text1Index++)
        dp[text1Index][0] = 0;
    // if row == 0
    for (int text2Index = 0; text2Index <= text2Size; text2Index++)
        dp[0][text2Index] = 0;
    int ans = 0; // Initialize the answer variable
    for (int text1Index = 1; text1Index <= text1Size; text1Index++)
    {
        for (int text2Index = 1; text2Index <= text2Size; text2Index++)
        {
            // Match
            if (text1[text1Index - 1] == text2[text2Index - 1])
            {
                dp[text1Index][text2Index] = 1 + dp[text1Index - 1][text2Index - 1];
                ans = max(ans, dp[text1Index][text2Index]);
            }
            // Not Match
            else
                dp[text1Index][text2Index] = 0;
        }
    }
    return ans;
}
// ---------------------
int longestCommonSubStringSpaceOptimization(string text1, string text2)
{
    int text1Size = text1.size();
    int text2Size = text2.size();
    vector<int> previousDataStore(text2Size + 1, -1);
    // if row == 0
    for (int text2Index = 0; text2Index <= text2Size; text2Index++)
        previousDataStore[text2Index] = 0;
    // If column == 0
    previousDataStore[0] = 0;
    int ans = 0; // Initialize the answer variable
    for (int text1Index = 1; text1Index <= text1Size; text1Index++)
    {
        vector<int> currentDataStore(text2Size + 1, -1);
        currentDataStore[0] = 0;
        for (int text2Index = 1; text2Index <= text2Size; text2Index++)
        {
            // Match
            if (text1[text1Index - 1] == text2[text2Index - 1])
            {
                currentDataStore[text2Index] = 1 + previousDataStore[text2Index - 1];
                ans = max(ans, currentDataStore[text2Index]);
            }
            // Not Match
            else
                currentDataStore[text2Index] = 0;
        }
        previousDataStore = currentDataStore;
    }
    return ans;
}

// int main()
// {
//     cout << string(20, '-') << endl;
//     string str1 = "abcjklp";
//     string str2 = "acjkp";
//     cout << longestCommonSubStringSpaceOptimization(str1, str2);
//     cout << endl
//          << string(20, '-');
//     return 0;
// }
// ----------------------------------------------------------- DP 28. Longest Palindromic Subsequence ---------------------------------------------------------------
int longestPalindromeSubseqMemoization(string &str1, string &str2, int str1index, int str2index, vector<vector<int>> &dp)
{
    if (str1index == 0 || str2index == 0)
        return dp[str1index][str2index] = 0;
    if (dp[str1index][str2index] != -1)
        return dp[str1index][str2index];
    // Match
    if (str1[str1index - 1] == str2[str2index - 1])
        return dp[str1index][str2index] = 1 + longestPalindromeSubseqMemoization(str1, str2, str1index - 1, str2index - 1, dp);
    // Not Match
    int str1SkipCharacter = 0 + longestPalindromeSubseqMemoization(str1, str2, str1index - 1, str2index, dp);
    int str2SkipCharacter = 0 + longestPalindromeSubseqMemoization(str1, str2, str1index, str2index - 1, dp);
    return dp[str1index][str2index] = max(str1SkipCharacter, str2SkipCharacter);
}
int longestPalindromeSubseq(string s)
{
    int n = s.size();
    string str2 = s;
    reverse(str2.begin(), str2.end());
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return longestPalindromeSubseqMemoization(s, str2, n, n, dp);
}
// -----------------------------
int longestPalindromeSubseqTabulation(string str1)
{
    int n = str1.size();
    string str2 = str1;
    reverse(str2.begin(), str2.end());
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    // If column == 0
    for (int str1index = 0; str1index <= n; str1index++)
        dp[str1index][0] = 0;
    // if row == 0
    for (int str2index = 0; str2index <= n; str2index++)
        dp[0][str2index] = 0;
    for (int str1index = 1; str1index <= n; str1index++)
    {
        for (int str2index = 1; str2index <= n; str2index++)
        {
            // Match
            if (str1[str1index - 1] == str2[str2index - 1])
                dp[str1index][str2index] = 1 + dp[str1index - 1][str2index - 1];
            // Not Match
            else
            {
                int str1SkipCharacter = 0 + dp[str1index - 1][str2index];
                int str2SkipCharacter = 0 + dp[str1index][str2index - 1];
                dp[str1index][str2index] = max(str1SkipCharacter, str2SkipCharacter);
            }
        }
    }
    return dp[n][n];
}
// --------------
int longestPalindromeSubseqSpaceOptimization(string str1)
{
    int n = str1.size();
    string str2 = str1;
    reverse(str2.begin(), str2.end());
    vector<int> previousDataStore(n + 1, -1);
    // if row == 0
    for (int str2index = 0; str2index <= n; str2index++)
        previousDataStore[str2index] = 0;
    // If column == 0
    previousDataStore[0] = 0;
    for (int str1index = 1; str1index <= n; str1index++)
    {
        vector<int> currentDataStore(n + 1, -1);
        currentDataStore[0] = 0;
        for (int str2index = 1; str2index <= n; str2index++)
        {
            // Match
            if (str1[str1index - 1] == str2[str2index - 1])
                currentDataStore[str2index] = 1 + previousDataStore[str2index - 1];
            // Not Match
            else
            {
                int str1SkipCharacter = 0 + previousDataStore[str2index];
                int str2SkipCharacter = 0 + currentDataStore[str2index - 1];
                currentDataStore[str2index] = max(str1SkipCharacter, str2SkipCharacter);
            }
        }
        previousDataStore = currentDataStore;
    }
    return previousDataStore[n];
}
// int main()
// {
//     cout << string(20, '-') << endl;
//     string s = "bbbab";
//     cout << longestPalindromeSubseqTabulation(s);
//     cout << endl
//          << string(20, '-');
//     return 0;
// }
// ----------------------------------------------------------- DP 29. Minimum Insertions to Make String Palindrome ---------------------------------------------------------------
int findLongestCommonSubsequenceMemoization(string &str1, string &str2, int str1Index, int str2Index, vector<vector<int>> &dp)
{
    if (str1Index == 0 || str2Index == 0)
        return dp[str1Index][str2Index] = 0;
    if (dp[str1Index][str2Index] != -1)
        return dp[str1Index][str2Index];
    // Match
    if (str1[str1Index - 1] == str2[str2Index - 1])
        return dp[str1Index][str2Index] = 1 + findLongestCommonSubsequenceMemoization(str1, str2, str1Index - 1, str2Index - 1, dp);
    // NotMatch
    int str1SkipCharacter = 0 + findLongestCommonSubsequenceMemoization(str1, str2, str1Index - 1, str2Index, dp);
    int str2SkipCharacter = 0 + findLongestCommonSubsequenceMemoization(str1, str2, str1Index, str2Index - 1, dp);
    return dp[str1Index][str2Index] = max(str1SkipCharacter, str2SkipCharacter);
}
int minInsertions(string str1)
{
    int n = str1.size();
    string str2 = str1;
    reverse(str2.begin(), str2.end());
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    int lengthOfLongestCommonSubsequence = findLongestCommonSubsequenceMemoization(str1, str2, n, n, dp);
    return (n - lengthOfLongestCommonSubsequence);
}
// ------------------
int minInsertionsTabulation(string str1)
{
    int n = str1.size();
    string str2 = str1;
    reverse(str2.begin(), str2.end());
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    // If column == 0
    for (int str1index = 0; str1index <= n; str1index++)
        dp[str1index][0] = 0;
    // if row == 0
    for (int str2index = 0; str2index <= n; str2index++)
        dp[0][str2index] = 0;
    for (int str1index = 1; str1index <= n; str1index++)
    {
        for (int str2index = 1; str2index <= n; str2index++)
        {
            // Match
            if (str1[str1index - 1] == str2[str2index - 1])
                dp[str1index][str2index] = 1 + dp[str1index - 1][str2index - 1];
            // Not Match
            else
            {
                int str1SkipCharacter = 0 + dp[str1index - 1][str2index];
                int str2SkipCharacter = 0 + dp[str1index][str2index - 1];
                dp[str1index][str2index] = max(str1SkipCharacter, str2SkipCharacter);
            }
        }
    }
    int lengthOfLongestCommonSubsequence = dp[n][n];
    return (n - lengthOfLongestCommonSubsequence);
}
// -------------
int minInsertionsSpaceOptimization(string str1)
{
    int n = str1.size();
    string str2 = str1;
    reverse(str2.begin(), str2.end());
    vector<int> previousDataStore(n + 1, -1);
    // if row == 0
    for (int str2index = 0; str2index <= n; str2index++)
        previousDataStore[str2index] = 0;
    // If column == 0
    previousDataStore[0] = 0;
    for (int str1index = 1; str1index <= n; str1index++)
    {
        vector<int> currentDataStore(n + 1, -1);
        currentDataStore[0] = 0;
        for (int str2index = 1; str2index <= n; str2index++)
        {
            // Match
            if (str1[str1index - 1] == str2[str2index - 1])
                currentDataStore[str2index] = 1 + previousDataStore[str2index - 1];
            // Not Match
            else
            {
                int str1SkipCharacter = 0 + previousDataStore[str2index];
                int str2SkipCharacter = 0 + currentDataStore[str2index - 1];
                currentDataStore[str2index] = max(str1SkipCharacter, str2SkipCharacter);
            }
        }
        previousDataStore = currentDataStore;
    }
    int lengthOfLongestCommonSubsequence = previousDataStore[n];
    return (n - lengthOfLongestCommonSubsequence);
}
// int main()
// {
//     cout << string(20, '-') << endl;
//     string s = "zzazz";
//     cout << minInsertionsSpaceOptimization(s);
//     cout << endl
//          << string(20, '-');
//     return 0;
// }
// ----------------------------------------------------------- 121. Best Time to Buy and Sell Stock ---------------------------------------------------------------
int maxProfit(vector<int> &prices)
{
    int buyPrice = INT_MAX;
    int sellPrice = INT_MIN;
    int max_profit = 0;
    for (int index = 0; index < prices.size(); index++)
    {
        if (buyPrice > prices[index])
        {
            buyPrice = prices[index];
            sellPrice = prices[index];
        }
        else if (sellPrice < prices[index])
            sellPrice = prices[index];
        max_profit = max(max_profit, sellPrice - buyPrice);
    }
    return max_profit;
}
// ----------------------------
int maxProfitTUF(vector<int> &prices)
{
    int maxProfit = 0;
    int minPrice = prices[0];
    for (int index = 1; index < prices.size(); index++)
    {
        int currProfit = prices[index] - minPrice;
        maxProfit = max(currProfit, maxProfit);
        minPrice = min(minPrice, prices[index]);
    }
    return maxProfit;
}
// int main()
// {
//     cout << string(20, '-') << endl;
//     vector<int> prices = {7, 1, 5, 3, 6, 4};
//     cout << maxProfit(prices);
//     cout << endl
//          << string(20, '-');
//     return 0;
// }
// ------------------------------------------------------ DP 36. Buy and Sell Stock - II | Recursion to Space Optimisation -------------------------------------------------------------
long buyAndSellStockMemoization(vector<int> &prices, int index, bool buy, int &n, vector<vector<int>> &dp)
{
    if (index == n)
        return dp[index][buy] = 0;
    if (dp[index][buy] != -1)
        return dp[index][buy];
    long profit = 0;
    if (buy == 0)
    {
        long notBuyStock = 0 + buyAndSellStockMemoization(prices, index + 1, 0, n, dp);
        long buyStock = -prices[index] + buyAndSellStockMemoization(prices, index + 1, 1, n, dp);
        profit = max(notBuyStock, buyStock);
    }
    if (buy == 1)
    {
        long notSellStack = 0 + buyAndSellStockMemoization(prices, index + 1, 1, n, dp);
        long sellStock = prices[index] + buyAndSellStockMemoization(prices, index + 1, 0, n, dp);
        profit = max(sellStock, notSellStack);
    }
    return dp[index][buy] = profit;
}
int buyAndSellStock2(vector<int> &prices)
{
    int n = prices.size();
    if (n == 0)
        return 0;
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    return buyAndSellStockMemoization(prices, 0, 0, n, dp);
}
// ---------------------
int buyAndSellStock2Tabulation(vector<int> &prices)
{
    int n = prices.size();
    if (n == 0)
        return 0;
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    dp[n][0] = 0;
    dp[n][1] = 0;
    long profit;
    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy == 0)
            {
                long notBuyStock = 0 + dp[index + 1][0];
                long buyStock = -prices[index] + dp[index + 1][1];
                profit = max(notBuyStock, buyStock);
            }
            if (buy == 1)
            {
                long notSellStock = 0 + dp[index + 1][1];
                long sellStock = prices[index] + dp[index + 1][0];
                profit = max(notSellStock, sellStock);
            }
            dp[index][buy] = profit;
        }
    }
    return dp[0][0];
}
// ------------------------
int buyAndSellStock2SpaceOptimization(vector<int> &prices)
{
    int n = prices.size();
    if (n == 0)
        return 0;
    vector<int> previousDataStore(2, -1);
    // Base condition: When there are no stocks left, the profit is 0.
    previousDataStore[0] = 0;
    previousDataStore[1] = 0;
    long profit;
    // Loop through the array in reverse order
    for (int index = n - 1; index >= 0; index--)
    {
        vector<int> currentDataDataStore(2, -1);
        for (int buy = 0; buy <= 1; buy++)
        {
            // We can buy the stock
            if (buy == 0)
            {
                long notBuyStock = 0 + previousDataStore[0];
                long buyStock = -prices[index] + previousDataStore[1];
                profit = max(notBuyStock, buyStock);
            }
            // We can sell the stock
            if (buy == 1)
            {
                long notSellStock = 0 + previousDataStore[1];
                long sellStock = prices[index] + previousDataStore[0];
                profit = max(notSellStock, sellStock);
            }
            currentDataDataStore[buy] = profit;
        }
        // Update the "previousDataStore" array with the current values
        previousDataStore = currentDataDataStore;
    }
    // The maximum profit is stored in previousDataStore[0] after all calculations
    return previousDataStore[0];
}
// int main()
// {
//     cout << string(20, '-') << endl;
//     vector<int> prices = {7, 1, 5, 3, 6, 4};
//     cout << buyAndSellStock2SpaceOptimization(prices);
//     cout << endl
//          << string(20, '-');
//     return 0;
// }