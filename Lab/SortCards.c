//INPUT
/*
7
J
A
K
Q
3
2
4

*/

//OUTPUT
/*
2
3
4
J
Q
K
A

*/

//ALGORITHMPSEUDOCODE
/*
START
DECLARE integers i, j, n
READ n
DECLARE character array a
ALLOCATE memory for n integers to array a
ASSIGN i = 0
REPEAT
    READ character a[i]
    READ integer a[i]
    i++
UNTIL (i >= n)
ASSIGN i = 0
REPEAT
    DECLARE integers min, index
    ASSIGN min = a[i], index = i, j = i + 1
    REPEAT
        IF (a[j] >= '1' AND a[j] <= '9' AND min > a[j]) THEN
            ASSIGN min = a[j], index = j
        ELSE IF (a[j] == 'J' OR (a[j] == 'Q' AND (a[i] == 'K' OR a[i] == 'A')) OR (a[j] == 'K' AND a[i] == 'A')) THEN
            ASSIGN min = a[j]. index = j
        ENDIF
        j++
    UNTIL (j >= n)
    ASSIGN a[index] = a[i], a[i] = min
    PRINT a[i] + "\n"
    i++
UNTIL (i >= n)
END
*/

//PROCESS
/*
Selection sort used to sort given array of elements. Nested for loop used to facilitate selection sorting. Variables assigned to swap required value at required positions. Compound if-else statements used to find element to be swapped. 
Memory of array dynamically allocated using malloc() from stdlib.h. getchar() used to check for characters from digits.
*/

//ALTERNATE SOLUTIONS
/*
Can use other sorting methods such as insertion sort or bubble sort. Can also declare array memory statically during initialization. 
Can also use separate for loop to print required outputs and nested if-else statements instead of compound if-else statements to find elements to be swapped.
*/

//CODE
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j, n;
    scanf("%d", &n);
    char *a = (char *)malloc(sizeof(char)*n);
    for (i = 0; i < n; i++)
    {
        if (getchar())
            scanf("%c", &a[i]);
        else
            scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        int min = a[i], index = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] >= '1' && a[j] <= '9' && min > a[j])
            {
                min = a[j];
                index = j;
            }
            else if (a[j] == 'J' || (a[j] == 'Q' && (a[i] == 'K' || a[i] == 'A')) || (a[j] == 'K' && a[i] == 'A'))
            {
                min = a[j];
                index = j;
            }
        }
        a[index] = a[i];
        a[i] = min;
        printf("%c\n", a[i]);
    }
    return 0;
}