class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        return s == target or (s.find('1') != string::npos and target.find('1') != string ::npos);
    }
};

// --- alternate solution ---

class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        return (s.find('1') != string::npos) == (target.find('1') != string ::npos);
    }
};
