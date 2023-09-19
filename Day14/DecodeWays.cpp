class Solution {
	public:
        int n,MOD = 1e9 + 7;
        int solve(string &s,int idx,vector<int> &dp)
        {
            if(idx>=n)
                return 1;
            if(dp[idx] != -1)
                return dp[idx];
            int take1 = 0,take2=0,total = 0;
            
            take1 = s[idx]-'0';
            
            if(idx < n-1)
            {
                take2 = take1 *10 + s[idx+1] -'0';
            }
            if(take1 > 0)
                total +=(solve(s,idx+1,dp) % MOD);
            if(take1 > 0 && take2 > 0 && take2 <=26)
                total +=(solve(s,idx+2,dp) % MOD);
            return dp[idx] = (total % MOD);
        }
		int CountWays(string str){
		    // Code here
		    n = str.length();
		    vector<int> dp(n+2,-1);
		    return solve(str,0,dp);
		}

};