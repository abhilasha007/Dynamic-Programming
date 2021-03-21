int solve(TreeNode* root, int& res) {
    //BASE
    if(root==NULL) return 0;

    //HYPOTHESIS : almost never change
    int l = solve(root->left, res);
    int r = solve(root->right, res);

    //INDUCTION : 3 things: temp, ans, res;  calculate temp, ans with l and r
    int temp = // calculate temp answer //when current root is not considered as root of final answer/path but just a passing node in path
    int ans = max(temp, /*relation*/); //when current node considers itself to be root of final answer/path
    res = max(res, ans);

    return temp;
}

int getSomething(TreeNode* root) {
    int res = INT_MIN;
    solve(root, res);
    return res; //may wanna do some alterations here
}