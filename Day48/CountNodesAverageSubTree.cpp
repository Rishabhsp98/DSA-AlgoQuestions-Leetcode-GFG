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
    
    int count = 0,sum = 0;
    int countnodes(TreeNode *node)
    {
        if(node == nullptr)
            return 0;
        sum +=node->val;
    
        return countnodes(node->left) + 
        countnodes(node->right)+ 1;
    }
    
    void solve(TreeNode *root)
    {
        if(root == nullptr)
            return;
    
        
        if(root->left == nullptr && root->right == nullptr)
            count++;
        else{
            sum = 0;
            int num = countnodes(root);
            // cout<<root->val <<"  "<<sum<<" "<<num<<endl;
            if((sum / num) == root->val)
                count++;
        }
        
        solve(root->left);
        solve(root->right);
    }
    
    
    int averageOfSubtree(TreeNode* root) {
        if(root == nullptr)
            return 0;
        solve(root);
        return count;
    }
};