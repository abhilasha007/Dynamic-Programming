#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    void findCombinations(vector<int> candidates, int n, int target, vector<int>& curr, vector<vector<int>>& ans)
    {
        if(target == 0)
        {
            ans.push_back(curr);
            return;
        }
        if(n == 0)
            return;
        if(candidates[n-1] <= target)
        {
            curr.push_back(candidates[n-1]);
            findCombinations(candidates, n, target - candidates[n-1], curr, ans);
            curr.pop_back();
            findCombinations(candidates, n-1, target, curr, ans);
        }
        
        else
        {
            findCombinations(candidates, n-1, target, curr, ans);
        }
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        
        vector<vector<int>> ans;
        vector<int> curr;
        int n = candidates.size();
        findCombinations(candidates, n, target, curr, ans);
        return ans;
        
    }
};


vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	sort( candidates.begin(), candidates.end() );

	//  Unbounded knapsack : Similar to coin change
	vector< vector< vector<int> > > dp(target + 1, vector<vector<int>>());
	dp[0].push_back(vector<int>());

	for( int i=1; i <= candidates.size(); i++ ) {
		for( int j=1; j<=target; j++ ) {
			if( candidates[i-1] <= j ) {
				auto combs = dp[ j - candidates[i-1] ];
				for( auto comb : combs ) {
					comb.push_back( candidates[i-1] );
					dp[j].push_back( comb );
				}
			}
		}
	}
	return dp[target];
}
class Solution {
    //Unbounded knap-sack
    List<List<Integer>>res = new ArrayList<>(); 
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        helper(candidates,target,0,new ArrayList<>());
        return res;
    }
    private void helper(int [] nums, int target, int i, List<Integer>curr){
        if(target==0){
            res.add(new ArrayList<>(curr));
            return;
        }
        if(i>=nums.length || target<0){
            return;
        }
        if(nums[i]<=target){
            curr.add(nums[i]);
            helper(nums,target-nums[i],i,curr); //when included
            
            curr.remove(new Integer(nums[i]));
            helper(nums,target,i+1,curr); //when not included
        }else{
            helper(nums,target,i+1,curr);
        }
    }
}