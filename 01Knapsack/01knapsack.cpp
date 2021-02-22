/*Given weights and values of n items, put these items in a knapsack of capacity W to get the 
maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] 
which represent values and weights associated with n items respectively. Also given an integer 
W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the 
weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete 
item or don’t pick it (0-1 property).
*/

#include <bits/stdc++.h> 
using namespace std; 

//RECURSIVE
int knapsack(int wt[], int val[], int W, int n){
    if(n==0 || W==0){
        return 0;
    }
    if(wt[n-1] <= W ) {
        return max((val[n-1] + knapsack(wt, val, W-wt[n-1], n-1)) , (knapsack(wt, val, W, n-1)));
    }
    else { 
        return knapsack(wt, val, W, n-1);
    }
}
//MEMOIZATION
int helper(int* wt, int* val, int W, int n, int** t) {
    if(n<=0 || W==0){
        return 0;
    }
    if(t[n][W] != -1) {
        return t[n][W];
    }
    if(wt[n-1] <= W ) {
        t[n][W] = max((val[n-1] + helper(wt, val, W-wt[n-1], n-1, t)) , (helper(wt, val, W, n-1, t)));
    }
    else {
        t[n][W] = helper(wt, val, W, n-1, t);
    }
    return t[n][W];
}
int knapsackMem(int wt[],int val[], int W, int n) {
    int** t = new int*[n+1];
    for(int i=0; i<=n; ++i ){
        t[i] = new int[W+1];
    }
    for (int i = 0; i <= n; i++) 
            for (int j = 0; j < W + 1; j++) 
                t[i][j] = -1;     

    int ans =  helper(wt, val, W, n, t);
    for(int i=0; i<=n; ++i){
        for(int j=0; j<=W; ++j){
            cout<< t[i][j] <<" ";
        }
        cout<<endl;
    }
    return ans;
}

// TOP DOWN
int knapsackDP(int wt[], int val[], int W, int n) {
    int** t = new int*[n+1];
    for(int i = 0 ; i<=n; ++i ){
        t[i] = new int[W+1];
    }


    for(int i=0; i<=n; ++i){
        for(int j=0; j<=W; ++j) {
            //initialization using base condition of recursive
            if(i==0 || j==0) {
                t[i][j] = 0;
            }
            //converting recursive calls into iterative
            else
                if(wt[i-1] <= j) {
                    t[i][j] = max( (val[i-1] + t[i-1][j-wt[i-1]]), t[i-1][j] );
                }
            else 
                if(wt[i-1] > j) {
                    t[i][j] = t[i-1][j];
                }
        }
    }
    for(int i=0; i<=n; ++i){
        for(int j=0; j<=W; ++j){
            cout<< t[i][j] <<" ";
        }
        cout<<endl;
    }
    return t[n][W];
}

int main() {
    int val[] = { 60, 100, 120 }; 
    int wt[] = { 10, 20, 30 }; 
    int W = 50; 
    int n = sizeof(val) / sizeof(val[0]); 
    // cout << knapsack(wt, val, W, n) <<endl; 
    // cout << knapsackMem(wt, val, W, n) <<endl;
    cout << knapsackDP(wt, val, W, n) <<endl;
    return 0; 
}