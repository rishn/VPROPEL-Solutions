#INPUT
'''
aerfsbon
'''

#OUTPUT
'''
Won
'''

#PSEUDOCODE
'''
SET pre to characters from that with ASCII cordinate 97 to that with ASCII coordinate 109
READ input, w
SET lost to 0
IF w has lowercase letters only THEN
    FOR every number i from 0 to size of w - 1
        SET temp1 to character with ASCII coordinate (ASCII coordinate of ith index w element + 13)
        IF ith index w element IN pre and temp1 NOT IN w or temp1 IN list containing elements with indices from 0 to i - 1 THEN
            SET lost to 1
        ELSEIF ith index w element IN pre and (i + 1)th index w element NOT EQUAL temp1 THEN
            FOR every number j from i + 1 to index of temp1 in w - 1
                SET temp2 to character with ASCII coordinate (ASCII coordinate of jth index w element + 13)
                IF jth index w element IN pre and temp2 NOT IN list containing elements with indices from i + 1 to index of temp1 in w - 1 THEN
                    SET lost to 1
                    BREAK
                ENDIF
            ELSE THEN
                FOR every number j from 0 to i - 1
                    SET temp2 to character with ASCII coordinate (ASCII coordinate of jth index w element + 13)
                    IF jth index w element IN pre and temp2 IN list containing elements with indices from i + 1 to index of temp1 in w - 1 THEN
                        SET lost to 1
                        BREAK
                    ENDIF
                ENDFOR
            ENDFOR
        ENDIF
        IF lost EQUAL 1
            PRINT 'Lost'
            BREAK
        ENDIF
    ELSE THEN
        PRINT 'Won'
    ENDFOR
ELSE THEN
    PRINT 'invalid'
ENDIF
'''

#CODE
pre, w, lost = ''.join([chr(i) for i in range(97, 110)]), input(), 0
if w.islower():
    for i in range(len(w)):
        if w[i] in pre and chr(ord(w[i])+13) not in w or chr(ord(w[i])+13) in w[:i]:
            lost = 1
        elif w[i] in pre and w[i+1] != chr(ord(w[i])+13):
            for j in range(i + 1, w.index(chr(ord(w[i])+13))):
                if w[j] in pre and chr(ord(w[j])+13) not in w[i + 1 : w.index(chr(ord(w[i])+13))]:
                    lost = 1
                    break
            else:
                for j in range(i):
                    if w[j] in pre and chr(ord(w[j])+13) in w[i + 1 : w.index(chr(ord(w[i])+13))]:
                        lost = 1
                        break
        if lost == 1:
            print('Lost')
            break
    else:
        print('Won')
else:
    print('invalid')
