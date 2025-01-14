#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------------------------------------- 455. Assign Cookies ---------------------------------------------------------------------------
// TLE
int findContentChildren(vector<int> &g, vector<int> &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        int maxGreedyIndex = -1;
        for (int j = 0; j < g.size(); j++)
        {
            if (g[j] != -1 && s[i] >= g[j])
            {
                if (maxGreedyIndex == -1)
                {
                    maxGreedyIndex = j;
                }
                else
                {
                    maxGreedyIndex = g[j] > g[maxGreedyIndex] ? j : maxGreedyIndex;
                }
            }
        }
        if (maxGreedyIndex != -1)
        {
            g[maxGreedyIndex] = -1;
        }
    }
    int contentChildren = 0;
    for (int i = 0; i < g.size(); i++)
    {
        if (g[i] == -1)
        {
            contentChildren += 1;
        }
    }
    return contentChildren;
}
// -----------------------
int findContentChildrenTuf(vector<int> &greed, vector<int> &cookieSize)
{
    // Get the size of the greed array:
    int n = greed.size();
    // Get the size of the cookieSize array:
    int m = cookieSize.size();
    // Sort the greed factors in ascending order to try and satisfy the least greedy children first:
    sort(greed.begin(), greed.end());
    // Sort the cookie sizes in ascending order to use the smallest cookies first:
    sort(cookieSize.begin(), cookieSize.end());
    // Initialize a pointer for the cookieSize array, starting from the first cookie:
    int cookiePointer = 0;
    // Initialize a pointer for the greed array, starting fromthe first child:
    int greedPointer = 0;
    // Iterate while there are cookies and childrenleft to consider:
    while (greedPointer < n && cookiePointer < m)
    {
        // If the current cookie can satisfy the current child's greed:
        if (greed[greedPointer] <= cookieSize[cookiePointer])
        {
            // Move to the next child, as the current child is satisfied:
            greedPointer += 1;
        }
        // Always move to the next cookie whether the current child was satisfied or not:
        cookiePointer += 1;
    }
    // The value of r at the end of the loop represents the number of children that were satisfied:
    return greedPointer;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> greed = {1, 5, 3, 3, 4};
//     vector<int> cookieSize = {4, 2, 1, 2, 1, 3};
//     cout << findContentChildrenTuf(greed, cookieSize);
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------------- Fractional Knapsack ---------------------------------------------------------------------------
bool customComparator(pair<int, int> &a, pair<int, int> &b)
{
    double result1 = (double)a.first / (double)a.second;
    double result2 = (double)b.first / (double)b.second;
    return result1 > result2;
}
double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
{
    // vector<pair<value, weight>> items;
    vector<pair<int, int>> items;
    for (int index = 0; index < val.size(); index++)
    {
        items.push_back(pair<int, int>{val.at(index), wt.at(index)});
    }
    sort(items.begin(), items.end(), customComparator);
    int currentWeight = 0;
    double finalValue = 0.0;
    for (int index = 0; index < val.size(); index++)
    {
        if (currentWeight + items[index].second <= capacity)
        {
            currentWeight += items[index].second;
            finalValue += items[index].first;
        }
        else
        {
            int remain = capacity - currentWeight;
            finalValue += (items[index].first / (double)items[index].second) * (double)remain;
            break;
        }
    }
    return finalValue;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> val = {100, 60, 100, 200};
//     vector<int> wt = {20, 10, 50, 50};
//     int capacity = 90;
//     cout << fractionalKnapsack(val, wt, capacity);
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------------- Greedy algorithm to find minimum number of coins ---------------------------------------------------------------------------
vector<int> minPartition(int N)
{
    vector<int> currency = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    vector<int> minCurrency;
    int index = 0;
    while (index < currency.size())
    {
        if (currency[index] > N)
        {
            index++;
            continue;
        }
        minCurrency.push_back(currency[index]);
        N -= currency[index];
    }
    return minCurrency;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> minCoins = minPartition(1000);
//     for (auto item : minCoins)
//     {
//         cout << item << ", ";
//     }
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------------- 860. Lemonade Change ---------------------------------------------------------------------------
bool lemonadeChange(vector<int> &bills)
{
    unordered_map<int, int> dollerFrequency;
    for (int i = 0; i < bills.size(); i++)
    {
        dollerFrequency[bills[i]] += 1;
        int requiredChange = bills[i] - 5;
        while (requiredChange != 0)
        {
            // We always first check for the 10 then 5: try to dry-run the eg: [5, 5, 5, 10, 20], by
            // 1. once consider 10 as the first check then 5 as the other check and
            // 2. once consider 5 as the first check then 10 as the other check:
            if (10 <= requiredChange && dollerFrequency[10] > 0)
            {
                dollerFrequency[10] -= 1;
                requiredChange -= 10;
            }
            else if (5 <= requiredChange && dollerFrequency[5] > 0)
            {
                dollerFrequency[5] -= 1;
                requiredChange -= 5;
            }
            // If it is not possible to return the required change to the customer return false:
            else
            {
                return false;
            }
        }
    }
    return true;
}
// ----------------------
bool lemonadeChangeTuf(vector<int> &bills)
{
    // Initialize a counter for $5 bills:
    int dollerFiveCount = 0;
    // Initialize a counter for $10 bills:
    int dollerTenCount = 0;
    // Iterate through each customer's bill;
    for (int i = 0; i < bills.size(); i++)
    {
        // If the customer's bill is $5:
        if (bills[i] == 5)
        {
            // Increment the count of $5 bills:
            dollerFiveCount += 1;
        }
        // If the customer's bill is $10:
        else if (bills[i] == 10)
        {
            // Check if there are $5 bills available to give change:
            if (dollerFiveCount)
            {
                // Use one $5 bill to give change:
                dollerFiveCount -= 1;
                // Receive one $10 bill:
                dollerTenCount += 1;
            }
            // If no $5 bill available, return false:
            else
            {
                return false;
            }
        }
        // If the customer's bill is $20:
        else
        {
            // Check if there are both $5 and $10 bills available to give change:
            if (dollerFiveCount && dollerTenCount)
            {
                // Use one $5 bill:
                dollerFiveCount -= 1;
                // Use one $10 bill
                dollerTenCount -= 1;
            }
            // If there are not enough $10 bills, check if there are at least three $5 bills available:
            else if (dollerFiveCount >= 3)
            {
                // Use three $5 bills to give change:
                dollerFiveCount -= 3;
            }
            // If unable to give change, return false:
            else
            {
                return false;
            }
        }
    }
    // Return true if all customers are served with correct change:
    return true;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> bills = {5, 5, 5, 10, 20};
//     cout << lemonadeChangeTuf(bills);
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------------- 678. Valid Parenthesis String ---------------------------------------------------------------------------
bool checkValidString(string s, int index, int count, vector<vector<int>> &dp)
{
    if (count < 0)
    {
        return false;
    }
    if (index == s.size())
    {
        return dp[index][count] = count == 0;
    }
    if (dp[index][count] != -1)
    {
        return dp[index][count];
    }
    if (s[index] == '(')
    {
        return dp[index][count] = checkValidString(s, index + 1, count + 1, dp);
    }
    if (s[index] == ')')
    {
        return dp[index][count] = checkValidString(s, index + 1, count - 1, dp);
    }
    // s[index] == '*':
    return dp[index][count] = checkValidString(s, index + 1, count + 1, dp) || checkValidString(s, index + 1, count - 1, dp) || checkValidString(s, index + 1, count, dp);
}
bool checkValidString(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return dp[0][0];
}
// ------------------------
bool checkValidStringTabulation(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    for (int count = 0; count <= n; count++)
    {
        dp[n][count] = count == 0;
    }
    for (int index = n - 1; index >= 0; index--)
    {
        for (int count = 0; count <= n; count++)
        {
            int result = 0;
            if (s[index] == '(')
            {
                if (count < n)
                {
                    result = dp[index + 1][count + 1];
                }
            }
            else if (s[index] == ')')
            {
                if (count > 0)
                {
                    result = dp[index + 1][count - 1];
                }
            }
            // s[index] == '*':
            else
            {
                if (count < n)
                {
                    result = dp[index + 1][count + 1];
                }
                if (count > 0)
                {
                    result = result || dp[index + 1][count - 1];
                }
                result = result || dp[index + 1][count];
            }
            dp[index][count] = result;
        }
    }
    return dp[0][0];
}
// ------------------------
bool checkValidStringSpaceOptimization(string s)
{
    int n = s.size();
    vector<int> previous(n + 1, -1);
    for (int count = 0; count <= n; count++)
    {
        previous[count] = count == 0;
    }
    for (int index = n - 1; index >= 0; index--)
    {
        vector<int> current(n + 1, -1);
        for (int count = 0; count <= n; count++)
        {
            int result = 0;
            if (s[index] == '(')
            {
                if (count < n)
                {
                    result = previous[count + 1];
                }
            }
            else if (s[index] == ')')
            {
                if (count > 0)
                {
                    result = previous[count - 1];
                }
            }
            // s[index] == '*':
            else
            {
                if (count < n)
                {
                    result = previous[count + 1];
                }
                if (count > 0)
                {
                    result = result || previous[count - 1];
                }
                result = result || previous[count];
            }
            current[count] = result;
        }
        previous = current;
    }
    return previous[0];
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     string s = "(*()";
//     cout << checkValidStringSpaceOptimization(s);
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------------- Job Sequencing Problem ---------------------------------------------------------------------------
long long solve(vector<int> &bt)
{
    sort(bt.begin(), bt.end());
    int n = bt.size();
    vector<int> waitingTime(n);
    waitingTime[0] = 0;
    for (int index = 1; index < n; index++)
    {
        waitingTime[index] = waitingTime[index - 1] + bt[index - 1];
    }
    int totalWatingTime = accumulate(waitingTime.begin(), waitingTime.end(), 0);
    return totalWatingTime / n;
}
// -------------------
long long solveOtherWay(vector<int> &bt)
{
    sort(bt.begin(), bt.end());
    int n = bt.size();
    int totalWatingTime = 0;
    int currentWaitingTime = 0;
    int previousWaitingTime = 0;
    for (int index = 1; index < n; index++)
    {
        currentWaitingTime = previousWaitingTime + bt[index - 1];
        totalWatingTime += currentWaitingTime;
        previousWaitingTime = currentWaitingTime;
    }
    return totalWatingTime / n;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> burstTime = {4, 3, 7, 1, 2};
//     cout << solveOtherWay(burstTime);
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------------- 55. Jump Game ---------------------------------------------------------------------------
bool canJump(vector<int> &nums, int index, vector<int> &dp)
{
    if (index >= nums.size() - 1)
    {
        return true;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }
    for (int i = 1; i <= nums[index]; i++)
    {
        if (canJump(nums, index + i, dp))
        {
            return dp[index] = true;
        }
    }
    return dp[index] = false;
}
bool canJump(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return canJump(nums, 0, dp);
}
// --------------------------
bool canJumpTabulation(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[n - 1] = 1;
    for (int index = n - 2; index >= 0; index--)
    {
        bool result = false;
        for (int i = 1; i <= nums[index]; i++)
        {
            if (index + i < n)
            {
                result = result || dp[index + i];
            }
        }
        dp[index] = result;
    }
    return dp[0];
}
// --------------------------
bool canJumpTuf(vector<int> &nums)
{
    // Initialize the maximum index that can be reached:
    int maxIndex = 0;
    // Iterate through each index of the array:
    for (int index = 0; index < nums.size(); index++)
    {
        // If the current index is greater than the maximum reachable index
        // it means we cannot move forward and should return false:
        if (index > maxIndex)
        {
            return false;
        }
        // Update the maximum index that can be reached by comparing
        // the current maxIndex with the sum of the current index and the
        // maximum jump from that index:
        maxIndex = max(maxIndex, index + nums[index]);
    }
    // If we complete the loop, it means we can reach the last index:
    return true;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {1, 2, 4, 1, 10, 2, 5};
//     cout << canJumpTabulation(nums);
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------------- 45. Jump Game II ---------------------------------------------------------------------------
int jump(vector<int> &nums, int index, vector<int> &dp)
{
    if (index >= nums.size() - 1)
    {
        return 0;
    }
    if (nums[index] == 0)
    {
        return dp[index] = INT_MAX;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }
    int minJumps = INT_MAX;
    for (int i = 1; i <= nums[index]; i++)
    {
        int currentJumps = jump(nums, index + i, dp);
        if (currentJumps != INT_MAX && currentJumps + 1 < minJumps)
        {
            minJumps = currentJumps + 1;
        }
    }
    return dp[index] = minJumps;
}
int jump(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return jump(nums, 0, dp);
}
// ------------------------------
int jumpTabulation(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    dp[n - 1] = 0;
    for (int index = n - 2; index >= 0; index--)
    {
        int minJumps = INT_MAX;
        for (int i = 1; i <= nums[index]; i++)
        {
            if (index + i < n)
            {
                int currentJumps = dp[index + i];
                if (currentJumps != INT_MAX && currentJumps + 1 < minJumps)
                {
                    minJumps = currentJumps + 1;
                }
            }
        }
        dp[index] = minJumps;
    }
    return dp[0];
}
// ------------------------------
// Dry-Run the below examples
// [2, 3, 1, 4, 1, 1, 1, 2]
// [3, 4, 5, 2, 3, 1, 4, 2]
int jumpGreedy(vector<int> &nums)
{
    int minJumps = 0;
    int currentEnd = 0;
    int currentFarthest = 0;
    for (int index = 0; index < nums.size() - 1; index++)
    {
        currentFarthest = max(currentFarthest, index + nums[index]);
        if (index == currentEnd)
        {
            minJumps += 1;
            currentEnd = currentFarthest;
        }
    }
    return minJumps;
}

// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> nums = {2, 3, 1, 1, 4};
//     cout << jumpGreedy(nums);
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------------- Job Sequencing Problem ---------------------------------------------------------------------------
// A structure to represent a job :
struct Job
{
    // Job Id:
    int id;
    // Deadline of job:
    int deadline;
    // Profit if job is over before or on deadline:
    int profit;
    Job(int id, int deadline, int profit) : id(id), deadline(deadline), profit(profit) {};
};
bool jobComparator(Job a, Job b)
{
    return a.profit > b.profit;
}
vector<int> JobSequencing(vector<int> &id, vector<int> &deadline, vector<int> &profit)
{
    int n = id.size();
    vector<Job> jobs;
    for (int index = 0; index < n; index++)
    {
        jobs.push_back(Job(id[index], deadline[index], profit[index]));
    }
    // Now short the jobs based on the profit (descending order)
    sort(jobs.begin(), jobs.end(), jobComparator);
    // Find the max deadline
    int maxDeadline = 0;
    for (int index = 0; index < n; index++)
    {
        maxDeadline = max(maxDeadline, jobs[index].deadline);
    }
    vector<int> slotDays(maxDeadline + 1, -1);
    int countJobs = 0;
    int jobProfit = 0;
    for (int index = 0; index < jobs.size(); index++)
    {
        for (int day = jobs[index].deadline; day > 0; day--)
        {
            if (slotDays[day] == -1)
            {
                slotDays[day] = jobs[index].id;
                countJobs += 1;
                jobProfit += jobs[index].profit;
                break;
            }
        }
    }
    return {countJobs, jobProfit};
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> id = {1, 2, 3, 4};
//     vector<int> deadline = {4, 1, 1, 1};
//     vector<int> profit = {20, 1, 40, 30};
//     vector<int> result = JobSequencing(id, deadline, profit);
//     cout << "{" << result[0] << ", " << result[1] << "}";
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------------- N meetings in one room ---------------------------------------------------------------------------
struct Meeting
{
    int start;
    int end;
    int position;
    Meeting(int start, int end, int position) : start(start), end(end), position(position) {};
};
bool meetingComparator(Meeting &m1, Meeting m2)
{
    if (m1.end < m2.end)
        return true;
    else if (m1.end > m2.end)
        return false;
    else if (m1.position < m2.position)
        return true;
    return false;
}
int maxMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    vector<Meeting> meetings;
    for (int index = 0; index < n; index++)
    {
        meetings.push_back(Meeting(start[index], end[index], index + 1));
    }
    sort(meetings.begin(), meetings.end(), meetingComparator);
    vector<int> meetingOrder;
    int previousMeetingEndTime = meetings[0].end;
    meetingOrder.push_back(meetings[0].position);
    for (int index = 1; index < n; index++)
    {
        if (meetings[index].start > previousMeetingEndTime)
        {
            previousMeetingEndTime = meetings[index].end;
            meetingOrder.push_back(meetings[index].position);
        }
    }
    return meetingOrder.size();
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<int> start = {1, 3, 0, 5, 8, 5};
//     vector<int> end = {2, 4, 6, 7, 9, 9};
//     cout << maxMeetings(start, end);
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------------- 435. Non-overlapping Intervals ---------------------------------------------------------------------------
bool intervalComparator(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}
int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(), intervalComparator);
    vector<int> currentInterval = intervals[0];
    int eraseCount = 0;
    for (int index = 1; index < n; index++)
    {
        if (intervals[index][0] >= currentInterval[1])
        {
            currentInterval = intervals[index];
            continue;
        }
        eraseCount += 1;
    }
    return eraseCount;
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
//     cout << eraseOverlapIntervals(intervals);
//     cout << endl
//          << string(30, '-');
// }
// --------------------------------------------------------------------------- 57. Insert Interval ---------------------------------------------------------------------------
vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    int n = intervals.size();
    vector<vector<int>> result;
    int index = 0;
    while (index < n)
    {
        if (intervals[index][1] < newInterval[0])
        {
            result.push_back(intervals[index]);
            index += 1;
            continue;
        }
        break;
    }
    while (index < n)
    {
        if (intervals[index][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[index][0]);
            newInterval[1] = max(newInterval[1], intervals[index][1]);
            index += 1;
            continue;
        }
        break;
    }
    result.push_back(newInterval);
    while (index < n)
    {
        result.push_back(intervals[index]);
        index += 1;
    }
    return result;
}
// ----------------------
vector<vector<int>> insertOtherWay(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    int n = intervals.size();
    vector<vector<int>> result;
    for (int index = 0; index < n; index++)
    {
        if (intervals[index][1] < newInterval[0])
        {
            result.push_back(intervals[index]);
        }
        else if (intervals[index][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[index][0]);
            newInterval[1] = max(newInterval[1], intervals[index][1]);
        }
        else
        {
            result.push_back(newInterval);
            newInterval = intervals[index];
        }
    }
    result.push_back(newInterval);
    return result;
}
int main()
{
    cout << string(30, '-') << endl;
    vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval = {4, 8};
    intervals = insertOtherWay(intervals, newInterval);
    for (int i = 0; i < intervals.size(); i++)
    {
        cout << "{" << intervals[i][0] << ", " << intervals[i][1] << "}" << endl;
    }
    cout << endl
         << string(30, '-');
}