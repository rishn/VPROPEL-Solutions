#INPUT
'''
3
3
4
5
3 0 3
3 3 0
3 3 0
3
'''

#OUTPUT
'''
1 1
1 3
2 1
2 2
3 1
3 2
'''

#PSEUDOCODE
'''
SET temp to empty list
FOR every number i from 0 to 3
    APPEND input to temp
ENDFOR
CALL tuple() with temp
    RETURNING tuple as temp
SET m, n, p, q to temp
SET a, b to empty lists
CALL int() with m
    RETURNING integer as m
CALL int() with n
    RETURNING integer as n
FOR every number from 0 to m-1
    APPEND list containing integer strings split from input to a
ENDFOR
READ l as input
IF q EQUAL l THEN
    SET q to p
ENDIF
FOR every number from 0 to m-1
    FOR every number j from 0 to n-1
        SET temp1 to jth element of ith element of and
	SET temp2 to empty list
	FOR every number k from 0 to m-1
            APPEND jth element of kth element of a to temp2
	ENDFOR
	IF temp1==l and q not in ith element of a and q not in temp2 THEN
	    APPEND list containing values i+1, j+1 to b
	ENDIF
    ENDFOR
ENDFOR
IF b EQUAL empty list THEN
    PRINT 'No winner'
ELSE
    CALL sorted() with b
    	RETURNING list as temp1
    SET temp2 to empty list
    FOR every element i in temp1
    	APPEND f-string containing 1st and 2nd element of i separated by ' ' to temp2
    ENDFOR
    PRINT string containing joined elements of temp2 with separator '\n'
ENDIF
'''

#CODE
m,n,p,q=(input() for i in range(4))
a,b,m,n=[],[],int(m),int(n)
for i in range(m):
    a.append(input().split())
l=input()
if q==l:
    q=p
for i in range(m):
    for j in range(n):
        if a[i][j]==l and q not in a[i] and q not in [a[k][j] for k in range(m)]:
                b.append([i+1,j+1])
if b==[]:
    print('No winner')
else:
    print('\n'.join([f'{i[0]} {i[1]}' for i in sorted(b)]))
