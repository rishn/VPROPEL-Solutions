//INPUT
/*
10
10
7
8
9
2
3
4
1
5
6
4
9

*/

//OUTPUT
/*
1
2
3
4
5
6
7
8
9
10
4
5
6
7
8
9

*/

//ALGORITHM/PSEUDOCODE
/*
START
DECLARE integers i, j, n, k1, k2, min, index, k1_index, k2_index
READ n
DECLARE integer array pointer *a
ALLOCATE memory for n integers to a
ASSIGN i = 0
REPEAT
    READ a[i]
    i++
UNTIL (i >= n)
READ k1, k2
REPEAT
    ASSIGN min = a[i], index = i, j = i + 1
    REPEAT
        IF min > a[j] THEN
            ASSIGN min = a[j], index = j
        ENDIF
        j++
    UNTIL (j >= n)
    ASSIGN a[index] = a[i], a[i] = min
    IF k1 == a[i] THEN
        ASSIGN k1_index = i
    ELSE IF k2 == a[i] THEN
        ASSIGN k2_index = i
    ENDIF
    PRINT a[i] + "\n"
    i++
UNTIL (i >= n)
ASSIGN i = 0
REPEAT
    PRINT a[i] + "\n"
UNTIL (i >= n)
END
*/

//PROCESS
/*
Using insertion sort with nested for loop to sort the given array in ascending order by finding the (i + 1)th min number in the array for every number 
from 0 to n - 1 in every outer loop iteration. Using scanf() and printf() function from stdio.h header file to read inputs and print outputs. 
Using if-else ladder (if-else-if conditions) to find indices of k1 and k2 in a during sorting process to reduce time complexity. 
malloc() from stdlib.h header file used to allocate memory for n integers to pointer array a. Using for loop to print required elements.
*/

//ALT SOLUTIONS
/*
Can use other sorting methods such as bubble sort or selection sort which may consume lesser memory but require more number of swaps. 
A separate loop (for/while) can be used to find indices of k1 and k2 or just the index of k1 to print the required elements. 
Memory of a random size can be set statically during initialization for the pointer array.
*/

//CODE
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j, n, k1, k2, min, index, k1_index, k2_index;
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d %d", &k1, &k2);
    for (i = 0; i < n; i ++)
    {
        min = a[i];
        index = i;
        for (j = i + 1; j < n; j++)
        {
            if (min > a[j])
            {
                min = a[j];
                index = j;
            }
        }
        a[index] = a[i];
        a[i] = min;
        if (k1 == a[i])
            k1_index = i;
        else if (k2 == a[i])
            k2_index = i;
        printf("%d\n", a[i]);
    }
    for (i = k1_index; i <= k2_index; i++)
        printf("%d\n", a[i]); 
    return 0;
}



