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
int main()
{
    cout << string(35, '-') << endl;
    string s = "(()())(())(()(()))";
    cout << removeOuterParentheses2(s) << endl;
    cout << endl
         << string(35, '-');
    return 0;
}