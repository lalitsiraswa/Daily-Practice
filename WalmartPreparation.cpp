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
int main()
{
    cout << string(30, '-') << endl;
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    cout << maxSubarraySum(arr) << endl;
    cout << endl
         << string(30, '-') << endl;
    return 1;
}