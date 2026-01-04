public class Solution {
    public int SumFourDivisors(int[] nums) {
        Dictionary<int, (int Sum, int Count)> divSumMap = new Dictionary<int, (int Sum, int Count)>();
        int totalSum = 0;

        foreach (int num in nums) {
            if (divSumMap.ContainsKey(num)) {
                (int s, int c) = divSumMap[num];
                if (c == 4) totalSum += s;
                continue;
            }

            int count = 0;
            int currentSum = 0;

            for (int i = 1; i * i <= num; i++) {
                if (num % i == 0) {
                    if (i * i == num) {
                        count += 1;
                        currentSum += i;
                    } else { // count both divisors as the other would be > sqrt(num) so won't be included in the loop
                        count += 2;
                        currentSum += i + (num / i);
                    }
                }
                if (count > 4) break; 
            }

            if (count == 4) {
                totalSum += currentSum;
            }

            divSumMap[num] = (currentSum, count);
        }

        return totalSum;
    }
}
