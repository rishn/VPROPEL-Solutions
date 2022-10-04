#INPUT
'''
5
2
4
5
6
3
3
11
12
7
9
7
15
13
8
1
2
21
25
13
14
17
10
16
19
3
'''

#OUTPUT
'''
5	4	3	6	1	
3	11	12	7	9	
2	15	13	8	3	
2	21	25	13	14	
7	10	17	19	16
'''

#PSEUDOCODE
'''
READ integer input, n
SET curr to 0
SET matrix, corner to empty lists
FOR every number i from 0 to n - 1
    FOR every number j from 0 to n - 1
        APPEND integer input to ith index matrix element
    ENDFOR
ENDFOR
FOR every number i from 0 to n - 1
    APPEND ith index (first matrix element) element to corner
ENDFOR
FOR every number i from 1 to n - 1
    APPEND last (ith index matrix element) element to corner
ENDFOR
CALL range() with n - 2, -1, -1
    RETURNING iterable as temp
FOR every element i in temp
    APPEND ith index (last matrix element) element to corner
ENDFOR
CALL range() with n - 2, 0, -1
    RETURNING iterable as temp
FOR every element i in temp
    APPEND first (ith index matrix element) element to corner
ENDFOR
CALL range() with 2, size of corner, 2
    RETURNING iterable as temp
FOR every element i in temp
    SET (i-2)th index corner element to ith index corner element, ith index corner element to (i-2)th index corner element
ENDFOR
FOR every number i from 0 to n - 1
    SET ith index (first matrix element) element to (curr)th index corner element
    INCREMENT curr
ENDFOR
FOR every number i from 1 to n - 1
    SET last (ith index matrix element) element to (curr)th index corner element
    INCREMENT curr
ENDFOR
CALL range() with n - 2, -1, -1
    RETURNING iterable as temp
FOR every element i in temp
    SET ith index (last matrix element) element to (curr)th index corner element
    INCREMENT curr
ENDFOR
CALL range() with n - 2, 0, -1
    RETURNING iterable as temp
FOR every element i in temp
    SET first (ith index matrix element) element to (curr)th index corner element
    INCREMENT curr
ENDFOR
FOR every number i from 0 to n - 1
    FOR every number j from 0 to n - 1
        PRINT jth index (ith index matrix element) element with end = '\t'
    ENDFOR
    PRINT ''
ENDFOR
'''

#CODE
n, curr = int(input()), 0
matrix = [[int(input()) for j in range(n)] for i in range(n)]
corner = [matrix[0][i] for i in range(n)] + [matrix[i][n - 1] for i in range(1, n)] + [matrix[n - 1][i]
    for i in range(n - 2, -1, -1)] + [matrix[i][0] for i in range(n - 2, 0, -1)]
for i in range(2, len(corner), 2):
    corner[i - 2], corner[i] = corner[i], corner[i - 2]
for i in range(n):
    matrix[0][i], curr = corner[curr], curr + 1
for i in range(1, n):
    matrix[i][n - 1], curr = corner[curr], curr + 1
for i in range(n - 2, -1, -1):
    matrix[n - 1][i], curr = corner[curr], curr + 1
for i in range(n - 2, 0, -1):
    matrix[i][0], curr = corner[curr], curr + 1
print('\n'.join(['\t'.join([str(j) for j in i]) for i in matrix]))
