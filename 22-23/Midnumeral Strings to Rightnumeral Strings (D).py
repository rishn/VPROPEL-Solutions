#INPUT
'''
a1b2c
'''

#OUTPUT
'''
abc21
'''

#PSEUDOCODE/ALGORITHM
'''
Midnumeral_Strings_to_Rightnumeral_Strings(char array s)
{
    j <- -1
    k <- 0
    stk <- char array of size length(s)
    res <- char array of size length(s)
    i <- 0
    until (i >= length(s))
    {
        if (s[i] == ')')
        {
            until (j < 0 || stk[j] == '(')
            {
                res[k] <- stk[j]
                k += 1
                j -= 1
            }
            j -= 1
        }
        else if (96 < s[i] && s[i] < 123)
        {
            res[k] <- s[i]
            k += 1
        }
        else
        {
            if (47 < s[i] && s[i] < 58)
                until (j < 0 || stk[j] <= s[i])
                {
                    res[k] <- stk[j]
                    k += 1
                    j -= 1
                }
            j += 1
            stk[j] <- s[i]
        }
        i += 1
    }
    until (j < 0)
    {
        res[k] <- stk[j]
        k += 1
        j -= 1
    }
    print res
}
'''

#CODE
s, stk, res = input(), [], ''
for i in range(len(s)):
    if s[i] == ')':
        while (stk != [] and stk[-1] != '('):
            res += stk.pop()
        stk.pop()
    elif 96 < ord(s[i]) and ord(s[i]) < 123:
        res += s[i]
    else:
        if 47 < ord(s[i]) and ord(s[i]) < 58:
            while (stk != [] and stk[-1] > s[i]):
                res += stk.pop()
        stk.append(s[i])
while (stk != []):
    res += stk.pop()
print(res)

#C
'''
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int i, j = -1, k = 0;
    char s[50];
    scanf("%s", &s);
    char *stk = (char *)malloc(sizeof(char) * strlen(s)),
         *res = (char *)malloc(sizeof(char) * strlen(s));
    for (i = 0; i < strlen(s); i++)
        if (s[i] == ')')
        {
            while (j >= 0 && stk[j] != '(')
                res[k++] = stk[j--];
            j--;
        }
        else if (96 < s[i] && s[i] < 123)
            res[k++] = s[i];
        else
        {
            if (47 < s[i] && s[i] < 58)
                while (j >= 0 && stk[j] > s[i])
                    res[k++] = stk[j--];
            stk[++j] = s[i];
        }
    while (j >= 0)
        res[k++] = stk[j--];
    printf("%s", res);
    return 0;
}
'''

#C++
'''
#include <iostream>
using namespace std;
int main()
{
    int i, j = -1;
    string s, stk = "", res = "";
    cin >> s;
    for (i = 0; i < s.length(); i++)
        if (s[i] == ')')
        {
            while (j >= 0 && stk[j] != '(')
                res += stk[j--];
            j--;
        }
        else if (96 < s[i] && s[i] < 123)
            res += s[i];
        else
        {
            if (47 < s[i] && s[i] < 58)
                while (j >= 0 && stk[j] > s[i])
                    res += stk[j--];
            stk[++j] = s[i];
        }
    while (j >= 0)
        res += stk[j--];
    cout << res;
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
        int i, j = -1;
        String res = "";
        Scanner sc = new Scanner(System.in);
        char[] s = sc.next().toCharArray(), stk = new char[s.length];
        for (i = 0; i < s.length; i++)
            if (s[i] == ')')
            {
                while (j >= 0 && stk[j] != '(')
                    res += stk[j--];
                j--;
            }
            else if (96 < s[i] && s[i] < 123)
                res += s[i];
            else
            {
                if (47 < s[i] && s[i] < 58)
                    while (j >= 0 && stk[j] > s[i])
                        res += stk[j--];
                stk[++j] = s[i];
            }
        while (j >= 0)
            res += stk[j--];
        System.out.println(res);
    }
}
'''