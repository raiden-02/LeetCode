class Solution {
    vector<vector<string>> ans;

    bool isPalindrome(string const& s) {
        return s == string(s.rbegin(), s.rend());
    }

    void helper(string const& s, int ind, vector<string> &arr) {
        if(ind >= s.length()) {
            ans.push_back(arr);
            return;
        }

        string tmp;

        for(int i = ind; i < s.length(); i++) {
            tmp.push_back(s[i]);

            if(isPalindrome(tmp)) { 
                arr.push_back(tmp);
                helper(s, i + 1, arr);
                arr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> arr;
        helper(s, 0, arr);
        return ans;
    }
};
