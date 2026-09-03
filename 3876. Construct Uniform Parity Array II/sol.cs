public class Solution {
    public (int? MinEven, int? MinOdd) FindMinimums(int[] nums) {
        int? minEven = null;
        int? minOdd = null;

        foreach (int number in nums) {
            if (number % 2 == 0) {
                minEven = Math.Min(minEven ?? number, number);
            }
            else {
                minOdd = Math.Min(minOdd ?? number, number);
            }
        }

        return (minEven, minOdd);
    }

    public bool UniformArray(int[] nums1) {
        var res = FindMinimums(nums1);
        return res.MinEven == null || res.MinOdd == null || res.MinOdd < res.MinEven;
    }
}
