class ATM {
    vector<long long> notes;
    unordered_map<int, int> mp;
public:
    ATM() {
        notes.assign(5, 0);
        mp = {{0, 20}, {1, 50}, {2, 100}, {3, 200}, {4, 500}};
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i = 0; i < 5; i++) {
            notes[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> ans(5);
        vector<long long> tmp = notes;

        for(int i = 4; i >= 0; i--) {
            if(notes[i] == 0) continue;

            long long div = min(notes[i], (long long)amount / mp[i]);

            amount -= mp[i] * div;
            notes[i] -= div;
            ans[i] = div;

        }

        if(amount != 0) {
            notes = tmp;
            return {-1};
        }

        return ans;   
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
