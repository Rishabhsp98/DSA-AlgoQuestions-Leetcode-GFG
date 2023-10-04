class Solution {
    // Finds decimal value of a given roman numeral
    public int romanToDecimal(String s) {
        // code here
        
        Map<Character,Integer> mp = new HashMap<Character,Integer>();
        mp.put('I',1);
        mp.put('V',5);
        mp.put('X',10);
        mp.put('L',50);
        mp.put('C',100);
        mp.put('D',500);
        mp.put('M',1000);
        
        int n = s.length();
        
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(i < n-1 && mp.get(s.charAt(i)) < mp.get(s.charAt(i+1)))
                ans -=mp.get(s.charAt(i));
            else
                ans +=mp.get(s.charAt(i));
        }
        return ans;
    }
}