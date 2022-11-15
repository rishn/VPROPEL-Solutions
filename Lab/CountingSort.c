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
    {
        int c = 0;
        cum[i] = t;
        for (j = 0; j < n; j++)
            if (i == arr[j])
                c++;
        count[i] = c;
        t += c;
    }
    for (i = 0; i < max; i++)
        for (j = cum[i]; j < cum[i + 1]; j++)
        {
            arr[j] = i;
            printf("%d ", arr[j]);
        }
    for (i = cum[max]; i < n; i++)
    {
        arr[i] = max;
        printf("%d ", arr[i]);
    }
    return 0;
}