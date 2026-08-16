class Solution {
public:
    int singleNumber(vector<int>& nums) {
        bitset<32> first, second;
        
        for(int &x : nums) {
            for(int i = 0; i < 32; i++) {
                int bit = (x >> i) & 1;
                
                if(bit) {
                    if(not first[i] and not second[i]) first[i] = 1;
                    
                    else if(first[i] and not second[i]) first[i] = 0, second[i] = 1;
                    
                    else if(not first[i] and second[i]) second[i] = 0;
                }
            }
        }
        /*int ans = 0;
        
        for(int i = 0; i < 31; i++) if(first[i] ^ first[31]) ans += (1 << i);
        
        return first[31] ? ~ans : ans;*/
       return (int32_t)(first.to_ulong());
    }
};

// --- alternate solution ---

//intuitve
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        for(int &x : nums) mp[x]++;
        
        for(auto &x : mp) if(x.second == 1) return x.first;
        
        return -1;
    }
};

//bitset
