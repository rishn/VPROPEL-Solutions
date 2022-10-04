#INPUT
'''
6
90
25
37
28
73
84
'''

#OUTPUT
'''
73
84
'''

#PSEUDOCODE
'''
READ integer input, n
SET result to empty list, children to empty list
REPEAT n times
    APPEND integer input to children
FOR every number i from 0 to n - 1
    IF i NOT IN list containing 0, n - 1 AND (i - 1)th index children element < ith index children element < (i + 1)th index children element THEN
        APPEND string containing (i + 1) to result
    ELSEIF i EQUAL 0 AND last children element < first children element < second children element THEN
        APPEND '1' to result
    ELSEIF i == n - 1 AND second last children element < last children element < first children element THEN
        APPEND string containing n to result
    ENDIF
ENDFOR
IF result THEN
    PRINT string containing children elements joined by '\n'
ELSE THEN
    PRINT 'None'
ENDIF
'''

#CODE
n, result = int(input()), []
children = [int(input()) for i in range(n)]
for i in range(n):
    if i not in [0, n - 1] and children[i - 1] < children[i] < children[i + 1]:
        result.append(str(i + 1))
    elif i == 0 and children[-1] < children[0] < children[1]:
        result.append('1')
    elif i == n - 1 and children[-2] < children[-1] < children[0]:
        result.append(str(n))
print('\n'.join(result) if result else 'None')
