class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        // Your code here
        // It can be a one liner logic!! Think of it!!
        int mask = 1;
        for(int i=0;i<32;i++)
        {
            if((n & mask) > 0 && i== k)
                return true;
            mask <<=1;
        }
        return false;
    }
};

//another solution

class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        // Your code here
        // It can be a one liner logic!! Think of it!!
        n >>=k;
        return (n&1);
    }
};