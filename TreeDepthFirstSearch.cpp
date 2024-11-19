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
//  Definition for a binary tree node.
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
// ---------- Determine if a tree is a valid binary search tree --------------
// We perform an inorder traversal of the tree. If the value of the current node is less than the value of the previous node traversed,
// the tree is not a valid BST, so we return FALSE. Otherwise, we keep on traversing the tree and return TRUE if the traversal of the entire tree is successful.
bool isValidBST(TreeNode<int> *root, vector<int> &visited)
{
    if (root == nullptr)
        return true;
    if (!isValidBST(root->left, visited))
        return false;
    if (!visited.empty() && visited.back() >= root->data)
        return false;
    visited.push_back(root->data);
    if (!isValidBST(root->right, visited))
        return false;
    return true;
}
// ----------
bool isValidBstInOrder(TreeNode<int> *root)
{
    if (root == nullptr)
        return true;
    stack<TreeNode<int> *> stck;
    TreeNode<int> *pre = nullptr;
    while (root != nullptr || !stck.empty())
    {
        while (root != nullptr)
        {
            stck.push(root);
            root = root->left;
        }
        root = stck.top();
        stck.pop();
        if (pre != nullptr && root->data <= pre->data)
            return false;
        pre = root;
        root = root->right;
    }
    return true;
}
// ------------
bool isValidBstRecursiveCall(TreeNode<int> *root, TreeNode<int> *minNode, TreeNode<int> *maxNode)
{
    if (root == nullptr)
        return true;
    if (minNode && root->data <= minNode->data || maxNode && root->data >= maxNode->data)
        return false;
    return isValidBstRecursiveCall(root->left, minNode, root) && isValidBstRecursiveCall(root->right, root, maxNode);
}
bool isValidBst(TreeNode<int> *root)
{
    return isValidBstRecursiveCall(root, nullptr, nullptr);
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     TreeNode<int> *root = new TreeNode(8);
//     root->left = new TreeNode(3);
//     root->right = new TreeNode(10);
//     root->left->left = new TreeNode(1);
//     root->left->right = new TreeNode(6);
//     root->left->right->left = new TreeNode(4);
//     // ----
//     // root->left->right->left = new TreeNode(2);
//     // ----
//     // TreeNode<int> *root = new TreeNode(1);
//     // root->left = new TreeNode(1);
//     vector<int> visited;
//     cout << isValidBst(root) << endl;
//     cout << string(35, '-') << endl;
// }
// --------------------------------------------------- 114. Flatten Binary Tree to Linked List ----------------------------------------------------
//   Definition for a binary tree node.
struct Node
{
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};
void preOrder(Node *root, queue<Node *> &que)
{
    if (root == nullptr)
        return;
    que.push(root);
    preOrder(root->left, que);
    preOrder(root->right, que);
}
void preOrderWithIteration(Node *root, queue<Node *> &que)
{
    stack<Node *> stck;
    while (root != nullptr || !stck.empty())
    {
        while (root != nullptr)
        {
            cout << root->val << " ";
            que.push(root);
            stck.push(root);
            root = root->left;
        }
        root = stck.top();
        stck.pop();
        root = root->right;
    }
}
Node *FlattenTree(Node *root)
{
    if (root == nullptr)
        return nullptr;
    queue<Node *> que;
    preOrderWithIteration(root, que);
    while (!que.empty())
    {
        Node *top = que.front();
        que.pop();
        top->left = nullptr;
        if (!que.empty())
            top->right = que.front();
        else
            top->right = nullptr;
    }
    return root;
}
// ---------
Node *FlattenTreeWithoudExtraSpace(Node *root)
{
    if (!root)
        return nullptr;
    Node *current = root;
    while (current)
    {
        if (current->left)
        {
            Node *last = current->left;
            while (last->right)
            {
                last = last->right;
            }
            last->right = current->right;
            current->right = current->left;
            current->left = nullptr;
        }
        current = current->right;
    }
    return root;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     Node *root = new Node(1);
//     root->left = new Node(2);
//     root->left->left = new Node(3);
//     root->right = new Node(4);
//     root->right->left = new Node(5);
//     root->right->right = new Node(6);
//     FlattenTreeWithoudExtraSpace(root);
//     cout << endl
//          << string(35, '-') << endl;
// }
// ------------------------------------------------------------------- 543. Diameter of Binary Tree --------------------------------------------------------------
int DiameterHelper(Node *node, int &diameter)
{
    if (node == nullptr)
    {
        return 0;
    }
    else
    {
        int leftHeight = DiameterHelper(node->left, diameter);
        int rightHeight = DiameterHelper(node->right, diameter);
        diameter = max(diameter, leftHeight + rightHeight);
        return max(leftHeight, rightHeight) + 1;
    }
}
int DiameterOfBinaryTree(Node *root)
{
    int diameter = 0;
    if (!root)
        return 0;
    DiameterHelper(root, diameter);
    return diameter;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     Node *root = new Node(1);
//     root->left = new Node(2);
//     root->left->left = new Node(3);
//     root->right = new Node(4);
//     root->right->left = new Node(5);
//     root->right->right = new Node(6);
//     FlattenTreeWithoudExtraSpace(root);
//     cout << endl
//          << string(35, '-') << endl;
// }
// ------------------------------------------------------------------ 226. Invert Binary Tree ---------------------------------------------------------------
void levelOrder(Node *root)
{
    queue<Node *> que;
    que.push(root);
    while (!que.empty())
    {
        Node *front = que.front();
        que.pop();
        cout << front->val << " ";
        if (front->left)
            que.push(front->left);
        if (front->right)
            que.push(front->right);
    }
}
Node *invertTree(Node *root)
{
    if (root == nullptr)
        return nullptr;
    if (root->left)
        invertTree(root->left);
    if (root->right)
        invertTree(root->right);
    Node *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    return root;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     Node *root = new Node(100);
//     root->left = new Node(50);
//     root->left->left = new Node(25);
//     root->left->right = new Node(75);
//     root->right = new Node(200);
//     root->right->right = new Node(350);
//     levelOrder(root);
//     invertTree(root);
//     levelOrder(root);
//     cout << endl
//          << string(35, '-') << endl;
// }
// ------------------------------------------------------------ 124. Binary Tree Maximum Path Sum -------------------------------------------------------
int maxPathSumRecursiveCall(Node *root, int &maxPath)
{
    if (root == nullptr)
        return 0;
    int leftTreeMaxPathSum = maxPathSumRecursiveCall(root->left, maxPath);
    int rightTreeMaxPathSum = maxPathSumRecursiveCall(root->right, maxPath);
    maxPath = max(maxPath, root->val + leftTreeMaxPathSum + rightTreeMaxPathSum);
    maxPath = max(maxPath, root->val + leftTreeMaxPathSum);
    maxPath = max(maxPath, root->val + rightTreeMaxPathSum);
    maxPath = max(maxPath, root->val);
    return max(max(leftTreeMaxPathSum, rightTreeMaxPathSum) + root->val, root->val);
}
// ---------
int findMaxPathSum(Node *root, int &maxPath)
{
    if (root == nullptr)
        return 0;
    int leftMaxPath = max(0, findMaxPathSum(root->left, maxPath));
    int rightMaxPath = max(0, findMaxPathSum(root->right, maxPath));
    maxPath = max(maxPath, leftMaxPath + rightMaxPath + root->val);
    return max(leftMaxPath, rightMaxPath) + root->val;
}
int maxPathSum(Node *root)
{
    if (root == nullptr)
        return 0;
    int maxPath = INT_MIN;
    findMaxPathSum(root, maxPath);
    return maxPath;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     cout << endl
//          << string(35, '-') << endl;
// }
// ----------------------------------------------------------- 108. Convert Sorted Array to Binary Search Tree -----------------------------------------------------
Node *constructBSTWithArray(vector<int> &nums, int start, int end)
{
    if (start >= nums.size() || start > end)
        return nullptr;
    int mid = (start + end) / 2;
    Node *root = new Node(nums.at(mid));
    if (start != end)
    {
        root->left = constructBSTWithArray(nums, start, mid - 1);
        root->right = constructBSTWithArray(nums, mid + 1, end);
    }
    return root;
}
Node *sortedArrayToBST(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return nullptr;
    return constructBSTWithArray(nums, 0, n);
}
// ----------------------
Node *SortedArrayToBstHelper(vector<int> &nums, int low, int high)
{
    if (low > high)
        return nullptr;
    int mid = low + (high - low) / 2;
    Node *root = new Node(nums[mid]);
    root->left = SortedArrayToBstHelper(nums, low, mid - 1);
    root->right = SortedArrayToBstHelper(nums, mid + 1, high);
    return root;
}

Node *SortedArrayToBst(vector<int> &nums)
{
    return SortedArrayToBstHelper(nums, 0, nums.size() - 1);
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     // vector<int> nums = {-10, -3, 0, 5, 9};
//     // vector<int> nums = {1, 3};
//     vector<int> nums = {0, 1, 2, 3, 4, 5};
//     Node *root = SortedArrayToBst(nums);
//     levelOrder(root);
//     cout << endl
//          << string(35, '-') << endl;
// }
// ---------------------------------------------------------- 105. Construct Binary Tree from Preorder and Inorder Traversal ------------------------------------------
Node *constructTree(vector<int> &preOrder, vector<int> &inOrder, int low, int high, int &index)
{
    if (low > high)
        return nullptr;
    int rootIndex = -1;
    Node *root = new Node(preOrder[index]);
    for (int i = low; i <= high; i++)
    {
        if (preOrder[index] == inOrder[i])
        {
            rootIndex = i;
            index++;
            break;
        }
    }
    if (low != high)
    {
        root->left = constructTree(preOrder, inOrder, low, rootIndex - 1, index);
        root->right = constructTree(preOrder, inOrder, rootIndex + 1, high, index);
    }
    return root;
}
Node *buildTree(vector<int> &preOrder, vector<int> &inOrder)
{
    int n = inOrder.size();
    int index = 0;
    return constructTree(preOrder, inOrder, 0, n - 1, index);
}
// ------------------------------------
Node *BuildTreeHelper(vector<int> &preOrder, vector<int> &inOrder, int left, int right, unordered_map<int, int> &mapping, int &pIndex)
{
    if (left > right)
        return nullptr;
    int curr = preOrder[pIndex++];
    Node *root = new Node(curr);
    if (left == right)
        return root;
    int inIndex = mapping[curr];
    root->left = BuildTreeHelper(preOrder, inOrder, left, inIndex - 1, mapping, pIndex);
    root->right = BuildTreeHelper(preOrder, inOrder, inIndex + 1, right, mapping, pIndex);
    return root;
}
Node *BuildTree(vector<int> &preOrder, vector<int> &inOrder)
{
    int pIndex = 0;
    unordered_map<int, int> mapping;
    for (int i = 0; i < inOrder.size(); i++)
        mapping[inOrder[i]] = i;
    return BuildTreeHelper(preOrder, inOrder, 0, preOrder.size() - 1, mapping, pIndex);
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     // vector<int> preOrder = {3, 9, 20, 15, 7};
//     // vector<int> inOrder = {9, 3, 15, 20, 7};
//     vector<int> preOrder = {10, 20, 40, 50, 30, 60};
//     vector<int> inOrder = {40, 20, 50, 10, 60, 30};
//     Node *root = BuildTree(preOrder, inOrder);
//     levelOrder(root);
//     cout << endl
//          << string(35, '-') << endl;
// }

// ---------------------------------------------------------------------- 199. Binary Tree Right Side View -------------------------------------------------------------
vector<int> rightSideViewBfs(Node *root)
{
    if (root == nullptr)
        return {};
    vector<int> rightSideViewList;
    queue<Node *> que;
    que.push(root);
    que.push(nullptr);
    while (!que.empty() && que.front() != nullptr)
    {
        Node *front = que.front();
        que.pop();
        if (front->left)
            que.push(front->left);
        if (front->right)
            que.push(front->right);
        if (que.front() == nullptr)
        {
            que.pop();
            que.push(nullptr);
            rightSideViewList.push_back(front->val);
        }
    }
    return rightSideViewList;
}
// ------------------------------------
void rightSideViewDfsCall(Node *root, vector<int> &rightSideViewList, int currLevel)
{
    if (root == nullptr)
        return;
    if (currLevel == rightSideViewList.size())
        rightSideViewList.push_back(root->val);
    rightSideViewDfsCall(root->right, rightSideViewList, currLevel + 1);
    rightSideViewDfsCall(root->left, rightSideViewList, currLevel + 1);
}
vector<int> rightSideViewDfs(Node *root)
{
    if (root == nullptr)
        return {};
    vector<int> rightSideViewList;
    rightSideViewDfsCall(root, rightSideViewList, 0);
    return rightSideViewList;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     Node *root = new Node(1);
//     root->left = new Node(2);
//     root->left->left = new Node(4);
//     root->left->right = new Node(5);
//     root->left->right->left = new Node(8);
//     root->left->right->right = new Node(9);
//     root->right = new Node(3);
//     root->right->left = new Node(6);
//     root->right->right = new Node(7);
//     vector<int> rightSideViewList = rightSideViewDfs(root);
//     for (int item : rightSideViewList)
//         cout << item << " ";
//     cout << endl
//          << string(35, '-') << endl;
// }
// ---------------------------------------------------------- 236. Lowest Common Ancestor of a Binary Tree --------------------------------------------------------
Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    // Base Case
    if (root == nullptr || root == p || root == q)
        return root;
    Node *left = lowestCommonAncestor(root->left, p, q);
    Node *right = lowestCommonAncestor(root->right, p, q);
    // Result
    if (left == nullptr)
        return right;
    else if (right == nullptr)
        return left;
    // Both left and right are not null, we found our result
    else
        return root;
}
// ----------------------------------
bool lowestCommonAncestorRecursion(Node *currentNode, Node *p, Node *q, Node *&commonAncestorRef)
{
    if (!currentNode)
        return false;
    bool left = false, right = false, mid = false;
    if (p == currentNode || q == currentNode)
        mid = true;
    if (!commonAncestorRef)
        left = lowestCommonAncestorRecursion(currentNode->left, p, q, commonAncestorRef);
    if (!commonAncestorRef)
        right = lowestCommonAncestorRecursion(currentNode->right, p, q, commonAncestorRef);
    if (mid + left + right >= 2)
        commonAncestorRef = currentNode;
    return mid || left || right;
}
Node *lowestCommonAncestorDfs(Node *root, Node *p, Node *q)
{
    Node *commonAncestor = nullptr;
    Node *&commonAncestorRef = commonAncestor;
    lowestCommonAncestorRecursion(root, p, q, commonAncestorRef);
    return commonAncestor;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     Node *root = new Node(3);
//     root->left = new Node(5);
//     root->left->left = new Node(6);
//     root->left->right = new Node(2);
//     root->left->right->left = new Node(7);
//     root->left->right->right = new Node(4);
//     root->right = new Node(1);
//     root->right->left = new Node(0);
//     root->right->right = new Node(8);
//     Node *commonAncestor = lowestCommonAncestorDfs(root, root->left, root->left->right->right);
//     cout << commonAncestor->val << endl;
//     cout << endl
//          << string(35, '-') << endl;
// }
// ---------------------------------------------------------- 98. Validate Binary Search Tree ----------------------------------------------------------
void inOrderCall(Node *root, vector<int> &inOrder)
{
    if (root == nullptr)
        return;
    inOrderCall(root->left, inOrder);
    inOrder.push_back(root->val);
    inOrderCall(root->right, inOrder);
}
bool isValidBST(Node *root)
{
    if (root == nullptr)
        return true;
    vector<int> inOrder;
    inOrderCall(root, inOrder);
    for (int i = 0; i < inOrder.size() - 1; i++)
    {
        if (inOrder[i] >= inOrder[i + 1])
            return false;
    }
    return true;
}
// --------------------------
bool static isValidBstRecursiveCall(Node *root, Node *minNode, Node *maxNode)
{
    if (root == nullptr)
        return true;
    if (minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
        return false;
    return isValidBstRecursiveCall(root->left, minNode, root) && isValidBstRecursiveCall(root->right, root, maxNode);
}
bool isValidBSTOtherWay(Node *root)
{
    return isValidBstRecursiveCall(root, nullptr, nullptr);
}
// ----------------------------
bool validateBstHelper(Node *root, int &prev)
{
    if (root == nullptr)
        return true;
    if (!validateBstHelper(root->left, prev))
        return false;
    if (root->val <= prev)
        return false;
    prev = root->val;
    return validateBstHelper(root->right, prev);
}
bool isValidBSTOtherWay2(Node *root)
{
    int prev = INT_MIN;
    return validateBstHelper(root, prev);
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     // Node *root = new Node(5);
//     // root->left = new Node(3);
//     // root->left->left = new Node(2);
//     // root->left->right = new Node(4);
//     // root->right = new Node(6);
//     // ----------
//     Node *root = new Node(5);
//     root->left = new Node(1);
//     root->right = new Node(4);
//     root->right->left = new Node(3);
//     root->right->right = new Node(6);
//     cout << isValidBSTOtherWay2(root) << endl;
//     cout << endl
//          << string(35, '-') << endl;
// }
// --------------------------------------------------------------- 104. Maximum Depth of Binary Tree ------------------------------------------------------------
int maxDepth(Node *root)
{
    if (root == 0)
        return 0;
    int leftMaxDepth = maxDepth(root->left);
    int rightMaxDepth = maxDepth(root->right);
    return max(leftMaxDepth, rightMaxDepth) + 1;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     Node *root = new Node(3);
//     root->left = new Node(9);
//     root->right = new Node(20);
//     root->right->left = new Node(15);
//     root->right->right = new Node(7);
//     cout << maxDepth(root) << endl;
//     cout << endl
//          << string(35, '-') << endl;
// }
// ----------------------------------------------------------- 230. Kth Smallest Element in a BST ---------------------------------------------------------------
int inOrderCall(Node *root, int &k)
{
    if (root == nullptr)
        return INT_MIN;
    int left = inOrderCall(root->left, k);
    if (left != INT_MIN && k == 0)
        return left;
    k--;
    if (k == 0)
        return root->val;
    return inOrderCall(root->right, k);
}
int kthSmallest(Node *root, int k)
{
    return inOrderCall(root, k);
}
// -------------------------
void callInOrder(Node *root, vector<int> &inOrder)
{
    if (root == nullptr)
        return;
    callInOrder(root->left, inOrder);
    inOrder.push_back(root->val);
    callInOrder(root->right, inOrder);
}
int kthSmallestOtherWay(Node *root, int k)
{
    vector<int> inOrder;
    callInOrder(root, inOrder);
    return inOrder[k - 1];
}
int main()
{
    cout << string(35, '-') << endl;
    Node *root = new Node(5);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->left->left->left = new Node(1);
    root->right = new Node(6);
    cout << kthSmallest(root, 3);
    cout << endl
         << string(35, '-') << endl;
}