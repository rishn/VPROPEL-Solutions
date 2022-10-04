#INPUT
'''
49
98
'''

#OUTPUT
'''
0.50
'''

#PSEUDOCODE
'''
READ inputs, x, y
FOR every element i in INTERSECTION of set containing x elements, set containing y elements
    REPEAT MIN of COUNT of i in x, COUNT of i in y times
        SET x to x elements excluding i, y to y elements excluding i
ENDFOR
IF x EQUAL empty string THEN
    SET x to string containing 1
ENDIF
IF y EQUAL empty string THEN
    SET y to string containing 1
ENDIF
IF y EQUAL string containing 0 THEN
    PRINT -1 with 2 decimal places
ELSE THEN
    CALL int() with x
        RETURNING integer as x
    CALL int() with y
        RETURNING integer as y
    PRINT x/y with 2 decimal places
ENDIF
'''

#CODE
x, y = input(), input()
for i in set(x) & set(y):
    for j in range(min(x.count(i), y.count(i))):
        x, y = x[ : x.index(i)] + x[x.index(i) + 1 : ], y[ : y.index(i)] + y[y.index(i) + 1 : ]
if x == '':
    x = '1'
if y == '':
    y = '1'
print(format(-1, '0.2f') if y == '0' else format(int(x)/int(y),'0.2f'))
