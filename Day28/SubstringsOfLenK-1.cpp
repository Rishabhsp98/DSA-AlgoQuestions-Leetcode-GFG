class Solution {
  public:
    int countOfSubstrings(string s, int k) {
        // code here
        unordered_map<int,int> mp;
        int n = s.length(),count =0,start = 0;
        
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
            
            while(mp.size() > (k-1) || (i-start+1) > k)
            {
                mp[s[start]]--;
                if(mp[s[start]] == 0)
                    mp.erase(s[start]);
                start++;
            }
            
            if((i-start+1) == k && mp.size() == k-1)
                count++;
        }
        return count;
    }
};