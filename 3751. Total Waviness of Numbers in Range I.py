class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        ans = 0

        for num in range(num1, num2 + 1):
            prev = -1

            while (num // 10) > 0:
                cur = num % 10
                nex = (num // 10) % 10
                num //= 10 

                if prev == -1:
                    prev = cur
                    continue

                if prev > cur < nex or prev < cur > nex:
                    ans += 1
                
                prev = cur

        return ans  
