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

int main()
{
    DFS();
    return 0;
}