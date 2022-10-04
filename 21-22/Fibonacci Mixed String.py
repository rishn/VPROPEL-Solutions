#INPUT
'''
asdf
aber
4
'''

#OUTPUT
'''
bfdt
'''

#PSEUDOCODE
'''
IMPORT module string
FUNCTION fn(s1: string, s2: string, m: positive integer, n: positive integer)
        SET s3 to ''
	FOR every number i from 0 to m-1
		IF i MOD 2 EQUAL 0 THEN
			SET temp to be the index of ith index s1 element in s
			SET s3 to s3 + (temp+1)th index s element
		ELSE
			SET temp to be the index of ith index s2 element in s
			SET s3 to s3 + (temp+1)th index s element
		ENDIF
	ENDFOR
	IF n EQUAL 1 THEN
		PRINT s3
		RETURN None
	ENDIF
	CALL fn(s2, s3, m, n-1)
        	RETURNING None
ENDFUNCTION
SET s to string.ascii_lowercase
SET s to s+'a'
READ input as s1
READ input as s2
READ input as n
SET n to int(n)
SET m to length of s1
CALL fn(s1, s2, m, n-2)
	RETURNING None
'''

#CODE
import string
def fn(s1,s2,m,n):
    s3=''
    for i in range(m):
        if i%2==0:
            s3+=s[s.index(s1[i])+1] 
        else:
            s3+=s[s.index(s2[i])+1]
    if n==1:
        print(s3)
        return
    fn(s2,s3,m,n-1)
s,s1,s2,n=string.ascii_lowercase+'a',input(),input(),int(input())
fn(s1,s2,len(s1),n-2)
