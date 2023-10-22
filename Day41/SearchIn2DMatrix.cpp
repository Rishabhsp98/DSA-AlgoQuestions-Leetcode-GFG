class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    bool bin_search(int start,int end,vector<int> &arr,int x)
    {
        while(start<= end)
        {
            int mid = start + (end-start)/2;
            
            if(arr[mid] == x)
                return true;
            else if(arr[mid] > x)
                end = mid-1;
            else 
                start = mid+1;
        }
        return false;
    }
    bool search(vector<vector<int> > matrix, int N, int m, int x) 
    {
        // code here 
        for(vector<int> arr : matrix)
        {
            int n = arr.size();
            if(bin_search(0,n-1,arr,x))
                return true;
        }
        return false;
    }
};