/*Partition problem is to determine whether a given set can be partitioned into 
two subsets such that the sum of elements in both subsets is the same. */

#include<bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int> arr, int n, int sum) {
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

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for(int i=0; i<nums.size() ; ++i) {
        sum += nums[i];
    }
    if(sum%2!=0){
        return false;
    }
    return subsetSum(nums,nums.size(), sum/2);   
}
    
int main() {
    vector<int> arr = { 3, 1, 5, 9, 12 };
    // Function call
    if (canPartition(arr) == true)
        cout << "Can be divided into two subsets "
                "of equal sum";
    else
        cout << "Can not be divided into two subsets"
                " of equal sum";
    return 0;
}