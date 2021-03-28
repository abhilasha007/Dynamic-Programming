/**
 * Given a set of N items, each with a weight and a value, and a weight limit W. 
 * Find the maximum value of a collection containing any of the N items any number of times 
 * so that the total weight is less than or equal to W.

Example 1:
Input: N = 2, W = 3
val[] = {1, 1}
wt[] = {2, 1}
Output: 3
Explaination: Pick the 2nd element thrice.

Example 2:
Input: N = 4, W = 8
val[] = {1, 4, 5, 7}
wt[] = {1, 3, 4, 5}
Output: 11
Explaination: The optimal choice is to pick the 2nd and 4th element.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    //------------------------------------ D.P. ----------------------------------------------//
    int knapSack(int N, int W, int val[], int wt[]) {
        int dp[N+1][W+1];
        for(int i=0; i<=W; ++i) dp[0][i] = 0;
        for(int i=0; i<=N; ++i) dp[i][0] = 0;
        
        for(int i=1; i<=N; ++i) {
            for(int j=1; j<=W; ++j) {
                if(wt[i-1] <= j)
                    dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[N][W];
    }

    //--------------------------------- Brute force -------------------------------------------//
    int knapSackBrute(int N, int W, int val[], int wt[]) {
        if(N<=0 || W==0) return 0;

        if(wt[N-1] <= W) 
            return max(val[N-1] + knapSack(N, W-val[N-1], val, wt) , knapSack(N-1, W, val, wt));
        
        return knapSack(N-1, W, val, wt);
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}