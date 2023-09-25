class Solution {
    
public:
    bool compare(string &s1,string &s2)
    {
        int n = s1.length(),m = s2.length(),i = 0,j =0;
        
        if(n != m+1)
            return false;
        
        while(i< n)
        {
            if(s1[i] == s2[j])
            {
                i++; j++;
            }
            else{
                i++; // insertion takes place
            }
        }
        return i == n && j ==m;
    }
    int solve(vector<string> &arr,int idx,int prev_idx,vector<vector<int>> &dp)
    {
        if(idx >=arr.size())
            return dp[idx][prev_idx+1] = 0;
        
        if(dp[idx][prev_idx+1] != -1)
            return dp[idx][prev_idx+1];
        int take = 0,notTake =0;
        
        if(prev_idx == -1 || compare(arr[idx],arr[prev_idx]))
            take +=solve(arr,idx+1,idx,dp)+1;
        notTake +=solve(arr,idx+1,prev_idx,dp);
        
        return dp[idx][prev_idx+1] = max(take,notTake);
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string &s1,string &s2){
            return s1.size() < s2.size();
        });
        int n = words.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(words,0,-1,dp);
    }
};