/**
 * Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. 
 * Determine the maximum value obtainable by cutting up the rod and selling the pieces.

For example, if length of the rod is 8 and the values of different pieces are given as following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6) 
length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20

And if the prices are as following, then the maximum obtainable value is 24 (by cutting in eight pieces of length 1) 
length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 3   5   8   9  10  17  17  20
**/

#include <iostream>
using namespace std;

//-------------------------------------- D.P. -------------------------------------------//
int rodCuttingDP(int length[], int prices, int n, int maxLen) {
    int dp[n+1][maxLen+1];
    for(int i=0; i<=n; ++i) dp[i][0] = 0;
    for(int i=1; i<=maxLen; ++i) dp[0][i] = 0;

    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=maxLen; ++j) {
            if(length[i-1] <= j)
                dp[i][j] = max(prices[i-1] + dp[i][j-length[i-1]], dp[i-1][j]);
            else
                dp[i][j] = [i-1][j];
        }
    }
    return dp[n][maxLen];
}

//---------------------------- Memoization of Brute force ---------------------------------//
int t[101][101];

int rodCutting(int length[], int prices, int n, int max_length) {
    if(n<=0 || max_length==0) return 0;

    if(length[n-1] <= max_length) {
        t[n][max_length] = max(prices[n-1] + rodCutting(length, prices, n, max_length-length[n-1]),
                                        rodCutting(length, prices, n-1, max_length));
    }
    else 
        t[n][max_length] = rodCutting(length, prices, n-1, max_length);

    return t[n][max_length];
}

//driver code
int max_rodCutting(int n, int prices[]) {
    int length[n];
    for(int i=0; i<n; ++i) {
        length[i] = i+1;
    }
    int max_len = n;
    return rodCutting(length, prices, n, max_len);
    // return rodCuttingDP(length, prices, n, max_len);
}
