#include <bits/stdc++.h>
using namespace std;

// ----------------------------------------------------------------- Pring Hello World N Times --------------------------------------------------------------------------
void printHelloWorld(int count)
{
    if (count == 0)
        return;
    cout << "Hello World" << endl;
    printHelloWorld(count - 1);
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     printHelloWorld(5);
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// ---------------------------------------------------- Print 1 to N By Backtracking or Without using + sign  -----------------------------------------------------------
void print1ToNUsingBacktracking(int n)
{
    if (n == 0)
        return;
    print1ToNUsingBacktracking(n - 1);
    cout << n << endl;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     print1ToNUsingBacktracking(5);
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// --------------------------------------------------------------- Sum of first N Natural Numbers ------------------------------------------------------------------------
int sumOfFirstNNaturalNumber(int n)
{
    if (n == 0)
        return n;
    return n + sumOfFirstNNaturalNumber(n - 1);
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     cout << sumOfFirstNNaturalNumber(5);
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// --------------------------------------------------------------- Reverse an array using recursion ------------------------------------------------------------------------
void reverseArray(vector<int> &vect, int left, int right)
{
    if (left >= right)
        return;
    swap(vect[left], vect[right]);
    reverseArray(vect, left + 1, right - 1);
}
// ---- Using single variable ------
void reverseArray2(vector<int> &vect, int index)
{
    int n = vect.size() - 1;
    if (index >= (n - index))
        return;
    swap(vect[index], vect[n - index]);
    reverseArray2(vect, index + 1);
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> vect = {1, 2, 3, 4, 2};
//     reverseArray2(vect, 0);
//     for (auto item : vect)
//         cout << item << " ";
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// --------------------------------------------------------------- Check if a string is palindrome or not ------------------------------------------------------------------------
bool isStringPalindrome(string s, int left, int right)
{
    if (left >= right)
        return true;
    if (s[left] != s[right])
        return false;
    return isStringPalindrome(s, left + 1, right - 1);
}
// -------- Using single variable -------------
bool isStringPalindrome2(string s, int index)
{
    int n = s.size() - 1;
    if (index >= (n - index))
        return true;
    if (s[index] != s[n - index])
        return false;
    return isStringPalindrome2(s, index + 1);
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     string str = "abcdedcba";
//     cout << isStringPalindrome2(str, 0) << endl;
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// ----------------------------------------------------------------------------- Fibonacci Series -----------------------------------------------------------------------
int fibonacciNum(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fibonacciNum(n - 1) + fibonacciNum(n - 2);
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     cout << fibonacciNum(4);
//     cout << endl << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------------- Recursion on Subsequences | Printing Subsequences -------------------------------------------------------
// take or not-take concept / pick or not-pick concept
void printAllSubsequences(vector<int> &vect, vector<int> &subsequence, int index)
{
    if (index >= vect.size())
    {
        for (auto item : subsequence)
            cout << item << ", ";
        if (subsequence.size() == 0)
            cout << "{}";
        cout << endl;
        return;
    }
    // take or pick the particular index into the subsequence
    subsequence.push_back(vect[index]);
    printAllSubsequences(vect, subsequence, index + 1);
    // not take or not pick condition, this element is not added to your subseqnence
    subsequence.pop_back();
    printAllSubsequences(vect, subsequence, index + 1);
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> vect = {1, 2, 3};
//     vector<int> subsequence;
//     printAllSubsequences(vect, subsequence, 0);
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------------------- Printing Subsequences whose sum is k -------------------------------------------------------------
void printSubSequenceWithSumK(vector<int> &vect, vector<int> &subSequence, int index, int sum)
{
    if (index >= vect.size())
    {
        if (sum == 0)
        {
            for (auto item : subSequence)
                cout << item << " ";
            cout << endl;
        }
        return;
    }
    // take
    subSequence.push_back(vect[index]);
    printSubSequenceWithSumK(vect, subSequence, index + 1, sum - vect[index]);
    // not-take
    subSequence.pop_back();
    printSubSequenceWithSumK(vect, subSequence, index + 1, sum);
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> vect = {1, 2, 3};
//     printSubsequenceWithSumK(vect, 3);
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// --------------------------------------------------------------- Printing Only One Subsequences whose sum is k ---------------------------------------------------------
bool printonlyOneSubSequenceWithSumK(vector<int> &vect, vector<int> &subSequence, int index, int sum)
{
    if (index >= vect.size())
    {
        if (sum == 0)
        {
            for (auto item : subSequence)
                cout << item << " ";
            cout << endl;
            return true;
        }
        return false;
    }
    // take
    subSequence.push_back(vect[index]);
    if (printonlyOneSubSequenceWithSumK(vect, subSequence, index + 1, sum - vect[index]))
        return true;
    // not-take
    subSequence.pop_back();
    if (printonlyOneSubSequenceWithSumK(vect, subSequence, index + 1, sum))
        return true;
    return false;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> vect = {1, 2, 3};
//     vector<int> subSequence;
//     bool isSubSequenceFound = false;
//     printonlyOneSubSequenceWithSumK(vect, subSequence, 0, 3);
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// --------------------------------------------------------------------- Count Subsequences whose sum is k ---------------------------------------------------------------
int countSubSequencesWithSumK(vector<int> &vect, int index, int sum)
{
    if (index >= vect.size())
    {
        if (sum == 0)
            return 1;
        return 0;
    }
    // take
    int take = countSubSequencesWithSumK(vect, index + 1, sum - vect[index]);
    // not-take
    int notTake = countSubSequencesWithSumK(vect, index + 1, sum);
    return take + notTake;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> vect = {1, 2, 1};
//     cout << countSubSequencesWithSumK(vect, 0, 2);
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// -------------------------------------------------------------------------------- Merge Sort --------------------------------------------------------------------------
void merge(vector<int> &arr, int low, int middle, int high)
{
    vector<int> temp;       // temporary array
    int left = low;         // starting index of left half of arr
    int right = middle + 1; // starting index of right half of arr
    // storing elements in the temporary array in a sorted manner//
    while (left <= middle && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    // if elements on the left half are still left //
    while (left <= middle)
    {
        temp.push_back(arr[left]);
        left++;
    }
    //  if elements on the right half are still left //
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}
void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int middle = (low + high) / 2;
    mergeSort(arr, low, middle);      // left half
    mergeSort(arr, middle + 1, high); // right half
    merge(arr, low, middle, high);    // merging sorted halves
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> arr = {3, 1, 2, 4, 1, 5, 2, 6, 4};
//     mergeSort(arr, 0, arr.size());
//     for (auto item : arr)
//         cout << item << " ";
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// -------------------------------------------------------------------------------- Quick Sort --------------------------------------------------------------------------
int findPartition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        // find element that is larger then the pivot
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        // find element that is smaller then the pivot
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        // swap them, so that, small element are on the left side
        // and large element on the right side
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int partitionIndex = findPartition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> arr = {4, 6, 8, 2, 5, 7, 9, 1, 3};
//     quickSort(arr, 0, arr.size() - 1);
//     for (auto item : arr)
//         cout << item << " ";
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// -------------------------------------------------------------------------- 8. String to Integer (atoi) --------------------------------------------------------------------
double myAtoiHelper(string &s, int index, double number)
{
    if (index >= s.size() || s[index] < '0' || s[index] > '9')
    {
        return number;
    }
    number = (number * 10) + (s[index] - '0');
    return myAtoiHelper(s, index + 1, number);
}
int myAtoi(string s)
{
    int n = s.size();
    int index = 0;
    while (s[index] == ' ')
        index++;
    bool positive = s[index] == '+';
    bool negative = s[index] == '-';
    positive == true ? index++ : index;
    negative == true ? index++ : index;
    double number = 0;
    number = myAtoiHelper(s, index, number);
    number = negative ? -(number) : number;
    number = number > INT_MAX ? INT_MAX : number;
    number = number < INT_MIN ? INT_MIN : number;
    return number;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     string s = "1337c0d3";
//     cout << myAtoi(s) << endl;
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------------------------------- 50. Pow(x, n) -------------------------------------------------------------------------
double powHelperPositive(double x, int n)
{
    if (n == 0)
        return 1;
    return x * powHelperPositive(x, n - 1);
}
double powHelperNegative(double x, int n)
{
    if (n == 0)
        return 1;
    return (1 / x * powHelperNegative(x, n + 1));
}
double myPow(double x, int n)
{
    if (n == INT_MAX)
        return (x == 1) ? 1 : (x == -1) ? -1
                                        : 0;
    if (n == INT_MIN)
        return (x == 1 || x == -1) ? 1 : 0;
    double ans = 0;
    if (n >= 0)
    {
        ans = powHelperPositive(x, n);
    }
    if (n < 0)
    {
        ans = powHelperNegative(x, n);
    }
    return ans;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     string s = "1337c0d3";
//     cout << myAtoi(s) << endl;
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// -------------------------------------------------------------------- 1922. Count Good Numbers -------------------------------------------------------------------------
// ------------ TLE -------------
int countGoodNumbers(long long n)
{
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            ans *= 5;
        }
        else
        {
            ans *= 4;
        }
    }
    return ans;
}
// -----------------------
long long powerHelper(long long x, long long n, int &mod)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return powerHelper((x * x) % mod, n / 2, mod);
    else
        return (x * powerHelper(x, n - 1, mod)) % mod;
}
int countGoodNumbersOtherWay(long long n)
{
    int mod = 1e9 + 7;
    long long evenCount = n / 2 + n % 2;
    long long oddCount = n / 2;
    long long first = powerHelper(5, evenCount, mod);
    long long second = powerHelper(4, oddCount, mod);
    long long ans = (first * second) % mod;
    return ans;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     cout << countGoodNumbersOtherWay(4) << endl;
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// -------------------------------------------------------------------- Sort a stack -------------------------------------------------------------------------
void sortStackHelper(stack<int> &s, int index)
{
    if (index == s.size())
        return;
    stack<int> temp;
    int minElement = s.top();
    s.pop();
    while (s.size() != index)
    {
        int topElement = s.top();
        if (topElement < minElement)
        {
            temp.push(minElement);
            minElement = topElement;
        }
        else
        {
            temp.push(topElement);
        }
        s.pop();
    }
    s.push(minElement);
    while (!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
    sortStackHelper(s, index + 1);
}
void SortedStack(stack<int> &s)
{
    sortStackHelper(s, 0);
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     stack<int> s;
//     s.push(11);
//     s.push(2);
//     s.push(32);
//     s.push(3);
//     s.push(41);
//     cout << s.size() << endl;
//     SortedStack(s);
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------------------------- Reverse a Stack ------------------------------------------------------------------------------
void ReverseHelper(stack<int> &St, int index)
{
    if (index == St.size() - 1)
        return;
    stack<int> temp;
    int topElement = St.top();
    St.pop();
    while (St.size() != index)
    {
        temp.push(St.top());
        St.pop();
    }
    St.push(topElement);
    while (!temp.empty())
    {
        St.push(temp.top());
        temp.pop();
    }
    ReverseHelper(St, index + 1);
}
void Reverse(stack<int> &St)
{
    ReverseHelper(St, 0);
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     stack<int> s;
//     s.push(11);
//     s.push(2);
//     s.push(32);
//     s.push(3);
//     s.push(41);
//     Reverse(s);
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------------------------- Generate all binary strings ------------------------------------------------------------------------------
void generateBinaryStringsHelper(string binaryString, int num, vector<string> &binaryStrings)
{
    int n = binaryString.size();
    if (n == num)
    {
        binaryStrings.push_back(binaryString);
        return;
    }
    char lastAddedChar = binaryString[n - 1];
    generateBinaryStringsHelper(binaryString + "0", num, binaryStrings);
    if (lastAddedChar != '1')
    {
        generateBinaryStringsHelper(binaryString + "1", num, binaryStrings);
    }
}
vector<string> generateBinaryStrings(int num)
{
    vector<string> binaryStrings;
    generateBinaryStringsHelper("0", num, binaryStrings);
    generateBinaryStringsHelper("1", num, binaryStrings);
    return binaryStrings;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<string> binaryStrings = generateBinaryStrings(4);
//     for (string str : binaryStrings)
//         cout << str << endl;
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------------------------- 22. Generate Parentheses ------------------------------------------------------------------------------
void generateParenthesisHelper(int n, vector<string> &parentheses, int openCount, int closeCount, string str)
{
    if (openCount + closeCount == n * 2)
    {
        parentheses.push_back(str);
        return;
    }
    if (openCount < n)
    {
        generateParenthesisHelper(n, parentheses, openCount + 1, closeCount, str + "(");
    }
    if (openCount > closeCount)
    {
        generateParenthesisHelper(n, parentheses, openCount, closeCount + 1, str + ")");
    }
}
vector<string> generateParenthesis(int n)
{
    vector<string> parentheses;
    generateParenthesisHelper(n, parentheses, 0, 0, "");
    return parentheses;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<string> parentheses = generateParenthesis(3);
//     for (string str : parentheses)
//         cout << str << endl;
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// --------------------------------------------------------------------------- 78. Subsets --------------------------------------------------------------------------------
void subSetsHelper(vector<int> &nums, vector<vector<int>> &subSets, int index, vector<int> &subSet)
{
    if (index >= nums.size())
    {
        subSets.push_back(subSet);
        return;
    }
    // not-pick
    subSetsHelper(nums, subSets, index + 1, subSet);
    // pick
    subSet.push_back(nums[index]);
    subSetsHelper(nums, subSets, index + 1, subSet);
    subSet.pop_back();
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> subSets;
    vector<int> subSet;
    subSetsHelper(nums, subSets, 0, subSet);
    return subSets;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {1, 2, 3};
//     vector<vector<int>> subSets = subsets(nums);
//     for (int i = 0; i < subSets.size(); i++)
//     {
//         cout << "[";
//         for (int j = 0; j < subSets[i].size(); j++)
//         {
//             cout << subSets[i][j] << " ";
//         }
//         cout << "]" << endl;
//     }
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// --------------------------------------------------------------------------- Better String --------------------------------------------------------------------------------
// ------------------ TLE ------------------------
void findSubsets(string str, set<string> &subSets, string subSet, int index)
{
    if (index >= str.size())
    {
        subSets.insert(subSet);
        return;
    }
    // not-pick
    findSubsets(str, subSets, subSet, index + 1);
    // pick
    subSet.push_back(str[index]);
    findSubsets(str, subSets, subSet, index + 1);
    subSet.pop_back();
}
string betterString(string str1, string str2)
{
    set<string> str1SubSets;
    set<string> str2SubSets;
    findSubsets(str1, str1SubSets, "", 0);
    findSubsets(str2, str2SubSets, "", 0);
    return str1SubSets.size() >= str2SubSets.size() ? str1 : str2;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     string str1 = "ljmolmti";
//     string str2 = "sqapzwbb";
//     cout << betterString(str1, str2) << endl;
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// --------------------------------------------------------------------------- Perfect Sum Problem --------------------------------------------------------------------------------
int perfectSumHelper(int arr[], int n, int sum, int index, int currentSum)
{
    if (index >= n)
    {
        if (currentSum == sum)
            return 1;
        return 0;
    }
    // pick
    int pick = perfectSumHelper(arr, n, sum, index + 1, currentSum + arr[index]);
    // not-pick
    int notPick = perfectSumHelper(arr, n, sum, index + 1, currentSum);
    return pick + notPick;
}
int perfectSum(int arr[], int n, int sum)
{
    return perfectSumHelper(arr, n, sum, 0, 0);
}
// ---------------------------
int static perfectSumRecursion(int arr[], int index, int sum, vector<vector<int>> &dp, int &MOD)
{
    // Base case: If the target sum is 0, we found a valid subset
    if (sum == 0)
        return 1;

    // Base case: If we have considered all elements and the target is still not 0, return 0
    if (index == 0)
        return (arr[0] == sum) ? 1 : 0;

    // If the result for this state is already calculated, return it
    if (dp[index][sum] != -1)
        return dp[index][sum];

    // Recursive cases
    // 1. Exclude the current element
    int notTaken = perfectSumRecursion(arr, index - 1, sum, dp, MOD);

    // 2. Include the current element if it doesn't exceed the target
    int taken = 0;
    if (arr[index] <= sum)
        taken = perfectSumRecursion(arr, index - 1, sum - arr[index], dp, MOD);

    // Store the result in the DP table and return
    return dp[index][sum] = (notTaken + taken) % MOD;
}
int perfectSum2(int arr[], int n, int sum)
{
    int MOD = 1e9 + 7;
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return perfectSumRecursion(arr, n - 1, sum, dp, MOD);
}
int main()
{
    cout << string(30, '-') << endl;
    int arr[] = {9, 7, 0, 3, 9, 8, 6, 5, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << perfectSum2(arr, n, 31);
    cout << endl
         << string(30, '-') << endl;
    return 0;
}