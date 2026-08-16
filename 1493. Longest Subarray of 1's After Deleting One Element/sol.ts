function longestSubarray(nums: number[]): number {
    let mp: number[] = new Array(2).fill(0); 
    let ans: number = 0;

    for(let l = 0, r = 0; r < nums.length; r++) {
        mp[nums[r]] += 1;

        while(l < r && mp[0] > 1) {
            mp[nums[l]] -= 1;;
            l += 1;
        }

        ans = Math.max(ans, r - l);
    }

    return ans;
};
