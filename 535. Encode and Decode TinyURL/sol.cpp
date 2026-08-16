class Solution {
    unordered_map<string, string> StL, LtS;
    int codeval;
public:
    Solution() {
        StL = unordered_map<string, string>();
        LtS = unordered_map<string, string>();
        codeval = 0;
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl = "http://tinyurl.com/" + to_string(++codeval);
        StL[longUrl] = shortUrl;
        LtS[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return LtS[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
