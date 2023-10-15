class Solution {
public:
    long long mod = 1e9 + 7;
    int solve(int startPos,int currPos,int endPos,int currSteps,int totalSteps,vector<vector<long long>> &dp)
    {
        if(currSteps > totalSteps)
            return 0;
       
        if(currSteps == totalSteps)
            return currPos == endPos ? 1 : 0;
        
        if(dp[currPos+1000][currSteps] != -1) // + 1000 to handle negative test cases
            return dp[currPos+1000][currSteps];
        
        long long goleft = 0,goRight = 0;
        goleft = (solve(startPos,currPos-1,endPos,currSteps+1,totalSteps,dp) % mod);
        goRight = (solve(startPos,currPos+1,endPos,currSteps+1,totalSteps,dp) % mod);
        
        return dp[currPos+1000][currSteps] = (goleft + goRight) % mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        int currPos = startPos,currSteps = 0;
        // unordered_set<string
        vector<vector<long long>> dp(3001,vector<long long>(k+1,-1));
        return solve(startPos,currPos,endPos,currSteps,k,dp);
    }
};