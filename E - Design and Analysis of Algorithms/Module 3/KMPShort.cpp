#include <iostream>
#include <string>
#include <vector>
using namespace std;
void KMPMatcher(string T, string P)
{
    int m, n, q, i;
    n = T.length();
    m = P.length();
    vector<int> pi(m, -1);
    q = - 1;
    for (i = 0; i < n; i++)
    {
        while ((q >= 0) && P[q + 1] != T[i])
            q = pi[q];
        if (P[q + 1] == T[i])
            q += 1;
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
    int i;
    cin >> T >> P;
    KMPMatcher(T, P);
}
