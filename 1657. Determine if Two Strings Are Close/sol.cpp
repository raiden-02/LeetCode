class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length())
            return false;
        
        int n = word1.length();
        unordered_map<char, int> mp1, mp2;

        auto condition1 = [&]() {
            
            for(int i = 0; i < n; i++) {
                mp1[word1[i]]++, mp2[word2[i]]++;
            }
            
            for(auto &x : mp1)
                if(x.second != mp2[x.first])
                    return false;
            
            return true;
        };
        
        auto condition2 = [&]() {
            set<char> st1, st2;
            
            for(int i = 0; i < n; i++)
                st1.insert(word1[i]), st2.insert(word2[i]);
            
            if(st1 != st2) return false;
            
            vector<int> v1, v2;
            
            for(auto &x : mp1) v1.push_back(x.second);
            for(auto &x : mp2) v2.push_back(x.second);
            
            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());
            
            return v1 == v2;
        };
        
        return condition1() or condition2();
    }
};

// --- alternate solution ---

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()) return false;

        unordered_map<char, int> mp1, mp2;

        for(char x : word1) mp1[x]++;
        for(char x : word2) mp2[x]++;

        if(mp1.size() != mp2.size()) return false;

        vector<int> f1, f2;

        for(char x = 'a'; x <= 'z'; x++) {
            auto it1 = mp1.find(x);
            auto it2 = mp2.find(x);

            if(it1 != mp1.end() && it2 != mp2.end()) {
                f1.push_back(it1->second);
                f2.push_back(it2->second);
            }

            else if(it1 == mp1.end() && it2 == mp2.end()) {
                continue;
            }

            else {
                return false;
            }
        }

        sort(f1.rbegin(), f1.rend());
        sort(f2.rbegin(), f2.rend());

        for(int i = 0; i < f1.size(); i++) {
            if(f1[i] != f2[i]) {
                return false;
            }
        }

        return true;
    }
};
