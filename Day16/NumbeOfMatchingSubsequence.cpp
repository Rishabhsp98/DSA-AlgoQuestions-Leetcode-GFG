class Solution {
public:
    bool solve(string s1, string s2, int m, int n){
		
        int j = 0;
        for(int i = 0; i < m && j < n; i++){
			
            if(s1[i] == s2[j]) j++;
        }
        return j == n;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.length(),count = 0;
        unordered_map<string,int> mp;
        for(string x: words)
        {
            int m = x.length();
            if(mp.find(x) != mp.end())
            {
                count += mp[x];
            }
            else
            {

                mp[x] = solve(s,x,n,m);
                count += mp[x];
            }
        }
        return count;
    }
};