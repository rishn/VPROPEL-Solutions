//INPUT
/*
No. of elements: 11
Provide 11 array elements below: 
25 19 22 23 21 12 10 17 11 13 10
*/

//OUTPUT
/*
10 10 11 12 13 17 19 21 22 23 25 
*/

//CODE
#include <stdio.h>
#include <stdlib.h>
int *Swap(int *A, int i)
{
    int temp = A[0];
    A[0] = A[i];
    A[i] = temp;
    return A;
}
int main()
{
    int i, j, n;
    printf("No. of elements: ");
    scanf("%d", &n);
    int *A = (int *)malloc(sizeof(int) * n);
    printf("Provide %d array elements below: \n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
            if (A[i] > A[j])
            {
                A = Swap(A, i);
                A = Swap(A, j);
                A = Swap(A, i);
            }
        printf("%d ", A[i]);
    }
    return 0;
}