#INPUT
'''
22BCE1888
'''

#OUTPUT
'''
YES
2026

'''

#PSEUDOCODE/ALGORITHM
'''
Reg_Num(char[] reg)
{
    i <- 0
    chk <- 0
    if (length(reg) == 9)
    {
        until (i >= 8)
        {
            if (48 > reg[i] || reg[i] > 57)
            {
                chk = 1
                break
            }
            if (i == 1)
                i += 3
            i += 1
        }
        if (chk == 1)
        {
            print "NO"
            return
        }
        i <- 2
        until (i >= 5)
        {
            if (65 > reg[i] || reg[i] > 90)
            {
                chk = 1
                break
            }
            i += 1
        }
        if (chk == 1)
        {
            print "NO"
        }
        else
        {
            print "YES", (2000 + (reg[0] - 48) * 10 + (reg[1] - 48) + 4) separated by newline
        }
    }
    else
    {
        print "NO"
    }
}
'''

#CODE
import re
reg = input()
if re.match(r'^\d{2}[A-Z]{3}\d{4}$', reg):
    print("YES", 2000 + int(reg[ : 2]) + 4, sep = "\n") 
else:
    print("NO")

#C
'''
#include <stdio.h>
#include <string.h>
int main()
{
    char reg[100];
    scanf("%s", reg);
    int i = 0, chk = 0;
    if (strlen(reg) == 9)
    {
        while (i < 8)
        {
            if (48 > reg[i] || reg[i] > 57)
            {
                chk = 1;
                break;
            }
            if (i == 1)
                i += 3;
            i++;
        }
        if (chk)
        {
            printf("NO\n");
            return 0;
        }
        for (i = 2; i < 5; i++)
            if (65 > reg[i] || reg[i] > 90)
            {
                chk = 1;
                break;
            }
        if (chk)
            printf("NO\n");
        else
            printf("YES\n%d\n", 2000 + (reg[0] - 48) * 10 + (reg[1] - 48) + 4);
    }
    else
        printf("NO\n");
    return 0;
}
'''

#C++
'''
#include <iostream>
using namespace std;
int main()
{
    string reg;
    cin >> reg;
    int i = 0, chk = 0;
    if (reg.length() == 9)
    {
        while (i < 8)
        {
            if (48 > reg[i] || reg[i] > 57)
            {
                chk = 1;
                break;
            }
            if (i == 1)
                i += 3;
            i++;
        }
        if (chk)
        {
            cout << "NO\n";
            return 0;
        }
        for (i = 2; i < 5; i++)
            if (65 > reg[i] || reg[i] > 90)
            {
                chk = 1;
                break;
            }
        if (chk)
            cout << "NO\n";
        else
            cout << "YES\n" << 2000 + (reg[0] - 48) * 10 + (reg[1] - 48) + 4 << "\n";
    }
    else
        cout << "NO\n";
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
        char[] reg = sc.nextLine().toCharArray();
        int i = 0, chk = 0;
        if (reg.length == 9)
        {
            while (i < 8)
            {
                if (48 > reg[i] || reg[i] > 57)
                {
                    chk = 1;
                    break;
                }
                if (i == 1)
                    i += 3;
                i++;
            }
            if (chk == 1)
            {
                System.out.println("NO");
                return;
            }
            for (i = 2; i < 5; i++)
                if (65 > reg[i] || reg[i] > 90)
                {
                    chk = 1;
                    break;
                }
            if (chk == 1)
                System.out.println("NO");
            else
                System.out.println("YES\n" + (2000 + (reg[0] - 48) * 10 + (reg[1] - 48) + 4));
        }
        else
            System.out.println("NO");
    }
}
'''
