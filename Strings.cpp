#include <bits/stdc++.h>
using namespace std;

// -------------------------------------------------------------- 1021. Remove Outermost Parentheses ------------------------------------------------------------------
string removeOuterParentheses(string s)
{
    int n = s.length();
    string result;
    int openBracketCount = 0, closeBracketCount = 0;
    for (int index = 0; index < n; index++)
    {
        if (s[index] == '(')
            openBracketCount += 1;
        else
            closeBracketCount += 1;
        if (openBracketCount == closeBracketCount)
        {
            openBracketCount = 0;
            closeBracketCount = 0;
            continue;
        }
        if (openBracketCount == 1)
            continue;
        result.push_back(s[index]);
    }
    return result;
}
// -----------------------
string removeOuterParentheses2(string s)
{
    int n = s.length();
    string result;
    int bracketCount = 0;
    for (int index = 0; index < n; index++)
    {
        if (s[index] == '(')
        {
            bracketCount += 1;
            if (bracketCount == 1)
                continue;
        }
        else
            bracketCount -= 1;
        if (bracketCount != 0)
            result.push_back(s[index]);
    }
    return result;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     string s = "(()())(())(()(()))";
//     cout << removeOuterParentheses2(s) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ----------------------------------------------------------------- 151. Reverse Words in a String ---------------------------------------------------------------------
string reverseWords(string s)
{
    int n = s.size();
    string result;
    string subString;
    int low = 0, high = n - 1;
    // Trim spaces from left and right end
    while (s[low] == ' ' || s[high] == ' ')
    {
        if (s[low] == ' ')
            low += 1;
        if (s[high] == ' ')
            high -= 1;
    }
    for (int index = low; index <= high; index++)
    {
        if (s[index] != ' ')
            subString.push_back(s[index]);
        else if (!subString.empty())
        {
            result = " " + subString + result;
            subString = "";
        }
    }
    result = subString + result;
    return result;
}
// ------------------------
string reverseWords2(string s)
{
    int n = s.size();
    string result;
    string subString;
    for (int index = 0; index < n; index++)
    {
        if (s[index] != ' ')
            subString.push_back(s[index]);
        else if (!subString.empty())
        {
            if (result.empty())
                result = subString;
            else
                result = subString + " " + result;
            subString = "";
        }
    }
    if (result.empty())
        return subString;
    if (!subString.empty())
        result = subString + " " + result;
    return result;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     // string s = "  hello world  ";
//     string s = "EPY2giL";
//     cout << reverseWords2(s) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ----------------------------------------------------------------- 1903. Largest Odd Number in String ---------------------------------------------------------------------
string largestOddNumber(string num)
{
    int n = num.size();
    int high = n - 1;
    while (high >= 0)
    {
        if ((num[high] - '0') % 2 != 0)
            break;
        high--;
    }
    int low = 0;
    return num.substr(0, high + 1);
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     // string num = "52";
//     // string num = "4206";
//     string num = "35427";
//     cout << largestOddNumber(num) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ------------------------------------------------------------------- 14. Longest Common Prefix ----------------------------------------------------------------------
string longestCommonPrefix(vector<string> &strs)
{
    string longestCommonPrefix;
    for (int i = 0; i < strs[0].size(); i++)
    {
        for (int j = 1; j < strs.size(); j++)
        {
            if (strs[j].size() - 1 >= i)
            {
                if (strs[j][i] != strs[0][i])
                    return longestCommonPrefix;
            }
            else
                return longestCommonPrefix;
        }
        longestCommonPrefix.push_back(strs[0][i]);
    }
    return longestCommonPrefix;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<string> strs = {"flower", "flow", "flight"};
//     cout << longestCommonPrefix(strs) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ------------------------------------------------------------------- 14. Longest Common Prefix ----------------------------------------------------------------------
bool isIsomorphic(string s, string t)
{
    if (s.size() != t.size())
        return false;
    unordered_map<char, int> sFrequency;
    unordered_map<char, int> tFrequency;
    for (char ch : s)
        sFrequency[ch]++;
    for (char ch : t)
        tFrequency[ch]++;
    for (int index = 0; index < s.size(); index++)
    {
        if (sFrequency[s[index]] != tFrequency[t[index]])
            return false;
    }
    return true;
}
int main()
{
    cout << string(35, '-') << endl;
    string s = "paper";
    string t = "title";
    cout << isIsomorphic(s, t) << endl;
    cout << endl
         << string(35, '-');
    return 0;
}