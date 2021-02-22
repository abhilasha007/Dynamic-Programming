
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int dp[100][100];
    int solve(int arr[], int i, int j){
        if(i>=j) return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        dp[i][j] = INT_MAX;
        for(int k = i; k<=j-1; ++k){
            dp[i][j] =  min(dp[i][j],
                            (solve(arr, i, k)+ solve(arr, k + 1, j)
                            + arr[i - 1] * arr[k] * arr[j])); 
        }
        return dp[i][j];
    }
    int matrixMultiplication(int N, int arr[])
    {
        int i = 1;
        int j = N-1;
        memset(dp, -1, sizeof dp); 
        return solve(arr, i, j);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends