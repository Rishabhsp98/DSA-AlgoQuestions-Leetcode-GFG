class Solution {
public:
    int dfs(vector<vector<int>> &arr,int i,int j,int n,int m,int color)
    {
        if(i < 0 || i>=n || j< 0 || j>=m || arr[i][j] == color || arr[i][j] == 0)
            return 0;
        
        arr[i][j] = color;
        
        int top = dfs(arr,i+1,j,n,m,color);
        int down = dfs(arr,i-1,j,n,m,color);
        int left = dfs(arr,i,j-1,n,m,color);
        int right = dfs(arr,i,j+1,n,m,color);
        
        return top + down + left + right + 1;
    }
    int largestIsland(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        unordered_map<int,int> mp;
        int maxArea = 0,color = 2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr[i][j] != 0)
                {
                    int currArea = dfs(arr,i,j,n,m,color);
                    mp[color] = currArea;
                    maxArea = max(maxArea,currArea);
                    color++;
                }
            }
        }
        // If there are no Zeroes , then by this step we have already calculated maxArea
        vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr[i][j] != 0)
                    continue;
                
                int area = 1;
                unordered_set<int> seen;
                for(int k=0;k<4;k++) // for this zero checking is around islands areas we have stored by their color indexing
                {
                    int r = i + dirs[k][0];
                    int c = j + dirs[k][1];
                    
                    if(r < 0 || r >=n || c < 0 || c>=m || arr[r][c] == 0)
                        continue;
                    seen.insert(arr[r][c]);// so that our zero don't include same color area twice
                }
                for(int colorIdx : seen)
                    area +=mp[colorIdx];
                  // flipping this zero we have just seen 
                maxArea = max(maxArea,area);
            }
        }
        return maxArea;
    }
};