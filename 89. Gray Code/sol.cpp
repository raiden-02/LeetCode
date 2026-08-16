class Solution {
    vector<int> ans;
    string bin = "01";
    
    void helper(string &s, unordered_set<int> &vis) {
        int n = stoi(s, nullptr, 2);
        
        if(vis.find(n) != vis.end())
            return;
        
        vis.insert(n);
        ans.push_back(n);
        
        for(int i = s.length() - 1; i >= 0; i--) {
            char prev = s[i];
            
            for(char x : bin) {
                if(s[i] != x) {
                    s[i] = x;
                    break;
                }
            }
            
            helper(s, vis);
            s[i] = prev;
        }
    }
public:
    vector<int> grayCode(int n) {
        if(n == 0)
            return {0};
        
        unordered_set<int> vis;
        string s(n, '0');
        
        helper(s, vis);
        
        return ans;
    }
};

// --- alternate solution ---

class Solution {
    bitset<32> cur;
    vector<int> ans;
    unordered_set<int> vis;
    
    void helper(int const& n, int ind) {
        int num = (int)cur.to_ulong();
        
        if(vis.find(num) != vis.end())
            return;
        
        vis.insert(num);
        ans.push_back(num);
        
        for(int i = 0; i < n; i++) {
            cur.flip(i);
            helper(n, i + 1);
            cur.flip(i);
        }
    }
public:
    vector<int> grayCode(int n) {
        helper(n, 0);
        
        return ans;
    }
};
