#INPUT
'''
10
5
2 3 6 4 10
'''

#OUTPUT
'''
10
'''

#PSEUDOCODE
'''
IMPORT function combinations FROM module itertools
READ integer input as n
READ integer input as m
CALL map() with int, list containing strings split with ' ' from input
    RETURNING map as temp1
CALL list() with temp1
    RETURNING list as packs
SET fetches to empty list
FOR every number i from 1 to m
    CALL combinations() with packs, i
        RETURNING iterable as temp1
    FOR every element j in temp1
        CALL list() with j
            RETURNING list as j
        SET temp2 to False
        FOR every number k from 0 to m - i
            IF list containing elements of packs with indices from k to k + i - 1 EQUAL j
                SET temp2 to True
                BREAK
            ENDIF
        ENDFOR
        IF temp2 and sum of elements in j EQUAL n
            fetches.append(j)
        ENDIF
    ENDFOR
    IF fetches THEN
        PRINT string joining elements of first element of fetches
        BREAK
    ENDIF
ELSE
    PRINT 'Not possible'
ENDFOR
'''

#CODE1 (0 TC)
from itertools import combinations
n, m, packs, fetches = int(input()), int(input()), list(map(int, input().split())), []
for i in range(1, m+1):
    for j in combinations(packs, i):
        if any(packs[k : k + i] == list(j) for k in range(m - i + 1)) and sum(j)==n:
            fetches.append(list(j))
    if fetches:
        print(' '.join([str(i) for i in fetches[0]]))
        break
else:
    print('Not possible')

#CODE2
'''
n, m, packs, combos, fetches = int(input()), int(input()), list(map(int, input().split())), [], []
for i in range(m):
    for j in range(i + 1, m + 1):
        combos.append(packs[i:j])
for i in combos:
    if sum(i)==n:
        fetches.append(i)
if fetches:
    ans=fetches[0]
    for i in fetches:
        if len(i)<len(ans):
            ans=i
    print(' '.join([str(i) for i in ans]))
else:
    print('Not possible')
'''
