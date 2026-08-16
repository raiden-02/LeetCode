class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> mp = {{')', '('}, {'}', '{'}, {']', '['}};
        
        for(char x : s) {
            st.push(x);
            
            if(x == ')' or x == ']' or x == '}') {
                st.pop();
                
                if(st.empty() or st.top() != mp[x])
                    return false;
                
                st.pop();
            }
        }
        
        return st.empty();
    }
};
