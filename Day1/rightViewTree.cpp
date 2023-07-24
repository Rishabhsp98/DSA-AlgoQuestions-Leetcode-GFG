vector<int> rightView(Node *root)
    {
       // Your Code here
       queue<Node*>que;
       vector<int> ans;
     
       
       if(root == nullptr)
        return ans;
        
        
       que.push(root);
        
       while(que.size() != 0)
       {
           int size = que.size();
           vector<int> temp;
           while(size--)
           {
               Node *rnode = que.front();
               que.pop();
               
               if(rnode->left != nullptr)
                que.push(rnode->left);
               if(rnode->right != nullptr)
                que.push(rnode->right);
               temp.push_back(rnode->data);
           }
           ans.push_back(temp.back());
       }
       return ans;
    }