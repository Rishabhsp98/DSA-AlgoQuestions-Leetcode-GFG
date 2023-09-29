class Solution {
  public:
  
    int sr,sc;
    void dfs(vector<vector<int>> &arr,int i,int j,int n,int m,vector<pair<int,int>> &vec)
    {
        if(i < 0 || i >= n || j < 0 || j>=m || arr[i][j] != 1)
            return;
        arr[i][j] = 2;
        
        if(vec.size() > 0)
            vec.push_back({i-sr,j-sc});
        else
            vec.push_back({i-i,j-j});
            
        dfs(arr,i+1,j,n,m,vec);
        dfs(arr,i,j+1,n,m,vec);
        dfs(arr,i-1,j,n,m,vec);
        dfs(arr,i,j-1,n,m,vec);
    }
    int countDistinctIslands(vector<vector<int>>& arr) {
        // code here
        int n = arr.size(), m = arr[0].size();
        set<vector<pair<int,int>>> st;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr[i][j] == 1)
                {
                    vector<pair<int,int>> vec;
                    sr = i,sc = j;
                    dfs(arr,i,j,n,m,vec);
                    // for(auto x: vec)
                    //     cout<<x.first<<","<<x.second<<"   ";
                    // cout<<"New vector now"<<endl;
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};
