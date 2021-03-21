/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root, int& res) {
        //Base
        if(root==NULL) return 0;
        
        //Hypothesis
        int leftSum = solve(root->left, res);
        int rightSum = solve(root->right, res);
        
        //Induction
        int temp = max(root->val + max(leftSum, rightSum), root->val);
        int ans = max(temp , (root -> val + leftSum + rightSum));
        res = max(res, ans);
        return temp;
    }
    
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        solve(root, res);
        return res;
    }
};