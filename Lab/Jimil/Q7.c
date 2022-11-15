//INPUT
/*
450920
*/

//OUTPUT
/*
2
*/

//CODE
#include <stdio.h>
int main()
{
    long k, count = 0;
    scanf("%ld", &k);
    while (k > 1)
    {
        if (! (k % 10))
            count++;
        k /= 10;
    }
    printf("%d", count);
    return 0;
}