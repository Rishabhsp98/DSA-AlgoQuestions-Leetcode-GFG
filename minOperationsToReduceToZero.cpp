class Solution {
public:
    int minOperations(vector<int>& arr, int x) {
        int currsum = 0,start= 0,n = arr.size(),maxlength = 0,sum = accumulate(arr.begin(),arr.end(),0);
        int targetsum = sum-x;
        if(sum < x)
            return -1;
        if(sum == x)
            return n;
        for(int i=0;i<n;i++)
        {
            currsum +=arr[i];
            while(currsum > targetsum)
            {
                currsum -=arr[start];
                start++;
            }
            if(currsum == targetsum)
                maxlength = max(maxlength,i-start+1);
        }
        return (maxlength == 0) ? -1 : n-maxlength;
    }
};