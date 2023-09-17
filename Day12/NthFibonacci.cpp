class Solution {
  public:
    int mod = 1e9 + 7;
    int nthFibonacci(int n){
        // code here
        if(n <=2)
            return 1;
        long long a = 1,b = 1,c=0;
        while(n-- > 2)
        {
            c = (a+b) % mod;
            a = (b) % mod;
            b = (c) % mod;
        }
        return c % mod;
    }
};