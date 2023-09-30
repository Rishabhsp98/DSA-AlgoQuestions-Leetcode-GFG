class Solution {
public:
    bool find132pattern(vector<int>& arr) {
        // we maintain 13 pattern out of "132" in the stack of pair at evry index
        int n = arr.size();
        stack<pair<int,int>> st;
        
        int min_so_far = 1e9;
        
        for(int i=0;i<n;i++)
        {
            min_so_far = min(min_so_far,arr[i]); // "1" of the "132" pattern
            
            while(st.size() != 0 && st.top().first < arr[i]) // we maintain highest element on stack top
            {
                st.pop();
            }
            
            if(st.size() != 0)
            {
                if(st.top().first > arr[i] && st.top().second < arr[i]) // 3 unique elements encountred 
                    return true;
            }
            st.push({arr[i],min_so_far}); // till current Index (Highest Ele and Lowest)
        }
        
        return false;
        
    }
};