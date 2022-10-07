#INPUT
'''
5
1 4 2 0 7
2 3 5 1 6
'''

#OUTPUT
'''
1 3 2 0 6
2 4 5 1 7

'''

#PSEUDOCODE/ALGORITHM
'''
Array_Swapping(int array a, int array b)
{
    n <- size of a
    i <- 0
    until (i > n)
    {
        if (a[i] > b[i])
        {
            temp <- a[i]
            a[i] <- b[i]
            b[i] <- temp
        }
        i += 1
    }
    i <- 0
    until (i >= n - 1)
    {
        print a[i] + " "
        i += 1
    }
    print a[i] + newline
    i <- 0
    until (i >= n)
    {
        print a[i] + " "
        i += 1
    }
}
'''

#CODE
n, a, b = int(input()), list(map(int, input().split())), list(map(int, input().split()))
for i in range(n):
    if a[i] > b[i]:
        a[i], b[i] = b[i], a[i]
print(*a)
print(*b)

#C
'''
#include <stdio.h>
int main()
{
    int i, n, temp;
    scanf("%d", &n);
    int a[n], b[n];
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
        scanf("%d", &b[i]);
    for (i = 0; i < n; i++)
        if (a[i] > b[i])
        {
            temp = a[i];
            a[i] = b[i];
            b[i] = temp;
        }
    for (i = 0; i < n - 1; i++)
        printf("%d ", a[i]);
    printf("%d\n", a[i]);
    for (i = 0; i < n; i++)
        printf("%d ", b[i]);
    return 0;
}
'''

#C++
'''
#include <iostream>
using namespace std;
int main()
{
    int i, n, temp;
    cin >> n;
    int a[n], b[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
        cin >> b[i];
    for (i = 0; i < n; i++)
        if (a[i] > b[i])
        {
            temp = a[i];
            a[i] = b[i];
            b[i] = temp;
        }
    for (i = 0; i < n - 1; i++)
        cout << a[i] << " ";
    cout << a[i] << endl;
    for (i = 0; i < n; i++)
        cout << b[i] << " ";
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
        int n = sc.nextInt(), i, temp;
        int a[] = new int[n], b[] = new int[n];
        for (i = 0; i < n; i++)
            a[i] = sc.nextInt();
        for (i = 0; i < n; i++)
            b[i] = sc.nextInt();
        for (i = 0; i < n; i++)
            if (a[i] > b[i])
            {
                temp = a[i];
                a[i] = b[i];
                b[i] = temp;
            }
        for (i = 0; i < n - 1; i++)
            System.out.print(a[i] + " ");
        System.out.println(a[i]);
        for (i = 0; i < n; i++)
            System.out.print(b[i] + " ");
    }
}
'''