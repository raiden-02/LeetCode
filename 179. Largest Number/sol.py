class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        nums = [str(x) for x in nums]
        
        def custom_comparator(a, b):
            if a + b > b + a:
                return -1  # a should come before b
            elif a + b < b + a:
                return 1   # a should come after b
            else:
                return 0   # a and b are equal

        nums.sort(key=cmp_to_key(custom_comparator))

        if nums[0] == "0":
            return "0"
            
        return "".join(nums)
