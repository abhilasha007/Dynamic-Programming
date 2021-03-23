// Minimum insertions in string to make palindrome =  m - LPS

/*
Given a string s. 
In one step you can insert any character at any index of the string.
Return the minimum number of steps to make s palindrome.
Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm" 
*/

#include<bits/stdc++.h>
using namespace std;
int minInsertions(string s) {
    int m = s.length();
    string s1 = s;
    reverse(s.begin(), s.end());
    string s2 = s;
    
    int t[m+1][m+1];
    for(int i=0; i<=m; ++i) t[i][0] = 0;
    for(int i=1; i<=m; ++i) t[0][i] = 0;

    for(int i=1; i<=m; ++i){
        for(int j=1; j<=m; ++j) {
            if(s1[i-1] == s2[j-1]) t[i][j] = 1 + t[i-1][j-1];
            else
            t[i][j] = max(t[i][j-1], t[i-1][j]);
        }
    }
    return m - t[m][m];
}