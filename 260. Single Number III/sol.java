class Solution {
    public int[] singleNumber(int[] nums) {
        Map<Integer, Integer> mp = new HashMap<Integer, Integer>();
        int ans[] = new int[2];
        int ind = 0;
        
        for(int x : nums)
            mp.put(x, mp.getOrDefault(x, 0) + 1);
        
        for(Map.Entry<Integer, Integer> item : mp.entrySet()) {
            if(item.getValue() == 1) {
                ans[ind] = item.getKey();
                ind += 1;
            }
        }
        
        return ans;        
    }
}
