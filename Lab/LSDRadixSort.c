#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j, k, m, n, l = 0, max = 0;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (max < arr[i])
            max = arr[i];
    }
    while (max > 0)
    {
        l++;
        max /= 10;
    }
    for (i = 1; i < l; i++)
    {
        int buckets[10][n], count[10] = {0};
        int pow = 1;
        for (j = 0; j < i; j++)
            pow *= 10;
        for (j = 0; j < n; j++)
            buckets[arr[j] % pow][count[arr[j] % pow]++] = arr[j]; 
        for (j = 0, k = 0; k < 10; k++)
            for (m = 0; m < count[k]; m++)
                arr[j++] = buckets[k][m];
    }
    for (i = 0; i < n; i++)
        printf("%d\n", arr[i]);
	return 0;
}