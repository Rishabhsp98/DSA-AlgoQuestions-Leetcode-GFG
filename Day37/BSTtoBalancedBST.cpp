class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
    vector<int> ans;
    void inorder(Node *root,unordered_map<int,int> &mp)
    {
        if(root == nullptr)
            return;
        inorder(root->left,mp);
        mp[root->data]++;
        inorder(root->right,mp);
    }
    
    void solve(Node *root2,unordered_map<int,int> &mp)
    {
        if(root2 == nullptr)
            return;
        solve(root2->left, mp);
        if(mp.find(root2->data) != mp.end())
            ans.push_back(root2->data);
        solve(root2->right,mp);
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
     //Your code here
        unordered_map<int,int> mp;
        inorder(root1,mp);
        
        solve(root2,mp);
        return ans;
    }
};