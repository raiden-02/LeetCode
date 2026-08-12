class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        left: int = 0
        n: int = len(nums)
        freq = defaultdict(int)
        ans: int = 0

        for right in range(n):
            freq[nums[right]] += 1

            while left < right and freq[nums[right]] > k:
                freq[nums[left]] -= 1

                if freq[nums[left]] == 0:
                    del freq[nums[left]]
                
                left += 1
            
            ans = max(ans, right - left + 1)
        
        return ans

