#include<bits/stdc++.h>
using namespace std;

int findTargetSumWays(vector<int>& nums, int S)
{
    int cnt = 0,sum = 0;
    int n = nums.size();
    for(int i=0;i<nums.size();i++)
    {
        sum = sum+nums[i];
        if(nums[i]==0)
            cnt = cnt+1;
    }
    if(S > sum)
        return 0;
    if((S+sum)%2!=0)
        return 0;
    int s = (S+sum)/2;
    int dp[n+1][s+1];
    for(int i=0;i<n+1;i++)
        dp[i][0] = 1;
    for(int j=1;j<s+1;j++)
        dp[0][j] = 0;
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<s+1;j++)
        {
            if(nums[i-1]==0)
                dp[i][j] = dp[i-1][j];
            else if(j < nums[i-1])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
        }
    }
    
    return pow(2,cnt)*dp[n][s];
}