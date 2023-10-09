class Solution {
public:
    int bin_search(vector<int> &arr,int start,int end,int ele,char ch)
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
    vector<int> searchRange(vector<int>& arr, int target) {
        int n = arr.size();
        int first= bin_search(arr,0,n-1,target,'F');
        if(first == -1)
            return {-1,-1};
        
        int last= bin_search(arr,0,n-1,target,'L');
        return {first,last};
    }
};