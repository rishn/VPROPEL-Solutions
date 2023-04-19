//INPUT
/*
6
0 16 13 0 0 0 
0 0 10 12 0 0
0 4 0 0 14 0
0 0 9 0 0 20
0 0 0 7 0 4
0 0 0 0 0 0

6
0 10 0 10 0 0
0 0 4 2 8 0
0 0 0 0 0 10
0 0 0 0 9 0
0 0 6 0 0 10
0 0 0 0 0 0
*/

//OUTPUT
/*
The maximum possible flow is 23

The maximum possible flow is 19
*/

//CODE
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
bool pathBFS(vector<vector<int>> residualGraph, int s, int t, int parents[])
{
    int u, v, n = residualGraph.size();
    bool visited[n];
    memset(visited, 0, n);
    queue<int> q;
    //cout << "BFS called\n" << s << " ";
    q.push(s);
    visited[s] = true;
    parents[s] = -1;
    while (! q.empty())
    {
        u = q.front();
        q.pop();
        for (v = 0; v < n; v++)
            if (visited[v] == false && residualGraph[u][v] > 0)
            {
                parents[v] = u;
                if (v == t)
                {
                    //cout << endl;
                    return true;
                }
                //cout << v << " ";
                q.push(v);
                visited[v] = true;
            }
    }
    //cout << endl;
    return false;
}
int floydFulkerson(vector<vector<int>> graph, int s)
{
    int u, v, n = graph.size(), maxFlow = 0, parents[n];
    vector<vector<int>> residualGraph(graph);
    while (pathBFS(residualGraph, s, n - 1, parents))
    {
        int pathFlow = 10000;
        for (v = n - 1; v != s; v = parents[v])
        {
            //cout << v << " ";
            u = parents[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }
        //cout << endl;
        for (v = n - 1; v != s; v = parents[v])
        {
            u = parents[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }
        maxFlow += pathFlow;
    }
    return maxFlow;
}
int main()
{
    int i, j, n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> graph[i][j];
    cout << "The maximum possible flow is " << floydFulkerson(graph, 0) << endl;
    /*
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }
    */
   return 0;
}