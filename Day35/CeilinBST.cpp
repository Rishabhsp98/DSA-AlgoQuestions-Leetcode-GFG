int ans = -1;
    void inorder(Node*root,int&high,int input)
    {
        if(!root) return;
        
        inorder(root->left,high,input);
        if(root->data >=input && root->data<high)
        {
            high=root->data;
            ans=root->data;
        }
        
        inorder(root->right,high,input);
    }
int findCeil(Node* root, int input) {
    if(root == nullptr)
        return -1;
    int high = 1e9;
    inorder(root,high,input);
    return ans;

    // Your code here
}