// ALGORITHM
/*
MaxNestedIntervalLength(S)
{
    i <- 0
    until (i >= S.length())
    {
        j <- i + 1
        until (j >= S.length())
        {
            if (S[i][0] > S[i][0])
            {
                Swap (S[i], S[j])
            }
            j += 1
        }
        i += 1
    }
    a <- 2D array of max size n * 2
    i <- 0
    until (i >= S[i])
    {
        if (a.length() == 0 || (S[i][0] > a[a.length() - 1][0] && S[i][1] < a[a.length() - 1][0])
        {
            a.insert(S[i])
        }
        i += 1
    }
    return a.length()
}
*/

// CODE
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxNestedIntervalLength(vector<pair<int, int>> S)
{
    sort(S.begin(), S.end());
    vector<pair<int, int>> a;
    for (auto i : S)
        if (a.empty() || (i.first > a.back().first && i.second < a.back().second))
            a.push_back(i);
    return a.size();
}
int main()
{
    int i, n;
    cout << "No. of intervals (n): ";
    cin >> n;
    vector<pair<int, int>> S(n);
    cout << "n interval endpoints separated by space:\n";
    for (i = 0; i < n; i++)
        cin >> S[i].first >> S[i].second;
    int m = maxNestedIntervalLength(S);
    cout << "Maximum nested interval length: " << m << endl;
    return 0;
}
