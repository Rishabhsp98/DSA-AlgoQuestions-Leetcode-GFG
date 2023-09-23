class Solution {
public:
    int solve(vector<int> &arr,int idx,int lastidx,vector<vector<int>> &dp)
    {
        if(idx >=arr.size())
            return 0;
        if(dp[idx][lastidx+1] != -1)
            return dp[idx][lastidx+1];
        int take = 0,notTake = 0;
        
        if(lastidx == -1 || arr[idx] > arr[lastidx])
            take +=solve(arr,idx+1,idx,dp) + 1;
        
        notTake += solve(arr,idx+1,lastidx,dp);
        
        return dp[idx][lastidx+1] = max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(nums,0,-1,dp);
    }
};