class Solution {
public:
    bool isMonotonic(vector<int>& arr) {
        int n = arr.size(),i;
        if(n == 1)
            return true;
        
        
        // bool inc  = true , dec = true;
        for(int i=1;i<n;i++)
        {
            if(arr[i] ==arr[i-1])
                continue;
            else if(i < n && arr[i] > arr[i-1])
            {
                while(i < n && arr[i] >=arr[i-1])
                    i++;
                if(i <n && arr[i] < arr[i-1])
                    return false;
            }
            else if(i < n && arr[i] < arr[i-1])
            {
                while(i < n && arr[i] <=arr[i-1])
                    i++;
                if(i < n && arr[i] > arr[i-1])
                    return false;
            }
        }
        
        return true;
    }
};