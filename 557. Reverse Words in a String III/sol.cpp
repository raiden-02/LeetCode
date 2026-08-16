class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string ans, token;

        while(getline(ss, token, ' ')) {
            reverse(token.begin(), token.end());
            ans += token + ' ';
        }

        ans.pop_back();
        
        return ans;
    }
};

// --- alternate solution ---

class Solution {
public:
    string reverseWords(string s) {
        string ans;
        stringstream ss(s);
        string k;
        
        while(ss >> k) {
            reverse(k.begin(), k.end());
            ans += k + " ";
        }
        
        ans.pop_back();
        return ans;
    }
};
