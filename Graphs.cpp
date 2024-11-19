#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------ BFS ------------------------------------------------
void bfs(map<char, vector<char>> &adjacencyList)
{
    queue<char> que;
    map<char, int> isVisited;
    que.push('A');
    isVisited['A'] = 1;
    while (!que.empty())
    {
        char top = que.front();
        que.pop();
        cout << top << " ";
        for (char neighbour : adjacencyList[top])
        {
            if (!isVisited[neighbour])
            {
                que.push(neighbour);
                isVisited[neighbour] = 1;
            }
        }
    }
    cout << endl;
}
void dfs(map<char, vector<char>> &adjacencyList, map<char, int> &isVisited, char node)
{
    if (isVisited[node])
        return;
    cout << node << " ";
    isVisited[node] = 1;
    for (char neighbour : adjacencyList[node])
    {
        if (!isVisited[neighbour])
        {
            dfs(adjacencyList, isVisited, neighbour);
        }
    }
}
bool detectCycle(map<char, vector<char>> &adjacencyList, map<char, int> &isVisited, map<char, int> &isPathVisited, char node)
{
    isVisited[node] = 1;
    isPathVisited[node] = 1;
    for (char neighbour : adjacencyList[node])
    {
        if (!isVisited[neighbour])
        {
            if (detectCycle(adjacencyList, isVisited, isPathVisited, neighbour))
                return true;
        }
        else if (isPathVisited[neighbour])
            return true;
    }
    isPathVisited[node] = 0;
    return false;
}
bool detectCycleBfs(int source, map<char, vector<char>> &adjacencyList, map<char, int> &isVisited)
{
    isVisited[source] = 1;
    queue<pair<char, char>> q;
    q.push({source, '.'});
    while (!q.empty())
    {
        char node = q.front().first;
        cout << node << " ";
        char parent = q.front().second;
        q.pop();
        for (char neighbour : adjacencyList[node])
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
// int main()
// {
//     cout << string(35, '-') << endl;
//     map<char, vector<char>> adjacencyList;
//     // adjacencyList['A'] = {'C', 'E'};
//     // adjacencyList['B'] = {'F'};
//     // adjacencyList['C'] = {'B', 'D', 'F'};
//     // adjacencyList['D'] = {'F'};
//     // adjacencyList['E'] = {'F'};
//     // adjacencyList['F'] = {};
//     // ----------------------------
//     // bfs(adjacencyList);
//     // map<char, int> isVisited;
//     // dfs(adjacencyList, isVisited, 'A');
//     // ----------------------------
//     map<char, int> isVisited;
//     map<char, int> isPathVisited;
//     // adjacencyList['A'] = {'B'};
//     // adjacencyList['B'] = {'A', 'C', 'D'};
//     // adjacencyList['C'] = {'B', 'E', 'D'};
//     // adjacencyList['D'] = {'B', 'C'};
//     // adjacencyList['E'] = {'C'};
//     // detectCycleBfs('A', adjacencyList, isVisited);
//     // -------------------------------
//     adjacencyList['A'] = {'B'};
//     adjacencyList['B'] = {'D'};
//     adjacencyList['C'] = {'B', 'E'};
//     adjacencyList['D'] = {'C'};
//     adjacencyList['E'] = {};
//     cout << detectCycle(adjacencyList, isVisited, isPathVisited, 'A');
//     cout << endl
//          << string(35, '-') << endl;
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
// -------------------------------
// int main()
// {
//     cout << string(35, '-') << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ---------------------------------------------------------------- 743. Network Delay Time ------------------------------------------------------------------
vector<int> dijkstraByQueueCall(vector<vector<vector<int>>> &adjacencyList, int n, int source)
{
    // Create a queue for storing the nodes as a pair {dist,node}
    // where dist is the distance from source to the node.
    queue<pair<int, int>> que;
    // Initialising distTo list with a large number to
    // indicate the nodes are unvisited initially.
    // This list contains distance from source to the nodes.
    vector<int> distTo(n + 1, INT_MAX);
    // Source initialised with dist=0.
    distTo[source] = 0;
    que.push(make_pair(0, source));
    // Now, pop the minimum distance node first from the min-heap
    // and traverse for all its adjacent nodes.
    while (!que.empty())
    {
        int node = que.front().second;
        int distance = que.front().first;
        que.pop();
        // Check for all adjacent nodes of the popped out
        // element whether the prev dist is larger than current or not.
        for (vector<int> item : adjacencyList[node])
        {
            int neighbour = item[0];
            int weight = item[1];
            if (distance + weight < distTo[neighbour])
            {
                distTo[neighbour] = distance + weight;
                // If current distance is smaller,
                // push it into the queue.
                que.push(make_pair(distance + weight, neighbour));
            }
        }
    }
    // Return the list containing shortest distances
    // from source to all the nodes.
    return distTo;
}
vector<int> dijkstraByPriorityQueueCall(vector<vector<vector<int>>> &adjacencyList, int n, int source)
{
    // Create a priority queue for storing the nodes as a pair {dist,node}
    // where dist is the distance from source to the node.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // Initialising distTo list with a large number to
    // indicate the nodes are unvisited initially.
    // This list contains distance from source to the nodes.
    vector<int> distTo(n + 1, INT_MAX);
    // Source initialised with dist=0.
    distTo[source] = 0;
    pq.push(make_pair(0, source));
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
                distTo[neighbour] = distance + weight;
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
int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<vector<vector<int>>> adjacencyList(n + 1);
    for (vector<int> time : times)
    {
        int source = time[0];
        int destination = time[1];
        int distance = time[2];
        adjacencyList[source].push_back({destination, distance});
    }
    vector<int> distance = dijkstraByPriorityQueueCall(adjacencyList, n, k);
    int totalMaximumTime = 0;
    for (int i = 1; i < distance.size(); i++)
    {
        if (distance[i] == INT_MAX)
            return -1;
        totalMaximumTime = max(totalMaximumTime, distance[i]);
    }
    return totalMaximumTime;
}
// -----------------
int NetworkDelayTimeOtherWay(vector<vector<int>> &times, int n, int k)
{
    unordered_map<int, vector<pair<int, int>>> adjacency;
    for (auto &time : times)
    {
        int src = time[0];
        int dst = time[1];
        int t = time[2];
        adjacency[src].push_back({dst, t});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, k});
    unordered_set<int> visited;
    int delays = 0;
    while (!pq.empty())
    {
        int time = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (visited.count(node))
            continue;
        visited.insert(node);
        delays = max(delays, time);
        vector<pair<int, int>> &neighbors = adjacency[node];
        for (auto &neighbor : neighbors)
        {
            int neighborNode = neighbor.first;
            int neighborTime = neighbor.second;
            if (!visited.count(neighborNode))
            {
                int newTime = time + neighborTime;
                pq.push({newTime, neighborNode});
            }
        }
    }
    if (visited.size() == n)
        return delays;
    return -1;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     // vector<vector<int>> times = {{2, 1, 1}, {3, 2, 1}, {3, 4, 2}};
//     vector<vector<int>> times = {{1, 2, 1}, {2, 3, 1}, {3, 5, 2}};
//     // vector<vector<int>> times = {{1, 2, 1}, {2, 3, 2}, {1, 3, 4}};
//     // vector<vector<int>> times = {{1, 2, 1}, {2, 1, 3}};
//     int n = 5, k = 1;
//     cout << networkDelayTime(times, n, k);
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ------------------------------------------------------------- Paths in Maze That Lead to Same Room ------------------------------------------------------------------
int IntersectionLength(unordered_set<int> &set1, unordered_set<int> &set2)
{
    int count = 0;
    for (int element : set1)
    {
        if (set2.find(element) != set2.end())
        {
            count++;
        }
    }
    return count;
}
int NumberOfPaths(int n, vector<vector<int>> &corridors)
{
    unordered_map<int, unordered_set<int>> neighbors;
    int cycles = 0;
    for (vector<int> &coridor : corridors)
    {
        int room1 = coridor[0];
        int room2 = coridor[1];
        neighbors[room1].insert(room2);
        neighbors[room2].insert(room1);
        cycles += IntersectionLength(neighbors[room1], neighbors[room2]);
    }
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<vector<int>> corridors = {{1, 2}, {5, 2}, {4, 1}, {2, 4}, {3, 1}, {3, 4}};
//     int n = 5;
//     cout << NumberOfPaths(n, corridors) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ------------------------------------------------------------------ 133. Clone Graph -------------------------------------------------------------------------------
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};
Node *cloneGraphBFS(Node *node)
{
    if (node == NULL)
        return NULL;
    unordered_map<int, Node *> isVisited;
    Node *newNode = new Node(node->val);
    isVisited[newNode->val] = newNode;
    queue<Node *> q;
    q.push(node);
    while (!q.empty())
    {
        Node *topNode = q.front();
        q.pop();
        for (Node *item : topNode->neighbors)
        {
            if (!isVisited[item->val])
            {
                Node *neighbour = new Node(item->val);
                isVisited[neighbour->val] = neighbour;
                isVisited[topNode->val]->neighbors.push_back(neighbour);
                q.push(item);
            }
            else
            {
                isVisited[topNode->val]->neighbors.push_back(isVisited[item->val]);
            }
        }
    }
    return newNode;
}
// -----------------
Node *cloneGraphDFSCall(Node *node, unordered_map<int, Node *> &isVisited)
{
    Node *newNode = new Node(node->val);
    isVisited[newNode->val] = newNode;
    for (Node *item : node->neighbors)
    {
        if (!isVisited[item->val])
        {
            Node *neighbor = cloneGraphDFSCall(item, isVisited);
            // newNode->neighbors.push_back(neighbor);
            isVisited[newNode->val]->neighbors.push_back(neighbor);
        }
        else
        {
            // newNode->neighbors.push_back(isVisited[item->val]);
            isVisited[newNode->val]->neighbors.push_back(isVisited[item->val]);
        }
    }
    return newNode;
}
Node *cloneGraphDFS(Node *node)
{
    if (node == NULL)
        return NULL;
    unordered_map<int, Node *> isVisited;
    return cloneGraphDFSCall(node, isVisited);
}
// -------------
Node *CloneHelper(Node *root, unordered_map<Node *, Node *> &nodesCompleted)
{
    if (root == nullptr)
        return nullptr;
    Node *cloneNode = new Node(root->val);
    nodesCompleted[root] = cloneNode;
    for (Node *p : root->neighbors)
    {
        Node *x = nodesCompleted[p];
        if (x == nullptr)
        {
            cloneNode->neighbors.push_back(CloneHelper(p, nodesCompleted));
        }
        else
        {
            cloneNode->neighbors.push_back(x);
        }
    }
    return cloneNode;
}
Node *cloneGraphDfs(Node *root)
{
    unordered_map<Node *, Node *> nodesCompleted;
    return CloneHelper(root, nodesCompleted);
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     Node *one = new Node(1);
//     Node *two = new Node(2);
//     Node *three = new Node(3);
//     Node *four = new Node(4);
//     one->neighbors.push_back(two);
//     one->neighbors.push_back(four);
//     two->neighbors.push_back(one);
//     two->neighbors.push_back(three);
//     three->neighbors.push_back(two);
//     three->neighbors.push_back(four);
//     four->neighbors.push_back(one);
//     four->neighbors.push_back(three);
//     Node *cloneNode = cloneGraphDFS(one);
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// -------------------------------------------------------------- Graph Valid Tree ------------------------------------------------------------------
// For the graph to be a valid tree, the number of edges must equal n−1.If the total number of edges is less than n−1, not all of the graph nodes
// are connected, which defies the property of a tree.Similarly, more edges will mean that there is a cycle in the graph;hence, it is not a tree.
bool isCycleDFSCall(int parent, int node, vector<int> &isVisited, vector<vector<int>> &adjacencyList)
{
    isVisited[node] = 1;
    for (int neighbour : adjacencyList[node])
    {
        if (!isVisited[neighbour])
        {
            if (isCycleDFSCall(node, neighbour, isVisited, adjacencyList))
                return true;
        }
        else if (parent != neighbour)
        {
            return true;
        }
    }
    return false;
}
bool validTree(int n, vector<vector<int>> &edges)
{
    vector<int> isVisited(n, 0);
    vector<vector<int>> adjacencyList(n);
    for (vector<int> edge : edges)
    {
        adjacencyList[edge[0]].push_back(edge[1]);
        adjacencyList[edge[1]].push_back(edge[0]);
    }
    bool isCycle = isCycleDFSCall(-1, 0, isVisited, adjacencyList);
    for (int i = 0; i < n; i++)
    {
        if (isVisited[i] == 0)
            return false;
    }
    return !isCycle;
}
// -----------------------------
bool validTreeBFS(int n, vector<vector<int>> &edges)
{
    vector<int> isVisited(n, 0);
    vector<vector<int>> adjacencyList(n);
    for (vector<int> edge : edges)
    {
        adjacencyList[edge[0]].push_back(edge[1]);
        adjacencyList[edge[1]].push_back(edge[0]);
    }
    queue<pair<int, int>> q;
    isVisited[0] = 1;
    q.push(make_pair(0, -1));
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
                q.push(make_pair(neighbour, node));
            }
            else if (parent != neighbour)
                return false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (isVisited[i] == 0)
            return false;
    }
    return true;
}
// -------------
bool ValidTreeOtherWay(int n, vector<vector<int>> &edges)
{
    if (edges.size() != n - 1)
    {
        return false;
    }
    vector<vector<int>> adjacency(n);
    for (const auto &edge : edges)
    {
        int x = edge[0];
        int y = edge[1];
        adjacency[x].push_back(y);
        adjacency[y].push_back(x);
    }
    unordered_set<int> visited;
    stack<int> stack;
    visited.insert(0);
    stack.push(0);
    while (!stack.empty())
    {
        int node = stack.top();
        stack.pop();
        for (int neighbor : adjacency[node])
        {
            if (visited.count(neighbor) > 0)
            {
                continue;
            }
            visited.insert(neighbor);
            stack.push(neighbor);
        }
    }
    return visited.size() == n;
}

int main()
{
    cout << string(35, '-') << endl;
    int n = 5;
    // vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {3, 4}};
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {3, 4}};
    cout << validTreeBFS(n, edges) << endl;
    cout << endl
         << string(35, '-');
    return 0;
}