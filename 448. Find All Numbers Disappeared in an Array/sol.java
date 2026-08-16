class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        
        for(int x : nums) {
            int ind = Math.abs(x) - 1;
            
            if(nums[ind] > 0) nums[ind] = -nums[ind]; 
        }
        
        for(int i = 0; i < nums.length; i++)
            if(nums[i] > 0) ans.add(i + 1);
        
        return ans;
    }
}
