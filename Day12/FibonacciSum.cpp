class Solution{
public:
    long long int mod = 1e9 + 7;
    long long int fibSum(long long int n){
        //code here
        if(n <=2)
            return 1;
        long long int a = 1,b = 1,c=0,ans = 2;
        while(n-- > 2)
        {
            c = (a+b) % mod;
            a = (b) % mod;
            b = (c) % mod;
            ans = (ans+c) %mod;
        }
        return ans % mod;
    }
};