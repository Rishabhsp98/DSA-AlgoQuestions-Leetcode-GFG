class Solution{

public:
    int ans = -1;
    void inorder(Node *root,int x)
    {
        if(root == nullptr)
            return;
        
        inorder(root->left,x);
        if(root->data <=x)
            ans = max(ans,root->data);
        inorder(root->right,x);
    }
    int floor(Node* root, int x) {
        // Code here
        if(root == nullptr)
            return -1;
            
        inorder(root,x);
        return ans;
    }
};