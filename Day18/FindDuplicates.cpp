class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        if(mp.size() == n)
            return {-1};
        for(auto x: mp)
        {
            if(x.second > 1)
            {
                // while(x.second--)
                    ans.push_back(x.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};