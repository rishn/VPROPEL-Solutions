#INPUT
'''
2456
'''

#OUTPUT
'''
2812
5624

'''

#PSEUDOCODE/ALGORITHM
'''
Largest_Factor_Among_Left_Rotated_Numbers(int n)
{
    p <- 1
    l <- f <- r <- 0
    t <- n
    until (t <= 0)
    {
        l += 1
        t /= 10
    }
    i <- 1
    until (i >= l)
    {
        p *= 10
        i += 1
    }
    until (i >= l)
    {
        if (n % 2 == 0)
        {
            if (n / 2 > f)
            {
                f = n / 2
                r = n
            }
        }
        else
        {
            j <- 1
            until (j >= n / 2)
            {
                if (n % j == 0 && j > f)
                {
                    f <- j
                    r <- n
                }
                j += 1
            }
        }
        q <- n / p
        n %= p
        n *= 10
        n += q
        i += 1
    }
    print f + "\n" + r
}
'''

#CODE
n, f, r = input(), 0, ''
for i in range(len(n)):
    if not int(n) % 2:
        f, r = int(n) // 2, n
    else: 
        for j in range(1, int(n) // 2, 2):
            if not int(n) % j and j > f:
                f, r = j, n
    n = n[1 : ] + n [0]
print(f, r, sep = '\n')

#C
'''
#include <stdio.h>
int main()
{
    int i, j, n, t, q, p = 1, l = 0, f = 0, r = 0;
    scanf("%d", &n);
    t = n;
    while (t > 0)
    {
        l++;
        t /= 10;
    }
    for (i = 1; i < l; i++)
        p *= 10;
    for (i = 0; i < l; i++)
    {
        if (! (n % 2))
            if (n / 2 > f)
            {
                f = n / 2;
                r = n;
            }
        else
            for (j = 1; j < n / 2; j += 2)
                if (! (n % j) && j > f)
                {
                    f = j;
                    r = n;
                }
        q = n / p;
        n %= p;
        n *= 10;
        n += q;
    }
    printf("%d\n%d", f, r);
    return 0;
}
'''

#C++
'''
#include <iostream>
using namespace std;
int main()
{
    int i, j, n, t, q, p = 1, l = 0, f = 0, r = 0;
    cin >> n;
    t = n;
    while (t > 0)
    {
        l++;
        t /= 10;
    }
    for (i = 1; i < l; i++)
        p *= 10;
    for (i = 0; i < l; i++)
    {
        if (! (n % 2))
            if (n / 2 > f)
            {
                f = n / 2;
                r = n;
            }
        else
            for (j = 1; j < n / 2; j += 2)
                if (! (n % j) && j > f)
                {
                    f = j;
                    r = n;
                }
        q = n / p;
        n %= p;
        n *= 10;
        n += q;
    }
    cout << f << endl << r;
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
        String n = sc.next(), r = "";
        int i, j, f = 0, t;
        for (i = 0; i < n.length(); i++)
        {
            t = Integer.parseInt(n);
            if (t % 2 == 0)
                if (t / 2 > f)
                {
                    f = t / 2;
                    r = n;
                }
            else
                for (j = 1; j < t / 2; j += 2)
                    if (t % j == 0 && j > f)
                    {
                        f = j;
                        r = n;
                    }
            n = n.substring(1) + n.substring(0, 1);
        }
        System.out.println(f + "\n" + r);
    }
}
'''