class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int ans = 0;
        
        for(int x : nums)
            ans ^= x;
        
        return ans;
    }
};

Intuition
There is really no intuition for this, you have to write it down on pen and paper and calculate the expression of the final answer, here's how I did it

Approach
I took the example of [1, 4] as [x, y] then I tried to find the final expression
=> (((x | x) & x) ^ ((x | x) & y) ^ ((x | y) & x) ^ ((x | y) & y) ^ ((y | x) & x) ^ ((y | x) & y) ^ ((y | y) & x) ^ ((y | y) & y))

=> x ^ (x & y) ^ ((x | y) & x) ^ ((x | y) & y) ^ ((y | x) & x) ^ ((y | x) & y) ^ (y & x) ^ y
(since, x | x == x and x & x == x)

Using the following basic boolean/bitwise operation properties

x ^ x == 0
x & y == y & x
(x | y) & x == (y | x) & x
We can see that all the elements from (x & y) to (y & x) cancel each other out, and the only expression that remains is x ^ y

This can be extrapolated to array of all lengths, and thus the answer just comes out as the XOR of all the elements.

// --- alternate solution ---

class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int ans = 0;
        
        for(int x : nums)
            ans ^= x;
        
        return ans;
    }
};
