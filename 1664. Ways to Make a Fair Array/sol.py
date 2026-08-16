class Solution:
    """
    split the array into left and right
    calculate sum of right arr initally that from 1 to n, where right[0] holds even sum, right[1] holds odd sum
    then for every iter left keeps expanding and the right arr keeps shrinking
    add the respective elem to the left arr where it too holds even and odd sums in left[0] and left[1]
    the right part would be flipped always, but the left remains the same
    """
    def waysToMakeFair(self, nums: List[int]) -> int:
        ans = 0
        left, right = [0, 0], [sum(nums[0::2]), sum(nums[1::2])]
        
        for i, val in enumerate(nums):
            right[i % 2] -= val
            ans += left[0] + right[1] == left[1] + right[0] #even in left + even in right(flipped after removing index i,e instead of right[0] we use right[1], similarly for odd as well)
            left[i % 2] += val
        
        return ans
