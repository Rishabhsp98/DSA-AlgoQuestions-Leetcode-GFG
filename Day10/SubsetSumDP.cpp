class Solution{   
public:

    bool solve(vector<int> &arr,int idx,int sum,vector<vector<int>> &dp)
    {
        if(sum < 0)
            return false;
        if(idx == arr.size())
        {
            return sum == 0;
        }
        if(dp[idx][sum] != -1)
            return dp[idx][sum];
        bool pick = solve(arr,idx+1,sum-arr[idx],dp);
        bool notpick = solve(arr,idx+1,sum,dp);
        
        return dp[idx][sum] = pick || notpick;
        
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return solve(arr,0,sum,dp);
    }
};
