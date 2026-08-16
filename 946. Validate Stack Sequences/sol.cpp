class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0;
        
        for(int i = 0; i < pushed.size(); i++) {
            st.push(pushed[i]);
            
            while(j < popped.size() and not st.empty() and st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }
        
        return st.empty();
    }
};
