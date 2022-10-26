#INPUT
'''
3
9
5 4 3 8 9 7 4 7 8
15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 1
17
14 11 12 17 13 9 4 3 2 6 31 71 41 1 90 61 5
'''

#OUTPUT
'''
YES
YES
NO

'''

#PSEUDOCODE/ALGORITHM
'''
Distinct_Array()
{
    read t
    until (t <= 0)
    {
        read n
        read elements of int array a
        n <- size of a
        set <- int array of size n
        dist <- 0
        i <- 0
        until (i >= n)
        {
            chk = 1
            until (j >= dist)
            {
                if (a[i] == set[j])
                {
                    chk = 0
                    break
                }
                j += 1
            }
            if (chk == 1)
            {
                set[dist] = a[i]
                dist += 1
            }
            i += 1
        }
        if (dist % 2 == 0 || dist % 2 == 1 && n > dist)
        {
            print "YES\n"
        }
        else
        {
            print "NO\n"
        }
        t -= 1
    }
}
'''

#CODE
for i in range(int(input())):
    n, dist = int(input()), len(set(map(int, input().split())))
    print("YES" if not dist % 2 or dist % 2 and n > dist else "NO")

#C
'''
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int i, j, t, n, dist, chk, item;
    char temp[100];
    scanf("%d", &t);
    for (; t > 0; t--)
    {
        scanf("%d\n", &n);
        int i = 0, *a = (int *)malloc(sizeof(int) * n);
        fgets(temp, 100, stdin);
        char * token = strtok(temp, " ");
        while(token != NULL) {
            a[i++] = atoi(token);
            token = strtok(NULL, " ");
        }
        n = i;
        int *set = (int *)malloc(sizeof(int) * n);
        dist = 0;
        for (i = 0; i < n; i++)
        {
            chk = 1;
            for (j = 0; j < dist; j++)
                if (a[i] == set[j])
                {
                    chk = 0;
                    break;
                }
            if (chk)
                set[dist++] = a[i];
        }
        if (! (dist % 2) || dist % 2 && n > dist)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
'''

#C++
'''
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
std::string ltrim(const std::string &str)
{
    std::string s(str);
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int c)
                                    { return !std::isspace(c); }));
    return s;
}
std::string rtrim(const std::string &str)
{
    std::string s(str);
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch)
                         { return !std::isspace(ch); }).base(), s.end());
    return s;
}
std::vector<std::string> split(const std::string &str)
{
    std::vector<std::string> tokens;
    std::string::size_type start = 0;
    std::string::size_type end = 0;
    while ((end = str.find(" ", start)) != std::string::npos)
    {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(str.substr(start));
    return tokens;
}
int main()
{
    int i, j, t, n, dist, chk, item;
    std::string temp;
    std::getline(std::cin, temp);
    t = std::stoi(ltrim(rtrim(temp)));
    for (; t > 0; t--)
    {
        std::getline(std::cin, temp);
        n = std::stoi(ltrim(rtrim(temp))); 
        std::getline(std::cin, temp);
        std::vector<std::string> a_temp = split(rtrim(temp));
        n = a_temp.size();
        std::vector<int> a(n), set(n);
        for (i = 0; i < n; i++)
        {
            item = std::stoi(a_temp[i]);
            a[i] = item;
        }
        dist = 0;
        for (i = 0; i < n; i++)
        {
            chk = 1;
            for (j = 0; j < dist; j++)
                if (a[i] == set[j])
                {
                    chk = 0;
                    break;
                }
            if (chk)
                set[dist++] = a[i];
        }
        if (! (dist % 2) || dist % 2 && n > dist)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
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
        int i, j, dist, chk, n, t = sc.nextInt();
        for (; t > 0; t--)
        {
            n = sc.nextInt();
            sc.nextLine();
            String[] str = sc.nextLine().split(" ");
            n = str.length;
            int[] a = new int[n], set = new int[n];
            for (i = 0; i < n; i++)
                a[i] = Integer.parseInt(str[i]);
            dist = 0;
            for (i = 0; i < n; i++)
            {
                chk = 1;
                for (j = 0; j < dist; j++)
                    if (a[i] == set[j])
                    {
                        chk = 0;
                        break;
                    }
                if (chk == 1)
                    set[dist++] = a[i];
            }
            if (dist % 2 == 0 || dist % 2 == 1 && n > dist)
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}
'''