class Solution{
public:
    int n;
    int totalsum = 0;
    bool check(int arr[],int idx,int currSum,vector<vector<int>> &dp)
    {
        if(idx>=n)
            return false;
        if(currSum * 2 == totalsum)
            return true;
        if(dp[idx][currSum] != -1)
            return dp[idx][currSum];
        int pick = check(arr,idx+1,currSum-arr[idx],dp);
        int notpick = check(arr,idx+1,currSum,dp);
        
        return dp[idx][currSum] = pick || notpick;
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int total = 0; n =N;
        for(int i=0;i<n;i++)
            total +=arr[i];
        totalsum = total;
        vector<vector<int>> dp(n+1,vector<int>(total+1,-1));
        return check(arr,0,total,dp);
    }
};