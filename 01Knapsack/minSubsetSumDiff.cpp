// Given an integer array arr of size N, the task is to divide it into
// two sets S1 and S2 such that the absolute difference between their 
//sums is minimum and find the minimum difference

#include<bits/stdc++.h>
using namespace std;

vector<int> subsetSum(int arr[], int n, int sum) {
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
    vector<int> v;
    for(int i=0; i<=(sum/2); ++i) {
        if(t[n][i]){
            v.push_back(i);
        }
    }
    return v;
}

int minDifference(int arr[], int n) {
    int range = 0;
    for(int i=0; i<n; ++i){
        range += arr[i];
    }      
    vector<int> candidatesS1 = subsetSum(arr, n, range);
    int min_diff = INT_MAX;
    for(int i=0; i < candidatesS1.size(); ++i) {
        min_diff = min(min_diff, range-(2*candidatesS1[i]));
    }
    return min_diff;
}

int main() {
    int arr[] = {1,6,11,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Minimum difference is " << minDifference(arr, n);
    return 0;
}
