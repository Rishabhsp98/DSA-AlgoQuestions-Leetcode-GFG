class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > arr, int n, int m) 
    {
        // code here
        vector<int> ans;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<=m-1;i++)  // ->
        {
            if(!vis[0][i])
                ans.push_back(arr[0][i]);
            vis[0][i] = true;
        }
        for(int i=1;i<=n-1;i++)   // down
        {
            if(!vis[i][m-1])
                ans.push_back(arr[i][m-1]);
            vis[i][m-1] = true;
        }
        for(int i=m-2;i>=0;i--)   // left
        {
            if(!vis[n-1][i])
                ans.push_back(arr[n-1][i]);
            vis[n-1][i] = true;
        }
        for(int i=n-2;i>=1;i--)  // up
        {
            if(!vis[i][0])
                ans.push_back(arr[i][0]);
            vis[i][0] = true;
        }
        return ans;
    }
};