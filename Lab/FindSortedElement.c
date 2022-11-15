//INPUT
/*
5
2
3
4
1
5
1

*/

//OUTPUT
/*
3
4
5
Yes
1

*/

//ALGORITHM/PSEUDOCODE
/*
START
DECLARE integers i, j, n, k, min, index, chk, k_index
ASSIGN chk = 0
READ n
DECLARE integer array pointer a
ALLOCATE memory for n integers to a
ASSIGN k_index = n
REPEAT
    READ a[i]
    i++
UNTIL (i >= n)
READ k
ASSIGN i = 0
REPEAT
    ASSIGN min = a[i], index = i, j = i + 1
    REPEAT
        IF (min > a[j]) THEN
            ASSIGN MIN = a[j], index = j
        ENDIF
    UNTIL (j >= n)
    ASSIGN a[index] = a[i], a[i] = min
    IF (k == a[i]) THEN
        ASSIGN k_index = i
    ENDIF
    PRINT a[i] + "\n"
UNTIL (i >= n)
IF k_index == n THEN
    PRINT "No\n-1"
ELSE
    PRINT "Yes\n" + (k_index + 1)
ENDIF
END
*/

//PROCESS
/*
Using insertion sort with nested for loop to sort the given array in ascending order by finding the (i + 1)th min number in the array for every number 
i from 0 to n - 1 in every outer loop iteration. Using scanf() and printf() from stdio.h header file to read inputs and print outputs. 
malloc() from stdlib.h header file used to allocate memory for n integers to array pointer a. 
Using if condition to find element k in array during sorting process to reduce time complexity and if-else condition to print required output.
*/

//ALT SOLUTIONS
/*
Can use other sorting methods such as bubble sort or insertion sort which may consume less memory but require more number of swaps. 
A separate loop (for/while) can be used to find k in the array. Memory of random size can be set statically during initialization to pointer array.
*/

//CODE
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j, n, k, min, index, chk = 0;
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int)*n), k_index = n;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &k);
    for (i = 0; i < n; i++)
    {
        min = a[i];
        index = i;
        for (j = i + 1; j < n; j++)
            if (min > a[j])
            {
                min = a[j];
                index = j;
            }
        a[index] = a[i];
        a[i] = min;
        if (k == a[i])
            k_index = i; 
        printf("%d\n", a[i]);
    }
    if (k_index == n)
        printf("No\n-1");
    else
        printf("Yes\n%d", k_index + 1);
    return 0;
}
