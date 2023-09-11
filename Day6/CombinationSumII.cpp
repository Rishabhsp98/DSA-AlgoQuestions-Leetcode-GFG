class Solution{
public:
 void fill_Combinations(vector<int> &arr,int target,int idx,vector<int> &comb,vector<vector<int>> &combs)
    {
      if(target == 0 || target < 0)
      {
          if(target == 0)
              combs.push_back(comb);
          return;
      }
          
      for(int i=idx;i<arr.size();i++)
      {
         if(i > idx && arr[i]==arr[i-1])
             continue;
         comb.push_back(arr[i]);
         fill_Combinations(arr,target-arr[i],i+1,comb,combs);
         comb.pop_back();
      }
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        // without repeat elements
        vector<vector<int>> combs;
        vector<int> comb;
        sort(arr.begin(),arr.end());
        fill_Combinations(arr,k,0,comb,combs);
        return combs;
    }
};