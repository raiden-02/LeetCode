class Solution:
    def smallestCommonElement(self, mat: List[List[int]]) -> int:
        freq = defaultdict(int)
        for i in mat:
            for j in i:
                freq[j] += 1
        
        for key,val in freq.items():
            if(val == len(mat)):
                return key
        
        return -1
