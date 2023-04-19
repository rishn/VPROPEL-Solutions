//INPUT
/*
8
0 3
1 1
2 2
4 4
0 0
1 2
3 1
3 3

18
-7 8
-4 6
2 6
6 4
8 6
7 -2
4 -6
8 -7
0 0
3 -2
6 -10
0 -6
-9 -5
-8 -2
-8 0
-10 3
-2 2
-10 4
*/

//OUTPUT
/*
The points in the convex hull are: 
(0, 3)
(4, 4)
(3, 1)
(0, 0)

The points in the convex hull are: 
(-9, -5)
(-10, 3)
(-10, 4)
(-7, 8)
(8, 6)
(8, -7)
(6, -10)

*/

//CODE
#include <iostream>
#include <stack>
using namespace std;
struct point
{
    int x, y;
}; 
point p0;
// A utility function to find next to top in a stack
point secondTop(stack<point> &S)
{
    point p = S.top();
    S.pop();
    point res = S.top();
    S.push(p);
    return res;
}
// A utility function to swap two points
void swap(point &a, point &b)
{
    point temp = a;
    a = b;
    b = temp;
}
// A utility function to return square of distance between a and b
int sqDist(point a, point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
int direction(point a, point b, point c)
{
    int dir = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    return dir ? (dir < 0 ? 2 : 1) : 0;
    // anti-clockwise direction // clockwise direction // colinear
}
// A function used by library function qsort() to sort an array of
// points with respect to the first point
int compare(const void *va, const void *vb)
{
    point *a = (point *)va;
    point *b = (point *)vb;
    // Find direction
    int d = direction(*a, *b, p0);
    if (! d)
        return sqDist(p0, *a) > sqDist(p0, *b) ? 1 : -1;
    return d == 1 ? 1 : -1;
}
// Prints convex hull of a set of n points
void convexHull(point points[], int n)
{
    // Find the bottommost point
    int i, yMin = points[0].y, min = 0, m = 1; // Initialize size of modified array
    for (i = 1; i < n; i++)
        // Pick the bottom-most or chose the left most point in case of tie
        if (points[i].y < yMin || yMin == points[i].y && points[i].x < points[min].x)
        {
            yMin = points[i].y;
            min = i;
        }
    // Place the bottom-most point at first position
    swap(points[0], points[min]);
    // Sort n-1 points with respect to the first point. A point a comes
    // before b in sorted ouput if b has larger polar angle (in
    // counterclockwise direction) than a
    p0 = points[0];
    qsort(&points[1], n - 1, sizeof(point), compare);
    // If two or more points make same angle with p0,
    // Remove all but the one that is farthest from p0
    // Remember that, in above sorting, our criteria was
    // to keep the farthest point at the end when more than
    // one points have same angle.
    for (int i = 1; i < n; i++)
    {
	// Keep removing i while angle of i and i+1 is same
	// with respect to p0
	    while (i < n - 1 && (! direction(p0, points[i], points[i + 1])))
            i++;
        points[m++] = points[i]; // Update size of modified array
	}
    // If modified array of points has less than 3 points,
    // convex hull is not possible
    if (m < 3)
        return;
    // Create an empty stack and push first three points to it.
    stack<point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);
    // Process remaining n-3 points
    for (i = 3; i < m; i++)
    {
        // Keep removing top while the angle formed by points next-to-top,
        // top, and points[i] makes a non-left turn
        while (S.size() > 1 && direction(secondTop(S), S.top(), points[i]) != 2)
            S.pop();
        S.push(points[i]);
    }
    // Now stack has the output points, print contents of stack
    while (! S.empty())
    {
        point p = S.top();
        cout << "(" << p.x << ", " << p.y << ")" << endl;
        S.pop();
    }
}
// Driver program to test above functions
int main()
{
    int i, n;
    cin >> n;
    point points[n];
    for (i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;
    cout << "The points in the convex hull are: \n";
    convexHull(points, n);
    return 0;
}