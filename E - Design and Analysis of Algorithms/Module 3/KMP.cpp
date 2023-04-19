#include <iostream>
#include <string>
#include <vector>
using namespace std;
void prefixFunction(string P, vector<int> pi)
{
    int m, q, k;
    m = P.length();
    pi[0] = -1;
    k = -1;
    for (q = 1; q < m; q++)
    {
        while (k >= 0 && P[k + 1] != P[q])
            k = pi[k];
        if (P[k + 1] == P[q])
            k += 1;
        pi[q] = k + 1;
    }
}
void KMPMatcher(string T, string P)
{
    int m, n, q, i;
    n = T.length();
    m = P.length();
    vector<int> pi(m, -1);
    prefixFunction(P, pi);
    for (i = 0; i < m; i++)
        cout << pi[i] << " ";
    cout << endl;
    q = -1;
    for (i = 0; i < n; i++)
    {
        while ((q >= 0) && P[q + 1] != T[i])
            q = pi[q];
        if (P[q + 1] == T[i])
            q ++;
        if (q == m - 1)
        {
            cout << "Pattern occurs at " << i - (m - 1) << endl;
            q = pi[q];
        }
    }
}
int main()
{
    string T, P;
    cin >> T >> P;
    KMPMatcher(T, P);
}