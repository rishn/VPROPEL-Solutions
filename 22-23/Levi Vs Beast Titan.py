#INPUT
'''
5 10
3 2 1 5 3
'''

#OUTPUT
'''
YES

'''

#PSEUDOCODE/ALGORITHM
'''
Levi_Vs_Beast_Titan()
{
    read n, l
    d <- 0
    until (n <= 0)
    {
        read t
        d += t
        n -= 1
    }
    if (l > d * 0.5)
    {
        print "YES"
    }
    else
    {
        print "NO"
    }
}
'''

#CODE
n, l = map(int, input().split())
print("YES" if l > sum(map(int, input().split())) * 0.5 else "NO")

#C
'''
#include <stdio.h>
int main()
{
    int n, l, t, d = 0;
    scanf("%d %d", &n, &l);
    for (; n > 0; n--)
    {
        scanf("%d", &t);
        d += t;
    }
    if (l > d * 0.5)
        printf("YES");
    else
        printf("NO");
    return 0;
}
'''

#C++
'''
#include <iostream>
using namespace std;
int main()
{
    int n, l, t, d = 0;
    cin >> n >> l;
    for (; n > 0; n--)
    {
        cin >> t;
        d += t;
    }
    if (l > d * 0.5)
        cout << "YES";
    else
        cout << "NO";
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
        int n = sc.nextInt(), l = sc.nextInt(), d = 0;
        for (; n > 0; n--)
            d += sc.nextInt();
        if (l > d * 0.5)
            System.out.println("YES");
        else
            System.out.println("NO");
    }
}
'''