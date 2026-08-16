class Solution {
    vector<int> arr;
    int n;
public:
    Solution(vector<int>& nums) {
        arr = nums;
        n = nums.size();
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return arr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ret = arr;
        
        for(int i = 0; i < n; i++)
            swap(ret[i], ret[rand() % n]);
        
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
 
 class Solution:

    def __init__(self, nums: List[int]):
        self.orig = nums

    def reset(self) -> List[int]:
        """
        Resets the array to its original configuration and return it.
        """
        return self.orig
        

    def shuffle(self) -> List[int]:
        """
        Returns a random shuffling of the array.
        """
        dup = self.orig[:]
        for i in range(len(dup)):
            ri = random.randrange(i, len(dup))
            dup[i], dup[ri] = dup[ri], dup[i]
        return dup


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
