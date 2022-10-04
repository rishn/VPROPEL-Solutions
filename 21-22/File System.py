#INPUT
'''
15
14
1 2
1 3
1 4
1 5
2 6
3 7
4 8
5 9
6 10
7 11
7 12
8 13
8 14
9 15
/ home opt lib usr user java cpp local a.txt a.txt b.txt d.txt e.txt x.cpp
3
/home/user /home a.txt
/home/user /opt/java a.txt
/lib/cpp /usr/local d.txt
'''

#OUTPUT
'''
yes
no
yes
'''
#PSEUDOCODE
'''
SET tree to dict containing integers from 1 to integer input as keys and empty lists as values
REPEAT integer input times
    SET p, f to integers split with ' ' from input
    APPEND f to value of p key of tree
SET files to list containing strings split with ' ' from input
REPEAT integer input times
    SET old, new, f to strings split with ' ' from input
    SET loc to last (list containing strings split with '/' from new) element
    IF loc THEN
        SET loc to index of loc in files + 1
    ELSE THEN
        SET loc to 1
    ENDIF
    FOR every element i in value of loc key of tree
        IF (i - 1)th index files element EQUAL f THEN
            PRINT 'no'
            BREAK
        ENDIF
    ELSE THEN
        PRINT 'yes'
    ENDFOR
'''

#CODE
tree = {i : [] for i in range(1, int(input()) + 1)}
for i in range(int(input())):
    p, f = map(int, input().split())
    tree[p].append(f)
files = input().split()
for i in range(int(input())):
    old, new, f = input().split()
    loc = new.split('/')[-1]
    loc = files.index(loc) + 1 if loc else 1 
    for i in tree[loc]:
        if files[i - 1] == f:
            print('no')
            break
    else:
        print('yes')

