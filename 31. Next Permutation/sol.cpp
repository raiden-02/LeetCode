//simulation find next greater number from ones place and swap
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1, n = nums.size();
        
        for(int i = n - 1; i > 0; i--) {
            if(nums[i - 1] < nums[i]) {
                ind = i - 1;
                break;
            }
        }
        
        if(ind != -1) {
            int rep = INT_MAX, j = ind;
            
            for(int i = ind + 1; i < n; i++) {
                if(nums[i] > nums[ind] && nums[i] < rep) {
                    j = i;
                    rep = nums[i];
                }
            }
            
            swap(nums[j], nums[ind]);
        }
        
        sort(nums.begin() + ind + 1, nums.end());
    }
};

//algorithm next permutation in built

// --- alternate solution ---

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto ind = is_sorted_until(nums.rbegin(), nums.rend()); //strictly increasing section from the end is the last permutation of that section
        
        if (ind != nums.rend()) //once a number lesser than previous number is found we swap it with the number greater than it and occurs after that number
            swap(*ind, *upper_bound(nums.rbegin(), ind, *ind));
        
        reverse(nums.rbegin(), ind); // then we reverse the perumutation from the end to that index to make it the first/least permuation after swapping the number
    }
};

// --- alternate solution ---

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};

//simulation using inbuilt upper_bound and is_sorted_until (same as first approach but more concise)
