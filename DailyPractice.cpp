#include <bits/stdc++.h>
using namespace std;

//------------------------------------------------------------ 2256. Minimum Average Difference ----------------------------------------------------------
int minimumAverageDifference(vector<int> &nums)
{
    int totalSum = 0;
    for (auto item : nums)
        totalSum += item;
    int n = nums.size();
    int minimumAverageIndex = 0;
    int currentMinimumAverage = INT_MAX;
    int leftSideSum = 0;
    int rightSideSum = 0;
    int currentAverage;
    for (int i = 0; i < n; i++)
    {
        leftSideSum += nums[i];
        rightSideSum = totalSum - leftSideSum;
        if (rightSideSum == 0)
        {
            currentAverage = abs(abs(leftSideSum / (i + 1)) - rightSideSum);
        }
        else
        {
            currentAverage = abs(abs(leftSideSum / (i + 1)) - abs(rightSideSum / (n - i - 1)));
        }
        if (currentAverage < currentMinimumAverage)
        {
            currentMinimumAverage = currentAverage;
            minimumAverageIndex = i;
        }
    }
    return minimumAverageIndex;
}
// int main()
// {
//     vector<int> nums{0};
//     cout << minimumAverageDifference(nums);
// }
//------------------------------------------------------------ Count Leaf Nodes ----------------------------------------------------------
// template <typename T>
// class BTNode
// {
// public:
//     T data;
//     BTNode<T> *left;
//     BTNode<T> *right;
//     BTNode(T data)
//     {
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
//     ~BTNode()
//     {
//         delete left;
//         delete right;
//     }
// };
// BTNode<int> *takeInputLevelWise()
// {
//     queue<BTNode<int> *> q;
//     int rootData;
//     cout << "Enter Root Data : ";
//     cin >> rootData;
//     if (rootData == -1)
//         return NULL;
//     BTNode<int> *root = new BTNode<int>(rootData);
//     q.push(root);
//     while (!q.empty())
//     {
//         int leftChild, rightChild;
//         cout << "Enter left child of " << q.front()->data << " : ";
//         cin >> leftChild;
//         cout << "Enter right child of " << q.front()->data << " : ";
//         cin >> rightChild;
//         if (leftChild != -1)
//         {
//             q.front()->left = new BTNode<int>(leftChild);
//             q.push(q.front()->left);
//         }
//         if (rightChild != -1)
//         {
//             q.front()->right = new BTNode<int>(rightChild);
//             q.push(q.front()->right);
//         }
//         q.pop();
//     }
//     return root;
// }
// void printLevelOrder(BTNode<int> *root)
// {
//     queue<BTNode<int> *> q;
//     if (root != NULL)
//         q.push(root);
//     while (!q.empty())
//     {
//         cout << q.front()->data << " : ";
//         if (q.front()->left != NULL)
//         {
//             cout << "Left : " << q.front()->left->data << ", ";
//             q.push(q.front()->left);
//         }
//         if (q.front()->right != NULL)
//         {
//             cout << "Right : " << q.front()->right->data;
//             q.push(q.front()->right);
//         }
//         cout << endl;
//         q.pop();
//     }
// }
// int countLeafNodes(BTNode<int> *root){
//     if(root == NULL)
//         return 0;
//     int leftSubTreeLeafNodes = countLeafNodes(root->left);
//     int rightSubTreeLeafNodes = countLeafNodes(root->right);
//     if(root->left == NULL && root->right == NULL)
//         return 1+leftSubTreeLeafNodes+rightSubTreeLeafNodes;
//     return leftSubTreeLeafNodes+rightSubTreeLeafNodes;
// }
// // 3 9 20 -1 -1  15 7 -1 -1 -1 -1
// // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
// // 1 2 3 4 5 6 -1 -1 -1 -1 -1 -1 -1
// // 4 7 12 8 -1 -1 7 5 9 -1 -1 -1 6 -1 -1 -1 -1
// // 1 2 2 3 4 4 3 -1 -1 -1 -1 -1 -1 -1 -1
// // 1 2 2 -1 3 -1 3 -1 -1 -1 -1
// // 7 -64 -64 -1 -90 -90 -6 88 -44 68 -65 -76 68 -44 88 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
// // 1 2 3 4 5 -1 7 -1 -1 -1 90 -1 -1 -1 -1
// // 3 2 1 -1 -1 -1 -1
// int main()
// {
//     BTNode<int> *root = takeInputLevelWise();
//     cout << "Level Order Travelersal" << endl;
//     printLevelOrder(root);
//     cout << "Count Leaf Node : " << countLeafNodes(root);
// }
// //------------------------------------------------------------ MAX VALUE IN A TREE ----------------------------------------------------------
// template <typename T>
// class BTNode
// {
// public:
//     T data;
//     BTNode<T> *left;
//     BTNode<T> *right;
//     BTNode(T data)
//     {
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
//     ~BTNode()
//     {
//         delete left;
//         delete right;
//     }
// };
// BTNode<int> *takeInputLevelWise()
// {
//     queue<BTNode<int> *> q;
//     int rootData;
//     cout << "Enter Root Data : ";
//     cin >> rootData;
//     if (rootData == -1)
//         return NULL;
//     BTNode<int> *root = new BTNode<int>(rootData);
//     q.push(root);
//     while (!q.empty())
//     {
//         int leftChild, rightChild;
//         cout << "Enter left child of " << q.front()->data << " : ";
//         cin >> leftChild;
//         cout << "Enter right child of " << q.front()->data << " : ";
//         cin >> rightChild;
//         if (leftChild != -1)
//         {
//             q.front()->left = new BTNode<int>(leftChild);
//             q.push(q.front()->left);
//         }
//         if (rightChild != -1)
//         {
//             q.front()->right = new BTNode<int>(rightChild);
//             q.push(q.front()->right);
//         }
//         q.pop();
//     }
//     return root;
// }
// void printLevelOrder(BTNode<int> *root)
// {
//     queue<BTNode<int> *> q;
//     if (root != NULL)
//         q.push(root);
//     while (!q.empty())
//     {
//         cout << q.front()->data << " : ";
//         if (q.front()->left != NULL)
//         {
//             cout << "Left : " << q.front()->left->data << ", ";
//             q.push(q.front()->left);
//         }
//         if (q.front()->right != NULL)
//         {
//             cout << "Right : " << q.front()->right->data;
//             q.push(q.front()->right);
//         }
//         cout << endl;
//         q.pop();
//     }
// }
// int maxValueInTree(BTNode<int> *root){
//     if(root == NULL)
//         return INT_MIN;
//     int leftMaxValue = maxValueInTree(root->left);
//     int rightMaxValue = maxValueInTree(root->right);
//     return max(root->data, max(leftMaxValue, rightMaxValue));
// }
// int maxValueInTreeOtherWay(BTNode<int> *root){
//     if(root == NULL)
//         return 0;
//     int leftTreeMaxVal = INT_MIN;
//     int rightTreeMaxVal = INT_MIN;
//     if(root->left) leftTreeMaxVal = maxValueInTreeOtherWay(root->left);
//     if(root->right) rightTreeMaxVal = maxValueInTreeOtherWay(root->right);
//     return max(root->data, max(leftTreeMaxVal, rightTreeMaxVal));
// }
// // 3 9 20 -1 -1  15 7 -1 -1 -1 -1
// // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
// // 1 2 3 4 5 6 -1 -1 -1 -1 -1 -1 -1
// // 4 7 12 8 -1 -1 7 5 9 -1 -1 -1 6 -1 -1 -1 -1
// // 1 2 2 3 4 4 3 -1 -1 -1 -1 -1 -1 -1 -1
// // 1 2 2 -1 3 -1 3 -1 -1 -1 -1
// // 7 -64 -64 -1 -90 -90 -6 88 -44 68 -65 -76 68 -44 88 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
// // 1 2 3 4 5 -1 7 -1 -1 -1 90 -1 -1 -1 -1
// // 3 2 1 -1 -1 -1 -1
// int main()
// {
//     BTNode<int> *root = takeInputLevelWise();
//     cout << "Level Order Travelersal" << endl;
//     printLevelOrder(root);
//     cout << "Max Value In Tree : " << maxValueInTreeOtherWay(root);
// }
// //----------------------------------------------------- MIN VALUE IN A TREE ------------------------------------------------------
// template <typename T>
// class BTNode
// {
// public:
//     T data;
//     BTNode<T> *left;
//     BTNode<T> *right;
//     BTNode(T data)
//     {
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
//     ~BTNode()
//     {
//         delete left;
//         delete right;
//     }
// };
// BTNode<int> *takeInputLevelWise()
// {
//     queue<BTNode<int> *> q;
//     int rootData;
//     cout << "Enter Root Data : ";
//     cin >> rootData;
//     if (rootData == -1)
//         return NULL;
//     BTNode<int> *root = new BTNode<int>(rootData);
//     q.push(root);
//     while (!q.empty())
//     {
//         int leftChild, rightChild;
//         cout << "Enter left child of " << q.front()->data << " : ";
//         cin >> leftChild;
//         cout << "Enter right child of " << q.front()->data << " : ";
//         cin >> rightChild;
//         if (leftChild != -1)
//         {
//             q.front()->left = new BTNode<int>(leftChild);
//             q.push(q.front()->left);
//         }
//         if (rightChild != -1)
//         {
//             q.front()->right = new BTNode<int>(rightChild);
//             q.push(q.front()->right);
//         }
//         q.pop();
//     }
//     return root;
// }
// void printLevelOrder(BTNode<int> *root)
// {
//     queue<BTNode<int> *> q;
//     if (root != NULL)
//         q.push(root);
//     while (!q.empty())
//     {
//         cout << q.front()->data << " : ";
//         if (q.front()->left != NULL)
//         {
//             cout << "Left : " << q.front()->left->data << ", ";
//             q.push(q.front()->left);
//         }
//         if (q.front()->right != NULL)
//         {
//             cout << "Right : " << q.front()->right->data;
//             q.push(q.front()->right);
//         }
//         cout << endl;
//         q.pop();
//     }
// }
// int minValueInTree(BTNode<int>  *root, int minValue = INT_MAX){
//     if(root == NULL)
//         return 0;
//     if(root->data < minValue)
//         minValue = root->data;
//     if(root->left != NULL)
//         minValue = minValueInTree(root->left, minValue);
//     if(root->right != NULL)
//         minValue = minValueInTree(root->right, minValue);
//     return minValue;
// }
// // int minValueInTreeOtherWay(BTNode<int>  *root){
// //     if(root == NULL)
// //         return 0;
// //     int leftTreeMinValue = INT_MAX;
// //     int rightTreeMinValue = INT_MAX;
// //     if(root->left != NULL)
// //         leftTreeMinValue = minValueInTreeOtherWay(root->left);
// //     if(root->right != NULL)
// //         rightTreeMinValue = minValueInTreeOtherWay(root->right);
// //     return min(min(leftTreeMinValue, rightTreeMinValue), root->data);
// // }

// int minValueInTreeOtherWay(BTNode<int>  *root){
//     if(root == NULL)
//         return INT_MAX;
//     int leftMin = minValueInTreeOtherWay(root->left);
//     int rightMin = minValueInTreeOtherWay(root->right);
//     return min(root->data, min(leftMin, rightMin));
// }

// // 3 9 20 -1 -1  15 7 -1 -1 -1 -1
// // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
// // 1 2 3 4 5 6 -1 -1 -1 -1 -1 -1 -1
// // 4 7 12 8 -1 -1 7 5 9 -1 -1 -1 6 -1 -1 -1 -1
// // 1 2 2 3 4 4 3 -1 -1 -1 -1 -1 -1 -1 -1
// // 1 2 2 -1 3 -1 3 -1 -1 -1 -1
// // 7 -64 -64 -1 -90 -90 -6 88 -44 68 -65 -76 68 -44 88 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
// // 1 2 3 4 5 -1 7 -1 -1 -1 -6 -1 -1 -1 -1
// // 3 2 1 -1 -1 -1 -1
// int main()
// {
//     BTNode<int> *root = takeInputLevelWise();
//     cout << "Level Order Travelersal" << endl;
//     printLevelOrder(root);
//     cout << "MIN VALUE IN TREE : " << minValueInTreeOtherWay(root);
// }
//-------------------------------------------------------------- FIND NODE -------------------------------------------------------------

// template <typename T>
// class BTNode
// {
// public:
//     T data;
//     BTNode<T> *left;
//     BTNode<T> *right;
//     BTNode(T data)
//     {
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
//     ~BTNode()
//     {
//         delete left;
//         delete right;
//     }
// };
// BTNode<int> *takeInputLevelWise()
// {
//     queue<BTNode<int> *> q;
//     int rootData;
//     cout << "Enter Root Data : ";
//     cin >> rootData;
//     if (rootData == -1)
//         return NULL;
//     BTNode<int> *root = new BTNode<int>(rootData);
//     q.push(root);
//     while (!q.empty())
//     {
//         int leftChild, rightChild;
//         cout << "Enter left child of " << q.front()->data << " : ";
//         cin >> leftChild;
//         cout << "Enter right child of " << q.front()->data << " : ";
//         cin >> rightChild;
//         if (leftChild != -1)
//         {
//             q.front()->left = new BTNode<int>(leftChild);
//             q.push(q.front()->left);
//         }
//         if (rightChild != -1)
//         {
//             q.front()->right = new BTNode<int>(rightChild);
//             q.push(q.front()->right);
//         }
//         q.pop();
//     }
//     return root;
// }
// void printLevelOrder(BTNode<int> *root)
// {
//     queue<BTNode<int> *> q;
//     if (root != NULL)
//         q.push(root);
//     while (!q.empty())
//     {
//         cout << q.front()->data << " : ";
//         if (q.front()->left != NULL)
//         {
//             cout << "Left : " << q.front()->left->data << ", ";
//             q.push(q.front()->left);
//         }
//         if (q.front()->right != NULL)
//         {
//             cout << "Right : " << q.front()->right->data;
//             q.push(q.front()->right);
//         }
//         cout << endl;
//         q.pop();
//     }
// }
// bool searchNode(BTNode<int> *root, int key){
//     int smallAnswer;
//     if(root == NULL)
//         return false;
//     if(root->data == key)
//         return true;
//     smallAnswer = searchNode(root->left, key);
//     if(smallAnswer) return true;
//     smallAnswer = searchNode(root->right, key);
//     if(smallAnswer) return true;
//     return false;
// }
// // 3 9 20 -1 -1  15 7 -1 -1 -1 -1
// // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
// // 1 2 3 4 5 6 -1 -1 -1 -1 -1 -1 -1
// // 4 7 12 8 -1 -1 7 5 9 -1 -1 -1 6 -1 -1 -1 -1
// // 1 2 2 3 4 4 3 -1 -1 -1 -1 -1 -1 -1 -1
// // 1 2 2 -1 3 -1 3 -1 -1 -1 -1
// // 7 -64 -64 -1 -90 -90 -6 88 -44 68 -65 -76 68 -44 88 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
// // 1 2 3 4 5 -1 7 -1 -1 -1 6 -1 -1 -1 -1
// int main()
// {
//     BTNode<int> *root = takeInputLevelWise();
//     cout << "Level Order Travelersal" << endl;
//     printLevelOrder(root);
//     cout << "SearchNode : " << searchNode(root, 4);
// }
//-------------------------------------------------------------- 1704. Determine if String Halves Are Alike -------------------------------------------------------------
// bool halvesAreAlike(string s)
// {
//     int n = s.size();
//     int leftHalfVowelCount = 0;
//     int rightHalfVowelCount = 0;
//     string lowerCharacterString = "";
//     for (int i = 0; i < s.size(); i++)
//         lowerCharacterString += tolower(s[i]);
//     for (int i = 0; i < n; i++)
//     {
//         if (lowerCharacterString[i] == 'a' || lowerCharacterString[i] == 'e' || lowerCharacterString[i] == 'i' || lowerCharacterString[i] == 'o' || lowerCharacterString[i] == 'u')
//         {
//             if (i < (n / 2))
//                 leftHalfVowelCount++;
//             else
//                 rightHalfVowelCount++;
//         }
//     }
//     if(leftHalfVowelCount == rightHalfVowelCount) return true;
//     return false;
// }
//-------------- Wrong Answer--------------
// bool halvesAreAlike(string s)
// {
//     int n = s.size();
//     int a[26] = {0};
//     int b[26] = {0};
//     string lowerCharacterString = "";
//     for (int i = 0; i < s.size(); i++)
//         lowerCharacterString += tolower(s[i]);
//     cout << lowerCharacterString << endl;
//     for (int i = 0; i < n; i++)
//     {
//         if (lowerCharacterString[i] == 'a' || lowerCharacterString[i] == 'e' || lowerCharacterString[i] == 'i' || lowerCharacterString[i] == 'o' || lowerCharacterString[i] == 'u')
//         {
//             if (i < (n / 2))
//             {
//                 a[lowerCharacterString[i] - 97]++;
//                 cout << "a : " << lowerCharacterString[i] << " : " << a[lowerCharacterString[i] - 97] << endl;
//             }
//             else
//             {
//                 b[lowerCharacterString[i] - 97]++;
//                 cout << "b : " << lowerCharacterString[i] << " : " << b[lowerCharacterString[i] - 97] << endl;
//             }
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if (a[lowerCharacterString[i] - 97] != b[lowerCharacterString[i] - 97])
//         {
//             cout << a[97 - lowerCharacterString[i]] << " : " << b[97 - lowerCharacterString[i]] << endl;
//             return false;
//         }
//     }
//     return true;
// }
//------------------------------------
// int main()
// {
//     string str = "book";
//     cout << halvesAreAlike(str);
// }

//--------------------------------------------------------------101. Symmetric Tree -------------------------------------------------------------

// template <typename T>
// class BTNode
// {
// public:
//     T data;
//     BTNode<T> *left;
//     BTNode<T> *right;
//     BTNode(T data)
//     {
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
//     ~BTNode()
//     {
//         delete left;
//         delete right;
//     }
// };
// BTNode<int> *takeInputLevelWise()
// {
//     queue<BTNode<int> *> q;
//     int rootData;
//     cout << "Enter Root Data : ";
//     cin >> rootData;
//     if (rootData == -1)
//         return NULL;
//     BTNode<int> *root = new BTNode<int>(rootData);
//     q.push(root);
//     while (!q.empty())
//     {
//         int leftChild, rightChild;
//         cout << "Enter left child of " << q.front()->data << " : ";
//         cin >> leftChild;
//         cout << "Enter right child of " << q.front()->data << " : ";
//         cin >> rightChild;
//         if (leftChild != -1)
//         {
//             q.front()->left = new BTNode<int>(leftChild);
//             q.push(q.front()->left);
//         }
//         if (rightChild != -1)
//         {
//             q.front()->right = new BTNode<int>(rightChild);
//             q.push(q.front()->right);
//         }
//         q.pop();
//     }
//     return root;
// }
// void printLevelOrder(BTNode<int> *root)
// {
//     queue<BTNode<int> *> q;
//     if (root != NULL)
//         q.push(root);
//     while (!q.empty())
//     {
//         cout << q.front()->data << " : ";
//         if (q.front()->left != NULL)
//         {
//             cout << "Left : " << q.front()->left->data << ", ";
//             q.push(q.front()->left);
//         }
//         if (q.front()->right != NULL)
//         {
//             cout << "Right : " << q.front()->right->data;
//             q.push(q.front()->right);
//         }
//         cout << endl;
//         q.pop();
//     }
// }
// bool helper(BTNode<int> *leftTree, BTNode<int> *rightTree){
//     if(leftTree == NULL && rightTree != NULL) return false;
//     if(leftTree != NULL && rightTree == NULL) return false;
//     if(leftTree == NULL && rightTree == NULL) return true;
//     if(leftTree->data != rightTree->data) return false;
//     return helper(leftTree->left, rightTree->right) &&
//             helper(leftTree->right, rightTree->left);
// }
// bool isSymmetric(BTNode<int>* root) {
//     if(root == NULL) return true;
//     return helper(root->left, root->right);
// }
// int isTreeSymmetric(BTNode<int> *leftSubTree, BTNode<int> *rightSubTree)
// {
//     if (leftSubTree->data != rightSubTree->data)
//         return 0;
//     if((leftSubTree->left == NULL && rightSubTree->right != NULL) || (leftSubTree->right == NULL && rightSubTree->left != NULL))
//         return 0;
//     int smallAnswer = 1;
//     if (leftSubTree->left != NULL)
//         if (rightSubTree->right != NULL)
//             smallAnswer = isTreeSymmetric(leftSubTree->left, rightSubTree->right);
//         else
//             return 0;
//     if(smallAnswer == 0)return 0;
//     if (leftSubTree->right != NULL)
//         if (rightSubTree->left != NULL)
//             smallAnswer = isTreeSymmetric(leftSubTree->right, rightSubTree->left);
//         else
//             return 0;
//     if(smallAnswer == 0)return 0;
//     return 1;
// }
// // 3 9 20 -1 -1  15 7 -1 -1 -1 -1
// // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
// // 1 2 3 4 5 6 -1 -1 -1 -1 -1 -1 -1
// // 4 7 12 8 -1 -1 7 5 9 -1 -1 -1 6 -1 -1 -1 -1
// // 1 2 2 3 4 4 3 -1 -1 -1 -1 -1 -1 -1 -1
// // 1 2 2 -1 3 -1 3 -1 -1 -1 -1
// // 7 -64 -64 -1 -90 -90 -6 88 -44 68 -65 -76 68 -44 88 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
// int main()
// {
//     BTNode<int> *root = takeInputLevelWise();
//     cout << "Level Order Travelersal" << endl;
//     printLevelOrder(root);
//     cout << "Symmetric Tree Or Not : " << isTreeSymmetric(root, root);
// }
//--------------------------------104. Maximum Depth of Binary Tree---------- Max Depth or Height of a Binary Tree ------------------------------------------
// template <typename T>
// class BTNode
// {
// public:
//     T data;
//     BTNode<T> *left;
//     BTNode<T> *right;
//     BTNode(T data)
//     {
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
//     ~BTNode()
//     {
//         delete left;
//         delete right;
//     }
// };
// BTNode<int> *takeInputLevelWise()
// {
//     queue<BTNode<int> *> q;
//     int rootData;
//     cout << "Enter Root Data : ";
//     cin >> rootData;
//     if (rootData == -1)
//         return NULL;
//     BTNode<int> *root = new BTNode<int>(rootData);
//     q.push(root);
//     while (!q.empty())
//     {
//         int leftChild, rightChild;
//         cout << "Enter left child of " << q.front()->data << " : ";
//         cin >> leftChild;
//         cout << "Enter right child of " << q.front()->data << " : ";
//         cin >> rightChild;
//         if (leftChild != -1)
//         {
//             q.front()->left = new BTNode<int>(leftChild);
//             q.push(q.front()->left);
//         }
//         if (rightChild != -1)
//         {
//             q.front()->right = new BTNode<int>(rightChild);
//             q.push(q.front()->right);
//         }
//         q.pop();
//     }
//     return root;
// }
// void printLevelOrder(BTNode<int> *root)
// {
//     queue<BTNode<int> *> q;
//     if (root != NULL)
//         q.push(root);
//     while (!q.empty())
//     {
//         cout << q.front()->data << " : ";
//         if (q.front()->left != NULL)
//         {
//             cout << "Left : " << q.front()->left->data << ", ";
//             q.push(q.front()->left);
//         }
//         if (q.front()->right != NULL)
//         {
//             cout << "Right : " << q.front()->right->data;
//             q.push(q.front()->right);
//         }
//         cout << endl;
//         q.pop();
//     }
// }
// int maxDepthOfTree(BTNode<int> *root)
// {
//     if(root == NULL)
//         return 0;
//     int leftSubTreeHeight = 0;
//     int rightSubTreeHeight = 0;
//     if(root->left != NULL)
//         leftSubTreeHeight = maxDepthOfTree(root->left);
//     if(root->right != NULL)
//         rightSubTreeHeight = maxDepthOfTree(root->right);
//     return 1+max(leftSubTreeHeight, rightSubTreeHeight);
// }
// // 3 9 20 -1 -1  15 7 -1 -1 -1 -1
// // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
// // 1 2 3 4 5 6 -1 -1 -1 -1 -1 -1 -1
// // 4 7 12 8 -1 -1 7 5 9 -1 -1 -1 6 -1 -1 -1 -1
// int main()
// {
//     BTNode<int> *root = takeInputLevelWise();
//     cout << "Level Order Travelersal" << endl;
//     printLevelOrder(root);
//     cout << "Max Depth Of A Tree : " << maxDepthOfTree(root) << endl;
// }
//-------------------------------------------------------------- 102. Binary Tree postOrder (postOrder Iteratively) Order Traversal---------------------------------------------------------

// template <typename T>
// class BTNode
// {
// public:
//     T data;
//     BTNode<T> *left;
//     BTNode<T> *right;
//     BTNode(T data)
//     {
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
//     ~BTNode()
//     {
//         delete left;
//         delete right;
//     }
// };
// BTNode<int> *takeInputLevelWise()
// {
//     queue<BTNode<int> *> q;
//     int rootData;
//     cout << "Enter Root Data : ";
//     cin >> rootData;
//     if (rootData == -1)
//         return NULL;
//     BTNode<int> *root = new BTNode<int>(rootData);
//     q.push(root);
//     while (!q.empty())
//     {
//         int leftChild, rightChild;
//         cout << "Enter left child of " << q.front()->data << " : ";
//         cin >> leftChild;
//         cout << "Enter right child of " << q.front()->data << " : ";
//         cin >> rightChild;
//         if (leftChild != -1)
//         {
//             q.front()->left = new BTNode<int>(leftChild);
//             q.push(q.front()->left);
//         }
//         if (rightChild != -1)
//         {
//             q.front()->right = new BTNode<int>(rightChild);
//             q.push(q.front()->right);
//         }
//         q.pop();
//     }
//     return root;
// }
// void postOrderTraversal(BTNode<int> *root)
// {
//     if (root != NULL)
//     {
//         postOrderTraversal(root->left);
//         postOrderTraversal(root->right);
//         cout << root->data << ", ";
//     }
// }
// void postOrderTraversalIterativeMethod(BTNode<int> *root)
// {
//     stack<BTNode<int> *> s;
//     unordered_map<BTNode<int> *, int> umap;
//     if (root != NULL)
//     {
//         s.push(root);
//     }
//     while (!s.empty())
//     {
//         if (s.top()->left != NULL && !umap[s.top()->left])
//         {
//             s.push(s.top()->left);
//         }
//         else if (s.top()->right != NULL && !umap[s.top()->right])
//         {
//             s.push(s.top()->right);
//         }
//         else
//         {
//             cout << s.top()->data << ", ";
//             umap[s.top()] = 1;
//             s.pop();
//         }
//     }
// }
// // 3 9 20 -1 -1  15 7 -1 -1 -1 -1
// // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
// // 1 2 3 4 5 6 -1 -1 -1 -1 -1 -1 -1
// int main()
// {
//     BTNode<int> *root = takeInputLevelWise();
//     cout << endl;
//     postOrderTraversal(root);
//     cout << endl;
//     postOrderTraversalIterativeMethod(root);
// }
//-------------------------------------------------------------- 102. Binary Tree PreOrder (PreOrder Iteratively) Order Traversal---------------------------------------------------------

// template <typename T>
// class BTNode
// {
// public:
//     T data;
//     BTNode<T> *left;
//     BTNode<T> *right;
//     BTNode(T data)
//     {
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
//     ~BTNode()
//     {
//         delete left;
//         delete right;
//     }
// };
// BTNode<int> *takeInputLevelWise()
// {
//     queue<BTNode<int> *> q;
//     int rootData;
//     cout << "Enter Root Data : ";
//     cin >> rootData;
//     if (rootData == -1)
//         return NULL;
//     BTNode<int> *root = new BTNode<int>(rootData);
//     q.push(root);
//     while (!q.empty())
//     {
//         int leftChild, rightChild;
//         cout << "Enter left child of " << q.front()->data << " : ";
//         cin >> leftChild;
//         cout << "Enter right child of " << q.front()->data << " : ";
//         cin >> rightChild;
//         if (leftChild != -1)
//         {
//             q.front()->left = new BTNode<int>(leftChild);
//             q.push(q.front()->left);
//         }
//         if (rightChild != -1)
//         {
//             q.front()->right = new BTNode<int>(rightChild);
//             q.push(q.front()->right);
//         }
//         q.pop();
//     }
//     return root;
// }
// void preOrderTraversal(BTNode<int> *root)
// {
//     if (root != NULL)
//     {
//         cout << root->data << ", ";
//         preOrderTraversal(root->left);
//         preOrderTraversal(root->right);
//     }
// }
// // void preOrderTraversalIterativeMethod(BTNode<int> *root)
// // {
// //     stack<BTNode<int> *> s;
// //     unordered_map<BTNode<int> *, int> umap;
// //     if (root != NULL)
// //         s.push(root);
// //     while (!s.empty())
// //     {
// //         if (!umap[s.top()])
// //         {
// //             cout << s.top()->data << ", ";
// //             umap[s.top()] = 1;
// //             if (s.top()->left)
// //                 s.push(s.top()->left);
// //         }
// //         else
// //         {
// //             BTNode<int> *topElement = s.top();
// //             s.pop();
// //             if(topElement->right)
// //                 s.push(topElement->right);
// //         }
// //     }
// // }
// void preOrderTraversalIterativeMethod(BTNode<int> *root)
// {
//     vector<int> result;
//     stack<BTNode<int> *> s;
//     BTNode<int> *currentNode = root;
//     while (currentNode != NULL || !s.empty())
//     {
//         while (currentNode != NULL)
//         {
//             cout << currentNode->data << ", ";
//             s.push(currentNode);
//             currentNode = currentNode->left;
//         }
//         currentNode = s.top();
//         s.pop();
//         currentNode = currentNode->right;
//     }
// }
// // 3 9 20 -1 -1  15 7 -1 -1 -1 -1
// // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
// // 1 2 3 4 5 6 -1 -1 -1 -1 -1 -1 -1
// int main()
// {
//     BTNode<int> *root = takeInputLevelWise();
//     cout << endl;
//     preOrderTraversal(root);
//     cout << endl;
//     preOrderTraversalIterativeMethod(root);
// }
//-------------------------------------------------------------- 102. Binary Tree InOrder (InOrder Iteratively) Order Traversal---------------------------------------------------------
// template <typename T>
// class BTNode
// {
// public:
//     T data;
//     BTNode<T> *left;
//     BTNode<T> *right;
//     BTNode(T data)
//     {
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
//     ~BTNode()
//     {
//         delete left;
//         delete right;
//     }
// };
// BTNode<int> *takeInputLevelWise()
// {
//     queue<BTNode<int> *> q;
//     int rootData;
//     cout << "Enter Root Data : ";
//     cin >> rootData;
//     if (rootData == -1)
//         return NULL;
//     BTNode<int> *root = new BTNode<int>(rootData);
//     q.push(root);
//     while (!q.empty())
//     {
//         int leftChild, rightChild;
//         cout << "Enter left child of " << q.front()->data << " : ";
//         cin >> leftChild;
//         cout << "Enter right child of " << q.front()->data << " : ";
//         cin >> rightChild;
//         if (leftChild != -1)
//         {
//             q.front()->left = new BTNode<int>(leftChild);
//             q.push(q.front()->left);
//         }
//         if (rightChild != -1)
//         {
//             q.front()->right = new BTNode<int>(rightChild);
//             q.push(q.front()->right);
//         }
//         q.pop();
//     }
//     return root;
// }
// void InOrderTraversal(BTNode<int> *root)
// {
//     if (root == NULL)
//         return;
//     InOrderTraversal(root->left);
//     cout << root->data << ", ";
//     InOrderTraversal(root->right);
// }
// void InOrderTraversalIterativeMethod(BTNode<int> *root)
// {
//     stack<BTNode<int> *> s;
//     unordered_map<BTNode<int> *, int> umap;
//     if (root != NULL)
//     {
//         s.push(root);
//     }
//     while (!s.empty())
//     {
//         if (s.top()->left && !umap[s.top()->left])
//         {
//             s.push(s.top()->left);
//         }
//         else
//         {
//             BTNode<int> *visit = s.top();
//             s.pop();
//             cout << visit->data << ", ";
//             umap[visit] = 1;
//             if (visit->right && !umap[visit->right])
//             {
//                 s.push(visit->right);
//             }
//         }
//     }
// }
// // 3 9 20 -1 -1  15 7 -1 -1 -1 -1
// // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
// // 1 2 3 4 5 6 -1 -1 -1 -1 -1 -1 -1
// int main()
// {
//     BTNode<int> *root = takeInputLevelWise();
//     cout << endl;
//     InOrderTraversal(root);
//     cout << endl;
//     InOrderTraversalIterativeMethod(root);
// }

// //-------------------------------------------------------------- 102. Binary Tree Level Order Traversal---------------------------------------------------------
// template <typename T>
// class BTNode
// {
// public:
//     T data;
//     BTNode<T> *left;
//     BTNode<T> *right;
//     BTNode(T data)
//     {
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
//     ~BTNode()
//     {
//         delete left;
//         delete right;
//     }
// };
// BTNode<int> *takeInputLevelWise()
// {
//     queue<BTNode<int> *> q;
//     int rootData;
//     cout << "Enter Root Data : ";
//     cin >> rootData;
//     if (rootData == -1)
//         return NULL;
//     BTNode<int> *root = new BTNode<int>(rootData);
//     q.push(root);
//     while (!q.empty())
//     {
//         int leftChild, rightChild;
//         cout << "Enter left child of " << q.front()->data << " : ";
//         cin >> leftChild;
//         cout << "Enter right child of " << q.front()->data << " : ";
//         cin >> rightChild;
//         if (leftChild != -1)
//         {
//             q.front()->left = new BTNode<int>(leftChild);
//             q.push(q.front()->left);
//         }
//         if (rightChild != -1)
//         {
//             q.front()->right = new BTNode<int>(rightChild);
//             q.push(q.front()->right);
//         }
//         q.pop();
//     }
//     return root;
// }
// void printLevelOrder(BTNode<int> *root)
// {
//     queue<BTNode<int> *> q;
//     if (root != NULL)
//         q.push(root);
//     while (!q.empty())
//     {
//         cout << q.front()->data << " : ";
//         if (q.front()->left != NULL)
//         {
//             cout << "Left : " << q.front()->left->data << ", ";
//             q.push(q.front()->left);
//         }
//         if (q.front()->right != NULL)
//         {
//             cout << "Right : " << q.front()->right->data;
//             q.push(q.front()->right);
//         }
//         cout << endl;
//         q.pop();
//     }
// }
// void levelOrder(BTNode<int> *root)
// {
//     queue<BTNode<int> *> q;
//     vector<vector<int>> result;
//     vector<int> subResult;
//     if (root != NULL)
//         q.push(root);
//     q.push(NULL);
//     while (!q.empty())
//     {
//         if (q.front() == NULL)
//         {
//             // cout << endl;
//             result.push_back(subResult);
//             subResult.clear();
//             q.pop();
//             if (!q.empty())
//                 q.push(NULL);
//         }
//         else
//         {
//             // cout << q.front()->data << ", ";
//             subResult.push_back(q.front()->data);
//             if (q.front()->left != NULL)
//             {
//                 q.push(q.front()->left);
//             }
//             if (q.front()->right != NULL)
//             {
//                 q.push(q.front()->right);
//             }
//             q.pop();
//         }
//     }
//     for (int i = 0; i < result.size(); i++)
//     {
//         for (int j = 0; j < result[i].size(); j++)
//         {
//             cout << result.at(i).at(j) << ", ";
//         }
//         cout << endl;
//     }
// }
// // 3 9 20 -1 -1  15 7 -1 -1 -1 -1
// int main()
// {
//     BTNode<int> *root = takeInputLevelWise();
//     cout << endl;
//     levelOrder(root);
// }

//--------------------------------------------------------------------------------------------------------------------------------------------------------------

// int *shiftArray(int n)
// {
//     int *arr = new int[n];
//     cout << "Enter " << n << " elements in array.";
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     int p;
//     cout << "Enter sift position : ";
//     cin >> p;
//     int result_array[n];
//     int j = 0;
//     int d;
//     cout << "Enter sift direction : ";
//     cin >> d;
//     if (d == 0)
//     {
//         for (int i = p; i < p + n; i++)
//         {
//             result_array[j++] = arr[i % n];
//         }
//     }
//     if (d == 1)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             result_array[(j + p) % n] = arr[i];
//             j++;
//         }
//     }
//     return result_array;
// }

// int main()
// {
//     int n;
//     cout << "Enter number of elements : ";
//     cin >> n;
//     int *arr = shiftArray(n);
// }

//------------------------------------------------------- 316. Remove Duplicate Letters ---------------------------------------------------------

// string removeDuplicateLetters1(string s)
// {
//     vector<int> lastIndex(26, 0);
//     for (int i = 0; i < s.length(); i++)
//     {
//         lastIndex[s[i] - 'a'] = i; // track the lastIndex of character presence
//     }
//     vector<bool> seen(26, false); // keep track seen
//     // string stack;
//     string result_stack;
//     for (int i = 0; i < s.size(); i++)
//     {
//         int curr = s[i] - 'a';
//         if (seen[curr])
//             continue; // if seen continue as we need to pick one char only
//         while (result_stack.size() > 0 && result_stack.back() > s[i] && i < lastIndex[result_stack.back() - 'a'])
//         {
//             seen[result_stack.back() - 'a'] = false; // pop out and mark unseen
//             result_stack.pop_back();
//         }
//         result_stack.push_back(s[i]); // add into stack
//         seen[curr] = true;            // mark seen
//     }
//     return result_stack;
// }
// //---------------------------------------------------
// string removeDuplicateLetters(string s)
// {
//     unordered_map<char, int> character_frequency;
//     unordered_map<char, int> occure;
//     for (auto item : s)
//     {
//         character_frequency[item]++;
//         occure[item] = 0;
//     }
//     string result_stack;
//     int i = 0;
//     int n = s.size();
//     while (i < n)
//     {
//         if (result_stack.empty())
//         {
//             result_stack.push_back(s[i]);
//             character_frequency[s[i]]--;
//             occure[s[i]] = 1;
//         }
//         else if (occure[s[i]])
//         {
//             character_frequency[s[i]]--;
//         }
//         else
//         {
//             while (s[i] <= result_stack.back())
//             {
//                 if (character_frequency[result_stack.back()])
//                 {
//                     occure[result_stack.back()] = 0;
//                     result_stack.pop_back();
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }
//             if (!occure[s[i]])
//             {
//                 result_stack.push_back(s[i]);
//                 character_frequency[s[i]]--;
//                 occure[s[i]] = 1;
//             }
//         }
//         i++;
//     }
//     return result_stack;
// }
// int main()
// {
//     // string s = "abacb";
//     string s = "bbcaac";
//     cout << removeDuplicateLetters(s);
// }

//------------------------------------------------------- 1047. Remove All Adjacent Duplicates In String ---------------------------------------------------------

//---------------------------------------
// string removeDuplicates(string s) {
//     string output;
//     int n = s.size();
//     for (int i = 0; i < n; i++)
//     {
//         if (!output.empty())
//         {
//             if (output.back() == s[i])
//             {
//                 output.pop_back();
//             }
//             else
//             {
//                 output.push_back(s[i]);
//             }
//         }
//         else
//         {
//             output.push_back(s[i]);
//         }
//     }
//     return output;
// }
//----------------------------------
// string removeDuplicates(string s)
// {
//     stack<char> ch_stack;
//     int n = s.length();
//     for (int i = 0; i < n; i++)
//     {
//         if (!ch_stack.empty())
//         {
//             if (ch_stack.top() == s[i])
//             {
//                 ch_stack.pop();
//             }
//             else
//             {
//                 ch_stack.push(s[i]);
//             }
//         }
//         else
//         {
//             ch_stack.push(s[i]);
//         }
//     }
//     s = "";
//     while (!ch_stack.empty())
//     {
//         s = ch_stack.top() + s;
//         ch_stack.pop();
//     }
//     return s;
// }
// int main()
// {
//     string s = "azxxzy";
//     cout << removeDuplicates(s);
// }
//------------------------------------------------------- 150. Evaluate Reverse Polish Notation ---------------------------------------------------------
// int evalRPN(vector<string> &tokens)
// {
//     stack<string> s;
//     int n = tokens.size();
//     string leftOperand, rightOperand;
//     for (int i = 0; i < n; i++)
//     {
//         if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
//         {
//             rightOperand = s.top();
//             s.pop();
//             leftOperand = s.top();
//             s.pop();
//             if (tokens[i] == "+")
//             {
//                 s.push(to_string(stoll(leftOperand) + stoll(rightOperand)));
//             }
//             if (tokens[i] == "-")
//             {
//                 s.push(to_string(stoll(leftOperand) - stoll(rightOperand)));
//             }
//             if (tokens[i] == "*")
//             {
//                 s.push(to_string(stoll(leftOperand) * stoll(rightOperand)));
//             }
//             if (tokens[i] == "/")
//             {
//                 s.push(to_string(stoll(leftOperand) / stoll(rightOperand)));
//             }
//         }
//         else
//         {
//             s.push(tokens[i].c_str());
//         }
//     }
//     return stoi(s.top());
// }
// int main()
// {
//     vector<string> tokens{"-128","-128","*","-128","*","-128","*","8","*","-1","*"};
//     cout << evalRPN(tokens);
// }
//------------------------------------------------------- 187. Repeated DNA Sequences ---------------------------------------------------------
// vector<string> findRepeatedDnaSequences(string s)
// {
//     int n = s.size();
//     unordered_map<string, int> mp;
//     vector<string> output;
//     string targetString;
//     int found;
//     for (int i = 0; i <= n - 10; i++)
//     {
//         targetString = s.substr(i, 10);
//         mp[targetString]++;
//         if (mp[targetString] == 2)
//         {
//             output.push_back(targetString);
//         }
//     }
//     return output;
// }
//---------------------------------------------------
// vector<string> findRepeatedDnaSequences(string s)
// {
//     int n = s.size();
//     set<string> result;
//     string targetString;
//     int found;
//     for (int i = 0; i < n - 10; i++)
//     {
//         targetString = s.substr(i, 10);
//         found = s.find(targetString, i + 1);
//         if (found != -1)
//         {
//             result.insert(targetString);
//         }
//     }
//     vector<string> output(result.begin(), result.end());
//     return output;
// }
// int main()
// {
//     // string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
//     // string s = "AAAAAAAAAAAAA";
//     string s = "AAAAAAAAAAA";
//     vector<string> output;
//     output = findRepeatedDnaSequences(s);
//     for (auto item : output)
//         cout << item << "  ";
// }
//------------------------------------------------------- 209. Minimum Size Subarray Sum ---------------------------------------------------------
// int minSubArrayLen(int target, vector<int> &nums)
// {
//     int left = 0, right = 0, totalSum = nums[0], n = nums.size();
//     int previousLength = INT_MAX, currentlength = 1;
//     while (right < n)
//     {
//         if (totalSum < target)
//         {
//             right++;
//             if (right > n - 1)
//             {
//                 if (previousLength != INT_MAX)
//                     return previousLength;
//                 break;
//             }
//             totalSum += nums[right];
//             currentlength++;
//         }
//         if (previousLength > currentlength && totalSum >= target)
//         {
//             previousLength = currentlength;
//         }
//         if (totalSum >= target)
//         {
//             totalSum -= nums[left++];
//             currentlength--;
//         }
//     }
//     return 0;
// }
//-------------------------------------------------------------
// int minSubArrayLen(int target, vector<int> &nums)
// {
//     int left = 0, right = 0, totalSum = 0, n = nums.size();
//     int previousLength = 0, currentLength = 0;
//     while (right < n)
//     {
//         totalSum += nums[right];
//         if (totalSum >= target)
//             break;
//         right++;
//     }
//     if (totalSum < target)
//         return 0;
//     previousLength = right + 1;
//     currentLength = previousLength;
//     while (right < n)
//     {
//         if (totalSum >= target)
//         {
//             totalSum -= nums[left++];
//             currentLength--;
//         }
//         if (totalSum < target)
//         {
//             right++;
//             if (right > n-1)
//             {
//                 break;
//             }
//             totalSum += nums[right];
//             currentLength++;
//         }
//         if (previousLength > currentLength)
//         {
//             previousLength = currentLength;
//         }
//     }
//     return previousLength;
// }
// int main()
// {
//     vector<int> nums = {2,3,1,2,4,3};
//     int target = 7;
//     cout << minSubArrayLen(target, nums);
// }
//------------------------------------------------------- 219. Contains Duplicate II ---------------------------------------------------------
// bool containsNearbyDuplicate(vector<int> &nums, int k)
// {

// }
// //-------------------------------------------------------
// // bool containsNearbyDuplicate(vector<int> &nums, int k)
// // {
// //     unordered_map<int, int> mp;
// //     int n = nums.size();
// //     for (int i = 0; i < n; i++)
// //     {
// //         if (mp.count(nums[i]))
// //         {
// //             if (abs(i - mp[nums[i]]) <= k)
// //             {
// //                 return true;
// //             }
// //         }
// //         mp[nums[i]] = i;
// //     }
// //     return false;
// // }
// int main()
// {
//     vector<int> nums = {1, 2, 3, 1, 3, 3};
//     int k = 2;
//     cout << containsNearbyDuplicate(nums, k);
// }
//------------------------------------------------------- 53. Maximum Subarray ---------------------------------------------------------
// int main()
// {
//     vector<int> nums = {1, 2};
//     int n = nums.size();
//     int previous_sum = nums[0], current_sum = nums[0];
//     for (int i = 1; i < n; i++)
//     {
//         current_sum += nums[i];
//         if (current_sum < nums[i])
//         {
//             current_sum = nums[i];
//         }
//         if (previous_sum < current_sum)
//         {
//             previous_sum = current_sum;
//         }
//     }
//     cout << previous_sum << endl;
// }
//------------------------------------------------------- 20. Valid Parentheses ---------------------------------------------------------
// bool isValid(string s)
// {
//     stack<char> st;
//     for (int i = 0; i < s.size(); i++)
//     {
//         if (s[i] == '(' || s[i] == '{' || s[i] == '[')
//         {
//             st.push(s[i]);
//         }

//         else
//         {
//             if (st.size() == 0)
//                 return false;

//             char ch = st.top();
//             st.pop();
//             if (s[i] == ')' && ch != '(')
//             {
//                 return false;
//             }
//             if (s[i] == '}' && ch != '{')
//             {
//                 return false;
//             }
//             if (s[i] == ']' && ch != '[')
//             {
//                 return false;
//             }
//         }
//     }
//     return st.empty();
// }
// int main()
// {
//     char str[] = "{[()]}";
//     cout << isValid(str) << endl;
// }
//-------------------------------------------------------21. Merge Two Sorted Lists---------------------------------------------------------
// class ListNode
// {
// public:
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int val) : val(val), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
// void printLinkedList(ListNode *head)
// {
//     ListNode *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->val << " -> ";
//         temp = temp->next;
//     }
//     cout << "NULL" << endl;
// }
// // ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
// // {
// //     ListNode *currentNode = NULL;
// //     ListNode *newHeadNode = NULL;
// //     if (!list1 && !list2)
// //         return NULL;
// //     if (list1 == NULL)
// //         return list2;
// //     if (list2 == NULL)
// //         return list1;
// //     if (list1->val <= list2->val)
// //     {
// //         currentNode = list1;
// //         newHeadNode = currentNode;
// //         list1 = list1->next;
// //     }
// //     else
// //     {
// //         currentNode = list2;
// //         newHeadNode = currentNode;
// //         list2 = list2->next;
// //     }
// //     while (list1 != NULL && list2 != NULL)
// //     {
// //         if (list1->val < list2->val)
// //         {
// //             currentNode->next = list1;
// //             currentNode = currentNode->next;
// //             list1 = list1->next;
// //         }
// //         else if (list2->val < list1->val)
// //         {
// //             currentNode->next = list2;
// //             currentNode = currentNode->next;
// //             list2 = list2->next;
// //         }
// //         else
// //         {
// //             currentNode->next = list1;
// //             currentNode = currentNode->next;
// //             list1 = list1->next;
// //             currentNode->next = list2;
// //             currentNode = currentNode->next;
// //             list2 = list2->next;
// //         }
// //     }
// //     if(!list1 && !list2)
// //         return newHeadNode;
// //     if(!list1)
// //         currentNode->next = list2;
// //     if(!list2)
// //         currentNode->next = list1;
// //     return newHeadNode;
// // }
// //------------------------------------
// ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
// {
//     if (list1 == NULL)
//         return list2;
//     if (list2 == NULL)
//         return list1;
//     ListNode *newHead = NULL;
//     if (list1->val < list2->val)
//     {
//         newHead = list1;
//         newHead->next = mergeTwoLists(list1->next, list2);
//     }
//     else
//     {
//         newHead = list2;
//         newHead->next = mergeTwoLists(list1, list2->next);
//     }
//     return newHead;
// }
// int main()
// {
//     ListNode *head1 = NULL;
//     ListNode *n1 = new ListNode(1);
//     head1 = n1;
//     ListNode *n2 = new ListNode(2);
//     n1->next = n2;
//     ListNode *n3 = new ListNode(4);
//     n2->next = n3;

//     ListNode *head2 = NULL;
//     ListNode *n01 = new ListNode(1);
//     head2 = n01;
//     ListNode *n02 = new ListNode(3);
//     n01->next = n02;
//     ListNode *n03 = new ListNode(4);
//     n02->next = n03;

//     printLinkedList(head1);
//     printLinkedList(head2);
//     ListNode *newHeadNode = NULL;
//     newHeadNode = mergeTwoLists(head1, head2);
//     printLinkedList(newHeadNode);
// }
//-------------------------------------------------------19. Remove Nth Node From End of List------------------------------------------------
// class ListNode
// {
// public:
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int val) : val(val), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
// void printLinkedList(ListNode *head)
// {
//     ListNode *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->val << " -> ";
//         temp = temp->next;
//     }
//     cout << "NULL";
// }
// // ListNode *removeNthFromEnd(ListNode *head, int n)
// // {
// //     ListNode *current_node = head;
// //     ListNode *Nth_node = head;
// //     ListNode *Nth_last_node = NULL;
// //     int counter = 1;
// //     while (current_node->next != NULL)
// //     {
// //         current_node = current_node->next;
// //         counter++;
// //         if (counter > n)
// //         {
// //             Nth_last_node = Nth_node;
// //             Nth_node = Nth_node->next;
// //         }
// //     }
// //     if (Nth_node == head)
// //     {
// //         head = head->next;
// //         delete Nth_node;
// //         return head;
// //     }
// //     Nth_last_node->next = Nth_node->next;
// //     delete Nth_node;
// //     return head;
// // }
// //--------------------------------------------------
// // ListNode *removeNthFromEnd(ListNode *head, int n)
// // {
// //     ListNode *temp = head;
// //     int length = 0;
// //     while (temp != NULL)
// //     {
// //         temp = temp->next;
// //         length++;
// //     }
// //     int target = length - n;
// //     ListNode *target_node = head;
// //     ListNode *target_previous = NULL;
// //     int counter = 0;
// //     while (counter != target)
// //     {
// //         target_previous = target_node;
// //         target_node = target_node->next;
// //         counter++;
// //     }
// //     if (target_node == head)
// //     {
// //         head = head->next;
// //         delete target_node;
// //         return head;
// //     }
// //     target_previous->next = target_node->next;
// //     delete target_node;
// //     return head;
// // }
// //-----------------------------------------------
// ListNode *removeNthFromEnd(ListNode *head, int n)
// {
//     ListNode *targetNode = head;
//     ListNode *currentNode = head;
//     ListNode *targetPrevious = NULL;
//     int index_counter = 1;
//     while (currentNode)
//     {
//         currentNode = currentNode->next;
//         index_counter++;
//         if (index_counter > (n + 1))
//         {
//             targetPrevious = targetNode;
//             targetNode = targetNode->next;
//         }
//     }
//     if (targetNode == head)
//     {
//         head = head->next;
//         delete targetNode;
//         return head;
//     }
//     targetPrevious->next = targetNode->next;
//     delete targetNode;
//     return head;
// }
// int main()
// {
//     ListNode *head = NULL;
//     ListNode *n1 = new ListNode(1);
//     head = n1;
//     ListNode *n2 = new ListNode(2);
//     n1->next = n2;
//     ListNode *n3 = new ListNode(3);
//     n2->next = n3;
//     ListNode *n4 = new ListNode(4);
//     n3->next = n4;
//     ListNode *n5 = new ListNode(5);
//     n4->next = n5;

//     head = removeNthFromEnd(head, 1);
//     printLinkedList(head);
// }
//----------------------------------------------------206. Reverse Linked List------------------------------------------------------
// class ListNode
// {
// public:
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int val) : val(val), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
// void printLinkedList(ListNode *head)
// {
//     ListNode *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->val << " -> ";
//         temp = temp->next;
//     }
//     cout << "NULL";
// }
// ListNode *reverseList(ListNode *head)
// {
//     ListNode *newHeadNode = NULL;
//     ListNode *currentNode = NULL, *currentNextNode = NULL;
//     if (head)
//     {
//         currentNode = head;
//         currentNextNode = currentNode->next;
//     }
//     while (currentNode)
//     {
//         currentNode->next = newHeadNode;
//         newHeadNode = currentNode;
//         currentNode = currentNextNode;
//         if(currentNode)
//             currentNextNode = currentNode->next;
//     }
//     return newHeadNode;
// }
// int main()
// {
//     ListNode *head = NULL;
//     ListNode *n1 = new ListNode(1);
//     head = n1;
//     ListNode *n2 = new ListNode(2);
//     n1->next = n2;
//     ListNode *n3 = new ListNode(3);
//     n2->next = n3;
//     ListNode *n4 = new ListNode(4);
//     n3->next = n4;
//     ListNode *n5 = new ListNode(5);
//     n4->next = n5;

//     head = reverseList(head);
//     printLinkedList(head);
// }
//--------------------------------------------------876. Middle of the Linked List---------------------------------------------------
// class ListNode
// {
// public:
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int val) : val(val), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
// // ListNode *middleNode(ListNode *head)
// // {
// //     if (head == NULL)
// //         return head;
// //     ListNode *middleNode = head;
// //     ListNode *temp = head;
// //     int index_counter = 1;
// //     while (temp->next != NULL)
// //     {
// //         temp = temp->next;
// //         index_counter++;
// //         if (index_counter % 2 != 0)
// //             middleNode = middleNode->next;
// //     }
// //     if(index_counter %2 == 0)
// //         middleNode = middleNode->next;
// //     return middleNode;
// // }
// //------------------------------------------
// ListNode* middleNode(ListNode *head)
// {
//     if (head == NULL)
//         return head;
//     ListNode *slowNode = head;
//     ListNode *fastNode = head->next;
//     while (fastNode != NULL && fastNode->next != NULL)
//     {
//         slowNode = slowNode->next;
//         fastNode = fastNode->next->next;
//     }
//     if(fastNode != NULL) // You have even length linked list
//         slowNode = slowNode->next;
//     return slowNode;
// }
// int main()
// {
//     ListNode *head = NULL;
//     ListNode *n1 = new ListNode(1);
//     head = n1;
//     ListNode *n2 = new ListNode(2);
//     n1->next = n2;
//     ListNode *n3 = new ListNode(3);
//     n2->next = n3;
//     ListNode *n4 = new ListNode(4);
//     n3->next = n4;
//     ListNode *n5 = new ListNode(5);
//     n4->next = n5;

//     ListNode *middle_node = middleNode(head);
//     cout << middle_node->val << endl;
// }
//------------------------------------------------------------------------------------------------------------------------------------
// class ListNode
// {
// public:
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int val) : val(val), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
// void printList(ListNode *head)
// {
//     ListNode *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->val << " -> ";
//         temp = temp->next;
//     }
//     cout << "NULL" << endl;
// }
// int listLength(ListNode *head)
// {
//     int length = 0;
//     ListNode *temp = head;
//     while (temp != NULL)
//     {
//         length++;
//         temp = temp->next;
//     }
//     return length;
// }
// ListNode *removeNthFromEnd(ListNode *head, int n)
// {
//     ListNode *current_node = head;
//     ListNode *Nth_node = head;
//     ListNode *Nth_last_node = NULL;
//     int counter = 1;
//     while (current_node->next != NULL)
//     {
//         current_node = current_node->next;
//         counter++;
//         if (counter > n)
//         {
//             Nth_last_node = Nth_node;
//             Nth_node = Nth_node->next;
//         }
//     }
//     if (Nth_node == head)
//     {
//         head = head->next;
//         delete Nth_node;
//         return head;
//     }
//     if (Nth_last_node == NULL)
//         return NULL;
//     Nth_last_node->next = Nth_node->next;
//     delete Nth_node;
//     return head;
// }
// //-------------------------------------------------------
// // ListNode *removeNthFromEnd(ListNode *head, int n)
// // {
// //     int length = listLength(head);
// //     if (length == 1)
// //         return NULL;
// //     if ((length - n) == 0)
// //     {
// //         ListNode *deletion_node = head;
// //         head = head->next;
// //         delete deletion_node;
// //         return head;
// //     }
// //     int Nth_last_node = 1;
// //     ListNode *temp = head;
// //     while (Nth_last_node < (length - n))
// //     {
// //         temp = temp->next;
// //         Nth_last_node++;
// //     }
// //     ListNode *temp2;
// //     temp2 = temp->next;
// //     temp->next = temp->next->next;
// //     delete temp2;
// //     return head;
// // }
// //--------------------------------------------------
// void printIthNode(ListNode *head, int index)
// {
//     // ListNode *temp = head;
//     // if (index < 0)
//     // {
//     //     cout << -1 << endl;
//     // }
//     // int length = listLength(head);
//     // if (index > length - 1)
//     // {
//     //     cout << "Invalid Index" << endl;
//     // }
//     //-------------------------
//     // while (index > 0)
//     // {
//     //     temp = temp->next;
//     //     index--;
//     // }
//     // cout << temp->val << endl;
//     //--------------------------
//     // int counter = 0;
//     // while (counter < index)
//     // {
//     //     temp = temp->next;
//     //     counter++;
//     // }
//     // cout << temp->val << endl;
//     //---------------------------------
//     if (index < 0)
//     {
//         cout << "-1" << endl;
//         return;
//     }
//     int count = 0;
//     while (count < index && head != NULL)
//     {
//         head = head->next;
//         count++;
//     }
//     if (head != NULL)
//         cout << head->val << endl;
//     else
//         cout << "-1" << endl;
// }
// ListNode *insert_at_Ith_index(ListNode *head, int data, int index)
// {
//     if (index < 0)
//     {
//         cout << "Index can't be negative!" << endl;
//         return head;
//     }
//     // int length = listLength(head);
//     // if (index > length)
//     // {
//     //     cout << "Index is not valid!" << endl;
//     //     return head;
//     // }
//     ListNode *newNode = new ListNode(data);
//     if (index == 0)
//     {
//         newNode->next = head;
//         return newNode;
//     }
//     int index_counter = 0;
//     ListNode *temp = head;
//     while (index_counter < index - 1 && temp != NULL)
//     {
//         temp = temp->next;
//         index_counter++;
//     }
//     if (temp == NULL)
//     {
//         cout << "Index is not valid!" << endl;
//         return head;
//     }
//     // newNode->next = temp->next;
//     // temp->next = newNode;
//     //---------- 2nd Approach--------------
//     ListNode *copyNode = temp->next;
//     temp->next = newNode;
//     newNode->next = copyNode;
//     return head;
// }
// ListNode *deleteIthNode(ListNode *head, int index)
// {
//     if (head == NULL)
//     {
//         return head;
//     }
//     if (index < 0)
//     {
//         cout << "Invalid Index!" << endl;
//         return head;
//     }
//     ListNode *temp = head;
//     int index_counter = 0;
//     if (index == 0)
//     {
//         head = head->next;
//         temp->next = NULL;
//         delete temp;
//         return head;
//     }
//     // while (index_counter < (index - 1) && temp->next != NULL)
//     while (index_counter != (index - 1) && temp->next != NULL)
//     {
//         temp = temp->next;
//         index_counter++;
//     }
//     if (temp->next == NULL)
//     {
//         cout << "Invalid Index!" << endl;
//         return head;
//     }
//     ListNode *target = temp->next;
//     temp->next = temp->next->next;
//     target->next = NULL;
//     delete target;
//     return head;
// }
// int lengthRecursively(ListNode *node)
// {
//     // Base Case
//     if (node == NULL)
//         return 0;
//     // Recursive Case
//     int small_answer = lengthRecursively(node->next);
//     // Calculation
//     return 1 + small_answer;
// }
// bool isElementPresent(ListNode *node, int element)
// {
//     if (node == NULL)
//         return false;
//     if (node->val == element)
//         return true;
//     return isElementPresent(node->next, element);
// }
// int main()
// {
//     ListNode *head = NULL;
//     ListNode *n1 = new ListNode(1);
//     head = n1;
//     ListNode *n2 = new ListNode(2);
//     n1->next = n2;
//     ListNode *n3 = new ListNode(3);
//     n2->next = n3;
//     ListNode *n4 = new ListNode(4);
//     n3->next = n4;
//     ListNode *n5 = new ListNode(5);
//     n4->next = n5;

//     // head = removeNthFromEnd(head, 2);
//     // printList(head);
//     // printIthNode(head, 5);
//     // insert_at_Ith_index(head, 10, 3);
//     // head = deleteIthNode(head, 2);
//     // printList(head);

//     // cout << "Length of the linked-list is : " << lengthRecursively(head) << endl;
//     cout << "Element present : " << isElementPresent(head, 0) << endl;
// }

//------------------------------------------------------------- Quick Sort -------------------------------------------------------------------
// int partitionFunction(int arr[], int s, int e)
// {
// int pivot = arr[e];
// int i = s;
// int j = e - 1;
// while (i < j)
// {
//     if (arr[i] < pivot)
//         i++;
//     else if (arr[j] >= pivot)
//         j--;
//     else if (arr[j] < pivot && arr[i] >= pivot)
//     {
//         int temp = arr[j];
//         arr[j] = arr[i];
//         arr[i] = temp;
//         i++;
//         j--;
//     }
//     else if (arr[i] >= pivot && arr[j] < pivot)
//     {
//         int temp = arr[j];
//         arr[j] = arr[i];
//         arr[i] = temp;
//         j--;
//         i++;
//     }
//     if (i >= j)
//         break;
// }
// if (arr[i] < pivot)
//     swap(arr[++i], arr[e]);
// else
//     swap(arr[i], arr[e]);
// return i;
// }
// void quickSort(int a[], int s, int e)
// {
//     if (s >= e)
//         return;
//     int p = partitionFunction(a, s, e);
//     quickSort(a, s, p - 1);
//     quickSort(a, p + 1, e);
// }
// int main()
// {
//     int arr[] = {6, 6, 3, 2, 1, 1, 5, 6, 4, 3, 5, 8, 5, 2, 2,  1, 7, 7, 3, 4, 4, 8, 8};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     quickSort(arr, 0, n - 1);
//     for (auto item : arr)
//         cout << item << "  ";
// }
//--------------------------------------------------
// int partitionFunction(int arr[], int s, int e)
// {
//     int pivot = arr[e];
//     int small_element_counter = 0;
//     for (int i = s; i < e; i++)
//         if (arr[i] < pivot)
//             small_element_counter++;
//     int temp = arr[e];
//     arr[e] = arr[s + small_element_counter];
//     arr[s + small_element_counter] = temp;
//     int i = s;
//     int j = e;
//     while (i <= (s+small_element_counter) && j >= (s+small_element_counter))
//     {
//         if (arr[i] < pivot)
//             i++;
//         else if (arr[j] >= pivot)
//             j--;
//         else if (arr[j] < pivot && arr[i] >= pivot)
//         {
//             int temp = arr[i];
//             arr[i] = arr[j];
//             arr[j] = temp;
//             i++;
//             j--;
//         }
//         else if (arr[i] >= pivot && arr[j] < pivot)
//         {
//             int temp = arr[i];
//             arr[i] = arr[j];
//             arr[j] = temp;
//             i++;
//             j--;
//         }
//     }
//     for(int i = s; i <= e; i++)
//         cout << arr[i] << "  ";
//     cout << endl;
//     return s+small_element_counter;
// }
// void quickSort(int a[], int s, int e)
// {
//     if (s >= e)
//         return;
//     int p = partitionFunction(a, s, e);
//     quickSort(a, s, p - 1);
//     quickSort(a, p + 1, e);
// }
// int main()
// {
//     int arr[] = {6, 6, 3, 2, 1, 1, 5, 6, 4, 3, 5, 8, 5, 2, 2, 1, 7, 7, 3, 4, 4, 8, 8};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     quickSort(arr, 0, n - 1);
//     for (auto item : arr)
//         cout << item << "  ";
// }
//------------------------------------------------
// int partitionFunction(int arr[], int s, int e)
// {
//     int i = s;
//     int pivot = arr[e];
//     for (int j = s; j <= e - 1; j++)
//     {
//         if (arr[j] < pivot)
//         {
//             swap(arr[i], arr[j]);
//             i++;
//         }
//     }
//     swap(arr[i], arr[e]);
//     return i;
// }

// void quickSort(int a[], int s, int e)
// {
//     if (s >= e)
//         return;
//     int p = partitionFunction(a, s, e);
//     quickSort(a, s, p - 1);
//     quickSort(a, p + 1, e);
// }
// int main()
// {
//     int arr[] = {6, 6, 3, 2, 1, 1, 5, 6, 4, 3, 5, 8, 5, 2, 2, 1, 7, 7, 3, 4, 4, 8, 8};
//     // int arr[] = {7, 3, 5, 1, 2, 6, 7};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     quickSort(arr, 0, n - 1);
//     for (auto item : arr)
//         cout << item << "  ";
// }
//------------------------------------------------------------- Merge Sort -------------------------------------------------------------------
// void mergeArrays(int x[], int y[], int a[], int s, int e)
// {
//     int mid = (s + e) / 2;
//     int i = s;
//     int j = mid + 1;
//     int index = s;
//     while (i <= mid && j <= e)
//     {
//         if (x[i] < y[j])
//         {
//             a[index++] = x[i++];
//         }
//         else
//         {
//             a[index++] = y[j++];
//         }
//     }
//     while (i <= mid)
//     {
//         a[index++] = x[i++];
//     }
//     while (j <= e)
//     {
//         a[index++] = y[j++];
//     }

//     for (int i = 0; i <= e; i++)
//     {
//         cout << a[i] << "  ";
//     }
//     cout << endl;
// }
// void mergeSort(int a[], int s, int e)
// {
//     if (s >= e)
//         return;
//     int mid = (s + e) / 2;
//     int x[100];
//     int y[100];
//     for (int i = 0; i <= mid; i++)
//     {
//         x[i] = a[i];
//     }
//     for (int i = mid + 1; i <= e; i++)
//     {
//         y[i] = a[i];
//     }
//     mergeSort(x, s, mid);
//     mergeSort(y, mid + 1, e);
//     mergeArrays(x, y, a, s, e);
// }
// int main()
// {
//     int arr[] = {8, 2, 7, 5, 9, 1};
//     // int arr[] = {7, 3, -9, 4, 0, -2, 5, 3, 6, 7, 5, 9, 3};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int startIndex = 0;
//     int endindex = n - 1;
//     mergeSort(arr, startIndex, endindex);
//     // cout << 5 / 2;
//     // for (auto item : arr)
//     //     cout << item << "  ";
// }
// ------------------------------------------------------------70. Climbing Stairs ---------------------------------------------------------
// int climbStairs(int n)
// {
//     if(n == 0 || n == 1)
//         return 1;
//     if(n == 2)
//         return 2;
//     int small_answer = climbStairs(n-1);
//     small_answer += climbStairs(n-2);
//     return small_answer;
// }
// int main()
// {
//     cout << climbStairs(44);
// }
// ------------------------------------------------------------TWO SUM---------------------------------------------------------
// vector<int> twoSum(vector<int> &nums, int target)
// {
//     vector<int> result;
//     int n = nums.size();
//     unordered_map<int, int> umap;
//     for (int i = 0; i < n; i++)
//     {
//         if (umap[target - nums[i]])
//         {
//             result.push_back(i);
//             result.push_back(umap[target - nums[i]] - 1);
//             break;
//         }
//         else
//         {
//             umap[nums[i]] = i + 1;
//         }
//     }
//     return result;
// }

// int main()
// {
//     vector<int> nums = {11, 7, 2, 15};
//     int target = 9;
//     nums = twoSum(nums, target);
//     for(auto item : nums)
//         cout << item << "  ";
// }
//---------------------------------------------54. Spiral Matrix-------------------------------------------------
// int main()
// {
//     // vector<vector<int>> matrix = {{00, 01, 02, 03}, {10, 11, 12, 13}, {20, 21, 22, 23}, {30, 31, 32, 33}};
//     vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
//     vector<int> result;
//     int row = matrix.size();
//     int col = matrix[0].size();
//     int right = matrix[0].size() - 1;
//     int bottom = matrix.size() - 1;
//     int left = 0;
//     int top = 0;
//     int total_elements = row * col;
//     int counter = 0;
//     while (top <= bottom && left <= right)
//     {
//         for (int j = left; j <= right; j++)
//         {
//             result.push_back(matrix[top][j]);
//             counter++;
//         }
//         if (counter == total_elements)
//             break;
//         top++;
//         for (int i = top; i <= bottom; i++)
//         {
//             result.push_back(matrix[i][right]);
//             counter++;
//         }
//         if (counter == total_elements)
//             break;
//         right--;
//         for (int i = right; i >= left; i--)
//         {
//             result.push_back(matrix[bottom][i]);
//             counter++;
//         }
//         if (counter == total_elements)
//             break;
//         bottom--;
//         for (int i = bottom; i >= top; i--)
//         {
//             result.push_back(matrix[i][left]);
//             counter++;
//         }
//         if (counter == total_elements)
//             break;
//         left++;
//     }
//     for (auto item : result)
//         cout << item << "  ";
// }
// ----------------------------------------------------------- 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit --------------------------------------
// ------------------- TLE ----------------------
int longestSubarray(vector<int> &nums, int limit)
{
    int n = nums.size();
    int subArrayLength = 0;
    for (int i = 0; i < n; i++)
    {
        int maxElement = INT_MIN;
        int minElement = INT_MAX;
        for (int j = i; j < n; j++)
        {
            minElement = min(minElement, nums[j]);
            maxElement = max(maxElement, nums[j]);
            int absDifference = abs(maxElement - minElement);
            if (absDifference <= limit)
            {
                int currLength = (j - i) + 1;
                if (currLength > subArrayLength)
                    subArrayLength = currLength;
            }
            // the current subarray exceeds the limit value
            else
            {
                break;
            }
        }
    }
    return subArrayLength;
}
// ---------------------
int longestSubarrayOtherWay(vector<int> &nums, int limit)
{
    int n = nums.size();
    deque<int> maxQueue, minQueue;
    int maxLength = 0;
    int left = 0, right = 0;
    while (right < n)
    {
        // Update maxQueue
        while (!maxQueue.empty() && nums[right] >= nums[maxQueue.back()])
            maxQueue.pop_back();
        maxQueue.push_back(right);
        // Update minQueue
        while (!minQueue.empty() && nums[right] <= nums[minQueue.back()])
            minQueue.pop_back();
        minQueue.push_back(right);
        // Check if the difference exceeds limit
        while (nums[maxQueue.front()] - nums[minQueue.front()] > limit)
        {
            left++;
            if (maxQueue.front() < left)
                maxQueue.pop_front();
            if (minQueue.front() < left)
                minQueue.pop_front();
        }
        // Update maxLength
        maxLength = max(maxLength, right - left + 1);
        right++;
    }
    return maxLength;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> nums = {10, 1, 2, 4, 7, 2};
//     cout << longestSubarrayOtherWay(nums, 5) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }