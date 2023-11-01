class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int n, int P)
    { 
        // code here
        unordered_map<int,int> mp;
        for(int x: arr)
            mp[x]++;
        for(int i=0;i<n;i++)
        {
            arr[i] = mp[i+1];
        }
    }
};