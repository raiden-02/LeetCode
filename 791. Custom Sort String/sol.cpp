class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> sortKey;

        for(int i = 0; i < order.length(); i++) sortKey[order[i]] = i;

        sort(s.begin(), s.end(), [&sortKey](char a, char b) {
            return sortKey[a] < sortKey[b];
        });

        return s;
    }
};
