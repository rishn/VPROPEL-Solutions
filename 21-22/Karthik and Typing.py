#INPUT
'''
4
dfjk
ddd
jkd
dfjk
'''

#OUTPUT
'''
36
'''

#PSEUDOCODE
'''
SET a to empty dict, b to 0
FOR every number i FROM 0 to integer input - 1
    READ input, w
    IF w IN a THEN
        COMPUTE c as value of key w in a // 2
    ELSE THEN
        IF first element of w IN 'df' THEN
            COMPUTE c as 2*(1 + size of w + count of string that replaced w[0] with '' in 'df')
        ELSE THEN
            COMPUTE c as 2*(1 + size of w + count of string that replaced w[0] with '' in 'jk')
        ENDIF
        SET value of key of w in a to c
    ENDIF
    ADD c to b
ENDFOR
PRINT b
'''

#CODE
a, b = {}, 0
for i in range(int(input())):
    w = input()
    if w in a:
        c = a[w]//2
    else:
        if w[0] in 'df':
            c=2*(1 + len(w) + w.count('df'.replace(w[0],'')))
        else:
            c=2*(1 + len(w) + w.count('jk'.replace(w[0],'')))
        a[w] = c
    b += c
print(b)
