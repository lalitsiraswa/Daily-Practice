#include <bits/stdc++.h>
using namespace std;

// -------------------------------------------------------- Cyclic Sort: Introduction -------------------------------------------------------
void cyclicSort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (i != nums[i] - 1 && nums[i] - 1 < n)
        {
            int temp = nums[i];
            nums[i] = nums[temp - 1];
            nums[temp - 1] = temp;
        }
    }
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> nums = {6, 7, 9, 2, 3, 13, 11};
//     cyclicSort(nums);
//     for (auto item : nums)
//         cout << item << " ";
//     cout << endl;
//     cout << string(35, '-') << endl;
// }
// -------------------------------------------------------- Missing Number -------------------------------------------------------------
int FindMissingNumber(vector<int> nums)
{
    int n = nums.size();
    int i = 0;
    while (i < n)
    {
        if (i == nums[i])
            i++;
        else if (i != nums[i] && nums[i] < n)
        {
            int temp = nums[i];
            nums[i] = nums[temp];
            nums[temp] = temp;
        }
        else
            i++;
    }
    for (int i = 0; i < n; i++)
    {
        if (i != nums[i])
            return i;
    }
    return n;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
//     cout << FindMissingNumber(nums) << endl;
//     cout << string(35, '-') << endl;
//     return -1;
// }
// -------------------------------------------------------- 41. First Missing Positive -------------------------------------------------------------
int SmallestMissingPositiveInteger(vector<int> nums)
{
    int n = nums.size();
    int i = 0;
    while (i < n)
    {
        if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) // nums[i] - 1 < n
            swap(nums[i], nums[nums[i] - 1]);
        else
            i++;
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i + 1)
            return i + 1;
    }
    return n + 1;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> nums = {0, 2, 1};
//     cout << SmallestMissingPositiveInteger(nums) << endl;
//     cout << string(35, '-') << endl;
//     return -1;
// }
// -------------------------------------------------------------- Find the Corrupt Pair ----------------------------------------------------------------
vector<int> FindCorruptPair(vector<int> nums)
{
    int n = nums.size();
    int i = 0;
    while (i < n)
    {
        // It also handles duplicate number cases
        if (nums[i] <= n && nums[i] != nums[nums[i] - 1]) // nums[i] - 1 < n
            swap(nums[i], nums[nums[i] - 1]);
        else
            i++;
    }
    for (int i = 0; i < n; i++)
    {
        if (i != nums[i] - 1)
        {
            return {i + 1, nums[i]};
        }
    }
    return {-1, -1};
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> nums = {4, 1, 2, 1, 6, 3};
//     // vector<int> nums = {1, 1};
//     vector<int> corruptPair = FindCorruptPair(nums);
//     cout << "{" << corruptPair[0] << ", " << corruptPair[1] << "}";
//     cout << endl;
//     cout << string(35, '-') << endl;
//     return -1;
// }
// -------------------------------------------------------------- Find the First K Missing Positive Numbers ----------------------------------------------------------------
vector<int> FirstKMissingNumbers(vector<int> nums, int k)
{
    int n = nums.size();
    int i = 0;
    while (i < n)
    {
        if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
            swap(nums[i], nums[nums[i] - 1]);
        else
            i++;
    }
    vector<int> missingNumbers;
    vector<int> extraNumbers;
    int counter = 0;
    i = 0;
    while (1)
    {
        if (i < n && i != nums[i] - 1)
        {
            missingNumbers.push_back(i + 1);
            extraNumbers.push_back(nums[i]);
            counter++;
        }
        if (i >= n && !(find(extraNumbers.begin(), extraNumbers.end(), i + 1) != extraNumbers.end()))
        {
            missingNumbers.push_back(i + 1);
            counter++;
        }
        if (counter == k)
            break;
        i++;
    }
    return missingNumbers;
}
int main()
{
    cout << string(35, '-') << endl;
    vector<int> nums = {2, 0, 9, 1, 5, 6, 8, 12, -9, 3, 4};
    vector<int> missingNumbers = FirstKMissingNumbers(nums, 10);
    for (auto item : missingNumbers)
        cout << item << " ";
    cout << endl;
    cout << string(35, '-') << endl;
    return -1;
}