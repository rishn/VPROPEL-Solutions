//INPUT
/*
5
7
0 3
3 2
2 1
1 0
0 2
2 4
4 1
*/

//OUTPUT
/*

*/

//CODE
#include <iostream>
using namespace std;
//Edge class
class Edge
{
    public:
        //Endpoints u and v of the Edge e
        int u, v;
        //Dummy constructor
        Edge()
        {

        };
        //Constructor for initiializing values
        Edge(int U, int V)
        {
            u = U;
            v = V;
        }

};
class MinCut
{
    public:
        //Declaring data members V, E, parent and rank
        int V, E, *parent, *rank;
        //Random module to get random integer values
        //Constructor
        MinCut(int v, int e)
        {
            V = v;
            E = e;
            parent = new int[V];
            rank = new int[V];
            //Initializing parents and ranks by is and 0s
            for (int i = 0; i < V; i++)
            {
                parent[i] = i;
                rank[i] = 0;
            }
        }
        //Function to find minimum cut
        int minCutKarger(Edge edges[])
        {
            int i, set1, set2, vertices = V, ans = 0; //Initializing answer minCut to 0
            //Iterating while vertices are > 2
            while (vertices > 2)
            {
                //Getting random integer in the range [0, E - 1]
                i = rand() % E;
                //Finding leader element to which edges[i].u belongs
                set1 = find(edges[i].u);
                //Finding leader element to which edges[i].v belongs
                set2 = find(edges[i].v);
                //If they do not belong to the same set
                if (set1 != set2)
                {
                    cout << "Contracting vertices " << edges[i].u << " and " << edges[i].v << endl;
                    //Merging vertives u and v into one
                    Union(edges[i].u, edges[i].v);
                    //Reducing count of vertices by 1
                    vertices--;
                }
            }
            //cout << "Edges needed to be removed -\n";
            for (i = 0; i < E; i++)
            {
                //Finding leader element to which edges[i].u belongs
                set1 = find(edges[i].u);
                //Finding leader element to which edges[i].v belongs
                set2 = find(edges[i].v);
                //If they do not belong to the same set
                if (set1 != set2)
                {
                    cout << edges[i].u << "<--->" << edges[i].v << endl;
                    //Increasing ans
                    ans++;
                }
            }
            return ans;
        }
        //Find function
        int find(int node)
        {
            //If node is the parent of itself then it's the tree leader
            if (node == parent[node])
                return node;
            //Else, finding parent and also compressing paths
            return parent[node] = find(parent[node]);
        }
        //Union function
        void Union(int u, int v)
        {
            //Make u as a leader of its tree
            u = find(u);
            //Make v as a leader of its tree
            v = find(v);
            //If u and v are not equal, because if they are equal then it means they are
            //already in same tree and it does not make sense to perform union operation
            if (u != v)
            {
                //Checking tree with smaller depth/height
                if (rank[u] < rank[v])
                    swap(u, v);
                //Attaching lower rank tree to higher one
                parent[v] = u;
                //If now ranks are equal increase rank of u
                if (rank[u] == rank[v])
                    rank[u]++;
            }
        }
};
int main()
{
    //Define V and E beforehand
    int i, u, v, V, E;
    cin >> V >> E;
    //Create an object of class MinCut
    MinCut minCut(V, E);
    Edge *edges = new Edge[E];
    for (i = 0; i < E; i++)
    {
        cin >> u >> v;
        edges[i] = Edge(u, v);
    }
    //Finding the size of the minimum cut
    //cout << "Count of edges needed to be removed = ";
    cout << minCut.minCutKarger(edges) << endl;
    return 0;
}