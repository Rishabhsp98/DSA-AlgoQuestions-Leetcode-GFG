class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& arr) {
        int n = arr.size(),start = 0;
        int end = n-1;
        for(int i=0;i<n;i++)
        {
            if(arr[i] % 2 == 0)
                swap(arr[i],arr[start++]);
        }
        return arr;
    }
};


// 2nd Solution
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& arr) {
        int n = arr.size(),start = 0;
        int end = n-1;
        while(start <=end)
        {
            if((arr[start] % 2 == 1) && (arr[end] % 2 == 0))
                swap(arr[start++],arr[end--]);
            else if(arr[start] % 2 == 0)
                start++;
            else if(arr[end] % 2 == 1)
                end--;
        }
        return arr;
    }
};