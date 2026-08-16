class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string temp;
        stack<char> st;
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                st.push(s[i]);
                temp += s[i];
            }
            
            else if(s[i] == ')') {
                if(!st.empty()) {
                    temp += s[i];
                    st.pop();
                }
            }
            
            else
                temp += s[i];
        }
        
        st = {};
        string ans;
        for(int i = temp.length() - 1; i >= 0; i--) {
            if(temp[i] == ')') {
                st.push(temp[i]);
                ans += temp[i];
            }
            
            else if(temp[i] == '(') {
                if(!st.empty()) {
                    ans += temp[i];
                    st.pop();
                }
            }
            
            else
                ans += temp[i];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// --- alternate solution ---

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        vector<bool> arr(n, false);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            char x = s[i];
            if(x == '(') 
                arr[i] = true, st.push(i);

            else if(x == ')') {
                if(i > 0 && !st.empty() && s[st.top()] == '(') {
                    arr[st.top()] = false;
                    arr[i] = false;
                    st.pop();
                }

                else arr[i] = true, st.push(i);
            }
        }

        string ans;

        for(int i = 0; i < n; i++) {
            if(arr[i]) continue;
            else ans.push_back(s[i]);
        }

        return ans;
    }
};
