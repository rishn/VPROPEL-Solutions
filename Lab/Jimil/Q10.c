//INPUT
/*
3
1 2
2 3
1 0
0 1
2 3
1 4
*/

//OUTPUT
/*
1 2
2 3

1 0
0 1

2 3
1 4

*/

//CODE
#include <stdio.h>
int main()
{
    int i, j, k, n;
    scanf("%d", &n);
    int arr[n][2][2], det[n][2];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 2; j++)
            for (k = 0; k < 2; k++)
                scanf("%d", &arr[i][j][k]);
        det[i][0] = arr[i][0][0] * arr[i][1][1] - arr[i][0][1] * arr[i][1][0];
        det[i][1] =  i;
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
            if (det[i][0] > det[j][0])
            {
                int temp[2];
                temp[0] = det[i][0], temp[1] = det[i][1];
                det[i][0] = det[j][0], det[i][1] = det[j][1];
                det[j][0] = temp[0], det[j][1] = temp[1];
            }
        printf("%d %d\n%d %d\n\n", arr[det[i][1]][0][0], arr[det[i][1]][0][1], arr[det[i][1]][1][0], arr[det[i][1]][1][1]);
    }
    return 0;
}