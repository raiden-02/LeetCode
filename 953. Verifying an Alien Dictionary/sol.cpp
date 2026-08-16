class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int val[26] = {0};
        for(int i = 0; i < order.length(); i++) val[order[i] - 'a'] = i;

        for(int i = 1; i < words.size(); i++) {
            string cur = words[i], prev = words[i - 1];
            int cnt = 0;

            for(int ci = 0, pi = 0; ci < cur.length() and pi < prev.length(); ci++, pi++) {
                if(cur[ci] == prev[pi]) {
                    cnt++;
                    continue;
                }
                if(val[cur[ci] - 'a'] > val[prev[pi] - 'a']) break;
                return false;
            }

            if(cur.length() < prev.length() and cnt == (int)cur.length()) return false;
        }

        return true;
    }
};
