class Solution {
    vector<int> ans;
public:
    void dfs(int num, int length, int const& n, int const& k) {
        //cout << num << endl;
        if(length >= n) {
            if(length == n)
                ans.push_back(num);
            return;
        }
        
        int prev = num % 10;
        int nexAdd = prev + k, nexSub = prev - k;
        if(nexAdd == nexSub) {
            dfs(num * 10 + nexAdd, length + 1, n, k);
            return;
        }
        
        if(nexAdd >= 0 and nexAdd <= 9)
            dfs(num * 10 + nexAdd, length + 1, n, k);
        
        if(nexSub >= 0 and nexSub <= 9)
            dfs(num * 10 + nexSub, length + 1, n, k);
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i = 1; i <= 9; i++) {
            dfs(i, 1, n, k);
        }
        
        return ans;
    }
};
