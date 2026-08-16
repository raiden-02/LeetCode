class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        l = 0
        r = 0
        s = 0
        ans = 0
        prev = -1
        while(r < len(nums)):
            #print(r)
            cur = nums[r]
            if(cur > prev):
                s += cur
                ans = max(ans, s)
            else:
                l = r
                s = cur
            r += 1
            prev = cur
        return ans
