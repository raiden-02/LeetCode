class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m1, m2;
        
        for(int i = 0; i < s.length(); i++) {
            int x = s[i], y = t[i];
            
            auto i1 = m1.find(x), i2 = m2.find(y);
            if(i1 == m1.end() and i2 == m2.end())
                m1[x] = y, m2[y] = x;
            
            else if(i1 != m1.end() and i2 != m2.end() and m1[x] == y and m2[y] == x)
                continue;
            
            else
                return false;
        }
        
        return true;
    }
};
