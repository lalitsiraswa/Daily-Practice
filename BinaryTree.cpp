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
//     vector<int> preOrder = preorderTraversal2(root);
//     for (int data : preOrder)
//         cout << data << " ";
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ------------------------------------------------------------ 94. Binary Tree Inorder Traversal ---------------------------------------------------------------------
void inorderTraversalHelper(TreeNode *root, vector<int> &inOrder)
{
    if (root == nullptr)
        return;
    inorderTraversalHelper(root->left, inOrder);
    inOrder.push_back(root->val);
    inorderTraversalHelper(root->right, inOrder);
}
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> inOrder;
    inorderTraversalHelper(root, inOrder);
    return inOrder;
}
// ------------------------------
vector<int> inorderTraversal2(TreeNode *root)
{
    vector<int> inOrder;
    stack<TreeNode *> s;
    TreeNode *currentNode = root;
    while (currentNode != nullptr || !s.empty())
    {
        while (currentNode != nullptr)
        {
            s.push(currentNode);
            currentNode = currentNode->left;
        }
        TreeNode *top = s.top();
        inOrder.push_back(top->val);
        s.pop();
        currentNode = top->right;
    }
    return inOrder;
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
//     vector<int> preOrder = inorderTraversal2(root);
//     for (int data : preOrder)
//         cout << data << " ";
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ------------------------------------------------------------- 145. Binary Tree Postorder Traversal ---------------------------------------------------------------------
void postorderTraversalHelper(TreeNode *root, vector<int> &postOrder)
{
    if (root == nullptr)
        return;
    postorderTraversalHelper(root->left, postOrder);
    postorderTraversalHelper(root->right, postOrder);
    postOrder.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> postOrder;
    postorderTraversalHelper(root, postOrder);
    return postOrder;
}
// ----------------------------
vector<int> postorderTraversal2(TreeNode *root)
{
    vector<int> postOrder;
    if (root == nullptr)
        return postOrder;
    stack<TreeNode *> st1, st2;
    st1.push(root);
    while (!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if (root->left)
            st1.push(root->left);
        if (root->right)
            st1.push(root->right);
    }
    while (!st2.empty())
    {
        postOrder.push_back(st2.top()->val);
        st2.pop();
    }
    return postOrder;
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
//     vector<int> preOrder = postorderTraversal2(root);
//     for (int data : preOrder)
//         cout << data << " ";
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ------------------------------------------------------------- 102. Binary Tree Level Order Traversal ---------------------------------------------------------------------
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> levelOrderTraversal;
    vector<int> result;
    queue<TreeNode *> que;
    if (root == nullptr)
        return levelOrderTraversal;
    que.push(root);
    que.push(nullptr);
    while (!que.empty())
    {
        TreeNode *top = que.front();
        if (top == nullptr)
        {
            levelOrderTraversal.push_back(result);
            if (que.size() == 1)
                break;
            result.clear();
            que.pop();
            que.push(nullptr);
            continue;
        }
        que.pop();
        result.push_back(top->val);
        if (top->left)
            que.push(top->left);
        if (top->right)
            que.push(top->right);
    }
    return levelOrderTraversal;
}
// --------------------------------
vector<vector<int>> levelOrder2(TreeNode *root)
{
    if (root == nullptr)
        return {};
    vector<vector<int>> levelOrderView;
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty())
    {
        vector<int> currLevel;
        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = que.front();
            que.pop();
            if (node->left)
                que.push(node->left);
            if (node->right)
                que.push(node->right);
            currLevel.push_back(node->val);
        }
        levelOrderView.push_back(currLevel);
    }
    return levelOrderView;
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
//     vector<vector<int>> levelOrderTraversal = levelOrder2(root);
//     for (int i = 0; i < levelOrderTraversal.size(); i++)
//     {
//         for (int j = 0; j < levelOrderTraversal[i].size(); j++)
//         {
//             cout << levelOrderTraversal[i][j] << "  ";
//         }
//         cout << endl;
//     }
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// -------------------------------------------------------------- Preorder, Inorder, Postorder Traversals in One Traversal ---------------------------------------------------------------------
// Function to get the Preorder,
// Inorder and Postorder traversal
// Of Binary Tree in One traversal
vector<int> preInPostTraversal(TreeNode *root)
{
    // Vectors to store traversals
    vector<int> preOrder;
    vector<int> inOrder;
    vector<int> postOrder;
    // If the tree is empty,
    // return empty traversals
    if (root == nullptr)
        return {};
    // Stack to maintain nodes
    // and their traversal state
    stack<pair<TreeNode *, int>> st;
    // Start with the root node
    // and state 1 (preorder)
    st.push({root, 1});
    while (!st.empty())
    {
        pair<TreeNode *, int> top = st.top();
        st.pop();
        // this is part of PreOrder
        if (top.second == 1)
        {
            // Store the node's data
            // in the preorder traversal
            preOrder.push_back(top.first->val);
            // Move to state 2
            // (inorder) for this node
            top.second = 2;
            // Push the updated state
            // back onto the stack
            st.push(top);
            // Push left child onto
            // the stack for processing
            if (top.first->left != nullptr)
                st.push({top.first->left, 1});
        }
        // this is a part of in
        else if (top.second == 2)
        {
            // Store the node's data
            // in the inorder traversal
            inOrder.push_back(top.first->val);
            // Move to state 3
            // (postorder) for this node
            top.second = 3;
            // Push the updated state
            // back onto the stack
            st.push(top);
            // Push right child onto
            // the stack for processing
            if (top.first->right != nullptr)
                st.push({top.first->right, 1});
        }
        // this is part of post (top.second == 3)
        else
        {
            // Store the node's data
            // in the postorder traversal
            postOrder.push_back(top.first->val);
        }
    }
    return preOrder;
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
//     vector<int> traversal = preInPostTraversal(root);
//     for (auto item : traversal)
//         cout << item << ", ";
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ------------------------------------------------------------- 104. Maximum Depth of Binary Tree ---------------------------------------------------------------------
int maxDepth(TreeNode *root)
{
    int maximumDepth = 0;
    if (root == nullptr)
        return maximumDepth;
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty())
    {
        maximumDepth += 1;
        int size = que.size();
        for (int i = 1; i <= size; i++)
        {
            TreeNode *top = que.front();
            que.pop();
            if (top->left != nullptr)
                que.push(top->left);
            if (top->right != nullptr)
                que.push(top->right);
        }
    }
    return maximumDepth;
}
// -----------------------
int maxDepthRecursion(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int leftSubTreeDepth = maxDepthRecursion(root->left);
    int rightSubTreeDepth = maxDepthRecursion(root->right);
    return 1 + max(leftSubTreeDepth, rightSubTreeDepth);
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
//     cout << "Maimum Depth : " << maxDepthRecursion(root) << endl;
//     return 0;
// }
// -------------------------------------------------------------------- 110. Balanced Binary Tree --------------------------------------------------------------------------
// A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
int dfsHeight(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int leftSubTreeDepth = dfsHeight(root->left);
    if (leftSubTreeDepth == -1)
        return -1;
    int rightSubTreeDepth = dfsHeight(root->right);
    if (rightSubTreeDepth == -1)
        return -1;
    if (abs(leftSubTreeDepth - rightSubTreeDepth) > 1)
        return -1;
    return 1 + max(leftSubTreeDepth, rightSubTreeDepth);
}
bool isBalanced(TreeNode *root)
{
    int result = dfsHeight(root);
    return result == -1 ? false : true;
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
//     cout << "Maimum Depth : " << isBalanced(root) << endl;
//     return 0;
// }
// -------------------------------------------------------------------- 543. Diameter of Binary Tree --------------------------------------------------------------------------
int diameterOfBinaryTreeHelper(TreeNode *root, int &diameter)
{
    int leftSubTtreeEdgeCount = 0;
    int rightSubtreeEdgeCount = 0;
    if (root->left != nullptr)
        leftSubTtreeEdgeCount = 1 + diameterOfBinaryTreeHelper(root->left, diameter);
    if (root->right != nullptr)
        rightSubtreeEdgeCount = 1 + diameterOfBinaryTreeHelper(root->right, diameter);
    diameter = max(diameter, leftSubTtreeEdgeCount + rightSubtreeEdgeCount);
    return max(leftSubTtreeEdgeCount, rightSubtreeEdgeCount);
}
int diameterOfBinaryTree(TreeNode *root)
{
    int diameter = 0;
    if (root == nullptr)
        return diameter;
    diameterOfBinaryTreeHelper(root, diameter);
    return diameter;
}
// --------------------------
int diameterOfBinaryTreeHelper2(TreeNode *root, int &diameter)
{
    if (root == nullptr)
        return 0;
    int leftSubTtreeEdgeCount = diameterOfBinaryTreeHelper2(root->left, diameter);
    int rightSubtreeEdgeCount = diameterOfBinaryTreeHelper2(root->right, diameter);
    diameter = max(diameter, leftSubTtreeEdgeCount + rightSubtreeEdgeCount);
    return max(leftSubTtreeEdgeCount, rightSubtreeEdgeCount) + 1;
}
int diameterOfBinaryTree2(TreeNode *root)
{
    int diameter = 0;
    diameterOfBinaryTreeHelper2(root, diameter);
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
//     root->right->left = new TreeNode(6);
//     root->right->right = new TreeNode(7);
//     cout << "Diameter Of Binary Tree : " << diameterOfBinaryTree2(root) << endl;
//     return 0;
// }
// -------------------------------------------------------------------- 124. Binary Tree Maximum Path Sum --------------------------------------------------------------------------
int maxPathSumRecursiveCall(TreeNode *root, int &maxPath)
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
int maxPathSum(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int maxPath = INT_MIN;
    maxPathSumRecursiveCall(root, maxPath);
    return maxPath;
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
    cout << "Maximum Path Sum : " << maxPathSum(root) << endl;
    return 0;
}