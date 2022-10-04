#INPUT
'''
6
15
12
17
32
26
42
4
45
34
64
80
'''

#OUTPUT
'''
15
12
42
'''

#PSEUDOCODE
'''
SET l1, l2 to empty lists
FOR every number i from 0 to integer input - 1
    APPEND integer input to l1
ENDFOR
FOR every number i from 0 to integer input - 1
    APPEND integer input to l2
ENDFOR
SET l3 to list containing first elements of l1 and l2
FOR every number i from 1 to maximum of size of l1, size of l2
    IF i < size of l1 and element at ith index of l1 % (i + 1) EQUAL 0 THEN
        APPEND element at ith index of l1 to l3
    ENDIF
    IF i < size of l2 and element at ith index of l2 % (i + 1) EQUAL 0 THEN
        APPEND element at ith index of l2 to l3
    ENDIF
ENDFOR
CALL str() with first element of l3
    RETURNING string as temp1
SET temp2 to list containing temp1
FOR every number i from 1 to size of l3
    IF element at ith index of l3 % (i + 1) EQUAL 0 THEN
        CALL str() with element at ith index of l3
            RETURNING string as temp3
        APPEND temp3 to temp2
ENDFOR
PRINT string containing elements of temp2 joined by '\n'
'''

#CODE
l1, l2 = [int(input()) for i in range(int(input()))], [int(input()) for i in range(int(input()))]
l3 = [l1[0], l2[0]]
for i in range(1, max(len(l1), len(l2))):
    if i < len(l1) and l1[i] % (i + 1) == 0:
        l3.append(l1[i])
    if i < len(l2) and l2[i]%(i + 1) == 0:
        l3.append(l2[i])
print('\n'.join([str(l3[0])] + [str(l3[i]) for i in range(1, len(l3)) if l3[i] % (i + 1) == 0]))
