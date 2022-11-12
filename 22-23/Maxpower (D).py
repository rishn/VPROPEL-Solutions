#INPUT
'''
8
2
'''

#OUTPUT
'''
3.00
'''

#ALGORITHM/PSEUDOCODE
'''
Log_x(double y, double x)
{
    return log(y) / log(x) 
}
Maxpower(int x, int y)
{
    print Log_x(x, y) with 2 decimal places
}
'''

#CODE
from math import log
print("{x: .2f}".format(x = log(int(input()), int(input()))))

#C
'''
#include <stdio.h>
#include <math.h>
double log_x(double y, double x)
{
    return log(y) / log(x); 
}
int main()
{
    int x, y, l;
    scanf("%d %d", &x, &y);
    printf("%.2f", log_x(x, y));
}
'''

#C++
'''
#include <iostream>
#include <cmath>
double log_x(double y, double x)
{
    return log(y) / log(x); 
}
int main()
{
    int x, y, l;
    std::cin >> x >> y;
    printf("%.2f", log_x(x, y));
}
'''

#JAVA
'''
import java.lang.Math;
import java.util.Scanner;
class Main
{
    static double log_x(double y, double x)
    {
        return Math.log(y) / Math.log(x);
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.printf("%.2f", log_x(sc.nextDouble(), sc.nextDouble()));
    }
}
'''