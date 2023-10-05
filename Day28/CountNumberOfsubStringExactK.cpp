class Solution
{
  public:
    long long int solve(string s,int k)
    {
        vector<int> mp(26,0);
    	long long int n = s.length(),start = 0,count = 0,unique = 0;
    	for(int i=0;i<n;i++)
    	{
    	    mp[s[i]-'a']++;
    	    
    	    if(mp[s[i]-'a'] == 1)
    	        unique++;
    	    
    	    while(unique > k)
    	    {
    	        mp[s[start]-'a']--;
    	        if(mp[s[start]-'a'] == 0)
    	            unique--;
    	        start++;
    	    }
    	    count +=(i-start+1);
    	}
    	return count;
    }
    long long int substrCount (string s, int k) {
    	//code here.
        int n = s.length();
        return solve(s,k) - solve(s,k-1);
    }
};