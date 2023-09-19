class Solution {
    struct comp{
        bool operator()(const pair<int,int> &a,const pair<int,int> &b){
            if(a.second == b.second)
                return a.first < b.first;
            return a.second < b.second;
        }
    };
public:
    vector<int> kWeakestRows(vector<vector<int>>& arr, int k) {
        int n = arr.size(),m=arr[0].size(),idx = 0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;
        vector<int> ans;
        
        for(vector<int> a: arr)
        {
            int count = 0;
            for(int x: a)
            {
                if(x==1)
                    count++;
            }
            pq.push({idx,count});
            if(pq.size() > k)
                pq.pop();
            idx++;
        }
        while(pq.size() != 0)
        {
            pair<int,int> pr = pq.top();
            ans.push_back(pr.first);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};