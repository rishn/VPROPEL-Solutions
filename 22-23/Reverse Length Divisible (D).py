#INPUT
'''
52267
'''

#OUTPUT
'''
Yes

'''

#PSEUDOCODE/ALGORITHM
'''
Reverse_Length_Divisible(int n)
{
    i <- 1
    chk <- 0
    until (n <= 0)
    {
        if (n % i > 0)
        {
            print "No"
            return
        }
        i += 1
        n /= 10
    }
    print "Yes"
}
'''

#CODE
n = input()
for i in range(len(n)):
    if int(n[ : i + 1]) % (len(n) - i):
        print("No")
        break
else:
    print("Yes")

#C
'''
#include <stdio.h>
int main()
{
    int n, i = 1;
    scanf("%d", &n);
    while (n > 0)
    {
        if (n % i)
        {
            printf("No");
            return 0;
        }
        i += 1;
        n /= 10;
    }
    printf("Yes");
    return 0;
}
'''

#C++
'''
#include <iostream>
using namespace std;
int main()
{
    int n, i = 1;
    cin >> n;
    while (n > 0)
    {
        if (n % i)
        {
            cout << "No";
            return 0;
        }
        i += 1;
        n /= 10;
    }
    cout << "Yes";
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
        int n = sc.nextInt(), i = 1;
        while (n > 0)
        {
            if (n % i > 0)
            {
                System.out.println("No");
                return;
            }
            i += 1;
            n /= 10;
        }
        System.out.println("Yes");
    }
}
'''