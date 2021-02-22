/*Given an array find out the number of pair of sub-arrays whose 
difference is equal to given target difference*/

#include<bits/stdc++.h>
using namespace std;
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
int countPairSubsets(int arr[], int n, int diff) {
    int sumOfarr = 0;
    for(int i=0; i<n; ++i) {
        sumOfarr += arr[i];
    }
    if(diff>sumOfarr || (sumOfarr+diff)%2!=0) return 0;
    int s1 = (diff + sumOfarr)/2;
    return countSubsetsDP(arr, n, s1);
}
int main() {
    int arr[] = {1,1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int diff = 1;
    cout<< countPairSubsets(arr, n, diff);
}
// ans 3 because there are 3 such pair of subsets with diff=1 :-
// [1,1] [3] ; [2] [3]; [1] [2] 