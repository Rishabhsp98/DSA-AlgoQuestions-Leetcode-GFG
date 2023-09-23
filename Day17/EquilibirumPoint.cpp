class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        long long total = 0,currSum = a[0];
        for(int i=0;i<n;i++)
         total +=a[i];
        if(currSum == total)
            return 1;
         
        for(int i=1;i<n;i++)
        {
            currSum +=a[i];
            if(currSum-a[i] == total-currSum)
                return i+1;
        }
        return -1;
    }

};