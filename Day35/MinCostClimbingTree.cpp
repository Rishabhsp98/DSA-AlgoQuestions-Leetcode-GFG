class Solution {
public:
    
    int solve(vector<int> &arr,int idx,vector<int> &dp)
    {
        if(idx >=arr.size())
            return 0;
        if(dp[idx] != -1)
            return dp[idx];
        
        int go1step = 0,go2step = 0;
        go1step = solve(arr,idx+1,dp) +arr[idx];
        go2step = solve(arr,idx+2,dp) + arr[idx];
        
        return dp[idx] = min(go1step,go2step);
    }
    int minCostClimbingStairs(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> dp(n+2,-1);
        return min(solve(arr,0,dp),solve(arr,1,dp));
    }
};