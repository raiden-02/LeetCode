// O(n)
function minOperations(boxes: string): number[] {
    const n: number = boxes.length
    let ans: number[] = new Array(n).fill(0)
    let lm = 0, lb = 0, rm = 0, rb = 0

    for(let i = 0; i < n; i++) {
        ans[i] += lm
        lb += boxes[i] == '1' ? 1 : 0
        lm += lb

        ans[n - i - 1] += rm
        rb += boxes[n - i - 1] == '1' ? 1 : 0
        rm += rb
    }

    return ans
};

// O(n^2)

// --- alternate solution ---

function minOperations(boxes: string): number[] {
    const n: number = boxes.length
    let ans: number[] = new Array(n)

    for(let i = 0; i < n; i++) {
        let cnt: number = 0
        
        for(let j = 0; j < n; j++) {
            cnt += boxes[j] == '1' ? Math.abs(i - j) : 0
        }

        ans[i] = cnt
    }

    return ans
};
