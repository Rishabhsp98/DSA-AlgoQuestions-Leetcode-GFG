class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        vector<int> ans;
        deque<int> dq; /// stroring indexes in deque 
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            
            while(dq.size() > 0 && dq.front()==i-k ) // no longer conssidering the out of bounds
                dq.pop_front();
            
            while(dq.size() > 0 && arr[dq.back()] < arr[i]) // maintain descresing order
                dq.pop_back();
            
            dq.push_back(i);
            
            if(i >=k-1) // because at i==2 size of window is 2 , which is K , then after every window we consider
                ans.push_back(arr[dq.front()]);
        }
        return ans;
    }
};