#INPUT
'''
123456789451
'''

#OUTPUT
'''
12321
'''

#PSEUDOCODE/ALGORITHM
'''
Perfect_Square()
{
    arr <- int array containing 11111, 12345, 99856 
    n <- 0
    until (n >= 3)
    {    
        s <- 0
        i <- 1
        until (i >= arr[n] / 2)
        {
            s += i
            if (s == arr[n])
            {
                return arr[n]
            }
            i += 2
        }
        n += 1
    }
}
Palindrome()
{
    arr <- 2D char array containing "12321", "12345", "56789"
    n <- 0
    until (n >= 3)
    {
        chk <- 1
        i <- 0
        until (i >= length(arr[n]) / 2)
        {
            if (arr[n][i] != arr[n][length(arr[n]) - i - 1])
            {
                chk <- 0
                break
            }
            i += 1
        }
        if (chk == 1)
            return arr[n]
    }
}
Security_Number(long int n)
{
    s <- 0
    while (n > 0)
    {
        s += n % 10
        n /= 10
    }
    if (s % 2 == 1)
        print Palindrome()
    else 
        print Perfect_Square()
}
'''

#CODE
def perfect_square():
    for n in [11111, 12345, 99856]:    
        s = 0
        for i in range(1, n // 2, 2):
            s += i
            if s == n:
                return n
def palindrome():
    for n in ['12321', '12345', '56789']:
        for i in range(len(n) // 2):
            if n[i] != n[len(n) - i - 1]:
                break
        else:
            return n
s = 0
for i in input():
    s += int(i)
print(palindrome() if s % 2 else perfect_square())

#C
'''
#include <stdio.h>
#include <string.h>
int perfect_square()
{
    int i, n, s, arr[] = {11111, 12345, 99856}; 
    for (n = 0; n < 3; n++)
    {    
        s = 0;
        for (i = 1; i < arr[n] / 2; i += 2)
        {
            s += i;
            if (s == arr[n])
                return arr[n];
        }
    }
}
void palindrome()
{
    int i, n, chk;
    char arr[][6] = {"12321", "12345", "56789"};
    for (n = 0; n < 3; n++)
    {
        chk = 1;
        for (i = 0; i < 2; i++)
            if (arr[n][i] != arr[n][4 - i])
            {
                chk = 0;
                break;
            }
        if (chk)
            printf("%s", arr[n]);
    }
}
int main()
{
    long n;
    int s = 0;
    scanf("%ld", &n);
    while (n > 0)
    {
        s += n % 10;
        n /= 10;
    }
    if (s % 2)
        palindrome();
    else 
        printf("%d", perfect_square());
    return 0;
}
'''

#C++
'''
#include <iostream>
using namespace std;
int perfect_square()
{
    int i, n, s, arr[] = {11111, 12345, 99856}; 
    for (n = 0; n < 3; n++)
    {    
        s = 0;
        for (i = 1; i < arr[n] / 2; i += 2)
        {
            s += i;
            if (s == arr[n])
                return arr[n];
        }
    }
}
string palindrome()
{
    int i, n, chk;
    string arr[] = {"12321", "12345", "56789"};
    for (n = 0; n < 3; n++)
    {
        chk = 1;
        for (i = 0; i < arr[n].length() / 2; i++)
            if (arr[n][i] != arr[n][arr[n].length() - i - 1])
            {
                chk = 0;
                break;
            }
        if (chk)
            return arr[n];
    }
}
int main()
{
    long n;
    int s = 0;
    cin >> n;
    while (n > 0)
    {
        s += n % 10;
        n /= 10;
    }
    if (s % 2)
        cout << palindrome();
    else 
        cout << perfect_square();
    return 0;
}
'''

#JAVA
'''
import java.util.Scanner;
class Main
{
    static int perfect_square()
    {
        int i, n, s, arr[] = {11111, 12345, 99856}; 
        for (n = 0; n < 3; n++)
        {    
            s = 0;
            for (i = 1; i < arr[n] / 2; i += 2)
            {
                s += i;
                if (s == arr[n])
                    return arr[n];
            }
        }
        return 0;
    }
    static String palindrome()
    {
        int i, n, chk;
        String arr[] = {"12321", "12345", "56789"};
        for (n = 0; n < 3; n++)
        {
            chk = 1;
            char[] t = arr[n].toCharArray();
            for (i = 0; i < t.length / 2; i++)
                if (t[i] != t[t.length - i - 1])
                {
                    chk = 0;
                    break;
                }
            if (chk == 1)
                return arr[n];
        }
        return "";
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int s = 0;
        char[] n = sc.next().toCharArray();
        for (int i = 0; i < 12; i++)
            s += n[i] - 48;
        if (s % 2 == 1)
            System.out.print(palindrome());
        else 
            System.out.print(perfect_square());
    }
}
'''
