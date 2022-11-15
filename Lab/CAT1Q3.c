//INPUT
/*
2 5
1 9 9 2 1
7 2 2 2 5
*/

//OUTPUT
/*
129

*/

//PSEUDOCODE
/*

*/

//CODE
#include <stdio.h>
#include <stdlib.h>
int duplicate_no(int **arr, int m, int n)
{
    int i, j, k, l, p, t, q = 0, num = 0;
    int *dups = (int *)malloc(sizeof(int));
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            for (k = 0; k < m; k++)
                for (l = 0; l < n; l++)
                {
                    if (arr[i][j] == arr[k][l] && (i != k || j != l))
                    {
                        int chk = 1;
                        for (p = 0; p < q; p++)
                            if (arr[i][j] == dups[p])
                            {
                                chk = 0;
                                break;
                            }
                        if (chk)
                        {
                            dups[q++] = arr[i][j];
                            dups = (int *)realloc(dups, sizeof(int) * (q + 1));
                        }
                    }
                }
    for (i = 0; i < q; i++)
    {
        for (j = i + 1; j < q; j++)
            if (dups[i] < dups[j])
            {
                t = dups[i];
                dups[i] = dups[j];
                dups[j] = t;
            }
        t = 1;
        for (j = 0; j < i; j++)
            t *= 10;
        num += dups[i] * t;
    }
    return num;
}
int main()
{
    int i, j, k, l, m, n;
    scanf("%d %d", &m, &n);
    int **arr = (int **)malloc(sizeof(int *) * m);
    for (i = 0; i < m; i++)
        arr[i] = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
    printf("%d\n", duplicate_no(arr, m, n));
    return 0;
}