#INPUT
'''
5
B1 5
B2 12
B3 14
B4 23
B5 6
'''

#OUTPUT
'''
B3 B5
B1 B2 B4
'''

#PSEUDOCODE
'''
FROM module itertools IMPORT function combinations
READ integer input as n
SET baskets, combos, duck, chicken to empty lists
FOR every number i from 0 to n - 1
    SET basket to list of strings split from input
    CALL int() with second basket element
        RETURNING integer as second basket element
    CALL tuple() with basket
        RETURNING tuple as basket
    APPEND basket to baskets
ENDFOR
FOR every number i from 1 to n - 1
    CALL combinations() with baskets, i
        RETURNING iterable as temp
    EXTEND combos with elements from temp
ENDFOR
FOR every element i IN combos
    FOR every element j IN combos
        CALL set() with i + j
            RETURNING set as temp1
        CALL set() with baskets
            RETURNING set as temp2
        IF i NOT EQUAL j AND temp1 EQUAL temp2  THEN
            FOR every element k IN i
                IF k IN j THEN
                    BREAK
            ELSE
                SET a, b to empty lists
                FOR every element k IN i
                    APPEND second k element to a
                ENDFOR
                FOR every element k IN j:
                    APPEND second k element to b
                ENDFOR
                SET a to sum of elements IN a
                SET b to sum of elements IN b
                IF 2*a EQUAL b THEN
                    FOR every element k IN i
                        APPEND first k element to duck
                    ENDFOR
                    FOR every element k IN j
                        APPEND second k element to chicken
                    ENDFOR
                ENDIF
            ENDFOR
        ENDIF
    ENDFOR
    IF duck NOT EQUAL empty list THEN
        BREAK
    ENDIF
ENDFOR
PRINT all elements in duck separated by ' '
PRINT all elements in chicken separated by ' '
'''

#CODE
from itertools import combinations
n, baskets, combos, duck, chicken = int(input()), [], [], [], []
for i in range(n):
    basket = input().split()
    basket[1]= int(basket[1])
    baskets.append(tuple(basket))
for i in range(1, n):
    combos.extend(combinations(baskets, i)) 
for i in combos:
    for j in combos:
        if i != j and set(i+j) == set(baskets):
            for k in i:
                if k in j:
                    break
            else:
                a, b = sum([k[1] for k in i]), sum([k[1] for k in j])
                if 2*a==b:
                    duck, chicken = [k[0] for k in i], [k[0] for k in j]
                    break
    if duck!=[]:
        break
print(*duck)
print(*chicken)
