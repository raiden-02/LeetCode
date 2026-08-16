class Solution {
    public int maximalRectangle(char[][] matrix) {
        if(matrix.length == 0) return 0;
        int ans = 0, m = matrix.length, n = matrix[0].length;
        int[] dp = new int[n];
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
            ans = Math.max(ans, helper(dp));
        }
        
        return ans;
    }
    
    //84. largest rectangle in histogram
    private int helper(int[] heights) {
        Stack<Integer> st = new Stack<>();
        int ans = 0, n = heights.length;
        st.add(-1);
        
        for(int i = 0; i < n; i++) {
            while(st.peek() != -1 && heights[i] <= heights[st.peek()]) {
                int top = st.peek(); st.pop();
                ans = Math.max(ans, heights[top] * (i - st.peek() - 1));
            }
            
            st.add(i);
        }
        
        while(st.peek() != -1) {
            int top = st.peek(); st.pop();
            ans = Math.max(ans, heights[top] * (n - st.peek() - 1));
        }
        
        return ans;
    }
}
