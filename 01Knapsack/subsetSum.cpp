/* Given an array find out if there's any sub-array that exist whose sum is equal to given target sum*/

#include<bits/stdc++.h>
using namespace std;
//RECURSION
bool subsetSum(int* arr, int n, int sum) {
    if(sum==0) {
        return true;
    } 
    if(n==0) {
        return false;
    }
    if(arr[n-1] > sum ) {
        return subsetSum(arr, n-1, sum);
    } 
    return (subsetSum(arr, n-1, sum-arr[n-1]) || subsetSum(arr, n-1, sum));
} 

//DYNAMIC / TOP DOWN
bool subsetSumDP(int arr[], int n, int sum ) {
    bool** t = new bool*[n+1];
    for(int i=0; i<=n; ++i){
        t[i] = new bool[sum+1];
    } 
    for(int i=0; i<=n; ++i) {
        t[i][0] = true;
    }
    for(int i=1; i<=sum; ++i) {
        t[0][i] = false;
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=sum; ++j){
            if(arr[i-1] <= j) {
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else 
            if(arr[i-1] > j) {
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

int main() {
    int arr[] = {2, 3, 7, 8, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 11; 
    subsetSumDP(arr, n, sum) ? cout << "true" : cout << "false" ;
}