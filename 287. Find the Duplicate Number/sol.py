class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        fast, slow = nums[0], nums[0]
        
        slow = nums[slow]
        fast = nums[nums[fast]]
        
        #finding intersection of two pointers
        while(fast != slow):
            slow = nums[slow]
            fast = nums[nums[fast]]
        
        #finding entrance to the cycle
        slow = nums[0]
        while(slow != fast):
            slow = nums[slow]
            fast = nums[fast]
        
        return slow
