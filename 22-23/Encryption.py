#INPUT
'''
2
HAPPY APPLE
CHENNAI MUMBAI
'''

#OUTPUT
'''
FAOOY
BEILLMF

'''

#PSEUDOCODE/ALGORITHM
'''
Encryption(char[] word, char[] key)
{
    alpha <- "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    key <- key + alpha
    l <- 0
    i <- 0
    dist_key <- char array of size 26
    new_word <- char array of size of word
    until (i >= length(key))
    {
        chk <- 1
        j <- 0
        until (j >= l)
        {
            if (key[i] == dist_key[j])
            {
                chk <- 0
                break
            }
            j += 1
        }
        if (chk == 1)
        {
            dist_key[l] = key[i]
            l += 1
        }
        i += 1
    }
    i <- 0
    until (i >= length(word))
    {
        index <- 0
        j <- 0
        until (j >= 26)
        {
            if (word[i] == alpha[j])
            {
                index <- k
                break
            }
            j += 1
        }
        new_word[i] <- dist_key[index]
        i += 1
    }
    return new_word
}
'''

#CODE
'''
from string import ascii_uppercase
for i in range(int(input())):
    word, key = input().split()
    dist_key = ''
    for j in key + ascii_uppercase:
        if j not in dist_key:
            dist_key += j
    new_word = ''
    for j in word:
        new_word += dist_key[ascii_uppercase.index(j)]
    print(new_word)
'''

#C
'''
#include <stdio.h>
#include <string.h>
int main()
{
    int i, j, k, l, n, index, chk;
    char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        char word[26], key[26];
        scanf("%s %s", &word, &key);
        strcat(key, alpha);
        char dist_key[26], new_word[strlen(word)];
        l = 0;
        for (j = 0; j < strlen(key); j++)
        {
            chk = 1;
            for (k = 0; k < l; k++)
                if (key[j] == dist_key[k])
                {
                    chk = 0;
                    break;
                }
            if (chk)
                dist_key[l++] = key[j];
        }
        for (j = 0; j < strlen(word); j++)
        {
            index = 0;
            for (k = 0; k < 26; k++)
                if (word[j] == alpha[k])
                {
                    index = k;
                    break;
                }
            new_word[j] = dist_key[index];
        }
        printf("%s\n", new_word);
    }
    return 0;
}
'''

#C++
'''
#include <iostream>
using namespace std;
int main()
{
    int i, j, k, n, index, chk;
    string word, key, alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> word >> key;
        key += alpha;
        string dist_key, new_word;
        for (j = 0; j < key.length(); j++)
        {
            chk = 1;
            for (k = 0; k < dist_key.length(); k++)
                if (key[j] == dist_key[k])
                {
                    chk = 0;
                    break;
                }
            if (chk)
                dist_key += key[j];
        }
        for (j = 0; j < word.length(); j++)
        {
            index = 0;
            for (k = 0; k < 26; k++)
                if (word[j] == alpha[k])
                {
                    index = k;
                    break;
                }
            new_word += dist_key[index];
        }
        cout << new_word << endl;
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
        String alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        char[] alpharray = alpha.toCharArray();
        int n = sc.nextInt(), i, j, k, l, index, chk;
        for (i = 0; i < n; i++)
        {
            char[] word = sc.next().toCharArray(), key = (sc.next() + alpha).toCharArray(), dist_key = new char[26], new_word = new char[word.length];
            l = 0;
            for (j = 0; j < key.length; j++)
            {
                chk = 1;
                for (k = 0; k < l; k++)
                    if (key[j] == dist_key[k])
                    {
                        chk = 0;
                        break;
                    }
                if (chk == 1)
                    dist_key[l++] = key[j];
            }
            for (j = 0; j < word.length; j++)
            {   
                index = 0;
                for (k = 0; k < 26; k++)
                    if (word[j] == alpharray[k])
                    {
                        index = k;
                        break;
                    }
                new_word[j] = dist_key[index];
            }
            System.out.println(new_word);
        }
    }
}
'''