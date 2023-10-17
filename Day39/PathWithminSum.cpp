class Solution{
public:
    
    int dfs(vector<vector<int>> &arr,int i,int j,int n,int m,vector<vector<int>> &dp)
    {
        if(i < 0 || j < 0 || j >=m || i >=n)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = arr[i][j] + max(dfs(arr,i+1,j,n,m,dp),
                               max(dfs(arr,i+1,j-1,n,m,dp),
                               dfs(arr,i+1,j+1,n,m,dp)));
    }
    int maximumPath(int N, vector<vector<int>> arr)
    {
        // code here
        int n = N,m = N,max_sum = 0;
        vector<vector<int>> dp;
        for(int i=0;i<m;i++)
        {
            // first row 
            dp.resize(n,vector<int>(n,-1));
            int sum = dfs(arr,0,i,n,m,dp);
            max_sum = max(max_sum,sum);
        }
        return max_sum;
    }
};