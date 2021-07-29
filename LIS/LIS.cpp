/** LONGEST INCREASING SUBSEQUENCE
Given an integer array nums, return the length of the longest strictly increasing subsequence.
A subsequence is a sequence that can be derived from an array by deleting 
some or no elements without changing the order of the remaining elements.
For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
**/

//--------------------------------- DP with binary search ----------------------------------------//
// O(NlognN) time; O(N) space in worst case
/**
Traversing through each element in input nums, 
if it nums[i] > last element of dp[], simply push it back at last
else by binary search find the index of immediate next greater element of nums[i] in dp[]
and then replace it with nums[i] in dp[]
finally size of dp[] will be length of LIS
**/

int lengthOfLIS(vector<int>& nums) {
    vector<int> seq;
    seq.push_back(nums[0]);
    
    for(int i=1; i<nums.size(); ++i) {
        if(seq.back() < nums[i]) 
            seq.push_back(nums[i]);
        else {
            //binary search to find index of immediate increasing element of nums[i]
            int index = lower_bound(seq.begin(), seq.end(), nums[i]) - seq.begin();
            seq[index] = nums[i];
        }
    }
    return seq.size();
}

//--------------------------------- simple DP of brute ------------------------------------------//
// O(n^2) time; O(n) space
// for every ith element in input we check all previous elements in input if they can form 
// increasing subsequence with current ith element
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if(n==0) return 0;
    int dp[n];
    dp[0] = 1;
    for(int i=1; i<n; ++i) {
        dp[i] = 1;
        for(int j=i-1; j>=0; --j) {
            if(nums[j] >= nums[i]) continue;
            int possibleAns = 1 + dp[j];
            dp[i] = max(dp[i], possibleAns);
        }
    }
    int llis = 0;
    for(int i=0; i<n; ++i) llis = max(llis, dp[i]);
    return llis;
}

//------------------------------------- BRUTE FORCE ----------------------------------------------//
// time O(2^n) , TLE
int lengthLIS(vector<int> arr, int prevMax, int currInx) {
    if(currInx >= arr.lenght()) return 0;

    int incl = 0;
    if(arr[currInx] > prevMax) {
        incl = 1 + lengthOfLIS(arr, arr[currInx], currInx+1);
    }

    int excl = lengthLIS(arr, prevMax, currInx+1);

    return max(incl, excl);
}

int lengthOfLis(vector<int> arr) {
    return lengthLIS(arr, INT_MIN, 0);
}