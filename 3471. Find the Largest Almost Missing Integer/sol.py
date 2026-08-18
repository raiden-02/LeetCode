class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        n: int = len(nums)
        integers = set(nums)
        freq = defaultdict(int)
        ans: int = -1

        for i in range(n - k + 1):
            subarr = nums[i:i+k]

            for integer in integers:
                if integer in subarr:
                    freq[integer] += 1
        

        for k,v in freq.items():
            if v == 1:
                ans = max(ans, k)
        
        return ans
