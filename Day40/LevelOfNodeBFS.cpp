class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    int level = 0;
	    queue<int> que;
	    que.push(0);
	    vector<bool> vis(V,false);
	    while(que.size() != 0)
	    {
	        int size= que.size();
	        level++;
	        while(size--)
	        {
	            int rnode = que.front();
	            que.pop();
	            vis[rnode] = true;
	            for(int x: adj[rnode])
	            {
	                if(X == x)
	                    return level;
	                if(!vis[x])
	                    que.push(x);
	            }
	        }
	        
	    }
	    return -1;
	}
};