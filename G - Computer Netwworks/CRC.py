#INPUT
'''
10111011
1001
'''

#OUTPUT
'''
10111011110
'''

#CODE
dd = input()
n, dv = len(dd), input()
dd += '0' * (len(dv) - 1)
m = k = len(dv)
res = dd[:m]
for i in range(len(dd) - m):
    if res[0] == '1':
        temp = dv
    else:
        temp = '0' * m
    new_res = ''
    for j in range(m):
        if (res[j] != temp[j]):
            new_res += '1'
        else:
            new_res += '0'
    if k < n + m:
         res = new_res[1:] + dd[k];
    k += 1
dd = dd[:n] + res[1:];
print(dd)