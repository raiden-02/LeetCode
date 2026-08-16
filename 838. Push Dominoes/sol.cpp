class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length(), inf = 1e5 + 1;
        vector<int> left(n, inf), right(n, inf);
        
        int dist = inf;
        for(int i = n - 1; i >= 0; i--) {
            dominoes[i] == 'L' ? dist = 0 : dominoes[i] == 'R' ? dist = inf : dist += 1;
            left[i] = dist;
        }
        
        dist = inf;
        for(int i = 0; i < n; i++) {
            dominoes[i] == 'R' ? dist = 0 : dominoes[i] == 'L' ? dist = inf : dist += 1;
            right[i] = dist;
        }
        
        string ans(n, '.');
        
        for(int i = 0; i < n; i++)
            left[i] < right[i] and left[i] < inf ? ans[i] = 'L' : right[i] < left[i] and right[i] < inf ? ans[i] = 'R' : ans[i] = '.';
        
        return ans;
    }
};
