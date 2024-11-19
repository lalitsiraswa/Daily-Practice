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
// --------------------------------------------------- 102. Binary Tree Level Order Traversal (BFS) --------------------------------------------------
vector<vector<int>> levelOrder(TreeNode *root)
{
    if (root == nullptr)
        return {};
    vector<vector<int>> levelOrderView;
    queue<TreeNode *> que;
    que.push(root);
    que.push(nullptr);
    vector<int> currLevel;
    while (!que.empty() && que.front() != nullptr)
    {
        TreeNode *node = que.front();
        currLevel.push_back(node->val);
        que.pop();
        if (node->left != nullptr)
            que.push(node->left);
        if (node->right != nullptr)
            que.push(node->right);
        if (que.front() == nullptr)
        {
            que.pop();
            que.push(nullptr);
            levelOrderView.push_back(currLevel);
            currLevel.clear();
        }
    }
    return levelOrderView;
}
// ----------------
vector<vector<int>> levelOrderOtherWay(TreeNode *root)
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
        for (int i = 1; i <= size; i++)
        {
            TreeNode *node = que.front();
            que.pop();
            if (node->left != nullptr)
                que.push(node->left);
            if (node->right != nullptr)
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
//     root->left->left = new TreeNode(4);
//     root->left->right = new TreeNode(5);
//     root->right = new TreeNode(3);
//     root->right->left = new TreeNode(6);
//     root->right->right = new TreeNode(7);
//     vector<vector<int>> levelOrderView = levelOrderOtherWay(root);
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ------------------------------------------------------------ 103. Binary Tree Zigzag Level Order Traversal -------------------------------------------------
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    if (root == nullptr)
        return {};
    vector<vector<int>> zigzagOrderView;
    queue<TreeNode *> que;
    que.push(root);
    que.push(nullptr);
    vector<int> currLevel;
    bool isEven = true;
    while (!que.empty() && que.front() != nullptr)
    {
        TreeNode *node = que.front();
        if (isEven)
            currLevel.push_back(node->val);
        else
            currLevel.insert(currLevel.begin(), node->val);
        que.pop();
        if (node->left)
            que.push(node->left);
        if (node->right)
            que.push(node->right);
        if (que.front() == nullptr)
        {
            isEven = !isEven;
            que.pop();
            que.push(nullptr);
            zigzagOrderView.push_back(currLevel);
            currLevel.clear();
        }
    }
    return zigzagOrderView;
}
// -----------------------
vector<vector<int>> zigzagLevelOrderOtherWay(TreeNode *root)
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
        vector<int> currLevel(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = que.front();
            que.pop();
            // Find position to fill node's value
            int index = (isLeftToRight) ? i : (size - 1 - i);
            currLevel[index] = node->val;
            if (node->left)
                que.push(node->left);
            if (node->right)
                que.push(node->right);
        }
        // after this level
        isLeftToRight = !isLeftToRight;
        zigzagOrderView.push_back(currLevel);
    }
    return zigzagOrderView;
}
// -----------------------------
vector<vector<int>> zigzagLevelOrderOtherWay2(TreeNode *root)
{
    if (root == nullptr)
        return {};
    vector<vector<int>> zigzagOrderView;
    deque<TreeNode *> dque;
    dque.push_back(root);
    bool reverse = false;
    while (!dque.empty())
    {
        int size = dque.size();
        zigzagOrderView.push_back({});
        for (int i = 0; i < size; i++)
        {
            if (!reverse)
            {
                TreeNode *node = dque.front();
                zigzagOrderView.back().push_back(node->val);
                dque.pop_front();
                if (node->left)
                    dque.push_back(node->left);
                if (node->right)
                    dque.push_back(node->right);
            }
            else
            {
                TreeNode *node = dque.back();
                zigzagOrderView.back().push_back(node->val);
                dque.pop_back();
                if (node->right)
                    dque.push_front(node->right);
                if (node->left)
                    dque.push_front(node->left);
            }
        }
        reverse = !reverse;
    }
    return zigzagOrderView;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     TreeNode *root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->left->left = new TreeNode(4);
//     root->left->right = new TreeNode(5);
//     root->right = new TreeNode(3);
//     root->right->left = new TreeNode(6);
//     root->right->right = new TreeNode(7);
//     vector<vector<int>> levelOrderView = zigzagLevelOrderOtherWay(root);
//     cout << endl
//          << string(35, '-');
//     return 0;
// }

// ------------------------------------------------------------ 116. Populating Next Right Pointers in Each Node ----------------------------------------------------
// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
Node *connect(Node *root)
{
    if (root == nullptr)
        return nullptr;
    queue<Node *> que;
    que.push(root);
    while (!que.empty())
    {
        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            Node *node = que.front();
            que.pop();
            if (node->left)
                que.push(node->left);
            if (node->right)
                que.push(node->right);
            if (i != size - 1)
                node->next = que.front();
        }
    }
    return root;
}
// --------------
Node *connectOtherWay(Node *root)
{
    if (root == nullptr)
        return nullptr;
    queue<Node *> que;
    que.push(root);
    que.push(nullptr);
    while (!que.empty() && que.front() != nullptr)
    {
        Node *node = que.front();
        que.pop();
        if (node->left)
            que.push(node->left);
        if (node->right)
            que.push(node->right);
        if (que.front() != nullptr)
            node->next = que.front();
        else
        {
            que.pop();
            que.push(nullptr);
        }
    }
    return root;
}
Node *PopulateNextPointers(Node *root)
{
    if (root == nullptr)
        return nullptr;
    Node *mostLeft = root;
    while (mostLeft->left != nullptr)
    {
        Node *current = mostLeft;
        while (current != nullptr)
        {
            current->left->next = current->right;
            if (current->next != nullptr)
                current->right->next = current->next->left;
            current = current->next;
        }
        mostLeft = mostLeft->left;
    }
    return root;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     Node *root = new Node(1);
//     root->left = new Node(2);
//     root->left->left = new Node(4);
//     root->left->right = new Node(5);
//     root->right = new Node(3);
//     root->right->left = new Node(6);
//     root->right->right = new Node(7);
//     connect(root);
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// -------------------------------------------------------------- 101. Symmetric Tree -------------------------------------------------------------------
bool isSymmetricDfsCall(TreeNode *left, TreeNode *right)
{
    if ((left != nullptr && right == nullptr) || (left == nullptr && right != nullptr))
        return false;
    if (left == nullptr && right == nullptr)
        return true;
    if (left->val != right->val)
        return false;
    if (!isSymmetricDfsCall(left->left, right->right))
        return false;
    if (!isSymmetricDfsCall(left->right, right->left))
        return false;
    return true;
}
bool isSymmetric(TreeNode *root)
{
    if (root == nullptr)
        return true;
    return isSymmetricDfsCall(root->left, root->right);
}
// --------------------------------
bool isSymmetricBfs(TreeNode *root)
{
    if (root == nullptr)
        return true;
    queue<TreeNode *> leftSubTree;
    queue<TreeNode *> rightSubTree;
    leftSubTree.push(root->left);
    rightSubTree.push(root->right);
    while (!leftSubTree.empty() && !rightSubTree.empty())
    {
        TreeNode *left = leftSubTree.front();
        leftSubTree.pop();
        TreeNode *right = rightSubTree.front();
        rightSubTree.pop();
        if (left == nullptr && right == nullptr)
            continue;
        if ((left == nullptr && right != nullptr) || (left != nullptr && right == nullptr))
            return false;
        if (left->val != right->val)
            return false;
        leftSubTree.push(left->left);
        rightSubTree.push(right->right);
        leftSubTree.push(left->right);
        rightSubTree.push(right->left);
    }
    return leftSubTree.empty() && rightSubTree.empty();
}
// --------------------------------
bool isSymmetricBfs2(TreeNode *root)
{
    if (root == nullptr)
        return true;
    queue<TreeNode *> queue;
    queue.push(root->left);
    queue.push(root->right);
    while (!queue.empty())
    {
        TreeNode *left = queue.front();
        queue.pop();
        TreeNode *right = queue.front();
        queue.pop();
        if (!left && !right)
            continue;
        if (!left || !right)
            return false;
        if (left->val != right->val)
            return false;
        queue.push(left->left);
        queue.push(right->right);
        queue.push(left->right);
        queue.push(right->left);
    }
    return true;
}
int main()
{
    cout << string(35, '-') << endl;
    // TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->left->left = new TreeNode(3);
    // root->left->right = new TreeNode(4);
    // root->right = new TreeNode(2);
    // root->right->left = new TreeNode(4);
    // root->right->right = new TreeNode(3);
    // -------------------------------------
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    cout << isSymmetricBfs2(root) << endl;
    cout << endl
         << string(35, '-');
    return 0;
}