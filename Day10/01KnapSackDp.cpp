class solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int n;
    int solve(int wt[],int val[],int idx,int W,vector<vector<int>> &dp)
    {
        if(idx>=n)
            return 0;
        if(dp[idx][W] != -1)
            return dp[idx][W];
        int pick = 0;
        if(W-wt[idx] >=0)
            pick = solve(wt,val,idx+1,W-wt[idx],dp) + val[idx];
        int notpick = solve(wt,val,idx+1,W,dp) + 0;
        
        return dp[idx][W] = max(pick,notpick);
    }
    int knapSack(int W, int wt[], int val[], int N) 
    { 
       // Your code here
       n=N;
       vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
       return solve(wt,val,0,W,dp);
    }
};