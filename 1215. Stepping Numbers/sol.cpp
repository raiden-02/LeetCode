//naive intuitive
class Solution {
    vector<int> ans;
    
    void helper(string cur, int const& low, int const& high) {
        long long n = stoll(cur);
        
        if(n >= low and n <= high)
            ans.push_back(n);
        
        if(n > high)
            return;
        
        int a = cur.back() - '0' + 1, b = cur.back() - '0' - 1;
        
        if(a >= 0 and a <= 9)
            helper(cur + to_string(a), low, high);
        
        if(b >= 0 and b <= 9)
            helper(cur + to_string(b), low, high);
    }
public:
    vector<int> countSteppingNumbers(int low, int high) {
        if(0 >= low and 0 <= high)
            ans.push_back(0);
        
        for(int i = 1; i <= 9; i++)
            helper(to_string(i), low, high);
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

//bfs

// --- alternate solution ---

class Solution {
public:
    vector<int> countSteppingNumbers(int low, int high) {
        vector<int> ans;
        queue<int> q;
        
        for(int i = 1; i <= 9; i++) q.push(i);
        
        if(low == 0)
            ans.push_back(0);
        
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            
            if(cur <= high / 10) {
                int unit = cur % 10, prev = cur * 10 + unit - 1, next = prev + 2;

                if(unit > 0) q.push(prev);
                if(unit < 9) q.push(next);
            }
            
            if(cur >= low and cur <= high)
                ans.push_back(cur);
        }
        
        return ans;
    }
};
