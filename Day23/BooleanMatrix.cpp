class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    
    void dfsRowDown(vector<vector<int>> &arr,int i,int j,int n,int m)
    {
        if(i >=n )
            return;
            
        if(arr[i][j] != 1)
            arr[i][j] = 2;
        // dfsRow(arr,i-1,j,n,m);
        dfsRowDown(arr,i+1,j,n,m);
    }
     void dfsRowUp(vector<vector<int>> &arr,int i,int j,int n,int m)
    {
        if(i < 0)
            return;
            
        if(arr[i][j] != 1)
            arr[i][j] = 2;
        dfsRowUp(arr,i-1,j,n,m);
    }
    
    void dfsColRight(vector<vector<int>> &arr,int i,int j,int n,int m)
    {
        if(j >=m)
            return;
        if(arr[i][j] != 1)
            arr[i][j] = 2;
        // dfsCol(arr,i,j-1,n,m);
        dfsColRight(arr,i,j+1,n,m);
    }
    void dfsColLeft(vector<vector<int>> &arr,int i,int j,int n,int m)
    {
        if(j < 0)
            return;
        if(arr[i][j] != 1)
            arr[i][j] = 2;
        // dfsCol(arr,i,j-1,n,m);
        dfsColLeft(arr,i,j-1,n,m);
    }
    void booleanMatrix(vector<vector<int> > &arr)
    {
        // code here 
        int n = arr.size(), m = arr[0].size();
        vector<bool> visRow(n,false);
        vector<bool> visCol(m,false);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr[i][j] == 1)
                {
                    // arr[i][j] = 2;
                    if(!visRow[i])
                    {
                        dfsColLeft(arr,i,j,n,m); // i fix here
                        dfsColRight(arr,i,j,n,m); // i fix here
                    }
                    if(!visCol[j])
                    {
                        dfsRowDown(arr,i,j,n,m);
                        dfsRowUp(arr,i,j,n,m); // j fix here
                    }
                        
                    visRow[i] = visCol[j] = true;
                }
            }
        }
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr[i][j] == 2)
                {
                    arr[i][j] = 1;
                }
            }
        }
    }
};