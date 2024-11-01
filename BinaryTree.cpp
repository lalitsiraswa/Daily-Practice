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
    vector<int> result = topViewTUF_ORIGINAL(root);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ", ";
    }
    return 0;
}