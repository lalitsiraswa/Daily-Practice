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
// int main()
// {
//     cout << string(35, '-') << endl;
//     // string s = "tree";
//     string s = "Aabb";
//     cout << frequencySort3(s) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// --------------------------------------------------------------- 1614. Maximum Nesting Depth of the Parentheses ----------------------------------------------------------------------
int maxDepth(string s)
{
    int maximumDepth = 0;
    int openBracketCount = 0, closeBracketCount = 0;
    for (char &ch : s)
    {
        if (ch == '(')
        {
            openBracketCount += 1;
            maximumDepth = max(maximumDepth, openBracketCount - closeBracketCount);
        }
        if (ch == ')')
        {
            closeBracketCount += 1;
        }
    }
    return maximumDepth;
}
// -----------------
int maxDepth2(string s)
{
    int maximumDepth = 0;
    int openBracketCount = 0;
    for (char &ch : s)
    {
        if (ch == '(')
            openBracketCount += 1;
        if (ch == ')')
            openBracketCount -= 1;
        maximumDepth = max(maximumDepth, openBracketCount);
    }
    return maximumDepth;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     string s = "(1+(2*3)+((8)/4))+1";
//     cout << maxDepth2(s) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// --------------------------------------------------------------------- 13. Roman to Integer ----------------------------------------------------------------------------
int romanToInt(string s)
{
    unordered_map<char, int> mapper;
    mapper['I'] = 1;
    mapper['V'] = 5;
    mapper['X'] = 10;
    mapper['L'] = 50;
    mapper['C'] = 100;
    mapper['D'] = 500;
    mapper['M'] = 1000;
    int n = s.size();
    int index = 0;
    int result = 0;
    while (index < n)
    {
        if (index + 1 < n && s[index] == 'I' && (s[index + 1] == 'V' || s[index + 1] == 'X'))
        {
            result += (mapper[s[index + 1]] - mapper[s[index]]);
            index += 1;
        }
        else if (index + 1 < n && s[index] == 'X' && (s[index + 1] == 'L' || s[index + 1] == 'C'))
        {
            result += (mapper[s[index + 1]] - mapper[s[index]]);
            index += 1;
        }
        else if (index + 1 < n && s[index] == 'C' && (s[index + 1] == 'D' || s[index + 1] == 'M'))
        {
            result += (mapper[s[index + 1]] - mapper[s[index]]);
            index += 1;
        }
        else
        {
            result += mapper[s[index]];
        }
        index += 1;
    }
    return result;
}
// -----------------------------------
int romanToInt2(string s)
{
    int roman2Int[26] = {0};
    roman2Int['I' - 65] = 1;
    roman2Int['V' - 65] = 5;
    roman2Int['X' - 65] = 10;
    roman2Int['L' - 65] = 50;
    roman2Int['C' - 65] = 100;
    roman2Int['D' - 65] = 500;
    roman2Int['M' - 65] = 1000;
    int result = 0;
    for (int i = 0; i < s.size(); i++)
    {
        // Roman numerals are usually written largest to smallest from left to right.
        if ((i + 1) < s.size() && roman2Int[s[i] - 65] < roman2Int[s[i + 1] - 65])
        {
            result += roman2Int[s[i + 1] - 65] - roman2Int[s[i] - 65];
            i += 1;
        }
        else
            result += roman2Int[s[i] - 65];
    }
    return result;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     string s = "MCMXCIV";
//     cout << romanToInt2(s) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// --------------------------------------------------------------------- 8. String to Integer (atoi) ----------------------------------------------------------------------------
int myAtoi(string s)
{
    int n = s.size();
    double num = 0;
    int i = 0;
    while (s[i] == ' ')
        i++;
    bool positive = s[i] == '+';
    bool negative = s[i] == '-';
    positive == true ? i++ : i;
    negative == true ? i++ : i;
    while (i < n && s[i] >= '0' && s[i] <= '9')
    {
        num = (num * 10) + (s[i] - '0');
        i++;
    }
    num = negative ? -num : num;
    num = (num > INT_MAX) ? INT_MAX : num;
    num = (num < INT_MIN) ? INT_MIN : num;
    return int(num);
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     string s = "0-1";
//     cout << myAtoi(s) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// --------------------------------------------------------------------- Count number of substrings ----------------------------------------------------------------------------
// ---------- TLE ------------
long long int substrCount(string s, int k)
{
    unordered_set<char> st;
    long long int subStrCount = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        st.clear();
        string subString;
        for (int j = i; j < n; j++)
        {
            subString += s[j];
            st.insert(s[j]);
            if (st.size() == k)
                subStrCount++;
            else if (st.size() > k)
                break;
        }
    }
    return subStrCount;
}
// ------------ TLE ---------------
int subArray(string &s, int k)
{
    int n = s.size();
    // create an unordered map to store the count of each character in the current subarray
    unordered_map<char, int> map;
    // initialize variables for count of valid subarrays, start and end index of subarray
    int count = 0, start = 0, end = 0;
    // loop through the array from the start to end index
    while (end < n)
    {
        // add the current element to the map and increment its count
        map[s[end]]++;
        // if the number of distinct elements in the map is greater than k, move the start index and remove elements from the map
        while (map.size() > k)
        {
            // decrement the count of the element at the start index
            map[s[start]]--;
            // if the count of the element at the start index becomes 0, remove it from the map
            if (map[s[start]] == 0)
                map.erase(s[start]);
            // increment the start index to move the window
            start++;
        }
        // add the count of valid subarrays for the current subarray to the total count
        count += end - start + 1;
        // increment the end index to move the window
        end++;
    }
    // return the total count of valid subarrays
    return count;
}
long long int substrCount2(string s, int k)
{
    // return the count of subarrays with exactly k distinct elements minus the count of subarrays with less than k distinct elements
    return subArray(s, k) - subArray(s, k - 1);
}
// ----------- Correct One ------------
int countSubstring(string &s, int k)
{
    int low = 0;
    int high = 0;
    int n = s.size();
    // Array to store the frequency of characters
    int charFreq[26] = {0};
    // Variable to keep track of distinct characters
    int dist_count = 0;
    // Variable to store the final count
    long ans = 0;
    while (high < n)
    {
        charFreq[s[high] - 'a']++;
        // If the character becomes distinct, increment the distinct count
        if (charFreq[s[high] - 'a'] == 1)
            dist_count++;
        // Decreasing the window size to maintain at most k distinct characters
        while (dist_count > k)
        {
            charFreq[s[low] - 'a']--;
            // If the frequency becomes 0, decrement the distinct count
            if (charFreq[s[low] - 'a'] == 0)
                dist_count--;
            // Move the window's starting point to the right
            low++;
        }
        // Update the count by adding the current window size
        ans += (high - low) + 1;
        // Move the window's ending point to the right
        high++;
    }
    return ans;
}
long long int substrCount3(string s, int k)
{
    return countSubstring(s, k) - countSubstring(s, k - 1);
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     string s = "abaaca";
//     cout << substrCount3(s, 1) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ------------------------------
// Function to count the number of substrings with at most k distinct characters
int countSubstringsWithAtMostKDistinctChars(string &s, int k)
{
    int left = 0, right = 0, n = s.size(), distinctCount = 0, substringCount = 0;

    // Vector to store the frequency of characters in the current substring
    vector<int> charFrequency(26, 0);

    while (right < n)
    {
        int charIndex = s[right] - 'a';
        charFrequency[charIndex]++;

        // If the frequency becomes 1, it means a new distinct character is added
        if (charFrequency[charIndex] == 1)
        {
            distinctCount++;
        }

        // While the number of distinct characters exceeds k, move the left pointer
        while (distinctCount > k)
        {
            charFrequency[s[left] - 'a']--;

            // If the frequency becomes 0, it means a distinct character is removed
            if (charFrequency[s[left] - 'a'] == 0)
            {
                distinctCount--;
            }

            left++;
        }

        // Add the count of substrings with at most k distinct characters
        substringCount += (right - left + 1);

        // Move the right pointer to expand the window
        right++;
    }

    return substringCount;
}

// Function to count the number of substrings with exactly k distinct characters
int countSubstringsWithExactlyKDistinctChars(string str, int k)
{
    // Count substrings with at most k distinct characters
    int countAtMostK = countSubstringsWithAtMostKDistinctChars(str, k);

    // Count substrings with at most (k-1) distinct characters
    int countAtMostKMinus1 = countSubstringsWithAtMostKDistinctChars(str, k - 1);

    // The difference gives the count of substrings with exactly k distinct characters
    return countAtMostK - countAtMostKMinus1;
}

// int main()
// {
//     // Example usage
//     string inputString = "aacfssa";
//     int k = 3;
//     int result = countSubstringsWithExactlyKDistinctChars(inputString, k);
//     cout << "The number of substrings with exactly " << k << " distinct characters is: " << result << endl;
//     return 0;
// }
// --------------------------------------------------------------------- 1781. Sum of Beauty of All Substrings ----------------------------------------------------------------------------
int beautySum(string s)
{
    int n = s.size();
    int totalBeautySum = 0;
    for (int i = 0; i < n; i++)
    {
        unordered_map<char, int> charFrequency;
        for (int j = i; j < n; j++)
        {
            charFrequency[s[j]]++;
            int mostFrequent = INT_MIN;
            int leastFrequent = INT_MAX;
            for (auto item : charFrequency)
            {
                mostFrequent = max(mostFrequent, item.second);
                leastFrequent = min(leastFrequent, item.second);
            }
            totalBeautySum += mostFrequent - leastFrequent;
        }
    }
    return totalBeautySum;
}
int main()
{
    cout << string(35, '-') << endl;
    string s = "aabcbaa";
    cout << beautySum(s) << endl;
    cout << endl
         << string(35, '-');
    return 0;
}