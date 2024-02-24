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
int main()
{
    cout << string(35, '-') << endl;
    map<char, vector<char>> adjacencyList;
    // adjacencyList['A'] = {'C', 'E'};
    // adjacencyList['B'] = {'F'};
    // adjacencyList['C'] = {'B', 'D', 'F'};
    // adjacencyList['D'] = {'F'};
    // adjacencyList['E'] = {'F'};
    // adjacencyList['F'] = {};
    // ----------------------------
    // bfs(adjacencyList);
    // map<char, int> isVisited;
    // dfs(adjacencyList, isVisited, 'A');
    // ----------------------------
    map<char, int> isVisited;
    map<char, int> isPathVisited;
    // adjacencyList['A'] = {'B'};
    // adjacencyList['B'] = {'A', 'C', 'D'};
    // adjacencyList['C'] = {'B', 'E', 'D'};
    // adjacencyList['D'] = {'B', 'C'};
    // adjacencyList['E'] = {'C'};
    // detectCycleBfs('A', adjacencyList, isVisited);
    // -------------------------------
    adjacencyList['A'] = {'B'};
    adjacencyList['B'] = {'D'};
    adjacencyList['C'] = {'B', 'E'};
    adjacencyList['D'] = {'C'};
    adjacencyList['E'] = {};
    cout << detectCycle(adjacencyList, isVisited, isPathVisited, 'A');
    cout << endl
         << string(35, '-') << endl;
}
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
int main()
{
    cout << string(35, '-') << endl;
    // vector<vector<int>> times = {{2, 1, 1}, {3, 2, 1}, {3, 4, 2}};
    vector<vector<int>> times = {{1, 2, 1}, {2, 3, 1}, {3, 5, 2}};
    // vector<vector<int>> times = {{1, 2, 1}, {2, 3, 2}, {1, 3, 4}};
    // vector<vector<int>> times = {{1, 2, 1}, {2, 1, 3}};
    int n = 5, k = 1;
    cout << networkDelayTime(times, n, k);
    cout << endl
         << string(35, '-');
    return 0;
}