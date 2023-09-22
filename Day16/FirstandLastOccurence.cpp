class Solution
{
    public:
    int bin_search(int arr[],int start,int end,int ele,char ch)
    {
        int res = -1;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(arr[mid] == ele)
            {
                res = mid;
                if(ch == 'F')
                    end = mid-1;
                else if(ch == 'L')
                    start = mid+1;
            }
            else if(arr[mid] < ele)
            {
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return res;
    }
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        
        int first= bin_search(arr,0,n-1,x,'F');
        if(first == -1)
            return {-1,-1};
        
        int last= bin_search(arr,0,n-1,x,'L');
        return {first,last};
    }
};