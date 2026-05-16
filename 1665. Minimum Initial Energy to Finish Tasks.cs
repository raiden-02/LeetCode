public class Solution {
    public int MinimumEffort(int[][] tasks) {
        // Sort DESCENDING by flex money i.e, money that does not get spent, biggest flex money executes first
        tasks.Sort((x, y) => (y[1] - y[0]) - (x[1] - x[0]));
        
        int spent = 0;
        int ans = 0;
        foreach (var task in tasks) {
            // To start this task, I need: (what I've already spent) + (this task's min)
            ans = Math.Max(ans, spent + task[1]);
            spent += task[0];
        }
        return ans;
    }
}
