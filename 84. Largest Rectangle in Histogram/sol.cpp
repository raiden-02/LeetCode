class Solution {
public:
    //montonic stack strictly increasing
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans = 0, n = heights.size();
        st.push(-1);
        
        for(int i = 0; i < n; i++) {
            while(st.top() != -1 and heights[i] <= heights[st.top()]) {
                int top = st.top(); st.pop();
                ans = max(ans, heights[top] * (i - st.top() - 1));
            }
            
            st.push(i);
        }
        
        while(st.top() != -1) {
            int top = st.top(); st.pop();
            ans = max(ans, heights[top] * (n - st.top() - 1));
        }
        
        
        return ans;
    }
};
