#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j, n, t = 0, max = 0;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (max < arr[i])
            max = arr[i];
    }
    int *count = (int *)malloc(sizeof(int) * (max + 1)), *cum = (int *)malloc(sizeof(int) * (max + 1));
    for (i = 0; i <= max; i++)
        count[i] = 0;
    for (i = 0; i < n; i++)
        count[arr[i]]++;
    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--)
        cum[--count[arr[i]]] = arr[i];
    for (i = 0; i < n; i++)
    {
        arr[i] = cum[i];
        printf("%d ", arr[i]);
    }
    return 0;
}
