/** Cut Ribbon
 * Polycarpus has a ribbon, its length is n.
    He wants to cut the ribbon in a way that fulfils the following two conditions:
    1.  After the cutting each ribbon piece should have length a, b or c.
    2.  After the cutting the number of ribbon pieces should be maximum.
Help Polycarpus and find the number of ribbon pieces after the required cutting.
Input
The first line contains four space-separated integers n, a, b and c (1 ≤ n, a, b, c ≤ 4000) — the length of the original ribbon and the acceptable lengths of the ribbon pieces after the cutting, correspondingly. The numbers a, b and c can coincide.
Output
Print a single number — the maximum possible number of ribbon pieces. It is guaranteed that at least one correct ribbon cutting exists.

Examples
input: 5 5 3 2
output: 2
**/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll t[4][4005],len,n=3;

//---------------------------- Memoization of brute --------------------------------------------//
ll ribbonCut(ll* arr, ll n, ll len) {
    if(n==0) return INT_MIN;
    if(len==0) return 0;
    if(t[n][len] != -1) return t[n][len];
    if(arr[n-1] <= len) {
        t[n][len] = max(1 + ribbonCut(arr, n, len-arr[n-1]), ribbonCut(arr, n-1, len));
    }
    else t[n][len] = ribbonCut(arr, n-1, len);
    return t[n][len];
}

//------------------------------ DP / tabulation ------------------------------------------------//
ll ribbonCutDP(ll* arr, ll n, ll len) {
    ll dp[n+1][len+1];
    for(int i=0; i<=len; ++i) dp[0][i] = INT_MIN;
    for(int i=1; i<=n; ++i) dp[i][0] = 0;

    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=len; ++j) {
            if(arr[i-1] <=j) {
                dp[i][j] = max(1 + dp[i][j-arr[i-1]], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][len] <= 0 ? 0 : dp[n][len];
}

//driver code
int main() {
    memset(t, -1, sizeof t);
    cin>> len;
    ll *arr = new ll[n];
    for(ll i=0; i<3; ++i) 
        cin>> arr[i];
    cout << ribbonCutDP(arr, n, len);
    return 0;
}