class Solution {
    public List<String> buildArray(int[] target, int n) {
        List<String> ans = new ArrayList<>();
        int size = target.length;
        for(int i=0,ele = 1;ele <=n && i<size;ele++)
        {
            if(target[i] == ele)
            {
                ans.add("Push");
                i++;
            }else{
                ans.add("Push");
                ans.add("Pop");
            }
        }
        return ans;
    }
}