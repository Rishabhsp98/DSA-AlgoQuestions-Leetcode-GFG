class Solution {
public:
    int n;
    int solve(vector<int> &arr,int start,int end,vector<vector<int>> &dp)
    {
        if(start > end)
            return 0;
        if(dp[start][end] != -1)
            return dp[start][end];
        return dp[start][end] = max(arr[start]-solve(arr,start+1,end,dp),arr[end]-solve(arr,start,end-1,dp));
    }
    bool stoneGame(vector<int>& piles) {
         n = piles.size();
         vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
         // solve going to give number of stones of alice - number of stones of bob 
         return solve(piles,0,n-1,dp) > 0;
    }
};