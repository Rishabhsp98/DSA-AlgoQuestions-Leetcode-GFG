class Solution {
public:
    int minDeletions(string s) {
        set<int> st; // set of frequency we havenot seen
        unordered_map<char,int> mp;
        for(char ch: s)
            mp[ch]++;
        
        int ans = 0;
        for(auto x: mp)
        {
            int val = x.second;
            
            while(val > 0 && st.find(val) != st.end())
            {
                val--;
                ans++;
            }
            
            if(val > 0)
                st.insert(val);
        }
        return ans;
        
    }
};