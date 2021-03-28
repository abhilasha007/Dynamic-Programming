/** 
 * Integer Break
Given an integer n, break it into the sum of k positive integers, where k >= 2,
and maximize the product of those integers. Return the maximum product you can get.

Example 1:
Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.

Example 2:
Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.

Constraints: 2 <= n <= 58
**/
//------------------------------------------ D.P. --------------------------------------------//



//-------------------------------- Memoization of brute ------------------------------------------//
class Solution {
public:
    long long int dp[59][59];
    long long int solve(int arr[], int maxn, int n) {
        if(n==0 && maxn>0) return INT_MIN;
        
        if(maxn == 0){
            dp[n][maxn] = 1;
            return 1;
        }
        
        if(dp[n][maxn] != -1) return dp[n][maxn];
        
        if(arr[n-1] <= maxn) {
            dp[n][maxn] = max(arr[n-1]*solve(arr, maxn-arr[n-1], n), solve(arr, maxn, n-1));
        }
        else dp[n][maxn] = solve(arr, maxn, n-1);
        
        return dp[n][maxn];
    }
    
    int integerBreak(int n) {
        if(n==2) return 1;
        memset(dp, -1, sizeof dp);
        int arr[n-1];
        for(int i=0; i<n-1; ++i) arr[i] = i+1;
        long long int ans = solve(arr, n, n-1);
        return ans;
    }
};