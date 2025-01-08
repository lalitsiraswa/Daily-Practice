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
int main()
{
    cout << string(30, '-') << endl;
    vector<int> minCoins = minPartition(1000);
    for (auto item : minCoins)
    {
        cout << item << ", ";
    }
    cout << endl
         << string(30, '-');
}