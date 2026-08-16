//priority queue solution O(nlogn)
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        auto compq = [&](tuple<int, int, int> &a, tuple<int, int, int> &b) {
            return get<2>(a) > get<2>(b);
        };
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(compq)> pq(compq);
        
        auto comp = [&](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        };
        sort(trips.begin(), trips.end(), comp);
        
        int cap = capacity;
            
        for(auto &x : trips) {
            while(!pq.empty() && x[1] >= get<2>(pq.top()))
                cap += get<0>(pq.top()), pq.pop();
            
            cap -= x[0];
            
            if(cap < 0)
                return false;
            pq.push(make_tuple(x[0], x[1], x[2]));
        }
        
        return true;
    }
};

//map solution O(n)

// --- alternate solution ---

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> times;
        int cur = 0;
        
        for(auto &trip : trips) {
            times[trip[1]] += trip[0];
            times[trip[2]] -= trip[0];
        }
        
        for(auto const &[k, v] : times) {
            capacity -= v;
            if(capacity < 0)
                return false;
        }
        
        return true;
    }
};

//bucket sort O(1001) or O(n)

// --- alternate solution ---

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> times(10001);
        int cur = 0;
        
        for(auto &trip : trips) {
            times[trip[1]] += trip[0];
            times[trip[2]] -= trip[0];
        }
        
        for(int i = 0; i < 1001 && capacity >= 0; i++) {
            capacity -= times[i];
            if(capacity < 0)
                return false;
        }
        
        return true;
    }
};
