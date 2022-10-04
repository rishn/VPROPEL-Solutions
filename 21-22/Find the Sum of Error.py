#INPUT
'''
5
17
29
35
48
93
45
67
108
34
56
59
96
75
23
103
'''

#OUTPUT
'''
42
125
104
39
58
72
'''

#PSEUDOCODE
'''
READ integer input, n
SET error to 0
SET s1, s2, xor to empty lists
FOR every number i from 0 to n - 1
    APPEND integer input to s1
ENDFOR
FOR every number i from 0 to n - 1
    APPEND integer input to s2
ENDFOR
FOR every number i from 0 to n - 1
    APPEND integer input to xor
ENDFOR
FOR every number i from 0 to n - 1
    COMPUTE temp as ith index s1 element bitwise XOR ith index xor element
    ADD ABS of temp - ith index s2 element to error
    SET ith index s2 element to temp
CALL map() with str, s2
    RETURNING map as s2
CALL list() with s2
    RETURNING list as s2
ENDFOR
PRINT string containing s2 elements joined with '\n', error with sep = '\n'
'''

#CODE
n, error = int(input()), 0
s1, s2, xor = [[int(input()) for i in range(n)] for i in range(3)]
for i in range(n):
    error += abs((s1[i] ^ xor[i]) - s2[i])
    s2[i] = s1[i] ^ xor[i]
print('\n'.join(list(map(str, s2))), error, sep='\n')
