#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <cassert>
using namespace std;

// ------------------------------------------------------------ Reverse a string using Stack --------------------------------------------------
void reverseUsingStack(string &str)
{
    stack<char> s;
    for (char ch : str)
        s.push(ch);
    for (int i = 0; i < str.size(); i++)
    {
        str[i] = s.top();
        s.pop();
    }
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     string str = "Educative";
//     reverseUsingStack(str);
//     for (auto item : str)
//         cout << item << " ";
//     cout << endl
//          << string(35, '-') << endl;
//     return 0;
// }
// -------------------------------------------------------------- 224. Basic Calculator ---------------------------------------------------------------
int Calculator(string expression)
{
    stack<int> s;
    int result = 0, number = 0, sign = 1;
    for (int i = 0; i < expression.size(); i++)
    {
        char ch = expression[i];
        if (ch >= 48 && ch <= 57)
        {
            number = 10 * number + (ch - 48);
        }
        else if (ch == '+')
        {
            result += sign * number;
            number = 0;
            sign = 1;
        }
        else if (ch == '-')
        {
            result += sign * number;
            number = 0;
            sign = -1;
        }
        else if (ch == '(')
        {
            // we push the result first, then sign;
            s.push(result);
            s.push(sign);
            // reset the sign and result for the value in the parenthesis
            sign = 1;
            result = 0;
        }
        else if (ch == ')')
        {
            result += sign * number;
            number = 0;
            result *= s.top(); // stack.pop() is the sign before the parenthesis
            s.pop();
            result += s.top(); // stack.pop() now is the result calculated before the parenthesis
            s.pop();
        }
    }
    if (number != 0)
        result += sign * number;
    return result;
}
// ----------------
int Calculator2(string expression)
{
    int number = 0;
    int sign = 1;
    int output = 0;
    stack<int> operationsStack;
    for (int i = 0; i < expression.length(); i++)
    {
        char c = expression[i];
        if (c >= 48 && c <= 57)
        {
            number = number * 10 + (int(c) - 48);
        }
        else if (c == '-' || c == '+')
        {
            output += number * sign;
            if (c == '-')
                sign = -1;
            else
                sign = 1;
            number = 0;
        }
        else if (c == '(')
        {
            operationsStack.push(output);
            operationsStack.push(sign);
            output = 0;
            sign = 1;
        }
        else if (c == ')')
        {
            output += sign * number;
            int popSignValue = operationsStack.top();
            operationsStack.pop();
            output *= popSignValue;
            int secondVal = operationsStack.top();
            operationsStack.pop();
            output += secondVal;
            number = 0;
        }
    }
    return output + number * sign;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     string expression = "(8+100)+(13-8-(2+1))";
//     cout << Calculator(expression);
//     cout << endl
//          << string(35, '-') << endl;
//     return 0;
// }
// ---------------------------------------------------------- 1047. Remove All Adjacent Duplicates In String ----------------------------------------------------------
string removeDuplicates(string s)
{
    int n = s.size();
    stack<char> oddCharsStack;
    stack<char> evenCharsStack;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            evenCharsStack.push(s[i]);
        else
            oddCharsStack.push(s[i]);
        if (!evenCharsStack.empty() && !oddCharsStack.empty())
        {
            char oddTopChar = oddCharsStack.top();
            char evenTopChar = evenCharsStack.top();
            if (oddTopChar == evenTopChar)
            {
                oddCharsStack.pop();
                evenCharsStack.pop();
            }
        }
    }
    string result = "";
    while (!evenCharsStack.empty() || !oddCharsStack.empty())
    {
        if (!oddCharsStack.empty() && oddCharsStack.size() == evenCharsStack.size())
        {
            result = oddCharsStack.top() + result;
            oddCharsStack.pop();
        }
        if (!evenCharsStack.empty())
        {
            result = evenCharsStack.top() + result;
            evenCharsStack.pop();
        }
    }
    return result;
}
// ------------------
string removeDuplicatesOtherWay(string s)
{
    int n = s.size();
    stack<char> charStack;
    for (int i = 0; i < n; i++)
    {
        if (!charStack.empty() && charStack.top() == s[i])
            charStack.pop();
        else
            charStack.push(s[i]);
    }
    string result = "";
    while (!charStack.empty())
    {
        result = charStack.top() + result;
        charStack.pop();
    }
    return result;
}
// ---------------
string removeDuplicatesOtherWay2(string s)
{
    string result;
    for (char ch : s)
    {
        if (!result.empty() && result.back() == ch)
            result.pop_back();
        else
            result.push_back(ch);
    }
    return result;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     string s = "sadkkdassa";
//     // string s = "abbaaca";
//     // string s = "aaa";
//     cout << removeDuplicatesOtherWay2(s);
//     cout << endl
//          << string(35, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------------------- 1249. Minimum Remove to Make Valid Parentheses ------------------------------------------------------
string minRemoveToMakeValid(string s)
{
    string output;
    stack<char> bracketStack;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            bracketStack.push(s[i]);
        else if (s[i] == ')')
        {
            if (!bracketStack.empty())
                bracketStack.pop();
            else
                s[i] = '.';
        }
    }
    while (!bracketStack.empty())
    {
        bracketStack.pop();
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == ')')
            bracketStack.push(s[i]);
        else if (s[i] == '(')
        {
            if (!bracketStack.empty())
                bracketStack.pop();
            else
                s[i] = '.';
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] != '.')
            output.push_back(s[i]);
    }
    return output;
}
// ----------------------
string minRemoveToMakeValid2(string s)
{
    int n = s.size();
    string output;
    int openBracketCount = 0, closeBracketCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            openBracketCount++;
        else if (s[i] == ')')
        {
            if (openBracketCount > 0)
                openBracketCount--;
            else
                s[i] = '.';
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == ')')
            closeBracketCount++;
        else if (s[i] == '(')
        {
            if (closeBracketCount > 0)
                closeBracketCount--;
            else
                s[i] = '.';
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] != '.')
            output.push_back(s[i]);
    }
    return output;
}
// ----------------------
string minRemoveToMakeValid3(string s)
{
    int n = s.size();
    string output;
    stack<pair<char, int>> bracketStack;
    for (int index = 0; index < n; index++)
    {
        char ch = s[index];
        if (ch == '(')
            bracketStack.push(make_pair(ch, index));
        else if (ch == ')')
        {
            if (!bracketStack.empty() && bracketStack.top().first == '(')
                bracketStack.pop();
            else
                bracketStack.push({ch, index});
        }
    }
    while (!bracketStack.empty())
    {
        s[bracketStack.top().second] = '.';
        bracketStack.pop();
    }
    for (int index = 0; index < n; index++)
    {
        if (s[index] != '.')
            output.push_back(s[index]);
    }
    return output;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     string s = "ab)cca(spo)(sc(s)(";
//     // string s = "a)di(o)qw)";
//     // string s = "lee(t(c)o)de)";
//     // string s = "a)b(c)d";
//     // string s = "))((";
//     cout << minRemoveToMakeValid3(s);
//     cout << endl
//          << string(35, '-') << endl;
//     return 0;
// }
// ------------------------------------------------------------- Exclusive Execution Time of Functions -------------------------------------------------------------
vector<int> exclusiveTime(int n, vector<string> &logs)
{
    map<int, int> totalTime;
    vector<int> output(n, 0);
    stack<pair<int, pair<string, int>>> functionStack;
    int num = logs.size();
    for (int i = 0; i < num; i++)
    {
        string log = logs[i];
        string startOrEnd;
        int idOrTimeStamp = 0;
        pair<int, pair<string, int>> functionCall;
        int pointer = 1;
        for (int j = 0; j < log.size(); j++)
        {
            char ch = log[j];
            if (ch >= 48 && ch <= 57)
            {
                idOrTimeStamp = 10 * idOrTimeStamp + (ch - 48);
            }
            else if (ch >= 97 && ch <= 122)
            {
                startOrEnd.push_back(ch);
            }
            else
            {
                if (pointer == 1)
                    functionCall.first = idOrTimeStamp;
                else if (pointer == 2)
                    functionCall.second.first = startOrEnd;
                else if (pointer == 3)
                    functionCall.second.second = idOrTimeStamp;
                pointer++;
                startOrEnd.clear();
                idOrTimeStamp = 0;
            }
        }
        functionStack.push(functionCall);
    }
    return {};
}
// ------------------------
vector<int> exclusiveTime2(int n, vector<string> &logs)
{
    vector<int> result(n, 0);
    int num = logs.size();
    stack<pair<int, pair<string, int>>> logStack;
    for (int i = 0; i < num; i++)
    {
        string log = logs[i];
        string startOrEnd;
        int idOrTimeStamp = 0;
        int id, timeStamp;
        int pointer = 1;
        for (int j = 0; j < log.size(); j++)
        {
            char ch = log[j];
            if (ch >= 48 && ch <= 57)
                idOrTimeStamp = 10 * idOrTimeStamp + (ch - 48);
            else if (ch >= 97 && ch <= 122)
                startOrEnd.push_back(ch);
            else
            {
                if (pointer == 1)
                    id = idOrTimeStamp;
                pointer++;
                idOrTimeStamp = 0;
            }
        }
        if (pointer == 3)
            timeStamp = idOrTimeStamp;
        if (startOrEnd == "start")
            logStack.push({id, {startOrEnd, timeStamp}});
        else
        {
            pair<int, pair<string, int>> topLog = logStack.top();
            result[topLog.first] += (timeStamp - topLog.second.second + 1);
            logStack.pop();
            if (!logStack.empty())
                result[logStack.top().first] -= (timeStamp - topLog.second.second + 1);
        }
        startOrEnd.clear();
    }
    return result;
}
// -------------------------
class Log
{
public:
    int id;
    bool isStart;
    int time;
    Log(string content)
    {
        vector<string> log;
        string delimiter = ":";
        split(content, delimiter, log);
        id = stoi(log[0]);
        isStart = log[1] == "start";
        time = stoi(log[2]);
    }
    void split(string &content, string &delimiter, vector<string> &log)
    {
        regex rgx(delimiter);
        sregex_token_iterator iter(content.begin(), content.end(), rgx, -1);
        sregex_token_iterator end;
        while (iter != end)
        {
            log.push_back(*iter);
            ++iter;
        }
    }
};
vector<int> ExclusiveTime(int n, vector<string> logs)
{
    stack<Log> logStack;
    vector<int> result(n);
    for (string content : logs)
    {
        Log myEvent(content);
        if (myEvent.isStart)
        {
            logStack.push(myEvent);
        }
        else
        {
            Log myTop = logStack.top();
            logStack.pop();
            result[myTop.id] += (myEvent.time - myTop.time + 1);
            if (!logStack.empty())
            {
                result[logStack.top().id] -= (myEvent.time - myTop.time + 1);
            }
        }
    }
    return result;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     int n = 2;
//     // vector<string> logs = {"0:start:0", "1:start:2", "1:end:3", "2:start:4", "2:end:7", "0:end:8"};
//     // vector<string> logs = {"0:start:0", "1:start:2", "1:end:5", "0:end:6"};
//     // vector<string> logs = {"0:start:0", "0:start:2", "0:end:5", "0:start:6", "0:end:6", "0:end:7"};
//     vector<string> logs = {"0:start:0", "1:start:2", "1:end:5", "0:end:6"};
//     vector<int> result = ExclusiveTime(n, logs);
//     for (int total : result)
//         cout << total << " ";
//     cout << endl
//          << string(35, '-') << endl;
//     return 0;
// }
// ----------------------------------------------------------------

// int main()
// {
//     cout << string(35, '-') << endl;
//     int n = 2;
//     // vector<string> logs = {"0:start:0", "1:start:2", "1:end:3", "2:start:4", "2:end:7", "0:end:8"};
//     // vector<string> logs = {"0:start:0", "1:start:2", "1:end:5", "0:end:6"};
//     // vector<string> logs = {"0:start:0", "0:start:2", "0:end:5", "0:start:6", "0:end:6", "0:end:7"};
//     vector<string> logs = {"0:start:0", "1:start:2", "1:end:5", "0:end:6"};
//     vector<int> result = ExclusiveTime(n, logs);
//     for (int total : result)
//         cout << total << " ";
//     cout << endl
//          << string(35, '-') << endl;
//     return 0;
// }
// ----------------------------------------------------------- 232. Implement Queue using Stacks ---------------------------------------------------------
class MyQueue
{
private:
    stack<int> stck, que;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        while (!que.empty())
        {
            stck.push(que.top());
            que.pop();
        }
        que.push(x);
        while (!stck.empty())
        {
            que.push(stck.top());
            stck.pop();
        }
    }

    int pop()
    {
        int top = que.top();
        que.pop();
        return top;
    }

    int peek()
    {
        return que.top();
    }

    bool empty()
    {
        return que.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// int main()
// {
//     cout << string(35, '-') << endl;
//     MyQueue *obj = new MyQueue();

//     cout << endl
//          << string(35, '-') << endl;
//     return 0;
// }
// -------------------------------------------------------------- 20. Valid Parentheses -----------------------------------------------------------------
bool isValidParentheses(string s)
{
    stack<char> bracketStack;
    for (char bracket : s)
    {
        if (bracket == '(' || bracket == '{' || bracket == '[')
            bracketStack.push(bracket);
        else if (bracketStack.empty())
            return false;
        else if (bracket == ')' && bracketStack.top() == '(')
            bracketStack.pop();
        else if (bracket == '}' && bracketStack.top() == '{')
            bracketStack.pop();
        else if (bracket == ']' && bracketStack.top() == '[')
            bracketStack.pop();
        else
            return false;
    }
    return bracketStack.empty();
}
int main()
{
    cout << string(35, '-') << endl;
    // string s = "(){[{()}]}";
    // string s = "))){{}}}]]";
    // string s = "(]";
    // string s = "()";
    string s = "(])";
    cout << isValidParentheses(s) << endl;
    cout << endl
         << string(35, '-') << endl;
    return 0;
}