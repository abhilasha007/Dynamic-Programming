// SCS = m + n - LCS

// Getting length of shortest common supersequence
/**
 * Examples : 
    Input:   str1 = "geek",  str2 = "eke"
    Output: 5
    Explanation: 
    String "geeke" has both string "geek" and "eke" as subsequences.

    Input:   str1 = "AGGTAB",  str2 = "GXTXAYB"
    Output:  9
    Explanation: 
    String "AGXGTXAYB" has both string "AGGTAB" and "GXTXAYB" as subsequences.
 **/

#include<bits/stdc++.h>
using namespace std;

int shortestCommonSupersequence(char* X, char* Y, int m, int n) {
    int t[m+1][n+1];
    for(int i=0; i<=m; ++i){
        t[i][0] = 0;
    }
    for(int i=0; i<=n; ++i) {
        t[0][i] = 0;
    }
    for(int i=1; i<=m; ++i){
        for(int j=1; j<=n; ++j){
            if(X[i-1]==Y[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else {
                t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
    }
    // int totalLen = m + n;
    // int LCSlen = t[m][n];
    return (m + n - t[m][n]);
}