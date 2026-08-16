function removeOccurrences(s: string, part: string): string {
    const stack: string[] = [];
    const m = s.length, n = part.length;

    for(let i = 0; i < s.length; i++) {
        stack.push(s[i]);

        let cnt = 0;

        for(let j = stack.length - 1, pi = n - 1; i >= n - 1 && j >= Math.max(0, j - n + 1) && pi >= 0; j--, pi--) {

            if(stack[j] != part[pi]) break;
            cnt += 1;
        }

        if(cnt == n) {
            while(cnt > 0) {
                stack.pop();
                cnt -= 1;
            }
        }  
    }

    return stack.join("");
};
