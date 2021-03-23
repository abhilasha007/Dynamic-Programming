// Minimum deletions from a = m - LCS
// Minimum insertions in remaining a = n - LCS
// total ins and del operations = m + n - 2*LCS

/**
 * Given two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2. 
 * It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.
Example 1: Input: str1 = "heap", str2 = "pea"
Output: 3
**/
//OR
/**
 * Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same,
 *  where in each step you can delete one character in either string.
Example 1:
Input: "sea", "eat"
Output: 2
**/

#include<bits/stdc++.h>
using namespace std;

int minOperations(string str1, string str2) 
{ 
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
    return m + n - 2*t[m][n];
} 