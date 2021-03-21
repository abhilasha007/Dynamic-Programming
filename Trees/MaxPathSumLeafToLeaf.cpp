/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

int solve(Node* root, int& res) {
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) return root->data;
    
    int l = solve(root->left, res);
    int r = solve(root->right, res);
    
    if(root->left && root->right) {
        int temp = root->data + max(l, r);
        res = max(res, root->data + l + r);
        return temp;
    }

    return root->left == NULL ? root->data + r : root->data + l;
}

int maxPathSum(Node* root)
{
    int res = INT_MIN;
    solve(root, res);
    return res;
}