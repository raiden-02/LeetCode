class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == 0) return num;

        if(k >= num.length()) return "0";

        stack<char> st;

        for(char x : num) {
            while(!st.empty() && k > 0 && st.top() > x)
                st.pop(), k--;
            
            st.push(x);

            if(st.size() == 1 && st.top() == '0') st.pop();
        }

        while(k-- && !st.empty()) st.pop();

        string ans;
        while(!st.empty())
            ans.push_back(st.top()), st.pop();
        
        reverse(ans.begin(), ans.end());

        return ans.empty() ? "0" : ans;
    }
};
