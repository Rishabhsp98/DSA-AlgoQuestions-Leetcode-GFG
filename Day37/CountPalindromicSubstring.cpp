int CountPS(char s[], int N)
{
    //code here
        int n = N,count = 0;
        string ans = "";
        
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
                if(dp[i][j] == true && gap >=1)
                   count++;
            }
        }
        return count;
    
}