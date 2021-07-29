/** PALINDROME PARTITIONING
 * Given a string s, partition s such that every substring of the partition is a palindrome.
    Return the minimum cuts needed for a palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
**/

#include <bits/stdc++.h>
using namespace std;

//--------------------------------------- D.P. with optimization -------------------------------------------//
// Time Complexity: O(n^2)
int minCut(string s) {
    int n = s.size();
    bool P[n][n];
    int C[n];
    
    for(int i=0; i<n; ++i) 
        P[i][i] = true;
    
    for(int L=2; L<=n; ++L) {
        for(int i=0; i<n-L+1; ++i) {
            int j = i + L - 1;
            if(L==2) 
                P[i][j] = (s[i]==s[j]);
            else
                P[i][j] = (s[i]==s[j]) && P[i+1][j-1];
        }
    }
    
    for(int i=0; i<n; ++i) {
        if(P[0][i] == true) 
            C[i] = 0;
        else {
            C[i] = INT_MAX;
            for(int j=0; j<i; ++j){
                if(P[j+1][i]) 
                    C[i] = min(C[i], 1 + C[j]);
            }
        }
    }
    return C[n-1];      
}

// T.L.E in all :-
//---------------------------------------- D.P. --------------------------------------------------------//
// Time Complexity: O(n^3)
int palindromicPartitionDP(string str)
{
    int n = str.length();
    int C[n][n];
    bool P[n][n];
    
    for(int i=0; i<n; ++i) {
        P[i][i] = true;
        C[i][i] = 0;
    }
    
    for(int L=2; L<=n; ++L) {
        for(int i=0; i<n-L+1; ++i) {
            int j = i + L - 1;
            
            if(L==2)
                P[i][j] = (str[i] == str[j]);
            else
                P[i][j] = (str[i] == str[j]) && P[i+1][j-1];
                
            if(P[i][j] == true)
                C[i][j] = 0;
            else {
                C[i][j] = INT_MAX;
                for(int k=i; k<=j-1; ++k) {
                    C[i][j] = min(C[i][j], 1 + C[i][k] + C[k+1][j]);
                }
            }
        }
    }
    return C[0][n-1];
}


//----------------------------------------- Memo of Brute --------------------------------------------------//
class Solution{
public:
    int dp[501][501];
    bool isPalindrome(string s, int i, int j){
        while(i<=j) {
            if(s[i] != s[j]) return false;
            ++i; --j;
        }
        return true;
    }
    
    int solve(string s, int i, int j) {
        if(i>=j || isPalindrome(s, i, j)) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        dp[i][j] = INT_MAX;
        for(int k=i; k<=j-1; ++k) {
            dp[i][j] = min(1 + solve(s, i, k) + solve(s, k+1, j), dp[i][j]);
        }
        return dp[i][j];
    }
    
    int palindromicPartition(string str){
        memset(dp, -1, sizeof dp);
        return solve(str, 0, str.length()-1);
    }
};

// Driver Code
int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}