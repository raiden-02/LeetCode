class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st, starst;
        int n = s.length();

        for(int i = 0; i < n; i++) {
            char x = s[i];

            if(x == ')') {
                if(!st.empty()) {
                    st.pop();
                }

                else if(!starst.empty()) {
                    starst.pop();
                }

                else return false;
            }

            else if(x == '(') st.push(i);
            
            else if(x == '*') starst.push(i);
        }

        if(st.size() > starst.size()) return false;

        while(!st.empty() && !starst.empty()) {
            if(st.top() < starst.top()) {
                st.pop(), starst.pop();
            }

            else if(st.top() > starst.top()) {
                return false;
            }
        }

        return true;
    }
};
