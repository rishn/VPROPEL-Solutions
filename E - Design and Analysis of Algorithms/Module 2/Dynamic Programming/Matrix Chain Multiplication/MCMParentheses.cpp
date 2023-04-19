// INPUT
/*
5
40 20 30 10 30
*/

// OUTPUT
/*
Table m:
24000	14000	26000	
0	6000	12000	
0	0	9000	
Table s:
0	1	1	3	
0	0	2	3	
0	0	0	3	
Min cost: 26000
Optimal parenthesization: ((A1(A2A3))A4)
*/

// CODE
#include <iostream>
#include <climits>
#include <vector>
using namespace std;
void MCO(vector<int> p, vector<vector<int>> &m,  vector<vector<int>> &s)
{
    int i, j, k, l, q, n = p.size();
    for (l = 2; l < n; l++)
        for (i = 1; i <= n - l; i++)
        {
            j = i + l - 1;
            m[i - 1][j - 1] = INT_MAX;
            for (k = i; k < j; k++)
            {
                q = m[i - 1][k - 1] + m[k][j - 1] + p[i - 1] * p[k] * p[j];
                if (q < m[i - 1][j - 1])
                {
                    m[i - 1][j - 1] = q;
                    s[i - 1][j - 1] = k;
                }
            }
        }
}
void printOP(vector<vector<int>> &s, int i, int j)
{
    if (i == j)
        cout << "A" << i;
    else
    {
        cout << "(";
        printOP(s, i, s[i - 1][j - 1]);
        printOP(s, s[i - 1][j - 1] + 1, j);
        cout << ")";
    }
}
int main()
{
    int i, j, n;
    cin >> n;
    vector<int> p(n);
    for (i = 0; i < n; i++)
        cin >> p[i];
    vector<vector<int>> m(n, vector<int>(n, 0)), s(n, vector<int>(n, 0));
    MCO(p, m, s);
    cout << "Table m:\n";
    for (i = 0; i < n - 2; i++)
    {
        for (j = 1; j < n - 1; j++)
            cout << m[i][j] << "\t";
        cout << endl;
    }
    cout << "Table s:\n";
    for (i = 0; i < n - 2; i++)
    {
        for (j = 0; j < n - 1; j++)
            cout << s[i][j] << "\t";
        cout << endl;
    }
    cout << "Min cost: " << m[0][n - 2] << endl;
    cout << "Optimal parenthesization: "; 
    printOP(s, 1, n - 1);
    return 0;
}