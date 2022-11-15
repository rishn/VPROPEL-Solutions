//INPUT
/*
1708945392045
*/

//OUTPUT
/*
d occurs in k.
No. of occurences of d in k: 2
Printing positions of d in k:
1 7 
*/

//CODE
#include <stdio.h>
#include <stdlib.h>
int main()
{
    long k;
    int i, d, count = 0, pos = 1, *arr;
    scanf("%ld %d", &k, &d);
    while (k > 1)
    {
        if (k % 10 == d)
        {
            if (! count)
            {
                printf("d occurs in k.\n");
                arr = (int *)malloc(sizeof(int));
            }
            arr[count] = pos;
            count++;
            arr = (int *)realloc(arr, sizeof(arr) + sizeof(int));
        }
        k /= 10;
        pos++;
    }
    printf("No. of occurences of d in k: %d\nPrinting positions of d in k:\n", count);
    for (i = 0; i < count; i++)
        printf("%d ", arr[i]);
    return 0;
}