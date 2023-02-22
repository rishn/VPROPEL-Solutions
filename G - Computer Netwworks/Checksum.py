#INPUT
'''
4
11001100
10101010
11110000
11000011
'''

#OUTPUT
'''
11010011
'''

#CODE
def add(a, b):
    sum, carry = '', 0
    for i in range(7, -1, -1):
        t = int(a[i]) + int(b[i]) + carry
        carry, r = t // 2, t % 2;
        sum = str(r) + sum
    return sum, carry
n = int(input())
a = [input() for i in range(n)]
sum = a[0]
for i in range(1, n):
    sum, carry = add(sum, a[i])
    if carry == 1:
        sum, carry = add(sum, '00000001')
res = ''
for i in range(7, -1, -1):
    if (sum[i] == '1'):
        res = '0' + res
    else:
        res = '1' + res
print(res)