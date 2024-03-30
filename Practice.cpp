#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

// int main()
// {
//     unordered_map<int, int> umap;
//     umap.insert(pair<int, int>(1, 1));
//     umap.insert(pair<int, int>(2, 2));
//     umap.insert(pair<int, int>(3, 3));
//     umap.insert(pair<int, int>(4, 4));
//     umap.erase(3);
//     for (auto item : umap)
//         cout << item.first << " : " << item.second << endl;
// }

//--------------------------------------------------------------------
// struct Interval
// {
//     int start, end;
// };
// bool compareInterval(Interval i1, Interval i2)
// {
//     return (i1.start < i2.start);
// }
// int main()
// {
//     Interval arr[] = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     sort(arr, arr + n, compareInterval);
//     for (int i = 0; i < n; i++)
//         cout << arr[i].start << " : " << arr[i].end << endl;
// }
//--------------------------------------------------------------------

// int main()
// {
//     cout << "Hello World" << endl;;
//     int limit = 25;
//     int sum = 60;
//     int helper = 0;
//     double randomValue = 2.77;
//     for(int var = 1; var < limit; var = var + 3){
//         cout << "randomValue : " << randomValue << endl;
//         for(int j = 1; j < limit; j = j+2){
//             sum++;
//             helper++;
//         }
//         cout << "Sum : " << sum << endl;
//     }
//     cout << "helper : " << helper << endl;
// }

//--------------------------------------------------------------------
// int main()
// {
//     set<int> s = {1, 2, 3, 4, 8, 9, 10, 34, 55};
//     set<int>::iterator current, previous;
//     for (current = ++s.begin(), previous = s.begin(); current != s.end(); current++, previous++)
//     {
//         cout << *previous << "  :  " << *current << endl;
//     }
// }

//---------------------------------------------------------------------
// string sortStr(string str)
// {
//     string sortedStr;
//     int counter[26] = {0};
//     for (auto &ch : str)
//         counter[ch - 97]++;
//     for (int i = 0; i < 26; i++)
//         sortedStr += string(counter[i], i + 97);
//     return sortedStr;
// }
//---------------------------------------------------------------------
// int main()
// {
//     // string str = "aabbcde";
//     string str = "wwwbbw";
//     int n = str.size();
//     string answer = "";
//     string challengeToken = "9e3cnrz2s5";
//     int counter = 1, i;
//     for (i = 1; i < n; i++)
//     {
//         if (str[i - 1] == str[i])
//             counter++;
//         else
//         {
//             answer.push_back(counter + 48);
//             answer.push_back(str[i - 1]);
//             counter = 1;
//         }
//     }
//     answer.push_back(counter + 48);
//     answer.push_back(str[i - 1]);
//     answer.append(challengeToken);
//     counter = 0;
//     n = answer.length();
//     string finalOutput = "";
//     i = 0;
//     while (i < n)
//     {
//         counter++;
//         if (counter == 4)
//         {
//             finalOutput.push_back('_');
//             counter = 0;
//         }
//         else
//             finalOutput.push_back(answer[i]);
//         i++;
//     }
//     return finalOutput;
// }

//----------------------------------------------------------------
// int main()
// {
//     string sen = "fun&!! time";
//     // string sen = "I love dogs";
//     int n = sen.size();
//     string previousString = "", currentString = "";
//     string challengeToken = "9e3cnrz2s5";
//     for (int i = 0; i < n; i++)
//     {
//         if ((sen[i] >= 'a' && sen[i] <= 'z') || (sen[i] >= 'A' && sen[i] <= 'Z') || (sen[i] >= 48 && sen[i] <= 57))
//             currentString.push_back(sen[i]);
//         else if (currentString.length() > previousString.length())
//         {
//             previousString = currentString;
//             currentString.clear();
//         }
//     }
//     if (currentString.length() > previousString.length())
//         previousString = currentString;
// previousString.append(challengeToken);
// cout << previousString << endl;
// int counter = 0;
// n = previousString.length();
// string finalOutput = "";
// int i = 0;
// while (i < n)
// {
//     counter++;
//     if (counter == 4)
//     {
//         finalOutput.push_back('_');
//         counter = 0;
//     }
//     else
//         finalOutput.push_back(previousString[i]);
//     i++;
// }
// return finalOutput;
// }

//-----------------------------------------------------
// int main()
// {
//     // int *ptr = new int(10);
//     int *ptr = new int;
//     cout << "Address : " << ptr << endl;
//     cout << "Value : " << *ptr << endl;
//     *ptr = 10;
//     cout << "Value : " << *ptr << endl;
//     cout << "Address : " << ptr << endl;
// }

//-------------------------------------------------------------------------------------------------------------------------------------------------------
// int main()
// {
//     vector<int> vect{6, 3, -1, 2, -4, 3, 1, -2, 20};
//     int n = vect.size();
//     int maxSubSetDistance = 0;
//     int sum = 0;
//     // unordered_map<int, int> umap;
//     for (int i = 0; i < n; i++)
//     {
//         sum = 0;
//         for (int j = i; j < n; j++)
//         {
//             sum += vect[j];
//             if (sum == 0)
//             {
//                 if (maxSubSetDistance < (j - i) + 1)
//                 {
//                     maxSubSetDistance = (j - i) + 1;
//                 }
//             }
//         }
//     }
//     cout << maxSubSetDistance << endl;
// }
//--------------------------------------------------------
// int main()
// {
//     vector<int> vect{6, 3, -1, 2, -4, 3, 1, -2, 20};
//     int n = vect.size();
//     int maxSubSetDistance = 0;
//     unordered_map<int, int> umap;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < i; j++)
//         {
//             umap[j] = umap[j] + vect[i];
//             if (umap[j] == 0)
//             {
//                 if (maxSubSetDistance < (i - j) + 1)
//                 {
//                     maxSubSetDistance = (i - j) + 1;
//                 }
//             }
//         }
//         umap[i] = vect[i];
//     }
//     cout << maxSubSetDistance << endl;
// }
//--------------------------------------------------------- TREE TRAVERSAL GENERIC TREE ----------------------------------------------------------------

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
//     ~TreeNode()
//     {
//         for (int i = 0; i < children.size(); i++)
//             delete children.at(i);
//     }
// };
// TreeNode<int> *takeInputLevelWise()
// {
//     queue<TreeNode<int> *> q;
//     int rootData;
//     cout << "Enter Root Data : " << endl;
//     cin >> rootData;
//     TreeNode<int> *root = new TreeNode<int>(rootData);
//     q.push(root);
//     while (!q.empty())
//     {
//         // we can use f instead of q.front()
//         // TreeNode<int> *f = q.front();
//         // q.pop();
//         // How many childrens
//         int n;
//         cout << "Enter number of children of " << q.front()->data << endl;
//         cin >> n;
//         for (int i = 1; i <= n; i++)
//         {
//             int childData;
//             cout << "Enter " << i << " th Child of " << q.front()->data << endl;
//             cin >> childData;
//             TreeNode<int> *child = new TreeNode<int>(childData);
//             q.push(child);
//             q.front()->children.push_back(child);
//         }
//         q.pop();
//     }
//     return root;
// }

// void levelOrderTraversal(TreeNode<int> *root)
// {
//     queue<TreeNode<int> *> q;
//     if (root != NULL)
//         q.push(root);
//     while (!q.empty())
//     {
//         cout << q.front()->data << " : ";
//         for (int i = 0; i < q.front()->children.size(); i++)
//         {
//             cout << q.front()->children.at(i)->data << ", ";
//             q.push(q.front()->children.at(i));
//         }
//         cout << endl;
//         q.pop();
//     }
// }
// void preOrderTraversal(TreeNode<int> *root)
// {
//     if (root == NULL)
//         return;
//     cout << root->data << ", ";
//     // for (int i = 0; i < root->children.size(); i++)
//     //     cout << root->children.at(i)->data << ", ";
//     // cout << endl;
//     for (int i = 0; i < root->children.size(); i++)
//         preOrderTraversal(root->children.at(i));
// }
// void postOrderTraversal(TreeNode<int> *root)
// {
//     if (root == NULL)
//         return;
//     for (int i = 0; i < root->children.size(); i++)
//         postOrderTraversal(root->children.at(i));
//     cout << root->data << ", ";
// }
// void deleteTree(TreeNode<int> *root)
// {
//     if (root == NULL)
//         return;
//     for (int i = 0; i < root->children.size(); i++)
//         deleteTree(root->children.at(i));
//     delete root;
// }
// // 1 3 2 3 4 2 5 6 0 1 9 0 2 7 8 0 0 0
// // 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
// int main()
// {
//     TreeNode<int> *root = takeInputLevelWise();
//     levelOrderTraversal(root);
//     cout << "PreOrder Traversal : ";
//     preOrderTraversal(root);
//     cout << endl
//          << "PostOrder Traversal : ";
//     postOrderTraversal(root);
//     delete root;
//     cout << endl;
//     levelOrderTraversal(root);
// }
// //--------------------------------------------------------- HEIGHT OF THE GENERIC TREE ----------------------------------------------------------------

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
// TreeNode<int> *takeInputLevelWise()
// {
//     queue<TreeNode<int> *> q;
//     int rootData;
//     cout << "Enter Root Data : " << endl;
//     cin >> rootData;
//     TreeNode<int> *root = new TreeNode<int>(rootData);
//     q.push(root);
//     while (!q.empty())
//     {
//         // we can use f instead of q.front()
//         // TreeNode<int> *f = q.front();
//         // q.pop();
//         // How many childrens
//         int n;
//         cout << "Enter number of children of " << q.front()->data << endl;
//         cin >> n;
//         for (int i = 1; i <= n; i++)
//         {
//             int childData;
//             cout << "Enter " << i << " th Child of " << q.front()->data << endl;
//             cin >> childData;
//             TreeNode<int> *child = new TreeNode<int>(childData);
//             q.push(child);
//             q.front()->children.push_back(child);
//         }
//         q.pop();
//     }
//     return root;
// }
// void printTree(TreeNode<int> *root)
// {
//     cout << root->data << " -> ";
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         cout << root->children.at(i)->data << ", ";
//     }
//     cout << endl;
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         printTree(root->children.at(i));
//     }
// }
// void levelOrderTraversal(TreeNode<int> *root)
// {
//     queue<TreeNode<int> *> q;
//     if (root != NULL)
//         q.push(root);
//     while (!q.empty())
//     {
//         cout << q.front()->data << " : ";
//         for (int i = 0; i < q.front()->children.size(); i++)
//         {
//             cout << q.front()->children.at(i)->data << ", ";
//             q.push(q.front()->children.at(i));
//         }
//         cout << endl;
//         q.pop();
//     }
// }
// // int countNodes(TreeNode<int> *root)
// // {
// //     static int nodeCounter = 0;
// //     if (root != NULL)
// //     {
// //         cout << root->data << ", ";
// //         nodeCounter++;
// //     }
// //     for (int i = 0; i < root->children.size(); i++)
// //     {
// //         countNodes(root->children.at(i));
// //     }
// //     return nodeCounter;
// // }
// int countNodes(TreeNode<int> *root)
// {
//     if(root == NULL)
//         return 0;
//     int smallAnswer = 0;
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         smallAnswer += countNodes(root->children.at(i));
//     }
//     return 1 + smallAnswer;
// }
// int heightOfTree(TreeNode<int> *root)
// {
//     if (root == NULL)
//         return 0;
//     int smallAnswer = 0;
//     int childrenHeight = 0;
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         childrenHeight = heightOfTree(root->children.at(i));
//         smallAnswer = max(smallAnswer, childrenHeight);
//     }
//     return 1 + smallAnswer;
// }
// void printNodesAtLevelK(TreeNode<int> *root, int k)
// {
//     if (root == NULL)
//         return;
//     if (k == 0)
//     {
//         cout << root->data << ", ";
//     }
//     if (k > 0)
//     {
//         for (int i = 0; i < root->children.size(); i++)
//         {
//             printNodesAtLevelK(root->children.at(i), k - 1);
//         }
//     }
// }
// int countLeafNodes(TreeNode<int> *root)
// {
//     if (root == NULL)
//         return 0;
//     if (root->children.size() == 0)
//         return 1;
//     int smallAnswer = 0;
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         smallAnswer += countLeafNodes(root->children.at(i));
//     }
//     return smallAnswer;
// }
// int main()
// {
//     TreeNode<int> *root = takeInputLevelWise();
//     levelOrderTraversal(root);
//     // printTree(root);
//     cout << endl
//          << "Total number of nodes are : " << countNodes(root) << endl;
//     cout << "Height of the tree : " << heightOfTree(root) << endl;
//     // int levelNumberToFind;
//     // cout << endl << "Enter the level number you want to find nodes : ";
//     // cin >> levelNumberToFind;
//     // printNodesAtLevelK(root, levelNumberToFind);
//     cout << "Count number of leaf nodes : " << countLeafNodes(root) << endl;
// }
// //--------------------------------------------------------- COUNT NUMBER OF NODES IN GENERIC TREE ----------------------------------------------------------------

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
// TreeNode<int> *takeInputLevelWise()
// {
//     queue<TreeNode<int> *> q;
//     int rootData;
//     cout << "Enter Root Data : " << endl;
//     cin >> rootData;
//     TreeNode<int> *root = new TreeNode<int>(rootData);
//     q.push(root);
//     while (!q.empty())
//     {
//         // we can use f instead of q.front()
//         // TreeNode<int> *f = q.front();
//         // q.pop();
//         // How many childrens
//         int n;
//         cout << "Enter number of children of " << q.front()->data << endl;
//         cin >> n;
//         for (int i = 1; i <= n; i++)
//         {
//             int childData;
//             cout << "Enter " << i << " th Child of " << q.front()->data << endl;
//             cin >> childData;
//             TreeNode<int> *child = new TreeNode<int>(childData);
//             q.push(child);
//             q.front()->children.push_back(child);
//         }
//         q.pop();
//     }
//     return root;
// }
// void printTree(TreeNode<int> *root)
// {
//     cout << root->data << " -> ";
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         cout << root->children.at(i)->data << ", ";
//     }
//     cout << endl;
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         printTree(root->children.at(i));
//     }
// }
// void levelOrderTraversal(TreeNode<int> *root)
// {
//     queue<TreeNode<int> *> q;
//     if (root != NULL)
//         q.push(root);
//     while (!q.empty())
//     {
//         cout << q.front()->data << " : ";
//         for (int i = 0; i < q.front()->children.size(); i++)
//         {
//             cout << q.front()->children.at(i)->data << ", ";
//             q.push(q.front()->children.at(i));
//         }
//         cout << endl;
//         q.pop();
//     }
// }
// // int countNodes(TreeNode<int> *root)
// // {
// //     static int nodeCounter = 0;
// //     if (root != NULL)
// //     {
// //         cout << root->data << ", ";
// //         nodeCounter++;
// //     }
// //     for (int i = 0; i < root->children.size(); i++)
// //     {
// //         countNodes(root->children.at(i));
// //     }
// //     return nodeCounter;
// // }
// int countNodes(TreeNode<int> *root)
// {
//     int smallAnswer = 0;
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         smallAnswer += countNodes(root->children.at(i));
//     }
//     return 1 + smallAnswer;
// }
// int main()
// {
//     TreeNode<int> *root = takeInputLevelWise();
//     levelOrderTraversal(root);
//     // printTree(root);
//     cout << endl
//          << "Total number of nodes are : " << countNodes(root) << endl;
// }
//--------------------------------------------------------- LEVEL ORDER TREE TRAVERSAL ----------------------------------------------------------------

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
// TreeNode<int> *takeInputLevelWise()
// {
//     queue<TreeNode<int> *> q;
//     int rootData;
//     cout << "Enter Root Data : " << endl;
//     cin >> rootData;
//     TreeNode<int> *root = new TreeNode<int>(rootData);
//     q.push(root);
//     while (!q.empty())
//     {
//         // we can use f instead of q.front()
//         // TreeNode<int> *f = q.front();
//         // q.pop();
//         // How many childrens
//         int n;
//         cout << "Enter number of children of " << q.front()->data << endl;
//         cin >> n;
//         for (int i = 1; i <= n; i++)
//         {
//             int childData;
//             cout << "Enter " << i << " th Child of " << q.front()->data << endl;
//             cin >> childData;
//             TreeNode<int> *child = new TreeNode<int>(childData);
//             q.push(child);
//             q.front()->children.push_back(child);
//         }
//         q.pop();
//     }
//     return root;
// }
// void printTree(TreeNode<int> *root)
// {
//     cout << root->data << " -> ";
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         cout << root->children.at(i)->data << ", ";
//     }
//     cout << endl;
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         printTree(root->children.at(i));
//     }
// }
// void levelOrderTraversal(TreeNode<int> *root)
// {
//     queue<TreeNode<int> *> q;
//     if (root != NULL)
//         q.push(root);
//     while (!q.empty())
//     {
//         cout << q.front()->data << " : ";
//         for (int i = 0; i < q.front()->children.size(); i++)
//         {
//             cout << q.front()->children.at(i)->data << ", ";
//             q.push(q.front()->children.at(i));
//         }
//         cout << endl;
//         q.pop();
//     }
// }
// int countNodes(TreeNode<int> *root)
// {
//     static int nodeCounter = 0;
//     if (root != NULL)
//     {
//         cout << root->data << ", ";
//         nodeCounter++;
//     }
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         countNodes(root->children.at(i));
//     }
//     return nodeCounter;
// }
// int main()
// {
//     TreeNode<int> *root = takeInputLevelWise();
//     levelOrderTraversal(root);
//     // printTree(root);
//     cout << endl
//          << "Total number of nodes are : " << countNodes(root) << endl;
// }
//--------------------------------------------------------- TAKING INPUT IN TREE LEVEL WISE ----------------------------------------------------------------
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
// TreeNode<int> *takeInputLevelWise()
// {
//     queue<TreeNode<int> *> q;
//     int rootData;
//     cout << "Enter Root Data : " << endl;
//     cin >> rootData;
//     TreeNode<int> *root = new TreeNode<int>(rootData);
//     q.push(root);
//     while (!q.empty())
//     {
//         // we can use f instead of q.front()
//         // TreeNode<int> *f = q.front();
//         // q.pop();
//         // How many childrens
//         int n;
//         cout << "Enter number of children of " << q.front()->data << endl;
//         cin >> n;
//         for (int i = 1; i <= n; i++)
//         {
//             int childData;
//             cout << "Enter " << i << " th Child of " << q.front()->data << endl;
//             cin >> childData;
//             TreeNode<int> *child = new TreeNode<int>(childData);
//             q.push(child);
//             q.front()->children.push_back(child);
//         }
//         q.pop();
//     }
//     return root;
// }
// //---------------------------------
// // TreeNode<int> * takeInput(TreeNode<int> *root)
// // {
// //     static int flage = 0;
// //     if (!flage)
// //     {
// //         int rootData;
// //         cout << "Enter Root Data : " << endl;
// //         cin >> rootData;
// //         root = new TreeNode<int>(rootData);
// //         flage++;
// //     }
// //     int n;
// //     cout << "Enter number of children of " << root->data << " : " << endl;
// //     cin >> n;
// //     for (int i = 1; i <= n; i++)
// //     {
// //         int childData;
// //         cout << "Enter " << i << " th Child of " << root->data << " : " << endl;
// //         cin >> childData;
// //         TreeNode<int> *child = new TreeNode<int>(childData);
// //         root->children.push_back(child);
// //     }
// //     for (int i = 0; i < root->children.size(); i++)
// //     {
// //         takeInput(root->children.at(i));
// //     }
// //     return root;
// // }
// void printTree(TreeNode<int> *root)
// {
//     cout << root->data << " -> ";
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         cout << root->children.at(i)->data << ", ";
//     }
//     cout << endl;
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         printTree(root->children.at(i));
//     }
// }
// int main()
// {
//     TreeNode<int> *root = takeInputLevelWise();
//     printTree(root);
// }
//----------------------------------------------------------------- TAKING INPUT RECURSIVELY IN TREE ------------------------------------------------------------------
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
// TreeNode<int> *takeInput()
// {
// int rootData;
// cout << "Enter Root Data : " << endl;
// cin >> rootData;
// TreeNode<int> *root = new TreeNode<int>(rootData);
// // How many childrens
// int n;
// cout << "Enter number of children of " << rootData << endl;
// cin >> n;
// for (int i = 1; i <= n; i++)
// {
//     TreeNode<int> *child = takeInput();
//     root->children.push_back(child);
// }
// return root;
// }
// void printTree(TreeNode<int> *root)
// {
//     cout << root->data << " -> ";
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         cout << root->children.at(i)->data << ", ";
//     }
//     cout << endl;
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         printTree(root->children.at(i));
//     }
// }
// int main()
// {
//     TreeNode<int> *root = takeInput();
//     printTree(root);
// }
//----------------------------------------------------------------- PRINT RECURSIVELY GENERIC TREE NODE CLASS ------------------------------------------------------------------
// template <typename T>
// class TreeNode
// {
// public:
//     T data;
//     vector<TreeNode<T> *> children;
//     TreeNode(int data)
//     {
//         this->data = data;
//     }
// };
// // void printTree(TreeNode<int> *root)
// // {
// //     cout << root->data << "  ";
// //     for (int i = 0; i < root->children.size(); i++)
// //     {
// //         printTree(root->children.at(i));
// //     }
// // }
// // void printTree(TreeNode<int> *root)
// // {
// //     // Edge Case
// //     if(root == NULL)
// //         return;
// //     cout << root->data << " -> ";
// //     for (int i = 0; i < root->children.size(); i++)
// //     {
// //         cout << root->children.at(i)->data << ", ";
// //     }
// //     cout << endl;
// //     for (int i = 0; i < root->children.size(); i++)
// //     {
// //         printTree(root->children.at(i));
// //     }
// // }
// // void printTreeLevelOrder(TreeNode<int> *root)
// // {
// //     static int flage = 0;
// //     // Edge Case
// //     if (root == NULL)
// //         return;
// //     if (!flage)
// //     {
// //         cout << root->data << ", ";
// //         flage++;
// //     }
// //     for (int i = 0; i < root->children.size(); i++)
// //     {
// //         cout << root->children.at(i)->data << ", ";
// //     }
// //     for (int i = 0; i < root->children.size(); i++)
// //     {
// //         printTreeLevelOrder(root->children.at(i));
// //     }
// // }
// void printTreeLevelOrder(TreeNode<int> *root)
// {
//     queue<TreeNode<int> *> q;
//     if (root != NULL)
//     {
//         q.push(root);
//     }
//     while (!q.empty())
//     {
//         cout << q.front()->data << ", ";
//         for (int i = 0; i < q.front()->children.size(); i++)
//         {
//             q.push(q.front()->children.at(i));
//         }
//         q.pop();
//     }
// }
// int main()
// {
//     TreeNode<int> *root = new TreeNode<int>(1);
//     TreeNode<int> *n1 = new TreeNode<int>(2);
//     TreeNode<int> *n2 = new TreeNode<int>(3);
//     TreeNode<int> *n3 = new TreeNode<int>(4);
//     TreeNode<int> *n4 = new TreeNode<int>(5);
//     TreeNode<int> *n5 = new TreeNode<int>(6);
//     TreeNode<int> *n6 = new TreeNode<int>(7);
//     TreeNode<int> *n7 = new TreeNode<int>(8);
//     TreeNode<int> *n8 = new TreeNode<int>(9);
//     TreeNode<int> *n9 = new TreeNode<int>(10);

//     root->children.push_back(n1);
//     root->children.push_back(n2);
//     root->children.push_back(n3);

//     n1->children.push_back(n4);
//     n1->children.push_back(n5);

//     n2->children.push_back(n6);
//     n2->children.push_back(n7);

//     n3->children.push_back(n8);
//     n3->children.push_back(n9);

//     printTreeLevelOrder(root);
// }
//----------------------------------------------------------------- GENERIC TREE NODE CLASS ------------------------------------------------------------------
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
// int main()
// {
//     TreeNode<int> *root = new TreeNode<int>(1);
//     TreeNode<int> *n1 = new TreeNode<int>(2);
//     TreeNode<int> *n2 = new TreeNode<int>(3);

//     root->children.push_back(n1);
//     root->children.push_back(n2);
//     //-----------------------
//     // TreeNode<int> root(1);
//     // TreeNode<int> n1(2);
//     // TreeNode<int> n2(3);

//     // root.children.push_back(&n1);
//     // root.children.push_back(&n2);
// }
//----------------------------------------------------------------- VECTOR ------------------------------------------------------------------
// int main()
// {
//     vector<int> *vrct = new vector<int>();
//     vector<int> v;
// v.push_back(10);
// v.push_back(20);
// v.push_back(30);
// v[3] = 40;
// v[4] = 50;
// v[5] = 60;
// v[6] = 70;
// v.push_back(80);
// v.push_back(90);
// cout << v[0] << endl;
// cout << v[1] << endl;
// cout << v[2] << endl;
// cout << v[3] << endl;
// cout << v[4] << endl;
// cout << v[5] << endl;
// cout << v[6] << endl;
//----------------------
// cout << v.at(0) << endl;
// cout << v.at(1) << endl;
// cout << v.at(2) << endl;
// cout << v.at(3) << endl;
// cout << v.at(4) << endl;
// cout << v.at(5) << endl;
// cout << v.at(6) << endl;
//-----------------------
// v.pop_back();
// for (int i = 0; i < v.size(); i++)
// {
//     cout << v.at(i) << "  ";
//     // cout << v[i] << "  ";
// }
//-------------------------------------
// for (int i = 0; i < 100; i++)
// {
//     v.push_back(i + 1);
//     cout << "Index : " << i << " and Capacity : " << v.capacity() << endl;
// }
// for (int i = 0; i < v.size(); i++)
// {
//     cout << v.at(i) << "  ";
// }
// }
//----------------------------------------------------------- Reverse a queue ------------------------------------------------------------
// void print(queue<int> *q)
// {
//     while (!q->empty())
//     {
//         cout << q->front() << "  ";
//         q->pop();
//     }
//     cout << " end!" << endl;
// }
// void reverseQueue(queue<int> *q)
// {
//     stack<int> s;
//     while (!q->empty())
//     {
//         s.push(q->front());
//         q->pop();
//     }
//     while (!s.empty())
//     {
//         q->push(s.top());
//         s.pop();
//     }
// }
// int main()
// {
//     queue<int> *q = new queue<int>();
//     q->push(10);
//     q->push(20);
//     q->push(30);
//     q->push(40);
//     q->push(50);
//     q->push(60);
//     reverseQueue(q);
//     print(q);
// }
//----------------------------------------------------------- Inbuilt Queue ------------------------------------------------------------
// void print(queue<int> &q)
// {
//     while (!q.empty())
//     {
//         cout << q.front() << "  ";
//         q.pop();
//     }
//     cout << " end!";
// }
//------------------------
// void print(queue<int> q)
// {
//     while (!q.empty())
//     {
//         cout << q.front() << "  ";
//         q.pop();
//     }
//     cout << " end!" << endl;
// }
// int main()
// {
//     queue<int> q;
//     q.push(10);
//     q.push(20);
//     q.push(30);
//     q.push(40);
//     q.push(50);
//     q.push(60);
//     print(q);
//     cout << "queue size : " << q.size() << endl;
//     cout << "queue front item : " << q.front() << endl;
//     cout << "queue is empty : " << q.empty() << endl;
//     q.pop();
//     q.pop();
//     print(q);
// }
//--------------------------------------------------- QUEUE Using Linked List ----------------------------------------------------------
// template <typename T>
// class Node
// {
// public:
//     T val;
//     Node<T> *next;
//     Node() : val(0), next(nullptr) {}
//     Node(T val) : val(val), next(nullptr) {}
//     Node(T val, Node<T> *next) : val(val), next(next) {}
// };
// template <typename T>
// class Queue
// {
//     Node<T> *head;
//     Node<T> *tail;
//     int size;

// public:
//     Queue()
//     {
//         head = NULL;
//         tail = NULL;
//         size = 0;
//     }
//     void push(T element)
//     {
//         Node<T> *newNode = new Node<T>(element);
//         newNode->next = NULL;
//         if (head == NULL)
//         {
//             head = newNode;
//             tail = newNode;
//         }
//         else
//         {
//             tail->next = newNode;
//             tail = newNode;
//         }
//         size++;
//     }
//     void print()
//     {
//         Node<T> *temp = head;
//         while (temp != NULL)
//         {
//             cout << temp->val << " -> ";
//             temp = temp->next;
//         }
//         cout << " NULL";
//     }
//     void pop()
//     {
//         if (head == NULL)
//         {
//             cout << "Queue Underflow!" << endl;
//             return;
//         }
//         Node<T> *temp = head;
//         head = head->next;
//         temp->next = NULL;
//         delete temp;
//     }
//     void front()
//     {
//         if (head == NULL)
//         {
//             cout << "Queue Underflow!" << endl;
//             return;
//         }
//         cout << "Queue front value : " << head->val << endl;
//     }
// };
// int main()
// {
//     Queue<int> queue;
//     queue.push(10);
//     queue.push(20);
//     queue.push(30);
//     queue.push(40);
//     queue.push(50);
//     queue.pop();
//     queue.print();
// }
//---------------------------------------------- DYNAMIC QUEUE Using Array -------------------------------------------------------

// template <typename T>
// class Queue
// {
//     T *arr;
//     int nextIndex;
//     int frontIndex;
//     int capacity;
//     int size;

// public:
//     Queue()
//     {
//         arr = new T[5];
//         nextIndex = 0;
//         frontIndex = -1;
//         size = 0;
//         capacity = 5;
//     }
//     Queue(int cap)
//     {
//         arr = new T[cap];
//         nextIndex = 0;
//         frontIndex = -1;
//         size = 0;
//         capacity = cap;
//     }
//     void push(T ele)
//     {
//         if (size == capacity)
//         {
//             T *newArray = new T[2 * capacity];
//             int j = 0;
//             for (int i = frontIndex; i < frontIndex + size; i++)
//             {
//                 newArray[j++] = arr[i];
//             }
//             frontIndex = 0;
//             nextIndex = capacity;
//             delete[] arr;
//             arr = newArray;
//             capacity = 2 * capacity;
//         }
//         arr[nextIndex] = ele;
//         cout << "Inserted element : " << arr[nextIndex % capacity] << endl;
//         size++;
//         nextIndex = (nextIndex + 1) % capacity;
//         if (frontIndex == -1)
//         {
//             frontIndex = 0;
//         }
//     }
//     void print()
//     {
//         if (size == 0)
//         {
//             cout << "Queue Underflow!" << endl;
//             return;
//         }
//         for (int i = frontIndex; i < frontIndex + size; i++)
//         {
//             cout << arr[i % capacity] << "  ";
//         }
//         cout << " end!" << endl;
//     }
//     void front()
//     {
//         if (size == 0)
//         {
//             cout << "Queue Underflow!" << endl;
//             return;
//         }
//         cout << "Queue font element : " << arr[frontIndex] << endl;
//     }
//     void pop()
//     {
//         if (size == 0)
//         {
//             cout << "Queue Underflow!" << endl;
//             return;
//         }
//         cout << "Popped element : " << arr[frontIndex] << endl;
//         frontIndex = (frontIndex + 1) % capacity;
//         size--;
//         if (size == 0 || frontIndex == nextIndex)
//         {
//             frontIndex = -1;
//             nextIndex = 0;
//         }
//     }
//     void getSize()
//     {
//         cout << "Queue size : " << size << endl;
//     }
//     bool isEmpty()
//     {
//         return size;
//     }
// };
// int main()
// {
//     Queue<int> *queue = new Queue<int>();
//     queue->push(10);
//     queue->push(20);
//     queue->push(30);
//     queue->push(40);
//     queue->push(50);
//     queue->push(60);
//     queue->push(10);
//     queue->push(20);
//     queue->push(30);
//     queue->push(40);
//     queue->push(50);
//     queue->push(60);
//     queue->push(10);
//     queue->push(20);
//     queue->push(30);
//     queue->push(40);
//     queue->push(50);
//     queue->push(60);
//     queue->push(10);
//     queue->push(20);
//     queue->push(30);
//     queue->push(40);
//     queue->push(50);
//     queue->push(60);
//     queue->print();
// }
//--------------------------------------------------------------------- QUEUE Using Array --------------------------------------------------------------------
// template <typename T>
// class Queue
// {
//     T *arr;
//     int nextIndex;
//     int frontIndex;
//     int capacity;
//     int size;

// public:
//     Queue()
//     {
//         arr = new T[5];
//         nextIndex = 0;
//         frontIndex = -1;
//         size = 0;
//         capacity = 5;
//     }
//     Queue(int cap)
//     {
//         arr = new T[cap];
//         nextIndex = 0;
//         frontIndex = -1;
//         size = 0;
//         capacity = cap;
//     }
//     // void push(T ele)
//     // {
//     //     if (size == capacity)
//     //     {
//     //         cout << "Queue Overflow!" << endl;
//     //         return;
//     //     }
//     //     arr[nextIndex] = ele;
//     //     cout << "Inserted element : " << arr[nextIndex % capacity] << endl;
//     //     size++;
//     //     nextIndex = (nextIndex + 1) % capacity;
//     //     // if (size == 1)
//     //     // {
//     //     //     frontIndex = nextIndex - 1;
//     //     // }
//     //     if (frontIndex == -1)
//     //     {
//     //         frontIndex = 0;
//     //     }
//     // }
//     void push(T ele)
//     {
//     if (size == capacity)
//     {
//         T newArray = new int[2 * capacity];
//         int j = 0;
//         for (int i = frontIndex; i < frontIndex + size; i++)
//         {
//             newArray[j++] = arr[i];
//         }
//         frontIndex = 0;
//         nextIndex = nextIndex - frontIndex;
//     }
//         arr[nextIndex] = ele;
//         cout << "Inserted element : " << arr[nextIndex % capacity] << endl;
//         size++;
//         nextIndex = (nextIndex + 1) % capacity;
//         // if (size == 1)
//         // {
//         //     frontIndex = nextIndex - 1;
//         // }
//         if (frontIndex == -1)
//         {
//             frontIndex = 0;
//         }
//     }
//     void print()
//     {
//         if (size == 0)
//         {
//             cout << "Queue Underflow!" << endl;
//             return;
//         }
//         for (int i = frontIndex; i < frontIndex + size; i++)
//         {
//             cout << arr[i % capacity] << "  ";
//         }
//         cout << " end!" << endl;
//     }
//     void front()
//     {
//         if (size == 0)
//         {
//             cout << "Queue Underflow!" << endl;
//             return;
//         }
//         cout << "Queue font element : " << arr[frontIndex] << endl;
//     }
//     void pop()
//     {
//         if (size == 0)
//         {
//             cout << "Queue Underflow!" << endl;
//             return;
//         }
//         cout << "Popped element : " << arr[frontIndex] << endl;
//         frontIndex = (frontIndex + 1) % capacity;
//         size--;
//         if (size == 0 || frontIndex == nextIndex)
//         {
//             frontIndex = -1;
//             nextIndex = 0;
//         }
//     }
//     void getSize()
//     {
//         cout << "Queue size : " << size << endl;
//     }
//     bool isEmpty()
//     {
//         return size;
//     }
// };

// int main()
// {
//     Queue<int> *queue = new Queue<int>();
//     queue->push(10);
//     queue->push(20);
//     queue->push(30);
//     queue->push(40);
//     queue->push(50);
//     queue->push(60);
//     queue->print();
//     queue->front();
//     queue->pop();
//     // queue->pop();
//     // queue->pop();
//     // queue->pop();
//     // queue->pop();
//     queue->push(60);
//     queue->push(70);
//     queue->push(80);
//     queue->getSize();
//     queue->print();
//     queue->pop();
//     queue->pop();
//     queue->pop();
//     queue->pop();
//     queue->pop();
//     queue->pop();
//     queue->pop();
//     queue->pop();
//     queue->pop();
//     queue->pop();
//     queue->pop();
//     queue->pop();
// }

//---------------------------------------------------------------------------------------------------------------------------------------------------------------
// int main()
// {
//     string s = "bcabc";
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
//         else
//         {
//             if (s[i] < result_stack.back())
//             {
//                 while (!result_stack.empty())
//                 {
//                     if (character_frequency[result_stack.back()])
//                     {
//                         occure[result_stack.back()] = 0;
//                         result_stack.pop_back();
//                     }
//                     else
//                     {
//                         break;
//                     }
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
//     cout << result_stack << endl;
// }

//---------------------------------------
// int main()
// {
//     string first = "bcabc";
//     string second = "bcabc";
//     string result;
//     int n = first.size();
//     int i = 0, j = n - 1;
//     while (i < n)
//     {
//         if (first[i] == second[j] && (j > i))
//         {

//             first = first.substr(0, i) + first.substr(i + 1);
//             second = second.substr(0, j) + second.substr(j + 1);
//             int x = strcmp(first.c_str(), second.c_str());
//             if(x < 0){
//                 result = first;
//             }
//             else{
//                 result = second;
//             }
//             first = result;
//             second = result;
//             i = 0;
//             n = result.size();
//             j = n - 1;
//         }
//         else if (j > i + 1)
//         {
//             j--;
//         }
//         else
//         {
//             i++;
//             j = n - 1;
//         }
//     }
//     cout << result << endl;
// }
//-----------------------------
// int main()
// {
//     string str = "wwwbbbw";
//     int n = str.size();
//     string halfResult = "";
//     int counter = 1;
//     int i = 0;
//     while (i < n)
//     {
//         if (str[i] == str[i + 1])
//         {
//             counter++;
//             i++;
//         }
//         else
//         {
//             halfResult = halfResult + to_string(counter) + str[i];
//             counter = 1;
//             i++;
//         }
//     }
//     string finalResult;
//     for (int i = 0; i < halfResult.length(); i++)
//     {
//         if (halfResult[i] == 'k' || halfResult[i] == 'p' || halfResult[i] == 's' || halfResult[i] == '7' || halfResult[i] == 'm' || halfResult[i] == '3' || halfResult[i] == 'z' || halfResult[i] == 'b' || halfResult[i] == '8' || halfResult[i] == '1')
//         {
//             finalResult = finalResult + "--" + halfResult[i] + "--";
//         }
//         else
//         {
//             finalResult += halfResult[i];
//         }
//     }
//     cout << finalResult << endl;
// }

//--------------------------------------
// int main()
// {
//     string sen = "fun&!! time";
//     int n = sen.size();
//     string newSen;
//     string previouResult = "";
//     string currentResult = "";
//     for (int i = 0; i < n; i++)
//     {
//         if (sen[i] >= 'a' && sen[i] <= 'z' || sen[i] >= 'A' && sen[i] <= 'Z' || sen[i] >= '0' && sen[i] <= '9' || sen[i] == ' ')
//         {
//             newSen += sen[i];
//         }
//     }
//     n = newSen.size();
//     for (int i = 0; i < n; i++)
//     {
//         if (newSen[i] == ' ')
//         {
//             if (previouResult.length() < currentResult.length())
//             {
//                 previouResult = currentResult;
//                 currentResult.clear();
//             }
//             else
//             {
//                 currentResult.clear();
//             }
//         }
//         else
//         {
//             currentResult += newSen[i];
//         }
//     }
//     if (previouResult.length() < currentResult.length())
//     {
//         previouResult = currentResult;
//         currentResult.clear();
//     }
// string finalResult;
// for (int i = 0; i < previouResult.length(); i++)
// {
//     if (previouResult[i] == 'k' || previouResult[i] == 'p' || previouResult[i] == 's' || previouResult[i] == '7' || previouResult[i] == 'm' || previouResult[i] == '3' || previouResult[i] == 'z' || previouResult[i] == 'b' || previouResult[i] == '8' || previouResult[i] == '1')
//     {
//         finalResult = finalResult + "--" + previouResult[i] + "--";
//     }
//     else
//     {
//         finalResult += previouResult[i];
//     }
// }
//     cout << finalResult << endl;
// }

//-------------------------------------------------REMOVE duplicate from a string----------------------------------------------------
// int main()
// {
//     string s = "aaabbbccc";
//     int i = 0, j = 0, n = s.size();
//     while (j < n)
//     {
//         if (s[i] != s[j])
//         {
//             s[++i] = s[j];
//         }
//         j++;
//     }
//     cout << s.substr(0, i+1) << endl;
// }
// ----------------------------------------------------------- Inbuilt Stack --------------------------------------------------------
// int main()
// {
//     stack<char> s1;
//     s1.push(65);
//     s1.push(66);
//     s1.push(67);
//     s1.push(68);
//     s1.push(69);
//     s1.push(97);
//     s1.push(98);
//     s1.push(99);
//     s1.push(100);
//     s1.push(101);
//     cout << s1.empty() << endl;
//     cout << s1.size() << endl;
//     while (!s1.empty())
//     {
//         cout << s1.top() << "  ";
//         s1.pop();
//     }
// }
// ----------------------------------------------------------- Stack Using Linked List --------------------------------------------------------
// template <typename T>
// class Node
// {
// public:
//     T val;
//     Node<T> *next;
//     Node() : val(0), next(nullptr) {}
//     Node(T val) : val(val), next(nullptr) {}
//     Node(T val, Node<T> *next) : val(val), next(next) {}
// };
// template <typename T>
// class Stack
// {
//     Node<T> *head;
//     int size;

// public:
//     Stack()
//     {
//         head = NULL;
//         size = 0;
//     }
//     void push(T ele)
//     {
//         Node<T> *newNode = new Node<T>(ele);
//         newNode->next = head;
//         head = newNode;
//         size++;
//     }
//     void print()
//     {
//         Node<T> *temp = head;
//         while (temp != NULL)
//         {
//             cout << temp->val << ", ";
//             temp = temp->next;
//         }
//     }
//     int stackSize()
//     {
//         return size;
//     }
//     bool isEmpty()
//     {
//         return head == NULL;
//     }
//     void pop()
//     {
//         if (isEmpty())
//         {
//             cout << "Stack Empty!" << endl;
//         }
//         else
//         {
//             Node<T> *temp = head;
//             head = head->next;
//             temp->next = NULL;
//             delete temp;
//             size--;
//         }
//     }
//     T top()
//     {
//         if (isEmpty())
//         {
//             cout << "Stack Empty!" << endl;
//             return 0;
//         }
//         return head->val;
//     }
// };
// int main()
// {
//     Stack<char> s;
//     s.push(65);
//     s.push(66);
//     s.push(67);
//     s.push(68);
//     s.push(69);
//     s.push(97);
//     s.push(98);
//     s.push(99);
//     s.push(100);
//     s.push(101);
//     // s.pop();
//     // s.pop();
//     // s.pop();
//     // s.pop();
//     // s.pop();
//     // s.pop();
//     s.print();
//     // cout << s.stackSize() << endl;
// }
// ----------------------------------------------------------- Templates --------------------------------------------------------
//--------------------- Stack Using Template----------------------------
// template <typename T>
// class Stack
// {
//     T *arr;
//     int nextIndex;
//     int capacity;

// public:
//     Stack()
//     {
//         arr = new T[5];
//         capacity = 5;
//         nextIndex = 0;
//     }
//     int size()
//     {
//         return nextIndex;
//     }
//     bool isEmpty()
//     {
//         return nextIndex == 0;
//     }
//     void push(T ele)
//     {
//         if (nextIndex == capacity)
//         {
//             T *newArr = new T[capacity * 2];
//             for (int i = 0; i < capacity; i++)
//                 newArr[i] = arr[i];
//             capacity = capacity * 2;
//             delete[] arr;
//             arr = newArr;
//         }
//         arr[nextIndex++] = ele;
//     }
//     void pop()
//     {
//         if (isEmpty())
//         {
//             cout << "Stack Empty!" << endl;
//             return;
//         }
//         cout << "Element " << arr[nextIndex - 1] << " removed!" << endl;
//         nextIndex--;
//     }
//     T top()
//     {
//         if (isEmpty())
//         {
//             cout << "Stack Empty!" << endl;
//             return 0;
//         }
//         return arr[nextIndex - 1];
//     }
// };
// int main()
// {
//     Stack<char> s1;
//     s1.push('A');
//     s1.push('B');
//     s1.push('C');
//     s1.push('D');
//     s1.push('E');
//     s1.push('A');
//     s1.push('B');
//     s1.push('C');
//     s1.push('D');
//     s1.push('E');
//     cout << s1.size() << endl;
//     while (!s1.isEmpty())
//     {
//         s1.pop();
//     }
//     s1.pop();
// }
//----------------------------------------------------------------------
// template <typename T, typename V>
// class Pair
// {
//     T x;
//     V y;

// public:
//     void setX(T x)
//     {
//         this->x = x;
//     }
//     void setY(V y)
//     {
//         this->y = y;
//     }
//     T getX()
//     {
//         return x;
//     }
//     V getY()
//     {
//         return y;
//     }
// };
// int main()
// {
//     Pair<int, int> p1;
//     p1.setX(10);
//     p1.setY(20);
//     Pair<Pair<int, int>, int> p2;
//     p2.setX(p1);
//     p2.setY(30);
//     cout << p2.getX().getX() << "  :  " << p2.getX().getY() << "  :  " << p2.getY() << endl;
// }
//---------------------------------------
// template <typename T1, typename T2>
// class Pair
// {
//     T1 x;
//     T2 y;

// public:
//     void setX(T1 x)
//     {
//         this->x = x;
//     }
//     void setY(T2 y)
//     {
//         this->y = y;
//     }
//     T1 getX()
//     {
//         return x;
//     }
//     T2 getY()
//     {
//         return y;
//     }
// };
// int main()
// {
//     Pair<int, double> p1;
//     p1.setX(2);
//     p1.setY(4);
//     cout << p1.getX() << "  :  " << p1.getY() << endl;

//     Pair<double, int> p2;
//     p2.setX(234.34);
//     p2.setY(13);
//     cout << p2.getX() << "  :  " << p2.getY() << endl;

//     Pair<char, int> p3;
//     p3.setX('A');
//     p3.setY('B');
//     cout << p3.getX() << "  :  " << p3.getY() << endl;
// }
//------------------------------------------
// template <typename T>
// class Pair
// {
//     T x;
//     T y;

// public:
//     void setX(T x)
//     {
//         this->x = x;
//     }
//     void setY(T y)
//     {
//         this->y = y;
//     }
//     T getX()
//     {
//         return x;
//     }
//     T getY()
//     {
//         return y;
//     }
// };
// int main()
// {
//     Pair<int> p1;
//     p1.setX(2);
//     p1.setY(4);
//     cout << p1.getX() << "  :  " << p1.getY() << endl;

//     Pair<double> p2;
//     p2.setX(234.34);
//     p2.setY(12.32);
//     cout << p2.getX() << "  :  " << p2.getY() << endl;

//     Pair<char> p3;
//     p3.setX('A');
//     p3.setY('B');
//     cout << p3.getX() << "  :  " << p3.getY() << endl;
// }
// -----------------------------------------------------------Stack Implementation Using Array--------------------------------------------------------
// class Stack
// {
//     int *arr;
//     int nextIndex;
//     int capacity;

// public:
//     Stack()
//     {
//         arr = new int[5];
//         nextIndex = 0;
//         capacity = 5;
//     }
//     Stack(int cap)
//     {
//         arr = new int[cap];
//         nextIndex = 0;
//         capacity = cap;
//     }
//     int size()
//     {
//         return nextIndex;
//     }
//     bool isEmpty()
//     {
//         // if(nextIndex == 0)
//         //     return true;
//         // return false;
//         return nextIndex == 0;
//     }
//     void push(int ele)
//     {
//         if (nextIndex == capacity)
//         {
//             // cout << "Stack Full!" << endl;
//             // return;
//             int *newArr = new int[2*capacity];
//             for(int i = 0; i < capacity; i++)
//                 newArr[i] = arr[i];
//             delete []arr;
//             arr = newArr;
//             capacity = capacity*2;
//         }
//         arr[nextIndex++] = ele;
//     }
//     void pop()
//     {
//         if (isEmpty())
//         {
//             cout << "Stack Empty!" << endl;
//             return;
//         }
//         cout << "Element " << arr[--nextIndex] << " removed!" << endl;
//     }
//     int top()
//     {
//         if (isEmpty())
//         {
//             cout << "Stack Empty!" << endl;
//             return -1;
//         }
//         return arr[nextIndex-1];
//     }
// };
// int main()
// {
//     // Stack s;
//     // s.push(2);
//     // s.push(4);
//     // s.push(6);
//     // s.push(8);
//     // s.push(10);
//     // s.push(12);
//     // s.push(14);
//     // cout << s.size() << endl;

//     vector<int> vect;
//     vect.push_back(2);
//     vect.pop_back();
//     vect.size();
//     cout << vect.front() << endl;
//     cout << vect.empty() << endl;
// }
// --------------------------------------------------------------------------------------------
// class Base
// {
// protected:
//     int x;
//     virtual void fun() = 0;
//     Base(int i)
//     {
//         x = i;
//         cout << "Constructor of base called!" << endl;
//     }
// };
// class Derived : public Base
// {
//     int y;

// public:
//     Derived(int i, int j) : Base(i) { y = j; };
//     virtual void fun()
//     {
//         cout << "x : " << x << " ,  y : " << y << endl;
//     }
// };
// int main()
// {
//     Derived d(4, 5);
//     d.fun();
// }

//---------------------------------Pure Virtual Function-----------------------
// class Base
// {
//     int x;

// public:
//     virtual void fun() = 0;
//     int getX() { return x; }
// };
// class Derived : public Base
// {
//     int y;

// public:
//     virtual void fun()
//     {
//         cout << "Fun() called!" << endl;
//     }
// };
// int main()
// {
//     // Derived d;
//     // d.fun();
//     //-------------
//     Base *basePtr;
//     Derived derived;
//     basePtr = &derived;
//     basePtr->fun();
// }

//--------------------------Virtual Function--------------------
// class GFG_Base
// {
// public:
//     virtual void display()
//     {
//         cout << "Called virtual Base Class function" << endl;
//     }
//     void print()
//     {
//         cout << "Called GFG_Base print function" << endl;
//     }
// };
// class GFG_Child : public GFG_Base
// {
// public:
//     virtual void display()
//     {
//         cout << "Called GFG_Child Display Function" << endl;
//     }
//     void print()
//     {
//         cout << "Called GFG_Child print Function" << endl;
//     }
// };

// int main()
// {
//     GFG_Base *base;
//     GFG_Child child;
//     base = &child;
//     base->display();
//     base->GFG_Base::display();
//     base->print();
// }

//------------------------------------------------------------1023. Camelcase Matching-------------------------------------------------------
// int main()
// {
//     // vector<string> queries = {"FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"};
//     // vector<string> queries = {"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"};
//     vector<string> queries = {"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"};
//     string pattern = "FoBaT";
//     vector<bool> answer;
//     int query_index = 0;
//     while (query_index < queries.size())
//     {
//         string current_string = queries[query_index];
//         int pattern_index = 0;
//         int flage = 1;
//         int current_string_index = 0;
//         while (current_string_index < current_string.size())
//         {
//             if (current_string[current_string_index] == pattern[pattern_index])
//             {
//                 current_string_index++;
//                 pattern_index++;
//             }
//             else if (current_string[current_string_index] <= 90)
//             {
//                 flage = 0;
//                 break;
//             }
//             else
//             {
//                 current_string_index++;
//             }
//         }
//         if(flage == 1 &&  pattern_index >= pattern.size())
//             answer.push_back(true);
//         else
//             answer.push_back(false);
//         query_index++;
//     }
//     for(auto item : answer)
//         cout << item << "  ";
// }
//---------------------------------------------
// int main()
// {
//     // vector<string> queries = {"FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"};
//     vector<string> queries = {"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"};
//     // vector<string> queries = {"FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"};
//     string pattern = "FoBa";
//     int n = queries.size();
//     vector<bool> answer(n, false);
//     for (int queries_index = 0; queries_index < n; queries_index++)
//     {
//         int current_string_index = 0;
//         int pattern_index = 0;
//         for (current_string_index; current_string_index < queries[queries_index].size(); current_string_index++)
//         {
//             if (queries[queries_index][current_string_index] == pattern[pattern_index])
//                 pattern_index++;
//             else if (queries[queries_index][current_string_index] <= 90)
//                 break;
//         }
//         cout << current_string_index << "  :  " << pattern_index << endl;
//         if (current_string_index == queries[queries_index].size() && pattern_index == pattern.size())
//             answer[queries_index] = true;
//     }
//     for (auto item : answer)
//         cout << item << "  ";
// }
//-----------------------------------------------------------169. Majority Element-----------------------------------------------------------
// int main()
// {
//     vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
//     int n = nums.size();
//     unordered_map<int, int> un_mp;
//     for (auto item : nums)
//         un_mp[item]++;
//     unordered_map<int, int>::iterator itr = un_mp.begin();
//     for (; itr != un_mp.end(); itr++)
//     {
//         if (itr->second > n / 2)
//         {
//             break;
//         }
//     }
//     cout << itr->first;
// }
//----------------------------------------------
// int main()
// {
//     vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
//     int n = nums.size();
//     sort(nums.begin(), nums.end());
//     int current_counter = 1, element = nums[0];
//     for (int i = 0; i < nums.size()-1; i++)
//     {
//         if (nums[i] == nums[i + 1])
//         {
//             current_counter++;
//         }
//         else if (current_counter > n / 2)
//         {
//             break;
//         }
//         else
//         {
//             current_counter = 1;
//             element = nums[i+1];
//         }
//     }
//     cout << element << endl;
// }
//-----------------------------------------------------
// int main()
// {
//     vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
//     sort(nums.begin(), nums.end());
//     int mid = (0+nums.size())/2;
//     cout << nums[mid] << endl;
// }
//----------Boyer-Moore Majority Voting Algorithm------------
// int main()
// {
//     // vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
//     vector<int> nums = {4, 7, 4, 4, 7, 4, 4, 9, 4, 3};
//     int n = nums.size();
//     int majority_element = nums[0];
//     int counter = 1;
//     for (int i = 1; i < n; i++)
//     {
//         if (nums[i] == majority_element)
//             counter++;
//         else
//         {
//             counter--;
//             if (counter == 0)
//             {
//                 majority_element = nums[i];
//                 counter = 1;
//             }
//         }
//     }
//     cout << majority_element << counter << endl;
// }
//------------------------------------------------ 33. Search in Rotated Sorted Array --------------------------------------------------
// int main()
// {
// vector<int> nums = {4,5,6,7,0,1,2};
// int target = 3;
//     int start = 0, end = nums.size() - 1;
//     while (start <= end)
//     {
//         if (nums[start] == target)
//         {
//             cout << start << endl;
//             break;
//         }
//         if (nums[end] == target)
//         {
//             cout << end << endl;
//             break;
//         }
//         if (nums[start] != target)
//             start++;
//         if (nums[end] != target)
//             end--;
//     }
//     if(start > end)
//         cout << -1 << endl;
// }
//-----------------------------------------
// int search(vector<int> &nums, int target)
// {
//     int start = 0, end = nums.size() - 1;
//     while (start <= end)
//     {
//         int mid = start + (end - start) / 2;
//         // int mid = (start+end)/2;
//         if (nums[mid] == target)
//             return mid;
//         else if (nums[start] > target && nums[mid] >= nums[start])
//             start = mid + 1;
//         else if (nums[end] < target && nums[mid] <= nums[end])
//             end = mid - 1;
//         else if (nums[mid] > target)
//             end = mid - 1;
//         else if (nums[mid] < target)
//             start = mid + 1;
//     }
//     return -1;
// }
// int main()
// {
//     // vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
//     // vector<int> nums = {3, 1};
//     vector<int> nums = {6, 7, 8, 0, 1, 2, 3, 4, 5, 6};
//     int target = 0;
//     cout << search(nums, target) << endl;
// }
//---------------------------------------------34. Find First and Last Position of Element in Sorted Array------------------------------------
// vector<int> searchRange(vector<int> &nums, int target)
// {
//     int i = 0;
//     int j = nums.size() - 1;
//     int start_index = -1, end_index = -1;
//     while ((i < nums.size()) && (j > -1))
//     {
//         if (start_index == -1 && nums[i] == target)
//             start_index = i;
//         else
//             i++;
//         if (end_index == -1 && nums[j] == target)
//             end_index = j;
//         else
//             j--;
//         if (start_index != -1 && end_index != -1)
//             break;
//     }
//     return {start_index, end_index};
// }
//-------------------------------------------
// vector<int> searchRange(vector<int> &nums, int target)
// {
//     int start_index = -1, end_index = -1;
//     int start = 0, end = nums.size() - 1;
//     while (start <= end)
//     {
//         // int mid = (start + end) / 2;
//         int mid = start + (end - start) / 2;
//         if (nums[mid] > target)
//             end = mid - 1;
//         if (nums[mid] < target)
//             start = mid + 1;
//         if (nums[mid] == target)
//         {
//             start_index = mid;
//             end = mid - 1;
//         }
//     }
//     if(start_index == -1)
//         return {start_index, end_index};
//     start = 0, end = nums.size() - 1;
//     while (start <= end)
//     {
//         // int mid = (start + end) / 2;
//         int mid = start + (end - start) / 2;
//         if (nums[mid] > target)
//             end = mid - 1;
//         if (nums[mid] < target)
//             start = mid + 1;
//         if (nums[mid] == target)
//         {
//             end_index = mid;
//             start = mid + 1;
//         }
//     }
//     // cout << start_index << endl;
//     // cout << end_index << endl;
//     return {start_index, end_index};
// }
//----------------------------------------
// vector<int> searchRange(vector<int> &nums, int target)
// {
//     int start_index = -1, end_index = -1;
//     int start = 0, end = nums.size() - 1;
//     while (start <= end)
//     {
//         if(nums[start] == target && nums[end] == target){
//             start_index = start;
//             end_index = end;
//             break;
//         }
//         if(nums[start] != target)
//             start++;
//         if(nums[end] != target)
//             end--;
//     }
//     return {start_index, end_index};
// }

// int main()
// {
//     vector<int> nums = {1, 3, 5, 5, 5, 5, 67, 123, 125};
//     // vector<int> nums = {1, 2, 3};
//     nums = searchRange(nums, 5);
//     for (auto item : nums)
//         cout << item << "  ";
// }
//---------------------------------------------------
// int searchIndex(vector<int> &nums, int target, bool findFirst = true)
// {
//     int index = -1, start = 0, end = nums.size() - 1;
//     while (start <= end)
//     {
//         // int mid = (start + end) / 2;
//         int mid = start + (end - start) / 2;
//         if (nums[mid] > target)
//             end = mid - 1;
//         if (nums[mid] < target)
//             start = mid + 1;
//         if (nums[mid] == target)
//         {
//             index = mid;
//             if (findFirst)
//                 end = mid - 1;
//             else
//                 start = mid + 1;
//         }
//     }
//     return index;
// }
// int main()
// {
//     vector<int> nums = {1, 3, 5, 5, 5, 5, 67, 123, 125};
//     // vector<int> nums = {1, 2, 3};
//     vector<int> result(2, -1);
//     int index = searchIndex(nums, 5);
//     if (index == -1)
//     {
//         for (auto item : result)
//             cout << item << "  ";
//     }
//     else
//     {
//         result[0] = index;
//         index = searchIndex(nums, 5, false);
//         result[1] = index;
//         for (auto item : result)
//             cout << item << "  ";
//     }
// }
//-----------------------------------------------
// int searchIndex(vector<int> &nums, int target, bool findFirst = true)
// {
//     int index = -1, start = 0, end = nums.size() - 1;
//     while (start <= end)
//     {
//         // int mid = (start + end) / 2;
//         int mid = start + (end - start) / 2;
//         if (nums[mid] > target)
//             end = mid - 1;
//         if (nums[mid] < target)
//             start = mid + 1;
//         if (nums[mid] == target)
//         {
//             index = mid;
//             if (findFirst)
//                 end = mid - 1;
//             else
//                 start = mid + 1;
//         }
//     }
//     return index;
// }
// int main()
// {
//     // vector<int> nums = {1, 3, 5, 5, 5, 5, 67, 123, 125};
//     vector<int> nums = {1, 2, 3};
//     vector<int> result(2, -1);
//     int target = 5;
//     int index = searchIndex(nums, target);
//     if (index == -1)
//         cout << "0 times the " << target << " is appearing.";
//     else
//     {
//         result[0] = index;
//         index = searchIndex(nums, target, false);
//         result[1] = index;
//         cout << (result[1]-result[0]) + 1 << " times the " << target << " is appearing.";
//     }
// }
// -------------------------------------------------------------------------------------------------------------------------------------------
// int main()
// {
//     int arr[] = {8, 5, 2, 1, 7, 3, 4};
// int arr[] = {6, 6, 3, 2, 1, 1, 5, 6, 4, 3, 5, 8, 5, 2, 2, 1, 7, 7, 3, 4, 4, 8, 8};
// int n = sizeof(arr) / sizeof(arr[0]);
// int pivot = arr[n - 1];
// int small_element_counter = 0;
// for (int i = 0; i < n; i++)
//     if (arr[i] < pivot)
//         small_element_counter++;
// int temp = arr[n - 1];
// arr[n - 1] = arr[0 + small_element_counter];
// arr[0 + small_element_counter] = temp;
// int i = 0;
// int j = n - 1;
// while (i <= small_element_counter && j >= small_element_counter)
// {
//     if (arr[i] < pivot)
//         i++;
//     else if (arr[j] >= pivot)
//         j--;
//     else if (arr[j] < pivot && arr[i] >= pivot)
//     {
//         int temp = arr[i];
//         arr[i] = arr[j];
//         arr[j] = temp;
//         i++;
//         j--;
//     }
//     else if (arr[i] >= pivot && arr[j] < pivot)
//     {
//         int temp = arr[i];
//         arr[i] = arr[j];
//         arr[j] = temp;
//         i++;
//         j--;
//     }
// }
//     for (auto item : arr)
//         cout << item << "  ";
//     cout << endl << "small_element_counter : " << small_element_counter << endl;
// }

//---------------------------------------------------------------------------------------------------------
// vector<int> countingSort(vector<int> arr)
// {
//     int maxElement = *max_element(arr.begin(), arr.end());
//     vector<int> indexer(maxElement + 1, 0);
//     vector<int> result;
//     // cout << indexer.size();
//     for (auto item : arr)
//         indexer[item]++;
//     int i = 0;
//     while (i < indexer.size())
//     {
//         if (indexer[i] == 0)
//             i++;
//         else
//         {
//             result.push_back(i);
//             indexer[i]--;
//         }
//     }
//     cout << "Index array size : " << indexer.size() << endl;
//     return result;
// }
// int main()
// {
//     vector<int> vect = {63, 54, 17, 78, 43, 70, 32, 97, 16, 94, 74, 18, 60, 61, 35, 83, 13, 56, 75, 52, 70, 12, 24, 37, 17, 0, 16, 64, 34, 81, 82, 24, 69, 2, 30, 61, 83, 37, 97, 16, 70, 53, 0, 61, 12, 17, 97, 67, 33, 30, 49, 70, 11, 40, 67, 94, 84, 60, 35, 58, 19, 81, 16, 14, 68, 46, 42, 81, 75, 87, 13, 84, 33, 34, 14, 96, 7, 59, 17, 98, 79, 47, 71, 75, 8, 27, 73, 66, 64, 12, 29, 35, 80, 78, 80, 6, 5, 24, 49, 82,};
//     int n = vect.size();
//     // cout << n << endl;
//     vect = countingSort(vect);
//     for(auto item : vect)
//         cout << item << "  ";
// }
//--------------------------------------------------------------------------------------------------------------------------------------------------
// int main()
// {
// int arr[] = {8, 2, 4, 8, 4, 7, 3, 4};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int high = n - 1;
//     int pivot = arr[high]; // pivot
//     int low = 0;
//     int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
//     for (int j = low; j <= high - 1; j++)
//     {
//         // If current element is smaller than the pivot
//         if (arr[j] < pivot)
//         {
//             i++;// increment index of smaller element
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i + 1], arr[high]);
//     for (auto item : arr)
//         cout << item << "  ";
// }
//--------------------------------------------------------------------------------------------------------------------------------------------------
// int main()
// {
//     int arr[] = {1, 3, 7, 2, 5, 6};
//     int x[] = {1, 3, 7};
//     int y[] = {0, 0, 0, 2, 5, 6};
//     int start = 0, end = 5;
//     int mid = (start + end) / 2;
//     int i = start;
//     int j = mid + 1;
//     int index = 0;
//     while (i <= mid || j <= end)
//     {
//         if (x[i] < y[j])
//         {
//             arr[index++] = x[i++];
//         }
//         else
//         {
//             arr[index++] = y[j++];
//         }
//     }
//     if(i > mid)
//         arr[index] = y[j];
//     else
//         arr[index] = x[i];
//     for(auto item : arr)
//         cout << item << "  ";
// }
//--------------------------------------------------------------- Tower Of Hanoi -------------------------------------------------------------------
//------Number of steps to transfer disk from source to destination-----------
// int toh(int n)
// {
//     if(n == 0)
//         return 0;
//     return toh(n-1)+1+toh(n-1);
// }
// int main()
// {
//         cout << toh(2) << endl;
// }
//------Print the steps to transfer disk from source to destination-----------
// void printSteps(int n, char source, char helper, char destination)
// {
//     if (n == 0)
//         return;
//     printSteps(n-1, source, destination, helper);
//     cout << source << " -> " << destination << endl;
//     printSteps(n-1, helper, source, destination);
// }
// int main()
// {
//     printSteps(4, 'A', 'B', 'C');
// }
//-------------------------
// void printSteps(int n, char source, char destination, char helper)
// {
//     if (n == 0)
//         return;
//     printSteps(n-1, source, helper, destination);
//     cout << "Moving disk " << n << " from " << source << " -> " << destination << endl;
//     printSteps(n-1, helper, destination, source);
// }
// int main()
// {
//     printSteps(4, 'A', 'C', 'B');
// }
//-------------------------------------------------------------------Staircase Problem--------------------------------------------------------------
//--------------------------------------------------------Number of ways to reach N from 0----------------------------------------------------------
// int staircaseProblem(int num)
// {
//     if (num == 0 || num == 1)
//         return 1;
//     if (num == 2)
//         return 2;
//     int small_answer = staircaseProblem(num-1);
//     small_answer += staircaseProblem(num-2);
//     small_answer += staircaseProblem(num-3);
//     return small_answer;
// }
//---------------------------------
// int staircaseProblem(int num)
// {
//     if (num == 0 || num == 1)
//         return 1;
//     if (num == 2)
//         return 2;
//     return  staircaseProblem(num-1)+staircaseProblem(num-2)+staircaseProblem(num-3);
// }
//--------------------------------
// int staircaseProblem(int num)
// {
//     if (num == 0 || num == 1)
//         return 1;
//     if (num < 0)
//         return 0;
//     return  staircaseProblem(num-1)+staircaseProblem(num-2)+staircaseProblem(num-3);
// }
// int main()
// {
//     cout << staircaseProblem(6);
// }
//-----------------------------------------------------------Print All The Permutations Of A String--------------------------------------------------------------
// void printAllPermutation(char input[], int i = 0)
// {
//     if (input[i] == '\0')
//     {
//         cout << input << "  ";
//         return;
//     }
//     for (int j = i; input[j] != '\0'; j++)
//     {
//         swap(input[i], input[j]);
//         printAllPermutation(input, i + 1);
//         swap(input[i], input[j]);
//     }
// }
// int main()
// {
//     char input[] = "ABC";
//     printAllPermutation(input);
// }
//----------------------------------
// void printAllPermutation(string input, int i = 0)
// {
//     if (input[i] == '\0')
//     {
//         cout << input << "  ";
//         return;
//     }
//     for (int j = i; input[j] != '\0'; j++)
//     {
//         swap(input[i], input[j]);
//         printAllPermutation(input, i + 1);
//         swap(input[i], input[j]);
//     }
// }
// int main()
// {
//     string input = "ABC";
//     printAllPermutation(input);
// }
//-----------------------------------------------------------Convert String To Integer--------------------------------------------------------------
// int stringToInt(string input, int &output)
// {
//     // Base Case
//     if (input.size() == 0)
//         return output;
//     else
//     {
//         output = output * 10 + (input[0] - 48);
//     }
//     // Recursive Case
//     int small_answer = stringToInt(input.substr(1), output);
//     // Calculation
//     return small_answer;
// }
// int main()
// {
//     string input = "12345";
//     int output = 0;
//     cout << stringToInt(input, output);
// }
//----------------------------------
// int stringToInt(string input, int n)
// {
//     // Base Case
//     if (n == 0)
//         return 0;
//     // Recursive Case
//     int small_answer = stringToInt(input, n - 1);
//     // Calculation
//     int lastDigit = (input[n - 1] - 48);
//     int ans = small_answer * 10 + lastDigit;
//     return ans;
// }
// int main()
// {
//     char input[] = "12345";
//     int n = sizeof(input) / sizeof(input[0]);
//     // cout << n << endl;
//     cout << stringToInt(input, n - 1) << endl;
//     // cout << int('\0') << endl;
// }
//-----------------------------------
// int stringToInt(char input[])
// {
//     // Base Case
//     if (input[0] == '\0')
//         return 0;
//     // Recursive Case
//     int small_answer = stringToInt(input + 1);
//     // Calculation
//     int last_digit = input[0] - 48;
//     cout << last_digit*10 + small_answer << endl;
//     int ans = last_digit*10 + small_answer;
//     return ans;
// }
// int main()
// {
//     char input[] = "12345";
//     cout << stringToInt(input) << endl;
// }
//-----------------------------------------------------------Store All Subsecqunces Of A String--------------------------------------------------------------
// void storeAllSubsequences(string input, string output, vector<string> &result)
// {
//     if (input.size() == 0)
//     {
//         result.push_back(output);
//         // cout << output << endl;
//         return;
//     }
//     storeAllSubsequences(input.substr(1), output, result);            // Excluding
//     storeAllSubsequences(input.substr(1), output + input[0], result); // Including
// }
// int main()
// {
//     string input = "ABC";
//     vector<string> result;
//     string output = " ";
//     storeAllSubsequences(input, output, result);
//     for(auto item:result)
//         cout << item << "  ";
//     // cout << input.substr(1, 1);
// }
//-----------------------------------------------------------Print All Subsecqunces Of A String--------------------------------------------------------------
// void printAllSubsequences(string input, string output)
// {
//     if (input.size() == 0)
//     {
//         cout << output << endl;
//         return;
//     }
//     printAllSubsequences(input.substr(1), output);            // Excluding
//     printAllSubsequences(input.substr(1), output + input[0]); // Including
// }
// int main()
// {
//     string input = "ABC";
//     string output = " ";
//     printAllSubsequences(input, output);
//     // cout << input.substr(1, 1);
// }
//-------------------------------------------
// void printAllSubsequences(char input[], char output[], int index)
// {
//     if (input[0] == '\0')
//     {
//         output[index] = '\0';
//         cout << output << endl;
//         return;
//     }
//     printAllSubsequences(input + 1, output, index); // Excluding
//     output[index] = input[0];
//     printAllSubsequences(input + 1, output, index + 1); // Including
// }
// int main()
// {
//     char input[] = "ABC";
//     char output[10];
//     printAllSubsequences(input, output, 0);
//     // cout << input.substr(1, 1);
// }
//-----------------------------------------------------------Remove Consecutive Duplicates--------------------------------------------------------------
// int main()
// {
//     char input[] = "aabbbcdda";
//     int i, j;
//     for (i = 0; input[i] != '\0'; i++)
//     {
//         int k = 1;
//         for (j = i + 1; input[j] == input[i]; j++)
//         {
//         }
//         for (int l = j; input[l] != '\0'; l++)
//         {
//             input[i + k] = input[l];
//             k++;
//         }
//         input[i + k] = '\0';
//     }
//     cout << input << endl;
// }
//------------------------------------
// void removeConsecutiveDuplicate(char input[])
// {
//     if (input[0] == '\0')
//         return;
//     if (input[0] == input[1])
//     {
//         for (int i = 1; input[i] != '\0'; i++)
//             input[i] = input[i + 1];
//         removeConsecutiveDuplicate(input);
//         cout << input << endl;
//     }
//     else
//         removeConsecutiveDuplicate(input+1);
// }
//----------------------------------------
// void removeConsecutiveDuplicate(char input[])
// {
//     if (input[0] == '\0')
//         return;
//     if (input[0] == input[1])
//     {
//         int k = 1, i, j;
//         for (i = 1; input[i] == input[0]; i++)
//         {
//         }
//         for (j = i; input[j] != '\0'; j++)
//         {
//             input[k] = input[j];
//             k++;
//         }
//         input[k] = '\0';
//         removeConsecutiveDuplicate(input);
//     }
//     else
//         removeConsecutiveDuplicate(input + 1);
// }
// int main()
// {
//     char input[] = "aaaaaaaaaaaaabbbcccccccccccccccccccccccccccccccddaaaaaaaa";
//     removeConsecutiveDuplicate(input);
//     cout << input << endl;
// }
//-----------------------------------------------------------Remove Character--------------------------------------------------------------
// void removeCharacter(char str[], char removeItem, int left, int right)
// {
//     // Base Case
//     if (str[right] == '\0')
//     {
//         str[left] = '\0';
//         return;
//     }
//     if (str[left] != removeItem)
//     {
//         left++;
//     }
//     if (str[right] == removeItem)
//     {
//         right++;
//     }
//     if (str[left] == removeItem && str[right] != removeItem)
//     {
//         char temp = str[left];
//         str[left++] = str[right];
//         str[right++] = temp;
//     }
//     // Recursive Case
//     // Calculation
//     removeCharacter(str, removeItem, left, right);
// }
// int main()
// {
//     // char str[] = "abcdabef";
//     char str[] = "aaaabaaaaa";
//     char removeItem = 'a';
//     removeCharacter(str, removeItem, 0, 0);
//     // int n = sizeof(str)/sizeof(str[0]);
//     // cout << n << endl;
//     cout << str << endl;
// }
//-----------------------------------------------------------Replace the character--------------------------------------------------------------
// void replaceCharacter(char str[], char targetValue, char replaceValue)
// {
//     // Base Case
//     if (str[0] == '\0')
//         return;
//     // Recursive Case
//     if (str[0] == targetValue)
//         str[0] = replaceValue;
//     // Calculation
//     replaceCharacter(str + 1, targetValue, replaceValue);
// }
// int main()
// {
//     char str[] = "abcdab";
//     char targetValue = 'a';
//     char replaceValue = 'x';
//     replaceCharacter(str, targetValue, replaceValue);
//     for (auto item : str)
//         cout << item << "  ";
// }
//-----------------------------------------------------------Find the lenght of the String--------------------------------------------------------------
// int stringLength(char str[])
// {
//     // Base Case
//     if(str[0] == '\0')
//         return 0;
//     // RecursiveCase
//     int small_answer = stringLength(str+1);
//     // Calculation
//     return 1+small_answer;
// }
//----------------------------------
// int stringLength(char str[])
// {
//     // Base Case
//     if(str[0] == '\0')
//         return 0;
//     // RecursiveCase
//     int small_answer = stringLength(str+1);
//     // Calculation
//     return 1+small_answer;
// }
// int main()
// {
//     char str[] = "abcdef";
//     cout << "Length of the given string : " << stringLength(str) << endl;
// }
//-----------------------------------------------------------Print And Reverse Print--------------------------------------------------------------
// void printArray(char str[])
// {
//     // Base Case
//     if (str[0] == '\0')
//         return;
//     cout << str[0] << "  ";
//     // Recursive Case
//     // Calculation
//     printArray(str + 1);
//     // cout << str[0] << "  ";
// }
//-----------------------------
// void reversePrintArray(char str[])
// {
//     // Base Case
//     if (str[0] == '\0')
//         return;
//     // cout << str[0] << "  ";
//     // Recursive Case
//     // Calculation
//     reversePrintArray(str + 1);
//     cout << str[0] << "  ";
// }
//-------------------------------
// void printArray(char str[], int n)
// {
//     // Base Case
//     if (n == 0)
//         return;
//     // cout << str[n - 1] << "  ";
//     // Recursive Case
//     // Calculation
//     printArray(str, n-1);
//     cout << str[n-1] << "  ";
// }
// int main()
// {
//     char str[] = "abcde";
//     int n = sizeof(str) / sizeof(str[0]);
//     cout << n << endl;
//     printArray(str, n - 1);
// }
//-----------------------------------------------------------Checking Palindrome--------------------------------------------------------------
// bool checkPalindrome(int arr[], int start, int end)
// {
//     // Base Case
//     if (arr[start] != arr[end])
//         return false;
//     if (start > end)
//         return true;
//     // Recursive Case
//     int small_answer = checkPalindrome(arr, start + 1, end - 1);
//     // Calculation
//     return small_answer;
// }
// int main()
// {
//     int arr[] = {1, 2, 3, 4, 3, 2, 1};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     cout << checkPalindrome(arr, 0, n - 1);
// }
//-----------------------------------------------------------Store all potion of an array element--------------------------------------------------------------
// void storeAllPosition(int arr[], int n, int element, vector<int> &result)
// {
//     // Base Case
//     if (n == 0)
//         return;
//     // if(arr[n-1] == element)
//     //     result.push_back(n-1);
//     // Recursive Case
//     // Calculation
//     storeAllPosition(arr, n - 1, element, result);
//     if (arr[n - 1] == element)
//         result.push_back(n - 1);
// }//-------------------------------
// void storeAllPosition(int arr[], int n, int element, vector<int> &result, int index)
// {
//     // Base Case
//     if (index == n)
//         return;
//     if (arr[index] == element)
//         result.push_back(index);
//     storeAllPosition(arr, n, element, result, index + 1);
//     // if (arr[index] == element)
//     //     result.push_back(index);
// }
//-------------------------------------
// void storeAllPosition(int arr[], int n, int element, int result[], int index, int &j)
// {
//     // Base Case
//     if (index == n)
//         return;
//     if (arr[index] == element)
//         result[j++] = index;
//     storeAllPosition(arr, n, element, result, index + 1, j);
// }
// int main()
// {
//     int arr[] = {5, 5, 6, 5, 6, 7};
//     // vector<int> result;
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int result[n];
//     int j = 0;
//     storeAllPosition(arr, n, 5, result, 0, j);
//     // for (auto item : result)
//     //     cout << item << "  ";
//     for(int i = 0; i < j; i++)
//         cout << result[i] << "  ";
// }
//-----------------------------------------------------------Count occurence of element present in array--------------------------------------------------------------
// int occurenceOfElement(int arr[], int n, int element)
// {
//     // Base Case
//     if (n == 0)
//         return 0;
//     // Recursive Case
//     int small_answer = occurenceOfElement(arr + 1, n - 1, element);
//     // Calculation
//     if (arr[0] == element)
//         return 1 + small_answer;
//     return small_answer;
// }
//-----------------------------------
// int occurenceOfElement(int arr[], int n, int element)
// {
//     // Base Case
//     if (n == 0)
//         return 0;
//     // Recursive Case
//     int small_answer = occurenceOfElement(arr, n - 1, element);
//     // Calculation
//     if (arr[n-1] == element)
//         return 1 + small_answer;
//     return small_answer;
// }
//------------------------------------
// int occurenceOfElement(int arr[], int n, int element, int answer)
// {
//     // Base Case
//     if (n == 0)
//         return answer;
//     // Calculation
//     if (arr[n - 1] == element)
//         answer++;
//     // Recursive Case
//     int small_answer = occurenceOfElement(arr, n - 1, element, answer);
//     return small_answer;
// }
//------------------------------------
// int occurenceOfElement(int arr[], int n, int element)
// {
//     // Base Case
//     if (n == 0)
//         return 0;
//     // Recursive Case
//     int small_answer = occurenceOfElement(arr, n - 1, element);
//     // Calculation
//     if (arr[n - 1] == element)
//         small_answer++;
//     return small_answer;
// }
// int main()
// {
//     int arr[] = {5, 5,  6, 5,};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     cout << occurenceOfElement(arr, n, 6) << endl;
// }
//-----------------------------------------------------------Print all position of element present in array--------------------------------------------------------------
// void printAllIndex(int arr[], int n, int element, int index)
// {
//     // Base Case
//     if (index == n)
//         return;
//     // printAllIndex(arr, n, element, index + 1);
//     if (arr[index] == element)
//         cout << index << "  ";
//     // Recursive Case
//     // Calculation
//     printAllIndex(arr, n, element, index + 1);
// }
//-------------------------------------
// void printAllIndex(int arr[], int n, int element)
// {
//     // Base Case
//     if (n == 0)
//         return;
//     printAllIndex(arr, n - 1, element);
//     if (arr[n - 1] == element)
//         cout << n - 1 << "  ";
//     // Recursive Case
//     // Calculation
//     // printAllIndex(arr, n-1, element);
// }
// int main()
// {
// int arr[] = {2, 4, 5, 6, 7, 5, 4, 2};
// int n = sizeof(arr) / sizeof(arr[0]);
// printAllIndex(arr, n, 2);
// }
//-----------------------------------------------------------Return last index of element present in array--------------------------------------------------------------
// int returnLastIndex(int arr[], int n, int element)
// {
//     // Base Case
//     if (n == 0)
//         return -1;
//     if (arr[n - 1] == element)
//         return n - 1;
//     // Recursive Case
//     int small_answer = returnLastIndex(arr, n - 1, element);
//     // Calculation
//     return small_answer;
// }
//----------------------------------------------
// int returnLastIndex(int arr[], int n, int element, int index)
// {
//     // Base Case
//     if (index == -1)
//         return -1;
//     if (arr[index] == element)
//         return index;
//     // Recursive Case
//     int small_answer = returnLastIndex(arr, n, element, index -1);
//     // Calculation
//     return small_answer;
// }
//----------------Iterating from left to right----------------------------
// int returnLastIndex(int arr[], int n, int element)
// {
//     // Base Case
//     if (n == 0)
//         return -1;
//     if (arr[0] == element)
//         return 0;
//     // Recursive Case
//     int fisrtSmallAnswer = returnLastIndex(arr + 1, n - 1, element);
//     // Calculation
//     int secondSmallAnswer = -2;
//     if (fisrtSmallAnswer > -1)
//         secondSmallAnswer = returnLastIndex(arr + 2, n - 2, element);
//     if (secondSmallAnswer > -1)
//         return secondSmallAnswer + 1;
//     if(fisrtSmallAnswer > -1)
//         return fisrtSmallAnswer+1;
//     return fisrtSmallAnswer;
// }
// int main()
// {
//     int arr[] = {2, 5, 6, 5, 2};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     cout << returnLastIndex(arr, n, 5) << endl;
// }
//-----------------------------------------------------------Return first index of element present in array--------------------------------------------------------------
// int returnFirstIndex(int arr[], int n, int element)
// {
//     // Base Case
//     if (n == 0)
//         return -1;
//     if (arr[0] == element)
//         return 0;
//     // Recursive Case
//     int small_answer = returnFirstIndex(arr + 1, n - 1, element);
//     // Calculation
//     if(small_answer > -1)
//         return 1+small_answer;
//     return small_answer;
// }
//-------------------------------------------
// int returnFirstIndex(int arr[], int n, int element, int index)
// {
//     // Base Case
//     if (index == n)
//         return -1;
//     if (arr[index] == element)
//         return index;
//     // Recursive Case
//     int small_answer = returnFirstIndex(arr, n, element, index + 1);
//     // Calculation
//     return small_answer;
// }
// int main()
// {
// int arr[] = {2, 4, 5, 6, 7, 5, 4, 2};
// int n = sizeof(arr) / sizeof(arr[0]);
// cout << returnFirstIndex(arr, n, 5, 8) << endl;
// }
//-----------------------------------------------------------Check if element present in array--------------------------------------------------------------
// bool elementPresent(int arr[], int n, int element){
//     // Base Case
//     if(n == 0)
//         return false;
//     if(arr[n-1] == element)
//         return true;
//     // Recursive Case
//     int small_answer = elementPresent(arr, n-1, element);
//     // Calculation
//     return small_answer;
// }
//---------------------------------------------------
// bool elementPresent(int arr[], int n, int element)
// {
//     // Base Case
//     if (n == 0)
//         return false;
//     if (arr[0] == element)
//         return true;
//     // Recursive Case
//     int small_answer = elementPresent(arr + 1, n - 1, element);
//     // Calculation
//     return small_answer;
// }
//---------------------------------------------------
// bool elementPresent(int arr[], int n, int element)
// {
//     // Base Case
//     if (n == 0)
//         return false;
//     if (arr[0] == element)
//         return true;
//     // Recursive Case
//     int small_answer = elementPresent(arr + 1, n - 1, element);
//     // Calculation
//     return small_answer;
// }
//--------------------------------------------------
// bool elementPresent(int arr[], int n, int element)
// {
//     // Base Case
//     if (n == 0)
//         return false;
//     // Recursive Case
//     bool small_answer = elementPresent(arr + 1, n - 1, element);
//     if (!small_answer)
//         if (arr[0] == element)
//             return true;
//     // Calculation
//     return small_answer;
// }
//----------------------------------------------------
// bool elementPresent(int arr[], int n, int element, int index)
// {
//     // Base Case
//     if (index == n)
//         return false;
//     if (arr[index] == element)
//         return true;
//     // Recursive Case
//     bool small_answer = elementPresent(arr, n, element, index + 1);
//     // Calculation
//     return small_answer;
// }
// int main()
// {
//     int arr[] = {2, 4, 6, 8, 10};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     cout << elementPresent(arr, n, 12, 0);
// }
//-----------------------------------------------------------Sum of the array elements--------------------------------------------------------------
// int sumOfElements(int arr[], int n)
// {
//     // Base Case
//     if (n == 1)
//         return arr[0];
//     // Recursive Case
//     int small_answer = sumOfElements(arr + 1, n - 1);
//     // Calculation
//     return arr[0] + small_answer;
// }
//-------------------------------------------------
// int sumOfElements(int arr[], int index, int n)
// {
//     // Base Case
//     if (index == n)
//         return 0;
//     // Recursive Case
//     int small_answer = sumOfElements(arr, index+1, n);
//     // Calculation
//     return arr[index] + small_answer;
// }
//-------------------------------------------------
// int sumOfElements(int arr[], int n)
// {
//     // Base Case
//     if (n == 1)
//         return arr[n-1];
//     // Recursive Case
//     int small_answer = sumOfElements(arr, n - 1);
//     // Calculation
//     return arr[n-1] + small_answer;
// }
// int main()
// {
//     int arr[] = {2, 4, 6, 8, 10};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     cout << sumOfElements(arr, 0, n);
// }
//-----------------------------------------------------------Check If A Array Is Sorted Or Not--------------------------------------------------------------
// bool isArraySorted(int arr[], int n)
// {
//     // Base Case
//     if (n == 0 || n == 1)
//         return true;
//     if (arr[0] > arr[1])
//         return false;
//     // Recursive Case
//     bool isSmallerSorted = isArraySorted(arr + 1, n - 1);
//     // if (small_answer)
//     //     return true;
//     // else
//     //     return false
//     return isSmallerSorted;
// }
//---------------------------------------
// int isArraySorted(vector<int> arr, int i)
// {
//     // Base Case
//     i -= 2;
//     if (i >= 0 && arr[i] > arr[i + 1])
//     {
//         return -1;
//     }
//     if (i == 0)
//         return 1;
//     // Recursive Case
//     int small_answer = isArraySorted(arr, i - 1);
//     // Calculation
//     return 1 * small_answer;
// }
//---------------------------------------
// bool isArraySorted(int arr[], int n)
// {
//     // Base Case
//     if (n == 0 || n == 1)
//         return true;
//     if (arr[n-2] > arr[n-1])
//         return false;
//     // Recursive Case
//     bool isSmallerSorted = isArraySorted(arr, n - 1);
//     // if (small_answer)
//     //     return true;
//     // else
//     //     return false
//     return isSmallerSorted;
// }
// int main()
// {
//     int arr[] = {3, 4, 6, 8, 10};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     cout << isArraySorted(arr, n);
// }
//-----------------------------------------------------------Geomatric Sum--------------------------------------------------------------
// double geomatricSum(int k)
// {
//     // Base Case
//     if(k == 0)
//         return 1;
//     // Recursive Case
//     double small_answer = geomatricSum(k-1);
//     // Calculation
//     return small_answer + 1.0/pow(2, k);
// }

// int main()
// {
//     cout << geomatricSum(3) << endl;
// }
//-----------------------------------------------------------Count Zeroes--------------------------------------------------------------
// int countZeroes(int num)
// {
//     // Base Case
//     if (num == 0)
//         return 0;
//     // Recursive Case
//     int small_answer = countZeroes(num / 10);
//     // Calculation
//     int last_digit = num % 10;
//     if (last_digit == 0)
//         return small_answer + 1;
//     else
//         return small_answer;
// }
// int main()
// {
//     cout << countZeroes(102050) << endl;
// }
//-----------------------------------------------------------Multiplication--------------------------------------------------------------
// int multiplication(int x, int n)
// {
//     // Base Case
//     if(n == 0)
//         return 0;
//     // Recursive Case
//     int small_answer = multiplication(x, n-1);
//     // Calculation
//     return x + small_answer;
// }
// int main()
// {
//     cout << multiplication(5, 3) << endl;
// }
//-----------------------------------------------------------Sum Of Digits--------------------------------------------------------------
// int sumOfDigits(int num)
// {
//     // Base Case
//     if(num == 0)
//         return 0;
//     // Recursive Case
//     int small_answer = sumOfDigits(num/10);
//     // Calculation
//     int last_digit = (num%10);
//     return  last_digit + small_answer;
// }

// int main()
// {
//     cout << sumOfDigits(12345) << endl;
// }
//-----------------------------------------------------------Count Digits--------------------------------------------------------------
// int digitCount(int num)
// {
//     // Base Case
//     if(num < 10)
//         return 1;
//     // Recursive Case
//     int small_answer = digitCount(num/10);
//     // Calculation
//     return 1+small_answer;
// }

// int main()
// {
//     cout << digitCount(111) << endl;
// }
//-----------------------------------------------------------Print Numbers--------------------------------------------------------------
// ---------------Descending Order----------------
// void printNumbers(int num)
// {
//     // Base Case
//     if(num == 0)
//         return;
//     // Calculation
//     cout << num << "  ";
//     // Recursive Case
//     printNumbers(num-1);
// }
//-------------------Ascending Order------------
// void printNumbers(int num)
// {
//     // Base Case
//     if (num == 1)
//         cout << num << "  ";
//     else
//     {
//         // Recursive Case
//         printNumbers(num - 1);
//         // Calculation
//         cout << num << "  ";
//     }
// }

// int main()
// {
//     printNumbers(5);
// }

// void printNumbers(int num)
// {
//     if (n == num)
//         cout << n << "  ";
//     else
//     {
//         cout << n << "  ";
//         ++n;
//         printNumbers(num);
//     }
// }

// int main()
// {
//     printNumbers(5);
// }
//-----------------------------------------------------------POWER x power n--------------------------------------------------------------
// int power(int x, int n)
// {
//     // Base Case
//     if (n == 0)
//         return 1;
//     // Recursive Case
//     int small_answer = power(x, n - 1);
//     // Calculation
//     return x * small_answer;
// }

// int main()
// {
//     cout << power(5, 4) << endl;
// }
//-----------------------------------------------------------Fabonnaci Series--------------------------------------------------------------
// int fibonnaci(int num)
// {
//     // Base Case
//     if (num == 0)
//         return 0;
//     if (num == 1)
//         return 1;

//     // Recursive Case
//     int last_first = fibonnaci(num - 1);
//     int last_second = fibonnaci(num - 2);

//     // Calculation
//     return last_first + last_second;
// }

// int main()
// {
//     cout << fibonnaci(9) << endl;
// }

//-----------------------------------------------------------Factorial--------------------------------------------------------------
// int fact(int num)
// {
//     if (num == 0)
//         return 1;
//     return (num * fact(num - 1));
// }
// int fun()
// {
//     return 5;
// }
// int main()
// {
//     fun();
//     // cout << fact(5) << endl;
// }
//-----------------------------------------------------------Binary Search--------------------------------------------------------------
// int main()
// {
//     vector<int> vect = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int element_search = 1;
//     int n = vect.size();
//     int start = 0, end = n - 1, mid = 0;
//     while (start <= end)
//     {
//         // mid = (start + end) / 2;
//         mid = start + (end - start) / 2;
//         if (element_search < vect[mid])
//             end = mid - 1;
//         else if (element_search > vect[mid])
//             start = mid + 1;
//         else
//         {
//             cout << "Element found at index : " << mid << endl;
//             return 0;
//         }
//     }
//     cout << "Element not found!" << endl;
// }
//-----------------------------------------------------------Bubble Sort--------------------------------------------------------------
// int main()
// {
//     // vector<int> vect = {10, 8, 6, 4, 2};
//     // vector<int> vect = {7, 5, 3, 6, 8};
//     vector<int> vect = {2, 4, 6, 8, 10};
//     int n = vect.size();
//     int round_number = 0;
//     bool flag = true;
//     for (int round = 1; round < n; round++)
//     {
//         round_number++;
//         flag = true;
//         for (int i = 0; i < n - round; i++)
//         {
//             if (vect[i] > vect[i + 1])
//             {
//                 int temp = vect[i];
//                 vect[i] = vect[i + 1];
//                 vect[i + 1] = temp;
//                 flag = false;
//             }
//         }
//         if (flag)
//             break;
//     }
//     cout << "round_number : " << round_number << endl;
//     for (int item : vect)
//         cout << item << "  ";
// }

//-----------------------------------------------------------Selection Sort--------------------------------------------------------------
// int main()
// {
// vector<int> vect = {7, 5, 3, 6, 8};
//     int n = vect.size();
//     int min = 0;
//     for (int left = 0; left < n-1; left++)
//     {
//         min = left;
//         for (int right = left + 1; right < n; right++)
//         {
//             if(vect[right] < vect[min])
//                 min = right;
//         }
//         swap(vect[left], vect[min]);
//         // int temp = vect[left];
//         // vect[left] = vect[min];
//         // vect[min] = temp;
//     }
//     for(auto item : vect)
//         cout << item << "  ";
// }
// ---------------------------------------------------------------- 457. Circular Array Loop ----------------------------------------------------------------------
int NextStep(int pointer, int value, int size)
{
    int result = (pointer + value) % size;
    if (result < 0)
        result += size;
    return result;
}

// A function to detect a cycle doesn't exist
bool IsNotCycle(vector<int> &nums, bool prev_direction, int pointer)
{
    int size = nums.size();
    // Set current direction to true if current element is positive, set false otherwise.
    bool curr_direction = nums[pointer] >= 0;
    // If current direction and previous direction are different or moving a pointer takes back to the same value,
    // then the cycle is not possible, we return true, otherwise return false.
    if (prev_direction != curr_direction || abs(nums[pointer] % size) == 0)
        return true;
    else
        return false;
}
bool circularArrayLoop(vector<int> &nums)
{
    int size = nums.size();
    // Iterate through each index of the array 'nums'.
    for (int i = 0; i < size; i++)
    {
        // Set slow and fast pointer at current index value.
        int slow = i, fast = i;
        // Set true in 'forward' if element is positive, set false otherwise.
        bool forward = nums[i] > 0;
        while (true)
        {
            // Move slow pointer to one step.
            slow = NextStep(slow, nums[slow], size);
            // If cycle is not possible, break the loop and start from next element.
            if (IsNotCycle(nums, forward, slow))
                break;
            // First move of fast pointer.
            fast = NextStep(fast, nums[fast], size);
            // If cycle is not possible, break the loop and start from next element.
            if (IsNotCycle(nums, forward, fast))
                break;
            // Second move of fast pointer.
            fast = NextStep(fast, nums[fast], size);
            // If cycle is not possible, break the loop and start from next element.
            if (IsNotCycle(nums, forward, fast))
                break;
            // At any point, if fast and slow pointers meet each other,
            // it indicates that loop has been found, return true.
            if (slow == fast)
                return true;
        }
    }
    return false;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     // vector<int> nums = {2, -1, 1, 2, 2};
//     // vector<int> nums = {-1, -2, -3, -4, -5, 6};
//     vector<int> nums = {1, -1, 5, 1, 4};
//     cout << circularArrayLoop(nums) << endl;
//     cout << string(35, '-') << endl;
// }
