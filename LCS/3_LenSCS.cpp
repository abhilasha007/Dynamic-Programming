// Getting length of shortest common supersequence
#include<bits/stdc++.h>
using namespace std;

// X : 1st given string of size m
// Y : 2nd given string of size n
int shortestCommonSupersequence(char* X, char* Y, int m, int n) {
    //code here
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
    // int LCSlen = t[m][n];
    // int totalLen = m + n;
    return (m + n - t[m][n]);
}