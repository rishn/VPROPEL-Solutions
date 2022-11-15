//INPUT
/*
3145782
4
*/

//OUTPUT
/*
5
Odd
*/

//ALGORITHM/PSEUDOCODE
/*
START
DECLARE long integers n, t
DECLARE integers i, p, l
ASSIGN l = 0
READ n, p
ASSIGN t = n
REPEAT
    t /= 10
    INCREMENT l
UNTIL (t >= 0)
ASSIGN t = 10, i = 0
REPEAT
    t *= 10
    INCREMENT i
UNTIL (i >= l - p - 1)
n /= t
PRINT n % 10
IF (2 cannot divide (n % 10))
    PRINT "Odd"
ELSE
    PRINT "Even"
END
*/

//CODE
#include <stdio.h>
int main()
{
    long n, t;
    int i, p, l = 0;
    scanf("%ld %d", &n, &p);
    t = n;
    while (t > 0)
    {
        t /= 10;
        l++;
    }
    t = 10;
    for (i = 0; i < l - p - 1; i++)
        t *= 10;
    n /= t;
    printf("%d\n", n % 10);
    if ((n % 10) % 2)
        printf("Odd");
    else
        printf("Even");
    return 0;
}