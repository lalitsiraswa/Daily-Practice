#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BTNode
{
public:
    T data;
    BTNode<T> *left;
    BTNode<T> *right;
    BTNode(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    ~BTNode()
    {
        delete left;
        delete right;
    }
};
// Print Tree Recursiverly
void printRecursively(BTNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << ": ";
    if (root->left != NULL)
        cout << "Left : " << root->left->data << ", ";
    if (root->right != NULL)
        cout << "Right : " << root->right->data;
    cout << endl;
    printRecursively(root->left);
    printRecursively(root->right);
}
BTNode<int> *takeInputRecursively()
{
    int rootData;
    cout << "Enter Data : ";
    cin >> rootData;
    if (rootData == -1)
        return NULL;
    BTNode<int> *root = new BTNode<int>(rootData);
    root->left = takeInputRecursively();
    root->right = takeInputRecursively();
    return root;
}
BTNode<int> *takeInputLevelWise()
{
    queue<BTNode<int> *> q;
    int rootData;
    cout << "Enter Root Data : ";
    cin >> rootData;
    if (rootData == -1)
        return NULL;
    BTNode<int> *root = new BTNode<int>(rootData);
    q.push(root);
    while (!q.empty())
    {
        int leftChild, rightChild;
        cout << "Enter left child of " << q.front()->data << " : ";
        cin >> leftChild;
        cout << "Enter right child of " << q.front()->data << " : ";
        cin >> rightChild;
        if (leftChild != -1)
        {
            q.front()->left = new BTNode<int>(leftChild);
            q.push(q.front()->left);
        }
        if (rightChild != -1)
        {
            q.front()->right = new BTNode<int>(rightChild);
            q.push(q.front()->right);
        }
        q.pop();
    }
    return root;
}
void printLevelOrder(BTNode<int> *root)
{
    queue<BTNode<int> *> q;
    if (root != NULL)
        q.push(root);
    while (!q.empty())
    {
        cout << q.front()->data << " : ";
        if (q.front()->left != NULL)
        {
            cout << "Left : " << q.front()->left->data << ", ";
            q.push(q.front()->left);
        }
        if (q.front()->right != NULL)
        {
            cout << "Right : " << q.front()->right->data;
            q.push(q.front()->right);
        }
        cout << endl;
        q.pop();
    }
}
void printLevelOrderOutherWay(BTNode<int> *root)
{
    queue<BTNode<int> *> q;
    if (root != NULL)
        q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        if (q.front() == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << q.front()->data << ", ";
            if (q.front()->left != NULL)
            {
                q.push(q.front()->left);
            }
            if (q.front()->right != NULL)
            {
                q.push(q.front()->right);
            }
            q.pop();
        }
    }
}
int countNodes(BTNode<int> *root)
{
    if (root == NULL)
        return 0;
    int smallAnswer = 0;
    if (root->left != NULL)
        smallAnswer += countNodes(root->left);
    if (root->right != NULL)
        smallAnswer += countNodes(root->right);
    return 1 + smallAnswer;
}
void InOrderTraversal(BTNode<int> *root)
{
    if (root != NULL)
    {
        InOrderTraversal(root->left);
        cout << root->data << ", ";
        InOrderTraversal(root->right);
    }
}
void preOrderTraversal(BTNode<int> *root)
{
    if (root != NULL)
    {
        cout << root->data << ", ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
// 1 2 3 4 5 6 -1 -1 -1 7 8 -1 -1 -1 -1 -1 -1
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
// 1 2 3 4 5 6 -1 -1 -1 -1 -1 -1 -1
int main()
{
    // BTNode<int> *root = takeInputRecursively();
    BTNode<int> *root = takeInputLevelWise();
    cout << endl;
    // printRecursively(root);
    // printLevelOrder(root);
    printLevelOrderOutherWay(root);
    cout << "Total number of nodes : " << countNodes(root) << endl;
    cout << "Inorder Traversal : ";
    InOrderTraversal(root);
    cout << endl;
    cout << "PreOrder Traversal : ";
    preOrderTraversal(root);
}