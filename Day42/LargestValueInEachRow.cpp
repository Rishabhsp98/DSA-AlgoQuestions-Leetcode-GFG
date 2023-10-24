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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr)
            return ans;
        queue<TreeNode*> que;
        que.push(root);
        int max_ele = INT_MIN;
        
        while(que.size() != 0)
        {
            int size = que.size();
            
            while(size--)
            {
                TreeNode *rnode = que.front();
                que.pop();
                
                if(rnode->left != nullptr)
                    que.push(rnode->left);
                if(rnode->right != nullptr)
                    que.push(rnode->right);
                max_ele = max(max_ele,rnode->val);
            }
            ans.push_back(max_ele);
            max_ele = INT_MIN;
        }
        
        return ans;
    }
};