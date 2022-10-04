#INPUT
'''
2
24 30 36
60 120 90
'''

#OUTPUT
'''
6
30

'''

#PSEUDOCODE/ALGORITHM
'''
gcd(int x, int y, int z)
{
    if (z == 1)
    {
        hcf <- 1
        i <- 2
        until (i > min(x, y))
        {
            if (x % i == 0 && y % i == 0)
            {
                hcf <- i
            }
            i += 1
        }
        return hcf
    }
    return gcd(gcd(x, y, 1), z, 1)
}
'''

#CODE
def gcd(x, y, z):
    if z == 1:
        hcf = 1
        for i in range(2, min(x, y) + 1):
            if not (x % i) and not (y % i):
                hcf = i
        return hcf
    return gcd(gcd(x, y, 1), z, 1)
for i in range(int(input())):
    x, y, z = map(int, input().split())
    print(gcd(x, y, z))

#C
'''
#include <stdio.h>
int gcd(int x, int y, int z)
{
    if (z == 1)
    {
        int i, hcf = 1;
        for (i = 2; i <= (x < y ? x : y); i++)
            if (! (x % i) && ! (y % i))
                hcf = i;
        return hcf;
    }
    return gcd(gcd(x, y, 1), z, 1);
}
int main()
{
    int i, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        printf("%d\n", gcd(x, y, z));
    }
}
'''

#C++
'''
#include <iostream>
using namespace std;
int gcd(int x, int y, int z)
{
    if (z == 1)
    {
        int i, hcf = 1;
        for (i = 2; i <= min(x, y); i++)
            if (! (x % i) && ! (y % i))
                hcf = i;
        return hcf;
    }
    return gcd(gcd(x, y, 1), z, 1);
}
int main()
{
    int i, n;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        cout << gcd(x, y, z) << endl;
    }
}
'''

#JAVA
'''
import java.util.Scanner;
import java.lang.Math;
class Main
{
    static int gcd(int x, int y, int z)
    {
        if (z == 1)
        {
            int i, hcf = 1;
            for (i = 2; i <= Math.min(x, y); i++)
                if (x % i == 0 && y % i == 0)
                hcf = i;
            return hcf;
        }
        return gcd(gcd(x, y, 1), z, 1);
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; i++)
        {
            int x = sc.nextInt(), y = sc.nextInt(), z = sc.nextInt();
            System.out.println(gcd(x, y, z));
        }
    }
}
'''
