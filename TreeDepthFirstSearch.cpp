#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node
// template <class T>
template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode(const T data) : data(data), left(nullptr), right(nullptr) {}
};
// ---------- Determine if a tree is a valid binary search tree --------------
// We perform an inorder traversal of the tree. If the value of the current node is less than the value of the previous node traversed,
// the tree is not a valid BST, so we return FALSE. Otherwise, we keep on traversing the tree and return TRUE if the traversal of the entire tree is successful.
bool isValidBST(TreeNode<int> *root, vector<int> &visited)
{
    if (root == nullptr)
        return true;
    if (!visited.empty() && visited.back() > root->data)
        return false;
    if (!isValidBST(root->left, visited))
        return false;
    visited.push_back(root->data);
    if (!isValidBST(root->right, visited))
        return false;
    return true;
}
int main()
{
    cout << string(35, '-') << endl;
    TreeNode<int> *root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    // root->left->right->left = new TreeNode(2);
    vector<int> visited;
    cout << isValidBST(root, visited) << endl;
    cout << string(35, '-') << endl;
}