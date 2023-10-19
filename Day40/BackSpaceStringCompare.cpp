class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.length(), m = t.length(),count = 0;
        string s1 = "",s2 ="";
        for(int i=n-1;i>=0;i--)
        {
            if(s[i] == '#')
                count++;
            else {
                if(count > 0)
                    count--;
                else
                    s1 +=s[i];
            }
        }
        count = 0;
        for(int i=m-1;i>=0;i--)
        {
            if(t[i] == '#')
                count++;
            else {
                if(count > 0)
                    count--;
                else
                    s2 +=t[i];
            }
        }
        reverse(s1.begin(),s1.end()); reverse(s2.begin(),s2.end());
        
        return s1==s2;
    }
};