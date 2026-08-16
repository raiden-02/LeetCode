class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> st;
        int ans = 0;
        
        for(char x : S) {
            if(x == '(')
                st.push(ans), ans = 0;
            
            else
                ans = st.top() + (ans == 0 ? 1 : ans * 2), st.pop();
        }
        
        return ans;
    }
};
