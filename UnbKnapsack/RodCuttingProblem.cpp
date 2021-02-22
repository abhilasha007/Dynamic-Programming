#include <bits/stdc++.h>
using namespace std;
//RECHECK-_-
//DP
// int cutRodDP(int prices[], int length[], int Max_len, int n) {
//     int** t = new int*[n+1];
//     for(int i=0; i<=n; ++i) {
//         t[i] = new int[Max_len+1];
//     }

//     for(int i=0; i<=n; ++i) {
//         t[i][0] = 0;
//     }   
//     for(int i=1; i<=Max_len; ++i) {
//         t[0][i] = 0;
//     }
//     for(int i=1; i<=n; ++i){
//         for(int j=1; j<=Max_len; ++j){
//             if(length[i-1] > j) {
//                 t[i][j] = t[i-1][j];
//             }
//             else {
//                 t[i][j] = max(prices[i-1] + t[i][j-length[i-1]], t[i-1][j]);
//             }
//         }
//     }
//     return t[n][Max_len];
// }

//Recursive
int un_kp(int price[], int length[], int Max_len, int n, int **t) 
{ 
    if (n == 0 || Max_len == 0)  
    { 
        return 0; 
    } 
    // if(t[n][Max_len]!=-1) {
    //     return t[n][Max_len];
    // }
    if (length[n - 1] <= Max_len)  
    { 
        t[n][Max_len] = max(price[n - 1] + un_kp(price, length, Max_len - length[n - 1], n, t), 
                  un_kp(price, length, Max_len, n - 1, t)); 
    } 
    
    else 
    { 
        t[n][Max_len] = un_kp(price, length, Max_len, n - 1, t); 
    } 
    return t[n][Max_len]; 
} 

int cutRod(int prices[], int Max_l, int n) {
    int* length = new int[n];
    for(int i=0; i<n; ++i) {
        length[i] = i+1;
    }
    int** dp = new int*[n+1];
    for(int i=0; i<=n; ++i) {
        dp[i] = new int[n+1];
    }
    for (int i = 0; i < n+1; i++) 
            for (int j = 0; j < n + 1; j++) 
                dp[i][j] = -1;   
    return un_kp(prices, length, n, n, dp);
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int* arr = new int[n];
	    for(int i=0; i<n; ++i) {
	        cin>> arr[i];
	    }
	    cout<< cutRod(arr, n, n);
	}
	return 0;
}