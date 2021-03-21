// O(n) TIME
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
    int solve(TreeNode* root, int &res) {
        //Base
        if(root==NULL) return 0;

        // Hypothesis
        int lh = solve(root->left, res);
        int rh = solve(root->right, res);

        //Induction
        int temp = 1 + max(lh, rh);  // when the root is not including itself as turning root of diameter
        int ans = max(temp, lh+rh+1); // when root is considering itself to be turning part of diameter
        res = max(res, ans);
        return temp;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int res = INT_MIN; //this will have no. of nodes in longest path after calling solve
        int t = solve(root, res);
        return res-1; // longest path length aka diameter
    }
};
