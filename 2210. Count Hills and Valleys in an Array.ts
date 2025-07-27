function countHillValley(nums: number[]): number {
    const n = nums.length;
    let ans = 0;

    for(let i = 1; i < n - 1; ) {
        const left = nums[i - 1];

        if(left == nums[i]) {
            i += 1;
            continue;
        }

        while(i + 1 < n && nums[i + 1] == nums[i]) {
            i += 1;
        }

        const right = nums[i + 1];

        if((nums[i] > left && nums[i] > right) || (nums[i] < left && nums[i] < right))
            ans += 1;
        
        i += 1;
    }

    return ans;
};
