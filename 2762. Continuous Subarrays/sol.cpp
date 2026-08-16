class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        l = r = 0
        freq = {}
        ans = 0

        while(r < len(nums)):
            freq[nums[r]] = freq.get(nums[r], 0) + 1

            while(max(freq) - min(freq) > 2):
                freq[nums[l]] -= 1
                if(freq[nums[l]] == 0):
                    del freq[nums[l]]
                l += 1
            
            ans += r - l + 1
            r += 1
        
        return ans
