class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        stringstream ss(s);
        string k;
        vector<string> arr;

        while(ss >> k)
            arr.push_back(k);

        int m = pattern.length(), n = arr.size();

        if(m != n) return false;

        for(int i = 0; i < m; i++) {
            auto it1 = mp1.find(pattern[i]);
            auto it2 = mp2.find(arr[i]);

            if(it1 != mp1.end() and it2 != mp2.end()) {
                if(it1->second != it2->first and it2->second != it1->first)
                    return false;
                
                else continue;
            }

            if(it1 != mp1.end() or it2 != mp2.end())
                return false;
            
            mp1[pattern[i]] = arr[i], mp2[arr[i]] = pattern[i];
        }

        return true;
    }
};
