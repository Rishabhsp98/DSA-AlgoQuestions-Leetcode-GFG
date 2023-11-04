class Solution {
public:
    int getLastMoment(int N, vector<int>& left, vector<int>& right) {
        int n = left.size(), m = right.size();
        for(int i=0;i<m;i++)
            right[i] = N-right[i];
        sort(left.begin(),left.end());
        sort(right.begin(),right.end());
        
        
        if(n == 0 || m == 0)
            return n == 0 ? right.back() : left.back();
        
        return max(left.back(),right.back());
    }
};