#INPUT
'''
12
13
1 2
1 5
2 4
5 3
5 6
1 7
7 8
1 9
9 10
7 10
10 11
11 12
4 6
1
3
2
12
11
'''

#OUTPUT
'''
yes
no
yes
'''

#PSEUDOCODE
'''
READ input as n
CALL int() with n
    RETURNING integer as n
SET connections to empty set
READ input as temp
CALL int() with temp
    RETURNING integer as temp
FOR every number i from 0 to temp-1
    SET temp to list containing string integers split from input
    FOR every element i in temp
        CALL int() with i
            RETURNING integer as i
    ENDFOR
    CALL frozenset with temp
        RETURNING frozenset as temp
    ADD temp to connections
ENDFOR
READ input as k
CALL int() with k
    RETURNING integer as k
CALL int() with temp
    RETURNING integer as temp
FOR every number i from 0 to temp-1 
    READ query as input
    CALL int() with query
        RETURNING integer as query
    IF set containing k, query in connections THEN
        PRINT 'yes'
    ELSE
        FOR every number i from 1 to n+1
            CALL frozenset() with tuple containing k, i
                RETURNING frozenset as temp1
            CALL frozenset() with tuple containing k, i
                RETURNING frozenset as temp2
            IF set containing temp1, temp2 SUBSET connections THEN
                PRINT 'yes'
                BREAK
            ELSE
                SET tempint to 0
                FOR every number j from 1 to n+1
                    CALL frozenset() with tuple containing k, i
                        RETURNING frozenset as temp1
                    CALL frozenset() with tuple containing i, j
                        RETURNING frozenset as temp2
                    CALL frozenset() with tuple containing j, query
                        RETURNING frozenset as temp3
                    IF set containing temp1, temp2, temp3 SUBSET connections THEN
                        SET temp to 1
                        PRINT 'yes'
                        BREAK
                    ENDIF
                IF temp EQUAL 1 THEN
                    BREAK
                ENDIF
            ENDIF
        ELSE
            PRINT 'no'
        ENDFOR
    ENDIF
ENDFOR
'''

#CODE
n,connections=int(input()),set()
for i in range(int(input())):
    connections.add(frozenset(int(i) for i in input().split()))
k=int(input())
for i in range(int(input())):
    query=int(input())
    if {k,query} in connections:
        print('yes')
    else:
        for i in range(1,n+1):
            if {frozenset((k,i)),frozenset((i,query))}.issubset(connections):
                print('yes')
                break
            else:
                temp=0
                for j in range(1,n+1):
                    if {frozenset((k,i)),frozenset((i,j)),frozenset((j,query))}.issubset(connections):
                        temp=1
                        print('yes')
                        break
                if temp==1:
                    break
        else:    
            print('no')