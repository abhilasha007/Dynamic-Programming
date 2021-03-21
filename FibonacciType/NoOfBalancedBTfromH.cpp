/**
 * Given an integer h, find the possible number of balanced binary trees of height h.
 *  You just need to return the count of possible binary trees which are balanced.
 * This number can be huge, so, return output modulus 10^9 + 7.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Recursive
    long long int countBT(int h) {
        if(h==0 || h == 1)
            return 1;
            
        int mod = 1e9 + 7;
        
        // return countBT(h-1) * (2 *countBT(h-2) + countBT(h-1));

        int x = countBT(h-1);
        int y = countBT(h-2);
        
        long long int temp1 = ((long long int)x * x) % mod;
        long long int temp2 = (2*(long long int)x * y) % mod;
        long long int  ans = (temp1 + temp2) % mod;
        
        return ans;
    }

    // Dynamic Programming 
    long long int countBTDP(int h) {
        if(h==0) return 1;
        vector<long long int> dp(h+1);
        dp[0] = 1;
        dp[1] = 1;
        
        int mod = 1e9 +7;
        
        for(int i=2; i<=h; ++i) {
            long long int temp1 = (dp[i-1] * dp[i-1]);
            temp1 = temp1%mod;
            long long int temp2 = (2 * dp[i-1] * dp[i-2]);
            temp2 = temp2%mod;
            dp[i] = (temp1 + temp2)%mod;
        }
        
        return dp[h];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}
  // } Driver Code Ends