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
DECLARE long integer n
DECLARE integers i, p
READ n, p
ASSIGN i = 1
REPEAT
    n /= 10
    INCREMENT i
UNTIL (i >= p)
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
    long n;
    int i, p;
    scanf("%ld %d", &n, &p);
    for (i = 1; i < p; i++)
        n /= 10;
    if ((n % 10) % 2)
    printf("%d\n", n % 10);
        printf("Odd");
    else
        printf("Even");
    return 0;
}