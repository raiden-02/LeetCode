class Solution {
    public List<Integer> targetIndices(int[] nums, int target) {
        int l = 0, n = nums.length, r = n - 1;
        Arrays.sort(nums);
        
        while(l < r) {
            int mid = (l + r) >> 1;
            
            //System.out.println(nums[mid] + " " + l + " " + r);
            if(nums[mid] < target)
                l = mid + 1;
            
            else
                r = mid;
        }
        
        List<Integer> ans = new ArrayList<>();
        for(int i = l; i < n && nums[i] == target; i++)
            ans.add(i);
        
        return ans;
    }
}

// --- alternate solution ---

class Solution {
    public List<Integer> targetIndices(int[] nums, int target) {
        int lessCount = 0, tarCount = 0;
        
        for(int x : nums) {
            if(x < target) lessCount++;
            else if(x == target) tarCount++;
        }
        
        List<Integer> ans = new ArrayList<>();
        
        for(int i = lessCount; i < lessCount + tarCount; i++)
            ans.add(i);
        
        return ans;
    }
}
