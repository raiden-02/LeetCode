class Solution {
public:
    bool isItPossible(string word1, string word2) {
        unordered_map<int, int> m1, m2;

        for(char x : word1) m1[x]++;
        for(char x : word2) m2[x]++;

        for(char x = 'a'; x <= 'z'; x++) {
            if(not m1.count(x)) continue;
            for(char y = 'a'; y <= 'z'; y++) {
                if(not m2.count(y)) continue;

                m1[x]--, m2[x]++;
                m2[y]--, m1[y]++;

                if(m1[x] == 0) m1.erase(x);
                if(m2[y] == 0) m2.erase(y);

                if(m1.size() == m2.size()) return true;

                m1[x]++, m2[x]--;
                m2[y]++, m1[y]--;

                if(m2[x] == 0) m2.erase(x);
                if(m1[y] == 0) m1.erase(y);
            }
        }

        return false;
    }
};
