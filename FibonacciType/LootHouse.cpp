/**
 * A thief wants to loot houses. He knows the amount of money in each house. 
 * He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Sample Input 1 :
6
5 5 10 100 10 5
Sample Output 1 :
110

Sample Input 2 :
6
10 2 30 20 3 50
Sample Output 2 :
90
*/
using namespace std;
//dynamic programming
int rob(vector<int>& nums) {
    int n = nums.size();
    if(n==0) return 0;
    if(n==1) return nums[0];
    if(n==2) return max(nums[0], nums[1]);
        
    int dp[n];
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    
    for(int i=2; i<n; ++i){
        dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
    }
    return dp[n-1];
}
    
//Memoization
int getMaxMoney_mem(int arr[], int n, int i, int *dp){
    if(i>=n){
        return 0;
    }
    //check if it's already here
    if(dp[i] != -1) {
        return dp[i];
    }
    //recursive call
    int a = arr[i] + getMaxMoney_mem(arr, n, i+2, dp);
    int b = getMaxMoney_mem(arr, n, i+1, dp);
    //save for future use
    dp[i] = max(a , b);
    
    return dp[i];
}
int getMaxMoney_mem(int arr[], int n){
    int *dp = new int[n];
    for(int i=0; i<n; ++i){
        dp[i] = -1;
    }
    return getMaxMoney_mem(arr, n, 0, dp);
}
//-------------
//Brute Force
int getMaxMoney(int arr[], int n, int i) {
    //base
    if(i>=n){
        return 0;
    }
    //recursive call
    int a = arr[i] + getMaxMoney(arr, n, i+2);
    int b = getMaxMoney(arr, n, i+1);
    return max(a , b);
}
int getMaxMoney(int arr[], int n) {
    //return getMaxMoney(arr, n, 0);
    return getMaxMoney_mem(arr, n);
    //return getMaxMoney_dp(arr, n);    
}
