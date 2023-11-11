class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    
    string solve(string s)
    {
        unordered_map<char,char> mp;
        
        char num = '1';
        int n = s.length();
        string res = "";
        
        for(int i=0;i<n;i++)
        {
            char ch = s[i];
            // only when new character comes we change the num
            if(mp.find(ch) == mp.end())
            {
                mp[ch] = num;
                num++;
            }
            res +=mp[ch];
        }
        
        return res;
    }
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        if(str1 == str2)
            return true;
        string s1 = solve(str1);
        string s2 = solve(str2);
        
        return s1 == s2;
        
        
    }
};