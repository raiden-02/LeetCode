class Solution {
public:
    int numberOfSpecialChars(string word) {
        array<int, 26> lmap, umap;
        lmap.fill(-1);
        umap.fill(-1);
        int n = word.length();

        for (int i = 0, j = n - 1; i < n && j >= 0; i++, j--) {
            int lindex = word[i] >= 'a' && word[i] <= 'z' ? word[i] - 'a' : -1;
            int uindex = word[j] >= 'A' && word[j] <= 'Z' ? word[j] - 'A' : -1;
            
            if (lindex != -1) lmap[lindex] = i;
            if(uindex != -1) umap[uindex] = j;
        }

        int ans = 0;

        for (int i = 0; i < 26; i++) {
            if (lmap[i] == -1 || umap[i] == -1) continue;
            if (lmap[i] < umap[i]) ans++;
        }

        return ans;
    }
};
