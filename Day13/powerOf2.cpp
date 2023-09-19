class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        // Your code here   

        if(n==1)
            return true;
        if(n == 0 || n % 2 == 1)
            return false;
        return isPowerofTwo(n/2);
        
    }
};