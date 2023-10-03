class Solution{
    public:
    string colName (long long int columnNumber)
    {
        // your code here
         string ans="";
        
        while(columnNumber > 0)
        {
            columnNumber--;
            
            int rem = columnNumber % 26;
            columnNumber /=26;
            ans += 'A'+rem;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};