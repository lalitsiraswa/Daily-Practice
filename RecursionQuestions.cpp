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
// -------------------------------
void subSequenceHelper(vector<int> &vect, int index, vector<int> &subSequence, int sum)
{
    if (sum == 0)
    {
        for (auto item : subSequence)
            cout << item << ", ";
        cout << endl;
    }
    if (index >= vect.size())
        return;
    if (vect[index] <= sum)
    {
        subSequence.push_back(vect[index]);
        subSequenceHelper(vect, index + 1, subSequence, sum - vect[index]);
        subSequence.pop_back();
    }
    else
    {
        subSequenceHelper(vect, index + 1, subSequence, sum - vect[index]);
    }
}
void printSubsequenceWithSumK(vector<int> &vect, int sum)
{
    for (int index = 0; index < vect.size(); index++)
    {
        if (vect[index] <= sum)
        {
            vector<int> subSequence = {vect[index]};
            subSequenceHelper(vect, index + 1, subSequence, sum - vect[index]);
        }
    }
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
int main()
{
    cout << string(30, '-') << endl;
    vector<int> vect = {1, 2, 3};
    vector<int> subSequence;
    bool isSubSequenceFound = false;
    printonlyOneSubSequenceWithSumK(vect, subSequence, 0, 3);
    cout << endl
         << string(30, '-') << endl;
    return 0;
}