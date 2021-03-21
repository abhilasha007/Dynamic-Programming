/**
 * Given a number n, find the minimum number of squares that sum to X.
Examples : 

Input:  n = 100
Output: 1
Explanation:
100 can be written as 102. 
Note that 100 can also be written as 5^2 + 5^2 + 5^2 + 5^2, but this representation requires 4 squares.

Input:  n = 6
Output: 3

**/

#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
    // DP
    int minSquaresDP(int n) {
        int* dp = new int[n+1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int i=4; i<=n; ++i){
            if(sqrt(i)-floor(sqrt(i)) == 0) 
                dp[i] = 1;
            int res = i;
            for(int j=1; j<=ceil(sqrt(i)); ++j) {
                int temp = j*j;
                if(temp > i) break;
                else
                    res = min(res, 1 + dp[i-temp]);
            }
            dp[i] = res;
        }
        return dp[n];
    }

    // BRUTE FORCE T.L.E
	int MinSquares(int n)
	{
	    // checking if perfect square
	    if(sqrt(n) - floor(sqrt(n)) == 0) return 1;
	    if(n<=3) return n;
	    // if anything 1^2 * n times
	    int res = n;
	    for(int x=1; x<=n; ++x){
	        int temp_sq = x*x;
	        if(temp_sq > n) break;
	        else 
	            res = min(res, 1 + MinSquares(n-temp_sq));
	    }
	    return res;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}