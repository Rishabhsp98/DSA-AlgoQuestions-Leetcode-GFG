class Solution{
  public:
    int palindromeSubStrs(string s) {
        // code here
        int n = s.length(),len = 0,maxlen =0;
        string ans = "";
        unordered_set<string> st;
        
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        
        for(int gap = 0;gap<n;gap++)
        {
            for(int i=0,j = gap;i<n && j < n; i++,j++)
            {
                if(gap == 0)
                    dp[i][j] = true;
                else if(gap == 1)
                    dp[i][j] = s[i] == s[j];
                else if(s[i] == s[j] && dp[i+1][j-1] == true)
                    dp[i][j] = true;
                if(dp[i][j] == true)
                {
                   len = gap+1;
                   ans = s.substr(i,len);
                   st.insert(ans);
                }
            }
        }
        return st.size();
    }
};