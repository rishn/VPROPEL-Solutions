//INPUT
/*
0 5 -1 10
-1 0 3 -1
-1 -1 0 1
-1 -1 -1 0
*/

//OUTPUT
/*
0	5	8	9	
INF	0	3	4	
INF	INF	0	1	
INF	INF	INF	0
*/

//CODE
#include <iostream>
using namespace std;
#define V 4
#define INF 99999
void printSolution(int dist[][V])
{
    cout << "The following matrix shows the shortest distances between every pair of vertices\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            if (dist[i][j] == INF)
                cout << "INF\t";
            else
                cout << dist[i][j] << "\t";
        cout << endl;
    }
}
void floydWarshall(int dist[][V])
{

    int i, j, k;
    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printSolution(dist);
}
int main()
{
    int graph[V][V];
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == -1)
                graph[i][j] = INF;
        }
    floydWarshall(graph);
    return 0;
}