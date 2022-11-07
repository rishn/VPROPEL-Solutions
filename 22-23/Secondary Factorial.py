#INPUT
'''
24
'''

#OUTPUT
'''
8
'''

#PSEUDOCODE/ALGORITHM
'''
SF(int n)
{
    p <- 1;
    i <- 2 + n % 2
    until (i > n)
    {
        p *= i
        i += 2
    }
    return p
}
Secondary_Factorial(int k)
{
    n <- 2
    until (k == n)
    {
        k /= n
        if (k < n)
        {
            return -1
        }
        n += 1
    }
    return SF(n)
}
'''

#CODE
def sf(n):
    p = 1
    for i in range(2 + n % 2, n + 1, 2):
        p *= i
    return p
n, k = 2, int(input())
while (k != n):
    k, n = k / n, n + 1
    if (k < n):
        print(-1)
        break
else:
    print(sf(n))

#C
'''
#include <stdio.h>
int sf(int n)
{
    int i, p = 1;
    for (i = 2 + n % 2; i <= n; i += 2)
        p *= i;
    return p;
}
int main()
{
    int n, k;
    scanf("%d", &k);
    for (n = 2; k != n; n++)
    {
        k /= n;
        if (k < n)
        {
            printf("-1");
            return 0;
        }
    }
    printf("%d", sf(n));
    return 0;
}
'''

#C++
'''
#include <iostream>
using namespace std;
int sf(int n)
{
    int i, p = 1;
    for (i = 2 + n % 2; i <= n; i += 2)
        p *= i;
    return p;
}
int main()
{
    int n, k;
    cin >> k;
    for (n = 2; k != n; n++)
    {
        k /= n;
        if (k < n)
        {
            cout << -1;
            return 0;
        }
    }
    cout << sf(n);
    return 0;
}
'''

#JAVA
'''
import java.util.Scanner;
class Main
{
    static int sf(int n)
    {
        int i, p = 1;
        for (i = 2 + n % 2; i <= n; i += 2)
            p *= i;
        return p;
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n, k = sc.nextInt();
        for (n = 2; k != n; n++)
        {
            k /= n;
            if (k < n)
            {
                System.out.println(-1);
                return;
            }
        }
        System.out.println(sf(n));
    }
}
'''