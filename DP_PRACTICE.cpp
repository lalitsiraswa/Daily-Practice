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
int main()
{
    cout << string(20, '-') << endl;
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << minPathSumSpaceOptimization(grid);
    cout << endl
         << string(20, '-');
    return 0;
}