class Solution {
    void dfs(int[][] arr,int i,int j,int n,int m)
    {
        if(i < 0 || i >= n || j < 0 || j >=m || arr[i][j] != 1)
            return;
        arr[i][j] = 2;
        dfs(arr,i+1,j,n,m);
        dfs(arr,i,j+1,n,m);
        dfs(arr,i-1,j,n,m);
        dfs(arr,i,j-1,n,m);
    }
    int numberOfEnclaves(int[][] arr) {

        // Your code here
        int n = arr.length, m = arr[0].length;
        
        for(int i=0;i<m;i++)
        {
            if(arr[0][i] == 1)
                dfs(arr,0,i,n,m);
            if(arr[n-1][i] == 1)
                dfs(arr,n-1,i,n,m);
        }
        
        for(int i=0;i<n;i++)
        {
            if(arr[i][0] == 1)
                dfs(arr,i,0,n,m);
            if(arr[i][m-1] == 1)
                dfs(arr,i,m-1,n,m);
        }
        int count = 0;
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(arr[i][j] == 1)
                    count++;
            }
        }
        return count;
    }
}