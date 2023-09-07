class Solution {
  public:
    int mod = 1e5;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int n = arr.size();
        queue<int> que;
        if(start == end)
            return 0;
        
        que.push(start);
        int steps = 0;
        vector<bool> vis(mod,false);
        vis[start] = true;
        while(que.size() != 0)
        {
            int size = que.size();
            steps++;
            while(size--)
            {
                int rnode = que.front();
                que.pop();
                if(rnode == end)
                    return steps;
                
                for(int i=0;i<n;i++)
                {
                    int res = (rnode * arr[i]) % mod;
                    if(vis[res])
                        continue;
                    
                    if(res ==end)
                        return steps;
                    vis[res] = true;
                    que.push(res);
                }
            }
        }
        return -1;
    }
};