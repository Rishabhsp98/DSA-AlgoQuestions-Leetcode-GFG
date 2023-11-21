class Solution{
    public:
    // return true/false denoting whether the tree is Symmetric or not
    
    bool solve(Node *root1,Node *root2)
    {
        if(root1 == nullptr && root2 == nullptr)
            return true;
        if(root1 == nullptr || root2 == nullptr)
            return false;
        
        if(root1->data != root2->data)
            return false;
        
        return solve(root1->left,root2->right) && 
               solve(root1->right,root2->left);
    }
    bool isSymmetric(struct Node* root)
    {
	    // Code here
	    if(root == nullptr)
	        return true;
	     return solve(root->left,root->right);
    }
};
