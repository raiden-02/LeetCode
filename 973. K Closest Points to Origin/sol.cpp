class Solution {
    int distance(vector<int> &x) {
        return x[0] * x[0] + x[1] * x[1];
    }
    
    int partition(vector<vector<int>> &arr, int l, int r) {
        int pivot = distance(arr[r]);
        
        for(int i = l; i < r; i++) {
            if(distance(arr[i]) < pivot)
                swap(arr[i], arr[l++]);
        }
        
        swap(arr[l], arr[r]);
        return l;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int l = 0, r = points.size() - 1;
        k--;
        
        while(1) {
            int p = partition(points, l, r);
            
            if(p == k)
                break;
            
            else if(p < k)
                l = p + 1;
            
            else
                r = p - 1;
        }
        
        return vector<vector<int>>(points.begin(), points.begin() + k + 1);
    }
};

// --- alternate solution ---

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [&](vector<int> &a, vector<int> &b) {
            return a[0] * a[0] + a[1]* a[1] < b[0] * b[0] + b[1] * b[1];
        };
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
        
        for(auto &x : points) {
            pq.push(x);
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<vector<int>> ans;
        
        while(not pq.empty())
            ans.push_back(pq.top()), pq.pop();
        
        return ans;
        
    }
};

//quick select

// --- alternate solution ---

//intuitive
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<pair<int, int>> arr(n);
        
        for(int i = 0; i < points.size(); i++)
            arr[i] = {points[i][0] * points[i][0] + points[i][1] * points[i][1], i};
        
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans(k);
        
        for(int x = 0; x < k; x++)
            ans[x] = points[arr[x].second];
        
        return ans;
    }
};

//priority queue
