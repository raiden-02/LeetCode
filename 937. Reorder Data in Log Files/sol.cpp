class Solution {
private:
    bool is_number(const string& s) {
        string::const_iterator it = s.begin();
        while (it != s.end() && isdigit(*it)) ++it;
        return !s.empty() && it == s.end();
    }
    
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digits;
        
        for(int i = logs.size() - 1; i >= 0; i--) {
            int j = 0;
            
            while(logs[i][j] != ' ')
                j++;
            
            stringstream ss(logs[i].substr(j + 1));
            string k;
            bool f = false;
            
            while(ss >> k) {
                if(is_number(k)) { 
                    digits.push_back(logs[i]);
                    logs.erase(logs.begin() + i);
                    break;
                }
            }
        }
        
        auto comp = [&](string &x, string &y) {
            int i = 0, j = 0;
            
            while(x[i] != ' ')
                i++;
            
            while(y[j] != ' ')
                j++;
            
            string keyx = x.substr(0, i);
            string keyy = y.substr(0, j);
            
            string valx = x.substr(i);
            string valy = y.substr(j);
            
            if(valx == valy)
                return keyx < keyy;
            
            return valx < valy;
        };
        
        sort(logs.begin(), logs.end(), comp);
        
        logs.insert(logs.end(), digits.rbegin(), digits.rend());
        
        return logs;
    }
};

// --- alternate solution ---

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        map<string, set<string>> mp;
        vector<string> digits, ans;
        
        for(string &log : logs) {
            string id;
            int i = 0;
            
            while(i < log.length() and log[i] != ' ')
                id += log[i], i++;
            
            i++;
            int ind = i;
            bool f = false;
            
            while(i < log.length() and log[i] != ' ') {
                if(isdigit(log[i])) {
                    f = true;
                    break;
                }
                i++;
            }
            
            if(f)
                digits.push_back(log);
            
            else
                mp[log.substr(ind)].insert(id);
        }
        
        for(auto &x : mp) {
            string const& cont = x.first;
            
            for(string const& y : x.second)
                ans.push_back(y + " " + cont);
        }
        
        ans.insert(ans.end(), digits.begin(), digits.end());
        
        return ans;
        
    }
};
