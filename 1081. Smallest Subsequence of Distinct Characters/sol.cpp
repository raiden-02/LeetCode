class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char> st;
        unordered_map<char, int> mp;
        for (char x : s) mp[x]++;
        unordered_map<char, bool> vis;

        for (char x : s) {
            mp[x] -= 1;

            if (vis[x]) continue;

            while (!st.empty() && x < st.top() && mp[st.top()] > 0) {
                vis[st.top()] = false;
                st.pop();
            }

            st.push(x);
            vis[x] = true;
        }

        string ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
