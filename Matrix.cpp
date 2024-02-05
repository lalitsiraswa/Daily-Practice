#include <bits/stdc++.h>
using namespace std;

// ----------------------------------------------------------------- 766. Toeplitz Matrix ----------------------------------------------------------------
bool isToeplitzMatrix(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    int target = matrix[0][0];
    for (int i = 0; i < m && i < n; i++)
    {
        if (target != matrix[i][i])
            return false;
    }
    for (int column = 1; column < n; column++)
    {
        int row = 0;
        target = matrix[row][column];
        for (int col = column; col < n && row < m; col++)
        {
            if (target != matrix[row++][col])
                return false;
        }
    }
    for (int row = 1; row < m; row++)
    {
        int column = 0;
        target = matrix[row][column];
        for (int r = row; r < m && column < n; r++)
        {
            if (target != matrix[r][column++])
                return false;
        }
    }
    return true;
}
// ----- OtherWay ------
bool isToeplitzMatrixOtherWay(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    for (int row = 1; row < m; row++)
    {
        for (int column = 1; column < n; column++)
        {
            if (matrix[row][column] != matrix[row - 1][column - 1])
                return false;
        }
    }
    return true;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<vector<int>> matrix = {{65, 98, 57}};
//     cout << isToeplitzMatrix(matrix);
//     cout << endl
//          << string(35, '-') << endl;
//     return 0;
// }
// -------------------------------------------------------- 48. Rotate Image ------------------------------------------------------------------
void rotate(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    // for (int row = 0; row < m; row++)
    // {
    //     for (int column = row; column < n; column++)
    //     {
    //         int temp = matrix[row][column];
    //         matrix[row][column] = matrix[column][row];
    //         matrix[column][row] = temp;
    //     }
    // }
    for (int row = 0; row < m; row++)
    {
        for (int column = 0; column <= row; column++)
        {
            int temp = matrix[row][column];
            matrix[row][column] = matrix[column][row];

            matrix[column][row] = temp;
        }
    }
    for (int row = 0; row < m; row++)
    {
        for (int column = 0; column < n / 2; column++)
        {
            int temp = matrix[row][column];
            matrix[row][column] = matrix[row][(n - 1) - column];
            matrix[row][(n - 1) - column] = temp;
        }
    }
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<vector<int>> matrix = {{00, 01, 02, 03}, {10, 11, 12, 13}, {20, 21, 22, 23}, {30, 31, 32, 33}};
//     rotate(matrix);
//     int m = matrix.size();
//     int n = matrix[0].size();
//     for (int row = 0; row < m; row++)
//     {
//         for (int column = 0; column < n; column++)
//         {
//             cout << matrix[row][column] << " ";
//         }
//         cout << endl;
//     }
//     cout << endl
//          << string(35, '-') << endl;
//     return 0;
// }
// ---------------------------------------------------- 73. Set Matrix Zeroes --------------------------------------------------------
void setZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    map<int, vector<int>> positionMap;
    for (int row = 0; row < m; row++)
    {
        for (int column = 0; column < n; column++)
        {
            if (matrix[row][column] == 0)
                positionMap[row].push_back(column);
        }
    }
    for (auto item : positionMap)
    {
        int row = item.first;
        for (int column = 0; column < n; column++)
            matrix[row][column] = 0;
        for (auto column : item.second)
        {
            for (int rw = 0; rw < m; rw++)
                matrix[rw][column] = 0;
        }
    }
}
// ----------------
void setZeroesUsingMatrixCopy(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> matrixCopy = matrix;
    for (int row = 0; row < m; row++)
    {
        for (int column = 0; column < n; column++)
        {
            if (matrix[row][column] == 0)
            {
                for (int rw = 0; rw < m; rw++)
                    matrixCopy[rw][column] = 0;
                for (int col = 0; col < n; col++)
                    matrixCopy[row][col] = 0;
            }
        }
    }
    matrix = matrixCopy;
}
// ----------------
void setZeroesUsingTwoMatrixes(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    vector<int> rowTrack;
    vector<int> columnTrack;
    for (int row = 0; row < m; row++)
    {
        for (int column = 0; column < n; column++)
        {
            if (matrix[row][column] == 0)
            {
                rowTrack.push_back(row);
                columnTrack.push_back(column);
            }
        }
    }
    for (int row : rowTrack)
    {
        for (int column = 0; column < n; column++)
            matrix[row][column] = 0;
    }
    for (int column : columnTrack)
    {
        for (int row = 0; row < m; row++)
            matrix[row][column] = 0;
    }
}
// --------------------------------
void setZeroesOptimizeApproach(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    int col0 = 1;
    for (int row = 0; row < m; row++)
    {
        for (int column = 0; column < n; column++)
        {
            if (matrix[row][column] == 0)
            {
                matrix[row][0] = 0;
                if (column == 0)
                    col0 = 0;
                else
                    matrix[0][column] = 0;
            }
        }
    }
    for (int row = 1; row < m; row++)
    {
        for (int column = 1; column < n; column++)
        {
            if (matrix[row][column] != 0)
            {
                if (matrix[0][column] == 0 || matrix[row][0] == 0)
                {
                    matrix[row][column] = 0;
                }
            }
        }
    }
    if (matrix[0][0] == 0)
    {
        for (int column = 1; column < n; column++)
            matrix[0][column] = 0;
    }
    if (col0 == 0)
    {
        for (int row = 0; row < m; row++)
            matrix[row][0] = 0;
    }
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<vector<int>> matrix = {{1, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {0, 1, 1, 1}};
//     setZeroesOptimizeApproach(matrix);
//     int m = matrix.size();
//     int n = matrix[0].size();
//     for (int row = 0; row < m; row++)
//     {
//         for (int column = 0; column < n; column++)
//         {
//             cout << matrix[row][column] << " ";
//         }
//         cout << endl;
//     }
//     cout << endl
//          << string(35, '-') << endl;
//     return 0;
// }
// ----------------------------------------------------- Rotate Image -------------------------------------------------------------
vector<vector<int>> RotateImage(vector<vector<int>> matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    for (int row = 1; row < m; row++)
    {
        for (int column = 0; column < row; column++)
        {
            int temp = matrix[row][column];
            matrix[row][column] = matrix[column][row];
            matrix[column][row] = temp;
        }
    }
    for (int row = 0; row < m; row++)
    {
        for (int column = 0; column < n / 2; column++)
        {
            int temp = matrix[row][column];
            matrix[row][column] = matrix[row][(n - 1) - column];
            matrix[row][(n - 1) - column] = temp;
        }
    }
    return matrix;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//     matrix = RotateImage(matrix);
//     int m = matrix.size();
//     int n = matrix[0].size();
//     for (int row = 0; row < m; row++)
//     {
//         for (int column = 0; column < n; column++)
//         {
//             cout << matrix[row][column] << " ";
//         }
//         cout << endl;
//     }
//     cout << endl
//          << string(35, '-') << endl;
//     return 0;
// }
// ----------------------------------------------------------------- 54. Spiral Matrix -------------------------------------------------------------------
vector<int> SpiralOrder(vector<vector<int>> matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int topRow = 0, topColumn = n - 1, bottomRow = m - 1, bottomColumn = 0;
    vector<int> result;
    while (topRow <= bottomRow)
    {
        int flag = 0;
        for (int column = bottomColumn; column <= topColumn; column++)
        {
            result.push_back(matrix[topRow][column]);
            flag = 1;
        }
        topRow++;
        if (flag)
        {
            flag = 0;
            for (int row = topRow; row <= bottomRow; row++)
            {
                result.push_back(matrix[row][topColumn]);
                flag = 1;
            }
        }
        topColumn--;
        if (flag)
        {
            flag = 0;
            for (int column = topColumn; column >= bottomColumn; column--)
            {
                result.push_back(matrix[bottomRow][column]);
                flag = 1;
            }
        }
        bottomRow--;
        if (flag)
        {
            for (int row = bottomRow; row >= topRow; row--)
                result.push_back(matrix[row][bottomColumn]);
        }
        bottomColumn++;
    }
    return result;
}
// ----------------------
vector<int> SpiralOrderBestWay(vector<vector<int>> matrix)
{
    vector<int> result;
    int m = matrix.size(), n = matrix[0].size();
    int top = 0, left = 0, bottom = m - 1, right = n - 1;
    while (top <= bottom && left <= right)
    {
        // For moving left to right.
        for (int column = left; column <= right; column++)
            result.push_back(matrix[top][column]);
        top++;
        // For moving top to bottom.
        for (int row = top; row <= bottom; row++)
            result.push_back(matrix[row][right]);
        right--;
        // For moving right to left.
        // Check condition for Case: {{1, 2, 3, 4}}
        if (top <= bottom)
        {
            for (int column = right; column >= left; column--)
                result.push_back(matrix[bottom][column]);
            bottom--;
        }
        // For moving bottom to top.
        if (left <= right)
        {
            for (int row = bottom; row >= top; row--)
                result.push_back(matrix[row][left]);
            left++;
        }
    }
    return result;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     // vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
//     vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
//     vector<int> result = SpiralOrderBestWay(matrix);
//     for (auto item : result)
//         cout << item << " ";
//     cout << endl
//          << string(35, '-') << endl;
//     return 0;
// }
//----------------------------------------------------------------------- Where Will the Ball Fall -------------------------------------------------------------
vector<int> FindExitColumn(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<int> result(n, 0);
    for (int column = 0; column < n; column++)
    {
        int row = 0, col = column;
        while (row < m && col < n && col >= 0)
        {
            if (grid[row][col] == 1)
            {
                if (col < n - 1 && grid[row][col + 1] == -1)
                {
                    result[column] = -1;
                    break;
                }
                else
                {
                    col++;
                    row++;
                }
            }
            else if (grid[row][col] == -1)
            {
                if (col > 0 && grid[row][col - 1] == 1)
                {
                    result[column] = -1;
                    break;
                }
                else
                {
                    col--;
                    row++;
                }
            }
        }
        if (row == m && col >= 0 && col < n)
            result[column] = col;
        else
            result[column] = -1;
    }
    return result;
}
//------------------ DFS ------------------
bool valid(int m, int n, int row, int column)
{
    if (row >= m || column >= n || row < 0 || column < 0)
        return false;
    return true;
}
int dfsCall(vector<vector<int>> &grid, int row, int column)
{
    if (row == grid.size())
        return column;
    if (valid(grid.size(), grid[0].size(), row, column))
    {
        if (grid[row][column] == 1)
        {
            if (valid(grid.size(), grid[0].size(), row, column + 1) && grid[row][column + 1] == 1)
            {
                return dfsCall(grid, row + 1, column + 1);
            }
        }
        else if (grid[row][column] == -1)
        {
            if (valid(grid.size(), grid[0].size(), row, column - 1) && grid[row][column - 1] == -1)
            {
                return dfsCall(grid, row + 1, column - 1);
            }
        }
    }
    return -1;
}
vector<int> FindExitColumnByDfs(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<int> result(n, 0);
    for (int column = 0; column < n; column++)
    {
        result[column] = dfsCall(grid, 0, column);
    }
    return result;
}
int main()
{
    cout << string(35, '-') << endl;
    vector<vector<int>> grid = {{-1, 1, 1, -1, -1, -1}, {-1, -1, 1, 1, 1, 1}, {1, -1, -1, -1, -1, -1}, {1, -1, 1, 1, 1, 1}, {-1, 1, -1, 1, 1, -1}};
    // vector<vector<int>> grid = {{1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}};
    vector<int> result = FindExitColumnByDfs(grid);
    for (auto item : result)
        cout << item << " ";
    cout << endl
         << string(35, '-') << endl;
    return 0;
}