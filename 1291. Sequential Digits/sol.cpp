class Solution {
    vector<int> ans;
    
    void helper(string cur, int const& low, int const& high) {
        int n = stoi(cur);;
        
        if(n >= low and n <= high)
            ans.push_back(n);
        
        else if(n > high)
            return;
        
        int b = cur.back() - '0';
        
        if(b == 9)
            return;
        
        helper(cur + to_string(b + 1), low, high);
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        for(int i = 1; i <= 9; i++)
            helper(to_string(i), low, high);
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
