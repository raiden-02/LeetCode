class Solution {
    vector<int> parent;
    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }

    void merge(int a, int b) {
        int pa = find(a), pb = find(b);

        if(pa != pb) {
            if(pa < pb) parent[pb] = pa;
            else parent[pa] = pb;
        }
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);

        for(int i = 0; i < 26; i++) parent[i] = i;

        for(int i = 0; i < s1.length(); i++) merge(s1[i] - 'a', s2[i] - 'a');

        for(int i = 0; i < baseStr.length(); i++)
            baseStr[i] = (char) find(baseStr[i] - 'a') + 'a';

        return baseStr;
    }
};
