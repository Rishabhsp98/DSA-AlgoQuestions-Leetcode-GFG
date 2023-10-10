/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void mark_parents(TreeNode *root,unordered_map<TreeNode*,TreeNode*> &mp)
    {
        queue<TreeNode*> que;
        que.push(root);
        
        
        while(que.size() != 0)
        {
            int size = que.size();
            while(size--)
            {
                TreeNode *rnode = que.front();
                que.pop();
                
                if(rnode->left != nullptr)
                {
                    mp[rnode->left] = rnode;
                    que.push(rnode->left);
                }
                if(rnode->right != nullptr)
                {
                    mp[rnode->right] = rnode;
                    que.push(rnode->right);
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
          vector<int> ans;
          if(root == nullptr)
              return {};
          unordered_map<TreeNode*,TreeNode*> mp;
          mark_parents(root,mp);
        
          queue<TreeNode*> que;
          que.push(target);
          int currDist = 0;
          unordered_map<TreeNode*,bool> vis;
        
          while(que.size() != 0)
          {
              int size = que.size();
              while(size--)
              {
                  TreeNode *rnode = que.front();
                  que.pop();
                  
                  
                  vis[rnode] = true;
                  
                  if(rnode->left != nullptr && !vis[rnode->left])
                      que.push(rnode->left);
                  
                  if(rnode->right != nullptr && !vis[rnode->right])
                      que.push(rnode->right);
                  
                  if(mp.find(rnode) != mp.end() && !vis[mp[rnode]])
                      que.push(mp[rnode]);
                  
                  if(currDist == k)
                      ans.push_back(rnode->val);
              }
              currDist++;
          }
          return ans;
        
    }
};