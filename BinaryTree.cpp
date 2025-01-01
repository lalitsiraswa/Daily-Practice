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
//     cout << "Maximum Path Sum : " << maxPathSum(root) << endl;
//     return 0;
// }
// -------------------------------------------------------------------- 100. Same Tree --------------------------------------------------------------------------
bool isSameTree(TreeNode *p, TreeNode *q)
{
    // Base case: if both trees are null, they are identical
    if (p == nullptr && q == nullptr)
        return true;
    // If only one tree is null or the values are different, they are not identical
    if (p == nullptr || q == nullptr || p->val != q->val)
        return false;
    if (!isSameTree(p->left, q->left))
        return false;
    return isSameTree(p->right, q->right);
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     TreeNode *p = new TreeNode(1);
//     p->left = new TreeNode(2);
//     // p->right = new TreeNode(3);
//     TreeNode *q = new TreeNode(1);
//     q->left = new TreeNode(2);
//     q->right = new TreeNode(3);
//     cout << "Maximum Path Sum : " << isSameTree(p, q) << endl;
//     return 0;
// }
// --------------------------------------------------------------- 103. Binary Tree Zigzag Level Order Traversal ---------------------------------------------------------------------
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> result;
    if (root == nullptr)
        return result;
    queue<TreeNode *> q;
    q.push(root);
    bool isOddLevel = true;
    while (!q.empty())
    {
        vector<int> level;
        int queueSize = q.size();
        for (int i = 0; i < queueSize; i++)
        {
            TreeNode *treeNode = q.front();
            level.push_back(treeNode->val);
            if (treeNode->left)
                q.push(treeNode->left);
            if (treeNode->right)
                q.push(treeNode->right);
            q.pop();
        }
        if (!isOddLevel)
            reverse(level.begin(), level.end());
        result.push_back(level);
        isOddLevel = !isOddLevel;
    }
    return result;
}
// ------------------------------
vector<vector<int>> zigzagLevelOrder2(TreeNode *root)
{
    vector<vector<int>> result;
    if (root == nullptr)
        return result;
    deque<TreeNode *> q;
    q.push_back(root);
    bool isOddLevel = true;
    while (!q.empty())
    {
        vector<int> level;
        int queueSize = q.size();
        for (int i = 0; i < queueSize; i++)
        {
            TreeNode *treeNode = nullptr;
            if (isOddLevel)
            {
                treeNode = q.front();
                level.push_back(treeNode->val);
                if (treeNode->left)
                    q.push_back(treeNode->left);
                if (treeNode->right)
                    q.push_back(treeNode->right);
                q.pop_front();
            }
            else
            {
                treeNode = q.back();
                level.push_back(treeNode->val);
                if (treeNode->right)
                    q.push_front(treeNode->right);
                if (treeNode->left)
                    q.push_front(treeNode->left);
                q.pop_back();
            }
        }
        result.push_back(level);
        isOddLevel = !isOddLevel;
    }
    return result;
}
// ------------------------------
vector<vector<int>> zigzagLevelOrder3(TreeNode *root)
{
    vector<vector<int>> result;
    if (root == nullptr)
        return result;
    queue<TreeNode *> que;
    que.push(root);
    bool isLeftToRight = true;
    while (!que.empty())
    {
        int size = que.size();
        vector<int> level(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = que.front();
            // Find position to fill node's value
            int index = (isLeftToRight) ? i : (size - 1 - i);
            level[index] = node->val;
            if (node->left)
                que.push(node->left);
            if (node->right)
                que.push(node->right);
            que.pop();
        }
        // after this level
        isLeftToRight = !isLeftToRight;
        result.push_back(level);
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
//     vector<vector<int>> result = zigzagLevelOrder3(root);
//     for (int i = 0; i < result.size(); i++)
//     {
//         cout << "{";
//         for (int j = 0; j < result[i].size(); j++)
//         {
//             cout << result[i][j] << ", ";
//         }
//         cout << "}";
//     }
//     return 0;
// }
// --------------------------------------------------------------- Tree Boundary Traversal ---------------------------------------------------------------------
void leftBoundary(TreeNode *root, vector<int> &result)
{
    if (root == nullptr)
        return;
    if (root->left == nullptr && root->right == nullptr)
        return;
    result.push_back(root->val);
    if (root->left)
        leftBoundary(root->left, result);
    else
        leftBoundary(root->right, result);
}
void leafNodesInOrder(TreeNode *root, vector<int> &result)
{
    if (root == nullptr)
        return;
    if (root->left == nullptr && root->right == nullptr)
        result.push_back(root->val);
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
    else
        rightBoundary(root->left, s);
}
vector<int> boundary(TreeNode *root)
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
// -------------------------------------
// Function to check if a node is a leaf
bool isLeafNode(TreeNode *root)
{
    return !root->left && !root->right;
}
// Function to add the left boundary of the tree
void addLeftBoundary(TreeNode *root, vector<int> &result)
{
    TreeNode *current = root->left;
    while (current)
    {
        // If the current node is not a leaf, add its value to the result
        if (!isLeafNode(current))
        {
            result.push_back(current->val);
        }
        // Move to the left child if it exists, otherwise move to the right child
        if (current->left)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
}
// Function to add the right boundary of the tree
void addRightBoundary(TreeNode *root, vector<int> &result)
{
    TreeNode *current = root->right;
    vector<int> temp;
    while (current)
    {
        // If the current node is not a leaf, add its value to a temporary vector
        if (!isLeafNode(current))
        {
            temp.push_back(current->val);
        }
        // Move to the right child if it exists, otherwise move to the left child
        if (current->right)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }
    // Reverse and add the values from the temporary vector to the result
    for (int i = temp.size() - 1; i >= 0; --i)
    {
        result.push_back(temp[i]);
    }
}
// Function to add the leaves of the tree
void addLeaves(TreeNode *root, vector<int> &result)
{
    // If the current node is a leaf, add its value to the result
    if (isLeafNode(root))
    {
        result.push_back(root->val);
        return;
    }
    // Recursively add leaves of the left and right subtrees
    if (root->left)
    {
        addLeaves(root->left, result);
    }
    if (root->right)
    {
        addLeaves(root->right, result);
    }
}
vector<int> boundaryTUF(TreeNode *root)
{
    vector<int> result;
    if (root == nullptr)
        return result;
    // If the root is not a leaf, add its value to the result
    if (!isLeafNode(root))
    {
        result.push_back(root->val);
    }
    // Add the left boundary, leaves, and right boundary in order
    addLeftBoundary(root, result);
    addLeaves(root, result);
    addRightBoundary(root, result);
    return result;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     TreeNode *root = new TreeNode(1);
//     root->left = new TreeNode(100);
//     root->right = new TreeNode(2);
//     root->right->right = new TreeNode(3);
//     root->right->right->right = new TreeNode(4);
//     root->right->right->right->right = new TreeNode(5);
//     root->right->right->right->right->right = new TreeNode(6);
//     vector<int> result = boundary(root);
//     for (int i = 0; i < result.size(); i++)
//     {
//         cout << result[i] << ", ";
//     }
//     cout << endl
//          << string(35, '-') << endl;
//     return 0;
// }
// --------------------------------------------------------------- 987. Vertical Order Traversal of a Binary Tree ---------------------------------------------------------------------
void verticalTraversal(TreeNode *root, map<int, map<int, vector<int>>> &mp, int row, int column)
{
    if (root == nullptr)
        return;
    // Check if the column is exists or not
    if (mp.count(column))
    {
        // Check if the the row exits ot not
        if (mp[column].count(row))
        {
            mp[column][row].push_back(root->val);
            sort(mp[column][row].begin(), mp[column][row].end());
        }
        // if not add a new row;
        else
        {
            mp[column][row] = {root->val};
        }
    }
    // If column doesn't exists
    else
    {
        mp[column][row] = {root->val};
    }
    verticalTraversal(root->left, mp, row + 1, column - 1);
    verticalTraversal(root->right, mp, row + 1, column + 1);
}
vector<vector<int>> verticalTraversal(TreeNode *root)
{
    vector<vector<int>> result;
    // map<column, map<row, vector<int>>> mp;
    map<int, map<int, vector<int>>> mp;
    verticalTraversal(root, mp, 0, 0);
    for (auto &col : mp)
    {
        vector<int> temp;
        for (auto &row : col.second)
        {
            temp.insert(temp.end(), row.second.begin(), row.second.end());
        }
        result.push_back(temp);
    }
    return result;
}
// ----------------------------------------------------
vector<vector<int>> verticalTraversalTUF(TreeNode *root)
{
    // Map to store nodes based on vertical and level information
    map<int, map<int, multiset<int>>> nodes;
    // Queue for BFS traversal, each element is a pair containing node and its vertical and level information
    // vertical and level are like row and column
    queue<pair<TreeNode *, pair<int, int>>> todo;
    // Push the root node with initial vertical and level values (0, 0)
    todo.push({root, {0, 0}});
    // BFS traversal
    while (!todo.empty())
    {
        // Retrieve the node and its vertical and level information from the front of the queue
        auto p = todo.front();
        todo.pop();
        TreeNode *temp = p.first;
        // Extract the vertical and level information (row & column information)
        // x -> vertical
        int x = p.second.first;
        // y -> level
        int y = p.second.second;
        // Insert the node value into the corresponding vertical and level in the map
        nodes[x][y].insert(temp->val);
        // Process left child
        if (temp->left)
        {
            // Move left in terms of vertical and
            // Move down in terms of level
            todo.push({temp->left, {x - 1, y + 1}});
        }
        // Process right child
        if (temp->right)
        {
            // Move right interms of vertical and
            // Move down in terms of level
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
// ------------------------------------------
void verticalTraversalDFS(TreeNode *root, map<int, map<int, multiset<int>>> &mp, int row, int column)
{
    if (root == nullptr)
        return;
    mp[column][row].insert(root->val);
    verticalTraversalDFS(root->left, mp, row + 1, column - 1);
    verticalTraversalDFS(root->right, mp, row + 1, column + 1);
}
vector<vector<int>> verticalTraversalDFS(TreeNode *root)
{
    map<int, map<int, multiset<int>>> mp;
    verticalTraversalDFS(root, mp, 0, 0);
    vector<vector<int>> result;
    for (auto p : mp)
    {
        vector<int> col;
        for (auto q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        result.push_back(col);
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
//     vector<vector<int>> result = verticalTraversalDFS(root);
//     for (int i = 0; i < result.size(); i++)
//     {
//         cout << "{";
//         for (int j = 0; j < result[i].size(); j++)
//         {
//             cout << result[i][j] << ", ";
//         }
//         cout << "}";
//     }
//     return 0;
// }
// --------------------------------------------------------------- Top View of Binary Tree ---------------------------------------------------------------------
void topView(TreeNode *root, map<int, pair<int, int>> &mp, int row, int column)
{
    if (root == nullptr)
        return;
    if (!mp.count(column))
    {
        mp[column] = {row, root->val};
    }
    else if (mp.count(column) && mp[column].first > row)
    {
        mp[column] = {row, root->val};
    }
    topView(root->left, mp, row + 1, column - 1);
    topView(root->right, mp, row + 1, column + 1);
}

vector<int> topView(TreeNode *root)
{
    // map<column, pair<row, value>>, 'We only need to collect top element from the column'
    map<int, pair<int, int>> mp;
    vector<int> result;
    if (root == nullptr)
        return result;
    topView(root, mp, 0, 0);
    for (auto itr : mp)
    {
        result.push_back(itr.second.second);
    }
    return result;
}
// ----------------------------------------------
vector<int> topViewTUF_TRY(TreeNode *root)
{
    vector<int> result;
    if (root == nullptr)
        return result;
    // queue<pair<TreeNode *, pair<row, column>>> todo;
    queue<pair<TreeNode *, pair<int, int>>> todo;
    // map<column, pair<row, value>> mp;
    map<int, pair<int, int>> mp;
    todo.push({root, {0, 0}});
    while (!todo.empty())
    {
        auto front = todo.front();
        todo.pop();
        int row = front.second.first;
        int column = front.second.second;
        TreeNode *node = front.first;
        if (!mp.count(column))
        {
            mp[column] = {row, node->val};
        }
        else if (mp.count(column) && mp[column].first > row)
        {
            mp[column] = {row, node->val};
        }
        if (node->left)
            todo.push({node->left, {row + 1, column - 1}});
        if (node->right)
            todo.push({node->right, {row + 1, column + 1}});
    }
    for (auto itr : mp)
    {
        result.push_back(itr.second.second);
    }
    return result;
}
// ----------------------------------------------
vector<int> topViewTUF_ORIGINAL(TreeNode *root)
{
    // Vector to store the result
    vector<int> result;
    // Check if the tree is empty
    if (root == nullptr)
        return result;
    // Map to store the top view nodes based on their vertical/column positions
    map<int, int> mp;
    // Queue for BFS traversal, each element is a pair containing node and its vertical/column position
    queue<pair<TreeNode *, int>> q;
    // Push the root node with its vertical/column position (0) into the queue
    q.push({root, 0});
    // BFS traversal
    while (!q.empty())
    {
        // Retrieve the node and its vertical/column position from the front of the queue
        auto itr = q.front();
        q.pop();
        TreeNode *node = itr.first;
        int column = itr.second;
        // If the vertical/column position is not already in the map, add the node's data to the map
        if (mp.find(column) == mp.end())
        {
            mp[column] = node->val;
        }
        // Process left child
        if (node->left)
        { // Push the left child with a decreased vertical/column position into the queue
            q.push({node->left, column - 1});
        }
        // Process right child
        if (node->right)
        {
            // Push the right child with an increased vertical/column position into the queue
            q.push({node->right, column + 1});
        }
    }
    // Transfer values from the map to the result vector
    for (auto it : mp)
    {
        result.push_back(it.second);
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
//     vector<int> result = topViewTUF_ORIGINAL(root);
//     for (int i = 0; i < result.size(); i++)
//     {
//         cout << result[i] << ", ";
//     }
//     return 0;
// }
// --------------------------------------------------------------- Bottom View of Binary Tree ---------------------------------------------------------------------
vector<int> bottomViewTUF(TreeNode *root)
{
    // Vector to store the result
    vector<int> result;
    // Check if the tree is empty
    if (root == nullptr)
        return result;
    // Map to store the bottom view nodes based on their vertical/column positions
    map<int, int> mp;
    // Queue for BFS traversal, each element is a pair containing nodeand its vertical/column position
    queue<pair<TreeNode *, int>> q;
    // Push the root node with its vertical/column position (0) into the queue
    q.push({root, 0});
    // BFS traversal
    while (!q.empty())
    {
        // Retrieve the node and its vertical/column position from the front of the queue
        auto front = q.front();
        q.pop();
        TreeNode *node = front.first;
        int column = front.second;
        // Update the map with the node's data for the current vertical/column position
        mp[column] = node->val;
        // Process left child
        if (node->left)
        {
            // Push the left child with a decreased vertical/column position into the queue
            q.push({node->left, column - 1});
        }
        // Process right child
        if (node->right)
        {
            // Push the right child with an increased vertical/column position into the queue
            q.push({node->right, column + 1});
        }
    }
    // Transfer values from the map to the result vector
    for (auto itr : mp)
    {
        result.push_back(itr.second);
    }
    return result;
}
// ------------------------------------------
void fillBottomViewMap(TreeNode *root, map<int, pair<int, int>> &mp, int row, int column)
{
    if (root == nullptr)
        return;

    // Update the map if the current node is at a greater row depth or if the column is empty
    if (mp.find(column) == mp.end() || mp[column].first <= row)
    {
        mp[column] = {row, root->val};
    }
    // Recurse for the left and right children
    fillBottomViewMap(root->left, mp, row + 1, column - 1);
    fillBottomViewMap(root->right, mp, row + 1, column + 1);
}
vector<int> bottomView(TreeNode *root)
{
    vector<int> result;
    if (root == nullptr)
        return result;
    // Map to store the bottom-most node at each column
    map<int, pair<int, int>> mp; // {column: {row, value}}
    // Recursive call to fill the map
    fillBottomViewMap(root, mp, 0, 0);
    // Collect the values in column order
    for (const auto &itr : mp)
    {
        result.push_back(itr.second.second);
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
//     root->left->right->left = new TreeNode(8);
//     root->right->left = new TreeNode(6);
//     root->right->left->right = new TreeNode(9);
//     root->right->right = new TreeNode(7);
//     vector<int> result = bottomView(root);
//     for (int i = 0; i < result.size(); i++)
//     {
//         cout << result[i] << ", ";
//     }
//     return 0;
// }
// --------------------------------------------------------------- 199. Binary Tree Right Side View ---------------------------------------------------------------------
// --------------- DFS 'PREFERRED-ONE' ---------------
void rightSideViewDfsCall(TreeNode *root, vector<int> &rightSideViewList, int currLevel)
{
    if (root == nullptr)
        return;
    if (currLevel == rightSideViewList.size())
        rightSideViewList.push_back(root->val);
    rightSideViewDfsCall(root->right, rightSideViewList, currLevel + 1);
    rightSideViewDfsCall(root->left, rightSideViewList, currLevel + 1);
}
vector<int> rightSideView(TreeNode *root)
{
    if (root == nullptr)
        return {};
    vector<int> rightSideViewList;
    rightSideViewDfsCall(root, rightSideViewList, 0);
    return rightSideViewList;
}
// -----------------------------------
vector<int> rightSideViewBFS(TreeNode *root)
{
    vector<int> result;
    if (root == nullptr)
        return result;
    // map<level/row, value> mp;
    map<int, int> mp;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto front = q.front();
        q.pop();
        TreeNode *node = front.first;
        int level = front.second;
        mp[level] = node->val;
        if (node->left)
            q.push({node->left, level + 1});
        if (node->right)
            q.push({node->right, level + 1});
    }
    for (auto itr : mp)
    {
        result.push_back(itr.second);
    }
    return result;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     TreeNode *root = new TreeNode(0);
//     root->left = new TreeNode(1);
//     root->right = new TreeNode(2);
//     root->left->right = new TreeNode(3);
//     root->right->left = new TreeNode(4);
//     root->left->right->right = new TreeNode(5);
//     root->right->left->left = new TreeNode(6);
//     root->left->right->right->right = new TreeNode(7);
//     root->right->left->left->left = new TreeNode(8);
//     vector<int> result = rightSideView(root);
//     for (int i = 0; i < result.size(); i++)
//     {
//         cout << result[i] << ", ";
//     }
//     cout << endl
//          << string(35, '-') << endl;
//     return 0;
// }
// --------------------------------------------------------------- Left View of Binary Tree ---------------------------------------------------------------------
vector<int> leftView(TreeNode *root)
{
    vector<int> result;
    if (root == nullptr)
        return result;
    queue<pair<TreeNode *, int>> q;
    // map<level/row, value> mp;
    map<int, int> mp;
    q.push({root, 0});
    while (!q.empty())
    {
        auto front = q.front();
        q.pop();
        TreeNode *node = front.first;
        int level = front.second;
        if (mp.find(level) == mp.end())
            mp[level] = node->val;
        if (node->left)
            q.push({node->left, level + 1});
        if (node->right)
            q.push({node->right, level + 1});
    }
    for (auto itr : mp)
        result.push_back(itr.second);
    return result;
}
// -----------------------------
void leftSideViewDFSCall(TreeNode *root, vector<int> &rightSideViewList, int currLevel)
{
    if (root == nullptr)
        return;
    if (currLevel == rightSideViewList.size())
        rightSideViewList.push_back(root->val);
    leftSideViewDFSCall(root->left, rightSideViewList, currLevel + 1);
    leftSideViewDFSCall(root->right, rightSideViewList, currLevel + 1);
}
vector<int> leftViewDFS(TreeNode *root)
{
    if (root == nullptr)
        return {};
    vector<int> rightSideViewList;
    leftSideViewDFSCall(root, rightSideViewList, 0);
    return rightSideViewList;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     TreeNode *root = new TreeNode(0);
//     root->left = new TreeNode(1);
//     root->right = new TreeNode(2);
//     root->left->right = new TreeNode(3);
//     root->right->left = new TreeNode(4);
//     root->left->right->right = new TreeNode(5);
//     root->right->left->left = new TreeNode(6);
//     root->left->right->right->right = new TreeNode(7);
//     root->right->left->left->left = new TreeNode(8);
//     vector<int> result = leftViewDFS(root);
//     for (int i = 0; i < result.size(); i++)
//     {
//         cout << result[i] << ", ";
//     }
//     cout << endl
//          << string(35, '-') << endl;
//     return 0;
// }
// --------------------------------------------------------------- 101. Symmetric Tree ---------------------------------------------------------------------
bool isSymmetric(TreeNode *leftNode, TreeNode *rightNode)
{
    if (leftNode == nullptr || rightNode == nullptr)
        return (leftNode == rightNode);
    if (leftNode->val != rightNode->val)
        return false;
    if (!isSymmetric(leftNode->left, rightNode->right))
        return false;
    return isSymmetric(leftNode->right, rightNode->left);
}
bool isSymmetric(TreeNode *root)
{
    if (root == nullptr)
        return true;
    return isSymmetric(root->left, root->right);
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     TreeNode *root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(2);
//     root->left->left = new TreeNode(3);
//     root->left->right = new TreeNode(4);
//     root->right->left = new TreeNode(4);
//     root->right->right = new TreeNode(3);
//     cout << isSymmetric(root);
//     cout << endl
//          << string(35, '-') << endl;
//     return 0;
// }
// --------------------------------------------------------------- Root to Leaf Paths ---------------------------------------------------------------------
void Paths(TreeNode *root, vector<vector<int>> &paths, vector<int> &path)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        path.push_back(root->val);
        paths.push_back(path);
        path.pop_back();
        return;
    }
    path.push_back(root->val);
    if (root->left)
        Paths(root->left, paths, path);
    if (root->right)
        Paths(root->right, paths, path);
    path.pop_back();
}
vector<vector<int>> Paths(TreeNode *root)
{
    if (root == nullptr)
    {
        return {};
    }
    vector<vector<int>> paths;
    vector<int> path;
    Paths(root, paths, path);
    return paths;
}
// ------------ Root To Node Path ------------
bool rootToPaths(TreeNode *root, vector<vector<int>> &paths, vector<int> &path, TreeNode *target)
{
    if (root == nullptr)
        return false;
    path.push_back(root->val);
    if (root->val == target->val)
    {
        paths.push_back(path);
        return true;
    }
    if (rootToPaths(root->left, paths, path, target))
        return true;
    if (rootToPaths(root->right, paths, path, target))
        return true;
    path.pop_back();
    return false;
}
vector<vector<int>> rootToPaths(TreeNode *root, TreeNode *target)
{
    if (root == nullptr)
    {
        return {};
    }
    vector<vector<int>> paths;
    vector<int> path;
    rootToPaths(root, paths, path, target);
    return paths;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     TreeNode *root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(3);
//     root->left->left = new TreeNode(4);
//     root->left->right = new TreeNode(5);
//     vector<vector<int>> paths = rootToPaths(root, new TreeNode(5));
//     for (int i = 0; i < paths.size(); i++)
//     {
//         cout << "{";
//         for (int j = 0; j < paths[i].size(); j++)
//         {
//             cout << paths[i][j] << ", ";
//         }
//         cout << "}";
//     }
//     cout << endl
//          << string(35, '-') << endl;
//     return 0;
// }
// --------------------------------------------------------------- 236. Lowest Common Ancestor of a Binary Tree ---------------------------------------------------------------------
bool findPathFromRoot(TreeNode *root, vector<TreeNode *> &path, TreeNode *target)
{
    if (root == nullptr)
    {
        return false;
    }
    path.push_back(root);
    if (root->val == target->val)
    {
        return true;
    }
    if (findPathFromRoot(root->left, path, target))
    {
        return true;
    }
    if (findPathFromRoot(root->right, path, target))
    {
        return true;
    }
    path.pop_back();
    return false;
}
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    vector<TreeNode *> pathToReachP;
    vector<TreeNode *> pathToReachQ;
    // Contains the list of nodes from root to target node p:
    findPathFromRoot(root, pathToReachP, p);
    // Contains the list of nodes from root to target node q:
    findPathFromRoot(root, pathToReachQ, q);
    TreeNode *lowestAncenstor = nullptr;
    // Find the lowest common ancestor by comparing the path:
    int n = pathToReachP.size() < pathToReachQ.size() ? pathToReachP.size() : pathToReachQ.size();
    for (int index = 0; index < n; index++)
    {
        if (pathToReachP[index] == pathToReachQ[index])
        {
            lowestAncenstor = pathToReachP[index];
        }
        else
        {
            break;
        }
    }
    return lowestAncenstor;
}
// --------------------------
TreeNode *lowestCommonAncestorTuf(TreeNode *root, TreeNode *p, TreeNode *q)
{
    // Base Case
    if (root == nullptr || root == p || root == q)
        return root;
    TreeNode *leftSubtTree = lowestCommonAncestorTuf(root->left, p, q);
    TreeNode *rightSubTree = lowestCommonAncestorTuf(root->right, p, q);
    if (leftSubtTree == nullptr)
        return rightSubTree;
    if (rightSubTree == nullptr)
        return leftSubtTree;
    // Both left and right are not null, we found our result
    else
        return root;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     TreeNode *root = new TreeNode(3);
//     root->left = new TreeNode(5);
//     root->right = new TreeNode(1);
//     root->left->left = new TreeNode(6);
//     root->left->right = new TreeNode(2);
//     root->left->right->left = new TreeNode(7);
//     root->left->right->right = new TreeNode(4);
//     root->right->left = new TreeNode(0);
//     root->right->right = new TreeNode(8);
//     TreeNode *p = root->left;
//     TreeNode *q = root->left->right->right;
//     TreeNode *lowestAncestor = lowestCommonAncestorTuf(root, p, q);
//     cout << lowestAncestor->val;
//     cout << endl
//          << string(35, '-') << endl;
//     return 0;
// }
// --------------------------------------------------------------- 662. Maximum Width of Binary Tree ---------------------------------------------------------------------
// TRY BUT NOT WORKED
int widthOfBinaryTree(TreeNode *root)
{
    // Store level order traversal
    vector<vector<TreeNode *>> levelOrder;
    queue<TreeNode *> todo;
    todo.push(root);
    // Level with the maximum nodes
    int maxNodeLevel = 0;
    int maxNodeCount = 0;
    // Current level
    int level = -1;
    while (!todo.empty())
    {
        // Increment the level by 1
        level += 1;
        int size = todo.size();
        // Collect the nodes on current level
        vector<TreeNode *> currentLevel;
        bool isAllNull = true;
        int currentNodeCount = 0;
        for (int i = 1; i <= size; i++)
        {
            TreeNode *node = todo.front();
            if (node != nullptr)
            {
                currentNodeCount += 1;
                isAllNull = false;
            }
            todo.pop();
            currentLevel.push_back(node);
            if (node == nullptr)
            {
                todo.push(nullptr);
                todo.push(nullptr);
                continue;
            }
            if (node->left)
                todo.push(node->left);
            else
                todo.push(nullptr);
            if (node->right)
                todo.push(node->right);
            else
                todo.push(nullptr);
        }
        if (isAllNull == true)
        {
            break;
        }
        //  If currentNodeCount is greater than the maxNodeCount update the maxNodeLevel and maxNodeCount
        if (currentNodeCount >= maxNodeCount)
        {
            maxNodeLevel = level;
            maxNodeCount = currentNodeCount;
        }
        levelOrder.push_back(currentLevel);
    }
    vector<TreeNode *> levelWithMaxNode = levelOrder[maxNodeLevel];
    int maxWidth = levelWithMaxNode.size();
    int i = 0;
    // Ignore all the null nodes from the front
    while (levelWithMaxNode[i] == nullptr)
    {
        maxWidth -= 1;
        i += 1;
    }
    // Ignore all the nodes from the back
    i = levelWithMaxNode.size() - 1;
    while (levelWithMaxNode[i] == nullptr)
    {
        maxWidth -= 1;
        i -= 1;
    }
    return maxWidth;
}
// ---------------- TUF -------------------
// '0' based indexing
// Left : 2 * Index + 1;
// Right : 2 * Index + 2;
// Root Index : 0
// ----------------------
// '1' based indexing
// Left : 2 * Index;
// Right : 2 * Index + 1;
// Root Index : 1
int widthOfBinaryTreeTuf(TreeNode *root)
{
    // If the root is null, the width is zero:
    if (root == nullptr)
    {
        return 0;
    }
    // Initialize a variable 'maxWidth' to store the maximum width:
    int maxWidth = 0;
    // Create a queue to perform level-order traversal, where each element is a pair of TreeNode* and its position in the level:
    // queue<pair<TreeNode *, position>> todo;
    queue<pair<TreeNode *, int>> todo;
    // Push the root node and its position (0) into the queue:
    todo.push({root, 0});
    // Perform level-order traversal:
    while (!todo.empty())
    {
        // Get the number of nodes at the current level:
        int size = todo.size();
        // Get the position of the front node in the current level:
        int minValueOfLevel = todo.front().second;
        // Store the first and last positions of nodes in the current level:
        int firstPosition, lastPosition;
        // Process each node in the current level:
        for (int i = 0; i < size; i++)
        {
            // Calculate current position relative to the minimum position in the level:
            long long currPosition = todo.front().second - minValueOfLevel;
            // Get the current node:
            TreeNode *node = todo.front().first;
            // Pop the front node from the queue:
            todo.pop();
            // If this is the first node in the level, update the 'firstPosition' variable:
            if (i == 0)
            {
                firstPosition = currPosition;
            }
            // If this is the last node in the level, update the 'lastPosition' variable:
            if (i == size - 1)
            {
                lastPosition = currPosition;
            }
            // Enqueue the left child of the current node with its position:
            if (node->left)
            {
                todo.push({node->left, 2 * currPosition + 1});
            }
            // Enqueue the right child of the current node with its position:
            if (node->right)
            {
                todo.push({node->right, 2 * currPosition + 2});
            }
        }
        // Update the maximum width by calculating the difference between the first and last positions, and adding 1:
        maxWidth = max(maxWidth, (lastPosition - firstPosition) + 1);
    }
    // Return the maximum width of the binary tree:
    return maxWidth;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     TreeNode *root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->left->left = new TreeNode(4);
//     root->left->left->left = new TreeNode(8);
//     root->left->left->right = new TreeNode(9);
//     root->left->right = new TreeNode(5);
//     root->left->right->left = new TreeNode(10);
//     root->left->right->right = new TreeNode(11);
//     root->right = new TreeNode(3);
//     root->right->left = new TreeNode(6);
//     root->right->left->left = new TreeNode(12);
//     root->right->left->right = new TreeNode(13);
//     root->right->right = new TreeNode(7);
//     root->right->right->left = new TreeNode(14);
//     root->right->right->right = new TreeNode(15);
//     cout << widthOfBinaryTreeTuf(root);
//     cout << endl
//          << string(35, '-') << endl;
//     return 0;
// }
// --------------------------------------------------------------- 662. Maximum Width of Binary Tree ---------------------------------------------------------------------
int isSumPropertyHelper(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left = isSumPropertyHelper(root->left);
    if (left == -1)
    {
        return -1;
    }
    int right = isSumPropertyHelper(root->right);
    if (right == -1)
    {
        return -1;
    }
    if (left + right == 0)
    {
        return root->val;
    }
    if (left + right != root->val)
    {
        return -1;
    }
    return root->val;
}
int isSumProperty(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int result = isSumPropertyHelper(root);
    return result == -1 ? 0 : 1;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     TreeNode *root = new TreeNode(35);
//     root->left = new TreeNode(20);
//     root->left->left = new TreeNode(15);
//     root->left->right = new TreeNode(5);
//     root->right = new TreeNode(15);
//     root->right->left = new TreeNode(10);
//     root->right->right = new TreeNode(5);
//     cout << isSumProperty(root);
//     cout << endl
//          << string(35, '-') << endl;
//     return 0;
// }
// --------------------------------------------------------------- 662. Maximum Width of Binary Tree ---------------------------------------------------------------------
void makeParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_track, TreeNode *target)
{
    queue<TreeNode *> todo;
    todo.push(root);
    while (!todo.empty())
    {
        TreeNode *current = todo.front();
        todo.pop();
        if (current->left)
        {
            parent_track[current->left] = current;
            todo.push(current->left);
        }
        if (current->right)
        {
            parent_track[current->right] = current;
            todo.push(current->right);
        }
    }
}
vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    // node -> parent
    unordered_map<TreeNode *, TreeNode *> parent_track;
    makeParents(root, parent_track, target);
    unordered_map<TreeNode *, bool> visited;
    queue<TreeNode *> todo;
    todo.push(target);
    visited[target] = true;
    int current_level = 0;
    // Second BFS to go upto K level from target node, using our hashtable info. i.e parent_track:
    while (!todo.empty())
    {
        int size = todo.size();
        if (current_level == k)
        {
            break;
        }
        current_level += 1;
        for (int i = 0; i < size; i++)
        {
            TreeNode *current = todo.front();
            todo.pop();
            if (current->left && !visited[current->left])
            {
                todo.push(current->left);
                visited[current->left] = true;
            }
            if (current->right && !visited[current->right])
            {
                todo.push(current->right);
                visited[current->right] = true;
            }
            if (parent_track[current] && !visited[parent_track[current]])
            {
                todo.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }
    vector<int> result;
    while (!todo.empty())
    {
        TreeNode *current = todo.front();
        todo.pop();
        result.push_back(current->val);
    }
    return result;
}
int main()
{
    cout << string(35, '-') << endl;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    TreeNode *target = root->left;
    vector<int> result = distanceK(root, target, 2);
    for (auto item : result)
    {
        cout << item << ", ";
    }
    cout << endl
         << string(35, '-') << endl;
    return 0;
}