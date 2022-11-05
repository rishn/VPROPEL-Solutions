#INPUT
'''
5
1 -3 0 2 -1
'''

#OUTPUT
'''
2

'''

#PSEUDOCODE/ALGORITHM
'''
Positive_Result(int n, int array a)
{
    c <- 0
    i <- 0
    until (i >= n)
    {
        read a[i]
        i += 1
    }
    i <- 0
    until (i >= n)
    {
        j <- i + 1
        until (until j >= n)
        {
            if (a[i] * a[j] > 0)
            {
                c += 1
            }
            j += 1
        }
        i += 1
    }
    return c
}
'''

#CODE
n, a, c = int(input()), list(map(int, input().split())), 0
for i in range(n):
    for j in range(i + 1, n):
        if a[i]*a[j] > 0:
            c += 1
print(c)

#C
'''
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{
    int i, j, n, c = 0;
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (a[i] * a[j] > 0)
                c++;
    printf("%d", c);
    return 0;
}
'''

#C++
'''
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{
    int i, j, n, c = 0;
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (a[i] * a[j] > 0)
                c++;
    printf("%d", c);
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
        int i, j, n = sc.nextInt(), c = 0;
        int a[] = new int[n];
        for (i = 0; i < n; i++)
            a[i] = sc.nextInt();
        for (i = 0; i < n; i++)
            for (j = i + 1; j < n; j++)
                if (a[i] * a[j] > 0)
                    c++;
        System.out.println(c);
    }
}
'''