class Solution {
public:
    
    int solve(vector<int> &arr,int idx,vector<int> &time,int wallremaining,vector<vector<int>> &dp)
    {
        if(wallremaining <= 0) // at this point paid painter has covered his paiting and free painter has also completed
            return 0;
        if(idx >=arr.size())
            return 1e9;
        if(dp[idx][wallremaining] != -1)
            return dp[idx][wallremaining];
        int paintbyPaid = 0,notPaintbyPaid = 0;
        paintbyPaid = solve(arr,idx+1,time,wallremaining-time[idx]-1,dp) + arr[idx];
        notPaintbyPaid = solve(arr,idx+1,time,wallremaining,dp);
        
        return dp[idx][wallremaining] = min(paintbyPaid,notPaintbyPaid);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(cost,0,time,time.size(),dp);
    }
};