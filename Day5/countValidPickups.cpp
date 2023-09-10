class Solution {
public:
    int mod = 1e9 + 7;
    int countOrders(int n) {
        long long res = 1;
        long long places = 2 *n;
        
        // every iterations we decrease number of places to fill 
        // places decrease 2 in evry ite..
        for(int i=n;i>=1;i--)
        {
            res = (res * (places *(places-1))/ 2) % mod;
            places -=2;
        }
        return (int)res;
    }
};