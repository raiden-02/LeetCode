class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        //build tree
        TrieNode* root = new TrieNode();
        
        for(int &num : nums) {
            TrieNode* cur = root;
            
            for(int i = 31; i >= 0; i--) {
                int curBit = (num >> i) & 1; //extracts the bit value
                
                if(not cur->children[curBit])
                    cur->children[curBit] = new TrieNode();
                
                cur = cur->children[curBit];
            }
        }
        
        //solve
        int ans = INT_MIN;
        
        for(int &num : nums) {
            TrieNode* cur = root;
            int s = 0;
            
            for(int i = 31; i >= 0; i--) {
                int curBit = (num >> i) & 1;
                
                if(cur->children[curBit ^ 1])
                    s += (1 << i), cur = cur->children[curBit ^ 1];
                
                else
                    cur = cur->children[curBit];
            }
            
            ans = max(ans, s);
        }
        
        return ans;
    }
};

// --- alternate solution ---

class TrieNode {
public:
    vector<TrieNode*> children;
    TrieNode() {
        children = vector<TrieNode*>(2);
    }
};
