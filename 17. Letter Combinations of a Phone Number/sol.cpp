class Solution {
    vector<string> ans;
    unordered_map<char, string> mp = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    
    void helper(string const& digits, int ind, string tmp) {
        if(ind >= digits.length()) {
            ans.push_back(tmp);
            return;
        }
        
        for(char x : mp[digits[ind]]) {
            tmp.push_back(x);
            helper(digits, ind + 1, tmp);
            tmp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        
        helper(digits, 0, "");
        return ans;
    }
};
