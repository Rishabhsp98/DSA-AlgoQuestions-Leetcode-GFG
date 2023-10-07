class Solution {
public:
    int n,m,k;
    // we need n number where there are K max_soFar element are placed(means max_soFar got changed K times) , n numbers are chosen from 1 to m(different)
    int mod = 1e9 + 7;
    
    int solve(int idx,int max_soFar,int maxPlaced,vector<vector<vector<int>>> &dp)
    {
        if(idx == n)
        {
            if(maxPlaced == 0) // no further number are left to place
                return 1;
            return 0;
        }
        if(maxPlaced < 0) // means more than K numbers(max_soFar) are placed which is not valid
            return 0;
        if(dp[idx][max_soFar][maxPlaced] != -1)
            return dp[idx][max_soFar][maxPlaced];
        int ans = 0;
        // here we place from 1 to max_soFar .. don't change the maxPlaced and max_soFar
        for(int num=1;num<=max_soFar;num++)
            ans = (ans + solve(idx+1,max_soFar,maxPlaced,dp)) % mod;
        
        //here we place from 1+max_sofar to m ( change the maxPlaced and max_sofar)
        for(int num=max_soFar+1;num<=m;num++)
            ans = (ans + solve(idx+1,num,maxPlaced-1,dp)) %mod;
        
        
        return dp[idx][max_soFar][maxPlaced] = ans;
        // return ans;
    }
    int numOfArrays(int N, int M, int K) {
        if(n > m)
            return 0;
        n = N,m =M,k=K;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        return solve(0,0,k,dp);
    }
};