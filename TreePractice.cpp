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
// int main()
// {
//     cout << string(35, '-') << endl;
//     TreeNode *root = new TreeNode(9);
//     root->left = new TreeNode(6);
//     root->right = new TreeNode(-3);
//     root->right->left = new TreeNode(-6);
//     root->right->right = new TreeNode(2);
//     root->right->right->left = new TreeNode(2);
//     root->right->right->left->left = new TreeNode(-6);
//     root->right->right->left->right = new TreeNode(-6);
//     root->right->right->left->left->left = new TreeNode(-6);
//     cout << maxPathSum(root) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ---------------------------------------------------------- 103. Binary Tree Zigzag Level Order Traversal ---------------------------------------------------------------------
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    if (root == nullptr)
        return {};
    vector<vector<int>> result;
    bool isEvenLevel = true;
    deque<TreeNode *> dque;
    dque.push_back(root);
    while (!dque.empty())
    {
        vector<int> temp;
        int size = dque.size();
        for (int i = 1; i <= size; i++)
        {
            if (isEvenLevel)
            {
                TreeNode *front = dque.front();
                dque.pop_front();
                temp.push_back(front->val);
                if (front->left)
                    dque.push_back(front->left);
                if (front->right)
                    dque.push_back(front->right);
            }
            else
            {
                TreeNode *back = dque.back();
                dque.pop_back();
                temp.push_back(back->val);
                if (back->right)
                    dque.push_front(back->right);
                if (back->left)
                    dque.push_front(back->left);
            }
        }
        result.push_back(temp);
        isEvenLevel = !isEvenLevel;
    }
    return result;
}
// -------------------------------------
vector<vector<int>> zigzagLevelOrderTUF(TreeNode *root)
{
    if (root == nullptr)
        return {};
    vector<vector<int>> zigzagOrderView;
    queue<TreeNode *> que;
    que.push(root);
    bool isLeftToRight = true;
    while (!que.empty())
    {
        int size = que.size();
        vector<int> currentLevel(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *treeNode = que.front();
            que.pop();
            int index = (isLeftToRight) ? i : (size - 1 - i);
            currentLevel[index] = treeNode->val;
            if (treeNode->left)
                que.push(treeNode->left);
            if (treeNode->right)
                que.push(treeNode->right);
        }
        isLeftToRight = !isLeftToRight;
        zigzagOrderView.push_back(currentLevel);
    }
    return zigzagOrderView;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     TreeNode *root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(3);
//     root->left->left = new TreeNode(4);
//     root->right->right = new TreeNode(5);
//     vector<vector<int>> result = zigzagLevelOrderTUF(root);
//     for (int i = 0; i < result.size(); i++)
//     {
//         for (int j = 0; j < result[i].size(); j++)
//         {
//             cout << result[i][j] << ", ";
//         }
//         cout << endl;
//     }
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ---------------------------------------------------------- Tree Boundary Traversal ---------------------------------------------------------------------
void leftBoundary(TreeNode *root, vector<int> &result)
{
    if (root == nullptr)
        return;
    if (root->left == nullptr && root->right == nullptr)
        return;
    result.push_back(root->val);
    if (root->left)
        leftBoundary(root->left, result);
    else if (root->right)
        leftBoundary(root->right, result);
}
void leafNodesInOrder(TreeNode *root, vector<int> &result)
{
    if (root == nullptr)
        return;
    if (root->left == nullptr && root->right == nullptr)
    {
        result.push_back(root->val);
        return;
    }
    leafNodesInOrder(root->left, result);
    leafNodesInOrder(root->right, result);
}
void rightBoundary(TreeNode *root, stack<int> &s)
{
    if (root == nullptr)
        return;
    if (root->left == nullptr && root->right == nullptr)
        return;
    s.push(root->val);
    if (root->right)
        rightBoundary(root->right, s);
    else if (root->left)
        rightBoundary(root->left, s);
}
vector<int> boundaryTraversal(TreeNode *root)
{
    vector<int> result;
    if (root == nullptr)
        return result;
    if (root->left || root->right)
        result.push_back(root->val);
    leftBoundary(root->left, result);
    leafNodesInOrder(root, result);
    stack<int> s;
    rightBoundary(root->right, s);
    while (!s.empty())
    {
        result.push_back(s.top());
        s.pop();
    }
    return result;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     TreeNode *root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(3);
//     root->left->left = new TreeNode(4);
//     root->left->right = new TreeNode(5);
//     root->right->left = new TreeNode(6);
//     root->right->right = new TreeNode(7);
//     root->left->right->left = new TreeNode(8);
//     root->left->right->right = new TreeNode(9);
//     vector<int> result = boundaryTraversal(root);
//     for (int i = 0; i < result.size(); i++)
//     {
//         cout << result[i] << ", ";
//     }
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ---------------------------------------------------------- 987. Vertical Order Traversal of a Binary Tree ---------------------------------------------------------------------
vector<vector<int>> verticalTraversal(TreeNode *root)
{
    // Map to store nodes based on vertical/column and level/row information
    // map<column, map<row, multiset<int>>> nodes;
    map<int, map<int, multiset<int>>> nodes;
    // Queue for BFS traversal, each element is a pair containing node and its vertical and level information
    // vertical and level are like column and row
    // queue<pair<TreeNode *, pair<column, row>>> todo;
    queue<pair<TreeNode *, pair<int, int>>> todo;
    // Push the root node with initial vertical/column and level/row values (0, 0)
    todo.push({root, {0, 0}});
    // BFS traversal
    while (!todo.empty())
    {
        // Retrieve the node and its vertical/column and level/row information from the front of the queue
        auto p = todo.front();
        todo.pop();
        TreeNode *temp = p.first;
        // Extract the vertical/column and level/row information (row & column information)
        // x -> vertical/column
        int x = p.second.first;
        // y -> level/row
        int y = p.second.second;
        // Insert the node value into the corresponding vertical and level in the map
        nodes[x][y].insert(temp->val);
        // Process left child
        if (temp->left)
        {
            // Move left in terms of vertical/column and
            // Move down in terms of level/row
            todo.push({temp->left, {x - 1, y + 1}});
        }
        // Process right child
        if (temp->right)
        {
            // Move right interms of vertical/column and
            // Move down in terms of level/row
            todo.push({temp->right, {x + 1, y + 1}});
        }
    }
    // Prepare the final result vector by combining values from the map
    vector<vector<int>> result;
    for (auto p : nodes)
    {
        vector<int> col;
        for (auto q : p.second)
        {
            // Insert node values into the column vector
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        // Add the column vector to the final result
        result.push_back(col);
    }
    return result;
}
int main()
{
    cout << string(35, '-') << endl;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<vector<int>> result = verticalTraversal(root);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << ", ";
        }
        cout << endl;
    }
    cout << endl
         << string(35, '-');
    return 0;
}