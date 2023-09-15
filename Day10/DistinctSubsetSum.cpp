class Solution {
public:
    unordered_set<int> st;
    int solve(vector<int> &arr,int idx,int sum,vector<vector<int>> &dp)
    {
        if(idx >=arr.size())
        {
            if(st.find(sum) != st.end())
                return 0;
            st.insert(sum);
            return 1;
        }
        if(dp[idx][sum] != -1)
            return dp[idx][sum];
        int pick = solve(arr,idx+1,sum+arr[idx],dp);
        int notpick = solve(arr,idx+1,sum,dp);
        
        return dp[idx][sum] = pick + notpick;
    }
	vector<int> DistinctSum(vector<int>nums){
	    // Code here
	   int n = nums.size();
	   vector<vector<int>> dp(n+1,vector<int>(1e5,-1));
	   solve(nums,0,0,dp);
	   vector<int> ans(st.begin(),st.end());
	   sort(ans.begin(),ans.end());
	   return ans;
	}
};