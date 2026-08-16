class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        
        for(char x : s) {
            if(not ans.empty() and ans.back() == x)
                ans.pop_back();
            
            else
                ans.push_back(x);
        }
        
        return ans;
    }
};
