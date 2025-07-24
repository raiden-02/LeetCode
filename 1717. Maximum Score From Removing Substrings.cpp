class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // cdbcbbaaabab -> ba -> cdbcbaabab
        // cdbcbaabab -> ba -> cdbcabab
        // cdbcabab -> ab -> cdbcab
        // cdbcab -> ab -> cdbc

        stack<char> st;
        int ans = 0;
        string min_s = x <= y ? "ab" : "ba";
        string max_s = x > y ? "ab" : "ba";
        int min_i = min(x, y);
        int max_i = max(x, y);

        for(int i = 0; i < s.length(); i++) {
            if(!st.empty()) {
                if(s[i] == max_s[1] && st.top() == max_s[0]) {
                    st.pop();
                    ans += max_i;
                }

                else st.push(s[i]);
            }

            else st.push(s[i]);
        }

        vector<char> tarr;

        auto flush_stack = [&st, &tarr]() mutable {
            while(!st.empty()) {
                tarr.push_back(st.top());
                st.pop();
            }
        };

        flush_stack();
        
        for(char x : tarr) {
            if(!st.empty()) {
                if(x == min_s[0] && st.top() == min_s[1]) {
                    st.pop();
                    ans += min_i;
                }

                else st.push(x);
            }

            else st.push(x);
        }

        return ans;
    }
};
