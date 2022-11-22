#include <stdio.h>
#include <stdlib.h>
int *a;
void merge(int *left, int *right, int *a)
{
    int nl = sizeof(left) / sizeof(int);
    int nr = sizeof(right) / sizeof(int);
    int i = 0, j = 0, k = 0;
    while (i < nl && j < nr)
    {
        if (left[i] <= right[j])
        {
            a[k] = left[i];
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < nl)
    {
        a[k] = left[i];
        i++;
        k++;
    }
    while (j < nr)
    {
        a[k] = right[j];
        j++;
        k++;
    }
}
void merge_sort(int *a)
{
    int n = sizeof(a) / sizeof(int), mid = n / 2;
    if (n < 2)
        return;
    int *left = (int *)malloc(sizeof(int)*mid), right = (int *)malloc(sizeof(int)*(n - mid));
    for (i = 0; i < mid; i++)
        left[i] = a[i];
    for (i = mid; i < n; i++)
        right[i] = a[i];
    merge_sort(left);
    merge_sort(right);
    merge(left, right, a);
}
int main()
{
    int i, n;
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    merge_sort(a);
    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);
}
