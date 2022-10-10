#INPUT
'''
good
10
'''

#OUTPUT
'''
10

'''

#PSEUDOCODE/ALGORITHM
'''
Select_Winner(char array w, int n)
{
    j <- 0
    l <- length(w)
    s1 <- char array of size n
    s2 <- char array of size n
    s3 <- char array of size n
    i <- 0
    until (i >= n)
    {
        if (j == l)
            j <- 0
        s1[i] = w[j]
        j += 1
        i += 1
    }
    i <- 0
    until (i >= n)
    {
        if (j == l)
            j <- 0
        s2[i] = w[j]
        j += 1
        i += 1
    }
    i <- 0
    until (i >= n)
    {
        s3[i] = s1[n - i -1]
        i += 1
    }
    i <- 0
    until (i >= n)
    {
        if (s3[i] == s2[i])
        {
            return n - i
        }
    }
    return -1
}
'''

#CODE
w, n = input(), int(input())
l = len(w)
s1, s2 = (w * (n // l + 1))[ : n][ : : -1], (w[n % l : ] + w * (n // l + 1))[ : n]
for i in range(n):
    if s1[i] == s2[i]:
        print(n - i)
        break
else:
    print(-1)

#C
'''
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char w[50];
    scanf("%s", &w);
    int n, i, j = 0, l = strlen(w);
    scanf("%d", &n);
    char *s1 = (char *)malloc(sizeof(char) * n), *s2 = (char *)malloc(sizeof(char) * n), *s3 = (char *)malloc(sizeof(char) * n);
    for (i = 0; i < n; i++)
    {
        if (j == l)
            j = 0;
        s1[i] = w[j++];
    }
    for (i = 0; i < n; i++)
    {
        if (j == l)
            j = 0;
        s2[i] = w[j++];
    }
    for (i = 0; i < n; i++)
        s3[i] = s1[n - i - 1];
    for (i = 0; i < n; i++)
        if (s3[i] == s2[i])
        {
            printf("%d", n - i);
            return 0;
        }
    printf("%d", -1);
    return 0;
}
'''

#C++
'''
#include <iostream>
using namespace std;
int main()
{
    string w;
    cin >> w;
    int n, i, j = 0, l = w.length();
    scanf("%d", &n);
    string s1, s2, s3;
    for (i = 0; i < n; i++)
    {
        if (j == l)
            j = 0;
        s1 += w[j++];
    }
    for (i = 0; i < n; i++)
    {
        if (j == l)
            j = 0;
        s2 += w[j++];
    }
    for (i = 0; i < n; i++)
        s3 += s1[n - i - 1];
    for (i = 0; i < n; i++)
        if (s3[i] == s2[i])
        {
            cout << n - i;
            return 0;
        }
    cout << -1;
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
        char[] w = sc.next().toCharArray();
        int i, j = 0, n = sc.nextInt(), l = w.length;
        char[] s1 = new char[n], s2 = new char[n], s3 = new char[n];
        for (i = 0; i < n; i++)
        {
            if (j == l)
                j = 0;
            s1[i] = w[j++];
        }
        for (i = 0; i < n; i++)
        {
            if (j == l)
                j = 0;
            s2[i] = w[j++];
        }
        for (i = 0; i < n; i++)
            s3[i] = s1[n - i - 1];
        for (i = 0; i < n; i++)
            if (s3[i] == s2[i])
            {
                System.out.println(n - i);
                return;
            }
        System.out.println(-1);
    }
}
'''