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
    int max_freq = 0;
    void dfs(TreeNode *root,unordered_map<int,int> &mp){
        if(root == nullptr)
            return;
        mp[root->val]++;
        max_freq = max(max_freq,mp[root->val]);
        dfs(root->left,mp);
        dfs(root->right,mp);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr)
            return ans;
        unordered_map<int,int> mp;
        dfs(root,mp);
        for(auto x: mp)
        {
            if(x.second == max_freq)
                ans.push_back(x.first);
        }
        return ans;
    }
};