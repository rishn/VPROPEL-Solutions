#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, j;
    scanf("%d", &n);
    int **a = (int **)malloc(sizeof(int *) * n);
    for (i = 0; i < n; i++)
    {
        a[i] = (int *)malloc(sizeof(int) * n);
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }
    for (i = 0; i < n; i++)
    {
        int min_row = a[i][0], min_col = a[0][i], row_index = 0, col_index = 0;
        for (j = 1; j < n; j++)
        {
            if (a[i][j] < min_row)
            {
                row_index = j;
                min_row = a[i][j];
            }
            if (a[j][i] < min_col)
            {
                col_index = j;
                min_col = a[j][i];
            }
        }
        a[i][row_index] = a[i][0];
        a[i][0] = min_row;
        a[col_index][i] = a[0][i];
        a[0][i] = min_col;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}