class Solution {
public:
    void dfs(string exp, int i, long long total, long long prev_add, string const& num, int const& target, vector<string> &out)
    {
        if(i == num.size() && total == target) return out.push_back(exp);
        
        for(int j = i + 1; j < num.size() + 1; j++)
        {
            string s = num.substr(i, j - i);
            long long n = stoll(s);
            if(num[i] == '0' && s != "0") continue;
            if(exp.empty()) dfs(s, j, n, n, num, target, out);
            else
            {
                dfs(exp + '+' + s, j, total + n, n, num, target, out);
                dfs(exp + '-' + s, j, total - n, -n, num, target, out);
                dfs(exp + '*' + s, j, total - prev_add + n * prev_add, prev_add * n, num, target, out);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> out;
        dfs("", 0, 0, 0, num, target, out);
        return out;
    }
};
