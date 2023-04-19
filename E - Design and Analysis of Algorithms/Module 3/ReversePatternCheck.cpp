//ALGORITHM
/*
ReverseOccurrence(T, P)
{
    TR <- reverse(T)
    if (P is a substring of TR or reverse(P) is a substring of T)
    {
        return true
    }
    else
    {
        return false
    }
}
*/

//CODE
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool reverse_occurrence(string T, string P)
{
    string TR = T;
    reverse(TR.begin(), TR.end());
    if (TR.find(P) != string::npos || T.find(string(P.rbegin(), P.rend())) != string::npos)
        return true;
    else
        return false;
}
int main()
{
    string T, P;
    cout << "T: ";
    cin >> T;
    cout << "P: ";
    cin >> P;
    if (reverse_occurrence(T, P))
        cout << "Pattern P occurs in text T reversely." << endl;
    else
        cout << "Pattern P does not occur in text T reversely." << endl;
    return 0;
}
