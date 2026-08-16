function maximumSum(nums: number[]): number {
    const sum_of_digits = (a: number): number => {
        let ans: number = 0;
        while(a > 0) {
            const dig = a % 10;
            a = Math.floor(a / 10);
            ans += dig;
        }

        return ans;
    };

    const mp: Map<number, number> = new Map();
    let ans: number = -1;

    for(let i = 0; i < nums.length; i++) {
        const cur_sum = sum_of_digits(nums[i]);

        if(mp.has(cur_sum)) {
            ans = Math.max(ans, mp.get(cur_sum) + nums[i]);
            mp.set(cur_sum, Math.max(mp.get(cur_sum), nums[i]))
        }

        else {
            mp.set(cur_sum, nums[i]);
        }
    }

    return ans;  
};
