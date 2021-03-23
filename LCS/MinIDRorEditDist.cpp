//----------------------------------- Dynamic Programming -------------------------------------//
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        int dp[m+1][n+1];
        
        dp[0][0] = 0;
        
        for(int i=1; i<=n; ++i) dp[0][i] = i;
        for(int j=1; j<=m; ++j) dp[j][0] = j;
        
        for(int i=1; i<=m; ++i) {
            for(int j=1; j<=n; ++j) {
                if(word1[i-1] == word2[j-1]) 
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
            }
        }
        
        return dp[m][n];
    }
};

//----------------------------------- MEMOIZATION --------------------------------------------// 
class Solution {
public:
    int output[501][501];

    int editDist(string s, string t, int m, int n) {
        // inserting all the chars of t in s
        if(m==0) return n; 
        // deleting all the chars of s
        if(n==0) return m;
        
        if(output[m][n] != -1) return output[m][n];
        
        int ans;
        if(s[m-1] == t[n-1]) ans =  editDist(s, t, m-1, n-1);
        else
        ans = 1 + min( editDist(s,t,m,n-1), min(editDist(s,t,m-1,n), editDist(s,t,m-1,n-1)));
        
        output[m][n] = ans;
        return ans;
    }
    
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        memset(output, -1, sizeof output);
        return editDist(word1, word2, m, n);
    }
};

//--------------------------------- RECURSIVE/BRUTE ----------------------------------------//
class Solution {
public:
    int editDist(string s, string t, int m, int n) {
        // inserting all the chars of t in s
        if(m==0) return n;
        // deleting all the chars of s
        if(n==0) return m;
        
        if(s[m-1] == t[n-1]) return editDist(s, t, m-1, n-1);
        
        return 1 + min( editDist(s,t,m,n-1), min(editDist(s,t,m-1,n), editDist(s,t,m-1,n-1)));
    }
    
    int minDistance(string word1, string word2) {
        return editDist(word1, word2, word1.size(), word2.size());
    }
};