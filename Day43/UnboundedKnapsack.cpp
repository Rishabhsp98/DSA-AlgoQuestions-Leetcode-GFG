class Solution{
public:
    int n;
    int solve(int val[],int wt[],int currWt,int idx,vector<vector<int>> &dp)
    {
        if(idx >= n)
            return 0;
        if(currWt <= 0)
            return 0;
        if(dp[idx][currWt] != -1) 
            return dp[idx][currWt];
        int take = 0,notTake = 0;
        if(currWt-wt[idx] >=0)
            take +=solve(val,wt,currWt-wt[idx],idx,dp) + val[idx];
        notTake +=solve(val,wt,currWt,idx+1,dp);
        
        return dp[idx][currWt] = max(take,notTake);
        
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        n = N;
        vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
        return solve(val,wt,W,0,dp);
    }
};