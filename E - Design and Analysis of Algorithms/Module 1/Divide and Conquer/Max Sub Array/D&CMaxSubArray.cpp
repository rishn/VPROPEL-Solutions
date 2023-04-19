//INPUT
/*
8
-2 -3 4 -1 -2 1 5 -3
*/

//OUTPUT
/*
2 6 7
*/

//CODE
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
struct details
{
    int low, high, sum;
};
details findMCS(vector<int> a, int low, int mid, int high)
{
    int i, ml, mr, left = INT_MIN, right = INT_MIN, sum = 0;
    details d;
    for (i = mid; i >= low; i--)
    {
        sum += a[i];
        if (sum > left)
        {
            left = sum;
            ml = i;
        }
    }
    sum = 0;
    for (i = mid + 1; i <= high; i++)
    {
        sum += a[i];
        if (sum > right)
        {
            right = sum;
            mr = i;
        }
    }
    d.low = ml;
    d.high = mr;
    d.sum = left + right;
    return d;
}
details findMS(vector<int> a, int low, int high)
{
    details left, right, cross, res;
    if (low == high)
    {
        res.low = low;
        res.high = high;
        res.sum = a[low];
        return res;
    }
    int mid = (low + high) / 2;
    left = findMS(a, low, mid);
    right = findMS(a, mid + 1, high);
    cross = findMCS(a, low, mid, high);
    if (left.sum >= right.sum && left.sum >= cross.sum)
        return left;
    else if (right.sum >= left.sum && right.sum >= cross.sum)
        return right;
    else
        return cross;
}
int main()
{
    int i, n;
    cin >> n;
    vector<int> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    details d = findMS(a, 0, n - 1);
    cout << d.low << " " << d.high << " " << d.sum;
    return 0;
}