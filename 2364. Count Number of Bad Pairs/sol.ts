function countBadPairs(nums: number[]): number {
    // let's find valid pairs instead
    // the equation after some shuffling becomes
    // j - nums[j] = i - nums[i]
    // at each index I have j and nums[j]
    // if I can find j - nums[j] in the map, then its a valid pair
    // so ans = total pairs possible - count of valid pairs

    const mp: Map<number, number> = new Map()
    let ans: number = 0;
    const n: number = nums.length

    nums.forEach((element, i) => {
        if(mp.has(i - element)) {
            ans += mp.get(i - element);
            mp.set(i - element, mp.get(i - element) + 1);
        }

        else {
            mp.set(i - element, 1);
        }
    });

    return (n * (n - 1)  / 2) - ans;
};
