class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<vector<int>> buy;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> sell;
        int mod = 1e9 + 7;
        
        for(auto &order : orders) {
            if(order[2] == 0)
                buy.push(order);
            else if(order[2] == 1)
                sell.push(order);
            
            while(!buy.empty() && !sell.empty() && buy.top()[0] >= sell.top()[0]) {
                auto s = sell.top(), b = buy.top();
                int m = min(s[1], b[1]);
                s[1] -= m;
                b[1] -= m;
                buy.pop();
                sell.pop();
                if(s[1])
                    sell.push(s);
                if(b[1])
                    buy.push(b);
            }
        }
        
        int ans = 0;
        while(!buy.empty()) {
            ans = (ans + buy.top()[1]) % mod;
            buy.pop();
        }
        
        while(!sell.empty()) {
            ans = (ans + sell.top()[1]) % mod;
            sell.pop();
        }
        
        return ans;
    }
};
