// if(LCS(a, b) == min(a, b)) return true;

/* Given two strings s and t, check if s is a subsequence of t.
A subsequence of a string is a new string that is formed from the original string 
by deleting some (can be none) of the characters without disturbing 
the relative positions of the remaining characters. 
(i.e., "ace" is a subsequence of "abcde" while "aec" is not).
Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true
**/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();
        int dp[m+1][n+1];
        for(int i=0; i<=m; ++i) dp[i][0] = 0;
        for(int i=1; i<=n; ++i) dp[0][i] = 0;
        
        for(int i=1; i<=m; ++i){
            for(int j=1; j<=n; ++j){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return (m == dp[m][n]);
    }
};