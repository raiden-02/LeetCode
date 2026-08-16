//O(n)
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size(), ans = 0, cnt = 0;
        vector<int> counts(n + 1);
        n /= 2;
        
        unordered_map<int, int> counter;
        for(int &x : arr) {counter[x]++; if(counter[x] >= n) return 1;}
        
        for(auto &x : counter) counts[x.second]++;
        
        for(int i = n; i >= 0; i--) {
            while(counts[i]) {
                cnt += i, counts[i]--, ans++;
                
                if(cnt >= n) return ans;
            }
        }
        
        return -1;
    }
};

//O(nlogn)

// --- alternate solution ---

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        vector<pair<int, int>> vec;
        int n = arr.size(), cnt = 0, ans = 0;
        n /= 2;
        
        for(int &x : arr) mp[x]++;
        
        for(auto &x : mp) vec.push_back({x.second, x.first});
        
        sort(vec.rbegin(), vec.rend());
        
        for(auto &x : vec) {
            cnt += x.first;
            ans++;
            
            if(cnt >= n)
                break;
        }
        
        return ans;
    }
};
