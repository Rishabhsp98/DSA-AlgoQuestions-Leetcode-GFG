class Solution {
public:
    int solve(vector<int> &arr,int idx,int target,int currSum,vector<vector<int>> &dp)
    {
        if(idx >=arr.size())
            return dp[idx][currSum] = 1;
        
        if(dp[idx][currSum] != -1)
            return dp[idx][currSum];
        
        int take = 1,notTake = 1;
        if(currSum + arr[idx] <=target)
            take *=solve(arr,idx,target,currSum+arr[idx],dp) * arr[idx];
        notTake *= solve(arr,idx+1,target,currSum,dp);
        
        
        return dp[idx][currSum] = max(take,notTake);
        
    }
    int integerBreak(int n) {
        vector<int> arr;
        for(int i=1;i<n;i++)
            arr.push_back(i);
        vector<vector<int>> dp(n+1,vector<int>(1e4,-1));
        return solve(arr,0,n,0,dp);
    }
};