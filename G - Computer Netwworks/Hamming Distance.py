#INPUT
'''
4
0000
1010
1111
0110
'''

#OUTPUT
'''
2
'''

#CODE
hd = 8
n = int(input())
a = [input() for i in range(n)]
for i in range(n):
    for j in range(i + 1, n):
        count = 0
        for k in range(len(a[i])):
            if (a[i][k] != a[j][k]):
                count += 1
        if (count < hd):
            hd = count
print(hd)