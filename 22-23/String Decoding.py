#INPUT
'''
3
3[a]2[bc]
3[a2[c]]
2[abc]3[cd]ef
'''

#OUTPUT
'''
aaabcbc
accaccacc
abcabccdcdcdef
'''

#PSEUDOCODE
'''
t <- no. of testcases
p <- 0
until (p >= t)
{
    str <- input string
    i <- 0
    while (True)
    {
        if (i >= length(str))
        {
            break
        }
        else if (str[i] == ']')
        {
            s <- empty string
            j <- i - 1
            until (str[j] == '[')
            {
                s += str[j]
                j -= 1
            }
            j -= 1
            n <- (int)str[j] - 48
            new_str <- empty string
            k <- 0
            until (k >= j)
            {
                new_str += str[k]
                k += 1
            }
            k <- length(s) - 1
            rpt <- empty string
            until (k < 0)
            {
                rpt += s[k]
                k -= 1
            }
            k <- 0
            until (k >= n)
            {
                new_str += rpt
            }
            k <- i + 1
            until (k >= length(str))
            {
                new_str += str[k]
                k += 1
            }
            str <- new_str
            i <- j - 1 + n * length(s)
        }
        i += 1
    }
    print str
    p += 1
}
'''

#CODE
for i in range(int(input())):
    str, i = input(), 0
    while True:
        if i >= len(str):
            break
        elif str[i] == ']':
            rpt, j = '', i - 1
            while str[j] != '[':
                rpt += str[j]
                j -= 1
            j -= 1
            n = int(str[j])
            str = str[ : j] + n * rpt[ : : -1] + str[i + 1 : ]
            i = j - 1 + n * len(rpt)
        i += 1
    print(str)
