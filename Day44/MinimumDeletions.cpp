class Solution{
  public:
  
    int solve(string &s1,string &s2,int i,int j,vector<vector<int>> &dp){
        if(i ==s1.length() || j == s2.length())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s1[i] == s2[j])
            return dp[i][j] = solve(s1,s2,i+1,j+1,dp)+1;
        else
            return dp[i][j] = max(solve(s1,s2,i+1,j,dp),solve(s1,s2,i,j+1,dp));
    }
    int minimumNumberOfDeletions(string S) { 
        // code here
        
        // same question as LCS of S and reverse of S
        string s1 = S;
        reverse(s1.begin(),s1.end());
        int n = S.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int ans = solve(S,s1,0,0,dp);
        
        return n-ans;
    } 
};