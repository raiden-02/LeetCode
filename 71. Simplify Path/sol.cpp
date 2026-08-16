class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        istringstream ss(path);
        string token;
        
        while(getline(ss, token, '/')) {
            if(token == "." || token.empty())
                continue;
            if(token == ".." && !st.empty())
                st.pop();
            else if(token != "..")
                st.push(token);
        }
        
        string ans;
        while(!st.empty()) {
            ans = '/' + st.top() + ans;
            st.pop();
        }
        
        return ans.empty() ? "/" : ans;
    }
};
