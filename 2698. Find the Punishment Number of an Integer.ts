function punishmentNumber(n: number): number {
    let ans = 0;

    const check_partition = (cur, tar) => {
        if(cur < tar || tar < 0) return false;

        if(cur == tar) return true;

        return check_partition(Math.floor(cur / 10), tar - Math.floor(cur % 10))
        || check_partition(Math.floor(cur / 100), tar - Math.floor(cur % 100))
        || check_partition(Math.floor(cur / 1000), tar - Math.floor(cur % 1000));
    }

    for(let i = 1; i <= n; i++) {
        let squared = i * i;

        if(check_partition(squared, i)) {
            ans += squared;
        }
    }

    return ans;
};
