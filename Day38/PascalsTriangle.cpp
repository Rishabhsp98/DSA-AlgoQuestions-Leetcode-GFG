class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> arr;
    
        arr.push_back({1});
        arr.push_back({1,1});
        
        for(int i=2;i<=rowIndex;i++)
        {
            vector<int> temp(i+1,1);
            arr.push_back(temp);
            for(int j=1;j<i;j++)
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
        }
        return arr[rowIndex];
    }
};