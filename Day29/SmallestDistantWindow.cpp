class Solution{
    public:
    int findSubString(string s)
    {
        // Your code goes here   
        unordered_map<char,int> mp1, mp2;
        vector<int> arr(26,0);
        int count = 0,n = s.length(),minlen = 1e8,start = 0;
        for(char ch: s)
            mp2[ch]++;
        
        for(int i=0;i<n;i++)
        {
            mp1[s[i]]++;
            
            while(mp1.size() > mp2.size())
            {
                mp1[s[start]]--;
                if(mp1[s[start]] == 0)
                    mp1.erase(s[start]);
                start++;
            }
            while(mp1.size() == mp2.size())
            {
                minlen = min(minlen,i-start+1);
                mp1[s[start]]--;
                if(mp1[s[start]] == 0)
                    mp1.erase(s[start]);
                start++;
            }
                
        }
        return minlen;
        
    }
};