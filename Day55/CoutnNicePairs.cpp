class Solution {
public:
    int revNum(int num)
    {
        string str = to_string(num);
        reverse(str.begin(),str.end());
        
        int ans = stoi(str);
        return ans;
    }
    int mod = 1e9 + 7;
    int countNicePairs(vector<int>& arr) {
        long long n = arr.size(),count = 0;
        unordered_map<long long,long long> mp;
        vector<long long> ans(n,0);
        for(int i=0;i<n;i++)
        {
            long long revI = revNum(arr[i]);
            ans[i] = (arr[i] - revI);
            if(mp.find(ans[i]) != mp.end())
                count+= (mp[ans[i]] % mod) % mod;
            mp[ans[i]]++;
        }
        

        return count % mod;
    }
};