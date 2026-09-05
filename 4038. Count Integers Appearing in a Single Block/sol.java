class Solution {
    public int countSpecialIntegers(int[] nums) {
        HashMap<Integer, Integer> vis = new HashMap<>();
        HashSet<Integer> ans = new HashSet<>();
        vis.put(nums[0], 1);
        ans.add(nums[0]);

        for (int i = 1; i < nums.length; i++) {
            if (vis.containsKey(nums[i])) {
                if (nums[i] == nums[i - 1]) {
                    continue;
                }

                else {
                    ans.remove(nums[i]);
                }
            }

            else {
                if (nums[i] == nums[i - 1]) {
                    continue;
                }

                else {
                    vis.put(nums[i], 1);
                    ans.add(nums[i]);
                }
            } 
        }

        return ans.size();
    }
}
