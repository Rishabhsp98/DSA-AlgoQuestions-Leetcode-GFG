class Solution
{
    //Function to find unit area of the largest region of 1s.
    
    
    int dfs(int[][] arr,int i,int j,int n,int m)
    {
        if(i < 0 || i >= n || j < 0 || j >=m || arr[i][j] != 1)
            return 0;
       arr[i][j] = 2;
       return dfs(arr,i+1,j,n,m) + 
              dfs(arr,i,j+1,n,m) +
              dfs(arr,i-1,j,n,m) +
              dfs(arr,i,j-1,n,m) +
              dfs(arr,i+1,j+1,n,m) +
              dfs(arr,i-1,j+1,n,m) +
              dfs(arr,i-1,j-1,n,m) +
              dfs(arr,i+1,j-1,n,m) + 1;
        
    }
    public int findMaxArea(int[][] arr)
    {
        // Code here
        int n = arr.length, m = arr[0].length,max_area = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr[i][j] == 1)
                {
                    int area = dfs(arr,i,j,n,m);
                    max_area = Math.max(max_area,area);
                }
            }
        }
        return max_area;
    }
}