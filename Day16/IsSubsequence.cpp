class Solution {
public:
    bool isSubsequence(string s, string t) {
        // brute force
        int n =s.length(),m = t.length(),lastidx = 0,j;
        if(n == m)
            return s==t;
        if(n > m)
            return false;
        for(int i=0;i<n;i++)
        {
            char ch = s[i];
            bool found = false;
            for(j=lastidx;j<m;j++)
            {
                if(ch == t[j])
                {
                    found = true;
                    break;
                }
            }
            if(!found)
                return false;
            else{
                lastidx = j+1;
            }
        }
        return true;
    }
};

// Alternate Solution
class Solution {
public:
    
    bool solve(string s,string t,int i,int j)
    {
        if(i == s.length())
            return true;
        if(j == t.length())
            return false;
        
        if(s[i] == t[j])
            return solve(s,t,i+1,j+1);
        else
            return solve(s,t,i,j+1);
        
    }
    bool isSubsequence(string s, string t) {
        int n = s.length(),m = t.length();
        
        return solve(s,t,0,0);
    }
};