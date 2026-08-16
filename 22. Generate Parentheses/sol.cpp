class Solution {
    vector<string> ans;
    
    void helper(int n, string &cur, int open) {
        if(n == 0) {
            ans.push_back(cur);
            return;
        }
        
        if(n < 0 or open > n)
            return;
        
        if(open)
            cur.push_back(')'), helper(n - 1, cur, open - 1), cur.pop_back();
        
        cur.push_back('('), helper(n, cur, open + 1), cur.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
        string cur = "(";
        helper(n, cur, 1);
        
        return ans;
    }
};
