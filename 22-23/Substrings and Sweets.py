#INPUT
'''
abc
1
'''

#OUTPUT
'''
3

'''

#PSEUDOCODE/ALGORITHM
'''
w <- input string
k <- integer input
res <- 0
i <- 0
until (i >= length(w))
{
    j <- i + 1
    until (j > length(w))
    {
        c <- 0
        l <- i
        until (l >= j)
        {
            if (w[l] == 'a' || w[l] == 'e' || w[l] == 'i' || w[l] == 'o' || w[l] == 'u')
            {
                c += 1
            }
            l += 1
        }
        if (c == k)
        {
            res += 1
        }
        j += 1
    }
    i += 1
}
print res
'''

#CODE
w, k, res = input(), int(input()), 0
for i in range(len(w)):
    for j in range(i + 1, len(w) + 1):
        c = 0
        for l in range(len(w[i : j])):
            if w[i : j][l] in 'aeiou':
                c += 1
        if c == k:
            res += 1
print(res)

#C++
'''
#include <iostream>
using namespace std;
int main()
{
    string w;
    cin >> w;
    int i, j, k, res = 0;
    cin >> k;
    for (i = 0; i < w.length(); i++)
        for (j = i + 1; j <= w.length(); j++)
        {
            int l, c = 0;
            for (l = i; l < j; l++)
                if (w[l] == 'a' || w[l] == 'e' || w[l] == 'i' || w[l] == 'o' || w[l] == 'u')
                    c++;
            if (c == k)
                res++;
        }
    cout << res;
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
        char[] w = sc.nextLine().toCharArray();
        int k = sc.nextInt(), res = 0, i, j;
        for (i = 0; i < w.length; i++)
            for (j = i + 1; j <= w.length; j++)
            {
                int c = 0, l;
                for (l = i; l < j; l++)
                    if (w[l] == 'a' || w[l] == 'e' || w[l] == 'i' || w[l] == 'o' || w[l] == 'u')
                        c++;
                if (c == k)
                    res++;
            }
        System.out.println(res);
    }
}
'''