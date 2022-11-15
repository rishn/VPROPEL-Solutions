//INPUT
/*
6
1
2
3
4
5
6
6

*/

//OUTPUT
/*
No
-1

*/

//ALGORITHM/PSEUDOCODE
/*
START
FUNCTION find(parameters : int pointer a, int n, int x)
    DECLARE integers i, j, count
    ASSIGN count = 0, i = 0
    REPEAT
        ASSIGN j = 0
        REPEAT
            IF (ABS(a[i] - a[j]) == x) THEN
                IF (count == 0) THEN
                    PRINT "Yes\n"
                ENDIF
                PRINT a[i] + "\n" + a[j] + "\n"
                count++
            ENDIF
        UNTIL (i >= n)
        IF ! count THEN
            PRINT "No\n-1"
ENDFUNCTION
DECLARE integers i, n, x
READ n
ALLOCATE memory for n integers to a
ASSIGN i = 0
REPEAT
    READ a[i]
    i++
UNTIL (i >= n)
READ x
CALL find() with a, n, x
    RETURNING None
END
*/

//PROCESS
/*
Using function find() for processing and printing required output which consists of a nested for loop to check if the difference between all possible pairs of array elements equals given number x. 
Using scanf() and printf() functions from stdio.h header file to read inputs and print required outputs. malloc() from stdlib.h header file used to allocate memory for n integers to pointer array a. 
*/

//ALT SOLUTIONS
/*
Can use separate array to store pairs of elements and a separate loop to print required pairs of elements. Memory of a random size can be set statically during initialization to pointer array.
*/

//CODE
#include <stdio.h>
#include <stdlib.h>
void find(int *a, int n, int x)
{
    int i, j, count = 0;
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
        {
            if (abs(a[i] - a[j]) == x)
            {
                if (count == 0)
                    printf("Yes\n");
                printf("%d\n%d\n", a[i], a[j]);
                count++;
            }
        }
        if (! count)
            printf("No\n-1");
}
int main()
{
    int i, n, x;
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &x);
    find(a, n, x);
    return 0;
}
