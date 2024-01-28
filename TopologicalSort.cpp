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
    // if (topologicalSortOrder.size() != adjacencyList.size())
    //     return {};
    while (!topologicalSortOrder.empty())
    {
        int node = topologicalSortOrder.top();
        topologicalSortOrder.pop();
        cout << node << " ";
    }
}
// -------------------------- Kahn’s algorithm for Topological Sorting -------------------
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
    // THERE IS A CYCLE
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
string FindDictionary(vector<string> &words)
{
    map<char, vector<char>> graph;
    map<char, int> inDegree;
    for (auto message : words)
    {
        for (auto c : message)
        {
            inDegree[c] = 0;
            graph[c] = {};
        }
    }
    for (int i = 0; i < words.size() - 1; i++)
    {
        string message1 = words[i];
        string message2 = words[i + 1];
        if (message1.size() > message2.size() && message1.find(message2) == 0)
            return "";
        for (int j = 0; j < min(message1.size(), message2.size()); j++)
        {
            if (message1[j] != message2[j])
            {
                graph[message1[j]].push_back(message2[j]);
                inDegree[message2[j]] = inDegree[message2[j]] + 1;
                break;
            }
        }
    }
    string result = "";
    queue<char> sourcesQueue;
    for (auto itr : inDegree)
    {
        char c = itr.first;
        if (itr.second == 0)
            sourcesQueue.push(c);
    }
    while (!sourcesQueue.empty())
    {
        char c = sourcesQueue.front();
        sourcesQueue.pop();
        result += c;
        for (char next : graph[c])
        {
            inDegree[next] = inDegree[next] - 1;
            if (inDegree[next] == 0)
                sourcesQueue.push(next);
        }
    }
    if (result.size() < inDegree.size())
        return "";
    return result;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<string> words = {"xro", "xma", "per", "pert", "oxh", "olv"};
//     cout << FindDictionary(words);
//     cout << endl;
//     cout << string(35, '-') << endl;
// }
// ------------------------------------------------------------- Alien Dictionary -----------------------------------------------------------------------
bool VerifyAlienDictionary(vector<string> &words, string order)
{
    int n = words.size();
    for (int i = 0; i < n - 1; i++)
    {
        string message1 = words[i];
        string message2 = words[i + 1];
        if (message1.size() > message2.size() && message1.find(message2) == 0)
            return false;
        for (int j = 0; j < min(message1.size(), message2.size()); j++)
        {
            if (message1[j] != message2[j])
            {
                int index01 = order.find(message1[j]);
                int index02 = order.find(message2[j]);
                if (index01 > index02)
                    return false;
                break;
            }
        }
    }
    return true;
}
// ----------------------
bool VerifyAlienDictionaryBestWay(vector<string> &words, string order)
{
    if (words.size() == 1)
        return true;
    unordered_map<char, int> map;
    for (int i = 0; i < order.size(); i++)
        map[order[i]] = i;
    for (int i = 0; i < words.size() - 1; i++)
    {
        for (int j = 0; j < words[i].size(); j++)
        {
            // case: words, word -> false
            if (j >= words[i + 1].size())
                return false;
            if (words[i][j] != words[i + 1][j])
            {
                if (map[words[i][j]] > map[words[i + 1][j]])
                    return false;
                break;
            }
        }
    }
    return true;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<string> words = {"hello", "word", "world"};
//     string order = "hwabcdefgijklmnopqrstuvxyz";
//     cout << VerifyAlienDictionaryBestWay(words, order);
//     cout << endl;
//     cout << string(35, '-') << endl;
// }
// ----------------------------------------------------------------- Course Schedule 1 & 2 ---------------------------------------------------------------------
bool canFinishBFS(int numCourses, vector<vector<int>> &prerequisites)
{
    map<int, vector<int>> graph;
    map<int, int> inDegree;
    vector<int> sortedOrder;
    for (int i = 0; i < prerequisites.size(); i++)
    {
        graph[prerequisites[i][0]] = {};
        graph[prerequisites[i][1]] = {};
        inDegree[prerequisites[i][0]] = 0;
        inDegree[prerequisites[i][1]] = 0;
    }
    for (int i = 0; i < prerequisites.size(); i++)
    {
        int parent = prerequisites[i][1];
        int child = prerequisites[i][0];
        graph[parent].push_back(child);
        inDegree[child] += 1;
    }
    queue<int> sources;
    for (auto &pairs : inDegree)
    {
        if (pairs.second == 0)
            sources.push(pairs.first);
    }
    while (!sources.empty())
    {
        int course = sources.front();
        sources.pop();
        sortedOrder.push_back(course);
        for (int i = 0; i < graph[course].size(); i++)
        {
            int child = graph[course][i];
            inDegree[child] -= 1;
            if (inDegree[child] == 0)
                sources.push(child);
        }
    }
    // THERE IS A CYCLE
    if (sortedOrder.size() != graph.size())
        return false;
    return true;
}
// -----------------------------------------
// BACKTRAKING
bool dfsRecursiveCheck(int course, vector<vector<int>> &adjacencyList, vector<int> &isVisited, vector<int> &pathVisited)
{
    isVisited[course] = 1;
    pathVisited[course] = 1;
    for (int neighbour : adjacencyList[course])
    {
        // Whent the node is not visited
        if (!isVisited[neighbour])
        {
            if (!dfsRecursiveCheck(neighbour, adjacencyList, isVisited, pathVisited))
                return false;
        }
        // if the node has been previously visited
        // but it has to be visited on the same path
        else if (pathVisited[neighbour])
            return false;
    }
    pathVisited[course] = 0;
    return true;
}
bool canFinishDFS(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adjacencyList(numCourses);
    vector<int> isVisited(numCourses, 0);
    vector<int> pathVisited(numCourses, 0);
    for (int i = 0; i < prerequisites.size(); i++)
    {
        int source = prerequisites[i][1];
        int neighbour = prerequisites[i][0];
        adjacencyList[source].push_back(neighbour);
    }
    for (int course = 0; course < numCourses; course++)
    {
        if (!isVisited[course])
        {
            if (!dfsRecursiveCheck(course, adjacencyList, isVisited, pathVisited))
                return false;
        }
    }
    return true;
}
// ------------------- Kahn's Algorithm ----------------------
bool canFinish_ByTopoSort(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adjacencylist(numCourses);
    vector<int> inDegree(numCourses, 0);
    for (int i = 0; i < prerequisites.size(); i++)
    {
        int source = prerequisites[i][1];
        int neighbour = prerequisites[i][0];
        adjacencylist[source].push_back(neighbour);
        inDegree[neighbour]++;
    }
    queue<int> sources;
    for (int i = 0; i < inDegree.size(); i++)
    {
        if (inDegree[i] == 0)
            sources.push(i);
    }
    vector<int> topoSort;
    while (!sources.empty())
    {
        int source = sources.front();
        topoSort.push_back(source);
        sources.pop();
        for (int neighbour : adjacencylist[source])
        {
            inDegree[neighbour] -= 1;
            if (inDegree[neighbour] == 0)
                sources.push(neighbour);
        }
    }
    // THERE IS A CYcle
    if (topoSort.size() != numCourses)
        return false;
    return true;
}
// --------- Course Schedule-2 ------------
vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adjacencylist(numCourses);
    vector<int> inDegree(numCourses, 0);
    for (int i = 0; i < prerequisites.size(); i++)
    {
        int source = prerequisites[i][1];
        int neighbour = prerequisites[i][0];
        adjacencylist[source].push_back(neighbour);
        inDegree[neighbour]++;
    }
    queue<int> sources;
    for (int i = 0; i < inDegree.size(); i++)
    {
        if (inDegree[i] == 0)
            sources.push(i);
    }
    vector<int> topoSort;
    while (!sources.empty())
    {
        int source = sources.front();
        topoSort.push_back(source);
        sources.pop();
        for (int neighbour : adjacencylist[source])
        {
            inDegree[neighbour] -= 1;
            if (inDegree[neighbour] == 0)
                sources.push(neighbour);
        }
    }
    // THERE IS A CYcle
    if (topoSort.size() != numCourses)
        return {};
    return topoSort;
}
// -------- USING DFS ------------
bool detectCycleByDFS(int course, vector<vector<int>> &adjacencyList, vector<int> &isVisited, vector<int> &pathVisited, stack<int> &topoSort)
{
    isVisited[course] = 1;
    pathVisited[course] = 1;
    for (int neighbour : adjacencyList[course])
    {
        if (!isVisited[neighbour])
        {
            if (detectCycleByDFS(neighbour, adjacencyList, isVisited, pathVisited, topoSort))
                return true;
        }
        else if (pathVisited[neighbour])
            return true;
    }
    pathVisited[course] = 0;
    topoSort.push(course);
    return false;
}
vector<int> findOrderDFS(int numCourses, vector<vector<int>> &prerequisites)
{
    stack<int> topoSort;
    vector<vector<int>> adjacencyList(numCourses);
    vector<int> isVisited(numCourses, 0);
    vector<int> pathVisited(numCourses, 0);
    for (int i = 0; i < prerequisites.size(); i++)
    {
        int source = prerequisites[i][1];
        int neighbour = prerequisites[i][0];
        adjacencyList[source].push_back(neighbour);
    }
    for (int course = 0; course < numCourses; course++)
    {
        if (!isVisited[course])
        {
            if (detectCycleByDFS(course, adjacencyList, isVisited, pathVisited, topoSort))
                return {};
        }
    }
    vector<int> topoSortOrder;
    while (!topoSort.empty())
    {
        topoSortOrder.push_back(topoSort.top());
        topoSort.pop();
    }
    return topoSortOrder;
}
int main()
{
    cout << string(35, '-') << endl;
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    findOrderDFS(numCourses, prerequisites);
    cout << endl;
    cout << string(35, '-') << endl;
}