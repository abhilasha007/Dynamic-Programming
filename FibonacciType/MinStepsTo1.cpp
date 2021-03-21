// { Driver Code Starts
/**
 * Given a number N, the task is to count minimum steps to minimize it to 1 according to the following criteria:
If N is divisible by 2 then you may reduce N to N/2.
If N is divisible by 3 then you may reduce N to N/3.
Otherwise, Decrement N by 1.

Example 1:
Input: N = 10
Output: 3
Explanation: 10 - 1 = 9 / 3 = 3 / 3 = 1

Example 2:
Input: N = 1
Output: 0
Explanation: N is 1
**/
/**
 * Crux
 * f(n) = f(n-1);
 * f(n) = f(n/2); if(n%2==0) 
 * f(n) = f(n/3); if(n%3==0)
**/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    // MEMOIZATION
    int getMinSteps(int N, int* mem) {
	    if(N==1) {
            return 0;
        }
        if(mem[N] != -1) {
            return mem[N];
        }
        
        int res = getMinSteps(N-1, mem);
        
        if(N%2==0)
            res = min(res, getMinSteps(N/2, mem));
            
        if(N%3==0)
            res = min(res, getMinSteps(N/3, mem));
            
        mem[N] =  1 + res;
        return mem[N];
	}
    public:
	int minSteps(int N) 
	{
	    int *mem = new int[N+1];
	    for(int i=0; i<=N; ++i) {
	        mem[i] = -1;
	    }
	    return getMinSteps(N, mem);
	} 

    // Dynamic Programming
    int minStepsDP(int N) 
	{ 
	    int *dp = new int[N+1];
	    dp[0] = 0;
	    dp[1] = 0;
	    dp[2] = 1;
	    for(int i=3; i<=N; ++i) {
	       int res = dp[i-1];
	       if(i%2 == 0)
	        res = min(res, dp[i/2]);
	       if(i%3 == 0) 
	        res = min(res, dp[i/3]);
	        
	        dp[i] = 1 + res;
	    }
	    return dp[N];
	}
};


// { Driver Code Starts.
int main() 
{  
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

	    Solution ob;
	    cout << ob.minSteps(n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends