#include <stdio.h>
/*
int sum(int *bst, int p, int i, int s)
{
    if (i >= p)
        return s;
    return sum(bst, p, i * 2, s += bst[i]);
    return sum(bst, p, i * 2 + 1, s += bst[i]);
}
*/
int main()
{
    int i, t, h, p = 1, s = 0;
    scanf("%d", &h);
    t = h + 1;
    for (; t > 0; t--)
        p *= 2;
    int bst[p - 1];
    for (i = 0; i < p - 1; i++)
        scanf("%d", &bst[i]);
    for (i = 1; i < p - 1; i++)
        if (bst[i] < bst[0] && bst[i] >= 0)
            s += bst[i];
    printf("%d\n%d", h, s);
    return 0;
}