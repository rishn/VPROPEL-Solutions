//INPUT
/*
6
2
3
4
5
6
1

*/

//OUTPUT
/*
1
2
3
4
5
6
2
1
4
3
6
5

*/

//ALGORITHM/PSEUDOCODE
/*
START
DECLARE int array a
FUNCTION void group(parameters : int array a, int n)
    DECLARE ints i, odd, even, j
    ASSIGN i = 0, odd = 0, even = 0
    DECLARE int array b
    ALLOCATE memory for n ints to b
    REPEAT
        REPEAT
            IF (! (a[j] % 2) == 1) THEN
                ASSIGN b[i] = a[j], i = i + 1, even = j, j= j + 1
                BREAK
            ENDIF
            INCREMENT j
        UNTIL (j >= n)
        REPEAT
            IF (a[j] & 2) THEN
                ASSIGN b[i] = a[j], i = i + 1, odd = j, j = j + 1
                BREAK
            ENDIF
            INCREMENT j
        UNTIL (j >= n)
    UNTIL (i >= n)
    REPEAT
        ASSIGN a[i] = b[i]
        PRINT a[i] + "\n"
        INCREMENT i
    UNTIL (i >= n)
ENDFUNCTION
FUNCTION int partition(parameters : int array a, int l, int r)
    DECLARE ints x, i, j, temp
    ASSIGN x = a[l], i = l, j = r - 1,
    REPEAT
        REPEAT
            DECREMENT j
        UNTIL (a[j] <= x)
        REPEAT
            INCREMENT i
        UNTIL (a[i] >= x)
        IF (i < j) THEN
            ASSIGN temp = a[i], a[i] = a[j], a[j] = temp
        ELSE
            RETURN j 
        ENDIF
    UNTIL (0)
ENDFUNCTION
FUNCTION void quick_sort(parameters : int array a, int p, int n)
    IF (p < n)
        DECLARE int q
        CALL partition() with a, p, n
            RETURNING int as q
        CALL quick_sort() with a, p, q
            RETURNING None
        CALL quick_sort() with a, q + 1, n
            RETURNING None
    ENDIF
ENDFUNCTION
DECLARE ints i, j, n
READ n
DECLARE int array a
ALLOCATE memory for n integers to a
READ n elements of a
CALL quick_sort() with a, 0, n
    RETURNING None
PRINT n elements of a separated by "\n"
CALL group() with a, n
    RETURNING None
END
*/

//PROCESS
/*
Quick sort process used to sort elements in increasing order. 
Functions quick_sort() and partition() involved in quick sorting procedure where quick_sort() is a recursive function and partition() gives the index of the array where the array is to be split into two parts, 
to continue the sorting. Nested while loops and if-else conditions used to check for required criteria during quicksort. Memory to arrays dynamically allocated using malloc() from stdlib.h header file. 
Inputs read and outputs printed using scanf() and printf() functions under stdio.h header file. 
group() used to group elements to alternating even-odd order and insert them into a new array which are then re-assigned back to the original array. The array elements are printed afterwards.
*/

//ALT SOLUTIONS
/*
Can use other sorting non-comparison sorting methods such as bubble, selection or insertion sort and can even use merge sort. 
Can also directly print array elements directly w/o rearranging the order while grouping them into required order.
*/

//CODE
#include <stdio.h>
#include <stdlib.h>
int *a;
void group(int *a, int n)
{
    int i = 0, odd = 0, even = 0, j;
    int *b = (int *)malloc(sizeof(int)*n);
    while (i < n)
    {
        for (j = even; j < n; j++)
            if (! (a[j] % 2))
            {
                b[i++] = a[j];
                even = ++j;
                break;
            }
        for (j = odd; j < n; j++)
            if (a[j] % 2)
            {
                b[i++] = a[j];
                odd = ++j;
                break;
            }
    }
    for (i = 0; i < n; i++)
    {
        a[i] = b[i];
        printf("%d\n", a[i]);
    }
}
int partition(int *a, int l, int r)
{
    int x = a[l], i = l, j = r - 1, temp;
    while (1)
    {
        while (a[j] > x)
            j--;
        while (a[i] < x)
            i++;
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else
            return j;
    }
}
void quick_sort(int *a, int p, int n)
{
    if (p < n)
    {
        int q = partition(a, p, n);
        quick_sort(a, p, q);
        quick_sort(a, q + 1, n);
    }
}
int main()
{
    int i, j, n;
    scanf("%d", &n);
    a = (int *)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    quick_sort(a, 0, n);
    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);
    group(a, n);
    return 0;
}