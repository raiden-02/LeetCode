class Solution:
    def longestSubsequence(self, nums: List[int]) -> int:
        non_zero: bool = nums[0] != 0
        xor: int = nums[0]
        n: int = len(nums)

        for i in range(1, n):
            xor ^= nums[i]
            non_zero = non_zero or (nums[i] != 0)
        
        if not non_zero:
            return 0
        
        if xor != 0:
            return n
        
        return n - 1
