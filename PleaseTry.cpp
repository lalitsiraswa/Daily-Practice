#include <bits/stdc++.h>
#include <typeinfo>
using namespace std;

int main()
{
    unordered_map<int, int> mp;
    mp.insert(pair<int, int>(1, 2));
    mp.insert(pair<int, int>(2, 3));
    unordered_map<int, int>::iterator itr;
    for (itr = mp.begin(); itr != mp.end(); itr++)
    {
        cout << itr->first << ",  " << itr->second << endl;
    }
    return 0;
}

// -------------------------------------------------------------------------------------------------------------------------------------------------------------
// int main()
// {
//     // vector<int> vect = {2, 4, 6, 8, 10};
//     // for (int item : vect)
//     // {
//     //     cout << item << " ";
//     // }
//     // cout << endl;
//     // vector<vector<int>> vect1 = {{1, 2}, {3, 4}};
//     // for (vector<int> item : vect1)
//     // {
//     //     cout << item[0] << "  " << item[1] << endl;
//     // }
//     vector<vector<vector<int>>> vect3 = {{{1, 2}, {3, 4}}, {{4, 5}, {6, 7}}};
//     for (vector<vector<int>> item : vect3)
//     {

//     }
//     return 0;
// }

// -------------------------------------------------------------------------------------------------------------------------------------------------------------
// int main()
// {
//     string s = "LALIT";
//     cout << s << endl;
//     s.append(" S");
//     cout << s << endl;
//     s.push_back('I');
//     cout << s << endl;
//     cout << s.front() << endl;
//     cout << s.back() << endl;
//     s.pop_back();
//     cout << s << endl;
//     return 0;
// }

// ----------------------------------------------------------------------------------------------------------------------------------------------------------
void fun(int *arr)
{
    cout << arr[1] << endl;
}
// int main()
// {
//     int arr[] = {2, 4, 6, 8, 10};
//     fun(arr);
//     return 0;
// }

// --------------------------------------------------------------------- 11. Container With Most Water -----------------------------------------------------
// Brute Force Approach - TLE
int maxAreaBruteForce(vector<int> &height)
{
    int maxAmountWater = 0;
    for (int leftPointer = 0; leftPointer < height.size(); leftPointer++)
    {
        for (int rightPointer = leftPointer + 1; rightPointer < height.size(); rightPointer++)
        {
            int maxWaterCanFillBetween = min(height[leftPointer], height[rightPointer]);
            int currMaxWater = (rightPointer - leftPointer) * maxWaterCanFillBetween;
            if (currMaxWater > maxAmountWater)
                maxAmountWater = currMaxWater;
        }
    }
    return maxAmountWater;
}
// -----------------------------
int maxArea(vector<int> &height)
{
    int n = height.size(), mostWaterLevel = 0, maxWaterCanFillBetween = 0;
    int left = 0, right = n - 1;
    while (left < right)
    {
        maxWaterCanFillBetween = min(height[left], height[right]);
        mostWaterLevel = max(mostWaterLevel, (right - left) * maxWaterCanFillBetween);
        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return mostWaterLevel;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
//     // vector<int> height = {1, 1};
//     cout << "Max Amount Water : " << maxArea(height) << endl;
//     cout << endl
//          << string(35, '-') << endl;
//     return 0;
// }

// ---------------------------------------------------------------------------------------------------------------------------------------------------------

// void printArray(int n, int *arr)
// {
//     for (int i = 0; i < n; i++)
//         cout << arr[i] << " ";
// }

// int main()
// {
//     int arr[5] = {2, 4, 6, 8, 10};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     printArray(n, arr);
//     return 0;
// }

// -------------------------------------------------------------------------------------------------------------------------------------------------------
// int main()
// {
//     vector<int> nums[5];
//     for (int i = 0; i < 5; i++)
//     {
//         for (int j = 0; j <= i; j++)
//             nums[i].push_back(j);
//     }
//     for (int i = 0; i < 5; i++)
//     {
//         for (auto item : nums[i])
//             cout << item << " ";
//         cout << endl;
//     }
//     return 0;
// }

// --------------------------------------------------------------- 1539. Kth Missing Positive Number -----------------------------------------------------
// int findKthPositive(vector<int> &nums, int k)
// {
//     int n = nums.size(), targetValue = 1, index = 0, counter = 0;
//     while (1)
//     {
//         if (index < n && targetValue == nums[index])
//             index++;
//         else
//             counter++;
//         if (counter == k)
//             break;
//         targetValue++;
//     }
//     return targetValue;
// }
// int main()
// {
//     vector<int> nums = {2, 3, 4, 7, 11};
//     cout << findKthPositive(nums, 5) << endl;
//     return 0;
// }

// -----------------------------------------------------------------------------------
// void findSubSequence(string &s, vector<string> &subSequences)
// {
//     int n = s.size();
//     for (int num = 0; num < pow(2, n); num++)
//     {
//         string subSequence = "";
//         for (int i = 0; i < n; i++)
//         {
//             if (num & (1 << i))
//                 subSequence += s[i];
//         }
//         subSequences.push_back(subSequence);
//     }
// }
// int main()
// {
//     string s = "ABC";
//     vector<string> subSequences;
//     findSubSequence(s, subSequences);
//     for (int i = 0; i < subSequences.size(); i++)
//     {
//         for (int j = 0; j < subSequences[i].size(); j++)
//         {
//             cout << subSequences[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

// --------------------------------------------------------------------------------
// void printAllSubSequences(vector<int> &nums, int index)
// {
//     for (int i = index; i < nums.size(); i++)
//     {
//         printAllSubSequences(nums, index);
//     }
// }

// int main()
// {
//     vector<int> nums = {1, 3, 4, 5};
//     printAllSubSequences(nums, 0);
//     return 0;
// }
// --------------------------------------------------------------------------------
// int main()
// {
//     unordered_map<int, unordered_map<int, int>> rowMap;
//     unordered_map<int, unordered_map<int, int>> columnMap;
//     rowMap[0] = {{8, 1}, {6, 1}, {3, 1}};
//     rowMap[1] = {{2, 1}, {7, 1}, {5, 1}};
//     rowMap[2] = {{1, 1}, {4, 1}, {9, 1}};

//     columnMap[0] = {{8, 1}, {2, 1}, {1, 1}};
//     columnMap[1] = {{6, 1}, {7, 1}, {4, 1}};
//     columnMap[2] = {{1, 1}, {4, 1}, {9, 1}};

//     cout << columnMap[0][5] << endl;
//     return 0;
// }

// ------------------------------------------------------------- Power Set Using Bimasking ------------------------------------------------------------------
void printPowerSet(vector<int> nums)
{
    // Set_size of power set of a set with set_size
    // n is (2^n-1)
    int n = nums.size();
    unsigned int pow_set_size = pow(2, n);
    int counter, j;

    // Run from counter 000..0 to 111..1
    for (counter = 0; counter < pow_set_size; counter++)
    {
        for (j = 0; j < n; j++)
        {
            // Check if jth bit in the counter is set
            // If set then print jth element from set
            if (counter & (1 << j))
                cout << nums[j];
        }

        cout << endl;
    }
}
// int main()
// {
//     printPowerSet({1, 2, 3});
//     return 0;
// }
// --------------------------------------------------- Program for Decimal to Binary Conversion in C/C++ -----------------------------------------------------
void decToBinary(int n)
{
    // Size of an integer is assumed to be 32 bits
    for (int i = 6; i >= 0; i--)
    {
        int k = n >> i;
        if (k & 1)
            cout << "1";
        else
            cout << "0";
    }
}
// int main()
// {
//     decToBinary(60);
//     return 0;
// }

// -------------------------------------------------------------- Decimal to Binary ---------------------------------------------------------------------
// int main()
// {
//     int binaryNum[32];
//     int i = 0;
//     int n = 10;
//     while (n > 0)
//     {
//         binaryNum[i] = n % 2;
//         n = n / 2;
//         i++;
//     }
//     for (int j = i - 1; j >= 0; j--)
//         cout << binaryNum[j];
//     return 0;
// }

// ------------------------------------ std::upper_bound and std::lower_bound for Vector in C++ STL ---------------------------
// int main()
// {
//     // vector<int> nums = {10, 20, 30, 30, 30, 40, 50};
//     // vector<int>::iterator lower;
//     // lower = lower_bound(nums.begin(), nums.end(), 55);
//     // cout << lower - nums.begin() << endl;
//     // --------------
//     // vector<int> nums = {10, 20, 30, 40, 50};
//     // vector<int>::iterator upper;
//     // upper = upper_bound(nums.begin(), nums.end(), 60);
//     // cout << upper - nums.begin() << endl;
//     // return 0;
// }
// -------------------------------
// int main()
// {
//     vector<int> nums = {5, 5, 5, 6, 6, 6, 7, 7};
//     vector<int>::iterator lower, upper;
//     lower = lower_bound(nums.begin(), nums.end(), 6);
//     upper = upper_bound(nums.begin(), nums.end(), 6);
//     cout << "lower_bound for 6 at index " << (lower - nums.begin()) << endl;
//     cout << "upper_bound for 6 at index " << (upper - nums.begin()) << endl;
//     return 0;
// }

//-----------------------------------------------------------------------------------------------------------------------------
// int main()
// {
//     queue<int> gquiz;
//     gquiz.push(10);
//     gquiz.push(20);
//     gquiz.push(30);
//     cout << gquiz.front() << endl;
//     cout << gquiz.back() << endl;
//     while (!gquiz.empty())
//     {
//         cout << gquiz.front() << " ";
//         gquiz.pop();
//     }
//     return 0;
// }

// ----------------------------------------------------------------------------------------------------------------------------

// class MyCustomPair
// {
// public:
//     int first;
//     int second;
// };
// int main()
// {
//     // unordered_map<int, int> umap;
//     // umap.insert(pair<int, int>(1, 0));
//     // umap.insert(pair<int, int>(2, 9));
//     // umap.insert(pair<int, int>(3, 8));
//     // umap.insert({4, 7});
//     // umap.insert({5, 6});
//     // if (umap.find(3) != umap.end())
//     //     cout << "Value Find !";
//     // for (auto item : umap)
//     //     cout << item.first << " : " << item.second << endl;

//     map<pair<int, int>, bool> umap;
//     umap.insert({{1, 0}, true});
//     return 0;
// }

// ------------------------------------------------------------------------------------------------------------------
// int main()
// {
//     vector<int> nums01 = {2, 6, 8};
//     vector<int> nums02 = {3, 6, 10};
//     vector<int> nums03 = {5, 8, 11};
//     priority_queue<pair<int, pair<vector<int>::iterator, vector<int>::iterator>>, vector<pair<int, pair<vector<int>::iterator, vector<int>::iterator>>>, greater<pair<int, pair<vector<int>::iterator, vector<int>::iterator>>>> pq;
//     pq.push({nums01.at(0), {nums01.begin(), nums01.end()}});
//     pq.push({nums02.at(0), {nums02.begin(), nums02.end()}});
//     pq.push({nums03.at(0), {nums03.begin(), nums03.end()}});
//     // cout << *(pq.top().second.first) << endl;
//     vector<int> vect = {1, 2, 3};
//     vector<int>::iterator itr = vect.begin();
//     itr += 3;
//     if (itr == vect.end())
//     {
//         cout << "End of the vector" << endl;
//     }
//     return 0;
// }

// -------------------------------------------------------------------------------------------------------------------------------------------------
// bool userComparator(pair<int, int> x, pair<int, int> y)
// {
//     return x.second < y.second;
// }
// class COMPARATOR
// {
// public:
//     bool operator()(pair<int, int> x, pair<int, int> y)
//     {
//         return x.second < y.second;
//     }
// };

// int main()
// {
//     vector<pair<int, int>> pair_vect;
//     pair_vect.push_back({10, 2});
//     pair_vect.push_back({15, 10});
//     pair_vect.push_back({5, 15});
//     pair_vect.push_back({12, 17});
//     pair_vect.push_back(pair<int, int>(2, 12));
//     pair_vect.push_back(pair<int, int>(9, 34));
//     pair_vect.push_back(pair<int, int>(4, 9));
//     pair_vect.push_back(pair<int, int>(1, 3));
//     for (auto item : pair_vect)
//         cout << item.first << " : " << item.second << endl;
//     cout << string(30, '-') << endl;
//     sort(pair_vect.begin(), pair_vect.end(), COMPARATOR());
//     for (auto item : pair_vect)
//         cout << item.first << " : " << item.second << endl;
//     return 0;
// }

//---------------------------------  Priority Queue in C++ Standard Template Library (STL) -------------------------------------

// int main()
// {
//     int arr[6] = {10, 2, 4, 8, 6, 9};
//     priority_queue<int, vector<int>, greater<int>> gquiz(arr, arr + 6);
//     cout << "Array : ";
//     for (int i = 0; i < 6; i++)
//         cout << arr[i] << " ";
//     cout << "Priority Queue : ";
//     cout << endl;
//     while (!gquiz.empty())
//     {
//         cout << gquiz.top() << " ";
//         gquiz.pop();
//     }
//     return 0;
// }

// int main()
// {
//     int arr[6] = {10, 2, 4, 8, 6, 9};
//     priority_queue<int> pq;
//     cout << "Array : ";
//     for (auto i : arr)
//         cout << i << " ";
//     cout << endl;
//     for (int i = 0; i < 6; i++)
//         pq.push(arr[i]);
//     cout << "Priority Queue : ";
//     while (!pq.empty())
//     {
//         cout << pq.top() << " ";
//         pq.pop();
//     }
//     return 0;
// }

// ------------------ Priority Queue in C++ Standard Template Library (STL)-------------------
// int main()
// {
//     int arr[6] = {10, 2, 4, 8, 6, 9};
//     priority_queue<int, vector<int>, greater<int>> pq;
//     cout << "Array : " << endl;
//     for (auto item : arr)
//         cout << item << ", ";
//     cout << endl;
//     for (int i = 0; i < 6; i++)
//         pq.push(arr[i]);
//     while (!pq.empty())
//     {
//         cout << pq.top() << ", ";
//         pq.pop();
//     }
//     return 0;
// }
// ------------------
// int main()
// {
//     int arr[6] = {10, 2, 4, 8, 6, 9};
//     priority_queue<int> pq;
//     cout << "Array : " << endl;
//     for (auto item : arr)
//         cout << item << ", ";
//     cout << endl;
// for (int i = 0; i < 6; i++)
//     pq.push(arr[i]);
// while (!pq.empty())
// {
//     cout << pq.top() << ", ";
//     pq.pop();
// }
//     return 0;
// }
// -------------------------------------------------------------------------------------------
// void show(int a[], int array_size)
// {
//     for (int i = 0; i < array_size; i++)
//         cout << a[i] << ", ";
// }
// // we pass an object of this class as
// // third arg to sort function...
// template <typename T>
// class Comparator
// {
// public:
//     bool operator()(T x1, T x2)
//     {
//         return x1 < x2;
//     }
// };
// template <class T>
// bool funComparator(T x1, T x2)
// {
//     return x1 > x2;
// }

// int main()
// {
//     int a[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
//     int asize = sizeof(a) / sizeof(a[0]);
//     cout << "The array before sorting is : " << endl;
//     show(a, asize);
//     cout << "The array after sorting is(asc) : " << endl;
//     sort(a, a + asize);
//     show(a, asize);
//     cout << "The arrays after sorting is(desc) : " << endl;
//     sort(a, a + asize, greater<int>());
//     show(a, asize);
//     cout << "The array after sorting is (asc but out comparator class) : " << endl;
//     sort(a, a + asize, Comparator<int>());
//     show(a, asize);
//     cout << "The array after sorting is (desc but out comparator class) : " << endl;
//     sort(a, a + asize, funComparator<int>);
//     show(a, asize);
//     return 0;
// }

// ---------------------------------------------------------------------
// struct Interval
// {
//     int start, end;
// };
// bool compareInterval(Interval i1, Interval i2)
// {
//     return (i1.end < i2.end);
// }
// int main()
// {
//     Interval arr[] = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     sort(arr, arr + n, compareInterval);
//     cout << "Intervals sorted by end time : " << endl;
//     for (int i = 0; i < n; i++)
//         cout << "[" << arr[i].start << ", " << arr[i].end << "]" << endl;
// }

// ---------------------------------------------------------------------
// struct cmp
// {
//     bool operator()(int a, int b) const { return a > b; }
// };

// int main()
// {
//     map<int, int> m1;
//     m1.insert({0, 5});
//     m1.insert({1, 6});
//     m1.insert({2, 7});
//     m1.insert({3, 8});
//     m1.insert({4, 9});
//     for (auto &item : m1)
//         cout << item.first << " : " << item.second << endl;
//     cout << endl;
//     map<int, int, cmp> m2;
//     m2.insert({0, 5});
//     m2.insert({1, 6});
//     m2.insert({2, 7});
//     m2.insert({3, 8});
//     m2.insert({4, 9});
//     for (auto &item : m2)
//         cout << item.first << " : " << item.second << endl;
//     return 0;
// }

//--------------------------- Deque ---------------------------------
void showdq(deque<int> &g)
{
    deque<int>::iterator itr;
    for (itr = g.begin(); itr != g.end(); itr++)
        cout << *itr << "  ";
}
// int main()
// {
//     deque<int> gquiz;
//     gquiz.push_back(10);
//     gquiz.push_back(20);
//     gquiz.push_back(30);
//     gquiz.push_back(15);
//     cout << "The dequeu gquiz is : ";
//     showdq(gquiz);
// }

//--------------------------------------------------------------------------------------------------

// int main()
// {
//     vector<int> nums = {100, 20, 50, 25, 12, 5, 2, 75, 80};
//     int first = INT_MIN, second = INT_MIN, third = INT_MIN;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (nums.at(i) > first)
//         {
//             third = second;
//             second = first;
//             first = nums.at(i);
//         }
//         else if (nums.at(i) > second)
//         {
//             third = second;
//             second = nums.at(i);
//         }
//         else if (nums.at(i) > third)
//             third = nums.at(i);
//     }
//     cout << first << " : " << second << " : " << third << endl;
// }

// -------------------------------------------------------------------------------------------------
// void printVector(vector<int> vect)
// {
//     for (auto item : vect)
//         cout << item << "  ";
// }

// int main()
// {
//     vector<int> vect = {2, 4, 6, 8, 10, 12, 14, 16};
//     vector<int>::iterator itr;
//     itr = find(vect.begin(), vect.end(), 10);
//     int index = itr - vect.begin();
//     vector<int> leftSubTree(vect.begin(), vect.begin() + index);
//     vector<int> rightSubTree(vect.begin()+index+1, vect.end());
//     for(auto item : leftSubTree)
//         cout << item << "  ";
//     cout << endl;
//     for(auto item : rightSubTree)
//         cout << item << "  ";
// }
//--------------------------------------------------------------------------------------------------
// int main()
// {
//     vector<int> vect{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
//     unordered_map<int, int> umap;
//     for (int i = 0; i < vect.size(); i++)
//     {
//         umap.insert({vect[i], i});
//     }
//     unordered_map<int, int>::iterator last2nd;
//     last2nd = umap.end();
//     cout << last2nd->first << "  :  " << --last2nd->second << endl;
//     // for(auto itr = umap.begin(); itr != umap.end();)
//     // {
//     //     cout << itr->first << " : " << itr->second << endl;
//     //     itr++;
//     // }
//     // auto itr = umap.begin();
//     // while (itr != umap.end())
//     // {
//     //     cout << itr->first << " : " << itr->second << endl;
//     //     itr++;
//     // }
// }

//--------------------------------------------------------------------------------------------------
// int main()
// {
//     vector<int> vect{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
//     unordered_map<int, int> umap;
//     for (int i = 0; i < vect.size(); i++)
//     {
//         umap.insert(pair(vect[i], i));
//     }
//     for (auto item : umap)
//     {
//         cout << item.first << " : " << item.second << endl;
//     }
// }

//------------------------------------------------------------------------------------------------
// class Demo
// {
// public:
//     Demo()
//     {
//         cout << "Default!";
//     }
//     Demo(int x)
//     {
//         cout << "Hello Parent!" << endl;
//     }
// };
// class Dep : Demo
// {
// public:
//     Dep()
//     {
//         cout << "Hello Child!" << endl;
//     }
// };

// int main()
// {
//     Dep obj;
// }

//------------------------------------------------------------------
// static int n = 1;
// void insert(int *arr)
// {
//     int element;
//     cout << "Enter an element : ";
//     cin >> element;
//     *(arr + n) = element;
//     // cout << *(arr+n) << endl;
//     ++n;
// }

// int main()
// {
//     int first = 5;
//     int *arr = &first;
//     insert(arr);
//     for(int i = 0; i < n; i++)
//         cout << *arr << "  ";
// }