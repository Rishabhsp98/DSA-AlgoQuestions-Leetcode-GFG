class Solution {
public:
    vector<int> findArray(vector<int>& arr) {
        // x ^ a = b , we do x ^ a ^ a = b ^ a , x = b ^ a
        
        int n = arr.size();
        vector<int> ans(n,0);
        ans[0] = arr[0];
        for(int i=1;i<n;i++)
        {
            ans[i] = arr[i] ^ arr[i-1];
        }
        
        return ans;
    }
};