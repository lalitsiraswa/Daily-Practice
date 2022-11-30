#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;
    TreeNode(T data)
    {
        this->data = data;
    }
};

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
int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    levelOrderTraversal(root);
    cout << endl
         << "Total number of nodes are : " << countNodes(root) << endl;
    cout << "Height of the tree : " << heightOfTree(root) << endl;
    int levelNumberToFind;
    cout << endl
         << "Enter the level number you want to find nodes : ";
    cin >> levelNumberToFind;
    printNodesAtLevelK(root, levelNumberToFind);
}