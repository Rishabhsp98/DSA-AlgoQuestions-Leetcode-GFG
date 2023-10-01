class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            string temp = "";
            while(i < n && s[i] != ' ')
            {
                temp +=s[i];
                i++;
            }
            reverse(temp.begin(),temp.end());
            ans +=temp +" ";
        }
        
        return ans.substr(0,ans.size()-1);
    }
};