#INPUT
'''
12
45 60 82 72 65 32 53 84 103 110 89 95
'''

#OUTPUT
'''
3 2
'''

#PSEUDOCODE
'''
READ integer input as n
SET locs to list containing integer strings split with ' ' from input
SET up, down to 0, 0
SET move to 2
FOR every element i from 1 to n - 1
    IF ith index element of locs > (i - 1)th index element of locs and move NOT EQUAL 1 THEN
        INCREMENT up
        SET move to 1
    ELSEIF ith index element of locs < (i - 1)th index element of locs and move NOT EQUAL 0
        INCREMENT down
        SET move to 0
    ENDIF
ENDFOR
PRINT up, down
'''

#CODE
n, locs, up, down, move = int(input()), list(map(int, input().split())), 0, 0, 2
for i in range(1, n):
    if locs[i]>locs[i-1] and move!=1:
        up, move = up + 1, 1
    elif locs[i]<locs[i-1] and move!=0:
        down, move = down + 1, 0
print(up, down)
