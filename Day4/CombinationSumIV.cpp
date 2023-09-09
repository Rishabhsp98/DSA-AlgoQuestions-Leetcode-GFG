class Solution {
public:
    int solve(vector<int> &arr,int target,int sum,vector<int> &dp)
    {
        if(sum > target)
            return 0;
        if(sum == target)
            return 1;
        if(dp[sum] != -1)
            return dp[sum];
        int ways = 0;
        for(int x: arr)
        {
            ways +=solve(arr,target,x + sum,dp);
        }
        
        return dp[sum] = ways;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(1001,-1);
        return solve(nums,target,0,dp);
    }
};