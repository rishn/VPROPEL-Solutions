//INPUT
/*
Enter order of matrix: 4
Enter elements of matrix row-wise below:
5 7 9 4
2 4 7 3
1 5 9 2
3 7 4 8
*/

//OUTPUT
/*
5 4 9 8 
4 7 5 3 
*/

//CODE
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j, n, *arr;
    printf("Enter order of matrix: ");
    scanf("%d", &n);
    printf("Enter elements of matrix row-wise below:\n");
    arr = (int *)malloc(sizeof(int)*n*n);
    for (i = 0; i < n*n; i++)
        scanf("%d", &arr[i]);
    for (i = 0; i < n*n; i += (n + 1))
        printf("%d ", arr[i]);
    printf("\n");
    for (i = n - 1; i < n*n - 1; i += (n - 1))
        printf("%d ", arr[i]);
    return 0;
}