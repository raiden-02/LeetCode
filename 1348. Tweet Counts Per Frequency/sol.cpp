class TweetCounts {
    unordered_map<string, vector<int>> mp;
    unordered_map<string, int> freqmap;
public:
    TweetCounts() {
        freqmap["minute"] = 60;
        freqmap["hour"] = 3600;
        freqmap["day"] = 86400;
    }
    
    void recordTweet(string tweetName, int time) {
        mp[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        auto key = mp[tweetName];
        
        int chunk = freqmap[freq];
        int rem = (endTime - startTime + 1) % chunk;
        int n = (endTime - startTime + 1) / chunk + (rem > 0);
        
        vector<int> ans(n);
        
        for(auto &t : key) {
            if(t >= startTime and t <= endTime) {
                int ind = (t - startTime) / chunk;
                ans[ind]++;
            }
        }
        
        return ans;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
