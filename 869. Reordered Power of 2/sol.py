class Solution:
    def reorderedPowerOf2(self, N: int) -> bool:
        num = str(N)
        n = len(num)
        st = sorted(num)
        #print(st)
        i = 1
        while(1):
            #print(i)
            x = str(i)
            l = len(x)
            if(l == n and sorted(x) == st):
                return True
            elif(l > n):
                break
            i *= 2
        
        return False
