//INPUT
/*
7
1
2
3
4
5
6

*/

//OUTPUT
/*
7
1
6
2
5
3
4

*/

//PROCESS
/*
Used selection sort to find and place alternate max. and min. values in array during sorting. Nested for loop used to enable selection sorting process. 
Variables created to swap required value at required index. If else condition used to check whether process to find min. or max. should be initiated depending on the iteration number.
*/

//ALTERNATE SOLUTIONS
/*
Other sorting methods like insertion or bubble sort could also be used. Also memory of array could be initialized statically instead of allocating dynamically.
*/

//ALGORITHM/PSEUDOCODE
/*
START
DECLARE integers i, j, n
READ n
DECLARE integer array arr
ALLOCATE memory for n integers to integer array arr
ASSIGN i = 0
REPEAT
    READ arr[i]
    i++
UNTIL (i >= n)
ASSIGN i = 0
REPEAT
    DECLARE integers value, index
    ASSIGN value = arr[i], index = i
    IF (! (i % 2) == 1) THEN
        ASSIGN j = i + 1
        REPEAT
            IF (arr[j] > value) THEN
                ASSIGN value = arr[j], index = j
            ENDIF
            ASSIGN arr[index] = arr[i], arr[i] = value
            j++
        UNTIL (j >= n)
    ELSE
        ASSIGN j = i + 1
        REPEAT
            IF (arr[j] < value) THEN
                ASSIGN value = arr[j], index = j
            ENDIF
            ASSIGN arr[index] = arr[i], arr[i] = value
            j++
        UNTIL (j >= n)
    ENDIF
    PRINT arr[i] + "\n"
    i++
UNTIL (i >= 0)
END
*/

//CODE
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j,  n;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (i = 0; i < n; i++)
    {
        int value = arr[i], index = i;
        if (! (i % 2))
        {
            for (j = i + 1; j < n; j++)
                if (arr[j] > value)
                {
                    value = arr[j];
                    index = j;
                }
            arr[index] = arr[i];
            arr[i] = value;
        }
        else
        {
            for (j = i + 1; j < n; j++)
                if (arr[j] < value)
                {
                    value = arr[j];
                    index = j;
                }
            arr[index] = arr[i];
            arr[i] = value;
        }
        printf("%d\n", arr[i]);
    }
return 0;
}



 