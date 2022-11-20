#INPUT
'''
230
170
310
217
6
12
11
7
8
'''

#OUTPUT
'''
3 35
'''

#PSEUDOCODE/ALGORITHM
'''
Ant_Gather_Food()
{
    read h, up, level, down, s_up, s_down, s_level, st_up, st_down
    t <- ceil((up + down) * (1 / s_up + 1 / s_down) + 2 * level / s_level + h / st_up + h / st_down)
    print ((t - (t % 60)) / 60) + " " + (t % 60)
}
'''

#CODE
from math import ceil
h, up, level, down = (int(input()) for _ in range(4))
t = ceil((up + down) * (1 / int(input()) + 1 / int(input())) + 2 * level / int(input()) + h / int(input()) + h / int(input()))
print((t - t % 60) // 60, t % 60)

#C
'''
#include <stdio.h>
#include <math.h>
int main()
{
    double h, up, level, down, s_up, s_down, s_level, st_up, st_down;
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf", &h, &up, &level, &down, &s_up, &s_down, &s_level, &st_up, &st_down);
    int t = ceil((up + down) * (1 / s_up + 1 / s_down) + 2 * level / s_level + h / st_up + h / st_down);
    printf("%d %d", (t - (t % 60)) / 60, t % 60);
    return 0;
}
'''

#C++
'''
#include <iostream>
#include <cmath>
int main()
{
    double h, up, level, down, s_up, s_down, s_level, st_up, st_down;
    std::cin >> h >> up >> level >> down >> s_up >> s_down >> s_level >> st_up >> st_down;
    int t = ceil((up + down) * (1 / s_up + 1 / s_down) + 2 * level / s_level + h / st_up + h / st_down);
    std::cout << (t - (t % 60)) / 60 << " " << t % 60;
    return 0;
}
'''

#JAVA
'''
import java.util.Scanner;
import java.lang.Math;
class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        double h = sc.nextInt(), up = sc.nextInt(), level = sc.nextInt(), down = sc.nextInt();
        int t = (int)Math.ceil((up + down) * (1 / sc.nextDouble() + 1 / sc.nextDouble()) + 2 * level / sc.nextDouble() + h / sc.nextDouble() + h / sc.nextDouble());
        System.out.println(((t - t % 60) / 60) + " " + (t % 60));
    }
}
'''