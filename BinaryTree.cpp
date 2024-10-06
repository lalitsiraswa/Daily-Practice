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

// ------------------------------------------------------------ 144. Binary Tree Preorder Traversal ---------------------------------------------------------------------
void preorderTraversalHelper(TreeNode *root, vector<int> &preOrder)
{
    if (root == nullptr)
        return;
    preOrder.push_back(root->val);
    preorderTraversalHelper(root->left, preOrder);
    preorderTraversalHelper(root->right, preOrder);
}
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> preOrder;
    preorderTraversalHelper(root, preOrder);
    return preOrder;
}
// -----------------------------------
vector<int> preorderTraversal2(TreeNode *root)
{
    vector<int> preOrder;
    stack<TreeNode *> s;
    if (root == nullptr)
        return preOrder;
    s.push(root);
    while (!s.empty())
    {
        TreeNode *temp = s.top();
        preOrder.push_back(temp->val);
        s.pop();
        if (temp->right)
            s.push(temp->right);
        if (temp->left)
            s.push(temp->left);
    }
    return preOrder;
}
// ------------------
vector<int> preorderTraversal3(TreeNode *root)
{
    vector<int> result;
    stack<TreeNode *> s;
    TreeNode *currentNode = root;
    while (currentNode != NULL || !s.empty())
    {
        while (currentNode != NULL)
        {
            // cout << currentNode->val << ", ";
            result.push_back(currentNode->val);
            s.push(currentNode);
            currentNode = currentNode->left;
        }
        currentNode = s.top();
        s.pop();
        currentNode = currentNode->right;
    }
    return result;
}
int main()
{
    cout << string(35, '-') << endl;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    vector<int> preOrder = preorderTraversal2(root);
    for (int data : preOrder)
        cout << data << " ";
    cout << endl
         << string(35, '-');
    return 0;
}
