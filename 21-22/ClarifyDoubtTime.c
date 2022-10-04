// INPUT
/*
3
5
7
8
2
*/

// OUTPUT
/*
13
18
20
*/

// PSEUDOCODE
/*
READ integer input, n
DECLARE integer array doubts
FOR every number i from 0 to n - 1
    READ integer input, ith index doubts element
ENDFOR
READ integer input, t
FOR every number i from 0 to n - 1
    SET doubt to ith index doubts element, time to 0
    SET temp to COPY of array doubts
    WHILE doubt > 0
        FOR every number j from 0 to n - 1
            IF jth index temp element >= t THEN
                SUBTRACT t from jth index temp element
                ADD t to time
            ELSE IF jth index temp element THEN
                ADD jth index temp element to time
                SET jth index temp element to 0
            ENDIF
            IF i EQUAL j THEN
                SUBTRACT t from doubt
                IF doubt <= 0 THEN
                    BREAK
                ENDIF
            ENDIF
        ENDFOR
    ENDWHILE
    PRINT time + "\n"
ENDFOR
*/

// CODE
#include <stdio.h>
int main()
{
    int i, j, n, t, doubts[1000];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &doubts[i]);
    scanf("%d", &t);
    for (i = 0; i < n; i++)
    {
        int doubt = doubts[i], temp[sizeof(doubts)], time = 0;
        for (j = 0; j < n; j++)
            temp[j] = doubts[j];
        while (doubt > 0)
        {
            for (j = 0; j < n; j++)
            {
                if (temp[j] >= t)
                {
                    temp[j] -= t;
                    time += t;
                }
                else if (temp[j])
                {
                    time += temp[j];
                    temp[j] = 0;
                }
                if (i == j)
                {
                    doubt -= t;
                    if (doubt <= 0)
                        break;
                }
            }
        }
        printf("%d\n", time);
    }
    return 0;
}