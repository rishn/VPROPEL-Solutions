#INPUT
'''
7
3
4 1 5
17
'''

#OUTPUT
'''
Levi

'''

#PSEUDOCODE/ALGORITHM
'''
Levi_vs_Titans()
{
    read l, n
    until (n <= 0)
    {
        read t
        l += t
        n -= 1
    }
    read b
    if (l == b)
    {
        print "Levi"
    }
    else if (l < b)
    {
        print "Beast"    
    }
    else
    {
        print "Jaw"
    }
}
'''

#CODE
l = int(input())
input()
l, b = l + sum(map(int, input().split())), int(input())
print("Levi" if l == b else "Beast" if l < b else "Jaw")

#C
'''
#include <stdio.h>
int main()
{
    int l, n, b, t;
    scanf("%d %d", &l, &n);
    for (; n > 0; n--)
    {
        scanf("%d", &t);
        l += t;
    }
    scanf("%d", &b);
    if (l == b)
        printf("Levi");
    else if (l < b)
        printf("Beast");
    else
        printf("Jaw");
    return 0;
}
'''

#C++
'''
#include <iostream>
using namespace std;
int main()
{
    int l, n, b, t;
    cin >> l >> n;
    for (; n > 0; n--)
    {
        cin >> t;
        l += t;
    }
    cin >> b;
    if (l == b)
        cout << "Levi";
    else if (l < b)
        cout << "Beast";
    else
        cout << "Jaw";
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
        int l = sc.nextInt(), n = sc.nextInt();
        for (; n > 0; n--)
            l += sc.nextInt();
        int b = sc.nextInt();
        if (l == b)
            System.out.println("Levi");
        else if (l < b)
            System.out.println("Beast");
        else
            System.out.println("Jaw");
    }
}
'''