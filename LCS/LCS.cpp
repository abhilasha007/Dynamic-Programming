//Find length of longest common subsequence of 2 strings
/**
 * Given two strings text1 and text2, return the length of their longest common subsequence. 

    Example 1:
    Input: text1 = "abcde", text2 = "ace" 
    Output: 3  
    Explanation: The longest common subsequence is "ace" and its length is 3.

    Example 2:
    Input: text1 = "abc", text2 = "abc"
    Output: 3
    Explanation: The longest common subsequence is "abc" and its length is 3.

    Example 3:
    Input: text1 = "abc", text2 = "def"
    Output: 0
    Explanation: There is no such common subsequence, so the result is 0.
*/

#include<bits/stdc++.h>
using namespace std;

//--------------------------------- Dynamic Programming --------------------------------------//
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

//------------------------------------MEMOIZATION-------------------------------------------//
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

//------------------------------------- RECURSIVE ----------------------------------------------//
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


// Driver code
int main() {
    string x = "abcdegh";
    string y = "absdrghf"; 
    cout<<"Length of longest common subsequence is " << LCS(x, y, x.length(), y.length());
}

/**
 * A subsequence of a string is a new string generated from the original string with 
 * some characters (can be none) deleted without changing the relative order of the 
 * remaining characters.
 * For example, "ace" is a subsequence of "abcde".
 * A common subsequence of two strings is a subsequence that is common to both strings.
**/
/**
LCS 
SCS = m + n - LCS
LPS = LCS(x, rev(x))
LRS = LCS(x, x) and in if condition also check i!=j

LCsubstr --> LCS but maintain a result variable; in else case t[i][j] = 0; 

min insertions & deletions to convert a to b = (m-LCS) + (n-LCS) = m + n - 2*LCS
min insertions for palindrome = m - LPS 
min deletions for palindrome = m - LPS
**/