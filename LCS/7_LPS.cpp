/**
 * Given a string s, find the longest palindromic subsequence's length in s.
 *  You may assume that the maximum length of s is 1000.
Example 1:
Input:"bbbab"
Output: 4
**/
#include<bits/stdc++.h>
using namespace std;
int longestPalindromeSubseq(string s) {
    string str1 = s;
    reverse(s.begin(), s.end());
    string str2 = s;
    int m = str1.length();
    int n = str2.length();
    int t[m+1][n+1];
    for(int i=0; i<=m; ++i){
        t[i][0] = 0;
    }
    for(int i=0; i<=n; ++i) {
        t[0][i] = 0;
    }
    for(int i=1; i<=m; ++i){
        for(int j=1; j<=n; ++j){
            if(str1[i-1]==str2[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else {
                t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
    }
    return t[m][n];
}
