//INPUT
/*
5
10
5
3
9
2
7

*/

//OUTPUT
/*
5
9
10
3
2

*/

//ALGORITHM/PSEUDOCODE
/*
START
DECLARE integers i, j, n, x
READ n
DECLARE integer array a
ALLOCATE memory of n integers to array a
ASSIGN i = 0
REPEAT
    READ a[i]
    i++
UNTIL (i >= n)
READ x
ASSIGN i = 0
REPEAT
    DELCARE integers min, value, index
    ASSIGN min = ABS (a[i] - x), value = a[i], index = i, j = i + 1
    REPEAT
        IF (ABS (a[j] - x) < min) THEN
            ASSIGN min = ABS (a[j] - x), value = a[j], index = j
        ENDIF
        j++
    UNTIL (j >= n)
    ASSIGN a[index] = a[i], a[i] = value
    PRINT a[i] + "\n"
    i++
UNTIL (i >= n)
END    
*/

//PROCESS
/*
Used selection sort to sort the given array according to given requirements. abs() function used to find absolute value of a quantity. Nested for loop used to facilitate selection sorting. 
Variables assigned to swap required variable at required position. Inputs read using scanf() and outputs printed using printf() functions from stdio.h header file. 
Memory of array dynamically allocated using malloc() from stdlib header file.
*/

//ALTERNATE SOLUTIONS
/*
Can use other sorting methods such as insertion and bubble sort. Can also statically allocate memory to array during initialization. 
Can also use separate for loops to print elements of array.
*/

//CODE
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j, n, x;
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &x);
    for (i = 0; i < n; i++)
    {
        int min = abs(a[i] - x), value = a[i], index = i;
        for (j = i + 1; j < n; j++)
            if (abs(a[j] - x) < min)
            {
                min = abs(a[j] - x);
                value = a[j];
                index = j;
            }
        a[index] = a[i];
        a[i] = value;
        printf("%d\n", a[i]);
    }
    return 0;
}