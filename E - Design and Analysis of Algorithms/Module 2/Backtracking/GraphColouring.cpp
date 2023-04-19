//INPUT
/*
4
0 1 1 1 
1 0 1 0
1 1 0 1 
1 0 1 0 
*/

//OUTPUT
/*
Solution Exists:
Following are the assigned colors:
1 2 3 2 
*/

//CODE
#include <iostream>
#include <vector>
using namespace std;
void printSolution(vector<int> color)
{
	cout << "Solution Exists:\nFollowing are the assigned colors:\n";
	for (int i = 0; i < color.size(); i++)
		cout << color[i] << " ";
	cout << "\n";
}
int isSafe(vector<vector<int>> graph, vector<int> color)
{
    int V = graph.size();
	for (int i = 0; i < V; i++)
		for (int j = i + 1; j < V; j++)
			if (graph[i][j] && color[j] == color[i])
				return 0;
	return 1;
}
int graphColoring(vector<vector<int>> graph, int m, int i, vector<int> color)
{
	if (i == graph.size()) 
    {
		if (isSafe(graph, color))
        {
			printSolution(color);
			return 1;
		}
		return 0;
	}
	for (int j = 1; j <= m; j++)
    {
	    color[i] = j;
		if (graphColoring(graph, m, i + 1, color))
			return 1;
		color[i] = 0;
	}
	return 0;
}
int main()
{
    int i, j, m, V;
    cin >> V;
    m = V - 1;
	vector<vector<int>> graph(V, vector<int>(V));
    vector<int> color(V, 0);
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            cin >> graph[i][j];
    if (! graphColoring(graph, m, 0, color))
		cout << "Solution does not exist";
	return 0;
}