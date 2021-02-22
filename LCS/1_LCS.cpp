//Find length of longest common subsequence of 2 strings
#include<bits/stdc++.h>
using namespace std;
//DP
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size(); int m = text2.size();
    int t[n+1][m+1];
    // memset(t, -1, sizeof(t));
    for(int i=0; i<=n; ++i) {
        t[i][0] = 0;
    }
    for(int i=0; i<=m; ++i){
        t[0][i] = 0;
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j) {
            if(text1[i-1]== text2[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
    }
    return t[n][m];
}
//MEMOIZATION------------------------------------------------------------------//
int LCSMemHelper(string x, string y, int n, int m, int** t) {
    if(n==0 || m==0){
        return 0;
    }
    if(t[n][m]!=-1) {
        return t[n][m];
    }
    if(x[n-1] == y[m-1]) {
        t[n][m] = 1 + LCSMemHelper(x, y, n-1, m-1, t);
    }
    else {
        t[n][m] = max(LCSMemHelper(x, y, n-1, m, t), LCSMemHelper(x, y, n, m-1, t));
    }
    return t[n][m];
}
int LCSmem(string x, string y, int n, int m) {
    int** dp = new int*[n+1];
    for(int i=0; i<=n; ++i){
        dp[i] = new int[m+1];
    }
    for(int i=0; i<=n; ++i){
        for(int j=0; j<=m; ++j) {
            dp[i][j] = -1;
        }
    }
    return LCSMemHelper(x, y, n, m, dp);
}
//RECURSIVE -------------------------------------------------------------------//
int LCS(string x, string y, int n, int m) {
    if(n==0 || m==0) {
        return 0;
    }
    if(x[n-1] == y[m-1]){
        return 1 + LCS(x, y, n-1, m-1);
    }
    else
    return max(LCS(x, y, n-1, m), LCS(x, y, n, m-1));
}

int main() {
    string x = "abcdegh";
    string y = "absdrghf"; 
    cout<<"Length of longest common subsequence is " << LCS(x, y, x.length(), y.length());
}