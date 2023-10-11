class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    int max_diff = 0;
    int solve(Node *root)
    {
        if(root == nullptr)
            return 0;
        int left = solve(root->left)+1;
        int right = solve(root->right)+1;
        // max_diff = abs(left-right);
        if(abs(left-right) > 1)
            max_diff = 2;
        return max(left,right);
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here
        if(root == nullptr)
            return true;
        solve(root);
        
        return max_diff < 2;
    }
};