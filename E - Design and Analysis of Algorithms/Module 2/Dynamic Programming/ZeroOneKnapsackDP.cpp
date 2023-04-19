//INPUT
/*
3
4
1 2 3
4 5 1
*/

//OUTPUT
/*
3
1 of 3
1
*/

//CODE
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int i, j, n, W, tw = 0;
    cin >> n >> W; //no. of items and knapsack capacity
    vector<int> v(n + 1), w(n + 1);
    vector<vector<int>> V(n + 1, vector<int>(W + 1));
    for (i = 1; i <= n; i++)
        cin >> v[i]; //read profits
    for (i = 1; i <= n; i++)
        cin >> w[i]; //read weights
    for (j = 0; j <= W; j++)
        V[0][j] = 0;
    for (i = 1; i <= n; i++)
        for (j = 0; j <= W; j++)
            if (w[i] <= j)
                V[i][j] = max(V[i - 1][j], v[i] + V[i - 1][j - w[i]]);
            else
                V[i][j] = V[i - 1][j];
    cout << V[n][W] << endl; //max profit
    for (i = n, j = W; i > 0 && j > 0; i--)
        if (V[i][j] != V[i - 1][j])
        {
            cout << w[i] << " of " << i << endl;
            j -= w[i];
            tw += w[i];
        }
    cout << tw << endl; //weight of knapsack
    return 0;
}