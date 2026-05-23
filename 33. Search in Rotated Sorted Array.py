class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        l, r = 0, n - 1

        while (l < r):
            mid = (l + r) >> 1
            print(mid)

            if (nums[mid] > nums[r]):
                l = mid + 1
            
            else:
                r = mid
        
        pivot = l
        l, r = 0, n - 1

        if (target == nums[pivot]): return pivot

        if (nums[pivot] <= target <= nums[r]):
            l = pivot
        else:
            r = pivot - 1
        
        index = bisect.bisect_left(nums, target, lo=l, hi=r + 1)
    
        if index < r + 1 and nums[index] == target:
            return index

        return -1
        
