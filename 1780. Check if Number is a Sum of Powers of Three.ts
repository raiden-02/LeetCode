function checkPowersOfThree(n: number): boolean {
    let rem: number = n;
    const set = new Set<number>();

    while(rem > 0) {
        let cur: number = 1;
        let cnt: number = 0;

        while(cur <= rem) {
            cur *= 3;
            cnt += 1;
        }

        if(set.has(cnt)) return false;
        set.add(cnt);

        cur /= 3;
        
        if(rem == cur) return true;
        rem -= cur;
    }

    return false;
};
