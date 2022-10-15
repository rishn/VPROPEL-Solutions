#INPUT
'''
12:00:00 midnight
'''

#OUTPUT
'''
08:00:00 midnight

'''

#PSEUDOCODE/ALGORITHM
'''
Substr(char array w)
{
    s <- char array of size 6
    i <- 2
    until (i >= 8)
    {
        s[i - 2] = w[i]
        i += 1
    }
    return s;
}
Time_In_Heaven()
{
    w <- char array of size 8
    m <- char array of size 8
    read w, m
    h <- ((int)w[0] - (int)'0') * 10 + (int)w[1] - (int)'0'
    if (m == "A.M")
        if (h < 8)
            print w + " " + m
        else if (w == "08:00:00")
            print w + " midmorning"
        else
            print "0" + (h - 8) + Substr(w) + " B.M"
    else if (m == "P.M")
        if (h < 4)
            print "0" + (h + 4) + Substr(w) + " B.M"
        else if (w == "04:00:00")
            print w + " midevening"
        else
            print "0" + (h - 4) + Substr(w) + " C.M"
    else if (m == "midnight")
        print "08:00:00 " + m
    else
        print "08:00:00 B.M"
}
'''

#CODE
w, m = input().split()
h = int(w[ : 2])
if m == 'A.M':
    print(f'{w} {m}' if h < 8 else f'{w} midmorning' if w == '08:00:00' else f'0{h - 8}{w[2 : ]} B.M')
elif m == 'P.M':
    print(f'0{h + 4}{w[2 : ]} B.M' if h < 4 else '{w} midevening' if w == '04:00:00' else f'0{h - 4}{w[2 : ]} C.M')
elif m == 'midnight':
    print('08:00:00', m)
else:
    print('04:00:00', 'B.M')

#C
'''
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *substr(char *w)
{
    char *s = (char *)malloc(sizeof(char) * 6);
    int i;
    for (i = 2; i < 8; i++)
        s[i - 2] = w[i];
    return s;
}
int main()
{
    char *w = (char *)malloc(sizeof(char) * 8), *m = (char *)malloc(sizeof(char) * 8);
    scanf("%s %s", w, m);
    int h = (w[0] - 48) * 10 + w[1] - 48;
    if (! strcmp(m, "A.M"))
        if (h < 8)
            printf("%s %s", w, m);
        else if (! strcmp(w, "08:00:00"))
            printf("%s midmorning", w);
        else
            printf("0%d%s B.M", h - 8, substr(w));
    else if (! strcmp(m, "P.M"))
        if (h < 4)
            printf("0%d%s B.M", h + 4, substr(w));
        else if (! strcmp(w, "04:00:00"))
            printf("%s midevening", w);
        else
            printf("0%d%s C.M", h - 4, substr(w));
    else if (! strcmp(m, "midnight"))
        printf("08:00:00 %s", m);
    else
        printf("08:00:00 B.M");
    return 0;
}
'''

#C++
'''
#include <iostream>
using namespace std;
string substr(string w)
{
    string s;
    for (int i = 2; i < 8; i++)
        s += w[i];
    return s;
}
int main()
{
    string w, m;
    cin >> w >> m;
    int h = (w[0] - 48) * 10 + w[1] - 48;
    if (m == "A.M")
        if (h < 8)
            cout << w << " " << m;
        else if (w == "08:00:00")
            cout << w << " midmorning";
        else
            cout << "0" << h - 8 << substr(w) << " B.M";
    else if (m == "P.M")
        if (h < 4)
            cout << "0" << h + 4 << substr(w) << " B.M";
        else if (w == "04:00:00")
            cout << w << " midevening";
        else
            cout << "0" << h - 4 << substr(w) << " C.M";
    else if (m == "midnight")
        cout << "08:00:00 " << m;
    else
        cout << "08:00:00 B.M";
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
        String w = sc.next(), m = sc.next(), s = w.substring(2);
        int h = Integer.parseInt(w.substring(0, 2));
        if (m.equals("A.M"))
            if (h < 8)
                System.out.println(w + " " + m);
            else if (w.equals("08:00:00"))
                System.out.println(w + " midmorning");
            else
                System.out.println("0" + (h - 8) + s + " B.M");
        else if (m.equals("P.M"))
            if (h < 4)
                System.out.println("0" + (h + 4) + s + " B.M");
            else if (w.equals("04:00:00"))
                System.out.println(w + " midevening");
            else
                System.out.println("0" + (h - 4) + s + " C.M");
        else if (m.equals("midnight"))
            System.out.println("08:00:00 " + m);
        else
            System.out.println("08:00:00 B.M");
    }
}
'''
