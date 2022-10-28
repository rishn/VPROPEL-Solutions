#INPUT
'''
4
1 2 3 3
'''

#OUTPUT
'''
3 2 0 0 
'''

#PSEUDOCODE/ALGORITHM
'''
Manipulating_the_List(int n, int array x)
{
    c <- 1
    y <- int array of size n
    i <- 1
    until (i >= n || x[i] != x[0])
    {
        c += 1
        i += 1
    }
    y[0] <- n - c
    print y[0] + " "
    i <- 0
    until (i >= n - 1)
    {
        if (x[i] != x[i + 1])
        {
            c <- 1
            j <- i + 2
            until (j >= n || x[j] != x[i + 1])
            {
                c += 1
                j += 1
            }
            y[i + 1] <- y[i] - c
        }
        else
        {
            y[i + 1] <- y[i]
        }
        print y[i + 1] + " "
        i += 1
    }
}
'''

#CODE
n, x, i, c = int(input()), list(map(int, input().split())), 1, 1
while (i < n and x[i] == x[0]):
    c += 1
    i += 1
y = [n - c]
print(y[0], end = " ")
for i in range(n - 1):
    if x[i] != x[i + 1]:
        c, j = 1, i + 2
        while (j < n and x[j] == x[i + 1]):
            c += 1
            j += 1
        y.append(y[i] - c) 
    else:
        y.append(y[i])
    print(y[i + 1], end = " ")

#C
'''
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j, n, c = 1;
    scanf("%d", &n);
    int *x = (int *)malloc(sizeof(int) * n), *y = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
        scanf("%d", &x[i]);
    for (i = 1; i < n && x[i] == x[0]; i++)
        c++;
    y[0] = n - c;
    printf("%d ", y[0]);
    for (i = 0; i < n - 1; i++)
    {
        if (x[i] != x[i + 1])
        {
            c = 1;
            for (j = i + 2; j < n && x[j] == x[i + 1]; j++)
                c++;
            y[i + 1] = y[i] - c;
        }
        else
            y[i + 1] = y[i];
        printf("%d ", y[i + 1]);
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
    int i, j, n, c = 1;
    cin >> n;
    int *x = new int(n), *y = new int(n);
    for (i = 0; i < n; i++)
        cin >> x[i];
    for (i = 1; i < n && x[i] == x[0]; i++)
        c++;
    y[0] = n - c;
    cout << y[0] << " ";
    for (i = 0; i < n - 1; i++)
    {
        if (x[i] != x[i + 1])
        {
            c = 1;
            for (j = i + 2; j < n && x[j] == x[i + 1]; j++)
                c++;
            y[i + 1] = y[i] - c;
        }
        else
            y[i + 1] = y[i];
        cout << y[i + 1] << " ";
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
        int i, j, n = sc.nextInt(), c = 1;
        int[] x = new int[n], y = new int[n];
        for (i = 0; i < n; i++)
            x[i] = sc.nextInt();
        for (i = 1; i < n && x[i] == x[0]; i++)
            c++;
        y[0] = n - c;
        System.out.print(y[0] + " ");
        for (i = 0; i < n - 1; i++)
        {
            if (x[i] != x[i + 1])
            {
                c = 1;
                for (j = i + 2; j < n && x[j] == x[i + 1]; j++)
                    c++;
                y[i + 1] = y[i] - c;
            }
            else
                y[i + 1] = y[i];
            System.out.print(y[i + 1] + " ");
        }
    }
}
'''