class Solution {
public:
    
    int solve(int idx1,int idx2,vector<int> &arr1,vector<int> &arr2,vector<vector<int>> &dp)
    {
        if(idx1 >=arr1.size() || idx2 >=arr2.size())
            return dp[idx1][idx2] = 0;
        
        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        
        int take = 0,notTake = 0;
        
        take +=solve(idx1+1,idx2+1,arr1,arr2,dp) +(arr1[idx1] * arr2[idx2]);
        notTake +=max(solve(idx1+1,idx2,arr1,arr2,dp),solve(idx1,idx2+1,arr1,arr2,dp));
        
        return dp[idx1][idx2] = max(take,notTake);
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        // special case here as [-1,-1] and [1,1] is resulting in  = 0 , which is not correct
        // so in case the answer is going to be negative , we need to minimize it
        
        int firstMax= -1e9,firstMin = 1e9,secondMax = -1e9,secondMin = 1e9;
        
        for(int x: nums1)
        {
            firstMax = max(firstMax,x);
            firstMin = min(firstMin,x);
        }
        for(int x: nums2)
        {
            secondMax = max(secondMax,x);
            secondMin = min(secondMin,x);
        }
        // here we are checking if it is going to be negative , If YES then return maximized min value
        
        // here first array is negative and other is positive
        if(firstMax < 0 && secondMin > 0) // firstMAx negative means sureShot negative ans
            return firstMax *secondMin;
        
        // here first array is positive and other is positve
        if(secondMax < 0 && firstMin > 0) // secondMax negative means sureShot negative ans
            return secondMax * firstMin;
        
        int n = nums1.size(),m = nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,nums1,nums2,dp);
    }
};