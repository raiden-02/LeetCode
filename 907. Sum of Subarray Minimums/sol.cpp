class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        const int MOD = 1e9 + 7;
        int ans = 0;
        
        for(int i = 0; i <= arr.size(); i++) {
            while(not st.empty() and (i == arr.size() or arr[st.top()] > arr[i])) {
                int mid = st.top(), right = i;
                st.pop();
                int left = st.empty() ? -1 : st.top();
                
                long cnt = (mid - left) * (right - mid);
                ans = (ans + (arr[mid] * cnt % MOD)) % MOD; 
            }
            
            st.push(i);
        }
        
        return ans;
    }
};
