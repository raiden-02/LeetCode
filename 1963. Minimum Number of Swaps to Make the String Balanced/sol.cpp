class Solution {
public:
    int minSwaps(string s) {
        stack<char> st; 
        int cnt = 0;

        for(char x : s) {
            if(x == '[') st.push(x);
            else if(!st.empty()) st.pop();
            else cnt++;
        }

        return (cnt + 1) / 2;
    }
};
