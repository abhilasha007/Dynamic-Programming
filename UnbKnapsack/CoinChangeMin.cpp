/**
 * You are given coins of different denominations and a total amount of money amount.
 *  Write a function to compute the fewest number of coins that you need to make up that amount.
 *  If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.
Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
**/

#include<bits/stdc++.h>
using namespace std;
int minCoins(int coins[], int n, int sum) 
{ 
    int t[n+1][sum+1];
    
    //Initialization
    //first row
    for(int i=0; i<=sum; ++i) {
        t[0][i] = INT_MAX - 1;
    }
    //first column
    for(int i=1; i<=n; ++i) {
        t[i][0] = 0; 
    }
    // second row
    for(int j=1; j<=sum; ++j) {
        if(j%coins[0] == 0) {
            t[1][j] = j/coins[0];
        }
        else {
            t[1][j] = INT_MAX-1;
        }
    }
    
    //Remaining cells : Recursion to Iterative
    for(int i=2; i<=n; ++i) {
        for(int j=1; j<=sum; ++j) {
            if(coins[i-1] <= j) {
                t[i][j] = min( 1 + t[i][j-coins[i-1]] , t[i-1][j] );
            }
            else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    if(t[n][sum] == INT_MAX-1) 
        return -1;
    else
        return t[n][sum];
}