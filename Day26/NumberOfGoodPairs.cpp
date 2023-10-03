class Solution {
public:
    int numIdenticalPairs(vector<int>& arr) {
        int count = 0,n = arr.size();
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[j] == arr[i])
                    count++;
            }
        }
        return count;
    }
};