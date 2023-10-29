class Solution
{
public:
    int setBits(int N) {
        // Write Your Code here
        int x = 1,count = 0;
        for(int i=0;i<32;i++)
        {
            if(x & N)
                count++;
            x <<=1;
        }
        return count;
    }
	int is_bleak(int n)
	{
	    // Code here.
	    for(int i=n-ceil(log2(n));i<n;i++)
	    {
	        int res = i + setBits(i);
	        if(res == n)
	            return 0;
	    }
	    return 1;
	}
};