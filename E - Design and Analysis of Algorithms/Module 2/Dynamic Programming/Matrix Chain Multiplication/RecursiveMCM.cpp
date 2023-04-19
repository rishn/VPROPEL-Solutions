//INPUT
/*
3
10 20 30
*/

//OUTPUT
/*
6000
*/

//CODE
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int MCM(vector<int> p, int i, int j)
{
    if (i == j)
        return 0;
    int k, left, right, total, min = INT_MAX;
    for (k = i; k < j; k++)
    {
        left = MCM(p, i, k);
        right = MCM(p, k + 1, j);
        total = left + right + p[i - 1] * p[k] * p[j];
        if (min > total)
            min = total;
    }
    return min;
}
int main()
{
    int i, n;
    cin >> n;
    vector<int> p(n);
    for (i = 0; i < n; i++)
        cin >> p[i];
    cout << MCM(p, 1, n - 1); //prints minimum cost for multiplication
    return 0;
}