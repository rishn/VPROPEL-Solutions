#INPUT
'''
1284
'''

#OUTPUT
'''
YES
'''

#PSEUDOCODE/ALGORITHM
'''
Right_Digit_Numbers(int n)
{
    if ((n % 100) % floor(n / 100) == 0)
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
n = input()
print("NO" if int(n[2 : ]) % int(n[ : 2]) else "YES")

#C
'''
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    if ((n % 100) % (n / 100))
        printf("NO");
    else
        printf("YES");
    return 0;
}
'''

#C++
'''
#include <iostream>
int main()
{
    int n;
    scanf("%d", &n);
    if ((n % 100) % (n / 100))
        std::cout << "NO";
    else
        std::cout << "YES";
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
        int n = sc.nextInt();
        if ((n % 100) % (n / 100) == 0)
            System.out.println("YES");
        else
            System.out.println("NO");
    }
}
'''