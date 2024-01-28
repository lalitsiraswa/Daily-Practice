#include <bits/stdc++.h>
using namespace std;

// SPACE : number of nodes * number of nodes
void storeGraphInMatrix()
{
    int nodes, edges;
    cout << "Enter number of nodes :";
    cin >> nodes;
    cout << "Enter number of edges : ";
    cin >> edges;
    int adj[nodes + 1][nodes + 1];
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}
// SPACE : 2*number of edges
void storeGraphInList()
{
    int nodes, edges;
    cout << "Enter number of nodes :";
    cin >> nodes;
    cout << "Enter number of edges : ";
    cin >> edges;
    vector<int> adj[nodes + 1];
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void BFS()
{
    // int nodes, edges;
    // cout << "Enter number of nodes : ";
    // cin >> nodes;
    // cout << "Enter number of edges : ";
    // cin >> edges;
    // vector<int> adjacencyList[nodes + 1];
    // for (int i = 1; i <= edges; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     adjacencyList[u].push_back(v);
    //     adjacencyList[v].push_back(u);
    // }

    int nodes = 9, edges = 9;
    vector<int> adjacencyList[] = {{}, {2, 6}, {1, 3, 4}, {2}, {2, 5}, {4, 8}, {1, 7, 9}, {6, 8}, {7, 5}, {6}};
    // BFS BEGINS
    vector<int> isVisited(nodes + 1, 0);
    queue<int> que;
    que.push(1);
    isVisited[1] = 1;
    while (!que.empty())
    {
        int currNode = que.front();
        que.pop();
        cout << currNode << " ";
        for (int neighbour : adjacencyList[currNode])
        {
            if (!isVisited[neighbour])
            {
                que.push(neighbour);
                isVisited[neighbour] = 1;
            }
        }
    }
}

void DFS_RECURSION(int currNode, vector<int> *adjacencyList, vector<int> &isVisited)
{
    cout << currNode << " ";
    isVisited[currNode] = 1;
    for (int neighbour : adjacencyList[currNode])
    {
        if (!isVisited[neighbour])
            DFS_RECURSION(neighbour, adjacencyList, isVisited);
    }
}
void DFS()
{
    int nodes = 8, edges = 8;
    vector<int> adjacencyList[] = {{}, {2, 3}, {1, 5, 6}, {1, 4, 7}, {3, 8}, {2}, {2}, {3, 8}, {4, 7}};
    vector<int> isVisited(nodes + 1, 0);
    DFS_RECURSION(1, adjacencyList, isVisited);
}

// int main()
// {
//     DFS();
//     return 0;
// }
// ---------------------------------------------------------- Detect A Cycle In A UnDirected Grph Using BFS ----------------------------------------------------
bool BFS(vector<int> *adjacencyList)
{
    queue<int> que;
    vector<int> isVisited(8, 0);
    que.push(1);
    isVisited[1] = 1;
    while (!que.empty())
    {
        int node = que.front();
        cout << node << " ";
        que.pop();
        for (int neighbour : adjacencyList[node])
        {
            if (!isVisited[neighbour])
            {
                que.push(neighbour);
                isVisited[neighbour] = 1;
            }
        }
    }
    return true;
}
// ------------------------------------
bool detectCycle(int source, vector<int> *adjacencyList, int *isVisited)
{
    isVisited[source] = 1;
    queue<pair<int, int>> q;
    q.push({source, -1});
    while (!q.empty())
    {
        int node = q.front().first;
        cout << node << " ";
        int parent = q.front().second;
        q.pop();
        for (int neighbour : adjacencyList[node])
        {
            if (!isVisited[neighbour])
            {
                isVisited[neighbour] = 1;
                q.push({neighbour, node});
            }
            else if (parent != neighbour)
                return true;
        }
    }
    return false;
}
bool isCycleBFS(int V, vector<int> *adjacencyList)
{
    int isVisited[V] = {0};
    for (int i = 0; i < V; i++)
    {
        if (!isVisited[i])
        {
            if (detectCycle(i, adjacencyList, isVisited))
                return true;
        }
    }
    return false;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> adjacencyList[] = {{}, {2, 3}, {1, 5}, {1, 4, 6}, {3}, {2, 7}, {3, 7}, {5, 6}};
//     int V = 8;
//     isCycle(V, adjacencyList);
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ---------------------------------------------------------- Detect A Cycle In A UnDirected Grph Using DFS ----------------------------------------------------
bool DFS(int source, int parent, vector<int> *adjacencyList, int *isVisited)
{
    cout << source << " ";
    isVisited[source] = 1;
    for (int neighbour : adjacencyList[source])
    {
        if (!isVisited[neighbour])
        {
            if (DFS(neighbour, source, adjacencyList, isVisited))
                return true;
        }
        else if (neighbour != parent)
            return true;
    }
    return false;
}
bool isCycleDFS(int V, vector<int> *adjacencyList)
{
    int isVisited[V] = {0};
    for (int i = 0; i < V; i++)
    {
        if (!isVisited[i])
        {
            if (DFS(i, -1, adjacencyList, isVisited))
                return true;
        }
    }
    return false;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> adjacencyList[] = {{}, {2, 3}, {1, 5}, {1, 4, 6}, {3}, {2, 7}, {3, 7}, {5, 6}};
//     // vector<int> adjacencyList[] = {{0, 1}, {1, 2}, {1, 4}, {2, 3}, {3, 4}};
//     int V = 8;
//     cout << isCycleDFS(V, adjacencyList) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ---------------------------------------------------------- Detect A Cycle In A UnDirected Grph Using DFS ----------------------------------------------------
bool dfsCheck(int source, vector<int> *adjacencyList, int *isVisited, int *pathVisited)
{
    isVisited[source] = 1;
    pathVisited[source] = 1;
    for (int neighbour : adjacencyList[source])
    {
        // Whent the node is not visited
        if (!isVisited[neighbour])
        {
            if (dfsCheck(neighbour, adjacencyList, isVisited, pathVisited))
                return true;
        }
        // if the node has been previously visited
        // but it has to be visited on the same path
        else if (pathVisited[neighbour])
            return true;
    }
    pathVisited[source] = 0;
    return false;
}
bool isCycleDirectedGraph(int V, vector<int> *adjacencyList)
{
    int isVisited[V] = {0};
    int pathVisited[V] = {0};
    for (int i = 0; i < V; i++)
    {
        if (!isVisited[i])
        {
            if (dfsCheck(i, adjacencyList, isVisited, pathVisited))
                return true;
        }
    }
    return false;
}
// --------------- Cycle Detection - Kahn's Algorithm (Topological Sort | BFS) ---------------- 
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
//     vector<int> adjacencyList[] = {{2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {2, 9}, {10}, {8}};
//     int V = 11;
//     cout << isCycleDirectedGraph(V, adjacencyList) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }