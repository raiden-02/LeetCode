class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        if(len(original) != m * n): 
            return []
            
        ind = 0
        ret = [[0] * n for _ in range(m)]

        for i in range(m):
            for j in range(n):
                ret[i][j] = original[ind]
                ind += 1
        
        return ret
