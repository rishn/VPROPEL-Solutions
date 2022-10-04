//INPUT
/*
3
3
2 3 4
5 7 3
3 8 1
*/

//OUTPUT
/*
8 10 9 
14 17 11
13 19 10
*/

//PSEUDOCODE
/*
READ integer inputs, r, c
SET m to empty 2D array
FOR every number i from 0 to r - 1
    RESIZE ith index m element to c
    SET arr_temp to array containing strings split FROM g_temp separated by " " 
    FOR every number j from 0 to c - 1
        SET jth index (ith index m element) element to integer jth index arr_temp element
    ENDFOR
ENDFOR
FOR every number i from 0 to r - 1
    FOR every number j from 0 to c - 1
        SET t1 to t2 to jth index (ith index m element) element
        FOR every number k from 0 to c - 1
            IF kth index (ith index m element) element > t1 THEN
                SET t1 to kth index (ith index m element)
            ENDIF
        ENDFOR
        FOR every number k from 0 to r - 1
            IF jth index (kth index m element) element < t2 THEN
                SET t1 to kth index (ith index m element)
            ENDIF
        ENDFOR
        PRINT m[i][j] + t1 + t2 ending with "  " 
    ENDFOR
    PRINT "\n" ending with ""
ENDFOR
*/

//CODE
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
std::string ltrim(const std::string &);
std::string rtrim(const std::string &);
std::vector<std::string> split(const std::string &);
int main()
{
    int r, c, t1, t2;
    std::string g_temp;
    std::getline(std::cin, g_temp);
    r = std::stoi(ltrim(rtrim(g_temp)));
    std::getline(std::cin, g_temp);
    c = std::stoi(ltrim(rtrim(g_temp)));
    std::vector<std::vector<int>> m(r);
    for (int i = 0; i < r; i++)
    {
        m[i].resize(c);
        std::getline(std::cin, g_temp);
        std::vector<std::string> arr_temp = split(rtrim(g_temp));
        for (int j = 0; j < c; j++)
        {
            int arr_item = std::stoi(arr_temp[j]);
            m[i][j] = arr_item;
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            t1 = t2 = m[i][j];
            for (int k = 0; k < c; k++)
                if (m[i][k] > t1)
                    t1 = m[i][k];
            for (int k = 0; k < r; k++)
                if (m[k][j] < t2)
                    t2 = m[k][j];
            std::cout << m[i][j] + t1 + t2 << " ";
        }
        std::cout << "\n";
    }
}
std::string ltrim(const std::string &str)
{
    std::string s(str);
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int c)
                                    { return !std::isspace(c); }));
    return s;
}
std::string rtrim(const std::string &str)
{
    std::string s(str);
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch)
                         { return !std::isspace(ch); }).base(), s.end());
    return s;
}
std::vector<std::string> split(const std::string &str)
{
    std::vector<std::string> tokens;
    std::string::size_type start = 0;
    std::string::size_type end = 0;
    while ((end = str.find(" ", start)) != std::string::npos)
    {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(str.substr(start));
    return tokens;
}