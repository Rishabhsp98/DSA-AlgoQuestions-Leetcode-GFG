class Solution {
public:
    
    bool dfs(vector<vector<int>> &arr,int i,int j,int n,int m,int maxTime,vector<vector<bool>> &vis)
    {
        if(i < 0 || i>=n || j < 0 || j>=m || vis[i][j] || arr[i][j] > maxTime)
            return false;
        if(i==n-1 && j==m-1)
            return true;
        vis[i][j] = true;
        return dfs(arr,i+1,j,n,m,maxTime,vis) ||
               dfs(arr,i,j+1,n,m,maxTime,vis) ||
               dfs(arr,i-1,j,n,m,maxTime,vis) ||
               dfs(arr,i,j-1,n,m,maxTime,vis);
    }
    int swimInWater(vector<vector<int>>& arr) {
        int n = arr.size(),m= arr[0].size();
        // similar question to path with minimum effort (Ques : 1631)
        
        int start = 0,end = 1e4,res = -1;
        
        while(start <=end)
        {
            vector<vector<bool>> vis(n,vector<bool>(m,false));
            int mid = start + (end-start)/2;
            if(dfs(arr,0,0,n,m,mid,vis))
            {
                res = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return res;
    }
};