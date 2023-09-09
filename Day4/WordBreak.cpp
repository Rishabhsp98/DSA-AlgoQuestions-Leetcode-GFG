class Solution {
public:
    bool solve(string s,unordered_set<string> &st,int idx,vector<int> &dp)
    {
        if(idx == s.length())
            return dp[idx] = true;
        
        if(dp[idx] != -1)
            return dp[idx];
            
        string pattern = "";
        
        for(int i=idx;i<s.length();i++)
        {
            pattern +=s[i];
            
            if(st.find(pattern) != st.end())
            {
                if(solve(s,st,i+1,dp)) // find for the rest of the string 
                    return true;
            }
        }
        return dp[idx] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        vector<int>dp(301,-1);
        for(string x: wordDict)
            st.insert(x);
        // find from 0th index
        return solve(s,st,0,dp);
    }
};