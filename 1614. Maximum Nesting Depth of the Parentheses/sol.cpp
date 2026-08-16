class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, len = 0;

        for(char x : s) {
            if(x == '(') len++;
            else if(x == ')') len--;

            ans = max(ans, len); 
        }

        return ans;
    }
};
