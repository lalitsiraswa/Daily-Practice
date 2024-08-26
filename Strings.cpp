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
    unordered_map<char, vector<int>> sTracker;
    unordered_map<char, vector<int>> tTracker;
    for (int i = 0; i < s.size(); i++)
    {
        sTracker[s[i]].push_back(i);
        tTracker[t[i]].push_back(i);
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (sTracker[s[i]] != tTracker[t[i]])
            return false;
    }
    return true;
}
// -----------------------------------
bool isIsomorphic2(string s, string t)
{
    if (s.size() != t.size())
        return false;
    // Check for the last index;
    unordered_map<char, int> sLastindexTracker;
    unordered_map<char, int> tLastindexTracker;
    for (int i = 0; i < s.size(); i++)
    {
        if (sLastindexTracker[s[i]] != tLastindexTracker[t[i]])
            return false;
        sLastindexTracker[s[i]] = i + 1;
        tLastindexTracker[t[i]] = i + 1;
    }
    return true;
}
// ------------------------------------
bool isIsomorphic3(string s, string t)
{
    if (s.size() != t.size())
        return false;
    unordered_map<char, int> sTracker;
    unordered_map<char, int> tTracker;
    for (int i = 0; i < s.size(); i++)
    {
        if (sTracker[s[i]] && sTracker[s[i]] != t[i])
            return false;
        if (tTracker[t[i]] && tTracker[t[i]] != s[i])
            return false;
        sTracker[s[i]] = t[i];
        tTracker[t[i]] = s[i];
    }
    return true;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     string s = "paper";
//     string t = "title";
//     // string s = "bbbaaaba";
//     // string t = "aaabbbba";
//     // string s = "badc";
//     // string t = "baba";
//     cout << isIsomorphic3(s, t) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ------------------------------------------------------------------- 796. Rotate String ----------------------------------------------------------------------
bool rotateString(string s, string goal)
{
    if (s.size() != goal.size())
        return false;
    int n = s.size();
    for (int index = 0; index < n; index++)
    {
        if (goal[index] == s[0])
        {
            int sIndex = 0;
            int goalIndex = index;
            while (sIndex < n)
            {
                if (s[sIndex] != goal[goalIndex % n])
                    break;
                sIndex++;
                goalIndex++;
            }
            if (sIndex == n)
                return true;
        }
    }
    return false;
}
// ---------------------
bool rotateString2(string s, string goal)
{
    if (s.size() != goal.size())
        return false;
    for (int index = 0; index < s.size(); index++)
    {
        if (s == goal)
            return true;
        s = s.substr(1) + s[0];
    }
    return false;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     string s = "abcde";
//     string goal = "cdeab";
//     // string s = "abcde";
//     // string goal = "abced";
//     cout << rotateString2(s, goal) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ------------------------------------------------------------------- 242. Valid Anagram ----------------------------------------------------------------------
bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
        return false;
    unordered_map<char, int> sFrequency;
    for (char ch : s)
        sFrequency[ch]++;
    for (char ch : t)
    {
        if (!sFrequency[ch])
            return false;
        sFrequency[ch]--;
    }
    return true;
}
// ------------------
bool isAnagram2(string s, string t)
{
    if (s.size() != t.size())
        return false;
    int sFrequency[26] = {0};
    for (char ch : s)
        sFrequency[ch - 'a']++;
    for (char ch : t)
    {
        if (!sFrequency[ch - 'a'])
            return false;
        sFrequency[ch - 'a']--;
    }
    return true;
}
// ------------------
bool isAnagram3(string s, string t)
{
    if (s.size() != t.size())
        return false;
    int characterCounter[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        characterCounter[s[i] - 'a']++;
        characterCounter[t[i] - 'a']--;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (characterCounter[s[i] - 'a'] != 0)
            return false;
    }
    return true;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     // string s = "anagram";
//     // string t = "nagaram";
//     string s = "ab";
//     string t = "a";
//     cout << isAnagram2(s, t) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// --------------------------------------------------------------- 451. Sort Characters By Frequency ----------------------------------------------------------------------
class CustomMapComparator
{
public:
    bool operator()(pair<char, int> &p1, pair<char, int> &p2)
    {
        return p1.second > p2.second;
    }
};
bool customMapperComparator(pair<char, int> &p1, pair<char, int> &p2)
{
    return p1.second > p2.second;
}
string frequencySort(string s)
{
    unordered_map<char, int> mapper;
    for (char &ch : s)
        mapper[ch]++;
    vector<pair<char, int>> mapperVect(mapper.begin(), mapper.end());
    sort(mapperVect.begin(), mapperVect.end(), CustomMapComparator());
    string result;
    for (auto &item : mapperVect)
        result += string(item.second, item.first);
    return result;
}
// ----------------- Counter & Bucket Sort ---------------------
string frequencySort2(string s)
{
    int n = s.size();
    unordered_map<char, int> mapper;
    for (char &ch : s)
        mapper[ch] += 1;
    // Since freq values are in range [0...n], so we can use Bucket Sort to achieve O(N) in Time Complexity
    vector<vector<char>> bucket(n + 1);
    for (auto item : mapper)
        bucket[item.second].push_back(item.first);
    string result;
    for (int frequency = n; frequency >= 1; frequency--)
    {
        for (char &ch : bucket[frequency])
            result.append(frequency, ch);
    }
    return result;
}
// -------------------------------
class MaxCharFrequencyComperator
{
public:
    bool operator()(const pair<char, int> &p1, const pair<char, int> &p2)
    {
        return p1.second <= p1.second;
    }
};
string frequencySort3(string str)
{
    int n = str.size();
    unordered_map<char, int> umap;
    string result;
    for (int index = 0; index < n; index++)
    {
        umap[str.at(index)]++;
    }
    priority_queue<pair<char, int>, vector<pair<char, int>>, MaxCharFrequencyComperator> pq(umap.begin(), umap.end());
    while (!pq.empty())
    {
        pair<char, int> topElement = pq.top();
        pq.pop();
        result.append(string(topElement.second, topElement.first));
    }
    return result;
}
int main()
{
    cout << string(35, '-') << endl;
    // string s = "tree";
    string s = "Aabb";
    cout << frequencySort3(s) << endl;
    cout << endl
         << string(35, '-');
    return 0;
}