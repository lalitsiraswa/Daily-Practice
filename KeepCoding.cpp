#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int data;
    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {};
};

vector<int> bottomView(TreeNode *root)
{
    vector<int> view;
    if (root == nullptr)
        return view;
    // queue<pair<TreeNode *, column>> q;
    queue<pair<TreeNode *, int>> q;
    // map<column, int> mp;
    map<int, int> mp;
    q.push({root, 0});
    while (!q.empty())
    {
        auto front = q.front();
        q.pop();
        TreeNode *node = front.first;
        int column = front.second;
        mp[column] = node->data;
        if (node->left)
        {
            q.push({root->left, column - 1});
        }
        if (node->right)
        {
            q.push({root->right, column + 1});
        }
    }
    for (auto column : mp)
    {
        view.push_back(column.second);
    }
    return view;
}

int main()
{
    cout << string(30, '-') << endl;

    cout << endl
         << string(30, '-');
}

int findFrequencyOne(vector<int> &nums)
{
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    int result = 0;
    if (n == 1)
    {
        return nums[0];
    }
    if (n > 2 && nums[0] != nums[1])
    {
        return nums[0];
    }
    if (n > 2 && nums[n - 1] != nums[n - 2])
    {
        return nums[n - 1];
    }
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1])
        {
            return nums[mid];
        }
        // Even -> Next
        if (mid % 2 == 0)
        {
            if (mid < n - 1 && nums[mid] == nums[mid + 1])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        // Odd -> Previous
        else
        {
            if (mid > 0 && nums[mid] == nums[mid - 1])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
    return -1;
}

// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {1};
//     cout << findFrequencyOne(nums);
//     cout << endl
//          << string(30, '-');
// }