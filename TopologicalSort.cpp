#include <bits/stdc++.h>
using namespace std;

// ----------------------------------------------------------------- TOPOLOGICAL SORT - INTRODUCTION -----------------------------------------------------------------
void DFS_RECURSION(int currNode, vector<int> *adjacencyList, vector<int> &isVisited, stack<int> &topologicalSortOrder)
{

    isVisited[currNode] = 1;
    for (int neighbour : adjacencyList[currNode])
    {
        if (!isVisited[neighbour])
        {
            DFS_RECURSION(neighbour, adjacencyList, isVisited, topologicalSortOrder);
        }
    }
    topologicalSortOrder.push(currNode);
}
void topologicalSort()
{
    vector<int> adjacencyList[] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
    vector<int> isVisited(6, 0);
    stack<int> topologicalSortOrder;
    for (int currNode = 0; currNode < 6; currNode++)
    {
        if (!isVisited[currNode])
        {
            DFS_RECURSION(currNode, adjacencyList, isVisited, topologicalSortOrder);
        }
    }
    while (!topologicalSortOrder.empty())
    {
        int node = topologicalSortOrder.top();
        topologicalSortOrder.pop();
        cout << node << " ";
    }
}
vector<char> TOPOLOGICAL_SORT(vector<vector<char>> &dependencies)
{
    vector<char> sortedOrder = {};
    map<char, vector<char>> graph;
    map<char, int> inDegree;
    for (int i = 0; i < dependencies.size(); i++)
    {
        inDegree[dependencies[i][0]] = 0;
        inDegree[dependencies[i][1]] = 0;
        graph[dependencies[i][0]] = {};
        graph[dependencies[i][1]] = {};
    }
    if (graph.size() == 0)
        return sortedOrder;
    for (int i = 0; i < dependencies.size(); i++)
    {
        char parent = dependencies[i][1];
        char child = dependencies[i][0];
        graph[parent].push_back(child);
        inDegree[child] += 1;
    }
    deque<char> sources;
    for (auto &pairs : inDegree)
    {
        if (pairs.second == 0)
            sources.push_back(pairs.first);
    }
    while (sources.size() > 0)
    {
        char vertex = sources.front();
        sources.pop_front();
        sortedOrder.push_back(vertex);
        for (int i = 0; i < graph[vertex].size(); i++)
        {
            char child = graph[vertex][i];
            inDegree[child] -= 1;
            if (inDegree[child] == 0)
                sources.push_back(child);
        }
    }
    if (sortedOrder.size() != graph.size())
        return {};
    return sortedOrder;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     topologicalSort();
//     cout << endl;
//     cout << string(35, '-') << endl;
// }
// ---------------------------------------------------------------------- Compilation Order ----------------------------------------------------------------------------
vector<char> FindCompilationOrder(vector<vector<char>> &dependencies)
{
    vector<char> sortedOrder = {};
    map<char, vector<char>> graph;
    map<char, int> inDegree;
    for (int i = 0; i < dependencies.size(); i++)
    {
        inDegree[dependencies[i][0]] = 0;
        inDegree[dependencies[i][1]] = 0;
        graph[dependencies[i][0]] = {};
        graph[dependencies[i][1]] = {};
    }
    if (graph.size() == 0)
        return sortedOrder;
    for (int i = 0; i < dependencies.size(); i++)
    {
        char parent = dependencies[i][1];
        char child = dependencies[i][0];
        graph[parent].push_back(child);
        inDegree[child] += 1;
    }
    deque<char> sources;
    for (auto &pairs : inDegree)
    {
        if (pairs.second == 0)
            sources.push_back(pairs.first);
    }
    while (sources.size() > 0)
    {
        char vertex = sources.front();
        sources.pop_front();
        sortedOrder.push_back(vertex);
        for (int i = 0; i < graph[vertex].size(); i++)
        {
            char child = graph[vertex][i];
            inDegree[child] -= 1;
            if (inDegree[child] == 0)
                sources.push_back(child);
        }
    }
    if (sortedOrder.size() != graph.size())
        return {};
    return sortedOrder;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<vector<char>> dependencies = {{'C', 'A'}, {'B', 'A'}, {'B', 'C'}, {'D', 'C'}, {'D', 'B'}, {'E', 'B'}, {'E', 'D'}};
//     vector<char> sortedOrder = FindCompilationOrder(dependencies);
//     for (auto item : sortedOrder)
//         cout << item << " ";
//     cout << endl;
//     cout << string(35, '-') << endl;
// }
// ------------------------------------------------------------- Alien Dictionary -----------------------------------------------------------------------
int main()
{
    cout << string(35, '-') << endl;
    vector<vector<char>> dependencies = {{'C', 'A'}, {'B', 'A'}, {'B', 'C'}, {'D', 'C'}, {'D', 'B'}, {'E', 'B'}, {'E', 'D'}};
    vector<char> sortedOrder = FindCompilationOrder(dependencies);
    for (auto item : sortedOrder)

        cout << item << " ";
    cout << endl;
    cout << string(35, '-') << endl;
}