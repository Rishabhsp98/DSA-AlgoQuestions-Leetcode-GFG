class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        if(n==1)
            return intervals;
        sort(intervals.begin(),intervals.end());
        int interval_lowest = intervals[0][0],interval_highest = intervals[0][1];
        for(int i=1;i<n;i++)
        {
            int a = intervals[i][0], b = intervals[i][1];
            
            if((interval_highest >=a && interval_highest <=b) || (interval_highest > b)) // falls under same previous interval
            {
                if(interval_highest <=b)
                    interval_highest = b;
                if(i==n-1)                          // If this is last then store curr interval
                    ans.push_back({interval_lowest,interval_highest});
                continue;
            }
            else{ // this is a diffrent interval
                ans.push_back({interval_lowest,interval_highest}); // storing last interval
                interval_lowest = a,interval_highest = b;
                if(i == n-1)      // if this is the last then we need to store this
                    ans.push_back({a,b});
            }
            
            
        }
        return ans;
    }
};