/**
 * A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time. 
 * Implement a method to count how many possible ways the child can run up the stairs.
Examples: 

Input : 4
Output : 7
Explantion:
Below are the four ways
 1 step + 1 step + 1 step + 1 step
 1 step + 2 step + 1 step
 2 step + 1 step + 1 step 
 1 step + 1 step + 2 step
 2 step + 2 step
 3 step + 1 step
 1 step + 3 step

Input : 3
Output : 4
Explantion:
Below are the four ways
 1 step + 1 step + 1 step
 1 step + 2 step
 2 step + 1 step
 3 step
**/

/**
 * Crux
 * f(n) = f(n-1) + f(n-2) + f(n-3);
**/

#include<bits/stdc++.h>
using namespace std;

// Dynamic Programming

int getTotalWaysDP(int n) {
    int* dp = new int[n+1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; ++i) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp[n];
}

int getTotalWays(int n) {
    if(n==0) return 1;
    if(n==1) return 1;
    if(n==2) return 2;
    return getTotalWays(n-1) + getTotalWays(n-2) + getTotalWays(n-3);
}

int main() {
    int n;
    cin >> n;
    cout << getTotalWays(n);
    return 0;
}