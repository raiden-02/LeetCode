class StockSpanner {
    stack<int> st;
    unordered_map<int, int> dp;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 1;
        while(not st.empty() and price >= st.top()) {
            ans += dp[st.top()];
            st.pop();
        }
        
        dp[price] = ans;
        st.push(price);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
