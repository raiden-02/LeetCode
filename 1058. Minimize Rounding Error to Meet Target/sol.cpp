//intuitive dp recur memo
class Solution {
    vector<unordered_map<double, double>> dp;
    
    double helper(vector<double> const& arr, int target, int ind) {
        if(ind >= arr.size()) {
            if(target != 0)
                return DBL_MAX / 2;
            return 0;
        }
        
        if(dp[ind].find(target) != dp[ind].end())
            return dp[ind][target];
        
        double cur = arr[ind];
        double c = ceil(cur), f = floor(cur);
        
        double a = helper(arr, target - c, ind + 1) + (c - cur);
        double b = helper(arr, target - f, ind + 1) + (cur - f);
        
        return dp[ind][target] = min(a, b);
    }
public:
    string minimizeError(vector<string>& prices, int target) {
        int n = prices.size();
        vector<double> arr(n);
        dp.resize(n);
        
        for(int i = 0; i < n; i++)
            arr[i] = stod(prices[i]);
        
        double ans = helper(arr, target, 0);
        
        string out = "-1";
        
        if(ans < INT_MAX / 2) {
            out = "";
            
            string tmp = to_string(ans);
            int i = 0;
            
            while(i < tmp.length() && tmp[i] != '.')
                out += tmp[i++];
            
            for(int j = i; j - i < 4; j++)
                out += tmp[j];
        }
        
        return out;
    }
};

//non intuitive greedy pq

// --- alternate solution ---

class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
        priority_queue<double, vector<double>, greater<double>> pq;
        double ans = 0;
        
        for(string &x : prices) {
            double cur = stod(x);
            double c = ceil(cur), f = floor(cur);
            
            if(c != f)
                pq.push((c - cur) - (cur - f));
            
            ans += (cur - f);
            //cout << ans << endl;
            target -= f;
        }
        
        if(target < 0 || target > pq.size())
            return "-1";
        
        //cout << target << endl;
        
        while(target > 0) {
            //cout << pq.top() << endl;
            ans += pq.top(), pq.pop(), target--;
        }
        
        //cout << ans << endl;
        
        string out = to_string(ans);
        return out.substr(0, out.find_first_of('.', 0) + 4);
    }
};
