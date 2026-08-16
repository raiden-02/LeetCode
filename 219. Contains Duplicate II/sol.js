/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var containsNearbyDuplicate = function(nums, k) {
    const mp = new Map();

    for(let i = 0; i < nums.length; i++) {
        let x = mp.get(nums[i]);
        if(x != undefined && i - x <= k)
            return true;

        mp.set(nums[i], i);
    }

    return false;
};
