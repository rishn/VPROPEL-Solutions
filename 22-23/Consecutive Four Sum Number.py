#INPUT
'''
10
'''

#OUTPUT
'''
1
1

'''

#PSEUDOCODE/ALGORITHM
'''
Consecutive_Four_Sum_Number(int n)
{
    if (4 * floor(n / 4) + 2 == n)
    {
        print 1, floor(n / 4) - 1 separated by newline
    }
    else
    {
        print 0
    }
}
'''

#CODE
n = int(input())
print(f"1\n{(n // 4) - 1}" if 4 * (n // 4) + 2 == n else 0)

#C
'''
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    if (4 * (n / 4) + 2 == n)
        printf("1\n%d", n / 4 - 1);
    else
        printf("0");
    return 0;
}
'''

#C++
'''
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (4 * (n / 4) + 2 == n)
        cout << "1\n" << n / 4 - 1;
    else
        cout << 0;
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
        if (4 * (n / 4) + 2 == n)
            System.out.println("1\n" + (n / 4 - 1));
        else
            System.out.println(0);
    }
}
'''