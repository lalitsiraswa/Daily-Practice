#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BTNode
{
public:
    T data;
    BTNode<T> *left;
    BTNode<T> *right;
    BTNode(T data) : data(data), left(nullptr), right(nullptr){};
    ~BTNode()
    {
        delete left;
        delete right;
    }
};
void printTreeRecusively(BTNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << " -> ";
    if (root->left)
        cout << "Left : " << root->left->data;
    if (root->right)
        cout << ", Right : " << root->right->data;
    cout << endl;
    printTreeRecusively(root->left);
    printTreeRecusively(root->right);
}
BTNode<int> *takeInputRecursively()
{
    int data;
    cout << "Enter Root Data : ";
    cin >> data;
    if (data == -1)
        return NULL;
    BTNode<int> *root = new BTNode<int>(data);
    root->left = takeInputRecursively();
    root->right = takeInputRecursively();
    return root;
}
BTNode<int> *takeInputLevelwise()
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
        int leftData, rightData;
        cout << "Enter Left Child Of " << q.front()->data << " : ";
        cin >> leftData;
        cout << "Enter Right Child Of " << q.front()->data << " : ";
        cin >> rightData;
        if (leftData != -1)
        {
            BTNode<int> *leftChild = new BTNode<int>(leftData);
            q.push(leftChild);
            q.front()->left = leftChild;
        }
        if (rightData != -1)
        {
            BTNode<int> *rightChild = new BTNode<int>(rightData);
            q.push(rightChild);
            q.front()->right = rightChild;
        }
        q.pop();
    }
    return root;
}
void printLevelwise(BTNode<int> *root)
{
    queue<BTNode<int> *> q;
    if (root == NULL)
        return;
    q.push(root);
    while (!q.empty())
    {
        BTNode<int> *front = q.front();
        q.pop();
        cout << front->data << " -> ";
        if (front->left)
        {
            cout << "Left : " << front->left->data;
            q.push(front->left);
        }
        if (front->right)
        {
            cout << ", Right : " << front->right->data;
            q.push(front->right);
        }
        cout << endl;
    }
}

void printLevelwiseCopy(BTNode<int> *root)
{
    queue<BTNode<int> *> q;
    if (root == NULL)
        return;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        BTNode<int> *front = q.front();
        q.pop();
        if (front == NULL)
        {
            if (q.empty())
                break;
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << front->data << "  ";
        if (front->left)
            q.push(front->left);
        if (front->right)
            q.push(front->right);
    }
}
void printLevelwiseOtherway(BTNode<int> *root)
{
    cout << endl;
    queue<BTNode<int> *> q;
    if (root == NULL)
        return;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        BTNode<int> *front = q.front();
        q.pop();
        if (front == NULL)
        {
            if (q.empty())
                break;
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << front->data << "  ";
        if (front->left)
            q.push(front->left);
        if (front->right)
            q.push(front->right);
    }
    cout << endl;
}
vector<vector<int>> levelOrder(BTNode<int> *root)
{
    vector<vector<int>> result;
    vector<int> subResult;
    queue<BTNode<int> *> q;
    if (root == NULL)
        return result;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        BTNode<int> *front = q.front();
        q.pop();
        if (front == NULL)
        {
            result.push_back(subResult);
            subResult.clear();
            if (q.empty())
                break;
            q.push(NULL);
            continue;
        }
        subResult.push_back(front->data);
        if (front->left)
            q.push(front->left);
        if (front->right)
            q.push(front->right);
    }
    return result;
}
int countNodes(BTNode<int> *root)
{
    if (root == NULL)
        return 0;
    int smallAnswer = 0;
    smallAnswer += countNodes(root->left);
    smallAnswer += countNodes(root->right);
    return smallAnswer + 1;
}
void inOrderTraversal(BTNode<int> *root)
{
    if (root == NULL)
        return;
    inOrderTraversal(root->left);
    cout << root->data << "  ";
    inOrderTraversal(root->right);
}
vector<int> inorderTraversalOtherway(BTNode<int> *root)
{
    static vector<int> answer;
    if (root == NULL)
        return answer;
    inorderTraversalOtherway(root->left);
    answer.push_back(root->data);
    inorderTraversalOtherway(root->right);
    return answer;
}
void preOrderTraversal(BTNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << "  ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void postOrderTraversal(BTNode<int> *root)
{
    if (root == NULL)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << "  ";
}
void inorderTraversalIteratively(BTNode<int> *root)
{
    stack<BTNode<int> *> s;
    unordered_map<BTNode<int> *, int> umap;
    if (root != NULL)
        s.push(root);
    while (!s.empty())
    {
        if (s.top()->left && !umap[s.top()->left])
            s.push(s.top()->left);
        else
        {
            BTNode<int> *top = s.top();
            umap[top] = 1;
            s.pop();
            cout << top->data << "  ";
            if (top->right && !umap[top->right])
                s.push(top->right);
        }
    }
}
void preOrderTraversalIteratively(BTNode<int> *root)
{
    stack<BTNode<int> *> s;
    if (root != NULL)
        s.push(root);
    while (!s.empty())
    {
        BTNode<int> *top = s.top();
        s.pop();
        cout << top->data << "  ";
        if (top->right)
            s.push(top->right);
        if (top->left)
            s.push(top->left);
    }
}
vector<int> inorderTraversalIterativelyOtherway(BTNode<int> *root)
{
    vector<int> result;
    stack<BTNode<int> *> s;
    BTNode<int> *current = root;
    while (current != NULL || !s.empty())
    {
        while (current != NULL)
        {
            s.push(current);
            current = current->left;
        }
        BTNode<int> *top = s.top();
        result.push_back(top->data);
        s.pop();
        current = top->right;
    }
    return result;
}
vector<int> postOrderTraversalIterativelyOtherway(BTNode<int> *root)
{
    vector<int> result;
    stack<BTNode<int> *> s;
    unordered_map<BTNode<int> *, int> umap;
    if (root != NULL)
        s.push(root);
    while (!s.empty())
    {
        BTNode<int> *top = s.top();
        if (top->right && !umap[top->right])
            s.push(top->right);
        if (top->left && !umap[top->left])
            s.push(top->left);
        if ((!top->left && !top->right) || (umap[top->left] && umap[top->right]))
        {
            cout << top->data << "  ";
            umap[top] = 1;
            s.pop();
        }
    }
    return result;
}
int maxDepthOfTree(BTNode<int> *root)
{
    if (root == NULL)
        return 0;
    int leftSubTreeDepth = maxDepthOfTree(root->left);
    int rightSubTreeDepth = maxDepthOfTree(root->right);
    return 1 + max(leftSubTreeDepth, rightSubTreeDepth);
}
bool isSymmetricBinaryTree(BTNode<int> *leftRoot, BTNode<int> *rightRoot)
{
    if (leftRoot == NULL && rightRoot == NULL)
        return true;
    if ((leftRoot == NULL && rightRoot != NULL) || leftRoot != NULL && rightRoot == NULL)
        return false;
    if (leftRoot->data != rightRoot->data)
        return false;
    if (!isSymmetricBinaryTree(leftRoot->left, rightRoot->right))
        return false;
    if (!isSymmetricBinaryTree(leftRoot->right, rightRoot->left))
        return false;
    return true;
}
bool findNode(BTNode<int> *root, int target)
{
    if (root == NULL)
        return false;
    if (root->data == target)
        return true;
    // if(findNode(root->left, target))
    //     return true;
    // if(findNode(root->right, target))
    //     return true;
    // return false;
    return (findNode(root->left, target) || findNode(root->right, target));
}
int minValueOfBT(BTNode<int> *root)
{
    if (root == NULL)
        return INT_MAX;
    int leftSubTreeSmallValue = INT_MAX;
    int rightSubTreeSmallValue = INT_MAX;
    if (root->left)
        leftSubTreeSmallValue = minValueOfBT(root->left);
    if (root->right)
        rightSubTreeSmallValue = minValueOfBT(root->right);
    return min(min(leftSubTreeSmallValue, rightSubTreeSmallValue), root->data);
}
int minValueOfBTOtherway(BTNode<int> *root)
{
    if (root == NULL)
        return INT_MAX;
    int leftMin = minValueOfBTOtherway(root->left);
    int rightMin = minValueOfBTOtherway(root->right);
    return min(min(leftMin, rightMin), root->data);
}
int minValueInBT(BTNode<int> *root, int minValue = INT_MAX)
{
    if (root == NULL)
        return 0;
    if (root->data < minValue)
        minValue = root->data;
    if (root->left)
        minValue = minValueInBT(root->left, minValue);
    if (root->right)
        minValue = minValueInBT(root->right, minValue);
    return minValue;
}
int maxValueInBT(BTNode<int> *root)
{
    if (root == NULL)
        return INT_MIN;
    int leftMax = INT_MIN;
    int rightMax = INT_MIN;
    if (root->left)
        leftMax = maxValueInBT(root->left);
    if (root->right)
        rightMax = maxValueInBT(root->right);
    return max(max(leftMax, rightMax), root->data);
}
int maxValueInBTOtherWay(BTNode<int> *root)
{
    if (root == NULL)
        return INT_MIN;
    int leftMax = maxValueInBTOtherWay(root->left);
    int rightMax = maxValueInBTOtherWay(root->right);
    return max(max(leftMax, rightMax), root->data);
}
int countLeafNodes(BTNode<int> *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    int leftSubTreeLeafNodeCount = countLeafNodes(root->left);
    int rightSubTreeLeafNodeCount = countLeafNodes(root->right);
    return leftSubTreeLeafNodeCount + rightSubTreeLeafNodeCount;
}
int findElementInVector(int targer, vector<int> vect)
{
    for (int i = 0; i < vect.size(); i++)
    {
        if (targer == vect.at(i))
            return i;
    }
    return -1;
}
BTNode<int> *preAndInorder(BTNode<int> *root, int &targetIndex, vector<int> preOrder, vector<int> vect)
{
    if (targetIndex > preOrder.size() - 1)
        return NULL;
    int index = findElementInVector(preOrder.at(targetIndex), vect);
    if (index == -1)
        return NULL;
    vector<int> leftSubTree(vect.begin(), vect.begin() + index);
    vector<int> rightSubTree(vect.begin() + index + 1, vect.end());
    root = new BTNode(preOrder.at(targetIndex));
    root->left = preAndInorder(root, ++targetIndex, preOrder, leftSubTree);
    root->right = preAndInorder(root, targetIndex, preOrder, rightSubTree);
    return root;
}
BTNode<int> *constructTreeFromPreAndInOrder(vector<int> preOrder, vector<int> inOrder)
{
    BTNode<int> *root = NULL;
    int targetIndex = 0;
    int index = findElementInVector(preOrder.at(targetIndex), inOrder);
    vector<int> leftSubTree(inOrder.begin(), inOrder.begin() + index);
    vector<int> rightSubTree(inOrder.begin() + index + 1, inOrder.end());
    root = new BTNode(preOrder.at(targetIndex));
    root->left = preAndInorder(root, ++targetIndex, preOrder, leftSubTree);
    root->right = preAndInorder(root, targetIndex, preOrder, rightSubTree);
    return root;
}
// 1 2 3 4 5 6 -1 -1 -1 7 8 -1 -1 -1 -1 -1 -1
// 1 2 3 4 5 -1 7 -1 -1 -1 6 -1 -1 -1 -1
int main()
{
    // BTNode<int> *root = takeInputLevelwise();
    // printLevelwiseOtherway(root);
    // --------------------------------------------
    // vector<int> preOrder = {1, 2, 4, 3, 5, 7, 8, 6};
    // vector<int> inOrder = {4, 2, 1, 7, 5, 8, 3, 6};
    vector<int> preOrder = {3, 9, 20, 15, 7};
    vector<int> inOrder = {9, 3, 15, 20, 7};
    BTNode<int> *root = constructTreeFromPreAndInOrder(preOrder, inOrder);
    printLevelwiseOtherway(root);
    // --------------------------------------------
    // cout << "LeafNode Count : " << countLeafNodes(root) << endl;
    // -------------------------------------------
    // cout << "MAX VALUE : " << maxValueInBT(root);
    // --------------------------------------------
    // cout << "MIN VALUE : " << minValueInBT(root);
    //----------------------------------------------
    // cout << "Find Node : " << findNode(root, 12);
    // ----------------------------------------------
    // cout << "Is Symmentric Tree : " << isSymmetricBinaryTree(root->left, root->right);
    // cout << "Max Depth Of The Tree : " << maxDepthOfTree(root) << endl;
    //-----------------------------------------------
    // printTreeRecusively(root);
    // printLevelwiseOtherway(root);
    // cout << "Total Node Count Is : " << countNodes(root) << endl;
    // inorderTraversalIteratively(root);
    // postOrderTraversalIterativelyOtherway(root);
    //------------------------------------------------
    // cout << "Inorder Traversal : ";
    // inOrderTraversal(root);
    // cout << endl;
    // cout << "PreOrder Traversal : ";
    // preOrderTraversal(root);
    // cout << endl;
    // cout << "PostOrder Traversal : ";
    // postOrderTraversal(root);
    //------------------------------------------------
    // vector<int> answer = inorderTraversalOtherway(root);
    // cout << "Inorder Traversal : ";
    // for (auto item : answer)
    //     cout << item << "  ";
    //-------------------------------------------------
    // vector<vector<int>> result = levelOrder(root);
    // cout << endl;
    // for (int i = 0; i < result.size(); i++)
    // {
    //     cout << "[ ";
    //     for (int j = 0; j < result.at(i).size(); j++)
    //     {
    //         cout << result.at(i).at(j) << ", ";
    //     }
    //     cout << " ]" << endl;
    // }
    //--------------------------------------------------
    // delete root;
    return 0;
}