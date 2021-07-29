/** Shortest Uncommon Subsequence 
 * Given two strings S and T, find length of the shortest subsequence in S 
 which is not a subsequence in T. If no such subsequence is possible, return -1. 
 A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. 
 A string of length n has 2^n different possible subsequences.
Example 1:
Input:
S = "babab"
T = "babba"
Output: 3
Explanation: There are no subsequences of S with length less than 3 which is not a subsequence of T. 
"aab" is an example of a subsequence of length 3 which isn't a subsequence of T.
**/

#include <bits/stdc++.h>
using namespace std;

//----------------------------------------- D.P. ------------------------------------------//

class Solution {
  public:
    #define MAX 1005
    int shortestUnSubDP(string S, string T) {
        int m = S.size(), n = T.size();
        int t[m+1][n+1];
        
        for (int i = 0; i <= m; i++) t[i][0] = 1;
        for (int i = 0; i <= n; i++) t[0][i] = MAX;        
        
        for(int i=1; i<=m; ++i) {
            for(int j=1; j<=n; ++j) {
                char ch = S[i-1];
                int k;
                for(k=j-1; k>=0; --k)
                    if(T[k] == ch) break;
                
                if(k==-1) t[i][j] = 1;
                else
                    t[i][j] = min(t[i-1][j], 1 + t[i-1][k]);
            }
        }
        int ans = t[m][n];
        if (ans >= MAX)
            ans = -1;
     
        return ans;
    }
};

//----------------------------------------- Brute force ------------------------------------------//
class Solution {
  public:
    # define MAX 1005
    int suss(string s, string t, int m, int n) {
        if(m==0) return MAX;
        if(n==0) return 1;
        
        int k;
        for(k=n-1; k>=0; --k)
            if(t[k] == s[m-1]) break;
        
        if(k==-1) return 1;
        
        return min(suss(s, t, m-1, n), 1 + suss(s, t, m-1, k));
    }
    
    int shortestUnSub(string S, string T) {
        return suss(S, T, S.size(), T.size());
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        cin>>S>>T;

        Solution ob;
        cout << ob.shortestUnSub(S,T) << endl;
    }
    return 0;
}  // } Driver Code Ends