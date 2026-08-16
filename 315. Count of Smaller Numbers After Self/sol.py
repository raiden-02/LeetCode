from sortedcontainers import SortedList

class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        container = SortedList()
        nums.reverse()
        ans = []
        
        for i in nums:
            ind = container.bisect_right(-i)
            ans.append(len(container) - ind)
            container.add(-i)
        
        ans.reverse()
        return ans
