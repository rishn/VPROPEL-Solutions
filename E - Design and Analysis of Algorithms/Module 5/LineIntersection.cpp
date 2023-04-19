// INPUT
/*
4
0 0
5 5
2 -10
3 10
1 1
10 1
1 2
10 2
10 0
0 10
0 0
10 10
-5 -5
0 0 
1 1
10 10
*/

// OUTPUT
/*
Lines are intersecting
Lines are not intersecting
Lines are intersecting
Lines are not intersecting

*/

// CODE
#include <iostream>
using namespace std;
struct point
{
    int x, y;
};
void readPoint(point &p)
{
    cin >> p.x >> p.y;
}
int onLine(point a, point b, point p)
{ // check whether p is on the line or not
    return p.x <= max(a.x, b.x) && p.x >= min(a.x, b.x) &&
            (p.y <= max(a.y, b.y) && p.y >= min(a.y, b.y));
}
int direction(point a, point b, point c)
{
    int dir = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    return dir ? (dir < 0 ? 2 : 1) : 0;
    // anti-clockwise direction // clockwise direction // colinear
}
int doIntersect(point a1, point b1, point a2, point b2)
{
    // four directions for two lines and points of other line
    int d1 = direction(a1, b1, a2), d2 = direction(a1, b1, b2), d3 = direction(a2, b2, a1), d4 = direction(a2, b2, b1);
    return (d1 != d2 && d3 != d4) || ((! d1) && onLine(a1, b1, a2)) ||
            ((! d2) && onLine(a1, b1, b2)) || ((! d3) && onLine(a2, b2, a1)) || 
            ((! d4) && onLine(a2, b2, b1)); 
    // they are intersecting / a of line2 on line1 / b of line2 on line1 / a of line1 on line2 / b of line1 on line2
}
int main()
{
    int i, n;
    cin >> n;
    point a1, b1, a2, b2;
    for (i = 0; i < n; i++)
    {
        readPoint(a1);
        readPoint(b1);
        readPoint(a2);
        readPoint(b2);
        cout << (doIntersect(a1, b1, a2, b2) ? "Lines are intersecting\n" : "Lines are not intersecting\n");
    }
    return 0;
}