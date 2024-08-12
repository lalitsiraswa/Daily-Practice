#include <bits/stdc++.h>
using namespace std;
// ------------------------------------------------------------------------ 74. Search a 2D Matrix ------------------------------------------------------------------------------------
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int rowCount = matrix.size();
    int columnCount = matrix[0].size();
    int row = 0;
    while (row < rowCount)
    {
        int minimum = matrix[row][0];
        int maximum = matrix[row][columnCount - 1];
        if (minimum <= target && maximum >= target)
            break;
        row++;
    }
    if (row == rowCount)
        return false;
    int left = 0;
    int right = columnCount - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        int element = matrix[row][middle];
        if (element == target)
            return true;
        else if (element < target)
            left++;
        else
            right--;
    }
    return false;
}
int main()
{
    cout << string(30, '-') << endl;
    // vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    cout << searchMatrix(matrix, 13) << endl;
    cout << endl
         << string(30, '-');
}