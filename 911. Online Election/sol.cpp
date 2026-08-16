class TopVotedCandidate {
    map<int, int> time2person;
    unordered_map<int, int> votes;
    int maxvotes = 0, maxvotedperson = -1;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        for(int i = 0; i < persons.size(); i++) {
            votes[persons[i]]++;
            
            if(votes[persons[i]] >= maxvotes) {
                maxvotes = votes[persons[i]];
                maxvotedperson = persons[i];
            }
            
            time2person[times[i]] = maxvotedperson;
        }
    }
    
    int q(int t) {
        auto it = time2person.lower_bound(t);
        
        if(it == time2person.end() or it->first > t) 
            it--;
        
        return it->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
