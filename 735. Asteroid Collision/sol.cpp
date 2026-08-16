class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i = 0; i < asteroids.size(); i++) {
            bool f = true;
            
            while(!st.empty() && st.top() > 0 && asteroids[i] < 0) {
                if(abs(asteroids[i]) > abs(st.top()))
                    st.pop();
                else {
                    if(abs(asteroids[i]) == abs(st.top()))
                        st.pop();
                    f = false;
                    break;
                }
            }
            
            if(f)
                st.push(asteroids[i]);
        }
        
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
