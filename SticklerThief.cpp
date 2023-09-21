class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int n;
    int solve(int arr[],int idx,vector<int> &dp)
    {
        if(idx >=n)
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
        int pick = 0,notpick = 0;
        
        pick += solve(arr,idx+2,dp) + arr[idx];
        notpick +=solve(arr,idx+1,dp);
        
        return dp[idx] = max(pick,notpick);
    }
    int FindMaxSum(int arr[], int N)
    {
        // Your code here
        n = N;
        vector<int> dp(n+2,-1);
        return solve(arr,0,dp);
        
    }
};