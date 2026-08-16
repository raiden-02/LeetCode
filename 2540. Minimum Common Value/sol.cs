public class Solution {
    public int GetCommon(int[] nums1, int[] nums2) {
        int i = 0, j = 0;

        while (i < nums1.Length && j < nums2.Length) {
            if (nums1[i] == nums2[j]) return nums1[i];

            if (nums1[i] > nums2[j]) {
                j++;
            }

            else {
                i++;
            }
        }

        return -1;
    }
}
