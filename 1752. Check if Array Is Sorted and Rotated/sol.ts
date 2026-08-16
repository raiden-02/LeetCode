function check(nums: number[]): boolean {
    const n = nums.length;
    if(n == 1) return true;

    let cnt = 1;

    for(let i = 0, iter_cnt = 0; iter_cnt < 2 * n ; i = (i + 1) % n, iter_cnt++) {
        cnt = nums[(i + 1) % n] >= nums[i] ? cnt + 1 : 1;
        if(cnt == n) return true;
    }

    return cnt == n;
};
