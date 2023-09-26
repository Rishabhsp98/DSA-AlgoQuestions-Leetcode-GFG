class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        vector<bool> vis(26,false);
        vector<int> freq(26,false);
        
        for(char ch : s)
            freq[ch-'a']++;
        
        string ans = "";
        stack<char> st;
        
        for(int i=0;i<n;i++)
        {
            char ch = s[i];
            if(vis[ch-'a'])
            {
                freq[ch-'a']--;
                continue;   
            }
            while(st.size() != 0 && st.top() > ch && freq[st.top()-'a'] > 0)
            {
                vis[st.top()-'a'] = false;
                st.pop();
            }
            st.push(ch);
            freq[ch-'a']--;
            vis[ch-'a'] = true;
            
        }
        
        while(st.size() != 0)
        {
            ans +=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};