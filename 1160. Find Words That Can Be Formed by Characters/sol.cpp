class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        array<int, 26> chf = {}, wf = {};
        int ans = 0;

        for(char x : chars) chf[x - 'a']++;

        for(string const& word : words) {
            wf = {};
            
            for(char x : word) wf[x - 'a']++;

            bool f = true;

            for(int i = 0; i < 26; i++) {
                if(wf[i] > chf[i]) {
                    f = false;
                    break;
                }
            }

            if(f) ans += word.length();
        }

        return ans;
    }
};
