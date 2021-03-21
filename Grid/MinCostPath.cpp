#include <iostream>
#include <vector>
#include <climits>
using namespace std;
//Dynamic Programming  
//T.C --> O(m*n)  S.C--> O(m*n)
int minCostPath_dp(int **input, int m, int n){
    int **output = new int*[m];
    for(int i=0; i<n; ++i){
        output[i] = new int[n];
    }
    //fill the last cell / destination 
    output[m-1][n-1] = input[m-1][n-1];
    //filling last row (R->L)
    for(int j= n-2; j>=0; --j){
        output[m-1][j] = input[m-1][j] + output[m-1][j+1];
    }
    //filling last column (B->T)
    for(int i = m-2; i>=0; --i){
        output[i][n-1] = input[i][n-1] + output[i+1][n-1];
    }
    //filling the remaining cells
    for(int i= m-2; i>=0; --i){
        for(int j= n-2; j>=0; --j){
            output[i][j] = min( output[i+1][j], min(output[i][j+1] , output[i+1][j+1])) + input[i][j];
        }
    }
    int ans = output[0][0];
    delete [] output;
    return  ans;
}
//---------------
//Memoization
//T.C --> O(m*n)  S.C--> call stack space
int minCostPath_mem(int **arr, int m, int n, int i, int j, int **output){
    //Base Case
    if(i== m-1 && j == n-1){
        return arr[i][j]; 
    }
    //edge case
    if(i>=m || j>=n){
        return INT_MAX;
    }
    //checking if it already exists
    if(output[i][j] != -1){
        return output[i][j];
    }
    //Recursive Call
    int x = minCostPath_mem(arr, m, n, i+1, j, output);
    int y = minCostPath_mem(arr, m, n, i, j+1, output);
    int z = minCostPath_mem(arr, m, n, i+1, j+1, output);
    //Small Calc
    int ans = arr[i][j] + min(x, min(y, z));
    //save for future use
    output[i][j] = ans;
    //return
    return ans;
}
int minCostPath_mem(int **arr, int m, int n){
    int **output =  new int*[m];
    for(int i=0; i<m; ++i){
        output[i] = new int[n];
        for (int j = 0; j < n; j++){
            output[i][j] = -1;
        }
    }
    return minCostPath_mem(arr, m, n, 0, 0, output);
}
//---------------
//Brute Force Approach //exponential T.C
int minCostHelper(int **arr, int m, int n, int i, int j){
    //Base Case
    if(i== m-1 && j == n-1){
        return arr[i][j]; 
    }
    //edge case
    if(i>=m || j>=n){
        return INT_MAX;
    }
    //Recursive Call
    int x = minCostHelper(arr, m, n, i+1, j);
    int y = minCostHelper(arr, m, n, i, j+1);
    int z = minCostHelper(arr, m, n, i+1, j+1);
    //Small Calc
    int ans = arr[i][j] + min(x, min(y, z));
    return ans;
}
int minCostPath(int **arr, int m, int n) {
    return minCostHelper(arr, m, n, 0, 0);
}
int main() {
    int **arr,n,m;
    cout<<"enter no. of rows: ";
    //n-> no. of rows. m-> no. of columns
    cin >> n ;
    cout<<"enter no. of columns: ";
    cin>>m;
    arr = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m) << endl;
    cout << minCostPath_mem(arr, n, m)<< endl;
    cout << minCostPath_dp(arr, n, m) << endl;
}