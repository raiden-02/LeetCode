function minimumLength(s: string): number {
    const mp = new Map<string, number>();

    for(const ch of s) {
        mp.set(ch, mp.get(ch) ? mp.get(ch) + 1 : 1);
    }

    let ans = 0;

    mp.forEach((value, key) => {
        if(value <= 2) ans += value;

        else {
            if(value % 2) ans += 1;
            else ans += 2;
        }
    });

    return ans;
};
