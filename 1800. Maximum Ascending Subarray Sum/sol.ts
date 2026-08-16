function maxAscendingSum(nums: number[]): number {
    const n = nums.length;
    if(n == 1) return nums[0];

    let ans = nums[0];
    let sum = nums[0];

    for(let i = 0; i < n - 1; i++) {
        if(nums[i] < nums[i + 1]) {
            sum += nums[i + 1];
        }

        else sum = nums[i + 1];

        ans = Math.max(ans, sum)
    }

    return ans
};
