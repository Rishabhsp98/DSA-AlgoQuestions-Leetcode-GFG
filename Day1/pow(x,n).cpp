double myPow(double x, int n) {
        long m= n;
        if(m == 0)
            return 1;
        if(m< 0)
        {
            x= 1/x;
            m *= -1;
        }

        if(m %2 == 0)
            return myPow(x*x,m/2);
        else
            return x*myPow(x*x,m/2);

    }