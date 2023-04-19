#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &a, int n, int l, int m, int r)
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
void mergeSort(vector<int> &a, int n, int cs, int l, int r)
{
    if (l == r)
        return;
    int m = l + cs - 1;
    if (r - l == 1)
    {
        if (a[l] > a[r])
            swap(a[l], a[r]);
        return;
    }
    mergeSort(a, n, cs, l, m);
    mergeSort(a, n, cs, m + 1, r);
    merge(a, n, l, m, r);
}
int main()
{
    int i, n, cs;
    cin >> n >> cs;
    vector<int> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    mergeSort(a, n, cs, 0, n - 1);
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}