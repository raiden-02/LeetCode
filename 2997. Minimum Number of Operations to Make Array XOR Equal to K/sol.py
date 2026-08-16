class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        ans = 0

        for i in nums:
            ans ^= i

        def bit_difference(a, b):
            xor_result = a ^ b
            return bin(xor_result).count('1')


        return bit_difference(ans, k)
