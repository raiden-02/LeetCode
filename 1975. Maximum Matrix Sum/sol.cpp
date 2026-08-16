public class Solution {
    public long MaxMatrixSum(int[][] matrix) {
        long sum = 0; 
        
        // Track the smallest *absolute* value across the entire matrix
        int minAbs = int.MaxValue; 
        int negCount = 0;

        foreach (int[] x in matrix) {
            foreach (int y in x) {
                // Track absolute sum and count negatives
                sum += Math.Abs(y);
                
                if (y < 0) {
                    negCount++;
                }

                // We need the number closest to 0 (positive OR negative)
                minAbs = Math.Min(minAbs, Math.Abs(y));
            }
        }

        // If odd negatives, subtract 2 * minAbs (once to remove it from sum, once to make it negative)
        if (negCount % 2 != 0) {
            sum -= 2 * minAbs;
        }

        return sum;
    }
}
