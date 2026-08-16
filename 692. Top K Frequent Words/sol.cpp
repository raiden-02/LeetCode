class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        
        for(string &word : words) {
            mp[word]++;
        }
        
        map<int, vector<string>> omp;
        
        for(auto &x : mp) {
            omp[-x.second].push_back(x.first);
        }
        
        vector<string> ans;
        int i = 0;
        
        for(auto &vec : omp) {
            vector<string> tmp;
            
            sort(vec.second.begin(), vec.second.end());
            for(string &x : vec.second) {
                tmp.push_back(x);
                i++;
                
                if(i == k) break;
            }
            
            ans.insert(ans.end(), tmp.begin(), tmp.end());
            
            if(i == k) break;
        }
        
        return ans;
    }
};

// --- alternate solution ---

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        
        priority_queue<pair<int, string>> pq;
        for(string &x : words)
            mp[x]++;
        
        for(auto i = mp.begin(); i != mp.end(); i++) {
            pq.push(make_pair(-i->second, i->first)); //minimum count at top
            if(pq.size() > k)
                pq.pop(); //minimum count removed
        }
        
        vector<string> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(ans.begin(), ans.end()); //maximum at bottom
        return ans;
    }
};
