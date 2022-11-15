//INPUT
/*
No. of elements: 11
Provide 11 array elements below: 
25 19 22 23 21 12 10 17 11 13 10
*/

//OUTPUT
/*
23
17
13

*/

//CODE
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, n;
    printf("No. of elements: ");
    scanf("%d", &n);
    int *x = (int *)malloc(sizeof(int) * n);
    printf("Provide %d array elements below: \n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &x[i]);
    for (i = 1; i < n - 1; i++)
        if (x[i] > x[i - 1] && x[i] > x[i + 1])
            printf("%d\n", x[i]);
    return 0;
}