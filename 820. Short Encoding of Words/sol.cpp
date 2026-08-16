//initial solution
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        auto comp = [&](string &a, string &b) {
            return a.length() > b.length();
        };
        
        auto endsWith = [&](std::string_view str, std::string_view suffix) {
            return str.size() >= suffix.size() && 0 == str.compare(str.size()-suffix.size(), suffix.size(), suffix);
        };
        
        int ans = 0;
        sort(words.begin(), words.end(), comp);
        
        unordered_map<string, int> mp;
        mp[words[0]] = words[0].length();
        ans += words[0].length() + 1;
        for(string &x : words) {
            if(x == words[0])
                continue;
            
            bool f = false;
            for(auto const&[k, v] : mp) {
                if(endsWith(k, x)) {
                    f = true;
                    break;
                }
            }
            
            if(!f) {
                mp[x] = x.length();
                ans += x.length() + 1;
            }
        }
        
        return ans;
    }
};

//optimised solution

// --- alternate solution ---

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        auto comp = [&](string &a, string &b) {
            return a.length() > b.length();
        };
        
        sort(words.begin(), words.end(), comp);
        string ans = words[0] + "#";
        
        for(int i = 1; i < words.size(); i++) {
            if(ans.find(words[i] + "#") == -1)
                ans += words[i] + "#";
        }
        
        return ans.length();
    }
};
