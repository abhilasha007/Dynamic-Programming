/**
 * You are given coins of different denominations and a total amount of money. 
 * Write a function to compute the number of combinations (or maximum number of ways) that make up that amount. 
 * You may assume that you have infinite number of each kind of coin.
Example 1:
Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1 
**/

#include<bits/stdc++.h>
using namespace std;
int coinChangeMax(int coins[], int n, int amount) {
    int t[n+1][amount+1];
    
    for(int i=0; i<=n; ++i) {
        t[i][0] = 1;
    }
    for(int i=1; i<=amount; ++i) {
        t[0][i] = 0;
    }
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=amount; ++j) {
            if(coins[i-1] > j) {
                t[i][j] = t[i-1][j];
            }
            else {
                t[i][j] = t[i][j-coins[i-1]] + t[i-1][j];
            }
        }
    }
    return t[n][amount];
}
int main() {
    int arr[] = {1,2,5};
    int amount = 5;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<< coinChangeMax(arr, n, amount);
}
