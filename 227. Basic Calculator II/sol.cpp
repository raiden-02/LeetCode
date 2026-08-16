class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        s.push_back('+');
        int cur = 0;
        char sign = '+';
        string signs = "*/+-";
        
        for(char x : s) {
            if(isdigit(x))
                cur = cur * 10 + (x - '0');
            
            else if(signs.find(x) != string::npos) {
                if(sign == '+')
                    st.push(cur);
                
                else if(sign == '-')
                    st.push(-cur);
                
                else if(sign == '*') {
                    int t = st.top(); st.pop();
                    st.push(t * cur);
                }
                
                else {
                    int t = st.top(); st.pop();
                    st.push(t / cur);
                }
                
                sign = x, cur = 0;
            }
        }
        int ans = 0;
        
        while(!st.empty())
            ans += st.top(), st.pop();
        
        return ans;
    }
};
