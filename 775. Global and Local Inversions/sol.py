class Solution:
    def isIdealPermutation(self, A: List[int]) -> bool:
        return True if all(abs(A[i] - i) <= 1 for i in range(len(A))) else False
