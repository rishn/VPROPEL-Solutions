// INPUT
/*
31
*/

// OUTPUT
/*
30
Green
*/

// PSEUDOCODE
/*
FUNCTION chair(parameters : arr, colour, x, t)
    FOR every number i FROM 0 to 3
        IF ith index arr element EQUAL t THEN
            IF 2 divides i THEN
                INCREMENT i
            ELSE
                DECREMENT i
            ENDIF
            PRINT (x + arr[i]) +"\n" + colour
            RETURN 1
        ENDIF
    ENDFOR
    RETURN 0
ENDFUNCTION
SET g to {1, 12, 6, 7}, o to {2, 11, 5, 8}, b to {3, 10, 4, 9}
READ integer input, x
SET to x MOD 12
IF NOT t THEN
    SET t to 12
ENDIF
SUBTRACT t from x
CALL chair() with g, "Green", x, t
    RETURNING integer as temp
IF ! temp THEN
    CALL chair() with o, "Orange", x, t
        RETURNING integer as temp
    IF ! temp THEN
        CALL chair() with b, "Blue", x, t
            RETURNING integer
    ENDIF
ENDIF
*/

// CODE
#include <stdio.h>
#include <string.h>
int chair(int arr[], char colour[6], int x, int t)
{
    for (int i = 0; i < 4; i++)
        if (arr[i] == t) 
        {
            if (i % 2)
                i--;
            else
                i++;
            printf("%d\n%s", x + arr[i], colour);
            return 1;
        }
    return 0;
}
int main()
{
    int g[] = {1, 12, 6, 7}, o[] = {2, 11, 5, 8}, b[] = {3, 10, 4, 9}, 
    x, y;
    scanf("%d", &x);
    int t = x % 12;
    if (! t)
        t = 12;
    x -= t;
    if (! chair(g, "Green", x, t) && ! chair(o, "Orange", x, t))
            chair(b, "Blue", x, t);
    return 0;
}