function vowelStrings(words: string[], queries: number[][]): number[] {
    function isVowel(ch: string): boolean {
        return ['a', 'e', 'i', 'o', 'u'].includes(ch);
    }

    const size: number = words.length;
    const prefix: number[] = new Array(size + 1).fill(0);
    const ans: number[] = new Array(queries.length);

    for (let i = 1; i <= size; i++) {
        prefix[i] = prefix[i - 1] +
            (isVowel(words[i - 1][0]) && isVowel(words[i - 1][words[i - 1].length - 1]) ? 1 : 0);
    }

    queries.forEach((query, i) => {
        const [start, end] = query;
        ans[i] = prefix[end + 1] - prefix[start];
    });

    return ans;
};
