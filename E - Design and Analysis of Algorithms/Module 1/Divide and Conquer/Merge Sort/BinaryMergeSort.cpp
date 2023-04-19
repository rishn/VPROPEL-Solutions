#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &a, int l, int m, int r)
{
    vector<int> la, ra;
    int i, j, k, ls = m - l + 1, rs = r - m;
    for (i = l; i < m + 1; i++)
        la.push_back(a[i]);
    for (i = m + 1; i < r + 1; i++)
        ra.push_back(a[i]);
    i = 0;
    j = 0;
    k = l;
    while (i < ls && j < rs)
        if (la[i] < ra[j])
        {
            a[k] = la[i];
            i++;
            k++;
        }
        else
        {
            a[k] = ra[j];
            j++;
            k++;
        }
    while (i < ls)
    {
        a[k] = la[i];
        i++;
        k++;
    }
    while (j < rs)
    {
        a[k] = ra[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int> &a, int l, int r)
{
    if (l == r)
        return;
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}
int main()
{
    int i, n;
    cin >> n;
    vector<int> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    mergeSort(a, 0, n - 1);
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}