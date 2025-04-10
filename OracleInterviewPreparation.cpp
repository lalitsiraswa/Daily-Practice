#include <bits/stdc++.h>
using namespace std;

// -------------------------------------------------------------  -------------------------------------------------------------------
int binarysearch(vector<int> &arr, int k)
{
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int element = arr.at(mid);
        if (element == k)
        {
            return mid;
        }
        else if (element < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    cout << string(30, '-') << endl;
    vector<int> nums = {1, 1, 1, 2, 2, 2, 3, 3, 3};
    cout << binarysearch(nums, 7) << endl;
    cout << endl
         << string(30, '-');
}