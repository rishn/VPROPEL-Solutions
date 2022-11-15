//INPUT
/*
5
309 25 100 6666 305
*/

//OUTPUT
/*
25 309 305 100 6666

*/

//PSEUDOCODE
/*

*/

//CODE
#include <stdio.h>
#include <stdlib.h>
int *sort_by_digits(int *arr, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        int l = 0, t = arr[i];
        while (t > 0)
        {
            l++;
            t /= 10;
        }
        for (j = i + 1; j < n; j++)
        {
            int m = 0, t = arr[j];
            while (t > 0)
            {
                m++;
                t /= 10;
            }
            if (l > m || (l == m && arr[i] < arr[j]))
            {
                t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
                l = m;
            }
        }
    }
    return arr;
}
int main()
{
    int i, j, n;
    scanf("%d",  &n);
    int *arr = (int *)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    arr = sort_by_digits(arr, n);
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}