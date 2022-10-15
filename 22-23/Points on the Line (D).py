#INPUT
'''
2
3
-15
3
'''

#OUTPUT
'''
4.33
3.00
1.67

'''

#PSEUDOCODE/ALGORITHM
'''
Points_On_The_Line(int a, int b, int c, int n)
{
    i <- 1
    until (i > 2 * n)
    {
        print (float)(- c - a * i) / b with 2 decimal places
        i += 2
    }
}
'''

#CODE
a, b, c = (int(input()) for i in range(3))
for i in range(1, 2 * int(input()) + 1, 2):
    print('{x:.2f}'.format(x = (- c - a * i) / b))

#C
'''
#include <stdio.h>
int main()
{
    int a, b, c, n, i;
    scanf("%d %d %d %d", &a, &b, &c, &n);
    for (i = 1; i < 2 * n + 1; i += 2)
        printf("%.2f\n", (float)(- c - a * i) / b);
    return 0;
}
'''

#C++
'''
#include <iostream>
using namespace std;
int main()
{
    int a, b, c, n, i;
    cin >> a >> b >> c >> n;
    for (i = 1; i < 2 * n + 1; i += 2)
        printf("%.2f\n", (float)(- c - a * i) / b);
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
        int a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt(), n = sc.nextInt(), i;
        for (i = 1; i < 2 * n + 1; i += 2)
            System.out.printf("%.2f\n", (float)(- c - a * i) / b);
    }
}
'''
