#INPUT
'''
1 3 2
4 5 6
9 7 8
'''

#OUTPUT
'''
7 8 9
4 5 6
1 2 3

'''

#PSEUDOCODE/ALGORITHM
'''
Matrix_Sort(int 2D array arr)
{
    n <- order of matrix arr
    i <- 0
    until (i >= n)
    {
        j <- 0
        until (j >= n)
        {
            k <- j + 1
            until (j >= n)
            {
                if (arr[i][j] > arr[i][k])
                {
                    temp <- arr[i][j];
                    arr[i][j] <- arr[i][k];
                    arr[i][k] <- temp;
                }
                k += 1
            }
            j += 1
        }
        i += 1
    }
    i <- 0
    until (i >= n)
    {
        j <- 0
        until (j >= n)
        {
            k <- j + 1
            until (k >= n)
            {    
                if (arr[j][i] < arr[k][i])
                {
                    temp <- arr[j][i];
                    arr[j][i] <- arr[k][i];
                    arr[k][i] <- temp;
                }
                k += 1
            }
            j += 1
        }
        i += 1
    }
    return arr
}
'''

#CODE
n = int(input())
arr = [sorted(map(int, input().split())) for i in range(n)]
for i in range(n):
    for j in range(n):
        for k in range(j + 1, n):
            if (arr[j][i] < arr[k][i]):
                arr[j][i], arr[k][i] = arr[k][i], arr[j][i]
for i in arr:
    print(*i)

#C
'''
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, j, k;
    scanf("%d", &n);
    int **arr = (int **)malloc(sizeof(int *) * n);
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * n);
        for (j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            for (k = j + 1; k < n; k++)
                if (arr[i][j] > arr[i][k])
                {
                    int temp = arr[i][j];
                    arr[i][j] = arr[i][k];
                    arr[i][k] = temp;
                }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            for (k = j + 1; k < n; k++)
                if (arr[j][i] < arr[k][i])
                {
                    int temp = arr[j][i];
                    arr[j][i] = arr[k][i];
                    arr[k][i] = temp;
                }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
            printf("%d ", arr[i][j]);
        printf("%d\n", arr[i][j]);
    }
    return 0;
}
'''

#C++
'''
#include <iostream>
using namespace std;
int main()
{
    int n, i, j, k;
    scanf("%d", &n);
    int arr[n][n];
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> arr[i][j];
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            for (k = j + 1; k < n; k++)
                if (arr[i][j] > arr[i][k])
                {
                    int temp = arr[i][j];
                    arr[i][j] = arr[i][k];
                    arr[i][k] = temp;
                }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            for (k = j + 1; k < n; k++)
                if (arr[j][i] < arr[k][i])
                {
                    int temp = arr[j][i];
                    arr[j][i] = arr[k][i];
                    arr[k][i] = temp;
                }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
            cout << arr[i][j] << " ";
        cout << arr[i][j] << endl;
    }
    return 0;
}
'''

#JAVA
'''
import java.util.Scanner;
class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), i, j, k;
        int arr[][] = new int[n][n];
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                arr[i][j] = sc.nextInt();
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                for (k = j + 1; k < n; k++)
                    if (arr[i][j] > arr[i][k])
                    {
                        int temp = arr[i][j];
                        arr[i][j] = arr[i][k];
                        arr[i][k] = temp;
                    }
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                for (k = j + 1; k < n; k++)
                    if (arr[j][i] < arr[k][i])
                    {
                        int temp = arr[j][i];
                        arr[j][i] = arr[k][i];
                        arr[k][i] = temp;
                    }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n - 1; j++)
                System.out.print(arr[i][j] + " ");
            System.out.println(arr[i][j]);
        }
    }
}
'''
