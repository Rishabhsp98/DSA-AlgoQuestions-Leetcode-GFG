class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& arr) {
        vector<vector<int>> ans;
        
        // how to get to know which group to insert 
        unordered_map<int,vector<int>> mp;
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            mp[arr[i]].push_back(i);
        }
        
        for(auto x: mp)
        {
            int requiredSize = x.first;
            vector<int> temp = x.second;
            int actualSize = temp.size();
            if(requiredSize == actualSize)
            {
                ans.push_back(temp);
            }
            else{
                int times = actualSize / requiredSize;
                    
                int size = times;
                while(size-- > 0)
                {
                  vector<int> res;
                  for(int i=0;i<requiredSize;i++)
                  {
                    res.push_back(temp.back());
                    temp.pop_back();
                  }
                  ans.push_back(res);
                }
            }
        }
        return ans;
    }
};