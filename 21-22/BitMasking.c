// INPUT
/*
268435446
1006
*/

// OUTPUT
/*
1 2 3 6 7 8 9 10 29 30 31 32
*/

// PSEUDOCODE
/*
READ unsigned integer inputs, m, n
FOR every number i FROM 1 to 32
    SET t1 to m MOD 2, t2 to n MOD 2
    IF t1 EQUAL t2 THEN
        PRINT i + " " 
    ENDIF
    DIVIDE m by 2, DIVIDE n by 2
ENDFOR
*/

// CODE
#include <stdio.h>
int main()
{
    unsigned m, n;
    scanf("%u %u", &m, &n);
    for (int i = 1; i <= 32; i++)
    {
        int t1 = m % 2, t2 = n % 2;
        if (t1 == t2)
            printf("%d ", i);
        m /= 2, n /= 2;
    }
    return 0;
}