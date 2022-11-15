//INPUT
/*
4
2
3
4
1

*/

//OUTPUT
/*
1
2
3
4

*/

//ALGORITHM/PSEUDOCODE
/*
START
DECLARE integers i, j, n, temp
READ n
DECLARE integer array a
ALLOCATE memory for n integers to array a
ASSIGN i = 0
REPEAT
    READ a[i]
    i++
UNITL (i >= n)
ASSIGN i = 1
REPEAT
    ASSIGN temp = a[i], j = i - 1
    REPEAT
        ASSIGN a[j + 1] = a[j]
        j--
    UNTIL (a[j] <= temp OR j < 0)
    ASSIGN a[j + 1] = temp
    i++
UNTIL (i >= n)
REPEAT
    PRINT a[i] + "\n"
    i++
UNTIL (i >= n)
END
*/

//PROCESS
/*
Using insertion sort to sort given array. Using for loop with inner while loop to facilitate insertion sorting. Memory to array dynamically allocated using malloc() from stdlib.h header file. 
Inputs read using scanf() and outputs printed using printf() from stdio.h header file.
*/

//ALTERNATE SOLUTIONS
/*
Can use other sorting methods such as bubble or selection sorting. Can also statically allocate memory to array during initialization.
*/

//CODE
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j, n, temp;
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while (a[j] > temp && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);
    return 0;
}