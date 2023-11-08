class Solution
{   
    public:
    //Function to return sum of upper and lower triangles of a matrix.
    vector<int> sumTriangles(const vector<vector<int> >& arr, int n)
    {
        // code here
        int totalsum = 0, m = n,uppersum = 0,diagsum = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                totalsum +=arr[i][j];
        }
        // just calculate any one triagle
        
        for(int gap = 0;gap <n ;gap++)
        {
            for(int i=0,j = gap;j < m && i < n;j++,i++)
            {
                if(gap == 0)
                    diagsum +=arr[i][j];
                uppersum +=arr[i][j];
            }
        }
        return {uppersum,totalsum + diagsum-uppersum};
    }
};
