class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n = arr.size(),start = 0;
        // int end = n-1;
        for(int i=0;i<n;i++)
        {
            if(arr[i] != 0)
                swap(arr[i],arr[start++]);
        }
        
    }
};