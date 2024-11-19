#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;
    TreeNode(T data) : data(data){};
    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
            delete children.at(i);
    }
};

void printTree(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << " : ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children.at(i)->data << " ";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children.at(i));
    }
}
TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter root node value : ";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int n;
    cout << "Enter number of children of " << rootData << " : ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}
TreeNode<int> *takeInputLevelWise()
{
    queue<TreeNode<int> *> q;
    TreeNode<int> *root = NULL;
    int rootData;
    cout << "Enter root data : ";
    cin >> rootData;
    root = new TreeNode<int>(rootData);
    q.push(root);
    while (!q.empty())
    {
        int n;
        cout << "Enter the number of children for " << q.front()->data << " : ";
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int data;
            cout << "Enter '" << i << "' child value : ";
            cin >> data;
            TreeNode<int> *child = new TreeNode<int>(data);
            q.front()->children.push_back(child);
            q.push(child);
        }
        q.pop();
    }
    return root;
}
void levelOrderPrint(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q;
    if (root == NULL)
        return;
    q.push(root);
    while (!q.empty())
    {
        cout << q.front()->data << " : ";
        for (int i = 0; i < q.front()->children.size(); i++)
        {
            cout << q.front()->children.at(i)->data << "  ";
            q.push(q.front()->children.at(i));
        }
        cout << endl;
        q.pop();
    }
}
int countTreeNodes(TreeNode<int> *root)
{
    int counter = 0;
    if (root == NULL)
    {
        return counter;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        counter += countTreeNodes(root->children.at(i));
    }
    return counter + 1;
}
int countNodes(TreeNode<int> *root)
{
    int static counter = 0;
    if (root == NULL)
        return counter;
    counter++;
    for (int i = 0; i < root->children.size(); i++)
    {
        countNodes(root->children.at(i));
    }
    return counter;
}
int heightOfTree(TreeNode<int> *root)
{
    int maxHeight = 0;
    if (root == NULL)
    {
        return maxHeight;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        int subTreeHeight = heightOfTree(root->children.at(i));
        maxHeight = (maxHeight < subTreeHeight) ? subTreeHeight : maxHeight;
    }
    return maxHeight + 1;
}
void printNodesAtLevelN(TreeNode<int> *root, int level)
{
    if (root == NULL)
        return;
    if (level == 0)
        cout << root->data << " ";
    else
    {
        level--;
        for (int i = 0; i < root->children.size(); i++)
        {
            printNodesAtLevelN(root->children.at(i), level);
        }
    }
}
// int countLeafNodes(TreeNode<int> *root)
// {
//     if (root == NULL)
//         return 0;
//     if (!root->children.size())
//         return 1;
//     int smallAnswer = 0;
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         smallAnswer += countLeafNodes(root->children.at(i));
//     }
//     return smallAnswer;
// }
//--------------------------------
// int countLeafNodes(TreeNode<int> *root)
// {
//     int static countLeafNode = 0;
//     if (root == NULL)
//         return 0;
//     if (!root->children.size())
//         countLeafNode++;
//     for(int i = 0; i < root->children.size(); i++){
//         countLeafNodes(root->children.at(i));
//     }
//     return countLeafNode;
// }
//--------------------------------
void countLeafNodes(TreeNode<int> *root, int &leafNodeCounter)
{
    if (root == NULL)
        return;
    if (!root->children.size())
        leafNodeCounter++;
    for (int i = 0; i < root->children.size(); i++)
        countLeafNodes(root->children.at(i), leafNodeCounter);
}
void preOrderTraversal(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
        preOrderTraversal(root->children.at(i));
}
void postOrderTraversal(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    for (int i = 0; i < root->children.size(); i++)
        postOrderTraversal(root->children.at(i));
    cout << root->data << " ";
}
void deleteTree(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    for (int i = 0; i < root->children.size(); i++)
        deleteTree(root->children.at(i));
    delete root;
}
// 1 3 2 3 4 2 5 6 0 1 9 0 2 7 8 0 0 0
// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    levelOrderPrint(root);
    // cout << "Number of total nodes are : " << countTreeNodes(root) << endl;
    cout << "Number of total nodes are : " << countNodes(root) << endl;
    cout << "Height of the Tree is : " << heightOfTree(root) << endl;
    cout << "Node at level 2 are ";
    // printNodesAtLevelN(root, 3);
    // int totalLeafNodes = 0;
    // countLeafNodes(root, totalLeafNodes);
    // cout << "Total Leaf Nodes Are : " << totalLeafNodes << endl;
    cout << "PreOrder Traversal : ";
    preOrderTraversal(root);
    cout << endl
         << "PostOrder Traversal : ";
    postOrderTraversal(root);

    // deleteTree(root);
    delete root;
    return 0;
}

// template <typename T>
// class TreeNode
// {
// public:
//     T data;
//     vector<TreeNode<T> *> children;
//     TreeNode(T data)
//     {
//         this->data = data;
//     }
// };

TreeNode<int> *takeInputLevelWise()
{
    queue<TreeNode<int> *> q;
    int rootData;
    cout << "Enter the root Data : ";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    q.push(root);
    while (!q.empty())
    {
        int n;
        cout << "Enter the number of children of " << q.front()->data << " : ";
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int childData;
            cout << "Enter the " << i << " th child of " << q.front()->data << " : ";
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            q.push(child);
            q.front()->children.push_back(child);
        }
        q.pop();
    }
    return root;
}
void printTree(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << " : ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children.at(i)->data << ", ";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children.at(i));
    }
}
void levelOrderTraversal(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q;
    if (root != NULL)
        q.push(root);
    while (!q.empty())
    {
        cout << q.front()->data << " : ";
        for (int i = 0; i < q.front()->children.size(); i++)
        {
            cout << q.front()->children.at(i)->data << ", ";
            q.push(q.front()->children.at(i));
        }
        cout << endl;
        q.pop();
    }
}
int countNodes(TreeNode<int> *root)
{
    if(root == NULL)
        return 0;
    int smallAnswer = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        smallAnswer += countNodes(root->children.at(i));
    }
    return 1 + smallAnswer;
}
int heightOfTree(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int smallAnswer = 0;
    int childrenHeight = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        childrenHeight = heightOfTree(root->children.at(i));
        smallAnswer = max(smallAnswer, childrenHeight);
    }
    return 1 + smallAnswer;
}
void printNodesAtLevelK(TreeNode<int> *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
    {
        cout << root->data << ", ";
    }
    if (k > 0)
    {
        for (int i = 0; i < root->children.size(); i++)
        {
            printNodesAtLevelK(root->children.at(i), k - 1);
        }
    }
}
// int main()
// {
//     TreeNode<int> *root = takeInputLevelWise();
//     levelOrderTraversal(root);
//     cout << endl
//          << "Total number of nodes are : " << countNodes(root) << endl;
//     cout << "Height of the tree : " << heightOfTree(root) << endl;
//     int levelNumberToFind;
//     cout << endl
//          << "Enter the level number you want to find nodes : ";
//     cin >> levelNumberToFind;
//     printNodesAtLevelK(root, levelNumberToFind);
// }