#INPUT
'''
super
3
'''

#OUTPUT
'''
per
ser
spe
spr
sue
sup
sur
uer
upe
upr
'''

#PSEUDOCODE
'''
IMPORT function itertools FROM module combinations
SET d to list of characters from input
READ input as k
CALL int() with k
	RETURNING integer as k
CALL combinations() with d,k
	RETURNING iterable as a
CALL list() with a
	RETURNING list as a
CALL sorted() with a
	RETURNING list as a
FOR every element i in a
	CALL ''.join() with i
		RETURNING string as x
	PRINT x
ENDFOR
'''

#CODE
from itertools import combinations  
for i in sorted(list(combinations(list(input()),int(input())))):
	print(''.join(i))
