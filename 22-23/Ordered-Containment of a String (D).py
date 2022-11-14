#INPUT
'''
anotherrandomstring
rre
'''

#OUTPUT
'''
No

'''

#ALGORITHM/PSEUDOCODE
'''
Ordered_Containment(char array s1, char array s2)
{
    i <- 0
    until (i >= length(s1))
    {
        if (s1[i] == s2[0])
        {
            k <- 1
            j <- 0
            until (j >= length(s2))
            {
                c <- 1
                l <- k
                until (l >= length(s1))
                {
                    if (s2[j] == s1[l])
                    {
                        c <- 0
                        break
                    }
                    l += 1
                }
                if (c == 1)
                {
                    print "No"
                    return
                }
                k <- l + 1
                j += 1
            }
            print "Yes"
            return
        }
        i += 1
    }
    print "No"
    return
}
'''

#CODE
s1, s2 = input(), input()
for i in s1:
    if i == s2[0]:
        k, c = 0, 0
        for j in s2:
            for l in range(k, len(s1)):
                if (j == s1[l]):
                    break
            else:
                print("No")
                c = 1
                break
            k = l + 1
        else:
            print("Yes")
            break
        if c == 1:
            break
else:
    print("No")

#C
'''
#include <stdio.h>
#include <string.h>
int main()
{
    int i, j, k, l, c;
    char s1[50], s2[50];
    scanf("%s %s", &s1, &s2);
    for (i = 0; i < strlen(s1); i++)
    {
        if (s1[i] == s2[0])
        {
            k = 1;
            for (j = 0; j < strlen(s2); j++)
            {
                c = 1;
                for (l = k; l < strlen(s1); l++)
                    if (s2[j] == s1[l])
                    {
                        c = 0;
                        break;
                    }
                if (c)
                {
                    printf("No");
                    return 0;
                }
                k = l + 1;
            }
            printf("Yes");
            return 0;
        }
    }
    printf("No");
    return 0;
}
'''

#C++
'''
#include <iostream>
using namespace std;
int main()
{
    int i, j, k, l, c;
    string s1, s2;
    cin >> s1 >> s2;
    for (i = 0; i < s1.length(); i++)
    {
        if (s1[i] == s2[0])
        {
            k = 1;
            for (j = 0; j < s2.length(); j++)
            {
                c = 1;
                for (l = k; l < s1.length(); l++)
                    if (s2[j] == s1[l])
                    {
                        c = 0;
                        break;
                    }
                if (c)
                {
                    cout << "No";
                    return 0;
                }
                k = l + 1;
            }
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
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
        int i, j, k, l, c;
        char[] s1 = sc.next().toCharArray(), s2 = sc.next().toCharArray();
        for (i = 0; i < s1.length; i++)
        {
            if (s1[i] == s2[0])
            {
                k = 1;
                for (j = 0; j < s2.length; j++)
                {
                    c = 1;
                    for (l = k; l < s1.length; l++)
                        if (s2[j] == s1[l])
                        {
                            c = 0;
                            break;
                        }
                    if (c == 1)
                    {
                        System.out.println("No");
                        return;
                    }
                    k = l + 1;
                }
                System.out.println("Yes");
                return;
            }
        }
        System.out.println("No");
    }
}       
'''