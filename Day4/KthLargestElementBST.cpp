class Solution
{
    public:
    int ans = -1,ele = 0,k,count = 0;
    void inorder(Node *root)
    {
        if(root == nullptr)
            return;
        inorder(root->left);
        ele++;
        if(ele == k)
            ans = root->data;
        inorder(root->right);
    }
    void solve(Node *root)
    {
        if(root == nullptr)
            return;
        solve(root->left);
        count++;
        solve(root->right);
    }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        if(root == nullptr)
            return 0;
        solve(root);
        // cout<<count<<" ";
        k = count-K + 1;
        inorder(root);
        return ans;
    }
};