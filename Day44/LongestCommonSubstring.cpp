class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int max_len = 0; string ans = "";
        for(int gap = 0;gap<n;gap++)
        {
            for(int j=gap,i=0;j<n && i<n;j++,i++)
            {
                if(gap == 0)
                    dp[i][j]= true;
                else if(gap == 1)
                {
                    if(s[i] == s[j])
                        dp[i][j] = true;
                }
                else if(s[i] == s[j])
                {
                    if(dp[i+1][j-1] == true)
                        dp[i][j] = true;
                }
                
                if(dp[i][j] == true)
                {
                    int len = gap+1;
                    if(len > max_len){
                        max_len = len;
                        ans = s.substr(i,gap+1);
                    }
                }
            }
        }
        
        return ans;
    }
};