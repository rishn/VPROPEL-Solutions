#INPUT
'''
5
3 2 1 5 3
9 7 2 1 4
6 6 9 8 4
'''

#OUTPUT
'''
YES
'''

#PSEUDOCODE/ALGORITHM
'''
Eren_Yeager_and_Survey_Corps()
{
    read n
    a <- int 2D array of size 3 x n
    b <- int array of zeroes of size n
    i <- 0
    until (i >= 3)
    {
        j <- 0
        until (j >= n)
        {
            read a[i][j]
            j += 1
        }
        i += 1
    }
    i <- 0
    until (i = 0; i < n; i++)
    {
        j <- 0
        until (j >= 3)
        {
            b[i] += a[j][i]
            j += 1
        }
    }
    e <- b[0]
    i <- 0
    until (i >= 3)
    {
        max <- b[i]
        k <- i
        j <- i + 1
        until (j >= n)
        {
            if (max < b[j])
            {
                max <- b[j]
                k <- j
            }
            j += 1
        }
        if (max != b[i])
        {
            b[k] <- b[i]
            b[i] <- max
        }
        if (e == b[i])
        {
            print "YES"
            return
        }
        i += 1
    }
    print "NO"
}
'''

#CODE
a, n = [], int(input())
for i in range(3):
    a.append(list(map(int, input().split())))
a = [sum(a[j][i] for j in range(3)) for i in range(n)]
e = a[0]
a.remove(max(a))
a.remove(max(a))
print("NO" if e < max(a) else "YES")

#C
'''
#include <stdio.h>
int main()
{
    int e, n, i, j, k, max;
    scanf("%d", &n);
    int a[3][n], b[n] = {0};
    for (i = 0; i < 3; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for (i = 0; i < n; i++)
        for (j = 0; j < 3; j++)
            b[i] += a[j][i];
    e = b[0];
    for (i = 0; i < 3; i++)
    {
        max = b[i];
        k = i;
        for (j = i + 1; j < n; j++)
            if (max < b[j])
            {
                max = b[j];
                k = j;
            }
        if (max != b[i])
        {
            b[k] = b[i];
            b[i] = max;
        }
        if (e == b[i])
        {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}
'''

#C++
'''
#include <iostream>
using namespace std;
int main()
{
    int e, n, i, j, k, max;
    cin >> n;
    int a[3][n], b[n] = {0};
    for (i = 0; i < 3; i++)
        for (j = 0; j < n; j++)
            cin >> a[i][j];
    for (i = 0; i < n; i++)
        for (j = 0; j < 3; j++)
            b[i] += a[j][i];
    e = b[0];
    for (i = 0; i < 3; i++)
    {
        max = b[i];
        k = i;
        for (j = i + 1; j < n; j++)
            if (max < b[j])
            {
                max = b[j];
                k = j;
            }
        if (max != b[i])
        {
            b[k] = b[i];
            b[i] = max;
        }
        if (e == b[i])
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
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
        int e, i, j, k, max, n = sc.nextInt();
        int a[][] = new int[3][n];
        int b[] = new int[n];
        for (i = 0; i < 3; i++)
            for (j = 0; j < n; j++)
                a[i][j] = sc.nextInt();
        for (i = 0; i < n; i++)
            for (j = 0; j < 3; j++)
                b[i] += a[j][i];
        e = b[0];
        for (i = 0; i < 3; i++)
        {
            max = b[i];
            k = i;
            for (j = i + 1; j < n; j++)
                if (max < b[j])
                {
                    max = b[j];
                    k = j;
                }
            if (max != b[i])
            {
                b[k] = b[i];
                b[i] = max;
            }
            if (e == b[i])
            {
                System.out.println("YES");
                return;
            }
        }
        System.out.println("NO");
    }
}
'''