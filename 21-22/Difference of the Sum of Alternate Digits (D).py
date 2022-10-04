#INPUT
'''
8975
'''

#OUTPUT
'''
1
'''

#PSEUDOCODE
'''
SET n to list containing integers strings split with '' from input
PRINT ABS of (SUM of list containing alternate integer elements of n starting from first n element -
    SUM of list containing alternate integer elements of n starting from second n element)
'''

#CODE
n = list(input())
print(abs(sum(map(int, n[ : : 2])) - sum(map(int, n[1 : : 2]))))
