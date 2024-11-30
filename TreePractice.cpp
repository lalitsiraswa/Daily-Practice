#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// -------------------------------------------------------------------------- 104. Maximum Depth of Binary Tree ---------------------------------------------------------------------
int maxDepth(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    queue<TreeNode *> que;
    que.push(root);
    int treeDepth = 0;
    while (!que.empty())
    {
        treeDepth += 1;
        int size = que.size();
        for (int i = 1; i <= size; i++)
        {
            TreeNode *frontNode = que.front();
            que.pop();
            if (frontNode->left)
                que.push(frontNode->left);
            if (frontNode->right)
                que.push(frontNode->right);
        }
    }
    return treeDepth;
}
// ---------------------
void maxDepth(TreeNode *root, int level, int &maxHeight)
{
    if (root == nullptr)
        return;
    if (level > maxHeight)
        maxHeight = level;
    maxDepth(root->left, level + 1, maxHeight);
    maxDepth(root->right, level + 1, maxHeight);
}
int maxDepthRecursion(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int maxHeight = 0;
    maxDepth(root, 1, maxHeight);
    return maxHeight;
}
// ------------------------
int maxDepthOtherWay(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int leftSubTreeDepth = maxDepth(root->left);
    int rightSubTreeDepth = maxDepth(root->right);
    return 1 + max(leftSubTreeDepth, rightSubTreeDepth);
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     TreeNode *root = new TreeNode(3);
//     root->left = new TreeNode(9);
//     root->right = new TreeNode(20);
//     root->right->left = new TreeNode(15);
//     root->right->right = new TreeNode(7);
//     cout << maxDepthOtherWay(root) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// -------------------------------------------------------------------------- 110. Balanced Binary Tree ---------------------------------------------------------------------
int isBalancedHeightHelper(TreeNode *root)
{
    if (root == 0)
        return 0;
    int leftSubTreeHeight = isBalancedHeightHelper(root->left);
    if (leftSubTreeHeight == -1)
        return -1;
    int rightSubTreeHeight = isBalancedHeightHelper(root->right);
    if (rightSubTreeHeight == -1)
        return -1;
    int heightDifference = abs(leftSubTreeHeight - rightSubTreeHeight);
    if (heightDifference > 1)
        return -1;
    return 1 + max(leftSubTreeHeight, rightSubTreeHeight);
}
bool isBalanced(TreeNode *root)
{
    if (root == nullptr)
        return true;
    int result = isBalancedHeightHelper(root);
    return result == -1 ? false : true;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     TreeNode *root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(2);
//     root->left->left = new TreeNode(3);
//     root->left->right = new TreeNode(3);
//     root->left->left->left = new TreeNode(4);
//     root->left->left->right = new TreeNode(4);
//     cout << isBalanced(root) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// -------------------------------------------------------------------------- 543. Diameter of Binary Tree ---------------------------------------------------------------------
int diameterOfBinaryTree(TreeNode *root, int &diameter)
{
    if (root == nullptr)
        return 0;
    int leftSubTreeEdgeCount = 0;
    if (root->left)
    {
        leftSubTreeEdgeCount = 1 + diameterOfBinaryTree(root->left, diameter);
    }
    int rightSubTreeEdgeCount = 0;
    if (root->right)
    {
        rightSubTreeEdgeCount = 1 + diameterOfBinaryTree(root->right, diameter);
    }
    int currentDiameter = leftSubTreeEdgeCount + rightSubTreeEdgeCount;
    diameter = max(diameter, currentDiameter);
    return max(leftSubTreeEdgeCount, rightSubTreeEdgeCount);
}
int diameterOfBinaryTree(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int diameter = 0;
    diameterOfBinaryTree(root, diameter);
    return diameter;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     TreeNode *root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(3);
//     root->left->left = new TreeNode(4);
//     root->left->right = new TreeNode(5);
//     cout << diameterOfBinaryTree(root) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// -------------------------------------------------------------------------- 124. Binary Tree Maximum Path Sum ---------------------------------------------------------------------
int maxPathSum(TreeNode *root, int &maxPath)
{
    if (root == nullptr)
        return 0;
    int leftTreeMaxPathSum = maxPathSum(root->left, maxPath);
    int rightTreeMaxPathSum = maxPathSum(root->right, maxPath);
    maxPath = max(maxPath, root->val + leftTreeMaxPathSum + rightTreeMaxPathSum);
    maxPath = max(maxPath, root->val + leftTreeMaxPathSum);
    maxPath = max(maxPath, root->val + rightTreeMaxPathSum);
    maxPath = max(maxPath, root->val);
    return max(max(leftTreeMaxPathSum, rightTreeMaxPathSum) + root->val, root->val);
}
int maxPathSum(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int maxPath = INT_MIN;
    maxPathSum(root, maxPath);
    return maxPath;
}
int main()
{
    cout << string(35, '-') << endl;
    TreeNode *root = new TreeNode(9);
    root->left = new TreeNode(6);
    root->right = new TreeNode(-3);
    root->right->left = new TreeNode(-6);
    root->right->right = new TreeNode(2);
    root->right->right->left = new TreeNode(2);
    root->right->right->left->left = new TreeNode(-6);
    root->right->right->left->right = new TreeNode(-6);
    root->right->right->left->left->left = new TreeNode(-6);
    cout << maxPathSum(root) << endl;
    cout << endl
         << string(35, '-');
    return 0;
}