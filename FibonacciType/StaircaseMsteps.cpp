/**
 * ways(n, m) = ways(n-1, m) + ways(n-2, m) + ... ways(n-m, m) 
**/

#include<bits/stdc++.h>
using namespace std;

int totalWaysDP(int n, int m) {
    int* dp = new int[n+1];
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=n; ++i) {
        dp[i] = 0;
        for(int j=1; j<=m && j<=i; ++j) {
            dp[i] += dp[i-j];
        }
    }
    return dp[n];
}

int totalWays(int n, int m) {
    if(n==0) return 1;
    if(n==1) return 1;
    if(n==2) return 2;
    int ways = 0;
    for(int i=3; i<=m && i<=n; ++i) {
        ways += totalWays(n-i, m);
    }
    return ways;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    cout << totalWays(n, m);
    return 0;
}