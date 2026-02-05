public class Solution {
    public bool IsTrionic(int[] nums) {
        bool a = false, b = false, c = false;

        for (int i = 1; i < nums.Length; i++) {
            if (!a) {
                if (nums[i] <= nums[i - 1]) return false;
                a = true;
            }

            else if (!b) {
                if (nums[i] < nums[i - 1]) {
                    b = true;
                }

                else if (nums[i] == nums[i - 1])
                    return false;
            }

            else if (!c) {
                if (nums[i] > nums[i - 1]) {
                    c = true;
                }

                else if (nums[i] == nums[i - 1])
                    return false;
            }

            else if (c) {
                if (nums[i] <= nums[i - 1]) return false;
            }
        }

        return a && b && c;
    }
}
