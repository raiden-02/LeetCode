class Solution {
    array<int, 1001> in;
    array<bool, 1001> out;
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        in.fill(0);
        out.fill(false);

        for(auto &t : trust) in[t[1]]++, out[t[0]] = true;
        
        for(int i = 1; i <= n; i++) if(!out[i] && in[i] == n - 1) return i;

        return -1;
    }
};

// --- alternate solution ---

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n + 1);
        vector<bool> out(n + 1);

        for(auto &t : trust) in[t[1]]++, out[t[0]] = true;
        
        for(int i = 1; i <= n; i++) if(not out[i] and in[i] == n - 1) return i;

        return -1;
    }
};
