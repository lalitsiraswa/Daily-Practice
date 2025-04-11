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
bool isCycle(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adjacencyList(V);
    for (auto edge : edges)
    {
        adjacencyList[edge[0]].push_back(edge[1]);
        adjacencyList[edge[1]].push_back(edge[0]);
    }
    vector<int> isVisited(V, 0);
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
bool detectCycle(int source, vector<vector<int>> &adjacencyList, vector<int> &isVisited)
{
    isVisited[source] = 1;
    queue<pair<int, int>> q;
    q.push({source, -1});
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (int neighbour : adjacencyList[node])
        {
            if (!isVisited[neighbour])
            {
                isVisited[neighbour] = 1;
                q.push({neighbour,
                        node});
            }
            else if (parent != neighbour)
                return true;
        }
    }
    return false;
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
// ------------------------------------
bool isCycle(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adjacencyList(V);
    for (auto edge : edges)
    {
        adjacencyList[edge[0]].push_back(edge[1]);
        adjacencyList[edge[1]].push_back(edge[0]);
    }
    vector<int> isVisited(V, 0);
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
bool DFS(int source, int parent, vector<vector<int>> &adjacencyList, vector<int> &isVisited)
{
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
// ---------------------------------------------------------- Detect A Cycle In A Directed Grph Using DFS ----------------------------------------------------
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
// ------------- GFG ---------------
bool isCyclic(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);
    for (auto &edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
    }
    vector<bool> visited(V, false);
    vector<bool> path(V, false);

    for (int i = 0; i < V; ++i)
    {
        if (dfs(i, visited, path, adj))
        {
            return true;
        }
    }
    return false;
}
bool dfs(int s, vector<bool> &visited, vector<bool> &path, vector<vector<int>> &adj)
{
    visited[s] = true;
    path[s] = true;

    for (int neighbor : adj[s])
    {
        if (path[neighbor])
        {
            return true;
        }
        else if (!visited[neighbor])
        {
            if (dfs(neighbor, visited, path, adj))
            {
                return true;
            }
        }
    }

    path[s] = false;
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
// -------------------------------------------------- Dijkstra's Algorithm - Using Priority Queue - C++ and Java - Part 1------------------------------------
vector<int> dijkstraUsingPQ(int V, vector<vector<int>> adjacencyList[], int S)
{
    // Create a priority queue for storing the nodes as a pair {dist,node}
    // where dist is the distance from source to the node.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // Initialising distTo list with a large number to
    // indicate the nodes are unvisited initially.
    // This list contains distance from source to the nodes.
    vector<int> distTo(V, INT_MAX);
    // Source initialised with dist=0.
    distTo[S] = 0;
    pq.push(make_pair(0, S));
    // Now, pop the minimum distance node first from the min-heap
    // and traverse for all its adjacent nodes.
    while (!pq.empty())
    {
        int node = pq.top().second;
        int distance = pq.top().first;
        pq.pop();
        // Check for all adjacent nodes of the popped out
        // element whether the prev dist is larger than current or not.
        for (vector<int> item : adjacencyList[node])
        {
            int neighbour = item[0];
            int weight = item[1];
            if (distance + weight < distTo[neighbour])
            {
                distTo[neighbour] = weight + distance;
                // If current distance is smaller,
                // push it into the queue.
                pq.push(make_pair(distance + weight, neighbour));
            }
        }
    }
    // Return the list containing shortest distances
    // from source to all the nodes.
    return distTo;
}
// ------------------------------
vector<int> dijkstraUsingQueue(int V, vector<vector<int>> adjacencyList[], int S)
{
    // Create a queue for storing the nodes as a pair {dist,node}
    // where dist is the distance from source to the node.
    queue<pair<int, int>> pq;
    // Initialising distTo list with a large number to
    // indicate the nodes are unvisited initially.
    // This list contains distance from source to the nodes.
    vector<int> distTo(V, INT_MAX);
    pq.push(make_pair(0, S));
    // Source initialised with dist=0.
    distTo[S] = 0;
    // Now, pop the minimum distance node first from the min-heap
    // and traverse for all its adjacent nodes.
    while (!pq.empty())
    {
        int node = pq.front().second;
        int distance = pq.front().first;
        pq.pop();
        // Check for all adjacent nodes of the popped out
        // element whether the prev dist is larger than current or not.
        for (vector<int> item : adjacencyList[node])
        {
            int neighbour = item[0];
            int weight = item[1];
            if (distance + weight < distTo[neighbour])
            {
                distTo[neighbour] = weight + distance;
                // If current distance is smaller,
                // push it into the queue.
                pq.push(make_pair(distance + weight, neighbour));
            }
        }
    }
    // Return the list containing shortest distances
    // from source to all the nodes.
    return distTo;
}
// -------------------------------
vector<int> dijkstraUsingStack(int V, vector<vector<int>> adjacencyList[], int S)
{
    // Create a set ds for storing the nodes as a pair {dist,node}
    // where dist is the distance from source to the node.
    // set stores the nodes in ascending order of the distances
    set<pair<int, int>> st;
    // Initialising dist list with a large number to
    // indicate the nodes are unvisited initially.
    // This list contains distance from source to the nodes.
    vector<int> dist(V, INT_MAX);
    st.insert(make_pair(0, S));
    // Source initialised with dist=0
    dist[S] = 0;
    // Now, erase the minimum distance node first from the set
    // and traverse for all its adjacent nodes.
    while (!st.empty())
    {
        auto it = *(st.begin());
        int node = it.first;
        int distance = it.second;
        st.erase(it);
        // Check for all adjacent nodes of the erased
        // element whether the prev dist is larger than current or not.
        for (vector<int> item : adjacencyList[node])
        {
            int neighbour = item[0];
            int weight = item[1];
            if (distance + weight < dist[neighbour])
            {
                // erase if it was visited previously at
                // a greater cost.
                if (dist[neighbour] != INT_MAX)
                    st.erase(make_pair(dist[neighbour], neighbour));
                // If current distance is smaller,
                // push it into the queue
                dist[neighbour] = distance + weight;
                st.insert(make_pair(dist[neighbour], neighbour));
            }
        }
    }
    // Return the list containing shortest distances
    // from source to all the nodes.
    return dist;
}
// ---------------------------------------------------------------- BFS of graph ----------------------------------------------------------
// --------- The Below Code Is For Not-Connected Undirected Graph ----------
vector<int> bfsOfGraph(vector<vector<int>> &adj)
{
    int size = adj.size();
    vector<int> isVisited(size, 0);
    vector<int> result;
    queue<int> q;
    for (int i = 0; i < size; i++)
    {
        if (!isVisited[i])
        {
            q.push(i);
            isVisited[i] = 1;
            while (!q.empty())
            {
                int q_size = q.size();
                for (int index = 0; index < q_size; index++)
                {
                    int node = q.front();
                    q.pop();
                    result.push_back(node);
                    for (auto neighbour : adj[node])
                    {
                        if (!isVisited[neighbour])
                        {
                            isVisited[neighbour] = 1;
                            q.push(neighbour);
                        }
                    }
                }
            }
        }
    }
    return result;
}
// --------- The Below Code Is For Connected Undirected Graph ----------
vector<int> bfsOfGraphTUF(vector<vector<int>> &adj)
{
    int size = adj.size();
    vector<int> isVisited(size, 0);
    vector<int> bfs;
    queue<int> q;
    q.push(0);
    isVisited[0] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for (auto neighbour : adj[node])
        {
            if (!isVisited[neighbour])
            {
                isVisited[neighbour] = 1;
                q.push(neighbour);
            }
        }
    }
    return bfs;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<vector<int>> adjacencyList = {{0, 2}, {2, 1}, {0, 1}};
//     vector<int> result = bfsOfGraphTUF(adjacencyList);
//     for (auto item : result)
//         cout << item << ", ";
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ---------------------------------------------------------------- DFS of graph ----------------------------------------------------------
void dfsOfGraph(vector<vector<int>> &adj, int node, vector<int> &dfs, vector<int> &isVisited)
{
    dfs.push_back(node);
    isVisited[node] = 1;
    for (auto neighbour : adj[node])
    {
        if (!isVisited[neighbour])
        {
            dfsOfGraph(adj, neighbour, dfs, isVisited);
        }
    }
}
vector<int> dfsOfGraph(vector<vector<int>> &adj)
{
    int size = adj.size();
    vector<int> dfs;
    vector<int> isVisited(size, 0);
    dfsOfGraph(adj, 0, dfs, isVisited);
    return dfs;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<vector<int>> adjacencyList = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
//     vector<int> result = dfsOfGraph(adjacencyList);
//     for (auto item : result)
//         cout << item << ", ";
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ---------------------------------------------------------------- 547. Number of Provinces ----------------------------------------------------------
int findCircleNum(vector<vector<int>> &isConnected)
{
    int size = isConnected.size();
    vector<int> isVisisted(size, 0);
    int provincesCount = 0;
    queue<int> q;
    for (int i = 0; i < size; i++)
    {
        if (!isVisisted[i])
        {
            provincesCount += 1;
            q.push(i);
            isVisisted[i] = 1;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (int j = 0; j < size; j++)
                {
                    if (isConnected[node][j] && !isVisisted[j])
                    {
                        q.push(j);
                        isVisisted[j] = 1;
                    }
                }
            }
        }
    }
    return provincesCount;
}
// ---------------------------------
void findCircleNum(vector<vector<int>> &isConnected, vector<int> &isVisisted, int node)
{
    isVisisted[node] = 1;
    for (int j = 0; j < isConnected.size(); j++)
    {
        if (isConnected[node][j] && !isVisisted[j])
        {
            findCircleNum(isConnected, isVisisted, j);
        }
    }
}
int findCircleNumDfs(vector<vector<int>> &isConnected)
{
    int size = isConnected.size();
    vector<int> isVisisted(size, 0);
    int provincesCount = 0;
    for (int i = 0; i < size; i++)
    {
        if (!isVisisted[i])
        {
            provincesCount += 1;
            findCircleNum(isConnected, isVisisted, i);
        }
    }
    return provincesCount;
}
// ---------------------------------
void dfs(vector<vector<int>> &adj, vector<int> &isVisited, int node)
{
    isVisited[node] = 1;
    for (auto neighbour : adj[node])
    {
        if (!isVisited[neighbour])
        {
            dfs(adj, isVisited, neighbour);
        }
    }
}
int findCircleNumTUF(vector<vector<int>> &isConnected)
{
    int size = isConnected.size();
    vector<int> isVisisted(size, 0);
    vector<vector<int>> adj(size);
    int provincesCount = 0;
    // to change adjacency matrix to list
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            // self nodes are not considered
            if (isConnected[i][j] == 1 && i != j)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        // if the node is not visited
        if (!isVisisted[i])
        {
            // counter to count the number of provinces
            provincesCount += 1;
            dfs(adj, isVisisted, i);
        }
    }
    return provincesCount;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
//     cout << findCircleNumTUF(isConnected);
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ---------------------------------------------------------------- 200. Number of Islands ----------------------------------------------------------
void numIslandsBfs(vector<vector<char>> &grid, vector<vector<int>> &isVisited, int &i, int &j, int &m, int &n)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    isVisited[i][j] = 1;
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        int row = node.first;
        int column = node.second;
        // UP
        if (row > 0 && grid[row - 1][column] == '1' && isVisited[row - 1][column] == 0)
        {
            q.push({row - 1, column});
            isVisited[row - 1][column] = 1;
        }
        // DOWN
        if (row < m - 1 && grid[row + 1][column] == '1' && isVisited[row + 1][column] == 0)
        {
            q.push({row + 1, column});
            isVisited[row + 1][column] = 1;
        }
        // LEFT
        if (column > 0 && grid[row][column - 1] == '1' && isVisited[row][column - 1] == 0)
        {
            q.push({row, column - 1});
            isVisited[row][column - 1] = 1;
        }
        // RIGHT
        if (column < n - 1 && grid[row][column + 1] == '1' && isVisited[row][column + 1] == 0)
        {
            q.push({row, column + 1});
            isVisited[row][column + 1] = 1;
        }
    }
}
int numIslands(vector<vector<char>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> isVisited(m, vector<int>(n, 0));
    int islandCount = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!isVisited[i][j] && grid[i][j] == '1')
            {
                islandCount += 1;
                numIslandsBfs(grid, isVisited, i, j, m, n);
            }
        }
    }
    return islandCount;
}
// -----------------------------
void numIslandsDfs(vector<vector<char>> &grid, vector<vector<int>> &isVisited, int row, int column, int &m, int &n)
{
    isVisited[row][column] = 1;
    // UP
    if (row > 0 && grid[row - 1][column] == '1' && isVisited[row - 1][column] == 0)
    {
        numIslandsDfs(grid, isVisited, row - 1, column, m, n);
    }
    // DOWN
    if (row < m - 1 && grid[row + 1][column] == '1' && isVisited[row + 1][column] == 0)
    {
        numIslandsDfs(grid, isVisited, row + 1, column, m, n);
    }
    // LEFT
    if (column > 0 && grid[row][column - 1] == '1' && isVisited[row][column - 1] == 0)
    {
        numIslandsDfs(grid, isVisited, row, column - 1, m, n);
    }
    // RIGHT
    if (column < n - 1 && grid[row][column + 1] == '1' && isVisited[row][column + 1] == 0)
    {
        numIslandsDfs(grid, isVisited, row, column + 1, m, n);
    }
}
int numIslandsDfs(vector<vector<char>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> isVisited(m, vector<int>(n, 0));
    int islandCount = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!isVisited[i][j] && grid[i][j] == '1')
            {
                islandCount += 1;
                numIslandsDfs(grid, isVisited, i, j, m, n);
            }
        }
    }
    return islandCount;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<vector<char>> grid = {{'1', '1', '0', '0', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'}};
//     cout << numIslandsDfs(grid);
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ---------------------------------------------------------------- 733. Flood Fill ----------------------------------------------------------
void floodFill(vector<vector<int>> &image, vector<vector<int>> &isVisited, int row, int column, int color, int &m, int &n, int &targetColor)
{
    isVisited[row][column] = 1;
    image[row][column] = color;
    // UP
    if (row > 0 && image[row - 1][column] == targetColor && isVisited[row - 1][column] == 0)
    {
        floodFill(image, isVisited, row - 1, column, color, m, n, targetColor);
    }
    // DOWN
    if (row < m - 1 && image[row + 1][column] == targetColor && isVisited[row + 1][column] == 0)
    {
        floodFill(image, isVisited, row + 1, column, color, m, n, targetColor);
    }
    // LEFT
    if (column > 0 && image[row][column - 1] == targetColor && isVisited[row][column - 1] == 0)
    {
        floodFill(image, isVisited, row, column - 1, color, m, n, targetColor);
    }
    // RIGHT
    if (column < n - 1 && image[row][column + 1] == targetColor && isVisited[row][column + 1] == 0)
    {
        floodFill(image, isVisited, row, column + 1, color, m, n, targetColor);
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int m = image.size();
    int n = image[0].size();
    vector<vector<int>> isVisited(m, vector<int>(n, 0));
    int targetColor = image[sr][sc];
    floodFill(image, isVisited, sr, sc, color, m, n, targetColor);
    return image;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
//     vector<vector<int>> result = floodFill(image, 1, 1, 2);
//     for (auto row : result)
//     {
//         for (int data : row)
//         {
//             cout << data << ", ";
//         }
//     }
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ---------------------------------------------------------------- 994. Rotting Oranges ----------------------------------------------------------
int orangesRotting(vector<vector<int>> &grid)
{
    // figure out the grid size
    int m = grid.size();
    int n = grid[0].size();
    // store {{row, column}, time}
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> isVisited(m, vector<int>(n, 0));
    int countFresh = 0;
    for (int row = 0; row < m; row++)
    {
        for (int column = 0; column < n; column++)
        {
            // if cell contains rotten orange
            if (grid[row][column] == 2)
            {
                q.push({{row, column}, 0});
                // mark as visited (rotten) in visited array
                isVisited[row][column] = 2;
            }
            if (grid[row][column] == 1)
                countFresh += 1;
        }
    }
    int time = 0;
    // delta row and delta column
    int drow[] = {-1, 0, +1, 0};
    int dcol[] = {0, 1, 0, -1};
    int tempCountFresh = 0;
    // bfs traversal (until the queue becomes empty)
    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        time = max(time, t);
        q.pop();
        // exactly 4 neighbours
        for (int i = 0; i < 4; i++)
        {
            // neighbouring row and column
            int neighbourRow = r + drow[i];
            int neighbourCol = c + dcol[i];
            // check for valid cell and then for unvisited fresh orange
            if (neighbourRow >= 0 && neighbourRow < m && neighbourCol >= 0 && neighbourCol < n && isVisited[neighbourRow][neighbourCol] == 0 && grid[neighbourRow][neighbourCol] == 1)
            {
                // push in queue with timer increased
                q.push({{neighbourRow, neighbourCol}, t + 1});
                // mark as rotten
                isVisited[neighbourRow][neighbourCol] = 2;
                tempCountFresh++;
            }
        }
    }
    // if all oranges are not rotten
    if (tempCountFresh != countFresh)
        return -1;
    return time;
}
int main()
{
    cout << string(35, '-') << endl;
    vector<vector<int>> grid = {{0, 1, 2}, {0, 1, 1}, {2, 1, 1}};
    cout << orangesRotting(grid);
    cout << endl
         << string(35, '-');
    return 0;
}