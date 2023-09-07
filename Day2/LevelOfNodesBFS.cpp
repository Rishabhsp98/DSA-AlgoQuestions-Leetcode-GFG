
class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    vector<bool> vis(V+1,false);
	    queue<int> que;
	    que.push(0);
	    int level = 0;
	    if(X==0)
	        return 0;
	    
	    while(que.size() != 0)
	    {
	        int size = que.size();
	        level++;
	        while(size--)
	        {
	            int rnode = que.front();
	            que.pop();
	            
	            for(int x: adj[rnode])
	            {
	                if(!vis[x])
	                    que.push(x);
	                else
	                    continue;
	                vis[x] = true;
	                if(x == X)
	                    return level;
	            }
	        }
	    }
	    return -1;
	}
};