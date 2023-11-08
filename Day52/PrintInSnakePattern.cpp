class Solution
{   
    public:
    //Function to return list of integers visited in snake pattern in matrix.
    vector<int> snakePattern(vector<vector<int> > matrix)
    {   
        // code here
        vector<int> ans;
        int idx = 0;
        for(vector<int> &arr: matrix)
        {
            if(idx % 2 != 0)
                reverse(arr.begin(),arr.end());
            ans.insert(ans.end(),arr.begin(),arr.end());
            idx++;
        }
        return ans;
    }
};