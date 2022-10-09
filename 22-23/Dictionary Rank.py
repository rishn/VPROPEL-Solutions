#INPUT
'''
MOTHER
'''

#OUTPUT
'''
309

'''

#PSEUDOCODE/ALGORITHM
'''
Fact(int n)
{
    fact <- 1;
    until (n <= 1)
    {
        fact *= n
        n -= 1
    }
    return fact;
}
Rank(char array word)
{
    rank <- 0
    size <- length(word);
    sort <- char array of size of word
    chk <- '0'
    i <- 0
    until (i >= size)
    {
        min <- 'a'
        j <- 0
        until (j >= size)
        {
            if (min > word[j] && word[j] > chk)
            {
                min <- word[j]
            }
            j += 1
        }
        sort[i] <- min
        chk <- min
        i += 1
    }
    i <- 0
    until (i >= size)
    {
        j <- 0
        until (j >= size - i)
        {
            if (word[i] == sort[j])
            {
                break
            }
            j += 1
        }
        rank += j * Fact(size - i - 1);
        k <- j
        until (k >= size - i - 1)
        {
            sort[k] <- sort[k + 1]
            k += 1
        }
        i += 1
    }
    rank += 1
    return rank;
}
'''

#CODE
from math import factorial
word = input()
sort, rank, size = sorted(word), 0, len(word)
for i in range(size):
    rank += (sort.index(word[i])) * factorial(size - i - 1)
    sort.pop(word[i])
rank += 1
print(rank)

#C
'''
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
int fact(int n)
{
    int fact = 1;
    while (n > 1)
        fact *= n--;
    return fact;
}
int main()
{
    char word[25];
    scanf("%s", word);
    int i, j, k, rank = 0, size = strlen(word);
    char *sort = (char *)malloc(sizeof(char) * size);
    char chk = '0', min;
    for (i = 0; i < size; i++)
    {
        min = 'a';
        for (j = 0; j < size; j++)
            if (min > word[j] && word[j] > chk)
                min = word[j];
        sort[i] = min;
        chk = min;
    }
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - i; j++)
            if (word[i] == sort[j])
                break;
        rank += j * fact(size - i - 1);
        for (k = j; k < size - i - 1; k++)
            sort[k] = sort[k + 1];
    }
    printf("%d", ++rank);
    return 0;
}
'''

#C++
'''
#include <iostream>
using namespace std;
int fact(int n)
{
    int fact = 1;
    while (n > 1)
        fact *= n--;
    return fact;
}
int main()
{
    string word, sort;
    cin >> word;
    int i, j, k, rank = 0, size = word.length();
    char chk = '0', min;
    for (i = 0; i < size; i++)
    {
        min = 'a';
        for (j = 0; j < size; j++)
            if (min > word[j] && word[j] > chk)
                min = word[j];
        sort += min;
        chk = min;
    }
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - i; j++)
            if (word[i] == sort[j])
                break;
        rank += j * fact(size - i - 1);
        for (k = j; k < size - i - 1; k++)
            sort[k] = sort[k + 1];
    }
    cout << ++rank;
    return 0;
}
'''

#JAVA
'''
import java.util.Scanner;
class Main
{
    static int fact(int n)
    {
        int fact = 1;
        while (n > 1)
            fact *= n--;
        return fact;
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        char[] word = sc.next().toCharArray(), sort = new char[word.length];
        int i, j, k, rank = 0, size = word.length;
        char chk = '0', min;
        for (i = 0; i < size; i++)
        {
            min = 'a';
            for (j = 0; j < size; j++)
                if (min > word[j] && word[j] > chk)
                    min = word[j];
            sort[i] = min;
            chk = min;
        }
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size - i; j++)
                if (word[i] == sort[j])
                    break;
            rank += j * fact(size - i - 1);
            for (k = j; k < size - i - 1; k++)
                sort[k] = sort[k + 1];
        }
        System.out.println(++rank);
    }
}
'''