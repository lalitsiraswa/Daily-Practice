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
int main()
{
    cout << string(35, '-') << endl;
    // string num = "52";
    // string num = "4206";
    string num = "35427";
    cout << largestOddNumber(num) << endl;
    cout << endl
         << string(35, '-');
    return 0;
}