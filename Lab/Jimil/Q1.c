//INPUT
/*
How many numbers7
Give 1th number4
Give 2th number5
Give 3th number2
Give 4th number5
Give 5th number6
Give 6th number4
Give 7th number7
*/

//a) OUTPUT
/*
209
*/

//a) CODE
#include <stdio.h>
int main()
{
    int x[20], sum, i, n;
    printf("How many numbers");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("Give %dth number", i);
        scanf("%d", &x[i]);
    }
    sum = 0;
    for (i = 1; i <= n - 2; i++)
        sum = sum + (x[i] + x[i + 1]) * x[i + 2];
    printf("%d", sum);
    return 0;
}

//b) OUTPUT
/*
56160
*/

//b) CODE
#include <stdio.h>
int main()
{
    int x[20], sum, i, n;
    printf("How many numbers");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("Give %dth number", i);
        scanf("%d", &x[i]);
    }
    sum = 1;
    for (i = 1; i <= n - 2; i++)
        sum = sum * (x[i] + x[i + 2]);
    printf("%d", sum);
    return 0;
}

//c) OUTPUT
/*
-7
*/

//c) CODE
#include <stdio.h>
int main()
{
    int x[20], sum, i, n;
    printf("How many numbers");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("Give %dth number", i);
        scanf("%d", &x[i]);
    }
    sum = 0;
    for (i = 1; i <= n - 2; i++)
        sum = sum + (x[i] - x[i + 1]) * (x[i + 1] + x[i + 2]);
    printf("%d", sum);
    return 0;
}