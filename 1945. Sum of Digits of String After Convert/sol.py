class Solution:
    def getLucky(self, s: str, k: int) -> int:
        num = 0

        for x in s:
            tmp = (ord(x) - ord('a') + 1)

            while tmp:
                num = num * 10 + (tmp % 10)
                tmp //= 10

        print(num)

        while k > 0:
            tmp = num
            num = 0

            while tmp:
                num += tmp % 10
                tmp //= 10
            
            k -= 1
        
        return num
