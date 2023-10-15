class Solution {
public:
    long long mod = 1e9 + 7;
    long long solve(int currStep,int totalSteps,int stepsTaken,int arrlen,vector<vector<long long>> &dp)
    {
        if(stepsTaken == totalSteps)
            return currStep == 0 ? 1: 0;
        if(currStep < 0 || currStep >= arrlen || stepsTaken > totalSteps) // out of bounds
            return 0;
       
        if(dp[currStep][stepsTaken] != -1)
            return dp[currStep][stepsTaken];
        
        long long goLeft = 0,goRight = 0,stay = 0;
        goLeft = (solve(currStep-1,totalSteps,stepsTaken+1,arrlen,dp) % mod);
        goRight = (solve(currStep+1,totalSteps,stepsTaken+1,arrlen,dp) % mod);
        stay = (solve(currStep,totalSteps,stepsTaken+1,arrlen,dp) % mod);
        
        return dp[currStep][stepsTaken] = (goLeft + goRight + stay) % mod;
    }
    int numWays(int steps, int arrLen) {
        
        long long currStep = 0,stepsTaken = 0;
        vector<vector<long long>> dp(500,vector<long long>(steps+1,-1));
        return solve(currStep,steps,stepsTaken,arrLen,dp);
    }
};