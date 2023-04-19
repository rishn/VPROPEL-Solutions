//INPUT
/*
11
a3 0 6
a1 1 4
a4 5 7
a2 3 5
a5 3 9
a11 12 16
a6 5 9
a9 8 12
a7 6 10
a8 8 11
a10 2 14
*/

//OUTPUT
/*
a1 a4 a8 a11 
*/

//CODE
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class activity
{
    public:
        string name;
        int start, finish;
        friend istream &operator>>(istream &, activity &);
        friend ostream &operator<<(ostream &, const activity &);
        bool operator<(const activity &) const;
};
istream &operator>>(istream &in, activity &a)
{
    in >> a.name >> a.start >> a.finish;
}
ostream &operator<<(ostream &out, const activity &a)
{
    out << a.name << " ";
}
bool activity::operator<(const activity &a) const
{
    return a.finish < finish;
}
void iterAS(priority_queue<activity> &pq, vector<activity> &v)
{
    activity a;
    a = pq.top();
    v.push_back(a);
    pq.pop();
    while (! pq.empty())
    {
        if (pq.top().start > a.finish)
        {
            a = pq.top();
            v.push_back(a);
        }
        pq.pop();
    }
}
int main()
{
    int i, n;
    cin >> n;
    activity a;
    priority_queue<activity> pq;
    vector<activity> v;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        pq.push(a);
    }
    iterAS(pq, v);
    for (auto a : v)
        cout << a;
    return 0;
}