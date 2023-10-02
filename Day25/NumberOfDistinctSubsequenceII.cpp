class Solution {
public:
    int mod = 1e9 + 7;
    int solve(string &s,int idx,vector<int> &dp)
    {
        if(idx >=s.size())
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
        vector<bool> vis(26,false);
        
        int ans = 0;
        for(int i=idx;i<s.size();i++)
        {
            char ch = s[i];
            if(vis[ch-'a'])
                continue;
            vis[ch-'a'] = true;
            ans =(ans +solve(s,i+1,dp)% mod +1) % mod;
        }
        
        return dp[idx] = (ans % mod);
    }
    int distinctSubseqII(string s) {
        vector<int> dp(s.size(),-1);
        return solve(s,0,dp);
    }
};