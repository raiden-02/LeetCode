class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;
        
        unordered_map<char, int> m1, m2;
        for(char x : s1) m1[x]++;
        int len = s1.length();
        
        for(int i = 0; i <= s2.length() - len; i++) {
            for(int j = i; j < i + len; j++) {
                m2[s2[j]]++;
            }
            
            bool f = true;
            
            for(auto &x : m1) {
                if(x.second != m2[x.first]) {
                    f = false;
                    break;
                }
            }
            
            if(f) return f;
            
            m2.clear();
        }
        
        return false;
    }
};

// --- alternate solution ---

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;
        
        unordered_map<char, int> m1, m2;
        for(char x : s1) m1[x]++;
        int len = s1.length();
        int l = 0, r = 0;

        while(r < s2.length()) {
            m2[s2[r]]++;

            while(r - l + 1 > len && l < r) {
                m2[s2[l]]--;
                l++;
            }

            bool f = true;

            for (const auto& [key, value] : m1) {
                if(value != m2[key]) {
                    f = false;
                    break;
                }
            }

            if(f) return true;

            r++;
        }

        return false;
    }
};
