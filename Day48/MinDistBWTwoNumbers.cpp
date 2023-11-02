class Solution{
  public:
    
    int minDist(int a[], int n, int x, int y) {
        // code here
        int idx = -1, p = -1,ans = 1e6;
        for(int i=0;i<n;i++)
        {
            if(a[i] == x)
            {
                idx = i;
                if(p != -1)
                {
                    ans = min(ans,abs(idx-p));
                }
            }
            if(a[i] == y)
            {
                p = i;
                if(idx != -1)
                {
                    ans = min(ans,abs(idx-p));
                }
                
            }
        }
        if(idx == -1 || p == -1)
            return -1;
        return ans;
    }
};