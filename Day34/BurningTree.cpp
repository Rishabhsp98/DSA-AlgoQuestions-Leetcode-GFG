class Solution {
  public:
  
    Node *targetNode = nullptr;
    void make_parents(Node *root,unordered_map<Node*,Node*> &mp)
    {
        queue<Node*> que;
        que.push(root);
        
        while(que.size() != 0)
        {
            int size = que.size();
            while(size--)
            {
                Node *rnode = que.front();
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
    
    void find(Node *root,int val)
    {
        if(root == nullptr)
            return;
        if(root->data == val)
            targetNode = root;
        
        find(root->left,val);
        find(root->right,val);
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        if(root == nullptr)
            return 0;
        unordered_map<Node*,Node*> mp;
        make_parents(root,mp);
        
        //find a targetNode
        find(root,target);
        
        queue<Node*> que;
        que.push(targetNode);
        int time = 0;
        unordered_map<Node*,bool> vis;
        
        
        while(que.size() != 0)
        {
            int size = que.size();
            
            while(size--)
            {
                Node *rnode = que.front();
                que.pop();
                
                vis[rnode] = true;
                
                if(rnode->left != nullptr && !vis[rnode->left])
                    que.push(rnode->left);
                    
                if(rnode->right != nullptr && !vis[rnode->right])
                    que.push(rnode->right);
                    
                if(mp.find(rnode) != mp.end() && !vis[mp[rnode]])
                    que.push(mp[rnode]);
            }
            time++;
        }
        
        return time-1;
        
    }
};