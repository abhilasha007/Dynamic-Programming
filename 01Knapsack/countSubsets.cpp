/*Given an array find out number of sub-arrays present in the array 
whose sum is equal to given target sum*/

#include<bits/stdc++.h>
using namespace std;

//TOP DOWN
int countSubsetsDP(int arr[], int n, int sum ) {
    int** t = new int*[n+1];
    for(int i=0; i<=n; ++i){
        t[i] = new int[sum+1];
    }
    for(int i=0; i<=n; ++i){
        t[i][0] = 1;
    }
    for (int i = 1; i <=sum ; ++i){
        t[0][i] = 0;
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=sum; ++j ){
            if(arr[i-1] > j ) {
                t[i][j] = t[i-1][j] ;
            }  
            else
            if(arr[i-1] <= j) {
                t[i][j] = t[i-1][j] + t[i-1][j-arr[i-1]];
            }
        }
    }
    return t[n][sum];
}
//--------------------------------------------------------------------------------------------------------
//MEMOIZATION
int helper(int arr[], int n, int sum, int** dp){
    if(sum==0) {
        return 1;
    }
    if(n==0){
        return 0;
    }
    if(dp[n][sum]!=-1){
        return dp[n][sum];
    }
    if(arr[n-1] > sum ) {
        dp[n][sum] =  helper(arr, n-1, sum, dp);
    }
    else
        dp[n][sum] =  helper(arr, n-1, sum-arr[n-1], dp) + helper(arr, n-1, sum, dp);

    return dp[n][sum];
}

int countSubsetsMem(int arr[], int n, int sum ) {
    int** t = new int*[n+1];
    for(int i=0; i<=n; ++i){
        t[i] = new int[sum+1];
    }
    for (int i = 0; i < n+1; i++) 
            for (int j = 0; j < sum + 1; j++) 
                t[i][j] = -1;     

    return helper(arr, n, sum, t);
}

//--------------------------------------------------------------------------------------------------------
//RECURSIVE
int countSubsets(int arr[], int n, int sum ) {
    if(sum==0) {
        return 1;
    }
    if(n==0){
        return 0;
    }
    if(arr[n-1] > sum ) {
        return countSubsets(arr, n-1, sum);
    }
    return countSubsets(arr, n-1, sum-arr[n-1]) + countSubsets(arr, n-1, sum);
}

int main() {
    int arr[] = {2, 3, 4, 5, 6, 8, 10};
    int sum = 10;
    cout<< "Number of subsets with sum " << sum << " is "<< countSubsetsMem(arr, 7, sum);
}