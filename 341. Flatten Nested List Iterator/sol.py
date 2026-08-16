#python
# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def isInteger(self) -> bool:
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        """
#
#    def getInteger(self) -> int:
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        """
#
#    def getList(self) -> [NestedInteger]:
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        """

class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        self.ans = []
        self.helper(nestedList)
        self.n = len(self.ans)
        self.i = -1
        
    def helper(self, l):
        for i in l:
            if i.isInteger():
                self.ans.append(i.getInteger())
            else:
                self.helper(i.getList())
                
    
    def next(self) -> int:
        self.i += 1
        return self.ans[self.i]
    
    def hasNext(self) -> bool:
         return self.i + 1 < self.n

# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())
