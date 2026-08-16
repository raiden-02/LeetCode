function clearDigits(s: string): string {
    const stack: string[] = [];
    const isDigit = (char: string): boolean => !isNaN(parseInt(char));

    for(const char of s) {
        if(isDigit(char)) {
            if(stack.length != 0) {
                stack.pop();
            }
        }

        else {
            stack.push(char);
        }
    }

    return stack.join("");
};
