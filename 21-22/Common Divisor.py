#INPUT
'''
5
5 10 15 20 25
'''

#OUTPUT
'''
YES
'''

#PSEUDOCODE
'''
READ integer input, n
CALL map() with int, list containing strings split with ' ' from input
    RETURNING map as nums
CALL list() with nums
    RETURNING list as nums
FOR every number i from 2 to MIN of elements in nums
    FOR every element j in nums
        IF NOT i divides j THEN
            BREAK
        ENDIF
    ELSE THEN
        PRINT 'YES'
        BREAK
    ENDFOR
ELSE THEN
    PRINT 'NO'
ENDFOR
'''

#CODE
n, nums = int(input()), list(map(int, input().split()))
for i in range(2, min(nums) + 1):
    for j in nums:
        if j % i != 0:
            break
    else:
        print('YES')
        break
else:
    print('NO')
