class Solution {
public:
    
    void dfs(unordered_map<int,vector<int>> &mp,int src,unordered_set<int> &st,vector<int> &ans)
    {
        if(st.find(src)!= st.end())
            return;
        st.insert(src);
        ans.push_back(src);
        
        for(int x: mp[src])
            dfs(mp,x,st,ans);
    
    }
    vector<int> restoreArray(vector<vector<int>>& arr) {
        
        vector<int> ans;
        int n = arr.size();
        // vector<int> adj[n+1];
        unordered_map<int,vector<int>> mp;
        
        for(vector<int> &ar: arr)
        {
            int a = ar[0], b = ar[1];
            mp[a].push_back(b);
            mp[b].push_back(a);
               
        }
        // finding the src node
        int src = 0;
        for(auto x: mp)
        {
            if(x.second.size() == 1)
            {
                src = x.first;
                break;
            }
        }
        unordered_set<int> st;
        dfs(mp,src,st,ans);
        
        return ans;
            
    }
};