/** Matrix Chain Multiplication
Given an array p[] which represents the chain of matrices such that the ith matrix Ai is of 
dimension p[i-1] x p[i]. We need to write a function MatrixChainOrder() that should 
return the minimum number of multiplications needed to multiply the chain. 

Input: p[] = {40, 20, 30, 10, 30}   
Output: 26000  
There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30. Let the input 4 matrices be A, B, C and D.  
The minimum number of multiplications are obtained by putting parenthesis in following way
(A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30
**/

#include <bits/stdc++.h>
using namespace std;

//------------------------------------- D.P. Tabulation --------------------------------------------------------//
// Time Complexity: O(n^3)
// Auxiliary Space: O(n^2)
int matrixMultiplicationDP(int n, int arr[])
{
    int m[n][n]; // m[i][j] is storing minimum ops for a matrix of dimension a[i] and a[j];

    // cost is zero when multiplying one matrix
    for(int i=1; i<n; ++i)
        m[i][i] = 0;
    
    // moving diagonally
    for(int L=2; L<n; ++L) {
        for(int i=1; i<n-L+1; ++i) { //starting indices for length L
            int j = i + L - 1; //end index for each i
            m[i][j] = INT_MAX;
            for(int k=i; k<=j-1; ++k) {
                int temp = m[i][k] + m[k+1][j] + arr[i-1]*arr[k]*arr[j];
                m[i][j] = min(temp, m[i][j]);
            }
        }
    }
    return m[1][n-1];
}

//-------------------------------------Memo of Brute --------------------------------------------------------//
class Solution{
public:
    int dp[501][501];
    int solve(int arr[], int N, int i, int j) {
        if(i>=j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        dp[i][j] = INT_MAX;
        
        for(int k=i; k<=j-1; ++k) {
            int temp = solve(arr, N, i, k) + solve(arr, N, k+1, j) + arr[i-1]*arr[k]*arr[j];
            dp[i][j] = min(temp, dp[i][j]);
        }
        
        return dp[i][j];
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        int i = 1;
        int j = N-1;
        memset(dp, -1, sizeof dp);
        return solve(arr, N, i, j);
    }
};

//  Driver Code
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
}