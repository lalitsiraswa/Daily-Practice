#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node
// template <class T>
// template <typename T>
// class TreeNode
// {
// public:
//     T data;
//     TreeNode<T> *left;
//     TreeNode<T> *right;
//     TreeNode(const T data) : data(data), left(nullptr), right(nullptr) {}
// };
//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// ---------------
// ------------- In-Order traversal -------------
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> list;
    if (root == nullptr)
        return list;
    stack<TreeNode *> stck;
    while (root != nullptr || !stck.empty())
    {
        while (root != nullptr)
        {
            stck.push(root);
            root = root->left;
        }
        root = stck.top();
        stck.pop();
        list.push_back(root->val);
        root = root->right;
    }
    return list;
}
int main()
{
    cout << string(35, '-') << endl;
    cout << endl
         << string(35, '-');
}