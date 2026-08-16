class Solution {
public:
    string reverseVowels(string s) {
        vector<int> inds;
        vector<char> vows;
        
        for(int i = 0; i < s.length(); i++) {
            char x = s[i];
            if(x == 'a' or x == 'e' or x == 'i' or x == 'o' or x == 'u' or x == 'A' or x == 'E' or x == 'I' or x == 'O' or x == 'U')
                inds.push_back(i), vows.push_back(x);
        }
        
        for(int l = 0, r = inds.size() - 1; l < vows.size() and r >= 0; l++, r--)
            s[inds[l]] = vows[r];
        
        return s;
    }
};
