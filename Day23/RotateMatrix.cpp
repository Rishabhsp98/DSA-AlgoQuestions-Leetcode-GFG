/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
void rotate(vector<vector<int> >& arr)
{
    // Your code goes here
    int n = arr.size(),m = arr[0].size(),idx = 0;
    
    for(vector<int> a: arr)
    {
        reverse(a.begin(),a.end());
    }
    
    for(vector<int> a : arr)
    {
        for(int i=idx;i<a.size()-1;i++)
        {
            swap(arr[idx][i+1],arr[i+1][idx]);
        }
        idx++;
    }
    reverse(arr.begin(),arr.end());
}