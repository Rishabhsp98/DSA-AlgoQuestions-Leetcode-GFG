class Solution {
public:
    int dfs(vector<int> adj[],int src,vector<bool> &vis)
    {
        if(vis[src])
            return 0;
        vis[src] = true;
        
        int count = 0;
        for(int x: adj[src])
            if(!vis[x])
                count+=dfs(adj,x,vis)+1;
        
        return count;
    }
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> adj[n+1],indegree(n,0);
        
        for(vector<int> &arr: edges)
        {
            int a = arr[0], b = arr[1];
            adj[a].push_back(b);
            indegree[b]++;
        }
        int src = 0; bool foundchamp = false;
        for(int i=0;i<n;i++)
        {
            if(indegree[i] == 0 && foundchamp)
            {
                src = -1;
            }
            if(indegree[i] == 0 && !foundchamp)
            {
                src = i;
                foundchamp = true;
            }
           
        }
        
        return src;
    }
};