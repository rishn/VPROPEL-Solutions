//INPUT
/*
7
1 3 12 19 13 2 15
3
*/

//OUTPUT
/*
13
13 is a Magic number.

*/

//PSEUDOCODE
/*
 
*/

//CODE
#include <stdio.h>
#include <stdlib.h>
void magic_no(int *a, int n, int k)
{
    int i, j, t, index, sum = 0;
    int *b = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
        b[i] = a[i];
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (b[i] < b[j])
            {
                t = b[i];
                b[i] = b[j];
                b[j] = t;
            }
    t = b[k - 1];
    printf("%d\n", t);
    for (i = 0; i < n; i++)
        if (a[i] == t)
        {
            index = i;
            break;
        }
    while (t > 0)
    {
        sum += t % 10;
        t /= 10;
    }
    if (sum == index)
        printf("%d is a Magic number.\n", b[k - 1]);
}
int main()
{
    int i, n, t, k, index;
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &k);
    magic_no(a, n, k);
    return 0;
}