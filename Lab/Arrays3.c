//INPUT
/*
6
6 7 4 3 5 2
*/

//OUTPUT
/*
7
5
2

*/

//ALGORITHM/PSEUDOCODE
/*
START
DECLARE integers i, j, n
READ n
DECLARE integer array a
ALLOCATE memory for n integers to array a
ASSIGN i = 0
REPEAT
    READ a[i]
    i++
UNTIL (i >= n)
ASSIGN i = 0
REPEAT
    DECLARE integer chk
    ASSIGN chk = 1, j = i + 1
    REPEAT
        IF (a[i] <= a[j]) THEN
            ASSIGN chk = 0
            BREAK
        ENDIF
        j++
    UNTIL (j >= n)
    IF (chk) THEN
        PRINT a[i] + "\n"
    ENDIF
    i++
UNTIL (i >= n)
END
*/

//CODE
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j, n;
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
    {
        int chk = 1;
        for (j = i + 1; j < n; j++)
            if (a[i] <= a[j])
            {
                chk = 0;
                break;
            }
        if (chk)
            printf("%d\n", a[i]);
    }
    return 0;
}