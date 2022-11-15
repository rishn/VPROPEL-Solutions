//INPUT
/*
5
2 4 1 3 5
*/

//OUTPUT
/*
3

*/

//PSEUDOCODE
/*

*/

//CODE
#include <stdio.h>
#include <stdlib.h>
int fixed_point(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
        if (abs(arr[i]) == i)
            return i;
    return -1;
}
int main()
{
    int i, n;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("%d", fixed_point(arr, n));
    return 0;
}