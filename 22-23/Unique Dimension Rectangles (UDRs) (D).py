#INPUT
'''
168
'''

#OUTPUT
'''
8
1 168
2 84
3 56
4 42
6 28
7 24
8 21
12 14

'''

#PSEUDOCODE/ALGORITHM
'''
UDRs(int n)
{
    j <- 0
    l <- 2D int array of size 1
    i <- 1
    until (i >= n / 4)
    {
        if (n % i == 0 && n / i > i)
        {
            l[j] <- int array of size 2
            l[j][0] <- i
            l[j][1] <- floor(n / i)
            j += 1
            l <- 2D int array of size (j + 1)
        }
        i += 1
    }
    print j + "\n"
    i <- 0
    until (i >= j)
    {
        print l[i][0] + " " + l[i][1] + "\n"
        i += 1
    } 
}
'''

#CODE
n, l = int(input()), []
for i in range(1, n // 4):
    if not n % i and n / i > i:
        l.append([i, n // i])
print(len(l))
for i in l:
    print(f'{i[0]} {i[1]}')

#C
'''
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, n, j = 0;
    scanf("%d", &n);
    int **l = (int **)malloc(sizeof(int *));
    for (i = 1; i < n / 4; i++)
        if (! (n % i) && n / i > i)
        {
            l[j] = (int *)malloc(sizeof(int) * 2);
            l[j][0] = i;
            l[j++][1] = n / i;
            l = (int **)realloc(l, (j + 1) * sizeof(int *));
        }
    printf("%d\n", j);
    for (i = 0; i < j; i++)
        printf("%d %d\n", l[i][0], l[i][1]);
}
'''

#C++
'''
#include <iostream>
using namespace std;
int main()
{
    int i, n, j = 0;
    cin >> n;
    int **l = new int*[n / 4 - 1];
    for (i = 1; i < n / 4; i++)
        if (! (n % i) && n / i > i)
        {
            l[j] = new int[2];
            l[j][0] = i;
            l[j++][1] = n / i;
        }
    cout << j << endl;
    for (i = 0; i < j; i++)
        cout << l[i][0] << " " << l[i][1] << endl;
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
        int i, n, j = 0;
        n = sc.nextInt();
        int[][] l = new int[n / 4][2];
        for (i = 1; i < n / 4; i++)
            if (n % i == 0 && n / i > i)
            {
                l[j][0] = i;
                l[j++][1] = n / i;
            }
        System.out.println(j);
        for (i = 0; i < j; i++)
            System.out.println(l[i][0] + " " + l[i][1]);
    }
}
'''