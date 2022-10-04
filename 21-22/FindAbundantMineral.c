//INPUT
/*
4
oqm
qfo
mpa
opf
*/

//OUTPUT
/*
o
*/

//PSEUDOCODE
/*
FUNCTION max(parameters : n1, n2)
    RETURN MAX of n1, n2
ENDFUNCTION
SET o, q, f, m, p, a to zeroes
READ integer input, n
REPEAT n times
    READ input character array, s
    FOR every number j FROM 0 to size of s - 1
        IF jth index s element EQUAL 'o' THEN
            INCREMENT o
        ELSE IF jth index s element EQUAL 'q' THEN
            INCREMENT q
        ELSE IF jth index s element EQUAL 'f' THEN
            INCREMENT f
        ELSE IF jth index s element EQUAL 'm' THEN
            INCREMENT m
        ELSE THEN
            INCREMENT a
        ENDIF
    ENDFOR
SET s to MAX of a, p, m, f, q, o
IF s EQUAL o THEN
    SET c to 'o'
ELSE IF s EQUAL q THEN
    SET c to 'q'
ELSE IF s EQUAL f THEN
    SET c to 'f'
ELSE IF s EQUAL m THEN
    SET c to 'm'
ELSE IF s EQUAL p THEN
    SET c to 'p'
ELSE THEN
    SET c to 'a'
ENDIF
PRINT c
*/

//CODE
#include <stdio.h>
#include <string.h>
int max(int n1, int n2)
{
    return (n1 > n2) ? n1 : n2;
}
int main()
{
    int n, s, o = 0, q = 0, f = 0, m = 0, p = 0, a = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char s[20];
        scanf("%s", s);
        for (int j = 0; j < strlen(s); j++)
            (s[j] == 'o') ? o++ : (s[j] == 'q') ? q++ : (s[j] == 'f') ? f++ : (s[j] == 'm') ? m++ : 
            (s[j] == 'p') ? p++ : a++;
    }
    s = max(a, max(p, max(m, max(f, max(q, o)))));
    char c = (s == o) ? 'o' : (s == q) ? 'q' : (s == f) ? 'f' : (s == m) ? 'm' : (s == p) ? 'p' : 'a';
    printf("%c", c);
    return 0;
}