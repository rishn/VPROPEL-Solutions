//INPUT
/*
No. of elements: 11
Provide 11 array elements below: 
25 19 22 23 21 12 10 17 11 13 10
Provide k value: 35
*/

//OUTPUT
/*
The 1th (25) and 7th (10) elements of A add up to give k.
The 1th (25) and 11th (10) elements of A add up to give k.
The 3th (22) and 10th (13) elements of A add up to give k.
The 4th (23) and 6th (12) elements of A add up to give k.

*/

//CODE
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j, k, n, count = 0;;
    printf("No. of elements: ");
    scanf("%d", &n);
    int *A = (int *)malloc(sizeof(int) * n);
    printf("Provide %d array elements below: \n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
    printf("Provide k value: ");
    scanf("%d", &k);
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (A[i] + A[j] == k)
            {
                printf("The %dth (%d) and %dth (%d) elements of A add up to give k.\n", i + 1, A[i], j + 1, A[j]);
                count++;
            }
    if (! count)
        printf("No two numbers in A add up to give k.");
    return 0;
}