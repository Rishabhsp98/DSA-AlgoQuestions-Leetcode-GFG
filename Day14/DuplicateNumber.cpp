class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        unordered_map<int,int> mp;
        
        unordered_set<int> st;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
            if(mp[arr[i]] > 1)
                st.insert(arr[i]);
        }
        vector<int> ans(st.begin(),st.end());
        sort(ans.begin(),ans.end());
        if(mp.size() < n)
            return ans;
        return {-1};
    }
};