class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        // Your code here
        int mask = 1;
        for(int i=0;i<32;i++)
        {
            if((n & mask) > 0)
                return i+1;
            mask <<=1;
        }
        return 0;
    }
};