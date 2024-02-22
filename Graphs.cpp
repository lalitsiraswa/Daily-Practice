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