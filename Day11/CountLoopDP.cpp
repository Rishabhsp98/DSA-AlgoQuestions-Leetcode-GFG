class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    int MOD = 1e9 + 7;
    long long solve(int n,vector<long long> &dp)
    {
        if(n < 0)
            return 0;
        if(n == 0 || n == 1)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        long long a = solve(n-1,dp) % MOD;
        long long b = solve(n-2,dp) % MOD;
        long long c = solve(n-3,dp) % MOD;
        return dp[n] = (a + b + c) % MOD;
    }
    long long countWays(int n)
    {
        
        // your code here
         vector<long long> dp(n+1,-1);
         return solve(n,dp);
    }
};