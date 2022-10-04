#INPUT
'''
14
15
'''

#OUTPUT
'''
14
'''

#PSEUDOCODE
'''
READ integer inputs, m, n
SET msum to 0, nsum to 0
FOR every number i from 2 to (MAX of m//2, n//2) + 1
    IF i NOT EQUAL m AND i divides m THEN
        ADD i to msum
    ENDIF
    IF i NOT EQUAL n AND i divides n THEN
        ADD i to nsum
    ENDIF
ENDFOR
IF msum > nsum THEN
    PRINT m
ELIF nsum > msum THEN
    PRINT n
ELSE THEN
    PRINT 'No dominance'
ENDIF
'''

#CODE
m, n, msum, nsum = int(input()), int(input()), 0, 0
for i in range(2, max(m//2, n//2) + 1):
    if i != m and m % i == 0:
        msum += i
    if i != n and n % i == 0:
        nsum += i
print(m if msum > nsum else n if nsum > msum else 'No dominance')
