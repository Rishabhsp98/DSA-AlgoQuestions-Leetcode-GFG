class Solution {
public:
    
    bool dfs(vector<vector<int>> &arr,int i,int j,int n,int m ,int lastval,int maxDiff,vector<vector<bool>> &vis)
    {
        if(i < 0 || i >= n || j < 0 || j>=m || vis[i][j] || abs(lastval-arr[i][j]) > maxDiff)
            return false;
        
        if(i==n-1 && j == m-1)
            return true;
        vis[i][j] = true;
        lastval = arr[i][j];
        return dfs(arr,i+1,j,n,m,lastval,maxDiff,vis) ||
        dfs(arr,i,j+1,n,m,lastval,maxDiff,vis) ||
        dfs(arr,i-1,j,n,m,lastval,maxDiff,vis) ||
        dfs(arr,i,j-1,n,m,lastval,maxDiff,vis);
            
    }
    int minimumEffortPath(vector<vector<int>>& arr) {
       
       int n = arr.size(),m = arr[0].size();
        
       /* applying binarySearch + dfs
       
       1. binary search of start to end and check for mid ,If it is the permissible differnece possible in 0,0 to n-1,m-1 
       2. if we can reach while maintaining "mid" then decrease it further to mid-1 and repeat step 1
       3. in this way we get the answer (min possible difference from 0,0 to n-1,m-1)
       */
       
       int start = 0,end = 1e6,res = -1;
       // dfs(arr,0,0,n,m,arr[0][0],4);
       
       while(start <=end)
       {
           int mid = start + (end-start)/2;
           
           vector<vector<bool>> vis(n,vector<bool>(m,false));
           if(dfs(arr,0,0,n,m,arr[0][0],mid,vis))
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