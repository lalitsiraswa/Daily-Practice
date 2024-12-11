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
// int main()
// {
//     cout << string(30, '-') << endl;
//     int arr[] = {9, 7, 0, 3, 9, 8, 6, 5, 7, 6};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     cout << perfectSum2(arr, n, 31);
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// --------------------------------------------------------------------------- Subset Sum --------------------------------------------------------------------------------
bool isSubsetPresentHelper(int k, vector<int> &a, int index, vector<vector<int>> &dp)
{
    if (k == 0)
        return true;
    if (index == 0)
        return a[index] == k;
    if (dp[index][k] != -1)
        return dp[index][k];
    if (isSubsetPresentHelper(k, a, index - 1, dp))
        return dp[index][k] = true;
    if (a[index] <= k && isSubsetPresentHelper(k - a[index], a, index - 1, dp))
        return dp[index][k] = true;
    return dp[index][k] = false;
}
bool isSubsetPresent(int n, int k, vector<int> &a)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return isSubsetPresentHelper(k, a, a.size() - 1, dp);
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> a = {4, 2, 5, 6, 7};
//     cout << isSubsetPresent(a.size(), 14, a);
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// --------------------------------------------------------------------------- 39. Combination Sum --------------------------------------------------------------------------------
void combinationSumHelper(vector<int> &candidates, int target, int index, vector<int> &combination, vector<vector<int>> &combinations)
{
    // base-case
    if (target == 0)
    {
        combinations.push_back(combination);
        return;
    }
    if (index < 0)
    {
        return;
    }
    // not-pick
    combinationSumHelper(candidates, target, index - 1, combination, combinations);
    // pick
    if (candidates[index] <= target)
    {
        combination.push_back(candidates[index]);
        combinationSumHelper(candidates, target - candidates[index], index, combination, combinations);
        combination.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> combinations;
    vector<int> combination;
    combinationSumHelper(candidates, target, candidates.size() - 1, combination, combinations);
    return combinations;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> candidates = {2, 3, 5};
//     vector<vector<int>> combinations = combinationSum(candidates, 8);
//     for (int i = 0; i < combinations.size(); i++)
//     {
//         cout << "{";
//         for (int j = 0; j < combinations[i].size(); j++)
//             cout << " " << combinations[i][j];
//         cout << "}" << endl;
//     }
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// --------------------------------------------------------------------------- 40. Combination Sum II --------------------------------------------------------------------------------
// ---------------- TLE ---------------------
void combinationSum2Helper(vector<int> &candidates, int target, vector<int> &combination, set<vector<int>> &combinationsSet, int index)
{
    if (target == 0)
    {
        vector<int> temp(combination.begin(), combination.end());
        sort(temp.begin(), temp.end());
        combinationsSet.insert(temp);
        return;
    }
    if (index < 0)
    {
        return;
    }
    // not-pick
    combinationSum2Helper(candidates, target, combination, combinationsSet, index - 1);
    // pick
    if (candidates[index] <= target)
    {
        combination.push_back(candidates[index]);
        combinationSum2Helper(candidates, target - candidates[index], combination, combinationsSet, index - 1);
        combination.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    set<vector<int>> combinationsSet;
    vector<int> combination;
    combinationSum2Helper(candidates, target, combination, combinationsSet, candidates.size() - 1);
    return {combinationsSet.begin(), combinationsSet.end()};
}
// ---------------------------------
void static findCombinations(int index, int target, vector<int> &candidates, vector<vector<int>> &combinations, vector<int> &ds)
{
    if (target == 0)
    {
        combinations.push_back(ds);
        return;
    }
    for (int i = index; i < candidates.size(); i++)
    {
        if (i > index && candidates[i] == candidates[i - 1])
            continue;
        if (candidates[i] > target)
            break;
        ds.push_back(candidates[i]);
        findCombinations(i + 1, target - candidates[i], candidates, combinations, ds);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum2_2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> combinations;
    vector<int> ds;
    findCombinations(0, target, candidates, combinations, ds);
    return combinations;
}

// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> candidates = {2, 5, 2, 1, 2};
//     vector<vector<int>> combinations = combinationSum2_2(candidates, 5);
//     for (int i = 0; i < combinations.size(); i++)
//     {
//         cout << "{";
//         for (int j = 0; j < combinations[i].size(); j++)
//             cout << " " << combinations[i][j];
//         cout << "}" << endl;
//     }
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// --------------------------------------------------------------------------- Subset Sums - GFG --------------------------------------------------------------------------------
void subsetSumsHelper(vector<int> &arr, vector<int> &subSetSum, int sum, int index)
{
    if (index < 0)
    {
        subSetSum.push_back(sum);
        return;
    }
    // Not-Pick
    subsetSumsHelper(arr, subSetSum, sum, index - 1);
    // Pick
    subsetSumsHelper(arr, subSetSum, sum + arr[index], index - 1);
}
vector<int> subsetSums(vector<int> arr, int n)
{
    vector<int> subSetSum;
    subsetSumsHelper(arr, subSetSum, 0, n - 1);
    return subSetSum;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> arr = {1, 2, 1};
//     vector<int> subsets = subsetSums(arr, arr.size());
//     for (auto item : subsets)
//         cout << item << " ";
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// --------------------------------------------------------------------------- 90. Subsets II --------------------------------------------------------------------------------
void subsetsWithDupHelper(vector<int> &nums, set<vector<int>> &subSets, vector<int> &subSet, int index)
{
    if (index < 0)
    {
        vector<int> temp(subSet.begin(), subSet.end());
        sort(temp.begin(), temp.end());
        subSets.insert(temp);
        return;
    }
    // not-pick
    subsetsWithDupHelper(nums, subSets, subSet, index - 1);
    // pick
    subSet.push_back(nums[index]);
    subsetsWithDupHelper(nums, subSets, subSet, index - 1);
    subSet.pop_back();
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    set<vector<int>> subSets;
    vector<int> subSet;
    subsetsWithDupHelper(nums, subSets, subSet, nums.size() - 1);
    return {subSets.begin(), subSets.end()};
}
// ------------------------
void subsetsWithDupHelper2(vector<int> &nums, vector<vector<int>> &subSets, vector<int> &subSet, int index)
{
    subSets.push_back(subSet);
    for (int i = index; i < nums.size(); i++)
    {
        if (i > index && nums[i] == nums[i - 1])
            continue;
        subSet.push_back(nums[i]);
        subsetsWithDupHelper2(nums, subSets, subSet, i + 1);
        subSet.pop_back();
    }
}
vector<vector<int>> subsetsWithDup2(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> subSets;
    vector<int> subSet;
    subsetsWithDupHelper2(nums, subSets, subSet, 0);
    return subSets;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {1, 2, 2};
//     vector<vector<int>> subSets = subsetsWithDup2(nums);
//     for (int i = 0; i < subSets.size(); i++)
//     {
//         cout << "{";
//         for (int j = 0; j < subSets[i].size(); j++)
//             cout << " " << subSets[i][j];
//         cout << "}" << endl;
//     }
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------------------- 17. Letter Combinations of a Phone Number --------------------------------------------------------------------------------
void letterCombinationsHelper(string digits, vector<string> &letterCombination, string &combination, int index, unordered_map<char, vector<char>> &phoneNumberMap)
{
    if (index == digits.size())
    {
        letterCombination.push_back(combination);
        return;
    }
    for (int i = 0; i < phoneNumberMap[digits[index]].size(); i++)
    {
        combination.push_back(phoneNumberMap[digits[index]][i]);
        letterCombinationsHelper(digits, letterCombination, combination, index + 1, phoneNumberMap);
        combination.pop_back();
    }
}
vector<string> letterCombinations(string digits)
{
    vector<string> letterCombination;
    if (digits.size() == 0)
        return letterCombination;
    unordered_map<char, vector<char>>
        phoneNumberMap;
    phoneNumberMap['0'] = {};
    phoneNumberMap['1'] = {};
    phoneNumberMap['2'] = {'a', 'b', 'c'};
    phoneNumberMap['3'] = {'d', 'e', 'f'};
    phoneNumberMap['4'] = {'g', 'h', 'i'};
    phoneNumberMap['5'] = {'j', 'k', 'l'};
    phoneNumberMap['6'] = {'m', 'n', 'o'};
    phoneNumberMap['7'] = {'p', 'q', 'r', 's'};
    phoneNumberMap['8'] = {'t', 'u', 'v'};
    phoneNumberMap['9'] = {'w', 'x', 'y', 'z'};
    string combination;
    letterCombinationsHelper(digits, letterCombination, combination, 0, phoneNumberMap);
    return letterCombination;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     string digits = "23";
//     vector<string> letterCombination = letterCombinations(digits);
//     for (auto item : letterCombination)
//         cout << item << ",  ";
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------------------------- 46. Permutations --------------------------------------------------------------------------------
void permuteHelper(vector<int> &nums, vector<vector<int>> &permutations, vector<int> &permutation, vector<int> &isVisited)
{
    if (permutation.size() == nums.size())
    {
        permutations.push_back(permutation);
        return;
    }
    for (int index = 0; index < nums.size(); index++)
    {
        if (!isVisited[index])
        {
            isVisited[index] = 1;
            permutation.push_back(nums[index]);
            permuteHelper(nums, permutations, permutation, isVisited);
            permutation.pop_back();
            isVisited[index] = 0;
        }
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    int n = nums.size();
    vector<int> isVisited(n, 0);
    vector<vector<int>> permutations;
    vector<int> permutation;
    permuteHelper(nums, permutations, permutation, isVisited);
    return permutations;
}
// ----------------------------------------
void recurPermute(int index, vector<int> &nums, vector<vector<int>> &ans)
{
    if (index == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        recurPermute(index + 1, nums, ans);
        swap(nums[index], nums[i]);
    }
}
vector<vector<int>> permute2(vector<int> &nums)
{
    vector<vector<int>> ans;
    recurPermute(0, nums, ans);
    return ans;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {1, 2, 3};
//     vector<vector<int>> permutations = permute2(nums);
//     for (int i = 0; i < permutations.size(); i++)
//     {
//         cout << "{";
//         for (int j = 0; j < permutations[i].size(); j++)
//             cout << " " << permutations[i][j];
//         cout << "}" << endl;
//     }
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------------------------- 51. N-Queens --------------------------------------------------------------------------------
bool isSafe(int row, int col, vector<string> &board, int n)
{
    // Check upper element
    int dupRow = row;
    int dupCol = col;
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }
    // Check for horizontal
    col = dupCol;
    row = dupRow;
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }
    // Check for lower elements
    col = dupCol;
    row = dupRow;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }
    return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[row][col] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    solve(0, board, ans, n);
    return ans;
}
// ------------------------------
void solveNQueensRecursively(int row, vector<int> &rows, vector<int> &columns, vector<string> &chessBoard, int n, vector<vector<string>> &solution)
{
    if (n == 0)
    {
        solution.push_back(chessBoard);
        return;
    }
    if (row >= chessBoard.size())
        return;
    if (rows[row])
        return;
    for (int i = 0; i < chessBoard.size(); i++)
    {
        if (columns[i])
            continue;
        int col = i;
        bool flag = false;
        // Check For Upper Diagonal Right
        for (int m = row; m > 0; m--)
        {
            if (col < chessBoard.size() - 1 && chessBoard[m - 1][col + 1] == 'Q')
            {
                flag = true;
                break;
            }
            col++;
        }
        if (flag)
            continue;
        col = i;
        // Check For Upper Diagonal Left
        for (int m = row; m > 0; m--)
        {
            if (col > 0 && chessBoard[m - 1][col - 1] == 'Q')
            {
                flag = true;
                break;
            }
            col--;
        }
        if (flag)
            continue;
        if (!columns[i] && !rows[row])
        {
            rows[row] = 1;
            columns[i] = 1;
            chessBoard[row][i] = 'Q';
            solveNQueensRecursively(row + 1, rows, columns, chessBoard, n - 1, solution);
            rows[row] = 0;
            columns[i] = 0;
            chessBoard[row][i] = '.';
        }
    }
    return;
}
vector<vector<string>> solveNQueens2(int n)
{
    vector<vector<string>> solution;
    vector<string> chessBoard;
    string rowString;
    for (int i = 0; i < n; i++)
        rowString.append(".");
    for (int i = 0; i < n; i++)
        chessBoard.push_back(rowString);
    vector<int> rows(n, 0);
    vector<int> columns(n, 0);
    solveNQueensRecursively(0, rows, columns, chessBoard, n, solution);
    return solution;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<vector<string>> nQueens = solveNQueens(4);
//     for (int i = 0; i < nQueens.size(); i++)
//     {
//         cout << "{";
//         for (int j = 0; j < nQueens[i].size(); j++)
//             cout << " " << nQueens[i][j];
//         cout << "}" << endl;
//     }
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------------------------- 37. Sudoku Solver --------------------------------------------------------------------------------
bool isValidMatrix(int row, int column, vector<vector<char>> &board, char data)
{
    for (int r = row; r < row + 3; r++)
    {
        for (int col = column; col < column + 3; col++)
        {
            if (board[r][col] == data)
            {
                return false;
            }
        }
    }
    return true;
}
bool isValidData(int row, int column, vector<vector<char>> &board, char data)
{
    // check row
    for (int col = 0; col < 9; col++)
    {
        if (board[row][col] == data)
            return false;
    }
    // check column
    for (int r = 0; r < 9; r++)
    {
        if (board[r][column] == data)
            return false;
    }
    // Check in 3*3 matrix
    int dummyRow = row;
    int dummyColumn = column;
    if (row >= 0 && row <= 2)
        dummyRow = 0;
    if (row >= 3 && row <= 5)
        dummyRow = 3;
    if (row >= 6 && row <= 8)
        dummyRow = 6;
    if (column >= 0 && column <= 2)
        dummyColumn = 0;
    if (column >= 3 && column <= 5)
        dummyColumn = 3;
    if (column >= 6 && column <= 8)
        dummyColumn = 6;
    if (!isValidMatrix(dummyRow, dummyColumn, board, data))
        return false;
    return true;
}
bool solveSudoku(vector<vector<char>> &board, int defaultRow = 0)
{
    for (int row = defaultRow; row < 9; row++)
    {
        for (int column = 0; column < 9; column++)
        {
            if (board[row][column] == '.')
            {
                for (int data = 1; data <= 9; data++)
                {
                    if (isValidData(row, column, board, data + 48))
                    {
                        board[row][column] = data + 48;
                        if (solveSudoku(board, row))
                            return true;
                        board[row][column] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<vector<char>> board = {
//         {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
//         {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
//         {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
//         {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
//         {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
//         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
//         {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
//         {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
//         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
//     solveSudoku(board);
//     for (int i = 0; i < 9; i++)
//     {
//         cout << "{";
//         for (int j = 0; j < 9; j++)
//         {
//             cout << board[i][j] << "  ";
//         }
//         cout << "}";
//         cout << endl;
//     }
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------------------------- 8. String to Integer (atoi) Revision --------------------------------------------------------------------------------
int myAtoiRevision(string s)
{
    double result = 0;
    int size = s.size();
    int index = 0;
    // 1. Whitespace: Ignore any leading whitespace (" ").
    while (s[index] == ' ')
    {
        index++;
    }
    // 2. Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
    bool isNegative = s[index] == '-';
    if (isNegative || s[index] == '+')
    {
        index++;
    }
    // 3. Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
    while (s[index] == '0')
    {
        index++;
    }
    while (s[index] >= '0' && s[index] <= '9')
    {
        result = (result * 10) + s[index] - '0';
        index++;
    }
    if (isNegative)
    {
        result *= -1;
    }
    // 4. Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
    result = result > INT_MAX ? INT_MAX : result;
    result = result < INT_MIN ? INT_MIN : result;
    return int(result);
}
int main()
{
    cout << string(30, '-') << endl;
    string s = "1337c0d3";
    cout << myAtoiRevision(s);
    cout << endl
         << string(30, '-') << endl;
    return 0;
}