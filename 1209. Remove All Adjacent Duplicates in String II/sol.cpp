class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<int, char>> st;
        
        for(char x : s) {
            if(st.empty()) {
                st.push({1, x});
                continue;
            }
            
            if(st.top().second == x)
                st.top().first += 1;
            else
                st.push({1, x});
            
            if(st.top().first == k)
                st.pop();
        }
        
        string ans;
        
        while(!st.empty()) {
            ans = string(st.top().first, st.top().second) + ans;
            st.pop();
        }
        
        return ans;
    }
};
