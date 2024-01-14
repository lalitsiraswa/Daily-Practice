#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------------------ Sudoku Solver -------------------------------------------------------------------------
// ------------------------------- TLE -----------------------------------------
// bool checkInMatrix(vector<vector<char>> &board, int row, int column, char data)
// {
//     for (int i = row; i < row + 3; i++)
//     {
//         for (int j = column; j < column + 3; j++)
//         {
//             if (board[i][j] == data)
//                 return false;
//         }
//     }
//     return true;
// }
// bool isPossible(vector<vector<char>> &board, unordered_map<int, unordered_map<char, int>> &rowMapping, unordered_map<int, unordered_map<char, int>> &collMapping, int row, int column, char data)
// {
//     if (rowMapping[row][data] == 1 || collMapping[column][data] == 1)
//         return false;
//     if (row >= 0 && row <= 2)
//     {
//         if (column >= 0 && column <= 2)
//             return checkInMatrix(board, 0, 0, data);
//         if (column >= 3 && column <= 5)
//             return checkInMatrix(board, 0, 3, data);
//         if (column >= 6 && column <= 8)
//             return checkInMatrix(board, 0, 6, data);
//     }
//     if (row >= 3 && row <= 5)
//     {
//         if (column >= 0 && column <= 2)
//             return checkInMatrix(board, 3, 0, data);
//         if (column >= 3 && column <= 5)
//             return checkInMatrix(board, 3, 3, data);
//         if (column >= 6 && column <= 8)
//             return checkInMatrix(board, 3, 6, data);
//     }
//     if (row >= 6 && row <= 8)
//     {
//         if (column >= 0 && column <= 2)
//             return checkInMatrix(board, 6, 0, data);
//         if (column >= 3 && column <= 5)
//             return checkInMatrix(board, 6, 3, data);
//         if (column >= 6 && column <= 8)
//             return checkInMatrix(board, 6, 6, data);
//     }
// }
// bool solveSudokuRecursive(vector<vector<char>> &board, unordered_map<int, unordered_map<char, int>> &rowMapping, unordered_map<int, unordered_map<char, int>> &collMapping, int row)
// {
//     for (int i = row; i < 9; i++)
//     {
//         for (int j = 0; j < 9; j++)
//         {
//             if (board[i][j] == '.')
//             {
//                 for (int data = 1; data <= 9; data++)
//                 {
//                     bool flag = isPossible(board, rowMapping, collMapping, i, j, data + 48);
//                     if (flag)
//                     {
//                         board[i][j] = data + 48;
//                         rowMapping[i][board[i][j]] = 1;
//                         collMapping[j][board[i][j]] = 1;
//                         bool isSudokuResolved = solveSudokuRecursive(board, rowMapping, collMapping, i);
//                         if (isSudokuResolved)
//                             return true;
//                         rowMapping[i][board[i][j]] = 0;
//                         collMapping[j][board[i][j]] = 0;
//                         board[i][j] = '.';
//                     }
//                     if (!flag && data == 9)
//                         return false;
//                 }
//             }
//         }
//     }
//     return true;
// }
// vector<vector<char>> solveSudoku(vector<vector<char>> &board)
// {
//     unordered_map<int, unordered_map<char, int>> rowMapping;
//     unordered_map<int, unordered_map<char, int>> collMapping;
//     for (int i = 0; i < 9; i++)
//     {
//         for (int j = 0; j < 9; j++)
//         {
//             if (board[i][j] != '.')
//             {
//                 rowMapping[i][board[i][j]] = 1;
//                 collMapping[j][board[i][j]] = 1;
//             }
//         }
//     }
//     solveSudokuRecursive(board, rowMapping, collMapping, 0);
//     return board;
// }
// ------------------------------------------------------------------------------
bool checkInMatrix(vector<vector<char>> &board, int row, int column, char data)
{
    for (int i = row; i < row + 3; i++)
    {
        for (int j = column; j < column + 3; j++)
        {
            if (board[i][j] == data)
                return false;
        }
    }
    return true;
}
bool isPossible(vector<vector<char>> &board, int row, int column, char data)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == data)
            return false;
        if (board[i][column] == data)
            return false;
    }
    if (row >= 0 && row <= 2)
    {
        if (column >= 0 && column <= 2)
            return checkInMatrix(board, 0, 0, data);
        if (column >= 3 && column <= 5)
            return checkInMatrix(board, 0, 3, data);
        if (column >= 6 && column <= 8)
            return checkInMatrix(board, 0, 6, data);
    }
    if (row >= 3 && row <= 5)
    {
        if (column >= 0 && column <= 2)
            return checkInMatrix(board, 3, 0, data);
        if (column >= 3 && column <= 5)
            return checkInMatrix(board, 3, 3, data);
        if (column >= 6 && column <= 8)
            return checkInMatrix(board, 3, 6, data);
    }
    if (row >= 6 && row <= 8)
    {
        if (column >= 0 && column <= 2)
            return checkInMatrix(board, 6, 0, data);
        if (column >= 3 && column <= 5)
            return checkInMatrix(board, 6, 3, data);
        if (column >= 6 && column <= 8)
            return checkInMatrix(board, 6, 6, data);
    }
    return false;
}
bool solveSudokuRecursive(vector<vector<char>> &board, int row)
{
    for (int i = row; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
            {
                for (int data = 1; data <= 9; data++)
                {
                    if (isPossible(board, i, j, data + 48))
                    {
                        board[i][j] = data + 48;
                        if (solveSudokuRecursive(board, i))
                            return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
vector<vector<char>> solveSudoku(vector<vector<char>> &board)
{
    solveSudokuRecursive(board, 0);
    return board;
}
// -----------------------------------------------------------------
// bool checkInMatrix(vector<vector<char>> &board, int row, int column, char data)
// {
//     for (int i = row; i < row + 3; i++)
//     {
//         for (int j = column; j < column + 3; j++)
//         {
//             if (board[i][j] == data)
//                 return false;
//         }
//     }
//     return true;
// }
// bool isPossible(vector<vector<char>> &board, int row, int column, char data)
// {
//     for (int i = 0; i < 9; i++)
//     {
//         if (board[row][i] == data)
//             return false;
//         if (board[i][column] == data)
//             return false;
//     }
//     if (row >= 0 && row <= 2)
//     {
//         if (column >= 0 && column <= 2)
//             return checkInMatrix(board, 0, 0, data);
//         if (column >= 3 && column <= 5)
//             return checkInMatrix(board, 0, 3, data);
//         if (column >= 6 && column <= 8)
//             return checkInMatrix(board, 0, 6, data);
//     }
//     if (row >= 3 && row <= 5)
//     {
//         if (column >= 0 && column <= 2)
//             return checkInMatrix(board, 3, 0, data);
//         if (column >= 3 && column <= 5)
//             return checkInMatrix(board, 3, 3, data);
//         if (column >= 6 && column <= 8)
//             return checkInMatrix(board, 3, 6, data);
//     }
//     if (row >= 6 && row <= 8)
//     {
//         if (column >= 0 && column <= 2)
//             return checkInMatrix(board, 6, 0, data);
//         if (column >= 3 && column <= 5)
//             return checkInMatrix(board, 6, 3, data);
//         if (column >= 6 && column <= 8)
//             return checkInMatrix(board, 6, 6, data);
//     }
//     return false;
// }
// bool solveSudokuRecursiveOtherWay(vector<vector<char>> &board, int row)
// {
//     for (int i = row; i < 9; i++)
//     {
//         for (int j = 0; j < 9; j++)
//         {
//             if (board[i][j] == '.')
//             {
//                 for (char data = '1'; data <= '9'; data++)
//                 {
//                     if (isPossible(board, i, j, data))
//                     {
//                         board[i][j] = data;
//                         if (solveSudokuRecursiveOtherWay(board, i))
//                             return true;
//                         board[i][j] = '.';
//                     }
//                 }
//                 return false;
//             }
//         }
//     }
//     return true;
// }
// vector<vector<char>> solveSudokuOtherWay(vector<vector<char>> &board)
// {
//     solveSudokuRecursiveOtherWay(board, 0);
//     return board;
// }
// int main()
// {
//     cout << string(30, '-') << endl;
//     // vector<vector<char>> board = {{'5', '3', '.', '6', '7', '8', '9', '.', '2'},
//     //                               {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
//     //                               {'.', '9', '8', '3', '4', '2', '5', '6', '7'},
//     //                               {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
//     //                               {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
//     //                               {'7', '1', '3', '9', '.', '4', '8', '5', '6'},
//     //                               {'9', '6', '.', '5', '3', '7', '2', '8', '4'},
//     //                               {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
//     //                               {'3', '4', '5', '2', '8', '6', '1', '7', '9'}};
//     vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
//                                   {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
//                                   {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
//                                   {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
//                                   {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
//                                   {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
//                                   {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
//                                   {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
//                                   {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
//     solveSudoku(board);
//     cout << string(30, '-') << endl;
// }
// -------------------------------------------------------------------- Matchsticks to Square ----------------------------------------------------------------
// ---------------- Wrong Answer ------------------
// bool RecursiveMatchstickToSquare(int index, vector<int> &matchsticks, vector<int> &isMatchStickUsed, int &numberOfSides, int sideSum, int n, int targetOneSideValue)
// {
//     if (sideSum == targetOneSideValue)
//     {
//         numberOfSides++;
//         return true;
//     }
//     if (sideSum > targetOneSideValue)
//         return false;
//     for (int i = index; i < n; i++)
//     {
//         if (!isMatchStickUsed[i])
//         {
//             sideSum += matchsticks[i];
//             isMatchStickUsed[i] = 1;
//             if (RecursiveMatchstickToSquare(i + 1, matchsticks, isMatchStickUsed, numberOfSides, sideSum, n, targetOneSideValue))
//                 return true;
//             sideSum -= matchsticks[i];
//             isMatchStickUsed[i] = 0;
//         }
//     }
//     return false;
// }
// bool MatchstickToSquare(vector<int> matchsticks)
// {
// int n = matchsticks.size();
// if (n < 4)
//     return false;
// int totalMatchSticksSum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
// if (totalMatchSticksSum % 4 != 0)
//     return false;
// sort(matchsticks.begin(), matchsticks.end(), greater<int>());
// vector<int> isMatchStickUsed(n, 0);
// int numberOfSides = 0;
// int targetOneSideValue = totalMatchSticksSum / 4;
//     for (int index = 0; index < n; index++)
//         if (!isMatchStickUsed[index])
//         {
//             RecursiveMatchstickToSquare(index, matchsticks, isMatchStickUsed, numberOfSides, 0, n, targetOneSideValue);
//         }
//     if (numberOfSides == 4)
//         return true;
//     return false;
// }
// ------------------- TLE -------------------------
bool RecursiveMatchstickToSquare(vector<int> &matchsticks, vector<int> &sides, int targetIndex)
{
    if (targetIndex == matchsticks.size())
    {
        if (sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3])
        {
            return true;
        }
        return false;
    }
    for (int i = 0; i < 4; i++)
    {
        sides[i] += matchsticks[targetIndex];
        if (RecursiveMatchstickToSquare(matchsticks, sides, targetIndex + 1))
            return true;
        sides[i] -= matchsticks[targetIndex];
    }
    return false;
}
bool MatchstickToSquare(vector<int> matchsticks)
{
    int n = matchsticks.size();
    if (n < 4)
        return false;
    int totalMatchSticksSum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
    if (totalMatchSticksSum % 4 != 0)
        return false;
    vector<int> sides(4, 0);
    RecursiveMatchstickToSquare(matchsticks, sides, 0);
    return false;
}
// ---------------------------------------------
bool RecursiveMatchstickToSquareOtherWay(vector<int> &matchsticks, vector<int> &sides, int targetIndex, int targetOneSideValue)
{
    if (targetIndex == matchsticks.size())
    {
        if (sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3])
        {
            return true;
        }
        return false;
    }
    for (int i = 0; i < 4; i++)
    {
        if (sides[i] + matchsticks[targetIndex] > targetOneSideValue)
            continue;
        sides[i] += matchsticks[targetIndex];
        if (RecursiveMatchstickToSquareOtherWay(matchsticks, sides, targetIndex + 1, targetOneSideValue))
            return true;
        sides[i] -= matchsticks[targetIndex];
    }
    return false;
}
bool MatchstickToSquareOtherWay(vector<int> matchsticks)
{
    int n = matchsticks.size();
    if (n < 4)
        return false;
    int totalMatchSticksSum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
    int targetOneSideValue = totalMatchSticksSum / 4;
    if (totalMatchSticksSum % 4 != 0)
        return false;
    sort(matchsticks.begin(), matchsticks.end(), greater<int>());
    if (matchsticks[0] > targetOneSideValue)
        return false;
    vector<int> sides(4, 0);
    return RecursiveMatchstickToSquareOtherWay(matchsticks, sides, 0, targetOneSideValue);
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     // vector<int> matchsticks = {13, 11, 1, 8, 6, 7, 8, 8, 6, 7, 8, 9, 8};
//     vector<int> matchsticks = {1, 1, 2, 2, 2};
//     cout << MatchstickToSquare(matchsticks) << endl;
//     cout << string(30, '-') << endl;
// }
// ------------------------------------------------------- Dynamic Programming: Introduction -----------------------------------------------------------
// ----------- Memoisation ------------
int recursivefibonacci(int n, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (n == 1)
    {
        dp[n] = 1;
        return 1;
    }
    if (dp[n] != 0)
        return dp[n];
    dp[n] = recursivefibonacci(n - 1, dp) + recursivefibonacci(n - 2, dp);
    return dp[n];
}
int fibonacci(int n)
{
    vector<int> dp(n + 1, 0);
    return recursivefibonacci(n, dp);
}
int fibonacciUsingDp(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     cout << fibonacciUsingDp(4) << endl;
//     cout << string(35, '-') << endl;
//     return 0;

// }
// ------------------------------------------------------------- 0/1 Knapsack -------------------------------------------------------------------
// ------------ Wrong Code -----------
// class valueComparator
// {
// public:
//     bool operator()(pair<int, int> pairA, pair<int, int> pairB)
//     {
//         return pairA.second > pairB.second;
//     }
// };
// int FindMaxKnapsackProfit(int capacity, vector<int> weights, vector<int> values)
// {
// vector<pair<int, int>> weightValuePair;
// for (int i = 0; i < weights.size(); i++)
//     weightValuePair.push_back(pair<int, int>(weights[i], values[i]));
// sort(weightValuePair.begin(), weightValuePair.end(), valueComparator());
// int maxPossibleValue = 0;
// int currentCapacity = 0;
// for (int i = 0; i < weightValuePair.size(); i++)
// {
//     if (currentCapacity + weightValuePair[i].first <= capacity)
//     {
//         currentCapacity += weightValuePair[i].first;
//         maxPossibleValue += weightValuePair[i].second;
//     }
//     else if (weightValuePair[i].first <= capacity && maxPossibleValue < weightValuePair[i].second)
//     {
//         currentCapacity = weightValuePair[i].first;
//         maxPossibleValue = weightValuePair[i].second;
//     }
// }
// return maxPossibleValue;
// }
// --------------- Wrong Code --------------
// int recursiveFindMaxKnapsackProfit(int capacity, vector<int> &weights, vector<int> &values, int index, int currentCapacity, int maxPossibleValue)
// {
//     for (int i = index; i < weights.size(); i++)
//     {
//         if (currentCapacity + weights[i] > capacity)
//             continue;
//         maxPossibleValue += values[i];
//         currentCapacity += weights[i];
//         int smallAnswer = recursiveFindMaxKnapsackProfit(capacity, weights, values, i, currentCapacity, maxPossibleValue);
//         if (smallAnswer > maxPossibleValue)
//             maxPossibleValue = smallAnswer;
//     }
//     return maxPossibleValue;
// }
// int FindMaxKnapsackProfit(int capacity, vector<int> &weights, vector<int> &values)
// {
//     int n = weights.size();
//     int maxPossibleValue = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int smallAnswer = recursiveFindMaxKnapsackProfit(capacity, weights, values, i, 0, 0);
//         if (smallAnswer > maxPossibleValue)
//             maxPossibleValue = smallAnswer;
//     }
//     return maxPossibleValue;
// }
// ----------------------------------------------------------------
int FindMaxKnapsackProfitRecursive(int capacity, vector<int> &weights, vector<int> &values, int index)
{
    if (index == 0)
    {
        if (weights[index] <= capacity)
            return values[0];
        else
            return 0;
    }
    int notPick = 0 + FindMaxKnapsackProfitRecursive(capacity, weights, values, index - 1);
    int pick = INT_MIN;
    if (weights[index] < capacity)
    {
        pick = values[index] + FindMaxKnapsackProfitRecursive(capacity - weights[index], weights, values, index - 1);
    }
    return max(pick, notPick);
}
int FindMaxKnapsackProfit(int capacity, vector<int> &weights, vector<int> &values)
{
    int n = weights.size();
    int maxPossibleValue = FindMaxKnapsackProfitRecursive(capacity, weights, values, n - 1);
    return maxPossibleValue;
}
// -------------- Using DP ------------------
int FindMaxKnapsackProfitRecursiveDP(int capacity, vector<int> &weights, vector<int> &values, int index, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (weights[index] <= capacity)
            return values[0];
        else
            return 0;
    }
    if (dp[index][capacity] != -1)
        return dp[index][capacity];
    int notPick = 0 + FindMaxKnapsackProfitRecursiveDP(capacity, weights, values, index - 1, dp);
    int pick = INT_MIN;
    if (weights[index] <= capacity)
    {
        pick = values[index] + FindMaxKnapsackProfitRecursiveDP(capacity - weights[index], weights, values, index - 1, dp);
    }
    return dp[index][capacity] = max(pick, notPick);
}
int FindMaxKnapsackProfitUsingDp(int capacity, vector<int> &weights, vector<int> &values)
{
    int n = weights.size();
    int m = capacity + 1;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maxPossibleValue = FindMaxKnapsackProfitRecursiveDP(capacity, weights, values, n - 1, dp);
    return maxPossibleValue;
}
// ---------------------------
int FindMaxKnapsackProfitUsingTabulation(int capacity, vector<int> &weights, vector<int> &values)
{
    int n = weights.size();
    int m = capacity + 1;
    // Create a 2D DP table with dimensions n x W+1 and initialize it with zeros
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
    // Base condition: Fill in the first row for the weight of the first item
    for (int i = weights[0]; i <= capacity; i++)
    {
        dp[0][i] = values[0];
    }
    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++)
    {
        for (int cap = 0; cap <= capacity; cap++)
        {
            // Calculate the maximum value by either excluding the current item or including it
            int notTaken = dp[ind - 1][cap];
            int taken = INT_MIN;
            // Check if the current item can be included without exceeding the knapsack's capacity
            if (weights[ind] <= cap)
            {
                taken = values[ind] + dp[ind - 1][cap - weights[ind]];
            }
            // Update the DP table
            dp[ind][cap] = max(notTaken, taken);
        }
    }
    // The final result is in the last cell of the DP table
    return dp[n - 1][capacity];
}
// -------------- Using DP ------------------
int FindMaxKnapsackProfitRecursiveDPOtherWay(int capacity, vector<int> &weights, vector<int> &values, int index, vector<vector<int>> &dp)
{
    if (index == weights.size() - 1)
    {
        if (weights[index] <= capacity)
            return values[weights.size() - 1];
        else
            return 0;
    }
    if (dp[index][capacity] != -1)
        return dp[index][capacity];
    int notPick = 0 + FindMaxKnapsackProfitRecursiveDPOtherWay(capacity, weights, values, index + 1, dp);
    int pick = INT_MIN;
    if (weights[index] <= capacity)
    {
        pick = values[index] + FindMaxKnapsackProfitRecursiveDPOtherWay(capacity - weights[index], weights, values, index + 1, dp);
    }
    return dp[index][capacity] = max(pick, notPick);
}
int FindMaxKnapsackProfitUsingDpOtherWay(int capacity, vector<int> &weights, vector<int> &values)
{
    int n = weights.size();
    int m = capacity + 1;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maxPossibleValue = FindMaxKnapsackProfitRecursiveDPOtherWay(capacity, weights, values, 0, dp);
    return maxPossibleValue;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     int capacity = 10;
//     vector<int> weights = {3, 6, 10, 7, 2};
//     vector<int> values = {12, 10, 15, 17, 13};
//     cout << FindMaxKnapsackProfitUsingDpOtherWay(capacity, weights, values) << endl;
//     cout << string(35, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------------------ Coin Change ----------------------------------------------------------------------------
// ------------------------ TLE ----------------------------
// void FindCoinChangeRecursive(vector<int> &coins, int total, int currentSum, int currCoinCount, int &minimumCoinCount)
// {
//     if (currentSum == total && currCoinCount < minimumCoinCount)
//     {
//         minimumCoinCount = currCoinCount;
//         return;
//     }
//     for (int i = 0; i < coins.size(); i++)
//     {
//         cout << i << endl;
//         if (currentSum + coins[i] <= total)
//         {
//             FindCoinChangeRecursive(coins, total, currentSum + coins[i], currCoinCount + 1, minimumCoinCount);
//         }
//         else
//         {
//             break;
//         }
//     }
// }
// int FindCoinChange(vector<int> &coins, int total)
// {
//     if (total == 0)
//         return total;
//     int minimumCoinCount = INT_MAX;
//     sort(coins.begin(), coins.end());
//     FindCoinChangeRecursive(coins, total, 0, 0, minimumCoinCount);
//     return (minimumCoinCount != INT_MAX) ? minimumCoinCount : -1;
// }
// --------------------- TLE ----------------------
int FindCoinChangeRecursive(vector<int> &coins, int target, int index)
{
    if (index == 0)
    {
        if (target % coins[index] == 0)
            return target / coins[index];
        else
            return 1e9;
    }
    int notTake = 0 + FindCoinChangeRecursive(coins, target, index - 1);
    int take = INT_MAX;
    if (coins[index] <= target)
        take = 1 + FindCoinChangeRecursive(coins, target - coins[index], index);
    return min(take, notTake);
}
int FindCoinChange(vector<int> &coins, int target)
{
    int n = coins.size();
    if (!target)
        return target;
    int minimumCoins = FindCoinChangeRecursive(coins, target, n - 1);
    return (minimumCoins > target) ? -1 : minimumCoins;
}
// ------------------ USING DP -----------------
int FindCoinChangeRecursiveDP(vector<int> &coins, int target, int index, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (target % coins[index] == 0)
            return target / coins[index];
        else
            return 1e9;
    }
    if (dp[index][target] != -1)
        return dp[index][target];
    int notTake = 0 + FindCoinChangeRecursiveDP(coins, target, index - 1, dp);
    int take = INT_MAX;
    if (coins[index] <= target)
        take = 1 + FindCoinChangeRecursiveDP(coins, target - coins[index], index, dp);
    return dp[index][target] = min(take, notTake);
}
int FindCoinChangeDP(vector<int> &coins, int target)
{
    int n = coins.size();
    int m = target + 1;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    if (!target)
        return target;
    int minimumCoins = FindCoinChangeRecursiveDP(coins, target, n - 1, dp);
    return (minimumCoins > target) ? -1 : minimumCoins;
}
// ------------------ USING TABULATION -----------------
int FindCoinChangeTabulation(vector<int> &coins, int target)
{
    int n = coins.size();
    int m = target + 1;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int T = 0; T <= target; T++)
    {
        if (T % coins[0] == 0)
            dp[0][T] = T / coins[0];
        else
            dp[0][T] = 1e9;
    }
    for (int index = 1; index < n; index++)
    {
        for (int T = 0; T <= target; T++)
        {
            int notTake = 0 + dp[index - 1][T];
            int take = INT_MAX;
            if (coins[index] <= T)
                take = 1 + dp[index][T - coins[index]];
            dp[index][T] = min(take, notTake);
        }
    }
    int result = dp[n - 1][target];
    if (result > target)
        return -1;
    return result;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     // vector<int> coins = {1, 2, 5};
//     vector<int> coins = {1, 3, 4, 5};
//     cout << FindCoinChangeTabulation(coins, 7) << endl;
//     cout << string(35, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------------------ Coin Change - 2 ----------------------------------------------------------------------------
// ---------------- Using DP-------------------
int coinChange2Recursive(int target, vector<int> &coins, int index, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (target % coins[index] == 0)
            return 1;
        return 0;
    }
    if (dp[index][target] != -1)
        return dp[index][target];
    int notTake = coinChange2Recursive(target, coins, index - 1, dp);
    int take = 0;
    if (coins[index] <= target)
        take = coinChange2Recursive(target - coins[index], coins, index, dp);
    return notTake + take;
}
int coinChange2(int target, vector<int> &coins)
{
    int n = coins.size();
    int m = target + 1;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    if (!target)
        return 1;
    return coinChange2Recursive(target, coins, n - 1, dp);
}
// ------------ USING TABULATION ------------
int coinChange2Tabulation(int target, vector<int> &coins)
{
    int n = coins.size();
    int m = target + 1;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int T = 0; T <= target; T++)
    {
        if (T % coins[0] == 0)
            dp[0][T] = 1;
        else
            dp[0][T] = 0;
    }
    for (int index = 1; index < n; index++)
    {
        for (int T = 0; T <= target; T++)
        {
            int notTake = dp[index - 1][T];
            int take = 0;
            if (coins[index] <= T)
                take = dp[index][T - coins[index]];
            dp[index][T] = notTake + take;
        }
    }
    return dp[n - 1][target];
}
// -----------------------------------------------------
int coinChange2OtherWayDP(vector<int> &coins, vector<vector<int>> &dp, int target, int index, int n)
{
    if (index == n - 1)
    {
        if (target % coins[index] == 0)
            return 1;
        return 0;
    }
    if (dp[index][target] != -1)
        return dp[index][target];
    int notTake = coinChange2OtherWayDP(coins, dp, target, index + 1, n);
    int take = 0;
    if (coins[index] <= target)
        take = coinChange2OtherWayDP(coins, dp, target - coins[index], index, n);
    return notTake + take;
}
int coinChange2OtherWay(vector<int> &coins, int target)
{
    int n = coins.size();
    int m = target + 1;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return coinChange2OtherWayDP(coins, dp, target, 0, n);
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> coins = {1, 2, 5};
//     cout << coinChange2Tabulation(5, coins) << endl;
//     cout << string(35, '-') << endl;
//     return 0;
// }
// -------------------------------------------------------- N-th Tribonacci Number -----------------------------------------------------
// ---------- TLE ------------
int FindTribonacci(int n)
{
    if (n == 0 || n == 1 || n == 2)
        return n;
    return FindTribonacci(n - 1) + FindTribonacci(n - 2) + FindTribonacci(n - 3);
}
// ----------- USING DP --------------
int FindTribonacciRecursive(int n, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    dp[n - 1] = FindTribonacciRecursive(n - 1, dp);
    dp[n - 2] = FindTribonacciRecursive(n - 2, dp);
    dp[n - 3] = FindTribonacciRecursive(n - 3, dp);
    return dp[n] = dp[n - 1] + dp[n - 2] + dp[n - 3];
}
int FindTribonacciDP(int n)
{
    if (n == 0 || n == 1)
        return n;
    if (n == 2)
        return 1;
    vector<int> dp(n + 1, -1);
    FindTribonacciRecursive(n, dp);
    return dp[n];
}
// ----------------- USING TABULATION -----------------
int FindTribonacciTabulation(int n)
{
    if (n == 0 || n == 1)
        return n;
    if (n == 2)
        return 1;
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for (int index = 3; index <= n; index++)
        dp[index] = dp[index - 1] + dp[index - 2] + dp[index - 3];
    return dp[n];
}
// ------------ Iterative ---------------
int FindTribonacciIterative(int n)
{
    if (n < 3)
        return n == 0 ? 0 : 1;
    int temp = 0, firstNum = 0;
    int secondNum = 1, thirdNum = 1;
    for (int i = 3; i <= n; i++)
    {
        temp = firstNum + secondNum + thirdNum;
        firstNum = secondNum;
        secondNum = thirdNum;
        thirdNum = temp;
    }
    return thirdNum;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     cout << FindTribonacciIterative(4) << endl;
//     cout << string(35, '-') << endl;
// }
// ---------------------------------------------------------------- Partition Equal Subset Sum ---------------------------------------------------------------------
// ----------------------- (TLE) -------------------------
bool CanPartitionArrayRecursive(vector<int> &arr, int targetSum, int index, int n)
{
    if (targetSum == 0)
        return true;
    if (index == n - 1)
    {
        if (targetSum == arr[index - 1])
            return true;
        return false;
    }
    bool notTake = CanPartitionArrayRecursive(arr, targetSum, index + 1, n);
    bool take = false;
    if (targetSum - arr[index] >= 0)
        take = CanPartitionArrayRecursive(arr, targetSum - arr[index], index + 1, n);
    if (take == true || notTake == true)
        return true;
    return false;
}
bool CanPartitionArray(vector<int> arr)
{
    int n = arr.size();
    int totalArraySum = accumulate(arr.begin(), arr.end(), 0);
    if (totalArraySum % 2 != 0)
        return false;
    int targetSum = totalArraySum / 2;
    return CanPartitionArrayRecursive(arr, targetSum, 0, n);
}
// ------------------------ OTHER WAY (TLE) --------------------------
bool CanPartitionArrayRecursiveOtherWay(vector<int> &arr, int targetSum, int index)
{
    if (targetSum == 0)
        return true;
    if (index == 0)
    {
        if (targetSum == arr[index])
            return true;
        return false;
    }
    bool notTake = CanPartitionArrayRecursiveOtherWay(arr, targetSum, index - 1);
    bool take = false;
    if (targetSum - arr[index] >= 0)
        take = CanPartitionArrayRecursiveOtherWay(arr, targetSum - arr[index], index - 1);
    return take || notTake;
}
bool CanPartitionArrayOtherWay(vector<int> arr)
{
    int n = arr.size();
    int totalArraySum = accumulate(arr.begin(), arr.end(), 0);
    if (totalArraySum % 2 != 0)
        return false;
    int targetSum = totalArraySum / 2;
    return CanPartitionArrayRecursiveOtherWay(arr, targetSum, n - 1);
}
// --------------------------------- MEMOIZATION ------------------------------------
bool CanPartitionArrayRecursiveOtherWay(vector<int> &arr, int targetSum, int index, vector<vector<int>> &dp)
{
    if (targetSum == 0)
        return true;
    if (index == 0)
    {
        if (targetSum == arr[index])
            return true;
        return false;
    }
    if (dp[index][targetSum] != -1)
        return dp[index][targetSum];
    bool notTake = CanPartitionArrayRecursiveOtherWay(arr, targetSum, index - 1, dp);
    bool take = false;
    if (targetSum - arr[index] >= 0)
        take = CanPartitionArrayRecursiveOtherWay(arr, targetSum - arr[index], index - 1, dp);
    return dp[index][targetSum] = take || notTake;
}
bool CanPartitionArrayOtherWayMemoization(vector<int> arr)
{
    int n = arr.size();
    if (n == 1)
        return false;
    int totalArraySum = accumulate(arr.begin(), arr.end(), 0);
    if (totalArraySum % 2 != 0)
        return false;
    int targetSum = totalArraySum / 2;
    vector<vector<int>> dp(n, vector<int>(targetSum + 1, -1));
    CanPartitionArrayRecursiveOtherWay(arr, targetSum, n - 1, dp);
    return dp[n - 1][targetSum];
}
// ----------------------------------- TABULATION ------------------------------------------
bool CanPartitionArrayTabulation(vector<int> arr)
{
    int n = arr.size();
    if (n == 1)
        return false;
    int totalArraySum = accumulate(arr.begin(), arr.end(), 0);
    if (totalArraySum % 2 != 0)
        return false;
    int targetSum = totalArraySum / 2;
    vector<vector<bool>> dp(n, vector<bool>(targetSum + 1, false));
    for (int index = 0; index < n; index++)
        dp[index][0] = true;
    if (arr[0] == targetSum)
        dp[0][arr[0]] = true;
    for (int index = 1; index < n; index++)
    {
        for (int target = 1; target <= targetSum; target++)
        {
            int notTake = dp[index - 1][target];
            int take = false;
            if (target >= arr[index]) // target - arr[index] >= 0
                take = dp[index - 1][target - arr[index]];
            dp[index][target] = notTake || take;
        }
    }
    return dp[n - 1][targetSum];
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     // vector<int> arr = {1, 6, 20, 7, 8};
//     // vector<int> arr = {1, 2, 5};
//     vector<int> arr = {99, 1};
//     cout << CanPartitionArrayOtherWay(arr) << endl;
//     cout << string(35, '-') << endl;
// }
// ------------------------------------------------------------------- Counting Bits ---------------------------------------------------------------------
int CountingBitsRecustive(int target, vector<int> &result)
{
    if (target == 0)
        return 0;
    int smallAnswer = 0;
    if (target % 2 == 1)
        smallAnswer = 1 + CountingBitsRecustive(target / 2, result);
    else
        smallAnswer = 0 + CountingBitsRecustive(target / 2, result);
    result[target] = smallAnswer;
    return smallAnswer;
}
vector<int> CountingBits(int n)
{
    vector<int> result(n + 1, 0);
    for (int target = n; target >= 0; target--)
    {
        if (result[target] == 0)
            CountingBitsRecustive(target, result);
    }
    return result;
}
// ------------------ MEMOIZATION ------------------
int CountingBitsRecustive(int target, vector<int> &result, vector<int> &dp)
{
    if (target == 0)
        return 0;
    if (dp[target] != -1)
        return dp[target];
    int smallAnswer = 0;
    if (target % 2 == 1)
        smallAnswer = 1 + CountingBitsRecustive(target / 2, result, dp);
    else
        smallAnswer = 0 + CountingBitsRecustive(target / 2, result, dp);
    result[target] = smallAnswer;
    return dp[target] = smallAnswer;
}
vector<int> CountingBitsMemoization(int n)
{
    vector<int> result(n + 1, 0);
    vector<int> dp(n + 1, -1);
    for (int target = n; target >= 0; target--)
    {
        if (dp[target] == -1)
            CountingBitsRecustive(target, result, dp);
    }
    return result;
}
// ---------------------- TABULATION -----------------------
vector<int> CountingBitsMemoizationTabulation(int n)
{
    vector<int> result(n + 1, 0);
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for (int target = 1; target <= n; target++)
    {
        int smallAnswer = 0;
        if (target % 2 == 1)
            smallAnswer = 1 + dp[target / 2];
        else
            smallAnswer = 0 + dp[target / 2];
        dp[target] = smallAnswer;
        result[target] = smallAnswer;
    }
    return result;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> result = CountingBitsMemoizationTabulation(5);
//     for (auto item : result)
//         cout << item << ", ";
//     cout << endl;
//     cout << string(35, '-') << endl;
// }
// --------------------------------------------------------------- 01 Matrix -------------------------------------------------------------------------
// -------------------- SOMETHING IS WRONG IN THE CODE ---------------------
int UpdateMatrixRecursive(int row, int column, vector<vector<int>> &matrix, vector<vector<int>> &isVisited)
{
    if (row < 0 || row > matrix.size() - 1 || column < 0 || column > matrix[0].size() - 1)
        return 1e9;
    if (matrix[row][column] == 0)
        return 0;
    if (isVisited[row][column])
        return 1e9;
    isVisited[row][column] = 1;
    int top = UpdateMatrixRecursive(row - 1, column, matrix, isVisited);
    int down = UpdateMatrixRecursive(row + 1, column, matrix, isVisited);
    int left = UpdateMatrixRecursive(row, column - 1, matrix, isVisited);
    int right = UpdateMatrixRecursive(row, column + 1, matrix, isVisited);
    matrix[row][column] = min(right, min(left, min(top, down))) + 1;
    return matrix[row][column];
}
vector<vector<int>> UpdateMatrix2(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> isVisited(n, vector<int>(m, 0));
    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < m; column++)
        {
            if (matrix[row][column] != 0)
                UpdateMatrixRecursive(row, column, matrix, isVisited);
        }
    }
    return matrix;
}
// ----------------- WRONG ANSWER -----------------
int UpdateMatrixRecursiveOtherWay(int row, int column, vector<vector<int>> &matrix, vector<vector<int>> &isVisited)
{
    if (row < 0 || row > matrix.size() - 1 || column < 0 || column > matrix[0].size() - 1)
        return 1e9;
    if (matrix[row][column] == 0)
        return 0;
    if (isVisited[row][column])
        return 1e9;
    isVisited[row][column] = 1;
    int top = UpdateMatrixRecursiveOtherWay(row - 1, column, matrix, isVisited);
    int down = UpdateMatrixRecursiveOtherWay(row + 1, column, matrix, isVisited);
    int left = UpdateMatrixRecursiveOtherWay(row, column - 1, matrix, isVisited);
    int right = UpdateMatrixRecursiveOtherWay(row, column + 1, matrix, isVisited);
    return min(right, min(left, min(top, down))) + 1;
}
vector<vector<int>> UpdateMatrixOtherWay(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> result(matrix);
    vector<vector<int>> isVisited(n, vector<int>(m, 0));
    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < m; column++)
        {
            if (matrix[row][column] != 0)
                result[row][column] = UpdateMatrixRecursiveOtherWay(row, column, matrix, isVisited);
        }
    }
    return result;
}
// ------------------ USING BFS (RIGHT ANSWER) ------------------
vector<vector<int>> UpdateMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> distance(n, vector<int>(m, 0));
    vector<vector<int>> isVisited(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> que;
    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < m; column++)
        {
            if (matrix[row][column] == 0)
            {
                que.push(pair<pair<int, int>, int>{{row, column}, 0});
                isVisited[row][column] = 1;
            }
        }
    }
    int delRow[] = {-1, 1, 0, 0};
    int delColumn[] = {0, 0, 1, -1};
    while (!que.empty())
    {
        int row = que.front().first.first;
        int column = que.front().first.second;
        int steps = que.front().second;
        que.pop();
        distance[row][column] = steps;
        for (int i = 0; i < 4; i++)
        {
            int neighbourRow = row + delRow[i];
            int neighbourColumn = column + delColumn[i];
            if (neighbourRow >= 0 && neighbourRow < n && neighbourColumn >= 0 && neighbourColumn < m && isVisited[neighbourRow][neighbourColumn] == 0)
            {
                que.push(pair<pair<int, int>, int>{{neighbourRow, neighbourColumn}, steps + 1});
                isVisited[neighbourRow][neighbourColumn] = 1;
            }
        }
    }
    return distance;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<vector<int>> matrix = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
//     vector<vector<int>> result = {{1, 0, 1, 1, 0, 0, 1, 0, 0, 1},
//                                   {0, 1, 1, 0, 1, 0, 1, 0, 1, 1},
//                                   {0, 0, 1, 0, 1, 0, 0, 1, 0, 0},
//                                   {1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
//                                   {0, 1, 0, 1, 1, 0, 0, 0, 0, 1},
//                                   {0, 0, 1, 0, 1, 1, 1, 0, 1, 0},
//                                   {0, 1, 0, 1, 0, 1, 0, 0, 1, 1},
//                                   {1, 0, 0, 0, 1, 2, 1, 1, 0, 1},
//                                   {2, 1, 1, 1, 1, 2, 1, 0, 1, 0},
//                                   {3, 2, 2, 1, 0, 1, 0, 0, 1, 1}};
//     vector<vector<int>>
//         matrixx = {{1, 0, 1, 1, 0, 0, 1, 0, 0, 1},
//                    {0, 1, 1, 0, 1, 0, 1, 0, 1, 1},
//                    {0, 0, 1, 0, 1, 0, 0, 1, 0, 0},
//                    {1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
//                    {0, 1, 0, 1, 1, 0, 0, 0, 0, 1},
//                    {0, 0, 1, 0, 1, 1, 1, 0, 1, 0},
//                    {0, 1, 0, 1, 0, 1, 0, 0, 1, 1},
//                    {1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
//                    {1, 1, 1, 1, 1, 1, 1, 0, 1, 0},
//                    {1, 1, 1, 1, 0, 1, 0, 0, 1, 1}};
//     matrix = UpdateMatrix(matrix);
//     for (int row = 0; row < matrix.size(); row++)
//     {
//         for (int column = 0; column < matrix[0].size(); column++)
//         {
//             cout << matrix[row][column] << ", ";
//         }
//         cout << endl;
//     }
//     cout << string(35, '-') << endl;
// }
// ------------------------------------------------------------- House Robber II -----------------------------------------------------------------
int HouseRobberRecursive(vector<int> &money, int index, vector<int> &dp)
{
    if (index == 0)
        return dp[index] = money[index];
    if (index < 0)
        return 0;
    if (dp[index] != -1)
        return dp[index];
    int take = money[index] + HouseRobberRecursive(money, index - 2, dp);
    int notTake = 0 + HouseRobberRecursive(money, index - 1, dp);
    return dp[index] = max(take, notTake);
}
int HouseRobber(vector<int> &money)
{
    int n = money.size();
    if (n == 1)
        return money[0];
    vector<int> moneyA;
    vector<int> moneyB;
    for (int index = 0; index < n; index++)
    {
        if (index != 0)
            moneyA.push_back(money[index]);
        if (index != n - 1)
            moneyB.push_back(money[index]);
    }
    n--;
    vector<int> dp(n, -1);
    int answerA = HouseRobberRecursive(moneyA, n - 1, dp);
    fill(dp.begin(), dp.end(), -1);
    int answerB = HouseRobberRecursive(moneyB, n - 1, dp);
    return max(answerA, answerB);
}
// --------------- TABULATION ------------------
int TabulationHouseRobber(vector<int> &money, int n, vector<int> &dp)
{
    dp[0] = money[0];
    for (int index = 1; index < n; index++)
    {
        int take = money[index];
        if (index > 1)
            take += dp[index - 2];
        int notTake = dp[index - 1];
        dp[index] = max(take, notTake);
    }
    return dp[n - 1];
}
int TabulationHouseRobberOtherway(vector<int> &money, int n, vector<int> &dp)
{
    if (n == 1)
        return money[0];
    if (n == 2)
        return max(money[0], money[1]);
    dp[0] = money[0];
    dp[1] = max(money[0], money[1]);
    for (int index = 2; index < n; index++)
    {
        int take = money[index] + dp[index - 2];
        int notTake = dp[index - 1];
        dp[index] = max(take, notTake);
    }
    return dp[n - 1];
}
int HouseRobberTabulation(vector<int> &money)
{
    int n = money.size();
    if (n == 1)
        return money[0];
    vector<int> moneyA;
    vector<int> moneyB;
    for (int index = 0; index < n; index++)
    {
        if (index != 0)
            moneyA.push_back(money[index]);
        if (index != n - 1)
            moneyB.push_back(money[index]);
    }
    n--;
    vector<int> dp(n, -1);
    int answerA = TabulationHouseRobberOtherway(moneyA, n, dp);
    fill(dp.begin(), dp.end(), -1);
    int answerB = TabulationHouseRobberOtherway(moneyB, n, dp);
    return max(answerA, answerB);
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> money = {1, 3, 1, 3, 100};
//     cout << HouseRobberTabulation(money) << endl;
//     cout << string(35, '-') << endl;
// }
// ---------------------------------------------------------- Maximum Product Subarray ------------------------------------------------------------
// ----------------- WRONG CODE ----------------
// int findProduct(vector<int> &nums, int index)
// {
//     if (nums.size() == 0)
//         return INT_MIN;
//     if (index == 0)
//         return nums[0];
//     return nums[index] * findProduct(nums, index - 1);
// }
// int MaxProduct(std::vector<int> nums)
// {
//     if (nums.size() == 1)
//         return nums[0];
//     vector<pair<vector<int>, int>> numsCopy;
//     vector<int> temp;
//     int negativeCounter = 0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (nums[i] == 0)
//         {
//             numsCopy.push_back(pair<vector<int>, int>{temp, negativeCounter});
//             negativeCounter = 0;
//             temp.clear();
//         }
//         else
//             temp.push_back(nums[i]);
//         if (nums[i] < 0)
//             negativeCounter++;
//     }
//     numsCopy.push_back(pair<vector<int>, int>{temp, negativeCounter});
//     int previousProduct = 0;
//     int currentProduct = 0;
//     for (int i = 0; i < numsCopy.size(); i++)
//     {
//         if (numsCopy[i].second % 2 == 0) // EVEN -Ve NUMBERS
//         {
//             currentProduct = findProduct(numsCopy[i].first, numsCopy[i].first.size() - 1);
//         }
//         else // ODD -Ve NUMBERS
//         {
//             int smallestNegativeIndex = 0;
//             int smallestNegativeValue = INT_MIN;
//             for (int j = 0; j < numsCopy[i].first.size(); j++)
//             {
//                 if (numsCopy[i].first[j] < 0 && numsCopy[i].first[j] >= smallestNegativeValue)
//                 {
//                     smallestNegativeValue = numsCopy[i].first[j];
//                     smallestNegativeIndex = j;
//                 }
//             }
//             vector<int> leftSubArray = {numsCopy[i].first.begin(), numsCopy[i].first.begin() + smallestNegativeIndex};
//             int leftSubArrayProduct = findProduct(leftSubArray, leftSubArray.size() - 1);
//             vector<int> rightSubArray = {numsCopy[i].first.begin() + smallestNegativeIndex, numsCopy[i].first.end()};
//             int rightSubArrayProduct = findProduct(rightSubArray, rightSubArray.size() - 1);
//             currentProduct = max(leftSubArrayProduct, rightSubArrayProduct);
//         }
//         if (currentProduct > previousProduct)
//         {
//             previousProduct = currentProduct;
//             currentProduct = 0;
//         }
//     }
//     return previousProduct;
// }
// ------------------ BRUTEFORCE APPROACH --------------------
// int MaxProduct(std::vector<int> nums)
// {
//     int n = nums.size();
//     int maxProduct = INT_MIN;
//     int currentProduct;
//     for (int i = 0; i < n; i++)
//     {
//         currentProduct = 1;
//         for (int j = i; j < n; j++)
//         {
//             currentProduct *= nums[j];
//             if (maxProduct < currentProduct)
//                 maxProduct = currentProduct;
//         }
//     }
//     return maxProduct;
// }
// ---------------------------------
int subArrayWithMaxProduct(std::vector<int> nums)
{
    int prefixMaxProduct = 1, suffixMaxProduct = 1;
    int result = INT_MIN;
    int n = nums.size();
    for (int index = 0; index < n; index++)
    {
        if (prefixMaxProduct == 0)
            prefixMaxProduct = 1;
        if (suffixMaxProduct == 0)
            suffixMaxProduct = 1;
        prefixMaxProduct = prefixMaxProduct * nums[index];
        suffixMaxProduct = suffixMaxProduct * nums[n - index - 1];
        result = max(result, max(prefixMaxProduct, suffixMaxProduct));
    }
    return result;
}
// ---------------------
int maxProduct(vector<int> &nums)
{
    if (nums.empty())
        return 0;
    int maxSoFar = nums[0];
    int minSoFar = nums[0];
    int result = maxSoFar;
    for (int index = 1; index < nums.size(); index++)
    {
        int current = nums[index];
        int tempMaxSoFar = max(current, max(maxSoFar * current, minSoFar * current));
        minSoFar = min(current, min(maxSoFar * current, minSoFar * current));
        maxSoFar = tempMaxSoFar;
        result = max(maxSoFar, result);
    }
    return result;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     // vector<int> nums = {2, -5, 3, 1, -4, 0, -10, 2};
//     // vector<int> nums = {1, 2, 3, 4};
//     vector<int> nums = {2, 3, -2, 4};
//     // vector<int> nums = {-3, -1, -1};
//     cout << maxProduct(nums) << endl;
//     cout << string(35, '-') << endl;
// }
// ----------------------------------------------------------------- Combination Sum -------------------------------------------------------------------------
void CombinationSumRecursive(vector<vector<int>> &combinations, vector<int> &combintion, int target, int totalSum, int index, vector<int> nums)
{
    if (totalSum > target)
        return;
    if (totalSum == target)
    {
        combinations.push_back(combintion);
        return;
    }
    if (index < 0)
        return;
    CombinationSumRecursive(combinations, combintion, target, totalSum, index - 1, nums); // Not Pick
    combintion.push_back(nums[index]);
    CombinationSumRecursive(combinations, combintion, target, totalSum + nums[index], index, nums); // Pick
    combintion.pop_back();
}
vector<vector<int>> CombinationSum(vector<int> &nums, int target)
{
    vector<vector<int>> combinations;
    vector<int> combination;
    CombinationSumRecursive(combinations, combination, target, 0, nums.size() - 1, nums);
    return combinations;
}
// --------------------
void CombinationSumRecursiveOtherWay(vector<vector<int>> &combinations, vector<int> &combintion, int target, int index, vector<int> nums)
{
    if (target == 0)
    {
        combinations.push_back(combintion);
        return;
    }
    if (index == nums.size())
        return;
    CombinationSumRecursiveOtherWay(combinations, combintion, target, index + 1, nums); // Not Pick
    if (nums[index] <= target)
    {
        combintion.push_back(nums[index]);
        CombinationSumRecursiveOtherWay(combinations, combintion, target - nums[index], index, nums); // Pick
        combintion.pop_back();
    }
}
vector<vector<int>> CombinationSumOtherWay(vector<int> &nums, int target)
{
    vector<vector<int>> combinations;
    vector<int> combination;
    CombinationSumRecursiveOtherWay(combinations, combination, target, 0, nums);
    return combinations;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> nums = {2, 4, 6};
//     vector<vector<int>> combinations = CombinationSumOtherWay(nums, 6);
//     for (int i = 0; i < combinations.size(); i++)
//     {
//         cout << "{ ";
//         for (int j = 0; j < combinations[i].size(); j++)
//         {
//             cout << combinations[i][j] << " ";
//         }
//         cout << "}";
//         cout << endl;
//     }
//     cout << string(35, '-') << endl;
// }
// ----------------------------------------------------------------- 40. Combination Sum II -------------------------------------------------------------------------
// ----------------------- TLE ---------------------------
void combinationSum2Recursion(int index, int target, vector<int> &combination, vector<int> &nums, set<vector<int>> &uniqueCombinations)
{
    if (target == 0)
    {
        uniqueCombinations.insert(combination);
        return;
    }
    if (index == nums.size())
        return;
    combinationSum2Recursion(index + 1, target, combination, nums, uniqueCombinations); // Not Pick
    if (nums[index] <= target)
    {
        combination.push_back(nums[index]);
        combinationSum2Recursion(index + 1, target - nums[index], combination, nums, uniqueCombinations); // Pick
        combination.pop_back();
    }
}
vector<vector<int>> combinationSum_2(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    set<vector<int>> uniqueCombinations;
    vector<int> combination;
    combinationSum2Recursion(0, target, combination, nums, uniqueCombinations);
    return {uniqueCombinations.begin(), uniqueCombinations.end()};
}
// ---------- Wrong Code -----------
// void combinationSum2RecursionOtherWay(int index, int target, vector<int> &combination, vector<vector<int>> &combinations, vector<int> &nums, vector<vector<int>> &dp)
// {
//     if (target == 0)
//     {
//         combinations.push_back(combination);
//         return;
//     }
//     if (index == nums.size())
//         return;
//     if (dp[index][target] != -1)
//         return;
//     combinationSum2RecursionOtherWay(index + 1, target, combination, combinations, nums, dp); // Not Pick
//     if (nums[index] <= target)
//     {
//         dp[index][target] = 1;
//         combination.push_back(nums[index]);
//         combinationSum2RecursionOtherWay(index + 1, target - nums[index], combination, combinations, nums, dp); // Pick
//         combination.pop_back();
//     }
// }
// vector<vector<int>> combinationSum2OtherWay(vector<int> &nums, int target)
// {
//     int n = nums.size();
//     int m = target + 1;
//     // sort(nums.begin(), nums.end());
//     vector<int> combination;
//     vector<vector<int>> combinations;
//     vector<vector<int>> dp(n, vector<int>(m, -1));
//     combinationSum2RecursionOtherWay(0, target, combination, combinations, nums, dp);
//     return combinations;
// }
// --------------------------------------------------
void findCombinations(int index, int target, vector<int> &candidates, vector<vector<int>> &combinations, vector<int> &ds)
{
    if (target == 0)
    {
        combinations.push_back(ds);
        return;
    }
    for (int i = index; i < candidates.size(); i++)
    {
        if (i > index && candidates[i] == candidates[i - 1])
            continue;
        if (candidates[i] > target)
            break;
        ds.push_back(candidates[i]);
        findCombinations(i + 1, target - candidates[i], candidates, combinations, ds);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> combinations;
    vector<int> ds;
    findCombinations(0, target, candidates, combinations, ds);
    return combinations;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> nums = {2, 5, 2, 1, 2};
//     vector<vector<int>> combinations = combinationSum2(nums, 5);
//     for (int i = 0; i < combinations.size(); i++)
//     {
//         cout << "{ ";
//         for (int j = 0; j < combinations[i].size(); j++)
//         {
//             cout << combinations[i][j] << " ";
//         }
//         cout << "}";
//         cout << endl;
//     }
//     cout << string(35, '-') << endl;
// }
// -------------------------------------------------------------------- Word Break -----------------------------------------------------------------------------
// ---------------------- TLE -----------------------------
// bool WordBreakRecursion(int index, string tempWord, string &s, set<string> &ds)
// {
//     if (index == s.size() && tempWord == "")
//         return true;
//     for (int i = index; i < s.size(); i++)
//     {
//         tempWord.push_back(s[i]);
//         if (ds.find(tempWord) != ds.end())
//         {
//             if (WordBreakRecursion(i + 1, "", s, ds))
//                 return true;
//         }
//     }
//     return false;
// }
// bool WordBreak(string s, vector<string> &wordDict)
// {
//     set<string> ds(wordDict.begin(), wordDict.end());
//     string word = "";
//     for (int i = 0; i < s.size(); i++)
//     {
//         word.push_back(s[i]);
//         if (ds.find(word) != ds.end())
//         {
//             if (WordBreakRecursion(i + 1, "", s, ds))
//                 return true;
//         }
//     }
//     return false;
// }
// ------------ TLE ---------------
bool WordBreakRecursion(int index, string &s, set<string> &ds)
{
    if (index == s.size())
        return true;
    for (int i = index; i < s.size(); i++)
    {
        if (ds.find(s.substr(index, i - index + 1)) != ds.end())
        {
            if (WordBreakRecursion(i + 1, s, ds))
                return true;
        }
    }
    return false;
}
bool WordBreak(string s, vector<string> &wordDict)
{
    set<string> ds(wordDict.begin(), wordDict.end());
    for (int i = 0; i < s.size(); i++)
    {
        if (ds.find(s.substr(0, i - 0 + 1)) != ds.end())
        {
            if (WordBreakRecursion(i + 1, s, ds))
                return true;
        }
    }
    return false;
}
// ------------------- MEMOIZATION -----------------
bool WordBreakRecursionMemo(int index, string &s, set<string> &ds, vector<int> &dp)
{
    if (index == s.size())
        return true;
    if (dp[index] != -1)
        return dp[index];
    for (int i = index; i < s.size(); i++)
    {
        if (ds.find(s.substr(index, i - index + 1)) != ds.end())
        {
            if (WordBreakRecursionMemo(i + 1, s, ds, dp))
                return dp[index] = true;
        }
    }
    return dp[index] = false;
}
bool WordBreakMemo(string s, vector<string> &wordDict)
{
    int n = s.size();
    vector<int> dp(n, -1);
    set<string> ds(wordDict.begin(), wordDict.end());
    if (WordBreakRecursionMemo(0, s, ds, dp))
        return true;
    return false;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     string s = "applepenapple";
//     vector<string> wordDict = {"apple", "pen"};
//     cout << WordBreakMemo(s, wordDict) << endl;
//     cout << string(35, '-') << endl;
// }
// --------------------------------------------------------------- Palindromic Substrings ------------------------------------------------------------------
bool isPalindromeString(string &s)
{
    int left = 0;
    int right = s.size() - 1;
    while (left < right)
    {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}
int CountPalindromicSubstrings(string &s)
{
    vector<string> subSets;
    string subSet;
    for (int i = 0; i < s.length(); i++)
    {
        subSet += s[i];
        subSets.push_back(subSet);
        for (int j = i + 1; j < s.length(); j++)
        {
            subSet.push_back(s[j]);
            subSets.push_back(subSet);
        }
        subSet.clear();
    }
    int palindromeSubStringCount = 0;
    for (int i = 0; i < subSets.size(); i++)
    {
        if (isPalindromeString(subSets[i]))
            palindromeSubStringCount++;
    }
    return palindromeSubStringCount;
}
// ---------------------------------------------
int CountPalindromicSubstringsOtherWay(string &s)
{
    string s1, s2;
    int palindromeSubStringCount = 0;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            s1 += s[j];
            s2 = s[j] + s2;
            if (!s1.compare(s2))
            {
                palindromeSubStringCount++;
            }
        }
        s1.clear();
        s2.clear();
    }
    return palindromeSubStringCount;
}
// -------------------------------------------------------
int isPalindromeStringRecursive(int left, int right, string &s)
{
    if (left > right)
        return 1;
    if (s[left] == s[right])
        return isPalindromeStringRecursive(left + 1, right - 1, s);
    return 0;
}
int CountPalindromicSubstrings2(string &s)
{
    int palindromeSubStringCount = 0;
    for (int left = 0; left < s.size(); left++)
    {
        for (int right = left; right < s.size(); right++)
        {
            palindromeSubStringCount += isPalindromeStringRecursive(left, right, s);
        }
    }
    return palindromeSubStringCount;
}
// ----------------- memoization ------------------------
int isPalindromeStringMemoization(int left, int right, string &s, vector<vector<int>> &ds)
{
    if (left > right)
        return 1;
    if (ds[left][right] >= 0)
        return ds[left][right];
    if (s[left] == s[right])
        return ds[left][right] = isPalindromeStringMemoization(left + 1, right - 1, s, ds);
    return ds[left][right] = 0;
}
int CountPalindromicSubstringsMemo(string &s)
{
    int n = s.size();
    vector<vector<int>> ds(n, vector<int>(n, -1));
    int palindromeSubStringCount = 0;
    for (int left = 0; left < s.size(); left++)
    {
        for (int right = left; right < s.size(); right++)
        {
            palindromeSubStringCount += isPalindromeStringMemoization(left, right, s, ds);
        }
    }
    return palindromeSubStringCount;
}
// -------------------------------------- DP ----------------------------------------
int CountPalindromicSubstringsDP(string &s)
{
    int n = s.size();
    vector<vector<int>> ds(n, vector<int>(n, -1));
    int palindromeSubStringCount = 0;
    for (int i = 0; i < n; i++)
    {
        for (int left = 0, right = i; right < n; left++, right++)
        {
            // For 1st Diagonal (For one length strings)
            if (left == right)
                ds[left][right] = 1;
            // For 2nd upper Diagonal (For two length strings)
            else if (left + 1 == right)
                ds[left][right] = s[left] == s[right] ? 1 : 0;
            // For Remaining Diagonals (for all remaining length strings)
            else
                ds[left][right] = s[left] == s[right] ? ds[left + 1][right - 1] : 0;
            palindromeSubStringCount += ds[left][right];
        }
    }
    return palindromeSubStringCount;
}
// -------------------------------------------------
int CountPalindromicSubstringsDPOtherWay(string &s)
{
    int n = s.size();
    int count = 0;
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = true;
        count++;
    }
    for (int i = 0; i < n - 1; i++)
    {
        dp[i][i + 1] = (s[i] == s[i + 1]);
        count += dp[i][i + 1];
    }
    for (int i = 2; i < n; i++)
    {
        for (int left = 0, right = i; right < n; left++, right++)
        {
            dp[left][right] = s[left] == s[right] ? dp[left + 1][right - 1] : 0;
            count += dp[left][right];
        }
    }
    return count;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     string s = "mnm";
//     cout << CountPalindromicSubstringsDPOtherWay(s) << endl;
//     cout << string(35, '-') << endl;
// }
// -------------------------------------------------- 1143. Longest Common Subsequence -------------------------------------------------
void findSubsequences(int index, string &s, string &subSequence, vector<string> &subSequences)
{
    if (index == s.size())
    {
        if (subSequence.size())
            subSequences.push_back(subSequence);
        return;
    }
    findSubsequences(index + 1, s, subSequence, subSequences); // Not Take
    subSequence.push_back(s[index]);
    findSubsequences(index + 1, s, subSequence, subSequences); // Take
    subSequence.pop_back();
}
void findSubSequencesBitManipulation(string &s, vector<string> &subSequences)
{
    int n = s.size();
    for (int num = 0; num < pow(2, n); num++)
    {
        string subSequence;
        for (int i = 0; i < n; i++)
        {
            if (num & (1 << i))
                subSequence += s[i];
        }
        subSequences.push_back(subSequence);
    }
}
int findCountOfLongestSubsequence(vector<string> subsequence1, vector<string> subSequence2)
{
    int longestSubsequenceLength = 0;
    for (int i = 0; i < subsequence1.size(); i++)
    {
        for (int j = 0; j < subSequence2.size(); j++)
        {
            if (!subsequence1[i].compare(subSequence2[j]) && subsequence1[i].length() > longestSubsequenceLength)
                longestSubsequenceLength = subsequence1[i].length();
        }
    }
    return longestSubsequenceLength;
}
int LongestCommonSubsequence(string &str1, string &str2)
{
    vector<string> str1Subsequences;
    vector<string> str2Subsequences;
    string subSequence = "";
    // findSubsequences(0, str1, subSequence, str1Subsequences);
    findSubSequencesBitManipulation(str1, str1Subsequences);
    subSequence.clear();
    // findSubsequences(0, str2, subSequence, str2Subsequences);
    findSubSequencesBitManipulation(str2, str2Subsequences);
    int longestLengthSubsequence = 0;
    if (str1.size() <= str2.size())
        longestLengthSubsequence = findCountOfLongestSubsequence(str1Subsequences, str2Subsequences);
    else
        longestLengthSubsequence = findCountOfLongestSubsequence(str2Subsequences, str1Subsequences);
    return longestLengthSubsequence;
}
// --------------------------------------- MEMOIZATION -----------------------------------------
int LongestCommonSubsequenceRecursion(int index1, string &str1, int index2, string &str2, vector<vector<int>> &ds)
{
    if (index1 < 0 || index2 < 0)
        return 0;
    if (ds[index1][index2] != -1)
        return ds[index1][index2];
    // Match
    if (str1[index1] == str2[index2])
        return ds[index1][index2] = 1 + LongestCommonSubsequenceRecursion(index1 - 1, str1, index2 - 1, str2, ds);
    // Not Match
    return ds[index1][index2] = 0 + max(LongestCommonSubsequenceRecursion(index1 - 1, str1, index2, str2, ds), LongestCommonSubsequenceRecursion(index1, str1, index2 - 1, str2, ds));
}
int LongestCommonSubsequenceWithRecursion(string &str1, string &str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> ds(n, vector<int>(m, -1));
    return LongestCommonSubsequenceRecursion(n - 1, str1, m - 1, str2, ds);
}
// -------------------------------------- Shifting Index With 1 Right In Ds ---------------------------------
int LongestCommonSubsequenceRecursion2(int index1, string &str1, int index2, string &str2, vector<vector<int>> &ds)
{
    if (index1 == 0 || index2 == 0)
        return 0;
    if (ds[index1][index2] != -1)
        return ds[index1][index2];
    // Match
    if (str1[index1 - 1] == str2[index2 - 1])
        return ds[index1][index2] = 1 + LongestCommonSubsequenceRecursion2(index1 - 1, str1, index2 - 1, str2, ds);
    // Not Match
    return ds[index1][index2] = 0 + max(LongestCommonSubsequenceRecursion2(index1 - 1, str1, index2, str2, ds), LongestCommonSubsequenceRecursion2(index1, str1, index2 - 1, str2, ds));
}
int LongestCommonSubsequenceWithRecursion2(string &str1, string &str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> ds(n + 1, vector<int>(m + 1, -1));
    return LongestCommonSubsequenceRecursion2(n, str1, m, str2, ds);
}
// -------------------------------------- TABULATION --------------------------------------
int LongestCommonSubsequenceTabulation(string &str1, string &str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // Match
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            // Not Match
            else
                dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     string str1 = "ace";
//     string str2 = "abcde";
//     cout << LongestCommonSubsequenceTabulation(str1, str2) << endl;
//     cout << string(35, '-') << endl;
// }
// -------------------------------------------------------------- Climbing Stairs --------------------------------------------------------------------
// --------------------- TLE ------------------------
void ClimbStairsRecursion(int n, int &distinctWays)
{
    if (n == 0)
    {
        distinctWays++;
        return;
    }
    if (n < 0)
        return;
    // Take 1 Step
    ClimbStairsRecursion(n - 1, distinctWays);
    // Take 2 Step
    ClimbStairsRecursion(n - 2, distinctWays);
}
int ClimbStairs(int n)
{
    int distinctWays = 0;
    ClimbStairsRecursion(n, distinctWays);
    return distinctWays;
}
// -------------------- MEMOIZATION ------------------------
int ClimbStairsMemoization(int n, vector<int> &dp)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    // Take 1 Step
    // Take 2 Step
    return dp[n] = ClimbStairsMemoization(n - 1, dp) + ClimbStairsMemoization(n - 2, dp);
}
int ClimbStairsMemo(int n)
{
    int distinctWays = 0;
    vector<int> dp(n + 1, -1);
    return ClimbStairsMemoization(n, dp);
}
// ---------------------- TABULATION ----------------------
int ClimbStairsTabulation(int n)
{
    vector<int> dp(n + 1);
    // Base Cases
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        // Take 1 Step + Take 2 Steps
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int main()
{
    cout << string(35, '-') << endl;
    cout << ClimbStairsTabulation(4) << endl;
    cout << string(35, '-') << endl;
}