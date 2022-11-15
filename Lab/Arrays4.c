//INPUT
/*
Enter order of matrix: 3
Entire matrix elements (row-wise) below:
11 2 4
4 5 6
10 8 -12
*/

//OUTPUT
/*
Sum across the first diagonal: 4
Sum across the second diagonal: 19
Absolute difference: 15
*/

//ALGORITHM/PSEUDOCODE
/*
START
DECLARE integers main, off, i, n
ASSIGN main = 0, off = 0
READ n
DECLARE integer array a
ALLOCATE memory of n*n integers to a
ASSIGN i = 0
REPEAT
    READ a[i]
    INCREMENT i
UNTIL (i >= n*n)
ASSIGN i = 0
REPEAT
    ADD a[i] to main, (n + 1) to i
UNTIL (i >= n*n)
ASSIGN i = n - 1
REPEAT
    ADD a[i] to off, (n - 1) to i
UNTIL (i >= n*n - 1)
PRINT main, off, ABS DIFF of main and off separated by newline
END
*/


//CODE
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int main = 0, off = 0, i, n;
    printf("Enter order of matrix: ");
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int)*n*n);
    printf("Entire matrix elements (row-wise) below:\n");
    for (i = 0; i < n*n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n*n; i += (n + 1))
        main += a[i];
    for (i = n - 1; i < n*n - 1; i += (n - 1))
        off += a[i];
    printf("Sum across the first diagonal: %d\nSum across the second diagonal: %d\nAbsolute difference: %d", main, off, abs(main - off));
    return 0;
}