// INPUT
/*
27
*/

// OUTPUT
/*
4
16      11
Somu
*/

// PSEUDOCODE
/*
SET trips, r, s, last to zeroes
READ integer input, n
WHILE r + s < n
    IF 2 cannot divide trips THEN
        IF r + s + 3*trips <= n THEN
            ADD trips to r
            ADD 2*trips to s
        ELSEIF r + s + trips >= n THEN
            ADD n - r - s to r
            INCREMENT last
        ELSE THEN
            ADD trips to r 
            ADD n - r - s to s
        ENDIF
    ELSE THEN
        IF r + s + 3*trips <= n THEN
            ADD 2*trips to r
            ADD trips to s
        ELSEIF r + s + 2*trips >= n THEN
            ADD n - r - s to r
            INCREMENT last
        ELSE THEN
            ADD 2*trips to r 
            ADD n - r - s to s
        ENDIF
    ENDIF
ENDWHILE
PRINT trips + "\n" + r + "\t" + s + "\n"
IF last THEN
    PRINT "Ramu"
ELSE THEN
    PRINT "Somu"
ENDIF
*/

// CODE
#include <stdio.h>
int main()
{
    int n, trips = 0, r = 0, s = 0, last = 0;
    scanf("%d", &n);
    while (r + s < n)
    {
        trips ++;
        if (trips % 2)
            if (r + s + 3*trips <= n)
                r += trips, s += 2*trips;
            else if (r + s + trips >= n)
                r += n - r - s, last++;
            else
                r += trips, s += n - r - s;
        else
            if (r + s + 3*trips <= n)
                r += 2*trips, s += trips;
            else if (r + s + 2*trips >= n)
                r += n - r - s, last++;
            else
                r += 2*trips, s += n - r - s;
    }
    printf("%d\n%d\t%d\n", trips, r, s);
    if (last)
        printf("Ramu");
    else
        printf("Somu");
    return 0;
}