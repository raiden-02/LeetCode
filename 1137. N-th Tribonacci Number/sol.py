class Solution:
    def tribonacci(self, n: int) -> int:
        if(n == 0):
            return 0
        
        if(n <= 2):
            return 1

        a, b, c = 0, 1, 1

        for i in range(3, n + 1):
            if(i % 3 == 0):
                a = a + b + c
            
            elif(i % 3 == 1):
                b = a + b + c
            
            else:
                c = a + b + c
        
        return max(a, b, c)
