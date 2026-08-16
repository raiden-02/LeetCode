class Solution {
    int ans = 0, sum = 0;

    void dfs(int i, int j, vector<vector<int>>& tree) {
        if (i == 4 || tree[i][j] == -1) return;
        
        sum += tree[i][j];
        int left = 2 * j, right = 2 * j + 1;

        if (i == 3 || (tree[i + 1][left] == -1 && tree[i + 1][right] == -1)) {
            ans += sum;
        } else {
            dfs(i + 1, left, tree);
            dfs(i + 1, right, tree);
        }
        sum -= tree[i][j]; 
    }

public:
    int pathSum(vector<int>& nums) {
        vector<vector<int>> tree(4, vector<int>(8, -1));

        for (int x : nums) {
            int v = x % 10;
            x /= 10;
            int p = x % 10;
            x /= 10;
            int d = x % 10;

            tree[d - 1][p - 1] = v;
        }

        dfs(0, 0, tree);
        return ans;
    }
};
